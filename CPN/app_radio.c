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


void applicationCoordinatorTxRequest(EmberNodeId id, message_request_t type, uint8_t val)
{
  app_log_info("sending ... \n" );
  uint8_t buffer[3];
  buffer[0] = 0xFF & (uint8_t) MSG_REQUEST;
  buffer[1] = 0xFF & (uint8_t) type;
  buffer[2] = 0xFF & (uint8_t) val;
  emberMessageSend (id,
  SENSOR_SINK_ENDPOINT, // endpoint
                    0, // messageTag
                    sizeof(buffer), buffer, tx_options);
}

void applicationCoordinatorRxMsg(EmberIncomingMessage *message)
{
  if ((message->endpoint != SENSOR_SINK_ENDPOINT)
        || ((tx_options & EMBER_OPTIONS_SECURITY_ENABLED)
            && !(message->options & EMBER_OPTIONS_SECURITY_ENABLED))) {
      // drop the message if it's not coming from a sensor
      // or if security is required but the message is non-encrypted
      return;
    }
    uint8_t buffer[message->length];
    //app_log_info("RX: Data from 0x%04X:", message->source);
    //app_log_info("rssi: %d, lqi: %d", message->rssi, message->lqi);
    for (int j = 0; j < message->length; j++) {
      //app_log_info(" %02X", message->payload[j]);
      buffer[j] = message->payload[j];
    }
    switch (buffer[0])
      {
      case MSG_REPORT:
        {
          uint32_t data = buffer[1] << 24;
          data |= buffer[2] << 16;
          data |= buffer[3] << 8;
          data |= buffer[4];
          uint8_t state = buffer[5];
          uint8_t iter = 0;
          for (uint8_t i = 0; i < (uint8_t) MAX_CONNECTED_DEVICES; i++)
            {
              if (sensorInfo[i].self_id == message->source)
                {
                  sensorInfo[i].battery_voltage = data;
                  break;
                }
              else
                {
                  iter++;
                }
            }
          app_log_info(" Voltage: %d, State: %d \n", data, state);
        break;
        }
      case MSG_REPLY:
        {
          uint8_t info = buffer[1];
        app_log_info(" Ack %d \n", info);
        break;
        }
      case MSG_WARN:
        {
          uint8_t info = buffer[1];
          if(info == 0){
              app_log_info(" Warning started %d \n", info);
          }
          else {
              app_log_info(" Warning ended with %d trigs \n", buffer[2]);
          }

          break;
        }
      case MSG_INIT:
        {
          uint8_t hw = buffer[1];
          uint8_t state = buffer[2];
          uint32_t battery = buffer[3] << 24;
          battery |= buffer[4] << 16;
          battery |= buffer[5] << 8;
          battery |= buffer[6];
          uint8_t nt = buffer[7];
          uint16_t cid = buffer[8] << 8;
          cid |= buffer[9];
          uint16_t sid = buffer[10] << 8;
          sid |= buffer[11];
          uint8_t ep = buffer[12];
          uint8_t iter = 0;
          for (uint8_t i = 0; i < (uint8_t)MAX_CONNECTED_DEVICES; i++)
            {
              if (sensorInfo[i].self_id == message->source)
                {
                  sensorInfo[i].hw = buffer[1];
                  sensorInfo[i].state = buffer[2];
                  sensorInfo[i].battery_voltage = battery;
                  sensorInfo[i].node_type = buffer[7];
                  sensorInfo[i].central_id = cid;
                  sensorInfo[i].self_id = sid;
                  sensorInfo[i].endpoint = buffer[12];
                  app_log_info("Updated device %d ", sid);
                  break;
                }
              else
                {
                  iter++;
                }
            }
          app_log_info("icnt %d ", iter);
          if(iter == (uint8_t)MAX_CONNECTED_DEVICES){
              sensorInfo[sensorIndex].hw = buffer[1];
              sensorInfo[sensorIndex].state = buffer[2];
              sensorInfo[sensorIndex].battery_voltage = battery;
              sensorInfo[sensorIndex].node_type = buffer[7];
              sensorInfo[sensorIndex].central_id = cid;
              sensorInfo[sensorIndex].self_id = sid;
              sensorInfo[sensorIndex].endpoint = buffer[12];
              sensorIndex++;
              app_log_info("Added new device %d ", sid);
          }
          app_log_info(
              " INIT -> State: %d, HW: %d, Voltage: %d, Nodetype: %d, CID: %d, SID: %d, ENDP: %d \n",
              state, hw, battery, nt, cid, sid, ep);
          break;
        }

      default:
        break;
      }


}
