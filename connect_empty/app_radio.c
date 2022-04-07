#include PLATFORM_HEADER
#include "stack/include/ember.h"
#include "hal/hal.h"
#include "em_chip.h"
#include "app_log.h"
#include "poll.h"
#include "em_iadc.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_burtc.h"
#include "em_acmp.h"
#include "app_process.h"
#include "app_framework_common.h"
#include "app_process.h"
#include "sl_simple_led_instances.h"
#if defined(SL_CATALOG_KERNEL_PRESENT)
#include "sl_component_catalog.h"
#include "sl_power_manager.h"
#endif

EmberStatus applicationSensorRadioInit(void)
{
  EmberStatus status;
  EmberNetworkParameters parameters;
  MEMSET(&parameters, 0, sizeof(EmberNetworkParameters));
  parameters.radioTxPower = 0;
  parameters.radioChannel = 11;
  parameters.panId = 0x01FF;
  status = emberJoinNetwork(EMBER_STAR_SLEEPY_END_DEVICE, &parameters);
  return status;
}
void applicationSensorTxInit(void)
{
  uint8_t buffer[13];
  buffer[0] = 0xFF & (uint8_t) INIT;
  buffer[1] = 0xFF & (uint8_t) (selfInfo.hw);
  buffer[2] = 0xFF & (uint8_t) (selfInfo.state);
  buffer[3] = 0xFF & (uint8_t) (selfInfo.battery_voltage >> 24);
  buffer[4] = 0xFF & (uint8_t) (selfInfo.battery_voltage >> 16);
  buffer[5] = 0xFF & (uint8_t) (selfInfo.battery_voltage >> 8);
  buffer[6] = 0xFF & (uint8_t) (selfInfo.battery_voltage);
  buffer[7] = 0xFF & (uint8_t) (selfInfo.node_type);
  buffer[8] = 0xFF & (uint8_t) (selfInfo.central_id >> 8);
  buffer[9] = 0xFF & (uint8_t) (selfInfo.central_id);
  buffer[10] = 0xFF & (uint8_t) (selfInfo.self_id >> 8);
  buffer[11] = 0xFF & (uint8_t) (selfInfo.self_id);
  buffer[12] = 0xFF & (uint8_t) (selfInfo.endpoint);
  emberMessageSend (selfInfo.central_id,
  1, // endpoint
                    0, // messageTag
                    sizeof(buffer), buffer, tx_options);
}


void applicationSensorTxStartEvent(void)
{
  uint8_t buffer[4];
  buffer[0] = 0xFF & (uint8_t) WARN;
  buffer[1] = 0xFF & (uint8_t) 0;
  buffer[2] = 0xFF & (uint8_t) 0;
  buffer[3] = 0xFF & (uint8_t) selfInfo.state;
  emberMessageSend (selfInfo.central_id,
  1, // endpoint
                    0, // messageTag
                    sizeof(buffer), buffer, tx_options);

}


void applicationSensorTxEndEvent(void)
{
  uint8_t buffer[4];
  buffer[0] = 0xFF & (uint8_t) WARN;
  buffer[1] = 0xFF & (uint8_t) 1;
  buffer[2] = 0xFF & (uint8_t) selfInfo.trigd;
  buffer[3] = 0xFF & (uint8_t) selfInfo.state;
  emberMessageSend (selfInfo.central_id,
  1, // endpoint
                    0, // messageTag
                    sizeof(buffer), buffer, tx_options);
}


void applicationSensorTxRoutine(void)
{
  uint8_t buffer[6];
  buffer[0] = 0xFF & (uint8_t) REPORT;
  buffer[1] = 0xFF & (uint8_t) (selfInfo.battery_voltage >> 24);
  buffer[2] = 0xFF & (uint8_t) (selfInfo.battery_voltage >> 16);
  buffer[3] = 0xFF & (uint8_t) (selfInfo.battery_voltage >> 8);
  buffer[4] = 0xFF & (uint8_t) (selfInfo.battery_voltage);
  buffer[5] = 0xFF & (uint8_t) selfInfo.state;
  emberMessageSend (selfInfo.central_id,
  1, // endpoint
                    0, // messageTag
                    sizeof(buffer), buffer, tx_options);
}

void applicationSensorTxReply(bool success)
{
  uint8_t buffer[3];
  buffer[0] = 0xFF & (uint8_t) REPLY;
  buffer[1] = 0xFF & success;
  buffer[2] = 0xFF & (uint8_t) selfInfo.state;
  emberMessageSend (selfInfo.central_id,
  1, // endpoint
                    0, // messageTag
                    sizeof(buffer), buffer, tx_options);
}

void applicationSensorRxMsg(EmberIncomingMessage *message)
{
  bool success = false;
  if ((message->endpoint == selfInfo.endpoint) || (message->source == selfInfo.central_id))
    {
      switch (message->payload[0])
        {
        case REQUEST:
          {
            switch (message->payload[1])
            {
              case REQ_STATE:
                {
                  if (message->payload[2] == (uint8_t) ACTIVE)
                    {
                      success = (message->payload[2] != selfInfo.state) ? true : false;
                      selfInfo.state = ACTIVE;
                     // NVIC_ClearPendingIRQ (GPIO_ODD_IRQn);
                      //NVIC_EnableIRQ (GPIO_ODD_IRQn);

                    }
                  else if (message->payload[2] == (uint8_t) INACTIVE)
                    {
                      success = (message->payload[2] != selfInfo.state) ? true : false;
                      selfInfo.state = INACTIVE;
                     // NVIC_ClearPendingIRQ (GPIO_ODD_IRQn);
                      //NVIC_DisableIRQ (GPIO_ODD_IRQn);
                    }
                  break;
                }
              case REQ_TXPWR:
                {
                  /* intentionally only accepts uint8_t txpwr so there can be no accidental setting of negative values, which may cause sensor
                  to lose connection with coordinator */
                  success = (emberSetRadioPower((int16_t)message->payload[2], false) == EMBER_SUCCESS ? true : false);
                  break;
                }
            }
            applicationSensorTxReply(success);
            break;
          }
        case SYNC:
          {
            applicationSensorTxInit();
            break;
          }
        default:
          break;
        }
    }
}
