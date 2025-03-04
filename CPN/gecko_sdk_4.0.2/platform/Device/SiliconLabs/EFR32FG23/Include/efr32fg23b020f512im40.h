/**************************************************************************//**
 * @file
 * @brief CMSIS Cortex-M Peripheral Access Layer Header File
 *        for EFR32FG23B020F512IM40
 ******************************************************************************
 * # License
 * <b>Copyright 2022 Silicon Laboratories, Inc. www.silabs.com</b>
 ******************************************************************************
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
 *****************************************************************************/
#ifndef EFR32FG23B020F512IM40_H
#define EFR32FG23B020F512IM40_H

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************//**
 * @addtogroup Parts
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @defgroup EFR32FG23B020F512IM40 EFR32FG23B020F512IM40
 * @{
 *****************************************************************************/

/** Interrupt Number Definition */
typedef enum IRQn{
  /******  Cortex-M Processor Exceptions Numbers ******************************************/
  NonMaskableInt_IRQn    = -14,             /*!< -14 Cortex-M Non Maskable Interrupt      */
  HardFault_IRQn         = -13,             /*!< -13 Cortex-M Hard Fault Interrupt        */
  MemoryManagement_IRQn  = -12,             /*!< -12 Cortex-M Memory Management Interrupt */
  BusFault_IRQn          = -11,             /*!< -11 Cortex-M Bus Fault Interrupt         */
  UsageFault_IRQn        = -10,             /*!< -10 Cortex-M Usage Fault Interrupt       */
  SVCall_IRQn            = -5,              /*!< -5  Cortex-M SV Call Interrupt           */
  DebugMonitor_IRQn      = -4,              /*!< -4  Cortex-M Debug Monitor Interrupt     */
  PendSV_IRQn            = -2,              /*!< -2  Cortex-M Pend SV Interrupt           */
  SysTick_IRQn           = -1,              /*!< -1  Cortex-M System Tick Interrupt       */

  /******  EFR32FG23 Peripheral Interrupt Numbers ******************************************/

  SMU_SECURE_IRQn        = 0,  /*!<  0 EFR32 SMU_SECURE Interrupt */
  SMU_PRIVILEGED_IRQn    = 1,  /*!<  1 EFR32 SMU_PRIVILEGED Interrupt */
  SMU_NS_PRIVILEGED_IRQn = 2,  /*!<  2 EFR32 SMU_NS_PRIVILEGED Interrupt */
  EMU_IRQn               = 3,  /*!<  3 EFR32 EMU Interrupt */
  TIMER0_IRQn            = 4,  /*!<  4 EFR32 TIMER0 Interrupt */
  TIMER1_IRQn            = 5,  /*!<  5 EFR32 TIMER1 Interrupt */
  TIMER2_IRQn            = 6,  /*!<  6 EFR32 TIMER2 Interrupt */
  TIMER3_IRQn            = 7,  /*!<  7 EFR32 TIMER3 Interrupt */
  TIMER4_IRQn            = 8,  /*!<  8 EFR32 TIMER4 Interrupt */
  USART0_RX_IRQn         = 9,  /*!<  9 EFR32 USART0_RX Interrupt */
  USART0_TX_IRQn         = 10, /*!< 10 EFR32 USART0_TX Interrupt */
  EUSART0_RX_IRQn        = 11, /*!< 11 EFR32 EUSART0_RX Interrupt */
  EUSART0_TX_IRQn        = 12, /*!< 12 EFR32 EUSART0_TX Interrupt */
  EUSART1_RX_IRQn        = 13, /*!< 13 EFR32 EUSART1_RX Interrupt */
  EUSART1_TX_IRQn        = 14, /*!< 14 EFR32 EUSART1_TX Interrupt */
  EUSART2_RX_IRQn        = 15, /*!< 15 EFR32 EUSART2_RX Interrupt */
  EUSART2_TX_IRQn        = 16, /*!< 16 EFR32 EUSART2_TX Interrupt */
  ICACHE0_IRQn           = 17, /*!< 17 EFR32 ICACHE0 Interrupt */
  BURTC_IRQn             = 18, /*!< 18 EFR32 BURTC Interrupt */
  LETIMER0_IRQn          = 19, /*!< 19 EFR32 LETIMER0 Interrupt */
  SYSCFG_IRQn            = 20, /*!< 20 EFR32 SYSCFG Interrupt */
  MPAHBRAM_IRQn          = 21, /*!< 21 EFR32 MPAHBRAM Interrupt */
  LDMA_IRQn              = 22, /*!< 22 EFR32 LDMA Interrupt */
  LFXO_IRQn              = 23, /*!< 23 EFR32 LFXO Interrupt */
  LFRCO_IRQn             = 24, /*!< 24 EFR32 LFRCO Interrupt */
  ULFRCO_IRQn            = 25, /*!< 25 EFR32 ULFRCO Interrupt */
  GPIO_ODD_IRQn          = 26, /*!< 26 EFR32 GPIO_ODD Interrupt */
  GPIO_EVEN_IRQn         = 27, /*!< 27 EFR32 GPIO_EVEN Interrupt */
  I2C0_IRQn              = 28, /*!< 28 EFR32 I2C0 Interrupt */
  I2C1_IRQn              = 29, /*!< 29 EFR32 I2C1 Interrupt */
  EMUDG_IRQn             = 30, /*!< 30 EFR32 EMUDG Interrupt */
  AGC_IRQn               = 31, /*!< 31 EFR32 AGC Interrupt */
  BUFC_IRQn              = 32, /*!< 32 EFR32 BUFC Interrupt */
  FRC_PRI_IRQn           = 33, /*!< 33 EFR32 FRC_PRI Interrupt */
  FRC_IRQn               = 34, /*!< 34 EFR32 FRC Interrupt */
  MODEM_IRQn             = 35, /*!< 35 EFR32 MODEM Interrupt */
  PROTIMER_IRQn          = 36, /*!< 36 EFR32 PROTIMER Interrupt */
  RAC_RSM_IRQn           = 37, /*!< 37 EFR32 RAC_RSM Interrupt */
  RAC_SEQ_IRQn           = 38, /*!< 38 EFR32 RAC_SEQ Interrupt */
  HOSTMAILBOX_IRQn       = 39, /*!< 39 EFR32 HOSTMAILBOX Interrupt */
  SYNTH_IRQn             = 40, /*!< 40 EFR32 SYNTH Interrupt */
  ACMP0_IRQn             = 41, /*!< 41 EFR32 ACMP0 Interrupt */
  ACMP1_IRQn             = 42, /*!< 42 EFR32 ACMP1 Interrupt */
  WDOG0_IRQn             = 43, /*!< 43 EFR32 WDOG0 Interrupt */
  WDOG1_IRQn             = 44, /*!< 44 EFR32 WDOG1 Interrupt */
  HFXO0_IRQn             = 45, /*!< 45 EFR32 HFXO0 Interrupt */
  HFRCO0_IRQn            = 46, /*!< 46 EFR32 HFRCO0 Interrupt */
  HFRCOEM23_IRQn         = 47, /*!< 47 EFR32 HFRCOEM23 Interrupt */
  CMU_IRQn               = 48, /*!< 48 EFR32 CMU Interrupt */
  AES_IRQn               = 49, /*!< 49 EFR32 AES Interrupt */
  IADC_IRQn              = 50, /*!< 50 EFR32 IADC Interrupt */
  MSC_IRQn               = 51, /*!< 51 EFR32 MSC Interrupt */
  DPLL0_IRQn             = 52, /*!< 52 EFR32 DPLL0 Interrupt */
  EMUEFP_IRQn            = 53, /*!< 53 EFR32 EMUEFP Interrupt */
  DCDC_IRQn              = 54, /*!< 54 EFR32 DCDC Interrupt */
  VDAC_IRQn              = 55, /*!< 55 EFR32 VDAC Interrupt */
  PCNT0_IRQn             = 56, /*!< 56 EFR32 PCNT0 Interrupt */
  SW0_IRQn               = 57, /*!< 57 EFR32 SW0 Interrupt */
  SW1_IRQn               = 58, /*!< 58 EFR32 SW1 Interrupt */
  SW2_IRQn               = 59, /*!< 59 EFR32 SW2 Interrupt */
  SW3_IRQn               = 60, /*!< 60 EFR32 SW3 Interrupt */
  KERNEL0_IRQn           = 61, /*!< 61 EFR32 KERNEL0 Interrupt */
  KERNEL1_IRQn           = 62, /*!< 62 EFR32 KERNEL1 Interrupt */
  M33CTI0_IRQn           = 63, /*!< 63 EFR32 M33CTI0 Interrupt */
  M33CTI1_IRQn           = 64, /*!< 64 EFR32 M33CTI1 Interrupt */
  FPUEXH_IRQn            = 65, /*!< 65 EFR32 FPUEXH Interrupt */
  SETAMPERHOST_IRQn      = 66, /*!< 66 EFR32 SETAMPERHOST Interrupt */
  SEMBRX_IRQn            = 67, /*!< 67 EFR32 SEMBRX Interrupt */
  SEMBTX_IRQn            = 68, /*!< 68 EFR32 SEMBTX Interrupt */
  LESENSE_IRQn           = 69, /*!< 69 EFR32 LESENSE Interrupt */
  SYSRTC_APP_IRQn        = 70, /*!< 70 EFR32 SYSRTC_APP Interrupt */
  SYSRTC_SEQ_IRQn        = 71, /*!< 71 EFR32 SYSRTC_SEQ Interrupt */
  LCD_IRQn               = 72, /*!< 72 EFR32 LCD Interrupt */
  KEYSCAN_IRQn           = 73, /*!< 73 EFR32 KEYSCAN Interrupt */
  RFECA0_IRQn            = 74, /*!< 74 EFR32 RFECA0 Interrupt */
  RFECA1_IRQn            = 75, /*!< 75 EFR32 RFECA1 Interrupt */
} IRQn_Type;

/**************************************************************************//**
 * @defgroup EFR32FG23B020F512IM40_Core EFR32FG23B020F512IM40 Core
 * @{
 * @brief Processor and Core Peripheral Section
 *****************************************************************************/

#define __CM33_REV                0x0004U /**< Cortex-M33 Core revision */
#define __DSP_PRESENT             1U      /**< Presence of DSP  */
#define __FPU_PRESENT             1U      /**< Presence of FPU  */
#define __MPU_PRESENT             1U      /**< Presence of MPU  */
#define __SAUREGION_PRESENT       1U      /**< Presence of FPU  */
#define __TZ_PRESENT              1U      /**< Presence of TrustZone */
#define __VTOR_PRESENT            1U      /**< Presence of VTOR register in SCB  */
#define __NVIC_PRIO_BITS          4U      /**< NVIC interrupt priority bits */
#define __Vendor_SysTickConfig    0U      /**< Is 1 if different SysTick counter is used */

/** @} End of group EFR32FG23B020F512IM40_Core */

/**************************************************************************//**
* @defgroup EFR32FG23B020F512IM40_Part EFR32FG23B020F512IM40 Part
* @{
******************************************************************************/

/** Part number */

/* If part number is not defined as compiler option, define it */
#if !defined(EFR32FG23B020F512IM40)
#define EFR32FG23B020F512IM40    1 /**< FULL Part */
#endif

/** Configure part number */
#define PART_NUMBER                                        "EFR32FG23B020F512IM40" /**< Part Number */

/** Family / Line / Series / Config */
#define _EFR32_FLEX_FAMILY                                 1                                    /** Device Family Name Identifier */
#define _EFR32_FG_FAMILY                                   1                                    /** Device Family Identifier */
#define _EFR_DEVICE                                        1                                    /** Product Line Identifier */
#define _SILICON_LABS_32B_SERIES_2                                                              /** Product Series Identifier */
#define _SILICON_LABS_32B_SERIES                           2                                    /** Product Series Identifier */
#define _SILICON_LABS_32B_SERIES_2_CONFIG_3                                                     /** Product Config Identifier */
#define _SILICON_LABS_32B_SERIES_2_CONFIG                  3                                    /** Product Config Identifier */
#define _SILICON_LABS_GECKO_█████████_SDID                  210                                  /** Silicon Labs internal use only */
#define _SILICON_LABS_GECKO_█████████_SDID_210                                                   /** Silicon Labs internal use only */
#define _SILICON_LABS_SECURITY_FEATURE_SE                  0                                    /** Mid */
#define _SILICON_LABS_SECURITY_FEATURE_VAULT               1                                    /** High */
#define _SILICON_LABS_SECURITY_FEATURE_ROT                 2                                    /** Root of Trust */
#define _SILICON_LABS_SECURITY_FEATURE                     _SILICON_LABS_SECURITY_FEATURE_VAULT /** Security feature set */
#define _SILICON_LABS_EFR32_RADIO_NONE                     0                                    /** No radio present */
#define _SILICON_LABS_EFR32_RADIO_SUBGHZ                   1                                    /** Radio supports Sub-GHz */
#define _SILICON_LABS_EFR32_RADIO_2G4HZ                    2                                    /** Radio supports 2.4 GHz */
#define _SILICON_LABS_EFR32_RADIO_DUALBAND                 3                                    /** Radio supports dual band */
#define _SILICON_LABS_EFR32_RADIO_TYPE                     _SILICON_LABS_EFR32_RADIO_SUBGHZ     /** Radio type */
#define _SILICON_LABS_EFR32_SUBGHZ_HP_PA_MAX_OUTPUT_DBM    20                                   /** Radio SUBGHZ HP PA output power */
#define _SILICON_LABS_EFR32_SUBGHZ_HP_PA_PRESENT                                                /** Radio SUBGHZ HP PA is present */

/** Memory Base addresses and limits */
#define FLASH_MEM_BASE                                     (0x08000000UL) /** FLASH_MEM base address */
#define FLASH_MEM_SIZE                                     (0x00080000UL) /** FLASH_MEM available address space */
#define FLASH_MEM_END                                      (0x0807FFFFUL) /** FLASH_MEM end address */
#define FLASH_MEM_BITS                                     (0x14UL)       /** FLASH_MEM used bits */
#define MSC_FLASH_MEM_BASE                                 (0x08000000UL) /** MSC_FLASH_MEM base address */
#define MSC_FLASH_MEM_SIZE                                 (0x00080000UL) /** MSC_FLASH_MEM available address space */
#define MSC_FLASH_MEM_END                                  (0x0807FFFFUL) /** MSC_FLASH_MEM end address */
#define MSC_FLASH_MEM_BITS                                 (0x14UL)       /** MSC_FLASH_MEM used bits */
#define MSC_FLASH_USERDATA_MEM_BASE                        (0x0FE00000UL) /** MSC_FLASH_USERDATA_MEM base address */
#define MSC_FLASH_USERDATA_MEM_SIZE                        (0x00000400UL) /** MSC_FLASH_USERDATA_MEM available address space */
#define MSC_FLASH_USERDATA_MEM_END                         (0x0FE003FFUL) /** MSC_FLASH_USERDATA_MEM end address */
#define MSC_FLASH_USERDATA_MEM_BITS                        (0xBUL)        /** MSC_FLASH_USERDATA_MEM used bits */
#define USERDATA_BASE                                      (0x0FE00000UL) /** USERDATA base address */
#define USERDATA_SIZE                                      (0x00000400UL) /** USERDATA available address space */
#define USERDATA_END                                       (0x0FE003FFUL) /** USERDATA end address */
#define USERDATA_BITS                                      (0xBUL)        /** USERDATA used bits */
#define MSC_FLASH_DEVINFO_MEM_BASE                         (0x0FE08000UL) /** MSC_FLASH_DEVINFO_MEM base address */
#define MSC_FLASH_DEVINFO_MEM_SIZE                         (0x00000400UL) /** MSC_FLASH_DEVINFO_MEM available address space */
#define MSC_FLASH_DEVINFO_MEM_END                          (0x0FE083FFUL) /** MSC_FLASH_DEVINFO_MEM end address */
#define MSC_FLASH_DEVINFO_MEM_BITS                         (0xBUL)        /** MSC_FLASH_DEVINFO_MEM used bits */
#define MSC_FLASH_CHIPCONFIG_MEM_BASE                      (0x0FE08400UL) /** MSC_FLASH_CHIPCONFIG_MEM base address */
#define MSC_FLASH_CHIPCONFIG_MEM_SIZE                      (0x00000600UL) /** MSC_FLASH_CHIPCONFIG_MEM available address space */
#define MSC_FLASH_CHIPCONFIG_MEM_END                       (0x0FE089FFUL) /** MSC_FLASH_CHIPCONFIG_MEM end address */
#define MSC_FLASH_CHIPCONFIG_MEM_BITS                      (0xBUL)        /** MSC_FLASH_CHIPCONFIG_MEM used bits */
#define DMEM_RAM0_RAM_MEM_BASE                             (0x20000000UL) /** DMEM_RAM0_RAM_MEM base address */
#define DMEM_RAM0_RAM_MEM_SIZE                             (0x00010000UL) /** DMEM_RAM0_RAM_MEM available address space */
#define DMEM_RAM0_RAM_MEM_END                              (0x2000FFFFUL) /** DMEM_RAM0_RAM_MEM end address */
#define DMEM_RAM0_RAM_MEM_BITS                             (0x11UL)       /** DMEM_RAM0_RAM_MEM used bits */
#define RAM_MEM_BASE                                       (0x20000000UL) /** RAM_MEM base address */
#define RAM_MEM_SIZE                                       (0x00010000UL) /** RAM_MEM available address space */
#define RAM_MEM_END                                        (0x2000FFFFUL) /** RAM_MEM end address */
#define RAM_MEM_BITS                                       (0x11UL)       /** RAM_MEM used bits */
#define RDMEM_SEQRAM_S_MEM_BASE                            (0xA0000000UL) /** RDMEM_SEQRAM_S_MEM base address */
#define RDMEM_SEQRAM_S_MEM_SIZE                            (0x00004000UL) /** RDMEM_SEQRAM_S_MEM available address space */
#define RDMEM_SEQRAM_S_MEM_END                             (0xA0003FFFUL) /** RDMEM_SEQRAM_S_MEM end address */
#define RDMEM_SEQRAM_S_MEM_BITS                            (0xFUL)        /** RDMEM_SEQRAM_S_MEM used bits */
#define RDMEM_FRCRAM_S_MEM_BASE                            (0xA0004000UL) /** RDMEM_FRCRAM_S_MEM base address */
#define RDMEM_FRCRAM_S_MEM_SIZE                            (0x00001000UL) /** RDMEM_FRCRAM_S_MEM available address space */
#define RDMEM_FRCRAM_S_MEM_END                             (0xA0004FFFUL) /** RDMEM_FRCRAM_S_MEM end address */
#define RDMEM_FRCRAM_S_MEM_BITS                            (0xDUL)        /** RDMEM_FRCRAM_S_MEM used bits */
#define RDMEM_SEQRAM_NS_MEM_BASE                           (0xB0000000UL) /** RDMEM_SEQRAM_NS_MEM base address */
#define RDMEM_SEQRAM_NS_MEM_SIZE                           (0x00004000UL) /** RDMEM_SEQRAM_NS_MEM available address space */
#define RDMEM_SEQRAM_NS_MEM_END                            (0xB0003FFFUL) /** RDMEM_SEQRAM_NS_MEM end address */
#define RDMEM_SEQRAM_NS_MEM_BITS                           (0xFUL)        /** RDMEM_SEQRAM_NS_MEM used bits */
#define RDMEM_SEQRAM_SEQRAM_MEM_BASE                       (0xB0000000UL) /** RDMEM_SEQRAM_SEQRAM_MEM base address */
#define RDMEM_SEQRAM_SEQRAM_MEM_SIZE                       (0x00004000UL) /** RDMEM_SEQRAM_SEQRAM_MEM available address space */
#define RDMEM_SEQRAM_SEQRAM_MEM_END                        (0xB0003FFFUL) /** RDMEM_SEQRAM_SEQRAM_MEM end address */
#define RDMEM_SEQRAM_SEQRAM_MEM_BITS                       (0xFUL)        /** RDMEM_SEQRAM_SEQRAM_MEM used bits */
#define RDMEM_FRCRAM_FRCRAM_MEM_BASE                       (0xB0004000UL) /** RDMEM_FRCRAM_FRCRAM_MEM base address */
#define RDMEM_FRCRAM_FRCRAM_MEM_SIZE                       (0x00001000UL) /** RDMEM_FRCRAM_FRCRAM_MEM available address space */
#define RDMEM_FRCRAM_FRCRAM_MEM_END                        (0xB0004FFFUL) /** RDMEM_FRCRAM_FRCRAM_MEM end address */
#define RDMEM_FRCRAM_FRCRAM_MEM_BITS                       (0xDUL)        /** RDMEM_FRCRAM_FRCRAM_MEM used bits */
#define RDMEM_FRCRAM_NS_MEM_BASE                           (0xB0004000UL) /** RDMEM_FRCRAM_NS_MEM base address */
#define RDMEM_FRCRAM_NS_MEM_SIZE                           (0x00001000UL) /** RDMEM_FRCRAM_NS_MEM available address space */
#define RDMEM_FRCRAM_NS_MEM_END                            (0xB0004FFFUL) /** RDMEM_FRCRAM_NS_MEM end address */
#define RDMEM_FRCRAM_NS_MEM_BITS                           (0xDUL)        /** RDMEM_FRCRAM_NS_MEM used bits */

/** Flash and SRAM limits for EFR32FG23B020F512IM40 */
#define FLASH_BASE                                         (0x08000000UL) /**< Flash Base Address */
#define FLASH_SIZE                                         (0x00080000UL) /**< Available Flash Memory */
#define FLASH_PAGE_SIZE                                    (0x00002000UL) /**< Flash Memory page size */
#define SRAM_BASE                                          (0x20000000UL) /**< SRAM Base Address */
#define SRAM_SIZE                                          (0x00010000UL) /**< Available SRAM Memory */
#define DMA_CHAN_COUNT                                     LDMA_CH_NUM    /**< Number of DMA channels */
#define EXT_IRQ_COUNT                                      76             /**< Number of External (NVIC) interrupts */

/* GPIO Avalibility Info */
#define GPIO_PA_INDEX                                      0U         /**< Index of port PA */
#define GPIO_PA_COUNT                                      9U         /**< Number of pins on port PA */
#define GPIO_PA_MASK                                       (0x01FFUL) /**< Port PA pin mask */
#define GPIO_PA_PIN0                                       1U         /**< GPIO pin PA0 is present. */
#define GPIO_PA_PIN1                                       1U         /**< GPIO pin PA1 is present. */
#define GPIO_PA_PIN2                                       1U         /**< GPIO pin PA2 is present. */
#define GPIO_PA_PIN3                                       1U         /**< GPIO pin PA3 is present. */
#define GPIO_PA_PIN4                                       1U         /**< GPIO pin PA4 is present. */
#define GPIO_PA_PIN5                                       1U         /**< GPIO pin PA5 is present. */
#define GPIO_PA_PIN6                                       1U         /**< GPIO pin PA6 is present. */
#define GPIO_PA_PIN7                                       1U         /**< GPIO pin PA7 is present. */
#define GPIO_PA_PIN8                                       1U         /**< GPIO pin PA8 is present. */
#define GPIO_PB_INDEX                                      1U         /**< Index of port PB */
#define GPIO_PB_COUNT                                      2U         /**< Number of pins on port PB */
#define GPIO_PB_MASK                                       (0x0003UL) /**< Port PB pin mask */
#define GPIO_PB_PIN0                                       1U         /**< GPIO pin PB0 is present. */
#define GPIO_PB_PIN1                                       1U         /**< GPIO pin PB1 is present. */
#define GPIO_PC_INDEX                                      2U         /**< Index of port PC */
#define GPIO_PC_COUNT                                      8U         /**< Number of pins on port PC */
#define GPIO_PC_MASK                                       (0x00FFUL) /**< Port PC pin mask */
#define GPIO_PC_PIN0                                       1U         /**< GPIO pin PC0 is present. */
#define GPIO_PC_PIN1                                       1U         /**< GPIO pin PC1 is present. */
#define GPIO_PC_PIN2                                       1U         /**< GPIO pin PC2 is present. */
#define GPIO_PC_PIN3                                       1U         /**< GPIO pin PC3 is present. */
#define GPIO_PC_PIN4                                       1U         /**< GPIO pin PC4 is present. */
#define GPIO_PC_PIN5                                       1U         /**< GPIO pin PC5 is present. */
#define GPIO_PC_PIN6                                       1U         /**< GPIO pin PC6 is present. */
#define GPIO_PC_PIN7                                       1U         /**< GPIO pin PC7 is present. */
#define GPIO_PD_INDEX                                      3U         /**< Index of port PD */
#define GPIO_PD_COUNT                                      4U         /**< Number of pins on port PD */
#define GPIO_PD_MASK                                       (0x000FUL) /**< Port PD pin mask */
#define GPIO_PD_PIN0                                       1U         /**< GPIO pin PD0 is present. */
#define GPIO_PD_PIN1                                       1U         /**< GPIO pin PD1 is present. */
#define GPIO_PD_PIN2                                       1U         /**< GPIO pin PD2 is present. */
#define GPIO_PD_PIN3                                       1U         /**< GPIO pin PD3 is present. */

/* Fixed Resource Locations */
#define GPIO_SWCLK_PORT                                    GPIO_PA_INDEX /**< Port of SWCLK.*/
#define GPIO_SWCLK_PIN                                     1U            /**< Pin of SWCLK.*/
#define GPIO_SWDIO_PORT                                    GPIO_PA_INDEX /**< Port of SWDIO.*/
#define GPIO_SWDIO_PIN                                     2U            /**< Pin of SWDIO.*/
#define GPIO_SWV_PORT                                      GPIO_PA_INDEX /**< Port of SWV.*/
#define GPIO_SWV_PIN                                       3U            /**< Pin of SWV.*/
#define GPIO_TDI_PORT                                      GPIO_PA_INDEX /**< Port of TDI.*/
#define GPIO_TDI_PIN                                       4U            /**< Pin of TDI.*/
#define GPIO_TDO_PORT                                      GPIO_PA_INDEX /**< Port of TDO.*/
#define GPIO_TDO_PIN                                       3U            /**< Pin of TDO.*/
#define GPIO_TRACECLK_PORT                                 GPIO_PA_INDEX /**< Port of TRACECLK.*/
#define GPIO_TRACECLK_PIN                                  4U            /**< Pin of TRACECLK.*/
#define GPIO_TRACEDATA0_PORT                               GPIO_PA_INDEX /**< Port of TRACEDATA0.*/
#define GPIO_TRACEDATA0_PIN                                3U            /**< Pin of TRACEDATA0.*/
#define GPIO_TRACEDATA1_PORT                               GPIO_PA_INDEX /**< Port of TRACEDATA1.*/
#define GPIO_TRACEDATA1_PIN                                5U            /**< Pin of TRACEDATA1.*/
#define GPIO_TRACEDATA2_PORT                               GPIO_PA_INDEX /**< Port of TRACEDATA2.*/
#define GPIO_TRACEDATA2_PIN                                6U            /**< Pin of TRACEDATA2.*/
#define GPIO_TRACEDATA3_PORT                               GPIO_PA_INDEX /**< Port of TRACEDATA3.*/
#define GPIO_TRACEDATA3_PIN                                7U            /**< Pin of TRACEDATA3.*/
#define GPIO_EM4WU0_PORT                                   GPIO_PA_INDEX /**< Port of EM4WU0.*/
#define GPIO_EM4WU0_PIN                                    5U            /**< Pin of EM4WU0.*/
#define GPIO_EM4WU10_PORT                                  GPIO_PD_INDEX /**< Port of EM4WU10.*/
#define GPIO_EM4WU10_PIN                                   5U            /**< Pin of EM4WU10.*/
#define GPIO_EM4WU3_PORT                                   GPIO_PB_INDEX /**< Port of EM4WU3.*/
#define GPIO_EM4WU3_PIN                                    1U            /**< Pin of EM4WU3.*/
#define GPIO_EM4WU4_PORT                                   GPIO_PB_INDEX /**< Port of EM4WU4.*/
#define GPIO_EM4WU4_PIN                                    3U            /**< Pin of EM4WU4.*/
#define GPIO_EM4WU6_PORT                                   GPIO_PC_INDEX /**< Port of EM4WU6.*/
#define GPIO_EM4WU6_PIN                                    0U            /**< Pin of EM4WU6.*/
#define GPIO_EM4WU7_PORT                                   GPIO_PC_INDEX /**< Port of EM4WU7.*/
#define GPIO_EM4WU7_PIN                                    5U            /**< Pin of EM4WU7.*/
#define GPIO_EM4WU8_PORT                                   GPIO_PC_INDEX /**< Port of EM4WU8.*/
#define GPIO_EM4WU8_PIN                                    7U            /**< Pin of EM4WU8.*/
#define GPIO_EM4WU9_PORT                                   GPIO_PD_INDEX /**< Port of EM4WU9.*/
#define GPIO_EM4WU9_PIN                                    2U            /**< Pin of EM4WU9.*/
#define GPIO_THMSW_EN_PORT                                 GPIO_PC_INDEX /**< Port of THMSW_EN.*/
#define GPIO_THMSW_EN_PIN                                  9U            /**< Pin of THMSW_EN.*/
#define LCD_COM0_PORT                                      GPIO_PD_INDEX /**< Port of COM0.*/
#define LCD_COM0_PIN                                       2U            /**< Pin of COM0.*/
#define LCD_COM1_PORT                                      GPIO_PD_INDEX /**< Port of COM1.*/
#define LCD_COM1_PIN                                       3U            /**< Pin of COM1.*/
#define LCD_COM2_PORT                                      GPIO_PD_INDEX /**< Port of COM2.*/
#define LCD_COM2_PIN                                       4U            /**< Pin of COM2.*/
#define LCD_COM3_PORT                                      GPIO_PD_INDEX /**< Port of COM3.*/
#define LCD_COM3_PIN                                       5U            /**< Pin of COM3.*/
#define LCD_LCD_CP_PORT                                    GPIO_PA_INDEX /**< Port of LCD_CP.*/
#define LCD_LCD_CP_PIN                                     6U            /**< Pin of LCD_CP.*/
#define LCD_SEG0_PORT                                      GPIO_PC_INDEX /**< Port of SEG0.*/
#define LCD_SEG0_PIN                                       0U            /**< Pin of SEG0.*/
#define LCD_SEG1_PORT                                      GPIO_PC_INDEX /**< Port of SEG1.*/
#define LCD_SEG1_PIN                                       1U            /**< Pin of SEG1.*/
#define LCD_SEG10_PORT                                     GPIO_PA_INDEX /**< Port of SEG10.*/
#define LCD_SEG10_PIN                                      4U            /**< Pin of SEG10.*/
#define LCD_SEG11_PORT                                     GPIO_PA_INDEX /**< Port of SEG11.*/
#define LCD_SEG11_PIN                                      5U            /**< Pin of SEG11.*/
#define LCD_SEG12_PORT                                     GPIO_PA_INDEX /**< Port of SEG12.*/
#define LCD_SEG12_PIN                                      7U            /**< Pin of SEG12.*/
#define LCD_SEG13_PORT                                     GPIO_PA_INDEX /**< Port of SEG13.*/
#define LCD_SEG13_PIN                                      8U            /**< Pin of SEG13.*/
#define LCD_SEG14_PORT                                     GPIO_PB_INDEX /**< Port of SEG14.*/
#define LCD_SEG14_PIN                                      0U            /**< Pin of SEG14.*/
#define LCD_SEG15_PORT                                     GPIO_PB_INDEX /**< Port of SEG15.*/
#define LCD_SEG15_PIN                                      1U            /**< Pin of SEG15.*/
#define LCD_SEG16_PORT                                     GPIO_PB_INDEX /**< Port of SEG16.*/
#define LCD_SEG16_PIN                                      2U            /**< Pin of SEG16.*/
#define LCD_SEG17_PORT                                     GPIO_PB_INDEX /**< Port of SEG17.*/
#define LCD_SEG17_PIN                                      3U            /**< Pin of SEG17.*/
#define LCD_SEG18_PORT                                     GPIO_PC_INDEX /**< Port of SEG18.*/
#define LCD_SEG18_PIN                                      8U            /**< Pin of SEG18.*/
#define LCD_SEG19_PORT                                     GPIO_PC_INDEX /**< Port of SEG19.*/
#define LCD_SEG19_PIN                                      9U            /**< Pin of SEG19.*/
#define LCD_SEG2_PORT                                      GPIO_PC_INDEX /**< Port of SEG2.*/
#define LCD_SEG2_PIN                                       2U            /**< Pin of SEG2.*/
#define LCD_SEG3_PORT                                      GPIO_PC_INDEX /**< Port of SEG3.*/
#define LCD_SEG3_PIN                                       3U            /**< Pin of SEG3.*/
#define LCD_SEG4_PORT                                      GPIO_PC_INDEX /**< Port of SEG4.*/
#define LCD_SEG4_PIN                                       4U            /**< Pin of SEG4.*/
#define LCD_SEG5_PORT                                      GPIO_PC_INDEX /**< Port of SEG5.*/
#define LCD_SEG5_PIN                                       5U            /**< Pin of SEG5.*/
#define LCD_SEG6_PORT                                      GPIO_PC_INDEX /**< Port of SEG6.*/
#define LCD_SEG6_PIN                                       6U            /**< Pin of SEG6.*/
#define LCD_SEG7_PORT                                      GPIO_PC_INDEX /**< Port of SEG7.*/
#define LCD_SEG7_PIN                                       7U            /**< Pin of SEG7.*/
#define LCD_SEG8_PORT                                      GPIO_PA_INDEX /**< Port of SEG8.*/
#define LCD_SEG8_PIN                                       0U            /**< Pin of SEG8.*/
#define LCD_SEG9_PORT                                      GPIO_PA_INDEX /**< Port of SEG9.*/
#define LCD_SEG9_PIN                                       1U            /**< Pin of SEG9.*/
#define LESENSE_EN_0_PORT                                  GPIO_PA_INDEX /**< Port of EN_0.*/
#define LESENSE_EN_0_PIN                                   3U            /**< Pin of EN_0.*/
#define LESENSE_EN_1_PORT                                  GPIO_PA_INDEX /**< Port of EN_1.*/
#define LESENSE_EN_1_PIN                                   4U            /**< Pin of EN_1.*/
#define LESENSE_EN_2_PORT                                  GPIO_PA_INDEX /**< Port of EN_2.*/
#define LESENSE_EN_2_PIN                                   5U            /**< Pin of EN_2.*/
#define LFXO_LFXTAL_I_PORT                                 GPIO_PD_INDEX /**< Port of LFXTAL_I.*/
#define LFXO_LFXTAL_I_PIN                                  1U            /**< Pin of LFXTAL_I.*/
#define LFXO_LFXTAL_O_PORT                                 GPIO_PD_INDEX /**< Port of LFXTAL_O.*/
#define LFXO_LFXTAL_O_PIN                                  0U            /**< Pin of LFXTAL_O.*/
#define LFXO_LF_EXTCLK_PORT                                GPIO_PD_INDEX /**< Port of LF_EXTCLK.*/
#define LFXO_LF_EXTCLK_PIN                                 1U            /**< Pin of LF_EXTCLK.*/
#define VDAC0_CH0_█████████_OUT_PORT                            GPIO_PB_INDEX /**< Port of CH0_█████████_OUT.*/
#define VDAC0_CH0_█████████_OUT_PIN                             0U            /**< Pin of CH0_█████████_OUT.*/
#define VDAC0_CH1_█████████_OUT_PORT                            GPIO_PB_INDEX /**< Port of CH1_█████████_OUT.*/
#define VDAC0_CH1_█████████_OUT_PIN                             1U            /**< Pin of CH1_█████████_OUT.*/

/* Part number capabilities */
#define ACMP_PRESENT                                         /** ACMP is available in this part */
#define ACMP_COUNT                                         2 /** 2 ACMPs available  */
#define AGC_PRESENT                                          /** AGC is available in this part */
#define AGC_COUNT                                          1 /** 1 AGCs available  */
#define AMUXCP_PRESENT                                       /** AMUXCP is available in this part */
#define AMUXCP_COUNT                                       1 /** 1 AMUXCPs available  */
#define BUFC_PRESENT                                         /** BUFC is available in this part */
#define BUFC_COUNT                                         1 /** 1 BUFCs available  */
#define BURAM_PRESENT                                        /** BURAM is available in this part */
#define BURAM_COUNT                                        1 /** 1 BURAMs available  */
#define BURTC_PRESENT                                        /** BURTC is available in this part */
#define BURTC_COUNT                                        1 /** 1 BURTCs available  */
#define CMU_PRESENT                                          /** CMU is available in this part */
#define CMU_COUNT                                          1 /** 1 CMUs available  */
#define DCDC_PRESENT                                         /** DCDC is available in this part */
#define DCDC_COUNT                                         1 /** 1 DCDCs available  */
#define DMEM_PRESENT                                         /** DMEM is available in this part */
#define DMEM_COUNT                                         1 /** 1 DMEMs available  */
#define DPLL_PRESENT                                         /** DPLL is available in this part */
#define DPLL_COUNT                                         1 /** 1 DPLLs available  */
#define ECAIFADC_PRESENT                                     /** ECAIFADC is available in this part */
#define ECAIFADC_COUNT                                     1 /** 1 ECAIFADCs available  */
#define EMU_PRESENT                                          /** EMU is available in this part */
#define EMU_COUNT                                          1 /** 1 EMUs available  */
#define EUSART_PRESENT                                       /** EUSART is available in this part */
#define EUSART_COUNT                                       3 /** 3 EUSARTs available  */
#define FRC_PRESENT                                          /** FRC is available in this part */
#define FRC_COUNT                                          1 /** 1 FRCs available  */
#define FSRCO_PRESENT                                        /** FSRCO is available in this part */
#define FSRCO_COUNT                                        1 /** 1 FSRCOs available  */
#define GPCRC_PRESENT                                        /** GPCRC is available in this part */
#define GPCRC_COUNT                                        1 /** 1 GPCRCs available  */
#define GPIO_PRESENT                                         /** GPIO is available in this part */
#define GPIO_COUNT                                         1 /** 1 GPIOs available  */
#define HFRCO_PRESENT                                        /** HFRCO is available in this part */
#define HFRCO_COUNT                                        1 /** 1 HFRCOs available  */
#define HFRCOEM23_PRESENT                                    /** HFRCOEM23 is available in this part */
#define HFRCOEM23_COUNT                                    1 /** 1 HFRCOEM23s available  */
#define HFXO_PRESENT                                         /** HFXO is available in this part */
#define HFXO_COUNT                                         1 /** 1 HFXOs available  */
#define HOSTMAILBOX_PRESENT                                  /** HOSTMAILBOX is available in this part */
#define HOSTMAILBOX_COUNT                                  1 /** 1 HOSTMAILBOXs available  */
#define I2C_PRESENT                                          /** I2C is available in this part */
#define I2C_COUNT                                          2 /** 2 I2Cs available  */
#define IADC_PRESENT                                         /** IADC is available in this part */
#define IADC_COUNT                                         1 /** 1 IADCs available  */
#define ICACHE_PRESENT                                       /** ICACHE is available in this part */
#define ICACHE_COUNT                                       1 /** 1 ICACHEs available  */
#define KEYSCAN_PRESENT                                      /** KEYSCAN is available in this part */
#define KEYSCAN_COUNT                                      1 /** 1 KEYSCANs available  */
#define LCD_PRESENT                                          /** LCD is available in this part */
#define LCD_COUNT                                          1 /** 1 LCDs available  */
#define LCDRF_PRESENT                                        /** LCDRF is available in this part */
#define LCDRF_COUNT                                        1 /** 1 LCDRFs available  */
#define LDMA_PRESENT                                         /** LDMA is available in this part */
#define LDMA_COUNT                                         1 /** 1 LDMAs available  */
#define LDMAXBAR_PRESENT                                     /** LDMAXBAR is available in this part */
#define LDMAXBAR_COUNT                                     1 /** 1 LDMAXBARs available  */
#define LESENSE_PRESENT                                      /** LESENSE is available in this part */
#define LESENSE_COUNT                                      1 /** 1 LESENSEs available  */
#define LETIMER_PRESENT                                      /** LETIMER is available in this part */
#define LETIMER_COUNT                                      1 /** 1 LETIMERs available  */
#define LFRCO_PRESENT                                        /** LFRCO is available in this part */
#define LFRCO_COUNT                                        1 /** 1 LFRCOs available  */
#define LFXO_PRESENT                                         /** LFXO is available in this part */
#define LFXO_COUNT                                         1 /** 1 LFXOs available  */
#define MODEM_PRESENT                                        /** MODEM is available in this part */
#define MODEM_COUNT                                        1 /** 1 MODEMs available  */
#define MSC_PRESENT                                          /** MSC is available in this part */
#define MSC_COUNT                                          1 /** 1 MSCs available  */
#define PCNT_PRESENT                                         /** PCNT is available in this part */
#define PCNT_COUNT                                         1 /** 1 PCNTs available  */
#define PFMXPPRF_PRESENT                                     /** PFMXPPRF is available in this part */
#define PFMXPPRF_COUNT                                     1 /** 1 PFMXPPRFs available  */
#define PROTIMER_PRESENT                                     /** PROTIMER is available in this part */
#define PROTIMER_COUNT                                     1 /** 1 PROTIMERs available  */
#define PRS_PRESENT                                          /** PRS is available in this part */
#define PRS_COUNT                                          1 /** 1 PRSs available  */
#define RAC_PRESENT                                          /** RAC is available in this part */
#define RAC_COUNT                                          1 /** 1 RACs available  */
#define RADIOAES_PRESENT                                     /** RADIOAES is available in this part */
#define RADIOAES_COUNT                                     1 /** 1 RADIOAESs available  */
#define RFCRC_PRESENT                                        /** RFCRC is available in this part */
#define RFCRC_COUNT                                        1 /** 1 RFCRCs available  */
#define RFECA_PRESENT                                        /** RFECA is available in this part */
#define RFECA_COUNT                                        2 /** 2 RFECAs available  */
#define RFMAILBOX_PRESENT                                    /** RFMAILBOX is available in this part */
#define RFMAILBOX_COUNT                                    1 /** 1 RFMAILBOXs available  */
#define RFSCRATCHPAD_PRESENT                                 /** RFSCRATCHPAD is available in this part */
#define RFSCRATCHPAD_COUNT                                 1 /** 1 RFSCRATCHPADs available  */
#define SCRATCHPAD_PRESENT                                   /** SCRATCHPAD is available in this part */
#define SCRATCHPAD_COUNT                                   1 /** 1 SCRATCHPADs available  */
#define SEMAILBOX_PRESENT                                    /** SEMAILBOX is available in this part */
#define SEMAILBOX_COUNT                                    1 /** 1 SEMAILBOXs available  */
#define SMU_PRESENT                                          /** SMU is available in this part */
#define SMU_COUNT                                          1 /** 1 SMUs available  */
#define SYNTH_PRESENT                                        /** SYNTH is available in this part */
#define SYNTH_COUNT                                        1 /** 1 SYNTHs available  */
#define SYSCFG_PRESENT                                       /** SYSCFG is available in this part */
#define SYSCFG_COUNT                                       1 /** 1 SYSCFGs available  */
#define SYSRTC_PRESENT                                       /** SYSRTC is available in this part */
#define SYSRTC_COUNT                                       1 /** 1 SYSRTCs available  */
#define TIMER_PRESENT                                        /** TIMER is available in this part */
#define TIMER_COUNT                                        5 /** 5 TIMERs available  */
#define ULFRCO_PRESENT                                       /** ULFRCO is available in this part */
#define ULFRCO_COUNT                                       1 /** 1 ULFRCOs available  */
#define USART_PRESENT                                        /** USART is available in this part */
#define USART_COUNT                                        1 /** 1 USARTs available  */
#define VDAC_PRESENT                                         /** VDAC is available in this part */
#define VDAC_COUNT                                         1 /** 1 VDACs available  */
#define WDOG_PRESENT                                         /** WDOG is available in this part */
#define WDOG_COUNT                                         2 /** 2 WDOGs available  */
#define DEVINFO_PRESENT                                      /** DEVINFO is available in this part */
#define DEVINFO_COUNT                                      1 /** 1 DEVINFOs available  */

/* Include standard ARM headers for the core */
#include "core_cm33.h"        /* Core Header File */
#include "system_efr32fg23.h" /* System Header File */

/** @} End of group EFR32FG23B020F512IM40_Part */

/**************************************************************************//**
 * @defgroup EFR32FG23B020F512IM40_Peripheral_TypeDefs EFR32FG23B020F512IM40 Peripheral TypeDefs
 * @{
 * @brief Device Specific Peripheral Register Structures
 *****************************************************************************/
#include "efr32fg23_scratchpad.h"
#include "efr32fg23_emu.h"
#include "efr32fg23_cmu.h"
#include "efr32fg23_hfrco.h"
#include "efr32fg23_fsrco.h"
#include "efr32fg23_dpll.h"
#include "efr32fg23_lfxo.h"
#include "efr32fg23_lfrco.h"
#include "efr32fg23_ulfrco.h"
#include "efr32fg23_msc.h"
#include "efr32fg23_icache.h"
#include "efr32fg23_prs.h"
#include "efr32fg23_gpio.h"
#include "efr32fg23_ldma.h"
#include "efr32fg23_ldmaxbar.h"
#include "efr32fg23_timer.h"
#include "efr32fg23_usart.h"
#include "efr32fg23_burtc.h"
#include "efr32fg23_i2c.h"
#include "efr32fg23_syscfg.h"
#include "efr32fg23_buram.h"
#include "efr32fg23_gpcrc.h"
#include "efr32fg23_dcdc.h"
#include "efr32fg23_mailbox.h"
#include "efr32fg23_eusart.h"
#include "efr32fg23_sysrtc.h"
#include "efr32fg23_lcd.h"
#include "efr32fg23_keyscan.h"
#include "efr32fg23_mpahbram.h"
#include "efr32fg23_lcdrf.h"
#include "efr32fg23_pfmxpprf.h"
#include "efr32fg23_aes.h"
#include "efr32fg23_smu.h"
#include "efr32fg23_letimer.h"
#include "efr32fg23_iadc.h"
#include "efr32fg23_acmp.h"
#include "efr32fg23_amuxcp.h"
#include "efr32fg23_vdac.h"
#include "efr32fg23_pcnt.h"
#include "efr32fg23_lesense.h"
#include "efr32fg23_hfxo.h"
#include "efr32fg23_wdog.h"
#include "efr32fg23_semailbox.h"
#include "efr32fg23_frc.h"
#include "efr32fg23_agc.h"
#include "efr32fg23_rfcrc.h"
#include "efr32fg23_modem.h"
#include "efr32fg23_synth.h"
#include "efr32fg23_protimer.h"
#include "efr32fg23_rac.h"
#include "efr32fg23_eca.h"
#include "efr32fg23_ecaifadc.h"
#include "efr32fg23_bufc.h"
#include "efr32fg23_devinfo.h"

/* Custom headers for LDMAXBAR and PRS mappings */
#include "efr32fg23_prs_signals.h"
#include "efr32fg23_dma_descriptor.h"
#include "efr32fg23_ldmaxbar_defines.h"

/** @} End of group EFR32FG23B020F512IM40_Peripheral_TypeDefs  */

/**************************************************************************//**
 * @defgroup EFR32FG23B020F512IM40_Peripheral_Base EFR32FG23B020F512IM40 Peripheral Memory Map
 * @{
 *****************************************************************************/

#define SCRATCHPAD_BASE           (0x40000000UL) /* SCRATCHPAD base address */
#define EMU_BASE                  (0x40004000UL) /* EMU base address */
#define CMU_BASE                  (0x40008000UL) /* CMU base address */
#define HFRCO0_BASE               (0x40010000UL) /* HFRCO0 base address */
#define FSRCO_BASE                (0x40018000UL) /* FSRCO base address */
#define DPLL0_BASE                (0x4001C000UL) /* DPLL0 base address */
#define LFXO_BASE                 (0x40020000UL) /* LFXO base address */
#define LFRCO_BASE                (0x40024000UL) /* LFRCO base address */
#define ULFRCO_BASE               (0x40028000UL) /* ULFRCO base address */
#define MSC_BASE                  (0x40030000UL) /* MSC base address */
#define ICACHE0_BASE              (0x40034000UL) /* ICACHE0 base address */
#define PRS_BASE                  (0x40038000UL) /* PRS base address */
#define GPIO_BASE                 (0x4003C000UL) /* GPIO base address */
#define LDMA_BASE                 (0x40040000UL) /* LDMA base address */
#define LDMAXBAR_BASE             (0x40044000UL) /* LDMAXBAR base address */
#define TIMER0_BASE               (0x40048000UL) /* TIMER0 base address */
#define TIMER1_BASE               (0x4004C000UL) /* TIMER1 base address */
#define TIMER2_BASE               (0x40050000UL) /* TIMER2 base address */
#define TIMER3_BASE               (0x40054000UL) /* TIMER3 base address */
#define TIMER4_BASE               (0x40058000UL) /* TIMER4 base address */
#define USART0_BASE               (0x4005C000UL) /* USART0 base address */
#define BURTC_BASE                (0x40064000UL) /* BURTC base address */
#define I2C1_BASE                 (0x40068000UL) /* I2C1 base address */
#define SYSCFG_CFGNS_BASE         (0x40078000UL) /* SYSCFG_CFGNS base address */
#define SYSCFG_BASE               (0x4007C000UL) /* SYSCFG base address */
#define BURAM_BASE                (0x40080000UL) /* BURAM base address */
#define GPCRC_BASE                (0x40088000UL) /* GPCRC base address */
#define DCDC_BASE                 (0x40094000UL) /* DCDC base address */
#define HOSTMAILBOX_BASE          (0x40098000UL) /* HOSTMAILBOX base address */
#define EUSART1_BASE              (0x400A0000UL) /* EUSART1 base address */
#define EUSART2_BASE              (0x400A4000UL) /* EUSART2 base address */
#define SYSRTC0_BASE              (0x400A8000UL) /* SYSRTC0 base address */
#define LCD_BASE                  (0x400AC000UL) /* LCD base address */
#define KEYSCAN_BASE              (0x400B0000UL) /* KEYSCAN base address */
#define DMEM_BASE                 (0x400B4000UL) /* DMEM base address */
#define LCDRF_BASE                (0x400C0000UL) /* LCDRF base address */
#define PFMXPPRF_BASE             (0x400C4000UL) /* PFMXPPRF base address */
#define RADIOAES_BASE             (0x44000000UL) /* RADIOAES base address */
#define SMU_BASE                  (0x44008000UL) /* SMU base address */
#define SMU_CFGNS_BASE            (0x4400C000UL) /* SMU_CFGNS base address */
#define LETIMER0_BASE             (0x49000000UL) /* LETIMER0 base address */
#define IADC0_BASE                (0x49004000UL) /* IADC0 base address */
#define ACMP0_BASE                (0x49008000UL) /* ACMP0 base address */
#define ACMP1_BASE                (0x4900C000UL) /* ACMP1 base address */
#define AMUXCP0_BASE              (0x49020000UL) /* AMUXCP0 base address */
#define VDAC0_BASE                (0x49024000UL) /* VDAC0 base address */
#define PCNT0_BASE                (0x49030000UL) /* PCNT0 base address */
#define LESENSE_BASE              (0x49038000UL) /* LESENSE base address */
#define HFRCOEM23_BASE            (0x4A000000UL) /* HFRCOEM23 base address */
#define HFXO0_BASE                (0x4A004000UL) /* HFXO0 base address */
#define I2C0_BASE                 (0x4B000000UL) /* I2C0 base address */
#define WDOG0_BASE                (0x4B004000UL) /* WDOG0 base address */
#define WDOG1_BASE                (0x4B008000UL) /* WDOG1 base address */
#define EUSART0_BASE              (0x4B010000UL) /* EUSART0 base address */
#define SEMAILBOX_HOST_BASE       (0x4C000000UL) /* SEMAILBOX_HOST base address */
#define SCRATCHPAD_NS_BASE        (0x50000000UL) /* SCRATCHPAD_NS base address */
#define EMU_NS_BASE               (0x50004000UL) /* EMU_NS base address */
#define CMU_NS_BASE               (0x50008000UL) /* CMU_NS base address */
#define HFRCO0_NS_BASE            (0x50010000UL) /* HFRCO0_NS base address */
#define FSRCO_NS_BASE             (0x50018000UL) /* FSRCO_NS base address */
#define DPLL0_NS_BASE             (0x5001C000UL) /* DPLL0_NS base address */
#define LFXO_NS_BASE              (0x50020000UL) /* LFXO_NS base address */
#define LFRCO_NS_BASE             (0x50024000UL) /* LFRCO_NS base address */
#define ULFRCO_NS_BASE            (0x50028000UL) /* ULFRCO_NS base address */
#define MSC_NS_BASE               (0x50030000UL) /* MSC_NS base address */
#define ICACHE0_NS_BASE           (0x50034000UL) /* ICACHE0_NS base address */
#define PRS_NS_BASE               (0x50038000UL) /* PRS_NS base address */
#define GPIO_NS_BASE              (0x5003C000UL) /* GPIO_NS base address */
#define LDMA_NS_BASE              (0x50040000UL) /* LDMA_NS base address */
#define LDMAXBAR_NS_BASE          (0x50044000UL) /* LDMAXBAR_NS base address */
#define TIMER0_NS_BASE            (0x50048000UL) /* TIMER0_NS base address */
#define TIMER1_NS_BASE            (0x5004C000UL) /* TIMER1_NS base address */
#define TIMER2_NS_BASE            (0x50050000UL) /* TIMER2_NS base address */
#define TIMER3_NS_BASE            (0x50054000UL) /* TIMER3_NS base address */
#define TIMER4_NS_BASE            (0x50058000UL) /* TIMER4_NS base address */
#define USART0_NS_BASE            (0x5005C000UL) /* USART0_NS base address */
#define BURTC_NS_BASE             (0x50064000UL) /* BURTC_NS base address */
#define I2C1_NS_BASE              (0x50068000UL) /* I2C1_NS base address */
#define SYSCFG_NS_CFGNS_BASE      (0x50078000UL) /* SYSCFG_NS_CFGNS base address */
#define SYSCFG_NS_BASE            (0x5007C000UL) /* SYSCFG_NS base address */
#define BURAM_NS_BASE             (0x50080000UL) /* BURAM_NS base address */
#define GPCRC_NS_BASE             (0x50088000UL) /* GPCRC_NS base address */
#define DCDC_NS_BASE              (0x50094000UL) /* DCDC_NS base address */
#define HOSTMAILBOX_NS_BASE       (0x50098000UL) /* HOSTMAILBOX_NS base address */
#define EUSART1_NS_BASE           (0x500A0000UL) /* EUSART1_NS base address */
#define EUSART2_NS_BASE           (0x500A4000UL) /* EUSART2_NS base address */
#define SYSRTC0_NS_BASE           (0x500A8000UL) /* SYSRTC0_NS base address */
#define LCD_NS_BASE               (0x500AC000UL) /* LCD_NS base address */
#define KEYSCAN_NS_BASE           (0x500B0000UL) /* KEYSCAN_NS base address */
#define DMEM_NS_BASE              (0x500B4000UL) /* DMEM_NS base address */
#define LCDRF_NS_BASE             (0x500C0000UL) /* LCDRF_NS base address */
#define PFMXPPRF_NS_BASE          (0x500C4000UL) /* PFMXPPRF_NS base address */
#define RADIOAES_NS_BASE          (0x54000000UL) /* RADIOAES_NS base address */
#define SMU_NS_BASE               (0x54008000UL) /* SMU_NS base address */
#define SMU_NS_CFGNS_BASE         (0x5400C000UL) /* SMU_NS_CFGNS base address */
#define LETIMER0_NS_BASE          (0x59000000UL) /* LETIMER0_NS base address */
#define IADC0_NS_BASE             (0x59004000UL) /* IADC0_NS base address */
#define ACMP0_NS_BASE             (0x59008000UL) /* ACMP0_NS base address */
#define ACMP1_NS_BASE             (0x5900C000UL) /* ACMP1_NS base address */
#define AMUXCP0_NS_BASE           (0x59020000UL) /* AMUXCP0_NS base address */
#define VDAC0_NS_BASE             (0x59024000UL) /* VDAC0_NS base address */
#define PCNT0_NS_BASE             (0x59030000UL) /* PCNT0_NS base address */
#define LESENSE_NS_BASE           (0x59038000UL) /* LESENSE_NS base address */
#define HFRCOEM23_NS_BASE         (0x5A000000UL) /* HFRCOEM23_NS base address */
#define HFXO0_NS_BASE             (0x5A004000UL) /* HFXO0_NS base address */
#define I2C0_NS_BASE              (0x5B000000UL) /* I2C0_NS base address */
#define WDOG0_NS_BASE             (0x5B004000UL) /* WDOG0_NS base address */
#define WDOG1_NS_BASE             (0x5B008000UL) /* WDOG1_NS base address */
#define EUSART0_NS_BASE           (0x5B010000UL) /* EUSART0_NS base address */
#define SEMAILBOX_NS_HOST_BASE    (0x5C000000UL) /* SEMAILBOX_NS_HOST base address */
#define FRC_BASE                  (0xA8004000UL) /* FRC base address */
#define AGC_BASE                  (0xA800C000UL) /* AGC base address */
#define RFCRC_BASE                (0xA8010000UL) /* RFCRC base address */
#define MODEM_BASE                (0xA8014000UL) /* MODEM base address */
#define SYNTH_BASE                (0xA8018000UL) /* SYNTH base address */
#define PROTIMER_BASE             (0xA801C000UL) /* PROTIMER base address */
#define RAC_BASE                  (0xA8020000UL) /* RAC base address */
#define RFSCRATCHPAD_BASE         (0xA8024000UL) /* RFSCRATCHPAD base address */
#define RFMAILBOX_BASE            (0xA802C000UL) /* RFMAILBOX base address */
#define RFECA0_BASE               (0xA8030000UL) /* RFECA0 base address */
#define RFECA1_BASE               (0xA8034000UL) /* RFECA1 base address */
#define ECAIFADC_BASE             (0xA8038000UL) /* ECAIFADC base address */
#define BUFC_BASE                 (0xAA000000UL) /* BUFC base address */
#define FRC_NS_BASE               (0xB8004000UL) /* FRC_NS base address */
#define AGC_NS_BASE               (0xB800C000UL) /* AGC_NS base address */
#define RFCRC_NS_BASE             (0xB8010000UL) /* RFCRC_NS base address */
#define MODEM_NS_BASE             (0xB8014000UL) /* MODEM_NS base address */
#define SYNTH_NS_BASE             (0xB8018000UL) /* SYNTH_NS base address */
#define PROTIMER_NS_BASE          (0xB801C000UL) /* PROTIMER_NS base address */
#define RAC_NS_BASE               (0xB8020000UL) /* RAC_NS base address */
#define RFSCRATCHPAD_NS_BASE      (0xB8024000UL) /* RFSCRATCHPAD_NS base address */
#define RFMAILBOX_NS_BASE         (0xB802C000UL) /* RFMAILBOX_NS base address */
#define RFECA0_NS_BASE            (0xB8030000UL) /* RFECA0_NS base address */
#define RFECA1_NS_BASE            (0xB8034000UL) /* RFECA1_NS base address */
#define ECAIFADC_NS_BASE          (0xB8038000UL) /* ECAIFADC_NS base address */
#define BUFC_NS_BASE              (0xBA000000UL) /* BUFC_NS base address */
#define DEVINFO_BASE              (0x0FE08000UL) /* DEVINFO base address */
/** @} End of group EFR32FG23B020F512IM40_Peripheral_Base */

/**************************************************************************//**
 * @defgroup EFR32FG23B020F512IM40_Peripheral_Declaration EFR32FG23B020F512IM40 Peripheral Declarations Map
 * @{
 *****************************************************************************/

#define SCRATCHPAD_S         ((SCRATCHPAD_TypeDef *) SCRATCHPAD_BASE)            /**< SCRATCHPAD_S base pointer */
#define SCRATCHPAD           ((SCRATCHPAD_TypeDef *) SCRATCHPAD_BASE)            /**< SCRATCHPAD_S base pointer */
#define EMU_S                ((EMU_TypeDef *) EMU_BASE)                          /**< EMU_S base pointer */
#define EMU                  ((EMU_TypeDef *) EMU_BASE)                          /**< EMU_S base pointer */
#define CMU_S                ((CMU_TypeDef *) CMU_BASE)                          /**< CMU_S base pointer */
#define CMU                  ((CMU_TypeDef *) CMU_BASE)                          /**< CMU_S base pointer */
#define HFRCO0_S             ((HFRCO_TypeDef *) HFRCO0_BASE)                     /**< HFRCO0_S base pointer */
#define HFRCO0               ((HFRCO_TypeDef *) HFRCO0_BASE)                     /**< HFRCO0_S base pointer */
#define FSRCO_S              ((FSRCO_TypeDef *) FSRCO_BASE)                      /**< FSRCO_S base pointer */
#define FSRCO                ((FSRCO_TypeDef *) FSRCO_BASE)                      /**< FSRCO_S base pointer */
#define DPLL0_S              ((DPLL_TypeDef *) DPLL0_BASE)                       /**< DPLL0_S base pointer */
#define DPLL0                ((DPLL_TypeDef *) DPLL0_BASE)                       /**< DPLL0_S base pointer */
#define LFXO_S               ((LFXO_TypeDef *) LFXO_BASE)                        /**< LFXO_S base pointer */
#define LFXO                 ((LFXO_TypeDef *) LFXO_BASE)                        /**< LFXO_S base pointer */
#define LFRCO_S              ((LFRCO_TypeDef *) LFRCO_BASE)                      /**< LFRCO_S base pointer */
#define LFRCO                ((LFRCO_TypeDef *) LFRCO_BASE)                      /**< LFRCO_S base pointer */
#define ULFRCO_S             ((ULFRCO_TypeDef *) ULFRCO_BASE)                    /**< ULFRCO_S base pointer */
#define ULFRCO               ((ULFRCO_TypeDef *) ULFRCO_BASE)                    /**< ULFRCO_S base pointer */
#define MSC_S                ((MSC_TypeDef *) MSC_BASE)                          /**< MSC_S base pointer */
#define MSC                  ((MSC_TypeDef *) MSC_BASE)                          /**< MSC_S base pointer */
#define ICACHE0_S            ((ICACHE_TypeDef *) ICACHE0_BASE)                   /**< ICACHE0_S base pointer */
#define ICACHE0              ((ICACHE_TypeDef *) ICACHE0_BASE)                   /**< ICACHE0_S base pointer */
#define PRS_S                ((PRS_TypeDef *) PRS_BASE)                          /**< PRS_S base pointer */
#define PRS                  ((PRS_TypeDef *) PRS_BASE)                          /**< PRS_S base pointer */
#define GPIO_S               ((GPIO_TypeDef *) GPIO_BASE)                        /**< GPIO_S base pointer */
#define GPIO                 ((GPIO_TypeDef *) GPIO_BASE)                        /**< GPIO_S base pointer */
#define LDMA_S               ((LDMA_TypeDef *) LDMA_BASE)                        /**< LDMA_S base pointer */
#define LDMA                 ((LDMA_TypeDef *) LDMA_BASE)                        /**< LDMA_S base pointer */
#define LDMAXBAR_S           ((LDMAXBAR_TypeDef *) LDMAXBAR_BASE)                /**< LDMAXBAR_S base pointer */
#define LDMAXBAR             ((LDMAXBAR_TypeDef *) LDMAXBAR_BASE)                /**< LDMAXBAR_S base pointer */
#define TIMER0_S             ((TIMER_TypeDef *) TIMER0_BASE)                     /**< TIMER0_S base pointer */
#define TIMER0               ((TIMER_TypeDef *) TIMER0_BASE)                     /**< TIMER0_S base pointer */
#define TIMER1_S             ((TIMER_TypeDef *) TIMER1_BASE)                     /**< TIMER1_S base pointer */
#define TIMER1               ((TIMER_TypeDef *) TIMER1_BASE)                     /**< TIMER1_S base pointer */
#define TIMER2_S             ((TIMER_TypeDef *) TIMER2_BASE)                     /**< TIMER2_S base pointer */
#define TIMER2               ((TIMER_TypeDef *) TIMER2_BASE)                     /**< TIMER2_S base pointer */
#define TIMER3_S             ((TIMER_TypeDef *) TIMER3_BASE)                     /**< TIMER3_S base pointer */
#define TIMER3               ((TIMER_TypeDef *) TIMER3_BASE)                     /**< TIMER3_S base pointer */
#define TIMER4_S             ((TIMER_TypeDef *) TIMER4_BASE)                     /**< TIMER4_S base pointer */
#define TIMER4               ((TIMER_TypeDef *) TIMER4_BASE)                     /**< TIMER4_S base pointer */
#define USART0_S             ((USART_TypeDef *) USART0_BASE)                     /**< USART0_S base pointer */
#define USART0               ((USART_TypeDef *) USART0_BASE)                     /**< USART0_S base pointer */
#define BURTC_S              ((BURTC_TypeDef *) BURTC_BASE)                      /**< BURTC_S base pointer */
#define BURTC                ((BURTC_TypeDef *) BURTC_BASE)                      /**< BURTC_S base pointer */
#define I2C1_S               ((I2C_TypeDef *) I2C1_BASE)                         /**< I2C1_S base pointer */
#define I2C1                 ((I2C_TypeDef *) I2C1_BASE)                         /**< I2C1_S base pointer */
#define SYSCFG_S_CFGNS       ((SYSCFG_CFGNS_TypeDef *) SYSCFG_CFGNS_BASE)        /**< SYSCFG_S_CFGNS base pointer */
#define SYSCFG_CFGNS         ((SYSCFG_CFGNS_TypeDef *) SYSCFG_CFGNS_BASE)        /**< SYSCFG_S_CFGNS base pointer */
#define SYSCFG_S             ((SYSCFG_TypeDef *) SYSCFG_BASE)                    /**< SYSCFG_S base pointer */
#define SYSCFG               ((SYSCFG_TypeDef *) SYSCFG_BASE)                    /**< SYSCFG_S base pointer */
#define BURAM_S              ((BURAM_TypeDef *) BURAM_BASE)                      /**< BURAM_S base pointer */
#define BURAM                ((BURAM_TypeDef *) BURAM_BASE)                      /**< BURAM_S base pointer */
#define GPCRC_S              ((GPCRC_TypeDef *) GPCRC_BASE)                      /**< GPCRC_S base pointer */
#define GPCRC                ((GPCRC_TypeDef *) GPCRC_BASE)                      /**< GPCRC_S base pointer */
#define DCDC_S               ((DCDC_TypeDef *) DCDC_BASE)                        /**< DCDC_S base pointer */
#define DCDC                 ((DCDC_TypeDef *) DCDC_BASE)                        /**< DCDC_S base pointer */
#define HOSTMAILBOX_S        ((MAILBOX_TypeDef *) HOSTMAILBOX_BASE)              /**< HOSTMAILBOX_S base pointer */
#define HOSTMAILBOX          ((MAILBOX_TypeDef *) HOSTMAILBOX_BASE)              /**< HOSTMAILBOX_S base pointer */
#define EUSART1_S            ((EUSART_TypeDef *) EUSART1_BASE)                   /**< EUSART1_S base pointer */
#define EUSART1              ((EUSART_TypeDef *) EUSART1_BASE)                   /**< EUSART1_S base pointer */
#define EUSART2_S            ((EUSART_TypeDef *) EUSART2_BASE)                   /**< EUSART2_S base pointer */
#define EUSART2              ((EUSART_TypeDef *) EUSART2_BASE)                   /**< EUSART2_S base pointer */
#define SYSRTC0_S            ((SYSRTC_TypeDef *) SYSRTC0_BASE)                   /**< SYSRTC0_S base pointer */
#define SYSRTC0              ((SYSRTC_TypeDef *) SYSRTC0_BASE)                   /**< SYSRTC0_S base pointer */
#define LCD_S                ((LCD_TypeDef *) LCD_BASE)                          /**< LCD_S base pointer */
#define LCD                  ((LCD_TypeDef *) LCD_BASE)                          /**< LCD_S base pointer */
#define KEYSCAN_S            ((KEYSCAN_TypeDef *) KEYSCAN_BASE)                  /**< KEYSCAN_S base pointer */
#define KEYSCAN              ((KEYSCAN_TypeDef *) KEYSCAN_BASE)                  /**< KEYSCAN_S base pointer */
#define DMEM_S               ((MPAHBRAM_TypeDef *) DMEM_BASE)                    /**< DMEM_S base pointer */
#define DMEM                 ((MPAHBRAM_TypeDef *) DMEM_BASE)                    /**< DMEM_S base pointer */
#define LCDRF_S              ((LCDRF_TypeDef *) LCDRF_BASE)                      /**< LCDRF_S base pointer */
#define LCDRF                ((LCDRF_TypeDef *) LCDRF_BASE)                      /**< LCDRF_S base pointer */
#define PFMXPPRF_S           ((PFMXPPRF_TypeDef *) PFMXPPRF_BASE)                /**< PFMXPPRF_S base pointer */
#define PFMXPPRF             ((PFMXPPRF_TypeDef *) PFMXPPRF_BASE)                /**< PFMXPPRF_S base pointer */
#define RADIOAES_S           ((AES_TypeDef *) RADIOAES_BASE)                     /**< RADIOAES_S base pointer */
#define RADIOAES             ((AES_TypeDef *) RADIOAES_BASE)                     /**< RADIOAES_S base pointer */
#define SMU_S                ((SMU_TypeDef *) SMU_BASE)                          /**< SMU_S base pointer */
#define SMU                  ((SMU_TypeDef *) SMU_BASE)                          /**< SMU_S base pointer */
#define SMU_S_CFGNS          ((SMU_CFGNS_TypeDef *) SMU_CFGNS_BASE)              /**< SMU_S_CFGNS base pointer */
#define SMU_CFGNS            ((SMU_CFGNS_TypeDef *) SMU_CFGNS_BASE)              /**< SMU_S_CFGNS base pointer */
#define LETIMER0_S           ((LETIMER_TypeDef *) LETIMER0_BASE)                 /**< LETIMER0_S base pointer */
#define LETIMER0             ((LETIMER_TypeDef *) LETIMER0_BASE)                 /**< LETIMER0_S base pointer */
#define IADC0_S              ((IADC_TypeDef *) IADC0_BASE)                       /**< IADC0_S base pointer */
#define IADC0                ((IADC_TypeDef *) IADC0_BASE)                       /**< IADC0_S base pointer */
#define ACMP0_S              ((ACMP_TypeDef *) ACMP0_BASE)                       /**< ACMP0_S base pointer */
#define ACMP0                ((ACMP_TypeDef *) ACMP0_BASE)                       /**< ACMP0_S base pointer */
#define ACMP1_S              ((ACMP_TypeDef *) ACMP1_BASE)                       /**< ACMP1_S base pointer */
#define ACMP1                ((ACMP_TypeDef *) ACMP1_BASE)                       /**< ACMP1_S base pointer */
#define AMUXCP0_S            ((AMUXCP_TypeDef *) AMUXCP0_BASE)                   /**< AMUXCP0_S base pointer */
#define AMUXCP0              ((AMUXCP_TypeDef *) AMUXCP0_BASE)                   /**< AMUXCP0_S base pointer */
#define VDAC0_S              ((VDAC_TypeDef *) VDAC0_BASE)                       /**< VDAC0_S base pointer */
#define VDAC0                ((VDAC_TypeDef *) VDAC0_BASE)                       /**< VDAC0_S base pointer */
#define PCNT0_S              ((PCNT_TypeDef *) PCNT0_BASE)                       /**< PCNT0_S base pointer */
#define PCNT0                ((PCNT_TypeDef *) PCNT0_BASE)                       /**< PCNT0_S base pointer */
#define LESENSE_S            ((LESENSE_TypeDef *) LESENSE_BASE)                  /**< LESENSE_S base pointer */
#define LESENSE              ((LESENSE_TypeDef *) LESENSE_BASE)                  /**< LESENSE_S base pointer */
#define HFRCOEM23_S          ((HFRCO_TypeDef *) HFRCOEM23_BASE)                  /**< HFRCOEM23_S base pointer */
#define HFRCOEM23            ((HFRCO_TypeDef *) HFRCOEM23_BASE)                  /**< HFRCOEM23_S base pointer */
#define HFXO0_S              ((HFXO_TypeDef *) HFXO0_BASE)                       /**< HFXO0_S base pointer */
#define HFXO0                ((HFXO_TypeDef *) HFXO0_BASE)                       /**< HFXO0_S base pointer */
#define I2C0_S               ((I2C_TypeDef *) I2C0_BASE)                         /**< I2C0_S base pointer */
#define I2C0                 ((I2C_TypeDef *) I2C0_BASE)                         /**< I2C0_S base pointer */
#define WDOG0_S              ((WDOG_TypeDef *) WDOG0_BASE)                       /**< WDOG0_S base pointer */
#define WDOG0                ((WDOG_TypeDef *) WDOG0_BASE)                       /**< WDOG0_S base pointer */
#define WDOG1_S              ((WDOG_TypeDef *) WDOG1_BASE)                       /**< WDOG1_S base pointer */
#define WDOG1                ((WDOG_TypeDef *) WDOG1_BASE)                       /**< WDOG1_S base pointer */
#define EUSART0_S            ((EUSART_TypeDef *) EUSART0_BASE)                   /**< EUSART0_S base pointer */
#define EUSART0              ((EUSART_TypeDef *) EUSART0_BASE)                   /**< EUSART0_S base pointer */
#define SEMAILBOX_S_HOST     ((SEMAILBOX_HOST_TypeDef *) SEMAILBOX_HOST_BASE)    /**< SEMAILBOX_S_HOST base pointer */
#define SEMAILBOX_HOST       ((SEMAILBOX_HOST_TypeDef *) SEMAILBOX_HOST_BASE)    /**< SEMAILBOX_S_HOST base pointer */
#define SCRATCHPAD_NS        ((SCRATCHPAD_TypeDef *) SCRATCHPAD_NS_BASE)         /**< SCRATCHPAD_NS base pointer */
#define EMU_NS               ((EMU_TypeDef *) EMU_NS_BASE)                       /**< EMU_NS base pointer */
#define CMU_NS               ((CMU_TypeDef *) CMU_NS_BASE)                       /**< CMU_NS base pointer */
#define HFRCO0_NS            ((HFRCO_TypeDef *) HFRCO0_NS_BASE)                  /**< HFRCO0_NS base pointer */
#define FSRCO_NS             ((FSRCO_TypeDef *) FSRCO_NS_BASE)                   /**< FSRCO_NS base pointer */
#define DPLL0_NS             ((DPLL_TypeDef *) DPLL0_NS_BASE)                    /**< DPLL0_NS base pointer */
#define LFXO_NS              ((LFXO_TypeDef *) LFXO_NS_BASE)                     /**< LFXO_NS base pointer */
#define LFRCO_NS             ((LFRCO_TypeDef *) LFRCO_NS_BASE)                   /**< LFRCO_NS base pointer */
#define ULFRCO_NS            ((ULFRCO_TypeDef *) ULFRCO_NS_BASE)                 /**< ULFRCO_NS base pointer */
#define MSC_NS               ((MSC_TypeDef *) MSC_NS_BASE)                       /**< MSC_NS base pointer */
#define ICACHE0_NS           ((ICACHE_TypeDef *) ICACHE0_NS_BASE)                /**< ICACHE0_NS base pointer */
#define PRS_NS               ((PRS_TypeDef *) PRS_NS_BASE)                       /**< PRS_NS base pointer */
#define GPIO_NS              ((GPIO_TypeDef *) GPIO_NS_BASE)                     /**< GPIO_NS base pointer */
#define LDMA_NS              ((LDMA_TypeDef *) LDMA_NS_BASE)                     /**< LDMA_NS base pointer */
#define LDMAXBAR_NS          ((LDMAXBAR_TypeDef *) LDMAXBAR_NS_BASE)             /**< LDMAXBAR_NS base pointer */
#define TIMER0_NS            ((TIMER_TypeDef *) TIMER0_NS_BASE)                  /**< TIMER0_NS base pointer */
#define TIMER1_NS            ((TIMER_TypeDef *) TIMER1_NS_BASE)                  /**< TIMER1_NS base pointer */
#define TIMER2_NS            ((TIMER_TypeDef *) TIMER2_NS_BASE)                  /**< TIMER2_NS base pointer */
#define TIMER3_NS            ((TIMER_TypeDef *) TIMER3_NS_BASE)                  /**< TIMER3_NS base pointer */
#define TIMER4_NS            ((TIMER_TypeDef *) TIMER4_NS_BASE)                  /**< TIMER4_NS base pointer */
#define USART0_NS            ((USART_TypeDef *) USART0_NS_BASE)                  /**< USART0_NS base pointer */
#define BURTC_NS             ((BURTC_TypeDef *) BURTC_NS_BASE)                   /**< BURTC_NS base pointer */
#define I2C1_NS              ((I2C_TypeDef *) I2C1_NS_BASE)                      /**< I2C1_NS base pointer */
#define SYSCFG_NS_CFGNS      ((SYSCFG_CFGNS_TypeDef *) SYSCFG_NS_CFGNS_BASE)     /**< SYSCFG_NS_CFGNS base pointer */
#define SYSCFG_NS            ((SYSCFG_TypeDef *) SYSCFG_NS_BASE)                 /**< SYSCFG_NS base pointer */
#define BURAM_NS             ((BURAM_TypeDef *) BURAM_NS_BASE)                   /**< BURAM_NS base pointer */
#define GPCRC_NS             ((GPCRC_TypeDef *) GPCRC_NS_BASE)                   /**< GPCRC_NS base pointer */
#define DCDC_NS              ((DCDC_TypeDef *) DCDC_NS_BASE)                     /**< DCDC_NS base pointer */
#define HOSTMAILBOX_NS       ((MAILBOX_TypeDef *) HOSTMAILBOX_NS_BASE)           /**< HOSTMAILBOX_NS base pointer */
#define EUSART1_NS           ((EUSART_TypeDef *) EUSART1_NS_BASE)                /**< EUSART1_NS base pointer */
#define EUSART2_NS           ((EUSART_TypeDef *) EUSART2_NS_BASE)                /**< EUSART2_NS base pointer */
#define SYSRTC0_NS           ((SYSRTC_TypeDef *) SYSRTC0_NS_BASE)                /**< SYSRTC0_NS base pointer */
#define LCD_NS               ((LCD_TypeDef *) LCD_NS_BASE)                       /**< LCD_NS base pointer */
#define KEYSCAN_NS           ((KEYSCAN_TypeDef *) KEYSCAN_NS_BASE)               /**< KEYSCAN_NS base pointer */
#define DMEM_NS              ((MPAHBRAM_TypeDef *) DMEM_NS_BASE)                 /**< DMEM_NS base pointer */
#define LCDRF_NS             ((LCDRF_TypeDef *) LCDRF_NS_BASE)                   /**< LCDRF_NS base pointer */
#define PFMXPPRF_NS          ((PFMXPPRF_TypeDef *) PFMXPPRF_NS_BASE)             /**< PFMXPPRF_NS base pointer */
#define RADIOAES_NS          ((AES_TypeDef *) RADIOAES_NS_BASE)                  /**< RADIOAES_NS base pointer */
#define SMU_NS               ((SMU_TypeDef *) SMU_NS_BASE)                       /**< SMU_NS base pointer */
#define SMU_NS_CFGNS         ((SMU_CFGNS_TypeDef *) SMU_NS_CFGNS_BASE)           /**< SMU_NS_CFGNS base pointer */
#define LETIMER0_NS          ((LETIMER_TypeDef *) LETIMER0_NS_BASE)              /**< LETIMER0_NS base pointer */
#define IADC0_NS             ((IADC_TypeDef *) IADC0_NS_BASE)                    /**< IADC0_NS base pointer */
#define ACMP0_NS             ((ACMP_TypeDef *) ACMP0_NS_BASE)                    /**< ACMP0_NS base pointer */
#define ACMP1_NS             ((ACMP_TypeDef *) ACMP1_NS_BASE)                    /**< ACMP1_NS base pointer */
#define AMUXCP0_NS           ((AMUXCP_TypeDef *) AMUXCP0_NS_BASE)                /**< AMUXCP0_NS base pointer */
#define VDAC0_NS             ((VDAC_TypeDef *) VDAC0_NS_BASE)                    /**< VDAC0_NS base pointer */
#define PCNT0_NS             ((PCNT_TypeDef *) PCNT0_NS_BASE)                    /**< PCNT0_NS base pointer */
#define LESENSE_NS           ((LESENSE_TypeDef *) LESENSE_NS_BASE)               /**< LESENSE_NS base pointer */
#define HFRCOEM23_NS         ((HFRCO_TypeDef *) HFRCOEM23_NS_BASE)               /**< HFRCOEM23_NS base pointer */
#define HFXO0_NS             ((HFXO_TypeDef *) HFXO0_NS_BASE)                    /**< HFXO0_NS base pointer */
#define I2C0_NS              ((I2C_TypeDef *) I2C0_NS_BASE)                      /**< I2C0_NS base pointer */
#define WDOG0_NS             ((WDOG_TypeDef *) WDOG0_NS_BASE)                    /**< WDOG0_NS base pointer */
#define WDOG1_NS             ((WDOG_TypeDef *) WDOG1_NS_BASE)                    /**< WDOG1_NS base pointer */
#define EUSART0_NS           ((EUSART_TypeDef *) EUSART0_NS_BASE)                /**< EUSART0_NS base pointer */
#define SEMAILBOX_NS_HOST    ((SEMAILBOX_HOST_TypeDef *) SEMAILBOX_NS_HOST_BASE) /**< SEMAILBOX_NS_HOST base pointer */
#define FRC_S                ((FRC_TypeDef *) FRC_BASE)                          /**< FRC_S base pointer */
#define FRC                  ((FRC_TypeDef *) FRC_BASE)                          /**< FRC_S base pointer */
#define AGC_S                ((AGC_TypeDef *) AGC_BASE)                          /**< AGC_S base pointer */
#define AGC                  ((AGC_TypeDef *) AGC_BASE)                          /**< AGC_S base pointer */
#define RFCRC_S              ((RFCRC_TypeDef *) RFCRC_BASE)                      /**< RFCRC_S base pointer */
#define RFCRC                ((RFCRC_TypeDef *) RFCRC_BASE)                      /**< RFCRC_S base pointer */
#define MODEM_S              ((MODEM_TypeDef *) MODEM_BASE)                      /**< MODEM_S base pointer */
#define MODEM                ((MODEM_TypeDef *) MODEM_BASE)                      /**< MODEM_S base pointer */
#define SYNTH_S              ((SYNTH_TypeDef *) SYNTH_BASE)                      /**< SYNTH_S base pointer */
#define SYNTH                ((SYNTH_TypeDef *) SYNTH_BASE)                      /**< SYNTH_S base pointer */
#define PROTIMER_S           ((PROTIMER_TypeDef *) PROTIMER_BASE)                /**< PROTIMER_S base pointer */
#define PROTIMER             ((PROTIMER_TypeDef *) PROTIMER_BASE)                /**< PROTIMER_S base pointer */
#define RAC_S                ((RAC_TypeDef *) RAC_BASE)                          /**< RAC_S base pointer */
#define RAC                  ((RAC_TypeDef *) RAC_BASE)                          /**< RAC_S base pointer */
#define RFSCRATCHPAD_S       ((SCRATCHPAD_TypeDef *) RFSCRATCHPAD_BASE)          /**< RFSCRATCHPAD_S base pointer */
#define RFSCRATCHPAD         ((SCRATCHPAD_TypeDef *) RFSCRATCHPAD_BASE)          /**< RFSCRATCHPAD_S base pointer */
#define RFMAILBOX_S          ((MAILBOX_TypeDef *) RFMAILBOX_BASE)                /**< RFMAILBOX_S base pointer */
#define RFMAILBOX            ((MAILBOX_TypeDef *) RFMAILBOX_BASE)                /**< RFMAILBOX_S base pointer */
#define RFECA0_S             ((ECA_TypeDef *) RFECA0_BASE)                       /**< RFECA0_S base pointer */
#define RFECA0               ((ECA_TypeDef *) RFECA0_BASE)                       /**< RFECA0_S base pointer */
#define RFECA1_S             ((ECA_TypeDef *) RFECA1_BASE)                       /**< RFECA1_S base pointer */
#define RFECA1               ((ECA_TypeDef *) RFECA1_BASE)                       /**< RFECA1_S base pointer */
#define ECAIFADC_S           ((ECAIFADC_TypeDef *) ECAIFADC_BASE)                /**< ECAIFADC_S base pointer */
#define ECAIFADC             ((ECAIFADC_TypeDef *) ECAIFADC_BASE)                /**< ECAIFADC_S base pointer */
#define BUFC_S               ((BUFC_TypeDef *) BUFC_BASE)                        /**< BUFC_S base pointer */
#define BUFC                 ((BUFC_TypeDef *) BUFC_BASE)                        /**< BUFC_S base pointer */
#define FRC_NS               ((FRC_TypeDef *) FRC_NS_BASE)                       /**< FRC_NS base pointer */
#define AGC_NS               ((AGC_TypeDef *) AGC_NS_BASE)                       /**< AGC_NS base pointer */
#define RFCRC_NS             ((RFCRC_TypeDef *) RFCRC_NS_BASE)                   /**< RFCRC_NS base pointer */
#define MODEM_NS             ((MODEM_TypeDef *) MODEM_NS_BASE)                   /**< MODEM_NS base pointer */
#define SYNTH_NS             ((SYNTH_TypeDef *) SYNTH_NS_BASE)                   /**< SYNTH_NS base pointer */
#define PROTIMER_NS          ((PROTIMER_TypeDef *) PROTIMER_NS_BASE)             /**< PROTIMER_NS base pointer */
#define RAC_NS               ((RAC_TypeDef *) RAC_NS_BASE)                       /**< RAC_NS base pointer */
#define RFSCRATCHPAD_NS      ((SCRATCHPAD_TypeDef *) RFSCRATCHPAD_NS_BASE)       /**< RFSCRATCHPAD_NS base pointer */
#define RFMAILBOX_NS         ((MAILBOX_TypeDef *) RFMAILBOX_NS_BASE)             /**< RFMAILBOX_NS base pointer */
#define RFECA0_NS            ((ECA_TypeDef *) RFECA0_NS_BASE)                    /**< RFECA0_NS base pointer */
#define RFECA1_NS            ((ECA_TypeDef *) RFECA1_NS_BASE)                    /**< RFECA1_NS base pointer */
#define ECAIFADC_NS          ((ECAIFADC_TypeDef *) ECAIFADC_NS_BASE)             /**< ECAIFADC_NS base pointer */
#define BUFC_NS              ((BUFC_TypeDef *) BUFC_NS_BASE)                     /**< BUFC_NS base pointer */
#define DEVINFO              ((DEVINFO_TypeDef *) DEVINFO_BASE)                  /**< DEVINFO base pointer */
/** @} End of group EFR32FG23B020F512IM40_Peripheral_Declaration */

/**************************************************************************//**
 * @defgroup EFR32FG23B020F512IM40_Peripheral_Parameters EFR32FG23B020F512IM40 Peripheral Parameters
 * @{
 * @brief Device peripheral parameter values
 *****************************************************************************/

/* Common peripheral register block offsets. */
#define PER_REG_BLOCK_SET_OFFSET                0x1000UL    /**< Offset to SET register block */
#define PER_REG_BLOCK_CLR_OFFSET                0x2000UL    /**< Offset to CLEAR register block */
#define PER_REG_BLOCK_TGL_OFFSET                0x3000UL    /**< Offset to TOGGLE register block */
#define DMEM_BANK0_SIZE                         0x4000UL    /**> Bank0 size */
#define DMEM_BANK1_SIZE                         0x4000UL    /**> Bank1 size */
#define DMEM_BANK2_SIZE                         0x4000UL    /**> Bank2 size */
#define DMEM_BANK3_SIZE                         0x4000UL    /**> Bank3 size */
#define DMEM_BANK4_SIZE                         0x2000UL    /**> Bank4 size */
#define DMEM_BANK5_SIZE                         0x2000UL    /**> Bank5 size */
#define DMEM_BANK6_SIZE                         0x2000UL    /**> Bank6 size */
#define DMEM_BANK7_SIZE                         0x2000UL    /**> Bank7 size */
#define DMEM_NUM_BANKS                          0x4UL       /**> Number of physical SRAM banks */
#define DMEM_NUM_PORTS                          0x2UL       /**> Number of AHB slave ports */
#define DMEM_NUM_PORTS_IS_2                     0x1UL       /**> Boolean indicating if NUM_PORTS=2 */
#define HFRCO0_EM23ONDEMAND                     0x0UL       /**> EM23 On Demand */
#define HFRCO0_EXCLUDEEM23ONDEMAND              0x1UL       /**> Exclude EM23 On Demand */
#define LFXO_NO_CTUNE                           0x0UL       /**> CTUNE Not Present */
#define LFXO_CTUNE                              0x1UL       /**> CTUNE Present */
#define MSC_CDA_PRESENT                         0x0UL       /**>  */
#define MSC_FDIO_WIDTH                          0x40UL      /**> None */
#define MSC_FLASHADDRBITS                       0x14UL      /**> None */
#define MSC_FLASHBLOCKADDRBITS                  0x14UL      /**> None */
#define MSC_FLASH_BLOCK_INFO_PCOUNT             0x2UL       /**> None */
#define MSC_FLASH_BLOCK_█████████_PCOUNT             0x50UL      /**>  */
#define MSC_INFOADDRBITS                        0xEUL       /**> None */
#define MSC_INFOBLOCKADDRBITS                   0xEUL       /**> None */
#define MSC_INFO_PSIZE_BITS                     0xDUL       /**> None */
#define MSC_█████████_PSIZE_BITS                     0xDUL       /**> None */
#define MSC_REDUNDANCY                          0x2UL       /**> None */
#define MSC_ROOT█████████_PRESENT                    0x1UL       /**>  */
#define MSC_UD_PRESENT                          0x1UL       /**>  */
#define MSC_YADDRBITS                           0x6UL       /**>  */
#define ICACHE0_AHB_LITE                        0x0UL       /**> AHB Lite */
#define ICACHE0_CACHEABLE_SIZE                  0x80000UL   /**> Cache Size */
#define ICACHE0_CACHEABLE_START                 0x8000000UL /**> Cache Start */
#define ICACHE0_DEFAULT_OFF                     0x0UL       /**> Default off */
#define ICACHE0_FLASH_SIZE                      0x80000UL   /**> Flash size */
#define ICACHE0_FLASH_START                     0x8000000UL /**> Flash start */
#define ICACHE0_LOOPCACHE_MEM_ADDR_BITS         0x3UL       /**> Loopcache Memory Address bits */
#define ICACHE0_LOOPCACHE_STICKINESS_BITS       0x4UL       /**> Loopcache Stickiness bits */
#define ICACHE0_PARITY_BITS                     0x1UL       /**> Use Parity */
#define ICACHE0_PC_BITS                         0x20UL      /**> Performance Counter bits */
#define ICACHE0_PIPE_STAGE                      0x1UL       /**> Pipeline Stage */
#define ICACHE0_RAM_ADDR_BITS                   0x0UL       /**> RAM Address bits */
#define ICACHE0_RAM_DATA_BITS                   0x0UL       /**> RAM Data bits */
#define ICACHE0_SET_BITS                        0x5UL       /**> Set bits */
#define ICACHE0_USE_HREADY_GATING               0x1UL       /**> Use HREADY gating */
#define ICACHE0_USE_IDLE_GATING                 0x1UL       /**> Use IDLE gating */
#define ICACHE0_USE_LOOPCACHE                   0x1UL       /**> Use Loopcache */
#define ICACHE0_WAY_BITS                        0x1UL       /**> Way bits */
#define ICACHE0_WORDS_PER_BLOCK                 0x0UL       /**> Words Per Block */
#define ICACHE0_WPB_BITS                        0x1UL       /**> Words Per Block bits */
#define ICACHE0_WPL_BITS                        0x3UL       /**> Words Per Line bits */
#define PRS_ASYNC_CH_NUM                        0xCUL       /**> None */
#define PRS_PRSSEL_WIDTH                        0x4UL       /**> New Param */
#define PRS_SPRSSEL_WIDTH                       0x2UL       /**> New Param */
#define PRS_SYNC_CH_NUM                         0x4UL       /**> None */
#define GPIO_COMALLOC_WIDTH                     0x4UL       /**> New Param */
#define GPIO_MODE_WIDTH                         0x4UL       /**> Mode Width */
#define GPIO_NUM_EM4_WU                         0xCUL       /**> New Param */
#define GPIO_NUM_EVEN_PA                        0x6UL       /**> Num of even pins port A */
#define GPIO_NUM_EVEN_PB                        0x4UL       /**> Num of even pins port B */
#define GPIO_NUM_EVEN_PC                        0x5UL       /**> Num of even pins port C */
#define GPIO_NUM_EVEN_PD                        0x3UL       /**> Num of even pins port D */
#define GPIO_NUM_EXT_INT                        0xCUL       /**> New Param */
#define GPIO_NUM_EXT_INT_L                      0x8UL       /**> New Param */
#define GPIO_NUM_EXT_INT_U                      0x4UL       /**> New Param */
#define GPIO_NUM_EXT_INT_U_ZERO                 0x0UL       /**> New Param */
#define GPIO_NUM_ODD_PA                         0x5UL       /**> Num of odd pins port A */
#define GPIO_NUM_ODD_PB                         0x3UL       /**> Num of odd pins port B */
#define GPIO_NUM_ODD_PC                         0x5UL       /**> Num of odd pins port C */
#define GPIO_NUM_ODD_PD                         0x3UL       /**> Num of odd pins port D */
#define GPIO_PINSEL_WIDTH                       0x4UL       /**> Route config pin select width */
#define GPIO_PORTSEL_WIDTH                      0x2UL       /**> Route config port select width */
#define GPIO_PORT_A_WIDTH                       0xBUL       /**> Port A Width */
#define GPIO_PORT_A_WIDTH_ZERO                  0x0UL       /**> Port A Width is Zero */
#define GPIO_PORT_A_WL                          0x8UL       /**> New Param */
#define GPIO_PORT_A_WU                          0x3UL       /**> New Param */
#define GPIO_PORT_A_WU_ZERO                     0x0UL       /**> New Param */
#define GPIO_PORT_B_WIDTH                       0x7UL       /**> Port B Width */
#define GPIO_PORT_B_WIDTH_ZERO                  0x0UL       /**> Port B Width is Zero */
#define GPIO_PORT_B_WL                          0x7UL       /**> New Param */
#define GPIO_PORT_B_WU                          0x0UL       /**> New Param */
#define GPIO_PORT_B_WU_ZERO                     0x1UL       /**> New Param */
#define GPIO_PORT_C_WIDTH                       0xAUL       /**> Port C Width */
#define GPIO_PORT_C_WIDTH_ZERO                  0x0UL       /**> Port C Width is Zero */
#define GPIO_PORT_C_WL                          0x8UL       /**> New Param */
#define GPIO_PORT_C_WU                          0x2UL       /**> New Param */
#define GPIO_PORT_C_WU_ZERO                     0x0UL       /**> New Param */
#define GPIO_PORT_D_WIDTH                       0x6UL       /**> Port D Width */
#define GPIO_PORT_D_WIDTH_ZERO                  0x0UL       /**> Port D Width is Zero */
#define GPIO_PORT_D_WL                          0x6UL       /**> New Param */
#define GPIO_PORT_D_WU                          0x0UL       /**> New Param */
#define GPIO_PORT_D_WU_ZERO                     0x1UL       /**> New Param */
#define GPIO_SEGALLOC_WIDTH                     0x14UL      /**> New Param */
#define GPIO_SLEWRATE_WIDTH                     0x3UL       /**> Slew Rate Width Param */
#define LDMA_CH_BITS                            0x5UL       /**> New Param */
#define LDMA_CH_NUM                             0x8UL       /**> New Param */
#define LDMA_FIFO_BITS                          0x5UL       /**> New Param */
#define LDMA_FIFO_DEPTH                         0x10UL      /**> New Param */
#define LDMAXBAR_CH_BITS                        0x5UL       /**> None */
#define LDMAXBAR_CH_NUM                         0x8UL       /**> None */
#define LDMAXBAR_SIGSEL_W                       0x4UL       /**> New Param */
#define LDMAXBAR_SOURCESEL_W                    0x6UL       /**> New Param */
#define TIMER0_CC_NUM                           0x3UL       /**> Number of Compare/Capture Channels */
#define TIMER0_CNTWIDTH                         0x20UL      /**> Counter Width */
#define TIMER0_DTI                              0x1UL       /**> Dead-time insertion enabled */
#define TIMER0_DTI_CC_NUM                       0x3UL       /**> Number of DTI Channels */
#define TIMER0_NO_DTI                           0x0UL       /**>  */
#define TIMER1_CC_NUM                           0x3UL       /**> Number of Compare/Capture Channels */
#define TIMER1_CNTWIDTH                         0x10UL      /**> Counter Width */
#define TIMER1_DTI                              0x1UL       /**> Dead-time insertion enabled */
#define TIMER1_DTI_CC_NUM                       0x3UL       /**> Number of DTI Channels */
#define TIMER1_NO_DTI                           0x0UL       /**>  */
#define TIMER2_CC_NUM                           0x3UL       /**> Number of Compare/Capture Channels */
#define TIMER2_CNTWIDTH                         0x10UL      /**> Counter Width */
#define TIMER2_DTI                              0x1UL       /**> Dead-time insertion enabled */
#define TIMER2_DTI_CC_NUM                       0x3UL       /**> Number of DTI Channels */
#define TIMER2_NO_DTI                           0x0UL       /**>  */
#define TIMER3_CC_NUM                           0x3UL       /**> Number of Compare/Capture Channels */
#define TIMER3_CNTWIDTH                         0x10UL      /**> Counter Width */
#define TIMER3_DTI                              0x1UL       /**> Dead-time insertion enabled */
#define TIMER3_DTI_CC_NUM                       0x3UL       /**> Number of DTI Channels */
#define TIMER3_NO_DTI                           0x0UL       /**>  */
#define TIMER4_CC_NUM                           0x3UL       /**> Number of Compare/Capture Channels */
#define TIMER4_CNTWIDTH                         0x10UL      /**> Counter Width */
#define TIMER4_DTI                              0x1UL       /**> Dead-time insertion enabled */
#define TIMER4_DTI_CC_NUM                       0x3UL       /**> Number of DTI Channels */
#define TIMER4_NO_DTI                           0x0UL       /**>  */
#define USART0_AUTOTX_REG                       0x1UL       /**> None */
#define USART0_AUTOTX_REG_B                     0x0UL       /**> None */
#define USART0_AUTOTX_TRIGGER                   0x1UL       /**> None */
#define USART0_AUTOTX_TRIGGER_B                 0x0UL       /**> New Param */
#define USART0_CLK_PRS                          0x1UL       /**> None */
#define USART0_CLK_PRS_B                        0x0UL       /**> New Param */
#define USART0_FLOW_CONTROL                     0x1UL       /**> None */
#define USART0_FLOW_CONTROL_B                   0x0UL       /**> New Param */
#define USART0_I2S                              0x1UL       /**> None */
#define USART0_I2S_B                            0x0UL       /**> New Param */
#define USART0_IRDA_AVAILABLE                   0x1UL       /**> None */
#define USART0_IRDA_AVAILABLE_B                 0x0UL       /**> New Param */
#define USART0_MVDIS_FUNC                       0x1UL       /**> None */
#define USART0_MVDIS_FUNC_B                     0x0UL       /**> New Param */
#define USART0_RX_PRS                           0x1UL       /**> None */
#define USART0_RX_PRS_B                         0x0UL       /**> New Param */
#define USART0_SC_AVAILABLE                     0x1UL       /**> None */
#define USART0_SC_AVAILABLE_B                   0x0UL       /**> New Param */
#define USART0_SYNC_AVAILABLE                   0x1UL       /**> None */
#define USART0_SYNC_AVAILABLE_B                 0x0UL       /**> New Param */
#define USART0_SYNC_LATE_SAMPLE                 0x1UL       /**> None */
#define USART0_SYNC_LATE_SAMPLE_B               0x0UL       /**> New Param */
#define USART0_TIMER                            0x1UL       /**> New Param */
#define USART0_TIMER_B                          0x0UL       /**> New Param */
#define BURTC_CNTWIDTH                          0x20UL      /**> None */
#define BURTC_PRECNT_WIDTH                      0xFUL       /**>  */
#define I2C1_DELAY                              0x7D0UL     /**> Delay cell selection */
#define I2C1_DELAY_CHAIN_NUM                    0x2UL       /**> Number of delay chain */
#define SYSCFG_CHIP_FAMILY                      0x38UL      /**> CHIP Family */
#define SYSCFG_DEMODRAM_INST_COUNT              0x1UL       /**>  */
#define SYSCFG_FRCRAM_INST_COUNT                0x1UL       /**>  */
#define SYSCFG_SEQRAM_INST_COUNT                0x2UL       /**> None */
#define SYSCFG_SWINT_NUM                        0x4UL       /**> Software interupts */
#define DCDC_DRVSPEED_WIDTH                     0x2UL       /**> Drive Speed bitfield width */
#define DCDC_IPKVAL_WIDTH                       0x4UL       /**> Peak Current Setting bitfield Width */
#define DCDC_VCMPIBIAS_WIDTH                    0x2UL       /**> VCMP ibias bitfield width */
#define HOSTMAILBOX_NUM_MSGPTRS                 0x4UL       /**>  */
#define EUSART1_EM2_CAPABLE                     0x0UL       /**> EM2 Capable instance */
#define EUSART1_NOT_EM2_CAPABLE                 0x1UL       /**> Not EM2 Capable instance */
#define EUSART2_EM2_CAPABLE                     0x0UL       /**> EM2 Capable instance */
#define EUSART2_NOT_EM2_CAPABLE                 0x1UL       /**> Not EM2 Capable instance */
#define SYSRTC0_GROUP0_ALTIRQDIS                0x1UL       /**> Group 0 Alternate IRQ disable */
#define SYSRTC0_GROUP0_CAPDIS                   0x0UL       /**> Group 0 Capture disable */
#define SYSRTC0_GROUP0_CMP1DIS                  0x0UL       /**> Group 0 Compare1 disable */
#define SYSRTC0_GROUP0_DIS                      0x0UL       /**> Group 0 Disable */
#define SYSRTC0_GROUP0_ROOTDIS                  0x1UL       /**> Group 0 ROOT disable */
#define SYSRTC0_GROUP1_ALTIRQDIS                0x0UL       /**> Group 1 Alternate IRQ disable */
#define SYSRTC0_GROUP1_CAPDIS                   0x0UL       /**> Group 1 Capture disable */
#define SYSRTC0_GROUP1_CMP1DIS                  0x0UL       /**> Group 1 Compare1 disable */
#define SYSRTC0_GROUP1_DIS                      0x0UL       /**> Group 1 Disable */
#define SYSRTC0_GROUP1_ROOTDIS                  0x1UL       /**> Group 1 ROOT disable */
#define SYSRTC0_GROUP2_ALTIRQDIS                0x1UL       /**> Group 2 Alternate IRQ disable */
#define SYSRTC0_GROUP2_CAPDIS                   0x1UL       /**> Group 2 Capture disable */
#define SYSRTC0_GROUP2_CMP1DIS                  0x1UL       /**> Group 2 Compare1 disable */
#define SYSRTC0_GROUP2_DIS                      0x0UL       /**> Group 2 Disable */
#define SYSRTC0_GROUP2_ROOTDIS                  0x0UL       /**> Group 2 ROOT disable */
#define SYSRTC0_GROUP3_ALTIRQDIS                0x1UL       /**> Group 3 Alternate IRQ disable */
#define SYSRTC0_GROUP3_CAPDIS                   0x1UL       /**> Group 3 Capture disable */
#define SYSRTC0_GROUP3_CMP1DIS                  0x1UL       /**> Group 3 Compare1 disable */
#define SYSRTC0_GROUP3_DIS                      0x1UL       /**> Group 3 Disable */
#define SYSRTC0_GROUP3_ROOTDIS                  0x1UL       /**> Group 3 ROOT disable */
#define SYSRTC0_GROUP4_ALTIRQDIS                0x1UL       /**> Group 4 Alternate IRQ disable */
#define SYSRTC0_GROUP4_CAPDIS                   0x1UL       /**> Group 4 Capture disable */
#define SYSRTC0_GROUP4_CMP1DIS                  0x1UL       /**> Group 4 Compare1 disable */
#define SYSRTC0_GROUP4_DIS                      0x1UL       /**> Group 4 Disable */
#define SYSRTC0_GROUP4_ROOTDIS                  0x1UL       /**> Group 4 ROOT disable */
#define SYSRTC0_GROUP5_ALTIRQDIS                0x1UL       /**> Group 5 Alternate IRQ disable */
#define SYSRTC0_GROUP5_CAPDIS                   0x1UL       /**> Group 5 Capture disable */
#define SYSRTC0_GROUP5_CMP1DIS                  0x1UL       /**> Group 5 Compare1 disable */
#define SYSRTC0_GROUP5_DIS                      0x1UL       /**> Group 5 Disable */
#define SYSRTC0_GROUP5_ROOTDIS                  0x1UL       /**> Group 5 ROOT disable */
#define SYSRTC0_GROUP6_ALTIRQDIS                0x1UL       /**> Group 6 Alternate IRQ disable */
#define SYSRTC0_GROUP6_CAPDIS                   0x1UL       /**> Group 6 Capture disable */
#define SYSRTC0_GROUP6_CMP1DIS                  0x1UL       /**> Group 6 Compare1 disable */
#define SYSRTC0_GROUP6_DIS                      0x1UL       /**> Group 6 Disable */
#define SYSRTC0_GROUP6_ROOTDIS                  0x1UL       /**> Group 6 ROOT disable */
#define SYSRTC0_GROUP7_ALTIRQDIS                0x1UL       /**> Group 7 Alternate IRQ disable */
#define SYSRTC0_GROUP7_CAPDIS                   0x1UL       /**> Group 7 Capture disable */
#define SYSRTC0_GROUP7_CMP1DIS                  0x1UL       /**> Group 7 Compare1 disable */
#define SYSRTC0_GROUP7_DIS                      0x1UL       /**> Group 7 Disable */
#define SYSRTC0_GROUP7_ROOTDIS                  0x1UL       /**> Group 7 ROOT disable */
#define SYSRTC0_ROOTDIS                         0x0UL       /**> ROOT disable */
#define LCD_COM_NUM                             0x4UL       /**> None */
#define LCD_NO_ANIM_LOCS                        0x1UL       /**> None */
#define LCD_NO_BANKED_SEG                       0x1UL       /**>  */
#define LCD_NO_DSC                              0x0UL       /**> None */
#define LCD_NO_EXTOSC                           0x0UL       /**> None */
#define LCD_NO_UPPER_SEGMENTS                   0x1UL       /**>  */
#define LCD_OCTAPLEX                            0x0UL       /**> None */
#define LCD_SEGASCOM_NUM                        0x4UL       /**> None */
#define LCD_SEG_NUM                             0x14UL      /**> None */
#define LCD_SEL_WIDTH                           0x3UL       /**> None */
#define KEYSCAN_COLNUM                          0x8UL       /**> COLNUM */
#define KEYSCAN_COLWIDTH                        0x3UL       /**> COLWIDTH */
#define KEYSCAN_ROWNUM                          0x6UL       /**> ROWNUM */
#define PFMXPPRF_COUNT_WIDTH                    0x9UL       /**> Width of counters for pulse-pairing */
#define RADIOAES_SIDECHANNEL_COUNTERMEASURES    0x1UL       /**> Enable sidechannel counter measures */
#define SMU_NUM_BMPUS                           0x7UL       /**> Number of BMPUs */
#define SMU_NUM_PPU_PERIPHS                     0x39UL      /**> Number of PPU Peripherals */
#define SMU_NUM_PPU_PERIPHS_MOD_32              0x19UL      /**> Number of PPU Peripherals (mod 32) */
#define SMU_NUM_PPU_PERIPHS_SUB_32              0x19UL      /**> Number of PPU peripherals minus 32 */
#define SMU_PERIPHID_BITS                       0x8UL       /**> Bits used for Peripheral ID */
#define LETIMER0_CNT_WIDTH                      0x18UL      /**> Count Width */
#define IADC0_CONFIGNUM                         0x2UL       /**> CONFIG */
#define IADC0_FULLRANGEUNIPOLAR                 0x0UL       /**> FULLRANGEUNIPOLAR */
#define IADC0_SCANBYTES                         0x1UL       /**> SCANBYTES */
#define IADC0_ENTRIES                           0x10UL      /**> ENTRIES */
#define ACMP0_DAC_INPUT                         0x1UL       /**> None */
#define ACMP0_EXT_OVR_IF                        0x1UL       /**> None */
#define ACMP1_DAC_INPUT                         0x1UL       /**> None */
#define ACMP1_EXT_OVR_IF                        0x1UL       /**> None */
#define AMUXCP0_AMUXCPNUM                       0x0UL       /**> AMUXCPNUM */
#define VDAC0_ALT_WIDTH                         0x6UL       /**> VOUT_AUX Out Width */
#define VDAC0_CH1_TRIG_LESENSE                  0x0UL       /**> CH1 Trig Source = LESENSE */
#define VDAC0_FIFO_DEPTH                        0x4UL       /**> WFIFO Depth */
#define VDAC0_INT_PRESC_WIDTH                   0x7UL       /**> Internal Prescaler Width */
#define VDAC0_RESOLUTION                        0xCUL       /**> DAC Resolution */
#define PCNT0_PCNT_WIDTH                        0x10UL      /**> None */
#define LESENSE_CHANNEL_NUM                     0x10UL      /**> None */
#define LESENSE_RIPCNT_WIDTH                    0x10UL      /**> None */
#define LESENSE_STATE_NUM                       0x20UL      /**> None */
#define HFRCOEM23_EM23ONDEMAND                  0x1UL       /**> EM23 On Demand */
#define HFRCOEM23_EXCLUDEEM23ONDEMAND           0x0UL       /**> Exclude EM23 On Demand */
#define HFXO0_BUFOUT                            0x1UL       /**> BUFOUT */
#define HFXO0_EXCLUDEBUFOUT                     0x0UL       /**> Exclude BUFOUT */
#define I2C0_DELAY                              0x3E8UL     /**> Delay cell selection */
#define I2C0_DELAY_CHAIN_NUM                    0x2UL       /**> Number of delay chain */
#define WDOG0_PCNUM                             0x2UL       /**> None */
#define WDOG1_PCNUM                             0x2UL       /**> None */
#define EUSART0_EM2_CAPABLE                     0x1UL       /**> EM2 Capable instance */
#define EUSART0_NOT_EM2_CAPABLE                 0x0UL       /**> Not EM2 Capable instance */
#define RDMEM_FRC_BANK0_SIZE                    0x1000UL    /**> FRC_RAM_BANK0_SIZE */
#define RDMEM_FRC_BANK1_SIZE                    0x0UL       /**> FRC_RAM_BANK1_SIZE */
#define RDMEM_FRC_BANK2_SIZE                    0x0UL       /**> FRC_RAM_BANK2_SIZE */
#define RDMEM_FRC_BANK3_SIZE                    0x0UL       /**> FRC_RAM_BANK3_SIZE */
#define RDMEM_FRC_BANK4_SIZE                    0x0UL       /**> FRC_RAM_BANK4_SIZE */
#define RDMEM_FRC_BANK5_SIZE                    0x0UL       /**> FRC_RAM_BANK5_SIZE */
#define RDMEM_FRC_BANK6_SIZE                    0x0UL       /**> FRC_RAM_BANK6_SIZE */
#define RDMEM_FRC_BANK7_SIZE                    0x0UL       /**> FRC_RAM_BANK7_SIZE */
#define RDMEM_FRC_NUM_BANK                      0x1UL       /**> FRC_NUM_BANK */
#define RDMEM_FRC_RAMADDRBITS                   0xCUL       /**> FRC RAM ADDRBITS */
#define RDMEM_FRC_RAMADDRMINBITS                0xCUL       /**> FRC RAM address bits for one bank */
#define RDMEM_FRC_RAMECCADDR_WIDTH              0x20UL      /**> FRC RAM ECC Address width */
#define RDMEM_FRC_RAM_BWE_WIDTH                 0x27UL      /**> FRCRAM BWE width */
#define RDMEM_FRC_RAM_DATA_WIDTH                0x27UL      /**> FRC_RAM_DATA_WIDTH */
#define RDMEM_FRC_RAM_ECC_EN                    0x1UL       /**> FRC RAM ECCEN */
#define RDMEM_FRC_RAM_TOTAL_SIZE                0x1000UL    /**> FRC_RAM_TOTAL_SIZE */
#define RDMEM_SEQ_BANK0_SIZE                    0x2000UL    /**> SEQ_RAM_BANK0_SIZE */
#define RDMEM_SEQ_BANK1_SIZE                    0x2000UL    /**> SEQ_RAM_BANK1_SIZE */
#define RDMEM_SEQ_BANK2_SIZE                    0x0UL       /**> SEQ_RAM_BANK2_SIZE */
#define RDMEM_SEQ_BANK3_SIZE                    0x0UL       /**> SEQ_RAM_BANK3_SIZE */
#define RDMEM_SEQ_BANK4_SIZE                    0x0UL       /**> SEQ_RAM_BANK4_SIZE */
#define RDMEM_SEQ_BANK5_SIZE                    0x0UL       /**> SEQ_RAM_BANK5_SIZE */
#define RDMEM_SEQ_BANK6_SIZE                    0x0UL       /**> SEQ_RAM_BANK6_SIZE */
#define RDMEM_SEQ_BANK7_SIZE                    0x0UL       /**> SEQ_RAM_BANK7_SIZE */
#define RDMEM_SEQ_NUM_BANK                      0x2UL       /**> SEQ_NUM_BANK */
#define RDMEM_SEQ_RAMADDRBITS                   0xEUL       /**> SEQ RAM ADDRBITS */
#define RDMEM_SEQ_RAMADDRMINBITS                0xDUL       /**> SEQ RAM address bits for one bank */
#define RDMEM_SEQ_RAMECCADDR_WIDTH              0x20UL      /**> SEQ RAM ECC Address width */
#define RDMEM_SEQ_RAM_BWE_WIDTH                 0x27UL      /**> SEQRAM BWE width */
#define RDMEM_SEQ_RAM_DATA_WIDTH                0x27UL      /**> SEQ_RAM_DATA_WIDTH */
#define RDMEM_SEQ_RAM_ECC_EN                    0x1UL       /**> SEQ RAM ECCEN */
#define RDMEM_SEQ_RAM_TOTAL_SIZE                0x4000UL    /**> SEQ_RAM_TOTAL_SIZE */
#define FRC_DEMOD_FILT_WIDTH                    0x13UL      /**> New Param */
#define FRC_FCD_NUM                             0x4UL       /**> None */
#define FRC_INTELEMENTS                         0x10UL      /**> None */
#define FRC_RAMADDR_WIDTH                       0x20UL      /**> None */
#define AGC_AMPLITUDE_WIDTH                     0x14UL      /**> New Param */
#define AGC_POWER_WIDTH                         0xCUL       /**> New Param */
#define MODEM_ADDR_WIDTH                        0xBUL       /**> New Param */
#define MODEM_AMPLITUDE_WIDTH                   0x14UL      /**> New Param */
#define MODEM_ANT_NUM                           0x2UL       /**> Antenna Number */
#define MODEM_DEC0_SIZE                         0xFUL       /**> New Param */
#define MODEM_DEMOD_RAM_WIDTH                   0xAUL       /**> New Param */
#define MODEM_DEMOD_WIDTH                       0x8UL       /**> New Param */
#define MODEM_█████████_SIZE                     0x13UL      /**> New Param */
#define MODEM_IN_SIZE                           0x8UL       /**> New Param */
#define MODEM_LEADING_BITS_SIZE                 0x4UL       /**> New Param */
#define MODEM_PHASE_SIZE                        0x8UL       /**> New Param */
#define MODEM_POWER_WIDTH                       0xCUL       /**> New Param */
#define MODEM_RAM_SIZE                          0x100UL     /**> New Param */
#define MODEM_REMOVE_BCR                        0x0UL       /**> New Param */
#define MODEM_REMOVE_COH_DEMOD                  0x0UL       /**> New Param */
#define MODEM_REMOVE_DEMOD_FILTER               0x0UL       /**> New Param */
#define MODEM_REMOVE_IQDSA                      0x1UL       /**> New Param */
#define MODEM_REMOVE_LRBLE                      0x1UL       /**> New Param */
#define MODEM_SYMBOL_WIDTH                      0x4UL       /**> New Param */
#define SYNTH_CHPDACBITS                        0x8UL       /**>  */
#define SYNTH_DACDEMBITS                        0x3UL       /**>  */
#define SYNTH_MMDDENOMBITS                      0x9UL       /**>  */
#define SYNTH_MODEM_AFCADJ_WIDTH                0x13UL      /**>  */
#define SYNTH_MOD_OUT_WIDTH                     0x11UL      /**>  */
#define SYNTH_ZERO_IF_RECEIVER                  0x0UL       /**>  */
#define PROTIMER_CC_NUM                         0x8UL       /**> None */
#define PROTIMER_PRS_NUM                        0xBUL       /**>  */
#define RAC_DIAGABLK_WIDTH                      0x7UL       /**> None */
#define RAC_DIAGATP_WIDTH                       0x6UL       /**> None */
#define RAC_DPI_CHAN_COUNT                      0x6UL       /**>  */
#define RAC_PRESC_BITS                          0x7UL       /**> None */
#define RAC_WAIT_BITS                           0xAUL       /**> None */
#define RFMAILBOX_NUM_MSGPTRS                   0x4UL       /**>  */
#define RFECA0_BUF_NUM                          0x2UL       /**> Number of Memory Buffers */
#define RFECA1_BUF_NUM                          0x2UL       /**> Number of Memory Buffers */
#define ECAIFADC_FIFO_SIZE                      0x4UL       /**> FIFO size */
#define BUFC_LOG2NUMOFBUFS                      0x2UL       /**> New Param */
#define BUFC_LOG2NUMOFINPUTS                    0x1UL       /**> New Param */
#define BUFC_NUMOFBUFS                          0x4UL       /**> New Param */
#define BUFC_NUMOFINPUTS                        0x1UL       /**> New Param */

/* Instance macros for ACMP */
#define ACMP(n)                         (((n) == 0) ? ACMP0   \
                                         : ((n) == 1) ? ACMP1 \
                                         : 0x0UL)
#define ACMP_NUM(ref)                   (((ref) == ACMP0) ? 0   \
                                         : ((ref) == ACMP1) ? 1 \
                                         : -1)
#define ACMP_DAC_INPUT(n)               (((n) == 0) ? ACMP0_DAC_INPUT   \
                                         : ((n) == 1) ? ACMP1_DAC_INPUT \
                                         : 0x0UL)
#define ACMP_EXT_OVR_IF(n)              (((n) == 0) ? ACMP0_EXT_OVR_IF   \
                                         : ((n) == 1) ? ACMP1_EXT_OVR_IF \
                                         : 0x0UL)

/* Instance macros for ECA */
#define ECA(n)                          (((n) == 0) ? RFECA0   \
                                         : ((n) == 1) ? RFECA1 \
                                         : 0x0UL)
#define ECA_NUM(ref)                    (((ref) == RFECA0) ? 0   \
                                         : ((ref) == RFECA1) ? 1 \
                                         : -1)
#define ECA_BUF_NUM(n)                  (((n) == 0) ? RFECA0_BUF_NUM   \
                                         : ((n) == 1) ? RFECA1_BUF_NUM \
                                         : 0x0UL)

/* Instance macros for EUSART */
#define EUSART(n)                       (((n) == 0) ? EUSART0   \
                                         : ((n) == 1) ? EUSART1 \
                                         : ((n) == 2) ? EUSART2 \
                                         : 0x0UL)
#define EUSART_NUM(ref)                 (((ref) == EUSART0) ? 0   \
                                         : ((ref) == EUSART1) ? 1 \
                                         : ((ref) == EUSART2) ? 2 \
                                         : -1)
#define EUSART_EM2_CAPABLE(n)           (((n) == 0) ? EUSART0_EM2_CAPABLE   \
                                         : ((n) == 1) ? EUSART1_EM2_CAPABLE \
                                         : ((n) == 2) ? EUSART2_EM2_CAPABLE \
                                         : 0x0UL)
#define EUSART_NOT_EM2_CAPABLE(n)       (((n) == 0) ? EUSART0_NOT_EM2_CAPABLE   \
                                         : ((n) == 1) ? EUSART1_NOT_EM2_CAPABLE \
                                         : ((n) == 2) ? EUSART2_NOT_EM2_CAPABLE \
                                         : 0x0UL)

/* Instance macros for HFRCO */
#define HFRCO(n)                        (((n) == 0) ? HFRCO0      \
                                         : ((n) == 1) ? HFRCOEM23 \
                                         : 0x0UL)
#define HFRCO_NUM(ref)                  (((ref) == HFRCO0) ? 0      \
                                         : ((ref) == HFRCOEM23) ? 1 \
                                         : -1)
#define HFRCO_EM23ONDEMAND(n)           (((n) == 0) ? HFRCO0_EM23ONDEMAND      \
                                         : ((n) == 1) ? HFRCOEM23_EM23ONDEMAND \
                                         : 0x0UL)
#define HFRCO_EXCLUDEEM23ONDEMAND(n)    (((n) == 0) ? HFRCO0_EXCLUDEEM23ONDEMAND      \
                                         : ((n) == 1) ? HFRCOEM23_EXCLUDEEM23ONDEMAND \
                                         : 0x0UL)

/* Instance macros for I2C */
#define I2C(n)                          (((n) == 0) ? I2C0   \
                                         : ((n) == 1) ? I2C1 \
                                         : 0x0UL)
#define I2C_NUM(ref)                    (((ref) == I2C0) ? 0   \
                                         : ((ref) == I2C1) ? 1 \
                                         : -1)
#define I2C_DELAY(n)                    (((n) == 0) ? I2C0_DELAY   \
                                         : ((n) == 1) ? I2C1_DELAY \
                                         : 0x0UL)
#define I2C_DELAY_CHAIN_NUM(n)          (((n) == 0) ? I2C0_DELAY_CHAIN_NUM   \
                                         : ((n) == 1) ? I2C1_DELAY_CHAIN_NUM \
                                         : 0x0UL)

/* Instance macros for TIMER */
#define TIMER(n)                        (((n) == 0) ? TIMER0   \
                                         : ((n) == 1) ? TIMER1 \
                                         : ((n) == 2) ? TIMER2 \
                                         : ((n) == 3) ? TIMER3 \
                                         : ((n) == 4) ? TIMER4 \
                                         : 0x0UL)
#define TIMER_NUM(ref)                  (((ref) == TIMER0) ? 0   \
                                         : ((ref) == TIMER1) ? 1 \
                                         : ((ref) == TIMER2) ? 2 \
                                         : ((ref) == TIMER3) ? 3 \
                                         : ((ref) == TIMER4) ? 4 \
                                         : -1)
#define TIMER_CC_NUM(n)                 (((n) == 0) ? TIMER0_CC_NUM   \
                                         : ((n) == 1) ? TIMER1_CC_NUM \
                                         : ((n) == 2) ? TIMER2_CC_NUM \
                                         : ((n) == 3) ? TIMER3_CC_NUM \
                                         : ((n) == 4) ? TIMER4_CC_NUM \
                                         : 0x0UL)
#define TIMER_CNTWIDTH(n)               (((n) == 0) ? TIMER0_CNTWIDTH   \
                                         : ((n) == 1) ? TIMER1_CNTWIDTH \
                                         : ((n) == 2) ? TIMER2_CNTWIDTH \
                                         : ((n) == 3) ? TIMER3_CNTWIDTH \
                                         : ((n) == 4) ? TIMER4_CNTWIDTH \
                                         : 0x0UL)
#define TIMER_DTI(n)                    (((n) == 0) ? TIMER0_DTI   \
                                         : ((n) == 1) ? TIMER1_DTI \
                                         : ((n) == 2) ? TIMER2_DTI \
                                         : ((n) == 3) ? TIMER3_DTI \
                                         : ((n) == 4) ? TIMER4_DTI \
                                         : 0x0UL)
#define TIMER_DTI_CC_NUM(n)             (((n) == 0) ? TIMER0_DTI_CC_NUM   \
                                         : ((n) == 1) ? TIMER1_DTI_CC_NUM \
                                         : ((n) == 2) ? TIMER2_DTI_CC_NUM \
                                         : ((n) == 3) ? TIMER3_DTI_CC_NUM \
                                         : ((n) == 4) ? TIMER4_DTI_CC_NUM \
                                         : 0x0UL)
#define TIMER_NO_DTI(n)                 (((n) == 0) ? TIMER0_NO_DTI   \
                                         : ((n) == 1) ? TIMER1_NO_DTI \
                                         : ((n) == 2) ? TIMER2_NO_DTI \
                                         : ((n) == 3) ? TIMER3_NO_DTI \
                                         : ((n) == 4) ? TIMER4_NO_DTI \
                                         : 0x0UL)

/* Instance macros for WDOG */
#define WDOG(n)                         (((n) == 0) ? WDOG0   \
                                         : ((n) == 1) ? WDOG1 \
                                         : 0x0UL)
#define WDOG_NUM(ref)                   (((ref) == WDOG0) ? 0   \
                                         : ((ref) == WDOG1) ? 1 \
                                         : -1)
#define WDOG_PCNUM(n)                   (((n) == 0) ? WDOG0_PCNUM   \
                                         : ((n) == 1) ? WDOG1_PCNUM \
                                         : 0x0UL)

/** @} End of group EFR32FG23B020F512IM40_Peripheral_Parameters  */

/** @} End of group EFR32FG23B020F512IM40 */
/** @}} End of group Parts */

#ifdef __cplusplus
}
#endif
#endif
