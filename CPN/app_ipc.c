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
volatile uint32_t ipcRxPos = 0;
volatile uint32_t ipcTxLen = 0;
volatile bool ipcDataReady = false;
volatile bool ipcRespReady = false;
volatile uint8_t tmpRxBuffer[IPC_RX_MAX_SIZE];
volatile uint32_t offset = 0;
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
      for (uint32_t i = 0; i < ipcTxLen; i++)
        {
          EUSART1->TXDATA = ipcTxBuffer[i];
          while (!(EUSART1->STATUS & (1 << 6)))
            ;
        }

      EUSART_IntEnable (EUSART1, EUSART_IEN_RXFL);
      EUSART_IntDisable (EUSART1, EUSART_IEN_TXFL);
  }


}
void ipcReplyHandler(void){
  EUSART_IntDisable (EUSART1, EUSART_IEN_RXFL);
  ipcRxPos = 0;
  ipcDataReady = false;
  uint8_t tmpTxIndex = 0;
  switch (ipcRxBuffer[0])

    {
    case IPC_ACK:
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
        }
        break;
      }
    case IPC_REQUEST:
      {
        ipcRequestHandler((EmberNodeId)(ipcRxBuffer[1] << 8 | ipcRxBuffer[2] ), ipcRxBuffer[3]);

        break;
      }
    default:
      {
        ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) IPC_ERR;
        break;
      }
    }

  ipcTxBuffer[tmpTxIndex] = (uint8_t) tmpTxIndex;
  ipcTxLen = tmpTxIndex + 1;
  ipcRespReady = true;

  EUSART_IntEnable (EUSART1, EUSART_IEN_TXFL);
}

void ipcNotify(void)
{

}

bool ipcRequestHandler(EmberNodeId id, sensor_state_t state)
{
  app_log_info("sending request to device %d state %d", id, state);
  uint8_t iter = 0;
  if(state != S_ACTIVE && state != S_INACTIVE)
    return false;
  applicationCoordinatorTxRequest(id, REQ_STATE, state);
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
      38,
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
  while (true) {
      ipcRxPos++;
    //app_log_info("rtos");
      if(ipcDataReady){
          ipcReplyHandler();
      }
      osDelay(10);
  }
}

