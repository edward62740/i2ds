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
#include "app_log.h"
#include "sl_app_common.h"
#include "stack/include/ember.h"
#include "app_process.h"
#include "app_framework_common.h"
#include "sl_simple_led_instances.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_eusart.h"
// -----------------------------------------------------------------------------
//                              Macros and Typedefs
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                          Static Function Declarations
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                                Global Variables
// -----------------------------------------------------------------------------

/// Data dump period  event control
extern EmberEventControl *data_report_control;

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
  // CLI info message
  app_log_info("\nSink\n");


  EmberStatus status;
  status = 0x01;

  while(status != (EMBER_SUCCESS || EMBER_NOT_JOINED))
    {
      status = emberNetworkInit();
      sl_sleeptimer_delay_millisecond(500);
      app_log_info("init Network status 0x%02X\n", status);
    }
  status = 0x01;
  emberResetNetworkState ();

#if defined(EMBER_AF_PLUGIN_BLE)
  bleConnectionInfoTableInit();
#endif
}

void startIPC(void)
{
  CMU_ClockEnable (cmuClock_GPIO, true);
  CMU_ClockEnable (cmuClock_EUSART1, true);
  GPIO_PinModeSet (gpioPortC, 4, gpioModePushPull, 1);
  // Configure the EUSART RX pin to the board controller as an input
  GPIO_PinModeSet (gpioPortC, 6, gpioModeInput, 0);
  EUSART_UartInit_TypeDef init = EUSART_UART_INIT_DEFAULT_HF;

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
