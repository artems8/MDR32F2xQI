/**
  ******************************************************************************
  * @file    MDR32F2xQI_config.h
  * @author  Milandr Application Team
  * @version V2.0.2i
  * @date    10/03/2022
  * @brief   Library configuration file.
  ******************************************************************************
  * <br><br>
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MILANDR SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2022 Milandr</center></h2>
  */

/**
  * @mainpage MDR32F2xQI Standard Peripherals Library.
  * MDR32F2xQI Standard Peripherals Library is a package consisting of
  * all standard peripheral device drivers for MDR32F1QI, MDR32F9Q2I,
  * MDR32FG16S1QI microcontrollers.
  * This library is a firmware package which contains a collection of routines,
  * data structures and macros covering the features of Milandr MDR32F2xQI
  * peripherals. It includes a description of the device drivers plus a set of
  * examples for each peripheral. The firmware library allows any device to be
  * used in the user application without the need for in-depth study of each
  * peripherals specifications. Using the Standard Peripherals Library has two
  * advantages: it saves significant time that would otherwise be spent in
  * coding, while simultaneously reducing application development and
  * integration costs.
  *
  * The MDR32F2xQI Standard Peripherals Library is full CMSIS compliant.
  */

// <<< Use Configuration Wizard in Context Menu >>>


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F2xQI_CONFIG_H
#define __MDR32F2xQI_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <RTE_Components.h> // Keil uVision specific inclusion

/* Uncomment the line corresponding to the target microcontroller */
/* When using Keil uVision, the definition is set automatically
   (when RTE_Components.h included) according to the selected
   microcontroller in "Options for Target->Device" window.*/
   
 #define USE_MDR32F21QI
 //#define USE_MDR32F23QI

/* Select the header file for target microcontroller */
#if defined (USE_MDR32F21QI)
    #include "MDR32F21QI.h"
#elif defined (USE_MDR32F23QI)
    #include "MDR32F23QI.h"
#else
    #error "Microcontroller not selected in MDR32F2xQI_config.h file"
#endif

// <c3> SWD pins protection
// <i> Prevents RTXT and OE bits setting for SWD pins when doing GPIO read-modify-write.
// <i> Uncomment the definition below to define used SWD port.
// <i> Leave all commented/unchecked if there is no GPIO pins combined with SWD.
#define USE_SWD
// </c>

// <h> Target system parameters
// <h> RST_CLK generators frequencies
// <o> HSI clock value [Hz]
// <i> Default: 8000000 (8MHz)
#define HSI_Value       ((uint32_t)8000000)
// <o> HSE clock value [Hz]
// <i> Default: 8000000 (8MHz)
#define HSE_Value       ((uint32_t)8000000)
// <o> LSI clock value [Hz]
// <i> Default: 40000 (40kHz)
#define LSI_Value       ((uint32_t)40000)
// <o> LSE clock value [Hz]
// <i> Default: 32768 (32.768kHz)
#define LSE_Value       ((uint32_t)32768)
// </h>


// <h> RST_CLK frequencies startup timeouts settings
// <o> HSE timeout startup value
// <i> Default: 0x0600
#define HSEonTimeOut    ((uint16_t)0x0600)
// <o> LSE timeout startup value
// <i> Default: 0x0600
#define LSEonTimeOut    ((uint16_t)0x0600)
// <o> HSI timeout startup value
// <i> Default: 0x0600
#define HSIonTimeOut    ((uint16_t)0x0600)
// <o> LSI timeout startup value
// <i> Default: 0x0600
#define LSIonTimeOut    ((uint16_t)0x0600)
// <o> PLLCPU timeout startup value
// <i> Default: 0x0600
#define PLLCPUonTimeOut ((uint16_t)0x0600)
// </h>

// <o> EEPROM controller freq [MHz]
 //<i> Default: 8MHz
#define FLASH_PROG_FREQ_MHZ     (8.0)
// </h>

#if defined (USE_MDR32F21QI)
// <h> Controller blocks settings
// <h> DMA configuration parameters
// <o.0..5> Number of DMA channels to use
// <i> This parameter is in range 1..32
// <i> Default: 32
#define DMA_Channels_Number   32

// <o> Alternate Control Data Structure Usage
//   <0=> 0: DMA_ALternateDataDisabled
//   <1=> 1: DMA_ALternateDataEnabled
// <i> Default: 1 (DMA_ALternateDataEnabled)
#define DMA_AlternateData     1
// </h>
#endif


// </h>
// <h> Examples settings
// <c2> Use debug UART
// <i> Definition used in examples
// <i> Default: commented/not defined
    //#define _USE_DEBUG_UART_
// </c>

#if defined (_USE_DEBUG_UART_)

#if defined (USE_MDR32F21QI)
    #define DEBUG_UART                  MDR_UART1
    #define DEBUG_UART_PORT             MDR_PORTC
    #define DEBUG_UART_PINS             (PORT_Pin_3 | PORT_Pin_4)
    #define DEBUG_UART_PINS_FUNCTION    PORT_FUNC_MAIN
    #define DEBUG_BAUD_RATE             115200
#elif defined (USE_MDR32F23QI)
    #define DEBUG_UART                  MDR_UART2
    #define DEBUG_UART_PORT             MDR_PORTF
    #define DEBUG_UART_PINS             (PORT_Pin_0 | PORT_Pin_1)
    #define DEBUG_UART_PINS_FUNCTION    PORT_FUNC_OVERRID
    #define DEBUG_BAUD_RATE             115200
#endif

#endif /* #if defined (_USE_DEBUG_UART_) */



// <h> RTC configuration parameters
// <o> RTC calibration value
// <i> Default: 0
#define RTC_CalibratorValue     0
// <o> RTC prescaler value
// <i> Default: 32768
#define RTC_PRESCALER_VALUE     32768
// </h>


#if defined (__ICCARM__)
    #define __attribute__(name_section)
    #if defined (USE_MDR32F1QI)
        #pragma section = "EXECUTABLE_MEMORY_SECTION"
        #define IAR_SECTION(section) @ section
    #elif defined (USE_MDR32F9Q2I)
        #define IAR_SECTION(section)
    #endif
#endif
#if defined (__CMCARM__)
    #define __attribute__(name_section)
    #define IAR_SECTION(section)
#endif
#if defined (__ARMCC_VERSION)
    #define IAR_SECTION(section)
#endif


// <h> Parameter run-time check support

// <o> Paramater checking level
//   <0=> 0: no parameter checks ("assert_param" macro is disabled)
//   <1=> 1: check enabled, source file ID and line number are available
//   <2=> 2: check enabled, source file ID, line number and checking expression (as string) are available (increased code size)
// <i> Default: 0 ("assert_param" macro is disabled)
#define USE_ASSERT_INFO    1

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed user's function which 
  *         reports the name of the source file, source line number
  *         and expression text (if USE_ASSERT_INFO == 2) of the call that failed.
  *         That function should not return. If expr is true, nothing is done.
  * @retval None
  */
#if (USE_ASSERT_INFO == 0)
    #define assert_param(expr) ((void)0U)
#elif (USE_ASSERT_INFO == 1)
    #define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
    void assert_failed(uint8_t* file, uint32_t line);
#elif (USE_ASSERT_INFO == 2)
    #define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__, (const uint8_t*) #expr))
    void assert_failed(uint8_t* file, uint32_t line, const uint8_t* expr);
#else
    #error "Unsupported USE_ASSERT_INFO level"
#endif /* USE_ASSERT_INFO */

// </h>

#ifdef __cplusplus
}
#endif

#endif /* __MDR32F2xQI_CONFIG_H */

/*********************** (C) COPYRIGHT 2022 Milandr ****************************
*
* END OF FILE MDR32F2xQI_config.h */

