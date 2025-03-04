#include PLATFORM_HEADER
#include "app_process.h"
#include "stack/include/ember.h"
#include "hal/hal.h"
#include "em_chip.h"
#include "app_log.h"
#include "sl_app_common.h"
#include "app_framework_common.h"
#include "sl_simple_led_instances.h"
#include "app_process.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_eusart.h"
#include "app_ipc.h"
#include "app_radio.h"

volatile uint8_t ipcRxBuffer[IPC_RX_MAX_SIZE];
volatile uint8_t ipcTxBuffer[IPC_TX_MAX_SIZE];
volatile uint8_t tmpRxBuffer[IPC_RX_MAX_SIZE];
volatile uint32_t ipcRxPos = 0;
volatile uint32_t ipcTxLen = 0;
volatile bool ipcDataReady = false;
volatile bool ipcRespReady = false;
volatile bool ipcReceive = false;
osThreadId_t ipcId;

void EUSART1_RX_IRQHandler(void)
{
  volatile uint8_t tmpData = (uint8_t)EUSART1->RXDATA;

  if (!ipcReceive) {
      ipcRxPos = 0;
      if (tmpData == 0xAF)
          ipcReceive = true;
    }
  else {
      if ((tmpData != 0xAC) && (ipcRxPos < IPC_RX_MAX_SIZE))
        {
          ipcRxBuffer[ipcRxPos] = tmpData;
          ipcRxPos++;
        }
      else if (tmpData == 0xAC && (ipcRxPos < IPC_RX_MAX_SIZE)){
          ipcDataReady = true;
          ipcReceive = false;
      }
      else if (ipcRxPos >= IPC_RX_MAX_SIZE) {
          ipcRxPos = 0;
          ipcReceive = false;
      }
  }
  EUSART_IntClear(EUSART1, EUSART_IF_RXFL);
}

void EUSART1_TX_IRQHandler(void)
{
  EUSART_IntClear (EUSART1, EUSART_IF_TXFL);
  if(ipcRespReady){
      ipcRespReady = false;
      EUSART1->TXDATA = IPC_START_BYTE;
      while (!(EUSART1->STATUS & (1 << 6)))
        ;
      for (uint32_t i = 0; i < ipcTxLen; i++)
        {
          EUSART1->TXDATA = ipcTxBuffer[i];
          while (!(EUSART1->STATUS & (1 << 6)))
            ;
        }
      EUSART1->TXDATA = IPC_END_BYTE;
      while (!(EUSART1->STATUS & (1 << 6)))
        ;
      EUSART_IntEnable (EUSART1, EUSART_IEN_RXFL);
      EUSART_IntDisable (EUSART1, EUSART_IEN_TXFL);
  }
}

void ipcReplyHandler(void){
  EUSART_IntDisable (EUSART1, EUSART_IEN_RXFL);
  ipcRxPos = 0;
  ipcDataReady = false;
  uint8_t tmpTxIndex = 1;
  switch (ipcRxBuffer[0])
    {
    case IPC_LIST_CTS:
      {
        ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) IPC_LIST;
        ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorIndex;
        for(uint8_t i = 0; i < sensorIndex; i++){
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorInfo[i].hw;
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorInfo[i].state;
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (sensorInfo[i].battery_voltage >> 24);
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (sensorInfo[i].battery_voltage >> 16);
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (sensorInfo[i].battery_voltage >> 8);
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorInfo[i].battery_voltage;
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorInfo[i].node_type;
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (sensorInfo[i].central_id >> 8);
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorInfo[i].central_id;
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (sensorInfo[i].self_id >> 8);
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorInfo[i].self_id;
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorInfo[i].endpoint;
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorInfo[i].trigd;
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (int8_t) sensorInfo[i].rssi;
            ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) sensorInfo[i].lqi;
        }
        break;
      }
    case IPC_REQUEST:
      {
        ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) IPC_REQUEST_ACK;
        ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t)
            ipcRequestHandler((EmberNodeId)(ipcRxBuffer[1] << 8 | ipcRxBuffer[2] ), ipcRxBuffer[3]);
        break;
      }
    default:
      {
        ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) IPC_ERR;
        break;
      }
    }

  ipcTxBuffer[0] = (uint8_t) tmpTxIndex + 1;
  ipcTxLen = tmpTxIndex + 1;
  ipcRespReady = true;

  EUSART_IntEnable (EUSART1, EUSART_IEN_TXFL);
}

void ipcRequestDone(uint8_t ret, EmberNodeId id, sensor_state_t state)
{
  EUSART_IntDisable (EUSART1, EUSART_IEN_RXFL);
  uint8_t tmpTxIndex = 1;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) IPC_REQUEST_DONE;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (id >> 8);
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) id;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) state;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) ret;
  ipcTxBuffer[0] = (uint8_t) tmpTxIndex + 1;
  ipcTxLen = tmpTxIndex + 1;
  ipcRespReady = true;
  EUSART_IntEnable (EUSART1, EUSART_IEN_TXFL);
}

void ipcNotify(EmberNodeId id, sensor_state_t state, uint8_t alert, uint8_t count)
{
  EUSART_IntDisable (EUSART1, EUSART_IEN_RXFL);
  uint8_t tmpTxIndex = 1;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) IPC_CHANGE;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (id >> 8);
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) id;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) state;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) alert;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) count;
  ipcTxBuffer[0] = (uint8_t) tmpTxIndex + 1;
  ipcTxLen = tmpTxIndex + 1;
  ipcRespReady = true;
  EUSART_IntEnable (EUSART1, EUSART_IEN_TXFL);
}

void ipcReport(EmberNodeId id, uint32_t battery, sensor_state_t state, int8_t rssi, uint8_t lqi)
{
  EUSART_IntDisable (EUSART1, EUSART_IEN_RXFL);
  uint8_t tmpTxIndex = 1;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) IPC_REPORT;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (id >> 8);
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) id;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (battery >> 24);
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (battery >> 16);
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) (battery >> 8);
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) battery;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) state;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (int8_t) rssi;
  ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) lqi;
  ipcTxBuffer[0] = (uint8_t) tmpTxIndex + 1;
  ipcTxLen = tmpTxIndex + 1;
  ipcRespReady = true;
  EUSART_IntEnable (EUSART1, EUSART_IEN_TXFL);
}

bool ipcRequestHandler(EmberNodeId id, sensor_state_t state)
{
  app_log_info("sending request to device %d state %d", id, state);
  if(state != S_ACTIVE && state != S_INACTIVE)
    return false;
  return applicationCoordinatorTxRequest(id, REQ_STATE, state);
}

void ipcInitThread(void)
{
  osThreadAttr_t ipcStackAttribute = {
      "Inter Processor Communication Task",
      osThreadDetached,
      NULL,
      0,
      NULL,
      (1000 * sizeof(void *)) & 0xFFFFFFF8u,
      37,
      0,
      0
    };

    ipcId = osThreadNew(ipcRtosTask,
                                 NULL,
                                 &ipcStackAttribute);
    assert(ipcId != 0);
}

void ipcRtosTask(void *p_arg)
{
  (void)p_arg;

  startIPC();
  ipcRxPos = 0;
  uint8_t cnt = 0;
  while (true) {
      ipcRxPos++;
      if(ipcDataReady){
          sl_led_turn_on(&sl_led_stat);
          ipcReplyHandler();
          sl_led_turn_off(&sl_led_stat);
      }
      osDelay(10);
      cnt++;
      if(cnt > 25){
          sl_led_toggle(&sl_led_comms);
          cnt = 0;
      }
  }
}


void startIPC(void)
{
  CMU_ClockEnable (cmuClock_GPIO, true);
  CMU_ClockEnable (cmuClock_EUSART1, true);
  GPIO_PinModeSet (gpioPortC, 4, gpioModePushPull, 1);

  // Configure the EUSART RX pin to the board controller as an input
  GPIO_PinModeSet (gpioPortC, 6, gpioModeInput, 0);
  EUSART_UartInit_TypeDef init = EUSART_UART_INIT_DEFAULT_HF;
  init.baudrate = 921600;
  init.parity = EUSART_FRAMECFG_PARITY_ODD;

  // Route EUSART1 TX and RX to the board controller TX and RX pins
  GPIO->EUSARTROUTE[1].TXROUTE = (gpioPortC << _GPIO_EUSART_TXROUTE_PORT_SHIFT)
      | (4 << _GPIO_EUSART_TXROUTE_PIN_SHIFT);
  GPIO->EUSARTROUTE[1].RXROUTE = (gpioPortC << _GPIO_EUSART_RXROUTE_PORT_SHIFT)
      | (6 << _GPIO_EUSART_RXROUTE_PIN_SHIFT);

  // Enable RX and TX signals now that they have been routed
  GPIO->EUSARTROUTE[1].ROUTEEN = GPIO_EUSART_ROUTEEN_RXPEN
      | GPIO_EUSART_ROUTEEN_TXPEN;

  // Configure and enable EUSART1 for high-frequency (EM0/1) operation
  EUSART_UartInitHf (EUSART1, &init);
  EUSART_IntEnable (EUSART1, EUSART_IEN_RXFL);
  EUSART_IntDisable (EUSART1, EUSART_IEN_TXFL);

  // Enable NVIC USART sources
  NVIC_ClearPendingIRQ (EUSART1_RX_IRQn);
  NVIC_EnableIRQ (EUSART1_RX_IRQn);
  NVIC_ClearPendingIRQ (EUSART1_TX_IRQn);
  NVIC_EnableIRQ (EUSART1_TX_IRQn);
}
