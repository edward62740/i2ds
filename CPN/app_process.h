/***************************************************************************//**
 * @file
 * @brief app_process.h
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
#ifndef APP_PROCESS_H
#define APP_PROCESS_H
#include "stack/include/ember.h"
#include "hal/hal.h"
#include "em_chip.h"
#include "app_log.h"
#include "sl_app_common.h"
#include "app_framework_common.h"
#include "sl_simple_led_instances.h"
#include "app_process.h"
// -----------------------------------------------------------------------------
//                                   Includes
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                              Macros and Typedefs
// -----------------------------------------------------------------------------
#define MAX_CONNECTED_DEVICES     (30u)
typedef enum {     /* Packet identifier byte */
  INIT,            // (S -> C) notify sensor type and features
  REPORT,          // (S -> C) report battery levels and status
  WARN = 0x9A,     // (S -> C) report triggered sensor
  REQUEST,         // (S <- C) request change status
  REPLY,           // (S <- C) ack REQUEST
  SYNC = 0xFF,     // (S <- C) request INIT
} message_pid_t;

typedef enum {     /* Sensor state byte */
  ACTIVE = 0x05,   // Sensor element active
  INACTIVE,        // Sensor element inactive
  FAULT_HW = 0xCA, // Hardware fault detected
  FAULT_OPN,       // Operational fault detected
} sensor_state_t;

typedef enum {     /* Hardware identification byte */
  CPN = 0x88,      // Control Panel Node (Coordinator)
  PIRSN,           // PIR Sensor Node (Sensor)
  ACSN,            // Access Control Sensor Node (Sensor)
} device_hw_t ;

typedef enum {     /* Request identifier byte */
  REQ_STATE,       // Request state change
  REQ_TXPWR,       // Request change of radio transmit power in positive deci-dbm
  REQ_REPORT,      // Request REPORT packet
  REQ_LED,         // Request enable/disable LEDs
}  message_request_t;

typedef struct {   /* Sensor info */
  device_hw_t hw;
  sensor_state_t state;
  uint32_t battery_voltage;
  EmberNodeType node_type;
  EmberNodeId central_id;
  EmberNodeId self_id;
  uint8_t endpoint;
  uint8_t trigd;
} DeviceInfo;

extern DeviceInfo selfInfo, sensorInfo[MAX_CONNECTED_DEVICES];
extern uint8_t sensorIndex;
// -----------------------------------------------------------------------------
//                                Global Variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                          Public Function Declarations
// -----------------------------------------------------------------------------

/**************************************************************************//**
 * The function is used for Application logic.
 *
 * @param None
 * @returns None
 *
 * Here we print out the first two bytes reported by the sinks as a little
 * endian 16-bits decimal.
 *****************************************************************************/
void data_report_handler(void);

/**************************************************************************//**
 * The function is used for Application logic.
 *
 * @param None
 * @returns None
 *
 * An advertisement message consists of the sensor/sink protocol id, the
 * advertisement command id, and the long and short ids of the sink.  Each sink
 * on the network periodically broadcasts its advertisement to all other nodes.
 *****************************************************************************/
void advertise_handler(void);

/**************************************************************************//**
 * The function is used for Application logic.
 *
 * @param None
 * @returns None
 *
 * Housekeeping init of the sensor data.
 *****************************************************************************/
void sink_init(void);
void report_handler(void);
void initSensorInfo(DeviceInfo *info, device_hw_t hw, sensor_state_t state, uint32_t battery_voltage, EmberNodeType node_type,
                    EmberNodeId central_id, EmberNodeId self_id, uint8_t endpoint);

#endif  // APP_PROCESS_H
