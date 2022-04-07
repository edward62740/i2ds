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

void EUSART1_RX_IRQHandler(void)
{
  ipcRxBuffer[ipcRxPos] = EUSART1->RXDATA;

  if ((ipcRxBuffer[ipcRxPos] != '\r') && (ipcRxPos < IPC_RX_MAX_SIZE))
    ipcRxPos++;
  else {
      ipcDataReady = true;


  }
  EUSART_IntClear(EUSART1, EUSART_IF_RXFL);
}

void EUSART1_TX_IRQHandler(void)
{
  EUSART_IntClear (EUSART1, EUSART_IF_TXFL);
  if (ipcRespReady)
    {
      for (uint32_t i = 0; i < ipcTxLen; i++)
        {
          EUSART1->TXDATA = ipcTxBuffer[i];
        }
      ipcRespReady = false;
      EUSART_IntEnable (EUSART1, EUSART_IEN_RXFL);
      EUSART_IntDisable (EUSART1, EUSART_IEN_TXFL);
    }

}
void ipcRxHandler(DeviceInfo *info[]){

  memcpy(tmpRxBuffer, ipcRxBuffer, ipcRxPos);
  app_log_info("Input: %s \n", ipcRxBuffer);
  app_log_info("Output: %s \n", tmpRxBuffer);
  ipcTxLen = ipcRxPos;
  ipcRxPos = 0;

  switch (tmpRxBuffer[0])
    {
    default:
      {
        uint8_t tmpTxIndex = 0;
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
        ipcTxBuffer[tmpTxIndex++] = (uint8_t) (13 * sensorIndex);
        ipcTxLen = tmpTxIndex;
        app_log_info("Info: %s", ipcTxBuffer);
        break;
      }
    case IPC_ACK:
      {
        break;
      }
    }
  ipcDataReady = false;
  ipcRespReady = true;
  EUSART_IntDisable (EUSART1, EUSART_IEN_RXFL);
  EUSART_IntEnable (EUSART1, EUSART_IEN_TXFL);
}
