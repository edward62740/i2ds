/***************************************************************************//**
 * @file
 * @brief app_init.c
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
#include "app_init.h"
#include "app_log.h"
#include "sl_app_common.h"
#include "sl_sleeptimer.h"
#include "app_process.h"
#include "app_framework_common.h"
#include "em_iadc.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_prs.h"
#include "em_gpio.h"
#include "em_lesense.h"
#include "em_acmp.h"
#include "em_pcnt.h"
#include "sl_simple_led_instances.h"
// -----------------------------------------------------------------------------
//                              Macros and Typedefs
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
//                          Static Function Declarations
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                                Global Variables
// -----------------------------------------------------------------------------
EmberKeyData security_key = { .contents = SENSOR_SINK_SECURITY_KEY };
// -----------------------------------------------------------------------------
//                                Static Variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                          Public Function Definitions
// -----------------------------------------------------------------------------
/******************************************************************************
 * Application framework init callback
 ******************************************************************************/
void emberAfInitCallback(void)
{
  sl_led_turn_on (&sl_led_stat);
  EmberStatus status;
  emberAfAllocateEvent (&report_control, &report_handler);
  // CLI info message
  app_log_info("\nSensor\n");
  while (status != EMBER_SUCCESS)
    {
      sl_sleeptimer_delay_millisecond (500);
      status = emberNetworkInit ();

    }

  //emberResetNetworkState ();
  sl_sleeptimer_delay_millisecond (100);
  app_log_info("Network status 0x%02X\n", status);

  while (emberSetSecurityKey (&security_key) != EMBER_SUCCESS)
    ;

  app_log_info("Network status 0x%02X\n", status);
  EmberNetworkParameters parameters;
  MEMSET(&parameters, 0, sizeof(EmberNetworkParameters));
  parameters.radioTxPower = 0;
  parameters.radioChannel = 11;
  parameters.panId = 0x01FF;
  status = emberJoinNetwork(EMBER_STAR_SLEEPY_END_DEVICE, &parameters);
  app_log_info("Network status 0x%02X\n", status);

//  emberAfPluginPollEnableShortPolling (true);

  //emberCalibrateCurrentChannel();


 // sl_power_manager_remove_em_requirement (SL_POWER_MANAGER_EM1);
 // sl_power_manager_add_em_requirement (SL_POWER_MANAGER_EM2);
  //CMU_ClockSelectSet(cmuClock_EM23GRPACLK, cmuSelect_FSRCO);
}
// -----------------------------------------------------------------------------
//                          Static Function Definitions
// -----------------------------------------------------------------------------

void startBatteryMonitor(void)
{
  IADC_Init_t init = IADC_INIT_DEFAULT;
  IADC_AllConfigs_t initAllConfigs = IADC_ALLCONFIGS_DEFAULT;
  IADC_InitSingle_t initSingle = IADC_INITSINGLE_DEFAULT;
  // Single input structure
  IADC_SingleInput_t singleInput = IADC_SINGLEINPUT_DEFAULT;

  CMU_ClockEnable (cmuClock_PRS, true);
  PRS_SourceAsyncSignalSet (0,
  PRS_ASYNC_CH_CTRL_SOURCESEL_MODEM,
                            PRS_MODEMH_PRESENT);
  PRS_ConnectConsumer (0, prsTypeAsync, prsConsumerIADC0_SINGLETRIGGER);
  CMU_ClockEnable (cmuClock_IADC0, true);
  initAllConfigs.configs[0].reference = iadcCfgReferenceInt1V2;
  initAllConfigs.configs[0].vRef = 1200;
  initAllConfigs.configs[0].osrHighSpeed = iadcCfgOsrHighSpeed2x;

  initAllConfigs.configs[0].adcClkPrescale = IADC_calcAdcClkPrescale (
      IADC0, 1000000, 0, iadcCfgModeNormal, init.srcClkPrescale);
  initSingle.triggerSelect = iadcTriggerSelPrs0PosEdge;
  initSingle.dataValidLevel = iadcFifoCfgDvl4;
  initSingle.start = true;
  singleInput.posInput = iadcPosInputAvdd;
  singleInput.negInput = iadcNegInputGnd;
  IADC_init (IADC0, &init, &initAllConfigs);
  IADC_initSingle (IADC0, &initSingle, &singleInput);
  IADC_clearInt (IADC0, _IADC_IF_MASK);
  IADC_enableInt (IADC0, IADC_IEN_SINGLEDONE);
  NVIC_ClearPendingIRQ (IADC_IRQn);
  NVIC_SetPriority(GPIO_ODD_IRQn, 7);
  NVIC_EnableIRQ (IADC_IRQn);
}

void startSensorMonitor(void)
{
  CMU_ClockEnable (cmuClock_GPIO, true);
  // Configure Button PB1 as input and enable interrupt
  GPIO_PinModeSet(gpioPortC, 5, gpioModeInputPullFilter, 1);

  /* falling edge interrupt */
  GPIO_EM4EnablePinWakeup(GPIO_IEN_EM4WUIEN7, 0 << _GPIO_IEN_EM4WUIEN7_SHIFT);
  GPIO->IEN = 1 << _GPIO_IEN_EM4WUIEN7_SHIFT;
  GPIO->EM4WUEN = 1 << _GPIO_IEN_EM4WUIEN7_SHIFT;

  /* Enable EVEN interrupt to catch button press */
  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_SetPriority(GPIO_ODD_IRQn, 5);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
}
