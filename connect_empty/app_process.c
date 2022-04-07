/***************************************************************************//**
 * @file
 * @brief app_process.c
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

// -----------------------------------------------------------------------------
//                                   Includes
// -----------------------------------------------------------------------------
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
#include "em_lesense.h"
#include "em_pcnt.h"
#include "app_process.h"
#include "app_framework_common.h"
#include "app_radio.h"
#include "sl_simple_led_instances.h"
#if defined(SL_CATALOG_KERNEL_PRESENT)
#include "sl_component_catalog.h"
#include "sl_power_manager.h"
#endif





// -----------------------------------------------------------------------------
//                              Macros and Typedefs
// -----------------------------------------------------------------------------
#define MAX_TX_FAILURES     (10u)


void initSensorInfo(DeviceInfo *info, device_hw_t hw, sensor_state_t state, uint32_t battery_voltage, EmberNodeType node_type,
                    EmberNodeId central_id, EmberNodeId self_id, uint8_t endpoint, uint8_t trigd) {
  info->hw = hw;
  info->state = state;
  info->battery_voltage = battery_voltage;
  info->node_type = node_type;
  info->central_id = central_id;
  info->self_id = self_id;
  info->endpoint = endpoint;
  info->trigd = trigd;
}

volatile DeviceInfo selfInfo;
volatile bool cooldown = false;
/// Global flag set by a button push to allow or disallow entering to sleep
bool enable_sleep = false;
/// report timing event control
EmberEventControl *report_control;
/// report timing period
uint16_t sensor_report_period_ms =  (5 * MILLISECOND_TICKS_PER_SECOND);
/// TX options set up for the network
EmberMessageOptions tx_options = EMBER_OPTIONS_ACK_REQUESTED | EMBER_OPTIONS_SECURITY_ENABLED;

// -----------------------------------------------------------------------------
//                                Static Variables
// -----------------------------------------------------------------------------
/// Destination of the currently processed sink node


void IADC_IRQHandler(void){
  static volatile IADC_Result_t sample;
  sample = IADC_pullSingleFifoResult(IADC0);
  selfInfo.battery_voltage = (sample.data * 1200)/1000;
  app_log_info(" %d", selfInfo.battery_voltage);
  //app_log_info((uint8_t));
  IADC_clearInt(IADC0, IADC_IF_SINGLEDONE);
}

void GPIO_ODD_IRQHandler(void)
{
  // Get and clear all pending GPIO interrupts
  volatile uint32_t interruptMask = GPIO_IntGet ();
  //GPIO_IntClear(interruptMask);
  GPIO_IntClear (GPIO_IntGet ());
  // Check if button 1 was pressed
 // sl_led_toggle (&sl_led_led1);
  if ((interruptMask & (1 << 5)) && selfInfo.trigd == 0)
    {
      selfInfo.trigd++;
      sl_led_turn_on (&sl_led_inst);
      app_log_info("trigd");
      applicationSensorTxStartEvent ();

       CMU_ClockSelectSet (cmuClock_EM4GRPACLK, cmuSelect_ULFRCO);
       CMU_ClockEnable (cmuClock_BURTC, true);
       CMU_ClockEnable (cmuClock_BURAM, true);

       BURTC_Init_TypeDef burtcInit = BURTC_INIT_DEFAULT;
       burtcInit.compare0Top = true; // reset counter when counter reaches compare value
       burtcInit.em4comp = true; // BURTC compare interrupt wakes from EM4 (causes reset)
       BURTC_Init (&burtcInit);
       BURTC_CounterReset ();
       BURTC_CompareSet (0, 2600);
       BURTC_IntEnable (BURTC_IEN_COMP);    // compare match
       NVIC_EnableIRQ (BURTC_IRQn);
       BURTC_Enable (true);
    }
  else if ((interruptMask & (1 << 5)) && selfInfo.trigd > 0)
    {
      selfInfo.trigd++;
      app_log_info("again");
      BURTC_CounterReset ();
    }
  //sl_power_manager_remove_em_requirement (SL_POWER_MANAGER_EM1);
  sl_power_manager_add_em_requirement (SL_POWER_MANAGER_EM2);
}




void BURTC_IRQHandler(void)
{
  NVIC_ClearPendingIRQ (GPIO_ODD_IRQn);
  NVIC_DisableIRQ (GPIO_ODD_IRQn);
  if (selfInfo.trigd > 0)
    {
      BURTC_CounterReset ();
      BURTC_CompareSet (0, 1300);
      BURTC_IntEnable (BURTC_IEN_COMP);    // compare match
      BURTC_IntClear (BURTC_IntGet ());
      NVIC_EnableIRQ (BURTC_IRQn);
      BURTC_Enable (true);
      applicationSensorTxEndEvent ();
      app_log_info("COOLDOWN");
      selfInfo.trigd = 0;
    }
  else
    {
      BURTC_CounterReset ();
      BURTC_CompareSet (0, 2600);
      NVIC_DisableIRQ (BURTC_IRQn);
      BURTC_Enable (false);
      BURTC_IntClear (BURTC_IF_COMP); // compare match
      app_log_info("END");
      NVIC_ClearPendingIRQ (GPIO_ODD_IRQn);
      NVIC_EnableIRQ (GPIO_ODD_IRQn);
    }
}
// -----------------------------------------------------------------------------
//                          Public Function Definitions
// -----------------------------------------------------------------------------

/**************************************************************************//**
 * Here we print out the first two bytes reported by the sinks as a little
 * endian 16-bits decimal.
 *****************************************************************************/
void report_handler(void)
{

  // sl_power_manager_remove_em_requirement (SL_POWER_MANAGER_EM1);
   //sl_power_manager_add_em_requirement (SL_POWER_MANAGER_EM2);
  if (!emberStackIsUp()) {
    emberEventControlSetInactive(*report_control);
  } else {
      sl_led_turn_on(&sl_led_inst);
      applicationSensorTxRoutine();
      //app_log_info("poll");
     // NVIC_DisableIRQ(IADC_IRQn);
      //emberPollForData();
     // NVIC_ClearPendingIRQ(IADC_IRQn);
         //   NVIC_EnableIRQ(IADC_IRQn);
     // IADC_command(IADC0, iadcCmdStartSingle);
      emberEventControlSetDelayMS(*report_control, sensor_report_period_ms);
  }
}

/**************************************************************************//**
 * Entering sleep is approved or denied in this callback, depending on user
 * demand.
 *****************************************************************************/
bool emberAfCommonOkToEnterLowPowerCallback(bool enter_em2, uint32_t duration_ms)
{
  (void) enter_em2;
  (void) duration_ms;
  return true;
}

/**************************************************************************//**
 * This function is called when a message is received.
 *****************************************************************************/
void emberAfIncomingMessageCallback (EmberIncomingMessage *message)
{

  sl_led_turn_on(&sl_led_inst0);
  applicationSensorRxMsg(&(*message));
}

/**************************************************************************//**
 * This function is called to indicate whether an outgoing message was
 * successfully transmitted or to indicate the reason of failure.
 *****************************************************************************/
void emberAfMessageSentCallback(EmberStatus status,
                                EmberOutgoingMessage *message)
{
  (void) message;
  if (status != EMBER_SUCCESS) {
  }
  sl_led_turn_off(&sl_led_inst);
  sl_led_turn_off(&sl_led_inst0);
}

/**************************************************************************//**
 * This function is called when the stack status changes.
 *****************************************************************************/
void emberAfStackStatusCallback(EmberStatus status)
{
  switch (status)
    {
    case EMBER_NETWORK_UP:
      app_log_info("Network up\n");
      app_log_info("Joined to Sink with node ID: 0x%04X\n", emberGetNodeId());
      initSensorInfo (&selfInfo, PIRSN, ACTIVE, 0, emberGetNodeType(),
      EMBER_COORDINATOR_ADDRESS,
                      emberGetNodeId(), 1, 0);
      // Schedule start of periodic sensor reporting to the Sink
      emberEventControlSetDelayMS(*report_control, sensor_report_period_ms);
      startBatteryMonitor ();
       startSensorMonitor ();


      applicationSensorTxInit ();
      break;
    case EMBER_NETWORK_DOWN:
      {
        sl_led_turn_on (&sl_led_inst0);
        app_log_info("Join process timed out!\n");
        EmberNetworkParameters parameters;
        status = applicationSensorRadioInit ();
        app_log_info("Network status 0x%02X\n", status);
        sl_led_turn_off (&sl_led_inst0);
      }
      break;
    case EMBER_JOIN_SCAN_FAILED:
      app_log_error("Scanning during join failed\n");
      break;
    case EMBER_JOIN_DENIED:
      app_log_error("Joining to the network rejected!\n");
      break;
    case EMBER_JOIN_TIMEOUT:

      {
        sl_led_turn_on (&sl_led_inst0);
        app_log_info("Join process timed out!\n");
        status = applicationSensorRadioInit ();
        app_log_info("Network status 0x%02X\n", status);
        sl_led_turn_off (&sl_led_inst0);
      }
      break;
    default:
      {
        sl_led_turn_on (&sl_led_inst0);
        app_log_info("Stack status: 0x%02X\n", status);
        status = applicationSensorRadioInit ();
        app_log_info("Network status 0x%02X\n", status);
        sl_led_turn_off (&sl_led_inst0);
      }
      break;
    }
}

/**************************************************************************//**
 * This callback is called in each iteration of the main application loop and
 * can be used to perform periodic functions.
 *****************************************************************************/
void emberAfTickCallback(void)
{

}

/**************************************************************************//**
 * This function is called when a frequency hopping client completed the start
 * procedure.
 *****************************************************************************/
void emberAfFrequencyHoppingStartClientCompleteCallback(EmberStatus status)
{
  if (status != EMBER_SUCCESS) {
    app_log_error("FH Client sync failed, status=0x%02X\n", status);
  } else {
    app_log_info("FH Client Sync Success\n");
  }
}



/**************************************************************************//**
 * This function is called when a requested energy scan is complete.
 *****************************************************************************/
void emberAfEnergyScanCompleteCallback(int8_t mean,
                                       int8_t min,
                                       int8_t max,
                                       uint16_t variance)
{
  app_log_info("Energy scan complete, mean=%d min=%d max=%d var=%d\n",
               mean, min, max, variance);
}
#if defined(EMBER_AF_PLUGIN_MICRIUM_RTOS) && defined(EMBER_AF_PLUGIN_MICRIUM_RTOS_APP_TASK1)

/**************************************************************************//**
 * This function is called from the Micrium RTOS plugin before the
 * Application (1) task is created.
 *****************************************************************************/
void emberAfPluginMicriumRtosAppTask1InitCallback(void)
{
  app_log_info("app task init\n");
}

#include <kernel/include/os.h>
#define TICK_INTERVAL_MS 1000

/**************************************************************************//**
 * This function implements the Application (1) task main loop.
 *****************************************************************************/
void emberAfPluginMicriumRtosAppTask1MainLoopCallback(void *p_arg)
{
  RTOS_ERR err;
  OS_TICK yield_time_ticks = (OSCfg_TickRate_Hz * TICK_INTERVAL_MS) / 1000;

  while (true) {
    app_log_info("app task tick\n");

    OSTimeDly(yield_time_ticks, OS_OPT_TIME_DLY, &err);
  }
}

#endif // EMBER_AF_PLUGIN_MICRIUM_RTOS && EMBER_AF_PLUGIN_MICRIUM_RTOS_APP_TASK1
