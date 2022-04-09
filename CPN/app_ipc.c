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

volatile uint8_t ipcRxBuffer[IPC_RX_MAX_SIZE];
volatile uint8_t ipcTxBuffer[IPC_TX_MAX_SIZE];
volatile uint32_t ipcRxPos = 0;
volatile uint32_t ipcTxLen = 0;
volatile bool ipcDataReady = false;
volatile bool ipcRespReady = false;
volatile uint8_t tmpRxBuffer[IPC_RX_MAX_SIZE];
volatile uint32_t offset = 0;
osThreadId_t ipcId;

void EUSART1_RX_IRQHandler(void)
{
  EUSART_IntClear(EUSART1, EUSART_IF_RXFL);
  ipcRxBuffer[ipcRxPos] = EUSART1->RXDATA;
  for(volatile uint32_t i = 0; i < ipcRxPos; i++){
       app_log_info("Data: 0x%02X, %d  \n", ipcRxBuffer[ipcRxPos], ipcRxPos);
  }

  if ((ipcRxBuffer[ipcRxPos] != 0xAC) && (ipcRxPos < IPC_RX_MAX_SIZE))
    {
      ipcRxPos++;

    }

  else if (ipcRxBuffer[ipcRxPos] == 0xAC){




      ipcDataReady = true;
  }

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
void ipcRxHandler(void){
  EUSART_IntDisable (EUSART1, EUSART_IEN_RXFL);
  app_log_info("running handler 0x%02X ", ipcRxBuffer[0]);
  ipcDataReady = false;
  uint8_t tmpTxIndex = 0;
  switch (ipcRxBuffer[ipcRxPos - 1])

    {
    case IPC_LIST:
      {
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
    default:
      {
        ipcTxBuffer[tmpTxIndex++] = 0xFF & (uint8_t) 0xCC;
        break;
      }
    }
  ipcRxPos = 0;
  ipcTxBuffer[tmpTxIndex++] = (uint8_t) ((13 * sensorIndex) + 1);
  ipcTxLen = tmpTxIndex;
  ipcRespReady = true;

  EUSART_IntEnable (EUSART1, EUSART_IEN_TXFL);
}

void ipcNotify(void){

}

void ipcInitThread(void){
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
          ipcRxHandler();
      }
      osDelay(10);
  }
}

