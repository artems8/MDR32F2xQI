
/**
  * FILE MDR32F23QI.h
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F23QI_H
#define __MDR32F23QI_H

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @addtogroup MDR32F23QI MDR32F21QI
  * @{
  */

/** @addtogroup MDR32F23QI_Peripheral MDR32F23QI Peripheral
  * @{
  */

#ifdef __cplusplus
extern "C" {
#endif

#if defined ( __CC_ARM   )
  #pragma anon_unions
#endif

/**
  * @brief MDR32F23QI Interrupt Number Definition
  */
  
  
  typedef enum IRQn
{
/* =======================================  ARM Cortex-M0 Specific Interrupt Numbers  ======================================== */

  Reset_IRQn                = -15,              /*!< -15  Reset Vector, invoked on Power up and warm reset                     */
  NonMaskableInt_IRQn       = -14,              /*!< -14  Non maskable Interrupt, cannot be stopped or preempted               */
  HardFault_IRQn            = -13,              /*!< -13  Hard Fault, all classes of Fault                                     */
  SVCall_IRQn               =  -5,              /*!< -5 System Service Call via SVC instruction                                */
  PendSV_IRQn               =  -2,              /*!< -2 Pendable request for system service                                    */
  SysTick_IRQn              =  -1,              /*!< -1 System Tick Timer                                                      */

/* ===========================================  MDR32F23QI Specific Interrupt Numbers  ======================================== */
  Reserved_0_IRQn           = 0,                /*!< Reserved Interrupt   */
  UART0_IRQn                = 1,                /*!< UART1  Interrupt     */
  UART1_IRQn                = 2,                /*!< UART2  Interrupt     */
  SSP1_IRQn                 = 3,                /*!< SSP1  Interrupt      */
  POWER_IRQn                = 4,                /*!< POWER Interrupt      */
  WWDG_IRQn                 = 5,                /*!< WWDG Interrupt       */
  TIMER0_IRQn               = 6,                /*!< Timer1  Interrupt    */
  TIMER1_IRQn               = 7,                /*!< Timer2  Interrupt    */
  ADC_IRQn                  = 8,                /*!< ADC  Interrupt       */
  I2C_IRQn                  = 9,                /*!< I2C  Interrupt       */
  BKP_IRQn                  = 10,               /*!< BACKUP  Interrupt    */
  EXT1_IRQn                 = 11,               /*!< EXT_INT0  Interrupt  */
  EXT2_IRQn                 = 12,               /*!< EXT_INT1  Interrupt  */
  EXT3_IRQn                 = 13,               /*!< EXT_INT2  Interrupt  */
  ADCUI_F0_IRQn             = 14,               /*!< ADCIU_F0 Interrupt   */
} IRQn_Type;

/** @addtogroup __MDR32F23QI___Configuration_of_CMSIS Configuration of CMSIS
  * @{
  */
/* Configuration of the Processor and Core Peripherals */
#define __CM0_REV               0x0201  /*!< Core Revision                                */
#define __MPU_PRESENT             0     /*!< MPU present or not                           */
#define __NVIC_PRIO_BITS          2     /*!< Number of Bits used for Priority Levels      */
#define __Vendor_SysTickConfig    0     /*!< Set to 1 if different SysTick Config is used */

/** @} */ /* __Configuration_of_CMSIS */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F2xQI_config.h"
#include "core_cm0.h"
//#include "system_MDR32F23QI.h"

/** @defgroup __MDR32F23QI___Exported_types Exported types
  * @{
  */
typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus, BitStatus;

#define IS_BIT_STATUS(STATUS)       (((STATUS) == RESET) || ((STATUS) == SET))

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE)  (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

/** @} */ /* End of group __Exported_types */


/** @addtogroup MDR32F23QI_Peripheral_Units MDR32F23QI Peripheral Units
  * @{
  */

/** @defgroup MDR32F23QI_Periph_SSP SSP
  * @{
  */


/* MDR_SSPx_TypeDef structure */
typedef struct {
    __IO uint32_t   CR0;                    /*!<SSP Control0 Register */
    __IO uint32_t   CR1;                    /*!<SSP Control1 Register */
    __IO uint32_t   DR;                     /*!<SSP Data Register */
    __IO uint32_t   SR;                     /*!<SSP Status Register */
    __IO uint32_t   CPSR;                   /*!<SSP Clock Prescaler Register */
    __IO uint32_t   IMSC;                   /*!<SSP Interrupt Mask Register */
    __IO uint32_t   RIS;                    /*!<SSP Interrupt Pending Register */
    __IO uint32_t   MIS;                    /*!<SSP Masked Interrupt Pending Register */
    __IO uint32_t   ICR;                    /*!<SSP Interrupt Clear Register */
}MDR_SSP_TypeDef;

/** @defgroup Periph_SSP_CR0 SSP CR0
  * @{
  */

/*-- SSP_CR0:SSP CR0 Register -----*/

/* Bit field positions: */
#define SSP_CR0_DSS_Pos                                    0
#define SSP_CR0_FRF_Pos                                    4
#define SSP_CR0_SPO_Pos                                    6
#define SSP_CR0_SPH_Pos                                    7
#define SSP_CR0_SCR_Pos                                    8

/* Bit field masks: */
#define SSP_CR0_DSS_Msk                                    ((uint32_t)0x0000000F)
#define SSP_CR0_FRF_Msk                                    ((uint32_t)0x00000030)
#define SSP_CR0_SPO                                        ((uint32_t)0x00000040)
#define SSP_CR0_SPH                                        ((uint32_t)0x00000080)
#define SSP_CR0_SCR_Msk                                    ((uint32_t)0x0000FF00)

/** @} */ /* End of group SSP_CR0 */

/** @defgroup Periph_SSP_CR1 SSP CR1
  * @{
  */

/*-- SSP_CR1:SSP CR1 Register -----*/

/* Bit field positions: */
#define SSP_CR1_LBM_Pos                                    0
#define SSP_CR1_SSE_Pos                                    1
#define SSP_CR1_MS_Pos                                     2
#define SSP_CR1_SOD_Pos                                    3

/* Bit field masks: */
#define SSP_CR1_LBM                                        ((uint32_t)0x00000001)
#define SSP_CR1_SSE                                        ((uint32_t)0x00000002)
#define SSP_CR1_MS                                         ((uint32_t)0x00000004)
#define SSP_CR1_SOD                                        ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_CR1 */

/** @defgroup Periph_SSP_DR SSP DR
  * @{
  */

/*-- SSP_DR:SSP DR Register -----*/

/* Bit field positions: */
#define SSP_DR_DATA_Pos                                    0

/* Bit field masks: */
#define SSP_DR_DATA_Msk                                    ((uint32_t)0x0000FFFF)

/** @} */ /* End of group SSP_DR */

/** @defgroup Periph_SSP_SR SSP SR
  * @{
  */

/*-- SSP_SR:SSP SR Register -----*/

/* Bit field positions: */
#define SSP_SR_TFE_Pos                                     0
#define SSP_SR_TNF_Pos                                     1
#define SSP_SR_RNE_Pos                                     2
#define SSP_SR_RFF_Pos                                     3
#define SSP_SR_BSY_Pos                                     4

/* Bit field masks: */
#define SSP_SR_TFE                                         ((uint32_t)0x00000001)
#define SSP_SR_TNF                                         ((uint32_t)0x00000002)
#define SSP_SR_RNE                                         ((uint32_t)0x00000004)
#define SSP_SR_RFF                                         ((uint32_t)0x00000008)
#define SSP_SR_BSY                                         ((uint32_t)0x00000010)

/** @} */ /* End of group SSP_SR */

/** @defgroup Periph_SSP_CPSR SSP CPSR
  * @{
  */

/*-- SSP_CPSR:SSP CPSR Register -----*/

/* Bit field positions: */
#define SSP_CPSR_CPSDVSR_Pos                               0

/* Bit field masks: */
#define SSP_CPSR_CPSDVSR_Msk                               ((uint32_t)0x000000FF)

/** @} */ /* End of group SSP_CPSR */

/** @defgroup Periph_SSP_IMSC SSP IMSC
  * @{
  */

/*-- SSP_IMSC:SSP IMSC Register -----*/

/* Bit field positions: */
#define SSP_IMSC_RORIM_Pos                                 0
#define SSP_IMSC_RTIM_Pos                                  1
#define SSP_IMSC_RXIM_Pos                                  2
#define SSP_IMSC_TXIM_Pos                                  3

/* Bit field masks: */
#define SSP_IMSC_RORIM                                     ((uint32_t)0x00000001)
#define SSP_IMSC_RTIM                                      ((uint32_t)0x00000002)
#define SSP_IMSC_RXIM                                      ((uint32_t)0x00000004)
#define SSP_IMSC_TXIM                                      ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_IMSC */

/** @defgroup Periph_SSP_RIS SSP RIS
  * @{
  */

/*-- SSP_RIS:SSP RIS Register -----*/

/* Bit field positions: */
#define SSP_RIS_RORRIS_Pos                                 0
#define SSP_RIS_RTRIS_Pos                                  1
#define SSP_RIS_RXRIS_Pos                                  2
#define SSP_RIS_TXRIS_Pos                                  3

/* Bit field masks: */
#define SSP_RIS_RORRIS                                     ((uint32_t)0x00000001)
#define SSP_RIS_RTRIS                                      ((uint32_t)0x00000002)
#define SSP_RIS_RXRIS                                      ((uint32_t)0x00000004)
#define SSP_RIS_TXRIS                                      ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_RIS */

/** @defgroup Periph_SSP_MIS SSP MIS
  * @{
  */

/*-- SSP_MIS:SSP MIS Register -----*/

/* Bit field positions: */
#define SSP_MIS_RORMIS_Pos                                 0
#define SSP_MIS_RTMIS_Pos                                  1
#define SSP_MIS_RXMIS_Pos                                  2
#define SSP_MIS_TXMIS_Pos                                  3

/* Bit field masks: */
#define SSP_MIS_RORMIS                                     ((uint32_t)0x00000001)
#define SSP_MIS_RTMIS                                      ((uint32_t)0x00000002)
#define SSP_MIS_RXMIS                                      ((uint32_t)0x00000004)
#define SSP_MIS_TXMIS                                      ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_MIS */

/** @defgroup Periph_SSP_ICR SSP ICR
  * @{
  */

/*-- SSP_ICR:SSP ICR Register -----*/

/* Bit field positions: */
#define SSP_ICR_RORIC_Pos                                  0
#define SSP_ICR_RTIC_Pos                                   1

/* Bit field masks: */
#define SSP_ICR_RORIC                                      ((uint32_t)0x00000001)
#define SSP_ICR_RTIC                                       ((uint32_t)0x00000002)

/** @} */ /* End of group SSP_ICR */

/** @} */ /* End of group SSP */

/** @defgroup MDR32F23QI_Periph_UART UART
  * @{
  */


/* MDR_UARTx_TypeDef structure */
typedef struct {
    __IO uint32_t   DR;                     /*!<UART Data Register */
    __IO uint32_t   RSR_ECR;                /*!<UART RSR Register */
    __I  uint32_t   RESERVED0[4];
    __IO uint32_t   FR;                     /*!<UART Flag Register */
    __I  uint32_t   RESERVED1;
    __IO uint32_t   ILPR;                   /*!<UART IrDA transfer Register */
    __IO uint32_t   IBRD;                   /*!<UART IBRD  Register*/
    __IO uint32_t   FBRD;                   /*!<UART FBRD Register */
    __IO uint32_t   LCR_H;                  /*!<UART LCR_H Register */
    __IO uint32_t   CR;                     /*!<UART Command Register */
    __IO uint32_t   IFLS;                   /*!<UART IFLS Register */
    __IO uint32_t   IMSC;                   /*!<UART Interrupt Mask Register */
    __IO uint32_t   RIS;                    /*!<UART Interrupt Pending Register */
    __IO uint32_t   MIS;                    /*!<UART Masked Interrupt Pending Register */
    __IO uint32_t   ICR;                    /*!<UART Interrupt Clear Register */
}MDR_UART_TypeDef;

/** @defgroup Periph_UART_DR UART DR
  * @{
  */

/*-- UART_DR:UART DR Register -----*/

/* Bit field positions: */
#define UART_DR_DATA_Pos                                   0
#define UART_DR_FE_Pos                                     8
#define UART_DR_PE_Pos                                     9
#define UART_DR_BE_Pos                                     10
#define UART_DR_OE_Pos                                     11

/* Bit field masks: */
#define UART_DR_DATA_Msk                                   ((uint32_t)0x000000FF)
#define UART_DR_FE                                         ((uint32_t)0x00000100)
#define UART_DR_PE                                         ((uint32_t)0x00000200)
#define UART_DR_BE                                         ((uint32_t)0x00000400)
#define UART_DR_OE                                         ((uint32_t)0x00000800)

/** @} */ /* End of group UART_DR */

/** @defgroup Periph_UART_RSR_ECR UART RSR_ECR
  * @{
  */

/*-- UART_RSR_ECR:UART RSR_ECR Register -----*/

/* Bit field positions: */
#define UART_RSR_ECR_FE_Pos                                0
#define UART_RSR_ECR_PE_Pos                                1
#define UART_RSR_ECR_BE_Pos                                2
#define UART_RSR_ECR_OE_Pos                                3

/* Bit field masks: */
#define UART_RSR_ECR_FE                                    ((uint32_t)0x00000001)
#define UART_RSR_ECR_PE                                    ((uint32_t)0x00000002)
#define UART_RSR_ECR_BE                                    ((uint32_t)0x00000004)
#define UART_RSR_ECR_OE                                    ((uint32_t)0x00000008)

/** @} */ /* End of group UART_RSR_ECR */

/** @defgroup Periph_UART_FR UART FR
  * @{
  */

/*-- UART_FR:UART FR Register -----*/

/* Bit field positions: */
#define UART_FR_CTS_Pos                                    0
#define UART_FR_DSR_Pos                                    1
#define UART_FR_DCD_Pos                                    2
#define UART_FR_BUSY_Pos                                   3
#define UART_FR_RXFE_Pos                                   4
#define UART_FR_TXFF_Pos                                   5
#define UART_FR_RXFF_Pos                                   6
#define UART_FR_TXFE_Pos                                   7
#define UART_FR_RI_Pos                                     8

/* Bit field masks: */
#define UART_FR_CTS                                        ((uint32_t)0x00000001)
#define UART_FR_DSR                                        ((uint32_t)0x00000002)
#define UART_FR_DCD                                        ((uint32_t)0x00000004)
#define UART_FR_BUSY                                       ((uint32_t)0x00000008)
#define UART_FR_RXFE                                       ((uint32_t)0x00000010)
#define UART_FR_TXFF                                       ((uint32_t)0x00000020)
#define UART_FR_RXFF                                       ((uint32_t)0x00000040)
#define UART_FR_TXFE                                       ((uint32_t)0x00000080)
#define UART_FR_RI                                         ((uint32_t)0x00000100)

/** @} */ /* End of group UART_FR */

/** @defgroup Periph_UART_ILPR UART ILPR
  * @{
  */

/*-- UART_ILPR:UART ILPR Register -----*/

/* Bit field positions: */
#define UART_ILPR_ILPDVSR_Pos                              0

/* Bit field masks: */
#define UART_ILPR_ILPDVSR_Msk                              ((uint32_t)0x000000FF)

/** @} */ /* End of group UART_ILPR */

/** @defgroup Periph_UART_IBRD UART IBRD
  * @{
  */

/*-- UART_IBRD:UART IBRD Register -----*/

/* Bit field positions: */
#define UART_IBRD_BAUD_DIVINT_Pos                          0

/* Bit field masks: */
#define UART_IBRD_BAUD_DIVINT_Msk                          ((uint32_t)0x0000FFFF)

/** @} */ /* End of group UART_IBRD */

/** @defgroup Periph_UART_FBRD UART FBRD
  * @{
  */

/*-- UART_FBRD:UART FBRD Register -----*/

/* Bit field positions: */
#define UART_FBRD_BAUD_DIVFRAC_Pos                         0

/* Bit field masks: */
#define UART_FBRD_BAUD_DIVFRAC_Msk                         ((uint32_t)0x0000003F)

/** @} */ /* End of group UART_FBRD */

/** @defgroup Periph_UART_LCR_H UART LCR_H
  * @{
  */

/*-- UART_LCR_H:UART LCR_H Register -----*/

/* Bit field positions: */
#define UART_LCR_H_BRK_Pos                                 0
#define UART_LCR_H_PEN_Pos                                 1
#define UART_LCR_H_EPS_Pos                                 2
#define UART_LCR_H_STP2_Pos                                3
#define UART_LCR_H_FEN_Pos                                 4
#define UART_LCR_H_WLEN_Pos                                5
#define UART_LCR_H_SPS_Pos                                 7

/* Bit field masks: */
#define UART_LCR_H_BRK                                     ((uint32_t)0x00000001)
#define UART_LCR_H_PEN                                     ((uint32_t)0x00000002)
#define UART_LCR_H_EPS                                     ((uint32_t)0x00000004)
#define UART_LCR_H_STP2                                    ((uint32_t)0x00000008)
#define UART_LCR_H_FEN                                     ((uint32_t)0x00000010)
#define UART_LCR_H_WLEN_Msk                                ((uint32_t)0x00000060)
#define UART_LCR_H_SPS                                     ((uint32_t)0x00000080)

/** @} */ /* End of group UART_LCR_H */

/** @defgroup Periph_UART_CR UART CR
  * @{
  */

/*-- UART_CR:UART CR Register -----*/

/* Bit field positions: */
#define UART_CR_UARTEN_Pos                                 0
#define UART_CR_SIREN_Pos                                  1
#define UART_CR_SIRLP_Pos                                  2
#define UART_CR_LBE_Pos                                    7
#define UART_CR_TXE_Pos                                    8
#define UART_CR_RXE_Pos                                    9
#define UART_CR_DTR_Pos                                    10
#define UART_CR_RTS_Pos                                    11
#define UART_CR_OUT1_Pos                                   12
#define UART_CR_OUT2_Pos                                   13
#define UART_CR_RTSEN_Pos                                  14
#define UART_CR_CTSEN_Pos                                  15

/* Bit field masks: */
#define UART_CR_UARTEN                                     ((uint32_t)0x00000001)
#define UART_CR_SIREN                                      ((uint32_t)0x00000002)
#define UART_CR_SIRLP                                      ((uint32_t)0x00000004)
#define UART_CR_LBE                                        ((uint32_t)0x00000080)
#define UART_CR_TXE                                        ((uint32_t)0x00000100)
#define UART_CR_RXE                                        ((uint32_t)0x00000200)
#define UART_CR_DTR                                        ((uint32_t)0x00000400)
#define UART_CR_RTS                                        ((uint32_t)0x00000800)
#define UART_CR_OUT1                                       ((uint32_t)0x00001000)
#define UART_CR_OUT2                                       ((uint32_t)0x00002000)
#define UART_CR_RTSEN                                      ((uint32_t)0x00004000)
#define UART_CR_CTSEN                                      ((uint32_t)0x00008000)

/** @} */ /* End of group UART_CR */

/** @defgroup Periph_UART_IFLS UART IFLS
  * @{
  */

/*-- UART_IFLS:UART IFLS Register -----*/

/* Bit field positions: */
#define UART_IFLS_TXIFLSEL_Pos                             0
#define UART_IFLS_RXIFLSEL_Pos                             3

/* Bit field masks: */
#define UART_IFLS_TXIFLSEL_Msk                             ((uint32_t)0x00000007)
#define UART_IFLS_RXIFLSEL_Msk                             ((uint32_t)0x00000038)

/** @} */ /* End of group UART_IFLS */

/** @defgroup Periph_UART_IMSC UART IMSC
  * @{
  */

/*-- UART_IMSC:UART IMSC Register -----*/

/* Bit field positions: */
#define UART_IMSC_RIMIM_Pos                                0
#define UART_IMSC_CTSMIM_Pos                               1
#define UART_IMSC_DCDMIM_Pos                               2
#define UART_IMSC_DSRMIM_Pos                               3
#define UART_IMSC_RXIM_Pos                                 4
#define UART_IMSC_TXIM_Pos                                 5
#define UART_IMSC_RTIM_Pos                                 6
#define UART_IMSC_FEIM_Pos                                 7
#define UART_IMSC_PEIM_Pos                                 8
#define UART_IMSC_BEIM_Pos                                 9
#define UART_IMSC_OEIM_Pos                                 10

/* Bit field masks: */
#define UART_IMSC_RIMIM                                    ((uint32_t)0x00000001)
#define UART_IMSC_CTSMIM                                   ((uint32_t)0x00000002)
#define UART_IMSC_DCDMIM                                   ((uint32_t)0x00000004)
#define UART_IMSC_DSRMIM                                   ((uint32_t)0x00000008)
#define UART_IMSC_RXIM                                     ((uint32_t)0x00000010)
#define UART_IMSC_TXIM                                     ((uint32_t)0x00000020)
#define UART_IMSC_RTIM                                     ((uint32_t)0x00000040)
#define UART_IMSC_FEIM                                     ((uint32_t)0x00000080)
#define UART_IMSC_PEIM                                     ((uint32_t)0x00000100)
#define UART_IMSC_BEIM                                     ((uint32_t)0x00000200)
#define UART_IMSC_OEIM                                     ((uint32_t)0x00000400)

/** @} */ /* End of group UART_IMSC */

/** @defgroup Periph_UART_RIS UART RIS
  * @{
  */

/*-- UART_RIS:UART RIS Register -----*/

/* Bit field positions: */
#define UART_RIS_RIRMIS_Pos                                0
#define UART_RIS_CTSRMIS_Pos                               1
#define UART_RIS_DCDRMIS_Pos                               2
#define UART_RIS_DSRRMIS_Pos                               3
#define UART_RIS_RXRIS_Pos                                 4
#define UART_RIS_TXRIS_Pos                                 5
#define UART_RIS_RTRIS_Pos                                 6
#define UART_RIS_FERIS_Pos                                 7
#define UART_RIS_PERIS_Pos                                 8
#define UART_RIS_BERIS_Pos                                 9
#define UART_RIS_OERIS_Pos                                 10

/* Bit field masks: */
#define UART_RIS_RIRMIS                                    ((uint32_t)0x00000001)
#define UART_RIS_CTSRMIS                                   ((uint32_t)0x00000002)
#define UART_RIS_DCDRMIS                                   ((uint32_t)0x00000004)
#define UART_RIS_DSRRMIS                                   ((uint32_t)0x00000008)
#define UART_RIS_RXRIS                                     ((uint32_t)0x00000010)
#define UART_RIS_TXRIS                                     ((uint32_t)0x00000020)
#define UART_RIS_RTRIS                                     ((uint32_t)0x00000040)
#define UART_RIS_FERIS                                     ((uint32_t)0x00000080)
#define UART_RIS_PERIS                                     ((uint32_t)0x00000100)
#define UART_RIS_BERIS                                     ((uint32_t)0x00000200)
#define UART_RIS_OERIS                                     ((uint32_t)0x00000400)

/** @} */ /* End of group UART_RIS */

/** @defgroup Periph_UART_MIS UART MIS
  * @{
  */

/*-- UART_MIS:UART MIS Register -----*/

/* Bit field positions: */
#define UART_MIS_RIMMIS_Pos                                0
#define UART_MIS_CTSMMIS_Pos                               1
#define UART_MIS_DCDMMIS_Pos                               2
#define UART_MIS_DSRMMIS_Pos                               3
#define UART_MIS_RXMIS_Pos                                 4
#define UART_MIS_TXMIS_Pos                                 5
#define UART_MIS_RTMIS_Pos                                 6
#define UART_MIS_FEMIS_Pos                                 7
#define UART_MIS_PEMIS_Pos                                 8
#define UART_MIS_BEMIS_Pos                                 9
#define UART_MIS_OEMIS_Pos                                 10

/* Bit field masks: */
#define UART_MIS_RIMMIS                                    ((uint32_t)0x00000001)
#define UART_MIS_CTSMMIS                                   ((uint32_t)0x00000002)
#define UART_MIS_DCDMMIS                                   ((uint32_t)0x00000004)
#define UART_MIS_DSRMMIS                                   ((uint32_t)0x00000008)
#define UART_MIS_RXMIS                                     ((uint32_t)0x00000010)
#define UART_MIS_TXMIS                                     ((uint32_t)0x00000020)
#define UART_MIS_RTMIS                                     ((uint32_t)0x00000040)
#define UART_MIS_FEMIS                                     ((uint32_t)0x00000080)
#define UART_MIS_PEMIS                                     ((uint32_t)0x00000100)
#define UART_MIS_BEMIS                                     ((uint32_t)0x00000200)
#define UART_MIS_OEMIS                                     ((uint32_t)0x00000400)

/** @} */ /* End of group UART_MIS */

/** @defgroup Periph_UART_ICR UART ICR
  * @{
  */

/*-- UART_ICR:UART ICR Register -----*/

/* Bit field positions: */
#define UART_ICR_RIMIC_Pos                                 0
#define UART_ICR_CTSMIC_Pos                                1
#define UART_ICR_DCDMIC_Pos                                2
#define UART_ICR_DSRMIC_Pos                                3
#define UART_ICR_RXIC_Pos                                  4
#define UART_ICR_TXIC_Pos                                  5
#define UART_ICR_RTIC_Pos                                  6
#define UART_ICR_FEIC_Pos                                  7
#define UART_ICR_PEIC_Pos                                  8
#define UART_ICR_BEIC_Pos                                  9
#define UART_ICR_OEIC_Pos                                  10

/* Bit field masks: */
#define UART_ICR_RIMIC                                     ((uint32_t)0x00000001)
#define UART_ICR_CTSMIC                                    ((uint32_t)0x00000002)
#define UART_ICR_DCDMIC                                    ((uint32_t)0x00000004)
#define UART_ICR_DSRMIC                                    ((uint32_t)0x00000008)
#define UART_ICR_RXIC                                      ((uint32_t)0x00000010)
#define UART_ICR_TXIC                                      ((uint32_t)0x00000020)
#define UART_ICR_RTIC                                      ((uint32_t)0x00000040)
#define UART_ICR_FEIC                                      ((uint32_t)0x00000080)
#define UART_ICR_PEIC                                      ((uint32_t)0x00000100)
#define UART_ICR_BEIC                                      ((uint32_t)0x00000200)
#define UART_ICR_OEIC                                      ((uint32_t)0x00000400)

/** @} */ /* End of group UART_ICR */

/** @} */ /* End of group UART */

/** @defgroup MDR32F23QI_Periph_EEPROM EEPROM
  * @{
  */

/* MDR_EEPROM_TypeDef structure */
typedef struct {
    __IO uint32_t   CMD;                    /*!<EEPROM Command Register */
    __IO uint32_t   ADR;                    /*!<EEPROM Address Register */
    __IO uint32_t   DI;                     /*!<EEPROM Read Data Register */
    __IO uint32_t   DO;                     /*!<EEPROM Write Data Register */
    __IO uint32_t   KEY;                    /*!<EEPROM Key Register */
}MDR_EEPROM_TypeDef;

/** @defgroup Periph_EEPROM_CMD EEPROM CMD
  * @{
  */

/*-- EEPROM_CMD:EEPROM CMD Register -----*/

/* Bit field positions: */
#define EEPROM_CMD_CON_Pos                                 0
#define EEPROM_CMD_DELAY_Pos                               3
#define EEPROM_CMD_XE_Pos                                  6
#define EEPROM_CMD_YE_Pos                                  7
#define EEPROM_CMD_SE_Pos                                  8
#define EEPROM_CMD_IFREN_Pos                               9
#define EEPROM_CMD_ERASE_Pos                               10
#define EEPROM_CMD_MAS1_Pos                                11
#define EEPROM_CMD_PROG_Pos                                12
#define EEPROM_CMD_NVSTR_Pos                               13

/* Bit field masks: */
#define EEPROM_CMD_CON                                     ((uint32_t)0x00000001)
#define EEPROM_CMD_DELAY_Msk                               ((uint32_t)0x00000038)
#define EEPROM_CMD_XE                                      ((uint32_t)0x00000040)
#define EEPROM_CMD_YE                                      ((uint32_t)0x00000080)
#define EEPROM_CMD_SE                                      ((uint32_t)0x00000100)
#define EEPROM_CMD_IFREN                                   ((uint32_t)0x00000200)
#define EEPROM_CMD_ERASE                                   ((uint32_t)0x00000400)
#define EEPROM_CMD_MAS1                                    ((uint32_t)0x00000800)
#define EEPROM_CMD_PROG                                    ((uint32_t)0x00001000)
#define EEPROM_CMD_NVSTR                                   ((uint32_t)0x00002000)

/** @} */ /* End of group EEPROM_CMD */

/** @defgroup Periph_EEPROM_ADR EEPROM ADR
  * @{
  */

/*-- EEPROM_ADR:EEPROM ADR Register -----*/

/* Bit field positions: */
#define EEPROM_ADR_ADR_Pos                                 0

/* Bit field masks: */
#define EEPROM_ADR_ADR_Msk                                 ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group EEPROM_ADR */

/** @defgroup Periph_EEPROM_DI EEPROM DI
  * @{
  */

/*-- EEPROM_DI:EEPROM DI Register -----*/

/* Bit field positions: */
#define EEPROM_DI_DATA_Pos                                 0

/* Bit field masks: */
#define EEPROM_DI_DATA_Msk                                 ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group EEPROM_DI */

/** @defgroup Periph_EEPROM_DO EEPROM DO
  * @{
  */

/*-- EEPROM_DO:EEPROM DO Register -----*/

/* Bit field positions: */
#define EEPROM_DO_DATA_Pos                                 0

/* Bit field masks: */
#define EEPROM_DO_DATA_Msk                                 ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group EEPROM_DO */

/** @defgroup Periph_EEPROM_KEY EEPROM KEY
  * @{
  */

/*-- EEPROM_KEY:EEPROM KEY Register -----*/

/* Bit field positions: */
#define EEPROM_KEY_KEY_Pos                                 0

/* Bit field masks: */
#define EEPROM_KEY_KEY_Msk                                 ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group EEPROM_KEY */

/** @} */ /* End of group EEPROM */


/** @defgroup MDR32F23QI_Periph_RST_CLK RST_CLK
  * @{
  */

/* MDR_RST_CLK_TypeDef structure */
typedef struct {
    __IO uint32_t   CLOCK_STATUS;           /*!<Clock Status Register */
    __IO uint32_t   PLL_CONTROL;            /*!<PLL Control Register */
    __IO uint32_t   HS_CONTROL;             /*!<HS Control Register */
    __IO uint32_t   CPU_CLOCK;              /*!<CPU Clock Register */
    __IO uint32_t   PER1_CLOCK;             /*!<PER1 Clock Register */
    __IO uint32_t   ADC_CLOCK;              /*!<ADC Clock Register */
    __IO uint32_t   RTC_CLOCK;              /*!<RTC Clock Register */
    __IO uint32_t   PER2_CLOCK;             /*!<Peripheral Clock Enable Register */
    __I  uint32_t   RESERVED0;
    __IO uint32_t   TIM_CLOCK;              /*!<Timer Clock Register */
    __IO uint32_t   UART_CLOCK;             /*!<UART Clock Register */
    __IO uint32_t   SSP_CLOCK;              /*!<SSP Clock Register */
}MDR_RST_CLK_TypeDef;

/** @defgroup Periph_RST_CLK_CLOCK_STATUS RST_CLK CLOCK_STATUS
  * @{
  */

/*-- RST_CLK_CLOCK_STATUS:RST_CLK CLOCK_STATUS Register -----*/

/* Bit field positions: */
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY_Pos               1
#define RST_CLK_CLOCK_STATUS_HSE_RDY_Pos                   2

/* Bit field masks: */
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY                   ((uint32_t)0x00000002)
#define RST_CLK_CLOCK_STATUS_HSE_RDY                       ((uint32_t)0x00000004)

/** @} */ /* End of group RST_CLK_CLOCK_STATUS */

/** @defgroup Periph_RST_CLK_PLL_CONTROL RST_CLK PLL_CONTROL
  * @{
  */

/*-- RST_CLK_PLL_CONTROL:RST_CLK PLL_CONTROL Register -----*/

/* Bit field positions: */
#define RST_CLK_PLL_CONTROL_PLL_CPU_ON_Pos                 2
#define RST_CLK_PLL_CONTROL_PLL_CPU_RLD_Pos                3
#define RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Pos                8

/* Bit field masks: */
#define RST_CLK_PLL_CONTROL_PLL_CPU_ON                     ((uint32_t)0x00000004)
#define RST_CLK_PLL_CONTROL_PLL_CPU_RLD                    ((uint32_t)0x00000008)
#define RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Msk                ((uint32_t)0x00000F00)

/** @} */ /* End of group RST_CLK_PLL_CONTROL */

/** @defgroup Periph_RST_CLK_HS_CONTROL RST_CLK HS_CONTROL
  * @{
  */

/*-- RST_CLK_HS_CONTROL:RST_CLK HS_CONTROL Register -----*/

/* Bit field positions: */
#define RST_CLK_HS_CONTROL_HSE_ON_Pos                      0
#define RST_CLK_HS_CONTROL_HSE_BYP_Pos                     1

/* Bit field masks: */
#define RST_CLK_HS_CONTROL_HSE_ON                          ((uint32_t)0x00000001)
#define RST_CLK_HS_CONTROL_HSE_BYP                         ((uint32_t)0x00000002)

/** @} */ /* End of group RST_CLK_HS_CONTROL */

/** @defgroup Periph_RST_CLK_CPU_CLOCK RST_CLK CPU_CLOCK
  * @{
  */

/*-- RST_CLK_CPU_CLOCK:RST_CLK CPU_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_Pos                   0
#define RST_CLK_CPU_CLOCK_CPU_C2_SEL_Pos                   2
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_Pos                   4
#define RST_CLK_CPU_CLOCK_HCLK_SEL_Pos                     8

/* Bit field masks: */
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_Msk                   ((uint32_t)0x00000003)
#define RST_CLK_CPU_CLOCK_CPU_C2_SEL                       ((uint32_t)0x00000004)
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_Msk                   ((uint32_t)0x000000F0)
#define RST_CLK_CPU_CLOCK_HCLK_SEL_Msk                     ((uint32_t)0x00000300)

/** @} */ /* End of group RST_CLK_CPU_CLOCK */

/** @defgroup Periph_RST_CLK_PER1_CLOCK RST_CLK PER1_CLOCK
  * @{
  */

/*-- RST_CLK_PER1_CLOCK:RST_CLK PER1_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_PER1_CLOCK_C1_SEL_Pos                           0
#define RST_CLK_PER1_CLOCK_TIM0_C2_SEL_Pos                      2
#define RST_CLK_PER1_CLOCK_DEBUG_EN_Pos                         4
#define RST_CLK_PER1_CLOCK_TIM1_C2_SEL_Pos                      6
#define RST_CLK_PER1_CLOCK_UART0_C2_SEL_Pos                     8
#define RST_CLK_PER1_CLOCK_UART1_C2_SEL_Pos                     10
#define RST_CLK_PER1_CLOCK_SSP_C2_SEL_Pos                       12

/* Bit field masks: */
#define RST_CLK_PER1_CLOCK_C1_SEL_Msk                           ((uint32_t)0x00000003)
#define RST_CLK_PER1_CLOCK_TIM0_C2_SEL_Msk                      ((uint32_t)0x0000000C)
#define RST_CLK_PER1_CLOCK_DEBUG_EN                             ((uint32_t)0x00000010)
#define RST_CLK_PER1_CLOCK_TIM1_C2_SEL_Msk                      ((uint32_t)0x000000C0)
#define RST_CLK_PER1_CLOCK_UART0_C2_SEL_Msk                     ((uint32_t)0x00000300)
#define RST_CLK_PER1_CLOCK_UART1_C2_SEL_Msk                     ((uint32_t)0x00000C00)
#define RST_CLK_PER1_CLOCK_SSP_C2_SEL_Msk                       ((uint32_t)0x00003000)

/** @} */ /* End of group RST_CLK_PER1_CLOCK */

/** @defgroup Periph_RST_CLK_ADC_CLOCK RST_CLK ADC_CLOCK
  * @{
  */

/*-- RST_CLK_ADC_CLOCK:RST_CLK ADC_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_ADC_CLOCK_ADC_C1_SEL_Pos               0
#define RST_CLK_ADC_CLOCK_ADCIU_C1_SEL_Pos             2
#define RST_CLK_ADC_CLOCK_ADCIU_C3_SEL_Pos             4
#define RST_CLK_ADC_CLOCK_ADC_C3_SEL_Pos               8
#define RST_CLK_ADC_CLOCK_ADCIU_CLK_EN_Pos             12
#define RST_CLK_ADC_CLOCK_ADC_CLK_EN_Pos               13

/* Bit field masks: */
#define RST_CLK_ADC_CLOCK_ADC_C1_SEL_Msk               ((uint32_t)0x00000003)
#define RST_CLK_ADC_CLOCK_ADCIU_C1_SEL_Msk             ((uint32_t)0x0000000C)
#define RST_CLK_ADC_CLOCK_ADCIU_C3_SEL_Msk             ((uint32_t)0x000000F0)
#define RST_CLK_ADC_CLOCK_ADC_C3_SEL_Msk               ((uint32_t)0x00000F00)
#define RST_CLK_ADC_CLOCK_ADCIU_CLK_EN                 ((uint32_t)0x00001000)
#define RST_CLK_ADC_CLOCK_ADC_CLK_EN                   ((uint32_t)0x00002000)

/** @} */ /* End of group RST_CLK_ADC_CLOCK */

/** @defgroup Periph_RST_CLK_RTC_CLOCK RST_CLK RTC_CLOCK
  * @{
  */

/*-- RST_CLK_RTC_CLOCK:RST_CLK RTC_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_RTC_CLOCK_HSE_SEL_Pos                      0
#define RST_CLK_RTC_CLOCK_HSI_SEL_Pos                      4
#define RST_CLK_RTC_CLOCK_HSE_RTC_EN_Pos                   8
#define RST_CLK_RTC_CLOCK_HSI_RTC_EN_Pos                   9

/* Bit field masks: */
#define RST_CLK_RTC_CLOCK_HSE_SEL_Msk                      ((uint32_t)0x0000000F)
#define RST_CLK_RTC_CLOCK_HSI_SEL_Msk                      ((uint32_t)0x000000F0)
#define RST_CLK_RTC_CLOCK_HSE_RTC_EN                       ((uint32_t)0x00000100)
#define RST_CLK_RTC_CLOCK_HSI_RTC_EN                       ((uint32_t)0x00000200)

/** @} */ /* End of group RST_CLK_RTC_CLOCK */

/** @defgroup Periph_RST_CLK_PER2_CLOCK RST_CLK PER2_CLOCK
  * @{
  */

/*-- RST_CLK_PER2_CLOCK:RST_CLK PER2_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_PER2_CLOCK_PCLK_EN_SPI_Pos                 0
#define RST_CLK_PER2_CLOCK_PCLK_EN_UART0_Pos               1
#define RST_CLK_PER2_CLOCK_PCLK_EN_UART1_Pos               2
#define RST_CLK_PER2_CLOCK_PCLK_EN_EEPROM_Pos              3
#define RST_CLK_PER2_CLOCK_PCLK_EN_RST_CLK_Pos             4
#define RST_CLK_PER2_CLOCK_PCLK_EN_I2C_Pos                 6
#define RST_CLK_PER2_CLOCK_PCLK_EN_LCD_Pos                 7
#define RST_CLK_PER2_CLOCK_PCLK_EN_ADC_Pos                 8
#define RST_CLK_PER2_CLOCK_PCLK_EN_WWDT_Pos                9
#define RST_CLK_PER2_CLOCK_PCLK_EN_IWDT_Pos                10
#define RST_CLK_PER2_CLOCK_PCLK_EN_POWER_Pos               11
#define RST_CLK_PER2_CLOCK_PCLK_EN_BKP_Pos                 12
#define RST_CLK_PER2_CLOCK_PCLK_EN_ADCIU_Pos               13
#define RST_CLK_PER2_CLOCK_PCLK_EN_TIMER0_Pos              14
#define RST_CLK_PER2_CLOCK_PCLK_EN_TIMER1_Pos              15
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTA_Pos               16
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTB_Pos               17
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTC_Pos               18

/* Bit field masks: */
#define RST_CLK_PER2_CLOCK_PCLK_EN_SPI                     ((uint32_t)0x00000001)
#define RST_CLK_PER2_CLOCK_PCLK_EN_UART0                   ((uint32_t)0x00000002)
#define RST_CLK_PER2_CLOCK_PCLK_EN_UART1                   ((uint32_t)0x00000004)
#define RST_CLK_PER2_CLOCK_PCLK_EN_EEPROM                  ((uint32_t)0x00000008)
#define RST_CLK_PER2_CLOCK_PCLK_EN_RST_CLK                 ((uint32_t)0x00000010)
#define RST_CLK_PER2_CLOCK_PCLK_EN_I2C                     ((uint32_t)0x00000040)
#define RST_CLK_PER2_CLOCK_PCLK_EN_LCD                     ((uint32_t)0x00000080)
#define RST_CLK_PER2_CLOCK_PCLK_EN_ADC                     ((uint32_t)0x00000100)
#define RST_CLK_PER2_CLOCK_PCLK_EN_WWDT                    ((uint32_t)0x00000200)
#define RST_CLK_PER2_CLOCK_PCLK_EN_IWDT                    ((uint32_t)0x00000400)
#define RST_CLK_PER2_CLOCK_PCLK_EN_POWER                   ((uint32_t)0x00000800)
#define RST_CLK_PER2_CLOCK_PCLK_EN_BKP                     ((uint32_t)0x00001000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_ADCIU                   ((uint32_t)0x00002000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_TIMER0                  ((uint32_t)0x00004000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_TIMER1                  ((uint32_t)0x00008000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTA                   ((uint32_t)0x00010000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTB                   ((uint32_t)0x00020000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTC                   ((uint32_t)0x00040000)

/** @} */ /* End of group RST_CLK_PER2_CLOCK */

/** @defgroup Periph_RST_CLK_TIM_CLOCK RST_CLK TIM_CLOCK
  * @{
  */

/*-- RST_CLK_TIM_CLOCK:RST_CLK TIM_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_TIM_CLOCK_TIM0_BRG_Pos                     0
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Pos                     8
#define RST_CLK_TIM_CLOCK_TIM0_CLK_EN_Pos                  24
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN_Pos                  25

/* Bit field masks: */
#define RST_CLK_TIM_CLOCK_TIM0_BRG_Msk                     ((uint32_t)0x000000FF)
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Msk                     ((uint32_t)0x0000FF00)
#define RST_CLK_TIM_CLOCK_TIM0_CLK_EN                      ((uint32_t)0x01000000)
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN                      ((uint32_t)0x02000000)

/** @} */ /* End of group RST_CLK_TIM_CLOCK */

/** @defgroup Periph_RST_CLK_UART_CLOCK RST_CLK UART_CLOCK
  * @{
  */

/*-- RST_CLK_UART_CLOCK:RST_CLK UART_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_UART_CLOCK_UART0_BRG_Pos                   0
#define RST_CLK_UART_CLOCK_UART1_BRG_Pos                   8
#define RST_CLK_UART_CLOCK_UART0_CLK_EN_Pos                24
#define RST_CLK_UART_CLOCK_UART1_CLK_EN_Pos                25

/* Bit field masks: */
#define RST_CLK_UART_CLOCK_UART0_BRG_Msk                   ((uint32_t)0x000000FF)
#define RST_CLK_UART_CLOCK_UART1_BRG_Msk                   ((uint32_t)0x0000FF00)
#define RST_CLK_UART_CLOCK_UART0_CLK_EN                    ((uint32_t)0x01000000)
#define RST_CLK_UART_CLOCK_UART1_CLK_EN                    ((uint32_t)0x02000000)

/** @} */ /* End of group RST_CLK_UART_CLOCK */

/** @defgroup Periph_RST_CLK_SSP_CLOCK RST_CLK SSP_CLOCK
  * @{
  */

/*-- RST_CLK_SSP_CLOCK:RST_CLK SSP_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Pos                     0
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN_Pos                  24

/* Bit field masks: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Msk                     ((uint32_t)0x000000FF)
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN                      ((uint32_t)0x01000000)

/** @} */ /* End of group RST_CLK_SSP_CLOCK */

/** @} */ /* End of group RST_CLK */

/** @defgroup MDR32F23QI_Periph_ADC ADC
  * @{
  */

/* MDR_ADC_TypeDef structure */
typedef struct {
    __IO uint32_t   ADC1_CFG;               /*!<ADC1 Configuration Register */
    __IO uint32_t   ADC2_CFG;               /*!<ADC2 Configuration Register */
    __IO uint32_t   ADC1_H_LEVEL;           /*!<ADC1 High Level Register */
    __I  uint32_t   RESERVED0;
    __IO uint32_t   ADC1_L_LEVEL;           /*!<ADC1 Low Level Register */
    __I  uint32_t   RESERVED1;
    __IO uint32_t   ADC1_RESULT;            /*!<ADC1 Result Register */
    __I  uint32_t   RESERVED2;
    __IO uint32_t   ADC1_STATUS;            /*!<ADC1 Status Register */
    __I  uint32_t   RESERVED3;
    __IO uint32_t   ADC1_CHSEL;             /*!<ADC1 Channel Selector Register */
    __I  uint32_t   RESERVED4;
    __IO uint32_t   ADC1_TRIM;              /*!< */
}MDR_ADC_TypeDef;

/** @defgroup Periph_ADC1_CFG  ADC1_CFG
  * @{
  */

/*-- ADC1_CFG: ADC1_CFG Register -----*/

/* Bit field positions: */
#define ADC1_CFG_REG_ADON_Pos                              0
#define ADC1_CFG_REG_GO_Pos                                1
#define ADC1_CFG_REG_CLKS_Pos                              2
#define ADC1_CFG_REG_SAMPLE_Pos                            3
#define ADC1_CFG_REG_CHS_Pos                               4
#define ADC1_CFG_REG_CHCH_Pos                              9
#define ADC1_CFG_REG_RNGC_Pos                              10
#define ADC1_CFG_M_REF_Pos                                 11
#define ADC1_CFG_REG_DIVCLK_Pos                            12
#define ADC1_CFG_SYNC_CONVER_Pos                           16
#define ADC1_CFG_TS_EN_Pos                                 17
#define ADC1_CFG_TS_BUF_EN_Pos                             18
#define ADC1_CFG_SEL_TS_Pos                                19
#define ADC1_CFG_SEL_VREF_Pos                              20
#define ADC1_CFG_TR_Pos                                    21
#define ADC1_CFG_DELAY_GO_Pos                              25
#define ADC1_CFG_DELAY_ADC_Pos                             28

/* Bit field masks: */
#define ADC1_CFG_REG_ADON                                  ((uint32_t)0x00000001)
#define ADC1_CFG_REG_GO                                    ((uint32_t)0x00000002)
#define ADC1_CFG_REG_CLKS                                  ((uint32_t)0x00000004)
#define ADC1_CFG_REG_SAMPLE                                ((uint32_t)0x00000008)
#define ADC1_CFG_REG_CHS_Msk                               ((uint32_t)0x000001F0)
#define ADC1_CFG_REG_CHCH                                  ((uint32_t)0x00000200)
#define ADC1_CFG_REG_RNGC                                  ((uint32_t)0x00000400)
#define ADC1_CFG_M_REF                                     ((uint32_t)0x00000800)
#define ADC1_CFG_REG_DIVCLK_Msk                            ((uint32_t)0x0000F000)
#define ADC1_CFG_SYNC_CONVER                               ((uint32_t)0x00010000)
#define ADC1_CFG_TS_EN                                     ((uint32_t)0x00020000)
#define ADC1_CFG_TS_BUF_EN                                 ((uint32_t)0x00040000)
#define ADC1_CFG_SEL_TS                                    ((uint32_t)0x00080000)
#define ADC1_CFG_SEL_VREF                                  ((uint32_t)0x00100000)
#define ADC1_CFG_TR_Msk                                    ((uint32_t)0x01E00000)
#define ADC1_CFG_DELAY_GO_Msk                              ((uint32_t)0x0E000000)
#define ADC1_CFG_DELAY_ADC_Msk                             ((uint32_t)0xF0000000)

/** @} */ /* End of group ADC1_CFG */

/** @defgroup Periph_ADC2_CFG  ADC2_CFG
  * @{
  */

/*-- ADC2_CFG: ADC2_CFG Register -----*/

/* Bit field positions: */
#define ADC2_CFG_ADC1_OP_Pos                               17

/* Bit field masks: */
#define ADC2_CFG_ADC1_OP                                   ((uint32_t)0x00020000)

/** @} */ /* End of group ADC2_CFG */

/** @defgroup Periph_ADC1_H_LEVEL  ADC1_H_LEVEL
  * @{
  */

/*-- ADC1_H_LEVEL: ADC1_H_LEVEL Register -----*/

/* Bit field positions: */
#define ADC1_H_LEVEL_REG_H_LEVEL_Pos                       0

/* Bit field masks: */
#define ADC1_H_LEVEL_REG_H_LEVEL_Msk                       ((uint32_t)0x00000FFF)

/** @} */ /* End of group ADC1_H_LEVEL */

/** @defgroup Periph_ADC1_L_LEVEL  ADC1_L_LEVEL
  * @{
  */

/*-- ADC1_L_LEVEL: ADC1_L_LEVEL Register -----*/

/* Bit field positions: */
#define ADC1_L_LEVEL_REG_L_LEVEL_Pos                       0

/* Bit field masks: */
#define ADC1_L_LEVEL_REG_L_LEVEL_Msk                       ((uint32_t)0x00000FFF)

/** @} */ /* End of group ADC1_L_LEVEL */

/** @defgroup Periph_ADC1_RESULT  ADC1_RESULT
  * @{
  */

/*-- ADC1_RESULT: ADC1_RESULT Register -----*/

/* Bit field positions: */
#define ADC1_RESULT_RESULT_Pos                             0
#define ADC1_RESULT_CHANNEL_Pos                            16

/* Bit field masks: */
#define ADC1_RESULT_RESULT_Msk                             ((uint32_t)0x00000FFF)
#define ADC1_RESULT_CHANNEL_Msk                            ((uint32_t)0x0FFF0000)

/** @} */ /* End of group ADC1_RESULT */

/** @defgroup Periph_ADC1_STATUS  ADC1_STATUS
  * @{
  */

/*-- ADC1_STATUS: ADC1_STATUS Register -----*/

/* Bit field positions: */
#define ADC1_STATUS_FLG_REG_OVERWRITE_Pos                  0
#define ADC1_STATUS_FLG_REG_AWOIFEN_Pos                    1
#define ADC1_STATUS_FLG_REG_EOCIF_Pos                      2
#define ADC1_STATUS_AWOIF_IE_Pos                           3
#define ADC1_STATUS_ECOIF_IE_Pos                           4

/* Bit field masks: */
#define ADC1_STATUS_FLG_REG_OVERWRITE                      ((uint32_t)0x00000001)
#define ADC1_STATUS_FLG_REG_AWOIFEN                        ((uint32_t)0x00000002)
#define ADC1_STATUS_FLG_REG_EOCIF                          ((uint32_t)0x00000004)
#define ADC1_STATUS_AWOIF_IE                               ((uint32_t)0x00000008)
#define ADC1_STATUS_ECOIF_IE                               ((uint32_t)0x00000010)

/** @} */ /* End of group ADC1_STATUS */

/** @defgroup Periph_ADC1_CHSEL  ADC1_CHSEL
  * @{
  */

/*-- ADC1_CHSEL: ADC1_CHSEL Register -----*/

/* Bit field positions: */
#define ADC1_CHSEL_SL_CH_CH_REF0_Pos                       0
#define ADC1_CHSEL_SL_CH_CH_REF1_Pos                       1
#define ADC1_CHSEL_SL_CH_CH_REF2_Pos                       2
#define ADC1_CHSEL_SL_CH_CH_REF3_Pos                       3
#define ADC1_CHSEL_SL_CH_CH_REF4_Pos                       4
#define ADC1_CHSEL_SL_CH_CH_REF5_Pos                       5
#define ADC1_CHSEL_SL_CH_CH_REF6_Pos                       6
#define ADC1_CHSEL_SL_CH_CH_REF7_Pos                       7
#define ADC1_CHSEL_SL_CH_CH_REF8_Pos                       8
#define ADC1_CHSEL_SL_CH_CH_REF9_Pos                       9
#define ADC1_CHSEL_SL_CH_CH_REF10_Pos                      10
#define ADC1_CHSEL_SL_CH_CH_REF11_Pos                      11
#define ADC1_CHSEL_SL_CH_CH_REF12_Pos                      12
#define ADC1_CHSEL_SL_CH_CH_REF13_Pos                      13
#define ADC1_CHSEL_SL_CH_CH_REF14_Pos                      14
#define ADC1_CHSEL_SL_CH_CH_REF15_Pos                      15
#define ADC1_CHSEL_SL_CH_CH_REF16_Pos                      16
#define ADC1_CHSEL_SL_CH_CH_REF17_Pos                      17
#define ADC1_CHSEL_SL_CH_CH_REF18_Pos                      18
#define ADC1_CHSEL_SL_CH_CH_REF19_Pos                      19
#define ADC1_CHSEL_SL_CH_CH_REF20_Pos                      20
#define ADC1_CHSEL_SL_CH_CH_REF21_Pos                      21
#define ADC1_CHSEL_SL_CH_CH_REF22_Pos                      22
#define ADC1_CHSEL_SL_CH_CH_REF23_Pos                      23
#define ADC1_CHSEL_SL_CH_CH_REF24_Pos                      24
#define ADC1_CHSEL_SL_CH_CH_REF25_Pos                      25
#define ADC1_CHSEL_SL_CH_CH_REF26_Pos                      26
#define ADC1_CHSEL_SL_CH_CH_REF27_Pos                      27
#define ADC1_CHSEL_SL_CH_CH_REF28_Pos                      28
#define ADC1_CHSEL_SL_CH_CH_REF29_Pos                      29
#define ADC1_CHSEL_SL_CH_CH_REF30_Pos                      30
#define ADC1_CHSEL_SL_CH_CH_REF31_Pos                      31

/* Bit field masks: */
#define ADC1_CHSEL_SL_CH_CH_REF0                           ((uint32_t)0x00000001)
#define ADC1_CHSEL_SL_CH_CH_REF1                           ((uint32_t)0x00000002)
#define ADC1_CHSEL_SL_CH_CH_REF2                           ((uint32_t)0x00000004)
#define ADC1_CHSEL_SL_CH_CH_REF3                           ((uint32_t)0x00000008)
#define ADC1_CHSEL_SL_CH_CH_REF4                           ((uint32_t)0x00000010)
#define ADC1_CHSEL_SL_CH_CH_REF5                           ((uint32_t)0x00000020)
#define ADC1_CHSEL_SL_CH_CH_REF6                           ((uint32_t)0x00000040)
#define ADC1_CHSEL_SL_CH_CH_REF7                           ((uint32_t)0x00000080)
#define ADC1_CHSEL_SL_CH_CH_REF8                           ((uint32_t)0x00000100)
#define ADC1_CHSEL_SL_CH_CH_REF9                           ((uint32_t)0x00000200)
#define ADC1_CHSEL_SL_CH_CH_REF10                          ((uint32_t)0x00000400)
#define ADC1_CHSEL_SL_CH_CH_REF11                          ((uint32_t)0x00000800)
#define ADC1_CHSEL_SL_CH_CH_REF12                          ((uint32_t)0x00001000)
#define ADC1_CHSEL_SL_CH_CH_REF13                          ((uint32_t)0x00002000)
#define ADC1_CHSEL_SL_CH_CH_REF14                          ((uint32_t)0x00004000)
#define ADC1_CHSEL_SL_CH_CH_REF15                          ((uint32_t)0x00008000)
#define ADC1_CHSEL_SL_CH_CH_REF16                          ((uint32_t)0x00010000)
#define ADC1_CHSEL_SL_CH_CH_REF17                          ((uint32_t)0x00020000)
#define ADC1_CHSEL_SL_CH_CH_REF18                          ((uint32_t)0x00040000)
#define ADC1_CHSEL_SL_CH_CH_REF19                          ((uint32_t)0x00080000)
#define ADC1_CHSEL_SL_CH_CH_REF20                          ((uint32_t)0x00100000)
#define ADC1_CHSEL_SL_CH_CH_REF21                          ((uint32_t)0x00200000)
#define ADC1_CHSEL_SL_CH_CH_REF22                          ((uint32_t)0x00400000)
#define ADC1_CHSEL_SL_CH_CH_REF23                          ((uint32_t)0x00800000)
#define ADC1_CHSEL_SL_CH_CH_REF24                          ((uint32_t)0x01000000)
#define ADC1_CHSEL_SL_CH_CH_REF25                          ((uint32_t)0x02000000)
#define ADC1_CHSEL_SL_CH_CH_REF26                          ((uint32_t)0x04000000)
#define ADC1_CHSEL_SL_CH_CH_REF27                          ((uint32_t)0x08000000)
#define ADC1_CHSEL_SL_CH_CH_REF28                          ((uint32_t)0x10000000)
#define ADC1_CHSEL_SL_CH_CH_REF29                          ((uint32_t)0x20000000)
#define ADC1_CHSEL_SL_CH_CH_REF30                          ((uint32_t)0x40000000)
#define ADC1_CHSEL_SL_CH_CH_REF31                          ((uint32_t)0x80000000)

/** @} */ /* End of group ADC1_CHSEL */

/** @defgroup Periph_ADC1_TRIM  ADC1_TRIM
  * @{
  */

/*-- ADC1_TRIM: ADC1_TRIM Register -----*/

/* Bit field positions: */
#define ADC1_TRIM_TS_TRIM_Pos                              1
#define ADC1_TRIM_SEL_VREF_BUF_Pos                         6

/* Bit field masks: */
#define ADC1_TRIM_TS_TRIM_Msk                              ((uint32_t)0x0000003E)
#define ADC1_TRIM_SEL_VREF_BUF                             ((uint32_t)0x00000040)

/** @} */ /* End of group ADC1_TRIM */

/** @} */ /* End of group ADC */

/** @defgroup MDR32F23QI_Periph_WWDG WWDG
  * @{
  */


/* MDR_WWDG_TypeDef structure */
typedef struct {
    __IO uint32_t   CR;                     /*!<WWDG Command Register */
    __IO uint32_t   CFR;                    /*!<WWDG Configuration Register */
    __IO uint32_t   SR;                     /*!<WWDG Status Register */
}MDR_WWDG_TypeDef;

/** @defgroup Periph_WWDG_CR WWDG CR
  * @{
  */

/*-- WWDG_CR:WWDG CR Register -----*/

/* Bit field positions: */
#define WWDG_CR_T_Pos                                      0
#define WWDG_CR_WDGA_Pos                                   7

/* Bit field masks: */
#define WWDG_CR_T_Msk                                      ((uint32_t)0x0000007F)
#define WWDG_CR_WDGA                                       ((uint32_t)0x00000080)

/** @} */ /* End of group WWDG_CR */

/** @defgroup Periph_WWDG_CFR WWDG CFR
  * @{
  */

/*-- WWDG_CFR:WWDG CFR Register -----*/

/* Bit field positions: */
#define WWDG_CFR_W_Pos                                     0
#define WWDG_CFR_WGTB_Pos                                  7
#define WWDG_CFR_EWI_Pos                                   9

/* Bit field masks: */
#define WWDG_CFR_W_Msk                                     ((uint32_t)0x0000007F)
#define WWDG_CFR_WGTB_Msk                                  ((uint32_t)0x00000180)
#define WWDG_CFR_EWI                                       ((uint32_t)0x00000200)

/** @} */ /* End of group WWDG_CFR */

/** @defgroup Periph_WWDG_SR WWDG SR
  * @{
  */

/*-- WWDG_SR:WWDG SR Register -----*/

/* Bit field positions: */
#define WWDG_SR_EWIF_Pos                                   0

/* Bit field masks: */
#define WWDG_SR_EWIF                                       ((uint32_t)0x00000001)

/** @} */ /* End of group WWDG_SR */

/** @} */ /* End of group WWDG */

/** @defgroup MDR32F23QI_Periph_IWDG IWDG
  * @{
  */


/* MDR_IWDG_TypeDef structure */
typedef struct {
    __IO uint32_t   KR;                     /*!<IWDG Key Register */
    __IO uint32_t   PR;                     /*!<IWDG Clock Prescaler Register */
    __IO uint32_t   RLR;                    /*!<IWDG Reload Register */
    __IO uint32_t   SR;                     /*!<IWDG Status Register */
}MDR_IWDG_TypeDef;

/** @defgroup Periph_IWDG_KR IWDG KR
  * @{
  */

/*-- IWDG_KR:IWDG KR Register -----*/

/* Bit field positions: */
#define IWDG_KR_KEY_Pos                                    0

/* Bit field masks: */
#define IWDG_KR_KEY_Msk                                    ((uint32_t)0x0000FFFF)

/** @} */ /* End of group IWDG_KR */

/** @defgroup Periph_IWDG_PR IWDG PR
  * @{
  */

/*-- IWDG_PR:IWDG PR Register -----*/

/* Bit field positions: */
#define IWDG_PR_PR_Pos                                     0

/* Bit field masks: */
#define IWDG_PR_PR_Msk                                     ((uint32_t)0x00000007)

/** @} */ /* End of group IWDG_PR */

/** @defgroup Periph_IWDG_RLR IWDG RLR
  * @{
  */

/*-- IWDG_RLR:IWDG RLR Register -----*/

/* Bit field positions: */
#define IWDG_RLR_RLR_Pos                                   0

/* Bit field masks: */
#define IWDG_RLR_RLR_Msk                                   ((uint32_t)0x00000FFF)

/** @} */ /* End of group IWDG_RLR */

/** @defgroup Periph_IWDG_SR IWDG SR
  * @{
  */

/*-- IWDG_SR:IWDG SR Register -----*/

/* Bit field positions: */
#define IWDG_SR_PVU_Pos                                    0
#define IWDG_SR_RVU_Pos                                    1

/* Bit field masks: */
#define IWDG_SR_PVU                                        ((uint32_t)0x00000001)
#define IWDG_SR_RVU                                        ((uint32_t)0x00000002)

/** @} */ /* End of group IWDG_SR */

/** @} */ /* End of group IWDG */

/** @defgroup MDR32F23QI_Periph_POWER POWER
  * @{
  */


/* MDR_POWER_TypeDef structure */
typedef struct {
    __IO uint32_t   PVDCS;                  /*!<POWER Power Detector Control/Status Register */
}MDR_POWER_TypeDef;

/** @defgroup Periph_POWER_PVDCS POWER PVDCS
  * @{
  */

/*-- POWER_PVDCS:POWER PVDCS Register -----*/

/* Bit field positions: */
#define POWER_PVDCS_PVDEN_Pos                              0
#define POWER_PVDCS_PBLS_Pos                               1
#define POWER_PVDCS_PLS_Pos                                3
#define POWER_PVDCS_PVBD_Pos                               6
#define POWER_PVDCS_PVD_Pos                                7
#define POWER_PVDCS_IEPVBD_Pos                             8
#define POWER_PVDCS_IEPVD_Pos                              9
#define POWER_PVDCS_INVB_Pos                               10
#define POWER_PVDCS_INV_Pos                                11
#define POWER_PVDCS_PVDBEN_Pos                             12

/* Bit field masks: */
#define POWER_PVDCS_PVDEN                                  ((uint32_t)0x00000001)
#define POWER_PVDCS_PBLS_Msk                               ((uint32_t)0x00000006)
#define POWER_PVDCS_PLS_Msk                                ((uint32_t)0x00000038)
#define POWER_PVDCS_PVBD                                   ((uint32_t)0x00000040)
#define POWER_PVDCS_PVD                                    ((uint32_t)0x00000080)
#define POWER_PVDCS_IEPVBD                                 ((uint32_t)0x00000100)
#define POWER_PVDCS_IEPVD                                  ((uint32_t)0x00000200)
#define POWER_PVDCS_INVB                                   ((uint32_t)0x00000400)
#define POWER_PVDCS_INV                                    ((uint32_t)0x00000800)
#define POWER_PVDCS_PVDBEN                                 ((uint32_t)0x00001000)

/** @} */ /* End of group POWER_PVDCS */

/** @} */ /* End of group POWER */

/** @defgroup MDR32F23QI_Periph_BKP BKP
  * @{
  */


/* MDR_BKP_TypeDef structure */
typedef struct {
    __IO uint32_t   REG_00;                 /*!<Backup Register 0 */
    __IO uint32_t   REG_01;                 /*!<Backup Register 1 */
    __IO uint32_t   REG_02;                 /*!<Backup Register 2 */
    __IO uint32_t   REG_03;                 /*!<Backup Register 3 */
    __IO uint32_t   REG_04;                 /*!<Backup Register 4 */
    __IO uint32_t   REG_05;                 /*!<Backup Register 5 */
    __IO uint32_t   REG_06;                 /*!<Backup Register 6 */
    __IO uint32_t   REG_07;                 /*!<Backup Register 7 */
    __IO uint32_t   REG_08;                 /*!<Backup Register 8 */
    __IO uint32_t   REG_09;                 /*!<Backup Register 9 */
    __IO uint32_t   REG_0A;                 /*!<Backup Register 10 */
    __IO uint32_t   REG_0B;                 /*!<Backup Register 11 */
    __IO uint32_t   REG_0C;                 /*!<Backup Register 12 */
    __IO uint32_t   REG_0D;                 /*!<Backup Register 13 */
    __IO uint32_t   REG_0E;                 /*!<Backup Register 14 */
    __IO uint32_t   REG_0F;                 /*!<Backup Register 15 */
    __IO uint32_t   RTC_CNT;                /*!<Realtime Clock Counter Register */
    __IO uint32_t   RTC_DIV;                /*!<Realtime Prescaler Counter Register */
    __IO uint32_t   RTC_PRL;                /*!<Realtime Prescaler Auto-Reload Value Register */
    __IO uint32_t   RTC_ALRM;               /*!<Realtime Alarm Register */
    __IO uint32_t   RTC_CS;                 /*!<Backup Realtime clock Register */
}MDR_BKP_TypeDef;

/** @defgroup Periph_BKP_REG_00 BKP REG_00
  * @{
  */

/*-- BKP_REG_00:BKP REG_00 Register -----*/

/* Bit field positions: */
#define BKP_REG_00_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_00_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_00 */

/** @defgroup Periph_BKP_REG_01 BKP REG_01
  * @{
  */

/*-- BKP_REG_01:BKP REG_01 Register -----*/

/* Bit field positions: */
#define BKP_REG_01_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_01_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_01 */

/** @defgroup Periph_BKP_REG_02 BKP REG_02
  * @{
  */

/*-- BKP_REG_02:BKP REG_02 Register -----*/

/* Bit field positions: */
#define BKP_REG_02_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_02_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_02 */

/** @defgroup Periph_BKP_REG_03 BKP REG_03
  * @{
  */

/*-- BKP_REG_03:BKP REG_03 Register -----*/

/* Bit field positions: */
#define BKP_REG_03_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_03_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_03 */

/** @defgroup Periph_BKP_REG_04 BKP REG_04
  * @{
  */

/*-- BKP_REG_04:BKP REG_04 Register -----*/

/* Bit field positions: */
#define BKP_REG_04_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_04_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_04 */

/** @defgroup Periph_BKP_REG_05 BKP REG_05
  * @{
  */

/*-- BKP_REG_05:BKP REG_05 Register -----*/

/* Bit field positions: */
#define BKP_REG_05_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_05_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_05 */

/** @defgroup Periph_BKP_REG_06 BKP REG_06
  * @{
  */

/*-- BKP_REG_06:BKP REG_06 Register -----*/

/* Bit field positions: */
#define BKP_REG_06_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_06_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_06 */

/** @defgroup Periph_BKP_REG_07 BKP REG_07
  * @{
  */

/*-- BKP_REG_07:BKP REG_07 Register -----*/

/* Bit field positions: */
#define BKP_REG_07_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_07_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_07 */

/** @defgroup Periph_BKP_REG_08 BKP REG_08
  * @{
  */

/*-- BKP_REG_08:BKP REG_08 Register -----*/

/* Bit field positions: */
#define BKP_REG_08_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_08_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_08 */

/** @defgroup Periph_BKP_REG_09 BKP REG_09
  * @{
  */

/*-- BKP_REG_09:BKP REG_09 Register -----*/

/* Bit field positions: */
#define BKP_REG_09_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_09_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_09 */

/** @defgroup Periph_BKP_REG_0A BKP REG_0A
  * @{
  */

/*-- BKP_REG_0A:BKP REG_0A Register -----*/

/* Bit field positions: */
#define BKP_REG_0A_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_0A_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_0A */

/** @defgroup Periph_BKP_REG_0B BKP REG_0B
  * @{
  */

/*-- BKP_REG_0B:BKP REG_0B Register -----*/

/* Bit field positions: */
#define BKP_REG_0B_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_0B_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_0B */

/** @defgroup Periph_BKP_REG_0C BKP REG_0C
  * @{
  */

/*-- BKP_REG_0C:BKP REG_0C Register -----*/

/* Bit field positions: */
#define BKP_REG_0C_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_0C_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_0C */

/** @defgroup Periph_BKP_REG_0D BKP REG_0D
  * @{
  */

/*-- BKP_REG_0D:BKP REG_0D Register -----*/

/* Bit field positions: */
#define BKP_REG_0D_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_0D_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_0D */

/** @defgroup Periph_BKP_REG_0E BKP REG_0E
  * @{
  */

/*-- BKP_REG_0E:BKP REG_0E Register -----*/

/* Bit field positions: */
#define BKP_REG_0E_LOW_Pos                                 0
#define BKP_REG_0E_SELECTRI_Pos                            3
#define BKP_REG_0E_SWEN_Pos                                6
#define BKP_REG_0E_TRIM20_Pos                              8
#define BKP_REG_0E_FPOR_Pos                                11
#define BKP_REG_0E_TRIM43_Pos                              12
#define BKP_REG_0E_COVDET_Pos                              14
#define BKP_REG_0E_ILIMEN_Pos                              15

/* Bit field masks: */
#define BKP_REG_0E_LOW_Msk                                 ((uint32_t)0x00000007)
#define BKP_REG_0E_SELECTRI_Msk                            ((uint32_t)0x00000038)
#define BKP_REG_0E_SWEN                                    ((uint32_t)0x000000C0)
#define BKP_REG_0E_TRIM20_Msk                              ((uint32_t)0x00000700)
#define BKP_REG_0E_FPOR                                    ((uint32_t)0x00000800)
#define BKP_REG_0E_TRIM43_Msk                              ((uint32_t)0x00003000)
#define BKP_REG_0E_COVDET                                  ((uint32_t)0x00004000)
#define BKP_REG_0E_ILIMEN                                  ((uint32_t)0x00008000)

/** @} */ /* End of group BKP_REG_0E */

/** @defgroup Periph_BKP_REG_0F BKP REG_0F
  * @{
  */

/*-- BKP_REG_0F:BKP REG_0F Register -----*/

/* Bit field positions: */
#define BKP_REG_0F_LSE_ON_Pos                              0
#define BKP_REG_0F_LSE_BYP_Pos                             1
#define BKP_REG_0F_RTC_SEL_Pos                             2
#define BKP_REG_0F_RTC_EN_Pos                              4
#define BKP_REG_0F_CAL_Pos                                 5
#define BKP_REG_0F_LSE_RDY_Pos                             13
#define BKP_REG_0F_LSI_ON_Pos                              15
#define BKP_REG_0F_LSI_TRIM_Pos                            16
#define BKP_REG_0F_LSI_RDY_Pos                             21
#define BKP_REG_0F_HSI_ON_Pos                              22
#define BKP_REG_0F_HSI_RDY_Pos                             23
#define BKP_REG_0F_HSI_TRIM_Pos                            24
#define BKP_REG_0F_STANDBY_Pos                             30
#define BKP_REG_0F_RTC_RESET_Pos                           31

/* Bit field masks: */
#define BKP_REG_0F_LSE_ON                                  ((uint32_t)0x00000001)
#define BKP_REG_0F_LSE_BYP                                 ((uint32_t)0x00000002)
#define BKP_REG_0F_RTC_SEL_Msk                             ((uint32_t)0x0000000C)
#define BKP_REG_0F_RTC_EN                                  ((uint32_t)0x00000010)
#define BKP_REG_0F_CAL_Msk                                 ((uint32_t)0x00001FE0)
#define BKP_REG_0F_LSE_RDY                                 ((uint32_t)0x00002000)
#define BKP_REG_0F_LSI_ON                                  ((uint32_t)0x00008000)
#define BKP_REG_0F_LSI_TRIM_Msk                            ((uint32_t)0x001F0000)
#define BKP_REG_0F_LSI_RDY                                 ((uint32_t)0x00200000)
#define BKP_REG_0F_HSI_ON                                  ((uint32_t)0x00400000)
#define BKP_REG_0F_HSI_RDY                                 ((uint32_t)0x00800000)
#define BKP_REG_0F_HSI_TRIM_Msk                            ((uint32_t)0x3F000000)
#define BKP_REG_0F_STANDBY                                 ((uint32_t)0x40000000)
#define BKP_REG_0F_RTC_RESET                               ((uint32_t)0x80000000)

/** @} */ /* End of group BKP_REG_0F */

/** @defgroup Periph_BKP_RTC_CNT BKP RTC_CNT
  * @{
  */

/*-- BKP_RTC_CNT:BKP RTC_CNT Register -----*/

/* Bit field positions: */
#define BKP_RTC_CNT_RTC_CNT_Pos                            0

/* Bit field masks: */
#define BKP_RTC_CNT_RTC_CNT_Msk                            ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_RTC_CNT */

/** @defgroup Periph_BKP_RTC_DIV BKP RTC_DIV
  * @{
  */

/*-- BKP_RTC_DIV:BKP RTC_DIV Register -----*/

/* Bit field positions: */
#define BKP_RTC_DIV_RTC_DIV_Pos                            0

/* Bit field masks: */
#define BKP_RTC_DIV_RTC_DIV_Msk                            ((uint32_t)0x000FFFFF)

/** @} */ /* End of group BKP_RTC_DIV */

/** @defgroup Periph_BKP_RTC_PRL BKP RTC_PRL
  * @{
  */

/*-- BKP_RTC_PRL:BKP RTC_PRL Register -----*/

/* Bit field positions: */
#define BKP_RTC_PRL_RTC_PRL_Pos                            0

/* Bit field masks: */
#define BKP_RTC_PRL_RTC_PRL_Msk                            ((uint32_t)0x000FFFFF)

/** @} */ /* End of group BKP_RTC_PRL */

/** @defgroup Periph_BKP_RTC_ALRM BKP RTC_ALRM
  * @{
  */

/*-- BKP_RTC_ALRM:BKP RTC_ALRM Register -----*/

/* Bit field positions: */
#define BKP_RTC_ALRM_RTC_ALRM_Pos                          0

/* Bit field masks: */
#define BKP_RTC_ALRM_RTC_ALRM_Msk                          ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_RTC_ALRM */

/** @defgroup Periph_BKP_RTC_CS BKP RTC_CS
  * @{
  */

/*-- BKP_RTC_CS:BKP RTC_CS Register -----*/

/* Bit field positions: */
#define BKP_RTC_CS_OWF_Pos                                 0
#define BKP_RTC_CS_SECF_Pos                                1
#define BKP_RTC_CS_ALRF_Pos                                2
#define BKP_RTC_CS_OWF_IE_Pos                              3
#define BKP_RTC_CS_SECF_IE_Pos                             4
#define BKP_RTC_CS_ALRF_IE_Pos                             5
#define BKP_RTC_CS_WEC_Pos                                 6

/* Bit field masks: */
#define BKP_RTC_CS_OWF                                     ((uint32_t)0x00000001)
#define BKP_RTC_CS_SECF                                    ((uint32_t)0x00000002)
#define BKP_RTC_CS_ALRF                                    ((uint32_t)0x00000004)
#define BKP_RTC_CS_Msk                                     ((uint32_t)0x00000007)
#define BKP_RTC_CS_OWF_IE                                  ((uint32_t)0x00000008)
#define BKP_RTC_CS_SECF_IE                                 ((uint32_t)0x00000010)
#define BKP_RTC_CS_ALRF_IE                                 ((uint32_t)0x00000020)
#define BKP_RTC_CS_IE_Msk                                  ((uint32_t)0x00000038)
#define BKP_RTC_CS_WEC                                     ((uint32_t)0x00000040)

/** @} */ /* End of group BKP_RTC_CS */

/** @} */ /* End of group BKP */

/** @defgroup MDR32F23QI_Periph_ADCIU ADCIU
  * @{
  */


/* MDR_ADCIU_TypeDef structure */
typedef struct {
    __IO uint32_t   CTRL1;             /*!< General control1 for the ADCIU controller*/
    __IO uint32_t   CTRL2;             /*!< General control2 for the ADCIU controller */
    __IO uint32_t   CTRL3;             /*!< General control3 for the ADCIU controller*/
    __IO uint32_t   F0CTR;             /*!< Conrtol in channel F0*/
    __IO uint32_t   F0WC;              /*!< Active power calculation control in channel F0*/
    __IO uint32_t   F0WATTP;           /*!< Positive active power value in channel F0*/
    __IO uint32_t   F0WATTN;           /*!< Negative active power value in channel F0*/
    __IO uint32_t   F0VC;              /*!< Reactive power calculation control in channel F0*/
    __IO uint32_t   F0VARP;            /*!< Positive reactive power value in channel F0*/
    __IO uint32_t   F0VARN;            /*!< Negative reactive power value in channel F0*/
    __IO uint32_t   F0AC;              /*!< Apparent power calculation control in channel F0*/
    __IO uint32_t   F0VR;              /*!< Apparent power value in channel F0*/
    __IO uint32_t   F0MD0;             /*!< Parameters 0 channel F0*/
    __IO uint32_t   F0MD1;             /*!< Parameters 1 channel F0*/
    __IO uint32_t   F0VPEAK;           /*!< Peak value in the voltage channel in channel F0*/
    __IO uint32_t   F0IPEAK;           /*!< Peak value in current channel in channel F0*/
    __IO uint32_t   F0VDAT;            /*!< Voltage readings in channel F0*/
    __IO uint32_t   F0I0DAT;           /*!< Current readings I0 in channel F0*/
    __IO uint32_t   F0I3DAT;           /*!< Current readings I3 in channel F0*/
    __IO uint32_t   F0VRMS;            /*!< RMS value channel voltage F0*/
    __IO uint32_t   F0VRMS2;           /*!< RMS squared in F0 voltage channel*/
    __IO uint32_t   F0IRMS;            /*!< RMS current channel F0*/
    __IO uint32_t   F0IRMS2;           /*!< RMS squared in current channel F0*/
    __IO uint32_t   F0STAT;            /*!< Channel status F0*/
    __IO uint32_t   F0MASK;            /*!< F0 channel interrupt mask*/
    __IO uint32_t   RESERVED0[44];      /*!< */
    __IO uint32_t   CCAL1;             /*!< Current Channel Calibration Register 1*/
    __IO uint32_t   RESERVED1[2];       /*!< */
    __IO uint32_t   CCAL4;             /*!< Current channel calibration register 4*/
}MDR_ADCIU_TypeDef;

/** @defgroup Periph_ADCIU_CTRL1 ADCIU CTRL1
  * @{
  */

/*-- ADCIU_CTRL1:ADCIU CTRL1 Register -----*/

/* Bit field positions: */
#define ADCIU_CTRL1_I0EN_Pos                               0
#define ADCIU_CTRL1_V0EN_Pos                               1
#define ADCIU_CTRL1_I3EN_Pos                               6
#define ADCIU_CTRL1_RESOL_Pos                              7
#define ADCIU_CTRL1_ZXLPF_Pos                              8
#define ADCIU_CTRL1_PER_LENGHT_Pos                         9
#define ADCIU_CTRL1_APNOLOAD_Pos                           12
#define ADCIU_CTRL1_VARNOLOAD_Pos                          15
#define ADCIU_CTRL1_VANOLOAD_Pos                           17
#define ADCIU_CTRL1_FREQSEL_Pos                            19
#define ADCIU_CTRL1_VREF_SEL_Pos                           20
#define ADCIU_CTRL1_BUF_BYP_Pos                            21
#define ADCIU_CTRL1_ZXRMS_Pos                              27
#define ADCIU_CTRL1_RESET_DIG_Pos                          28
#define ADCIU_CTRL1_IBOOST_Pos                             29
#define ADCIU_CTRL1_OSR_CONF_Pos                           30

/* Bit field masks: */
#define ADCIU_CTRL1_I0EN_Msk                               ((uint32_t)0x00000001)
#define ADCIU_CTRL1_V0EN_Msk                               ((uint32_t)0x00000002)
#define ADCIU_CTRL1_I3EN_Msk                               ((uint32_t)0x00000040)
#define ADCIU_CTRL1_RESOL_Msk                              ((uint32_t)0x00000080)
#define ADCIU_CTRL1_ZXLPF_Msk                              ((uint32_t)0x00000100)
#define ADCIU_CTRL1_PER_LENGHT_Msk                         ((uint32_t)0x00000E00)
#define ADCIU_CTRL1_APNOLOAD_Msk                           ((uint32_t)0x00003000)
#define ADCIU_CTRL1_VARNOLOAD_Msk                          ((uint32_t)0x00018000)
#define ADCIU_CTRL1_VANOLOAD_Msk                           ((uint32_t)0x00060000)
#define ADCIU_CTRL1_FREQSEL_Msk                            ((uint32_t)0x00080000)
#define ADCIU_CTRL1_VREF_SEL_Msk                           ((uint32_t)0x00100000)
#define ADCIU_CTRL1_BUF_BYP_Msk                            ((uint32_t)0x00200000)
#define ADCIU_CTRL1_ZXRMS_Msk                              ((uint32_t)0x08000000)
#define ADCIU_CTRL1_RESET_DIG_Msk                          ((uint32_t)0x10000000)
#define ADCIU_CTRL1_IBOOST_Msk                             ((uint32_t)0x20000000)
#define ADCIU_CTRL1_OSR_CONF_Msk                           ((uint32_t)0xC0000000)

/** @} */ /* End of group ADCIU_CTRL1 */

/** @defgroup Periph_ADCIU_CTRL2 ADCIU CTRL2
  * @{
  */

/*-- ADCIU_CTRL2:ADCIU CTRL2 Register -----*/

/* Bit field positions: */
#define ADCIU_CTRL2_SAGLVL_Pos                           0
#define ADCIU_CTRL2_SAGCYC_Pos                           16

/* Bit field masks: */
#define ADCIU_CTRL2_SAGLVL_Msk                           ((uint32_t)0x0000FFFF)
#define ADCIU_CTRL2_SAGCYC_Msk                           ((uint32_t)0x00FF0000)

/** @} */ /* End of group ADCIU_CTRL2 */

/** @defgroup Periph_ADCIU_CTRL3 ADCIU CTRL2
  * @{
  */

/*-- ADCIU_CTRL2:ADCIU CTRL3 Register -----*/

/* Bit field positions: */
#define ADCIU_CTRL3_ZXTOUT_Pos                           0

/* Bit field masks: */
#define ADCIU_CTRL3_ZXTOUT_Msk                           ((uint32_t)0x00000FFF)

/** @} */ /* End of group ADCIU_CTRL3 */

/** @defgroup Periph_ADCIU_F0CTR ADCIU F0CTR 
  * @{
  */

/*-- ADCIU_F0CTR:ADCIU F0CTR Register -----*/

/* Bit field positions: */
#define ADCIU_F0CTR_F0I0NTEN_Pos                           0
#define ADCIU_F0CTR_F0I3NTEN_Pos                           1
#define ADCIU_F0CTR_F0VASEL_Pos                            2
#define ADCIU_F0CTR_F0RARS_Pos                             3
#define ADCIU_F0CTR_F0RRRS_Pos                             4
#define ADCIU_F0CTR_F0RVRS_Pos                             5
#define ADCIU_F0CTR_F0I0GAIN_Pos                           6
#define ADCIU_F0CTR_F0VGAIN_Pos                            8
#define ADCIU_F0CTR_F0VPHASE_Pos                           10
#define ADCIU_F0CTR_F0I3GAIN_Pos                           18
#define ADCIU_F0CTR_F0IRMSOS_Pos                           20

/* Bit field masks: */
#define ADCIU_F0CTR_F0I0NTEN_Msk                          ((uint32_t)0x00000001)
#define ADCIU_F0CTR_F0I3NTEN_Msk                          ((uint32_t)0x00000002)
#define ADCIU_F0CTR_F0VASEL_Msk                           ((uint32_t)0x00000004)
#define ADCIU_F0CTR_F0RARS_Msk                            ((uint32_t)0x00000008)
#define ADCIU_F0CTR_F0RRRS_Msk                            ((uint32_t)0x00000010)
#define ADCIU_F0CTR_F0RVRS_Msk                            ((uint32_t)0x00000020)
#define ADCIU_F0CTR_F0I0GAIN_Msk                          ((uint32_t)0x000000C0)
#define ADCIU_F0CTR_F0VGAIN_Msk                           ((uint32_t)0x00000300)
#define ADCIU_F0CTR_F0VPHASE_Msk                          ((uint32_t)0x0003FC00)
#define ADCIU_F0CTR_F0I3GAIN_Msk                          ((uint32_t)0x000C0000)
#define ADCIU_F0CTR_F0IRMSOS_Msk                          ((uint32_t)0xFFF00040)

/** @} */ /* End of group ADCIU_F0CTR */

/** @defgroup Periph_ADCIU_F0WС ADCIU F0WС
  * @{
  */

/*-- ADCIU_F0WС:ADCIU F0WС Register -----*/

/* Bit field positions: */
#define ADCIU_F0WС_F0WATTOS_Pos                           0
#define ADCIU_F0WС_F0WGAIN_Pos                            16

/* Bit field masks: */
#define ADCIU_F0WС_F0WATTOS_Msk                          ((uint32_t)0x0000FFFF)
#define ADCIU_F0WС_F0WGAIN_Msk                           ((uint32_t)0x0FFF0000)

/** @} */ /* End of group ADCIU_F0WС */

/** @defgroup Periph_ADCIU_F0WATTP ADCIU F0WATTP
  * @{
  */

/*-- ADCIU_F0WATTP:ADCIU F0WATTP Register -----*/

/* Bit field positions: */
#define ADCIU_F0WATTP_F0WATTHRP_Pos                      0

/* Bit field masks: */
#define ADCIU_F0WATTP_F0WATTHRP_Msk                      ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group ADCIU_F0WATTP */

/** @defgroup Periph_ADCIU_F0WATTN ADCIU F0WATTN
  * @{
  */

/*-- ADCIU_F0WATTN:ADCIU F0WATTN Register -----*/

/* Bit field positions: */
#define ADCIU_F0WATTN_F0WATTHRN_Pos                      0

/* Bit field masks: */
#define ADCIU_F0WATTN_F0WATTHRN_Msk                     ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group ADCIU_F0WATTN */

/** @defgroup Periph_ADCIU_F0VС ADCIU F0VС
  * @{
  */

/*-- ADCIU_F0VС:ADCIU F0VС Register -----*/

/* Bit field positions: */
#define ADCIU_F0VС_F0VAROS_Pos                            0
#define ADCIU_F0VС_F0VARGAIN_Pos                          16

/* Bit field masks: */
#define ADCIU_F0VС_F0VAROS_Msk                           ((uint32_t)0x0000FFFF)
#define ADCIU_F0VС_F0VARGAIN_Msk                           ((uint32_t)0x0FFF0000)

/** @} */ /* End of group ADCIU_F0VС */

/** @defgroup Periph_ADCIU_F0VARP ADCIU F0VARP
  * @{
  */

/*-- ADCIU_F0VARP:ADCIU F0VARP Register -----*/

/* Bit field positions: */
#define ADCIU_F0VARP_F0VARHRP_Pos                         0

/* Bit field masks: */
#define ADCIU_F0VARP_F0VARHRP_Msk                         ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group ADCIU_F0VARP */

/** @defgroup Periph_ADCIU_F0VARN ADCIU F0VARN
  * @{
  */

/*-- ADCIU_F0VARN:ADCIU F0VARN Register -----*/

/* Bit field positions: */
#define ADCIU_F0VARN_F0VARHRN_Pos                        0

/* Bit field masks: */
#define ADCIU_F0VARN_F0VARHRN_Msk                        ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group ADCIU_F0VARN */

/** @defgroup Periph_ADCIU_F0AС ADCIU F0AС
  * @{
  */

/*-- ADCIU_F0AС:ADCIU F0AС Register -----*/

/* Bit field positions: */
#define ADCIU_F0AС_F0VRMSOS_Pos                         0
#define ADCIU_F0AС_F0VAGAIN_Pos                         16

/* Bit field masks: */
#define ADCIU_F0AС_F0VRMSOS_Msk                         ((uint32_t)0x00000FFF)
#define ADCIU_F0AС_F0VAGAIN_Msk                         ((uint32_t)0x0FFF0000)

/** @} */ /* End of group ADCIU_F0AС */

/** @defgroup Periph_ADCIU_F0VR ADCIU F0VR
  * @{
  */

/*-- ADCIU_F0VR:ADCIU F0VR Register -----*/

/* Bit field positions: */
#define ADCIU_F0VR_F0VAHR_Pos                        0

/* Bit field masks: */
#define ADCIU_F0VR_F0VAHR_Msk                        ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group ADCIU_F0VR */

/** @defgroup Periph_ADCIU_F0MD0 ADCIU F0MD0
  * @{
  */

/*-- ADCIU_F0MD0:ADCIU F0MD0 Register -----*/

/* Bit field positions: */
#define ADCIU_F0MD0_F0VSEL_Pos                        0
#define ADCIU_F0MD0_F0ISEL_Pos                        2
#define ADCIU_F0MD0_F0ACTS_Pos                        4
#define ADCIU_F0MD0_F0REACTS_Pos                      5
#define ADCIU_F0MD0_I0GAIN_Pos                        6
#define ADCIU_F0MD0_V0GAIN_Pos                        7
#define ADCIU_F0MD0_I3GAIN_Pos                        8
#define ADCIU_F0MD0_F0PER_FREQ_Pos                    12
#define ADCIU_F0MD0_F0I3SEL_Pos                       29
#define ADCIU_F0MD0_F0SEL_I_CH_Pos                    30

/* Bit field masks: */
#define ADCIU_F0MD0_F0VSEL_Msk                        ((uint32_t)0x00000003)
#define ADCIU_F0MD0_F0ISEL_Msk                        ((uint32_t)0x0000000C)
#define ADCIU_F0MD0_F0ACTS_Msk                        ((uint32_t)0x00000010)
#define ADCIU_F0MD0_F0REACTS_Msk                      ((uint32_t)0x00000020)
#define ADCIU_F0MD0_I0GAIN_Msk                        ((uint32_t)0x00000040)
#define ADCIU_F0MD0_V0GAIN_Msk                        ((uint32_t)0x00000080)
#define ADCIU_F0MD0_I3GAIN_Msk                        ((uint32_t)0x00000100)
#define ADCIU_F0MD0_F0PER_FREQ_Msk                    ((uint32_t)0x1FFFF000)
#define ADCIU_F0MD0_F0I3SEL_Msk                       ((uint32_t)0x20000000)
#define ADCIU_F0MD0_F0SEL_I_CH_Msk                    ((uint32_t)0xC0000000)

/** @} */ /* End of group ADCIU_F0MD0 */

/** @defgroup Periph_ADCIU_F0MD1 ADCIU F0MD1
  * @{
  */

/*-- ADCIU_F0MD1:ADCIU F0MD1 Register -----*/

/* Bit field positions: */
#define ADCIU_F0MD1_F0IPKLVL_Pos                        0
#define ADCIU_F0MD1_F0VPKLVL_Pos                        16

/* Bit field masks: */
#define ADCIU_F0MD1_F0IPKLVL_Msk                        ((uint32_t)0x0000FFFF)
#define ADCIU_F0MD1_F0VPKLVL_Msk                        ((uint32_t)0xFFFF0000)

/** @} */ /* End of group ADCIU_F0MD1 */

/** @defgroup Periph_ADCIU_F0VPEAK ADCIU F0VPEAK
  * @{
  */

/*-- ADCIU_F0VPEAK:ADCIU F0VPEAK Register -----*/

/* Bit field positions: */
#define ADCIU_F0VPEAK_F0VPEAK_Pos                        0

/* Bit field masks: */
#define ADCIU_F0VPEAK_F0VPEAK_Msk                        ((uint32_t)0x00FFFFFF)

/** @} */ /* End of group F0VPEAK */


/** @defgroup Periph_ADCIU_F0IPEAK ADCIU F0IPEAK
  * @{
  */

/*-- ADCIU_F0IPEAK:ADCIU F0IPEAK Register -----*/

/* Bit field positions: */
#define ADCIU_F0IPEAK_F0IPEAK_Pos                        0

/* Bit field masks: */
#define ADCIU_F0IPEAK_F0IPEAK_Msk                        ((uint32_t)0x00FFFFFF)

/** @} */ /* End of group F0IPEAK */


/** @defgroup Periph_ADCIU_F0VDAT ADCIU F0VDAT
  * @{
  */

/*-- ADCIU_F0VDAT:ADCIU F0VDAT Register -----*/

/* Bit field positions: */
#define ADCIU_F0VDAT_F0VDAT_Pos                        0

/* Bit field masks: */
#define ADCIU_F0VDAT_F0VDAT_Msk                        ((uint32_t)0x00FFFFFF)

/** @} */ /* End of group F0VDAT */

/** @defgroup Periph_ADCIU_F0I0DAT ADCIU F0I0DAT
  * @{
  */

/*-- ADCIU_F0I0DAT:ADCIU F0I0DAT Register -----*/

/* Bit field positions: */
#define ADCIU_F0I0DAT_F0I0DAT_Pos                        0

/* Bit field masks: */
#define ADCIU_F0I0DAT_F0I0DAT_Msk                        ((uint32_t)0x00FFFFFF)

/** @} */ /* End of group F0I0DAT */

/** @defgroup Periph_ADCIU_F0I3DAT ADCIU F0I3DAT
  * @{
  */

/*-- ADCIU_F0I3DAT:ADCIU F0I3DAT Register -----*/

/* Bit field positions: */
#define ADCIU_F0I3DAT_F0I3DAT_Pos                        0

/* Bit field masks: */
#define ADCIU_F0I3DAT_F0I3DAT_Msk                        ((uint32_t)0x00FFFFFF)

/** @} */ /* End of group F0I3DAT */

/** @defgroup Periph_ADCIU_F0VRMS ADCIU F0VRMS
  * @{
  */

/*-- ADCIU_F0VRMS:ADCIU F0VRMS Register -----*/

/* Bit field positions: */
#define ADCIU_F0VRMS_F0VRMS_Pos                        0

/* Bit field masks: */
#define ADCIU_F0VRMS_F0VRMS_Msk                        ((uint32_t)0x00FFFFFF)

/** @} */ /* End of group F0VRMS */

/** @defgroup Periph_ADCIU_F0VRMS2 ADCIU F0VRMS2
  * @{
  */

/*-- ADCIU_F0VRMS2:ADCIU F0VRMS Register -----*/

/* Bit field positions: */
#define ADCIU_F0VRMS2_F0VRMS2_Pos                        0

/* Bit field masks: */
#define ADCIU_F0VRMS2_F0VRMS2_Msk                        ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group F0VRMS2 */

/** @defgroup Periph_ADCIU_F0IRMS ADCIU F0IRMS
  * @{
  */

/*-- ADCIU_F0IRMS:ADCIU F0IRMS Register -----*/

/* Bit field positions: */
#define ADCIU_F0IRMS_F0IRMS_Pos                        0

/* Bit field masks: */
#define ADCIU_F0IRMS_F0IRMS_Msk                        ((uint32_t)0x00FFFFFF)

/** @} */ /* End of group F0IRMS */

/** @defgroup Periph_ADCIU_F0IRMS2 ADCIU F0IRMS2
  * @{
  */

/*-- ADCIU_F0IRMS2:ADCIU F0IRMS2 Register -----*/

/* Bit field positions: */
#define ADCIU_F0IRMS2_F0IRMS2_Pos                        0

/* Bit field masks: */
#define ADCIU_F0IRMS2_F0IRMS2_Msk                        ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group F0IRMS2 */

/** @defgroup Periph_ADCIU_F0STAT ADCIU F0STAT
  * @{
  */

/*-- ADCIU_F0STAT:ADCIU F0STAT Register -----*/

/* Bit field positions: */
#define ADCIU_F0STAT_F0VF_EMP_Pos                        0
#define ADCIU_F0STAT_F0VF_FLL_Pos                        1
#define ADCIU_F0STAT_F0VF_OVR_Pos                        2
#define ADCIU_F0STAT_F0IF_EMP_Pos                        3
#define ADCIU_F0STAT_F0IF_FLL_Pos                        4
#define ADCIU_F0STAT_F0IF_OVR_Pos                        5
#define ADCIU_F0STAT_F0SAGF_Pos                          6
#define ADCIU_F0STAT_F0PEAKVF_Pos                        7
#define ADCIU_F0STAT_F0PEAKIF_Pos                        8
#define ADCIU_F0STAT_F0WATTOVP_Pos                       9
#define ADCIU_F0STAT_F0VAROVP_Pos                        10
#define ADCIU_F0STAT_F0VAOV_Pos                          11
#define ADCIU_F0STAT_F0ZXTOF_Pos                         12
#define ADCIU_F0STAT_F0ICHANNEL_Pos                      13
#define ADCIU_F0STAT_F0FAULTCON_Pos                      14
#define ADCIU_F0STAT_F0APSIGN_Pos                        15
#define ADCIU_F0STAT_F0APNLDFL_Pos                       16
#define ADCIU_F0STAT_F0VARSIGN_Pos                       17
#define ADCIU_F0STAT_F0VARNLDFL_Pos                      18
#define ADCIU_F0STAT_F0VANLDFL_Pos                       20
#define ADCIU_F0STAT_F0ZEROCRS_Pos                       21
#define ADCIU_F0STAT_C3IF_EMP_Pos                        22
#define ADCIU_F0STAT_C3IF_FLL_Pos                        23
#define ADCIU_F0STAT_C3IF_OVR_Pos                        24
#define ADCIU_F0STAT_F0WATTOVN_Pos                       25
#define ADCIU_F0STAT_F0VAROVN_Pos                        26

/* Bit field masks: */
#define ADCIU_F0STAT_F0VF_EMP_Msk                       ((uint32_t)0x00000001)
#define ADCIU_F0STAT_F0VF_FLL_Msk                       ((uint32_t)0x00000002)
#define ADCIU_F0STAT_F0VF_OVR_Msk                       ((uint32_t)0x00000004)
#define ADCIU_F0STAT_F0IF_EMP_Msk                       ((uint32_t)0x00000008)
#define ADCIU_F0STAT_F0IF_FLL_Msk                       ((uint32_t)0x00000010)
#define ADCIU_F0STAT_F0IF_OVR_Msk                       ((uint32_t)0x00000020)
#define ADCIU_F0STAT_F0SAGF_Msk                         ((uint32_t)0x00000040)
#define ADCIU_F0STAT_F0PEAKVF_Msk                       ((uint32_t)0x00000080)
#define ADCIU_F0STAT_F0PEAKIF_Msk                       ((uint32_t)0x00000100)
#define ADCIU_F0STAT_F0WATTOVP_Msk                      ((uint32_t)0x00000200)
#define ADCIU_F0STAT_F0VAROVP_Msk                       ((uint32_t)0x00000400)
#define ADCIU_F0STAT_F0VAOV_Msk                         ((uint32_t)0x00000800)
#define ADCIU_F0STAT_F0ZXTOF_Msk                        ((uint32_t)0x00001000)
#define ADCIU_F0STAT_F0ICHANNEL_Msk                     ((uint32_t)0x00002000)
#define ADCIU_F0STAT_F0FAULTCON_Msk                     ((uint32_t)0x00004000)
#define ADCIU_F0STAT_F0APSIGN_Msk                       ((uint32_t)0x00008000)
#define ADCIU_F0STAT_F0APNLDFL_Msk                      ((uint32_t)0x00010000)
#define ADCIU_F0STAT_F0VARSIGN_Msk                      ((uint32_t)0x00020000)
#define ADCIU_F0STAT_F0VARNLDFL_Msk                     ((uint32_t)0x00040000)
#define ADCIU_F0STAT_F0VANLDFL_Msk                      ((uint32_t)0x00100000)
#define ADCIU_F0STAT_F0ZEROCRS_Msk                      ((uint32_t)0x00200000)
#define ADCIU_F0STAT_C3IF_EMP_Msk                       ((uint32_t)0x00400000)
#define ADCIU_F0STAT_C3IF_FLL_Msk                       ((uint32_t)0x00800000)
#define ADCIU_F0STAT_C3IF_OVR_Msk                       ((uint32_t)0x01000000)
#define ADCIU_F0STAT_F0WATTOVN_Msk                      ((uint32_t)0x02000000)
#define ADCIU_F0STAT_F0VAROVN_Msk                       ((uint32_t)0x04000000)

/** @} */ /* End of group ADCIU_F0STAT */


/** @defgroup Periph_ADCIU_F0MASK ADCIU F0MASK
  * @{
  */

/*-- ADCIU_F0MASK:ADCIU F0MASK Register -----*/

/* Bit field positions: */
#define ADCIU_F0MASK_F0VF_EMPM_Pos                        0
#define ADCIU_F0MASK_F0VF_FLLM_Pos                        1
#define ADCIU_F0MASK_F0VF_OVRM_Pos                        2
#define ADCIU_F0MASK_F0IF_EMPM_Pos                        3
#define ADCIU_F0MASK_F0IF_FLLM_Pos                        4
#define ADCIU_F0MASK_F0IF_OVRM_Pos                        5
#define ADCIU_F0MASK_F0SAGFM_Pos                          6
#define ADCIU_F0MASK_F0PEAKVFM_Pos                        7
#define ADCIU_F0MASK_F0PEAKIFM_Pos                        8
#define ADCIU_F0MASK_F0WATTOVPM_Pos                       9
#define ADCIU_F0MASK_F0VAROVPM_Pos                        10
#define ADCIU_F0MASK_F0VAOVM_Pos                          11
#define ADCIU_F0MASK_F0ZXTOFM_Pos                         12
#define ADCIU_F0MASK_F0FAULTCONM_Pos                      14
#define ADCIU_F0MASK_F0APSIGNM_Pos                        15
#define ADCIU_F0MASK_F0APNLDFLM_Pos                       16
#define ADCIU_F0MASK_F0VARSIGNM_Pos                       17
#define ADCIU_F0MASK_F0VARNLDFLM_Pos                      18
#define ADCIU_F0MASK_F0VANLDFLM_Pos                       20
#define ADCIU_F0MASK_F0ZEROCRSM_Pos                       21
#define ADCIU_F0MASK_C3IF_EMPM_Pos                        22
#define ADCIU_F0MASK_C3IF_FLLM_Pos                        23
#define ADCIU_F0MASK_C3IF_OVRM_Pos                        24
#define ADCIU_F0MASK_F0WATTOVNM_Pos                       25
#define ADCIU_F0MASK_F0VAROVNM_Pos                        26

/* Bit field masks: */
#define ADCIU_F0MASK_F0VF_EMPM_Msk                       ((uint32_t)0x00000001)
#define ADCIU_F0MASK_F0VF_FLLM_Msk                       ((uint32_t)0x00000002)
#define ADCIU_F0MASK_F0VF_OVRM_Msk                       ((uint32_t)0x00000004)
#define ADCIU_F0MASK_F0IF_EMPM_Msk                       ((uint32_t)0x00000008)
#define ADCIU_F0MASK_F0IF_FLLM_Msk                       ((uint32_t)0x00000010)
#define ADCIU_F0MASK_F0IF_OVRM_Msk                       ((uint32_t)0x00000020)
#define ADCIU_F0MASK_F0SAGFM_Msk                         ((uint32_t)0x00000040)
#define ADCIU_F0MASK_F0PEAKVFM_Msk                       ((uint32_t)0x00000080)
#define ADCIU_F0MASK_F0PEAKIFM_Msk                       ((uint32_t)0x00000100)
#define ADCIU_F0MASK_F0WATTOVPM_Msk                      ((uint32_t)0x00000200)
#define ADCIU_F0MASK_F0VAROVPM_Msk                       ((uint32_t)0x00000400)
#define ADCIU_F0MASK_F0VAOVM_Msk                         ((uint32_t)0x00000800)
#define ADCIU_F0MASK_F0ZXTOFM_Msk                        ((uint32_t)0x00001000)
#define ADCIU_F0MASK_F0FAULTCONM_Msk                     ((uint32_t)0x00004000)
#define ADCIU_F0MASK_F0APSIGNM_Msk                       ((uint32_t)0x00008000)
#define ADCIU_F0MASK_F0APNLDFLM_Msk                      ((uint32_t)0x00010000)
#define ADCIU_F0MASK_F0VARSIGNM_Msk                      ((uint32_t)0x00020000)
#define ADCIU_F0MASK_F0VARNLDFLM_Msk                     ((uint32_t)0x00040000)
#define ADCIU_F0MASK_F0VANLDFLM_Msk                      ((uint32_t)0x00100000)
#define ADCIU_F0MASK_F0ZEROCRSM_Msk                      ((uint32_t)0x00200000)
#define ADCIU_F0MASK_C3IF_EMPM_Msk                       ((uint32_t)0x00400000)
#define ADCIU_F0MASK_C3IF_FLLM_Msk                       ((uint32_t)0x00800000)
#define ADCIU_F0MASK_C3IF_OVRM_Msk                       ((uint32_t)0x01000000)
#define ADCIU_F0MASK_F0WATTOVNM_Msk                      ((uint32_t)0x02000000)
#define ADCIU_F0MASK_F0VAROVNM_Msk                       ((uint32_t)0x04000000)

/** @} */ /* End of group ADCIU_F0MASK */

/** @defgroup Periph_ADCIU_CCAL1 ADCIU CCAL1
  * @{
  */

/*-- ADCIU_CCAL1:ADCIU CCAL1 Register -----*/

/* Bit field positions: */
#define ADCIU_CCAL1_V0BGAIN_Pos                        0
#define ADCIU_CCAL1_I0BGAIN_Pos                        12

/* Bit field masks: */
#define ADCIU_CCAL1_V0BGAIN_Msk                        ((uint32_t)0x00000FFF)
#define ADCIU_CCAL1_I0BGAIN_Msk                        ((uint32_t)0x0FFFF000)

/** @} */ /* End of group CCAL1 */

/** @defgroup Periph_ADCIU_CCAL1 ADCIU CCAL1
  * @{
  */

/*-- ADCIU_CCAL4:ADCIU CCAL4 Register -----*/

/* Bit field positions: */
#define ADCIU_CCAL4_V0BGAIN_Pos                        0

/* Bit field masks: */
#define ADCIU_CCAL4_V0BGAIN_Msk                        ((uint32_t)0x00000FFF)

/** @} */ /* End of group CCAL4 */

/** @} */ /* End of group ADCIU */


/** @defgroup MDR32F23QI_Periph_TIMER TIMER
  * @{
  */


/* MDR_TIMERx_TypeDef structure */
typedef struct {
    __IO uint32_t   CNT;                    /*!<Timer Counter Register */
    __IO uint32_t   PSG;                    /*!<Timer Clock Prescaler Register */
    __IO uint32_t   ARR;                    /*!<Timer Auto-Reload Register */
    __IO uint32_t   CNTRL;                  /*!<Timer Capture/Compare1 Register */
    __IO uint32_t   CCR1;                   /*!<Reserved */
    __IO uint32_t   RESERVED0;              /*!<Reserved */
    __IO uint32_t   RESERVED1;              /*!<Reserved */
    __IO uint32_t   RESERVED2;              /*!<Reserved */
    __IO uint32_t   CH1_CNTRL;              /*!<Timer Channel Control Register 1 */
    __IO uint32_t   RESERVED3;              /*!<Reserved */
    __IO uint32_t   RESERVED4;              /*!<Reserved */
    __IO uint32_t   RESERVED5;              /*!<Reserved */
    __IO uint32_t   CH1_CNTRL1;             /*!<Timer Channel Control1 Register 1 */
    __IO uint32_t   RESERVED6;              /*!<Reserved */
    __IO uint32_t   RESERVED7;              /*!<Reserved */
    __IO uint32_t   RESERVED8;              /*!<Reserved */
    __IO uint32_t   CH1_DTG;                /*!<Timer Channel DTG Register 1 */
    __IO uint32_t   RESERVED9;             /*!<Reserved */
    __IO uint32_t   RESERVED10;             /*!<Reserved */
    __IO uint32_t   RESERVED11;             /*!<Reserved */
    __IO uint32_t   BRKETR_CNTRL;           /*!<Timer BRK/ETR Control Register */
    __IO uint32_t   STATUS;                 /*!<Timer Status Register */
    __IO uint32_t   IE;                     /*!<Timer Interrupt Enable Register */
    __IO uint32_t   RESERVED12;             /*!<Reserved */
    __IO uint32_t   CH1_CNTRL2;             /*!<Timer Channel Control2 Register 1 */
    __IO uint32_t   RESERVED13;             /*!<Reserved */
    __IO uint32_t   RESERVED14;             /*!<Reserved */
    __IO uint32_t   RESERVED15;             /*!<Reserved */
    __IO uint32_t   CCR11;                  /*!<Timer Capture/Compare1 Register 1 */
}MDR_TIMER_TypeDef;

/** @defgroup Periph_TIMER_CNT TIMER CNT
  * @{
  */

/*-- TIMER_CNT:TIMER CNT Register -----*/

/* Bit field positions: */
#define TIMER_CNT_CNT_Pos                                  0

/* Bit field masks: */
#define TIMER_CNT_CNT_Msk                                  ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_CNT */

/** @defgroup Periph_TIMER_PSG TIMER PSG
  * @{
  */

/*-- TIMER_PSG:TIMER PSG Register -----*/

/* Bit field positions: */
#define TIMER_PSG_PSG_Pos                                  0

/* Bit field masks: */
#define TIMER_PSG_PSG_Msk                                  ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_PSG */

/** @defgroup Periph_TIMER_ARR TIMER ARR
  * @{
  */

/*-- TIMER_ARR:TIMER ARR Register -----*/

/* Bit field positions: */
#define TIMER_ARR_ARR_Pos                                  0

/* Bit field masks: */
#define TIMER_ARR_ARR_Msk                                  ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_ARR */

/** @defgroup Periph_TIMER_CNTRL TIMER CNTRL
  * @{
  */

/*-- TIMER_CNTRL:TIMER CNTRL Register -----*/

/* Bit field positions: */
#define TIMER_CNTRL_CNT_EN_Pos                             0
#define TIMER_CNTRL_ARRB_EN_Pos                            1
#define TIMER_CNTRL_WR_CMPL_Pos                            2
#define TIMER_CNTRL_DIR_Pos                                3
#define TIMER_CNTRL_FDTS_Pos                               4
#define TIMER_CNTRL_CNT_MODE_Pos                           6
#define TIMER_CNTRL_EVENT_SEL_Pos                          8

/* Bit field masks: */
#define TIMER_CNTRL_CNT_EN                                 ((uint32_t)0x00000001)
#define TIMER_CNTRL_ARRB_EN                                ((uint32_t)0x00000002)
#define TIMER_CNTRL_WR_CMPL                                ((uint32_t)0x00000004)
#define TIMER_CNTRL_DIR                                    ((uint32_t)0x00000008)
#define TIMER_CNTRL_FDTS_Msk                               ((uint32_t)0x00000030)
#define TIMER_CNTRL_CNT_MODE_Msk                           ((uint32_t)0x000000C0)
#define TIMER_CNTRL_EVENT_SEL_Msk                          ((uint32_t)0x00000F00)

/** @} */ /* End of group TIMER_CNTRL */

/** @defgroup Periph_TIMER_CCR TIMER CCR
  * @{
  */

/*-- TIMER_CCR:TIMER CCR Register -----*/

/* Bit field positions: */
#define TIMER_CCR_CCR_Pos                                  0

/* Bit field masks: */
#define TIMER_CCR_CCR_Msk                                  ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_CCR */

/** @defgroup Periph_TIMER_CH_CNTRL TIMER CH_CNTRL
  * @{
  */

/*-- TIMER_CH_CNTRL:TIMER CH_CNTRL Register -----*/

/* Bit field positions: */
#define TIMER_CH_CNTRL_CHFLTR_Pos                          0
#define TIMER_CH_CNTRL_CHSEL_Pos                           4
#define TIMER_CH_CNTRL_CHPSC_Pos                           6
#define TIMER_CH_CNTRL_OCCE_Pos                            8
#define TIMER_CH_CNTRL_OCCM_Pos                            9
#define TIMER_CH_CNTRL_BRKEN_Pos                           12
#define TIMER_CH_CNTRL_ETREN_Pos                           13
#define TIMER_CH_CNTRL_WR_CMPL_Pos                         14
#define TIMER_CH_CNTRL_CAP_NPWM_Pos                        15

/* Bit field masks: */
#define TIMER_CH_CNTRL_CHFLTR_Msk                          ((uint32_t)0x0000000F)
#define TIMER_CH_CNTRL_CHSEL_Msk                           ((uint32_t)0x00000030)
#define TIMER_CH_CNTRL_CHPSC_Msk                           ((uint32_t)0x000000C0)
#define TIMER_CH_CNTRL_OCCE                                ((uint32_t)0x00000100)
#define TIMER_CH_CNTRL_OCCM_Msk                            ((uint32_t)0x00000E00)
#define TIMER_CH_CNTRL_BRKEN                               ((uint32_t)0x00001000)
#define TIMER_CH_CNTRL_ETREN                               ((uint32_t)0x00002000)
#define TIMER_CH_CNTRL_WR_CMPL                             ((uint32_t)0x00004000)
#define TIMER_CH_CNTRL_CAP_NPWM                            ((uint32_t)0x00008000)

/** @} */ /* End of group TIMER_CH_CNTRL */

/** @defgroup Periph_TIMER_CH_CNTRL1 TIMER CH_CNTRL1
  * @{
  */

/*-- TIMER_CH_CNTRL1:TIMER CH_CNTRL1 Register -----*/

/* Bit field positions: */
#define TIMER_CH_CNTRL1_SELOE_Pos                          0
#define TIMER_CH_CNTRL1_SELO_Pos                           2
#define TIMER_CH_CNTRL1_INV_Pos                            4
#define TIMER_CH_CNTRL1_NSELOE_Pos                         8
#define TIMER_CH_CNTRL1_NSELO_Pos                          10
#define TIMER_CH_CNTRL1_NINV_Pos                           12

/* Bit field masks: */
#define TIMER_CH_CNTRL1_SELOE_Msk                          ((uint32_t)0x00000003)
#define TIMER_CH_CNTRL1_SELO_Msk                           ((uint32_t)0x0000000C)
#define TIMER_CH_CNTRL1_INV                                ((uint32_t)0x00000010)
#define TIMER_CH_CNTRL1_NSELOE_Msk                         ((uint32_t)0x00000300)
#define TIMER_CH_CNTRL1_NSELO_Msk                          ((uint32_t)0x00000C00)
#define TIMER_CH_CNTRL1_NINV                               ((uint32_t)0x00001000)

/** @} */ /* End of group TIMER_CH_CNTRL1 */

/** @defgroup Periph_TIMER_CH_DTG TIMER CH_DTG
  * @{
  */

/*-- TIMER_CH_DTG:TIMER CH_DTG Register -----*/

/* Bit field positions: */
#define TIMER_CH_DTG_DTGX_Pos                              0
#define TIMER_CH_DTG_EDTS_Pos                              4
#define TIMER_CH_DTG_DTG_Pos                               8

/* Bit field masks: */
#define TIMER_CH_DTG_DTGX_Msk                              ((uint32_t)0x0000000F)
#define TIMER_CH_DTG_EDTS                                  ((uint32_t)0x00000010)
#define TIMER_CH_DTG_DTG_Msk                               ((uint32_t)0x0000FF00)

/** @} */ /* End of group TIMER_CH_DTG */

/** @defgroup Periph_TIMER_BRKETR_CNTRL TIMER BRKETR_CNTRL
  * @{
  */

/*-- TIMER_BRKETR_CNTRL:TIMER BRKETR_CNTRL Register -----*/

/* Bit field positions: */
#define TIMER_BRKETR_CNTRL_BRK_INV_Pos                     0
#define TIMER_BRKETR_CNTRL_ETR_INV_Pos                     1
#define TIMER_BRKETR_CNTRL_ETR_PSC_Pos                     2
#define TIMER_BRKETR_CNTRL_ETR_FILTER_Pos                  4

/* Bit field masks: */
#define TIMER_BRKETR_CNTRL_BRK_INV                         ((uint32_t)0x00000001)
#define TIMER_BRKETR_CNTRL_ETR_INV                         ((uint32_t)0x00000002)
#define TIMER_BRKETR_CNTRL_ETR_PSC_Msk                     ((uint32_t)0x0000000C)
#define TIMER_BRKETR_CNTRL_ETR_FILTER_Msk                  ((uint32_t)0x000000F0)

/** @} */ /* End of group TIMER_BRKETR_CNTRL */

/** @defgroup Periph_TIMER_STATUS TIMER STATUS
  * @{
  */

/*-- TIMER_STATUS:TIMER STATUS Register -----*/

/* Bit field positions: */
#define TIMER_STATUS_CNT_ZERO_EVENT_Pos                    0
#define TIMER_STATUS_CNT_ARR_EVENT_Pos                     1
#define TIMER_STATUS_ETR_RE_EVENT_Pos                      2
#define TIMER_STATUS_ETR_FE_EVENT_Pos                      3
#define TIMER_STATUS_BRK_EVENT_Pos                         4
#define TIMER_STATUS_CCR_CAP_EVENT_Pos                     5
#define TIMER_STATUS_CCR_REF_EVENT_Pos                     9
#define TIMER_STATUS_CCR1_CAP_EVENT_Pos                    13

/* Bit field masks: */
#define TIMER_STATUS_CNT_ZERO_EVENT                        ((uint32_t)0x00000001)
#define TIMER_STATUS_CNT_ARR_EVENT                         ((uint32_t)0x00000002)
#define TIMER_STATUS_ETR_RE_EVENT                          ((uint32_t)0x00000004)
#define TIMER_STATUS_ETR_FE_EVENT                          ((uint32_t)0x00000008)
#define TIMER_STATUS_BRK_EVENT                             ((uint32_t)0x00000010)
#define TIMER_STATUS_CCR_CAP_EVENT_Msk                     ((uint32_t)0x000001E0)
#define TIMER_STATUS_CCR_REF_EVENT_Msk                     ((uint32_t)0x00001E00)
#define TIMER_STATUS_CCR1_CAP_EVENT_Msk                    ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_STATUS */

/** @defgroup Periph_TIMER_IE TIMER IE
  * @{
  */

/*-- TIMER_IE:TIMER IE Register -----*/

/* Bit field positions: */
#define TIMER_IE_CNT_ZERO_EVENT_IE_Pos                     0
#define TIMER_IE_CNT_ARR_EVENT_IE_Pos                      1
#define TIMER_IE_ETR_RE_EVENT_IE_Pos                       2
#define TIMER_IE_ETR_FE_EVENT_IE_Pos                       3
#define TIMER_IE_BRK_EVENT_IE_Pos                          4
#define TIMER_IE_CCR_CAP_EVENT_IE_Pos                      5
#define TIMER_IE_CCR_REF_EVENT_IE_Pos                      9
#define TIMER_IE_CCR1_CAP_EVENT_IE_Pos                     13

/* Bit field masks: */
#define TIMER_IE_CNT_ZERO_EVENT_IE                         ((uint32_t)0x00000001)
#define TIMER_IE_CNT_ARR_EVENT_IE                          ((uint32_t)0x00000002)
#define TIMER_IE_ETR_RE_EVENT_IE                           ((uint32_t)0x00000004)
#define TIMER_IE_ETR_FE_EVENT_IE                           ((uint32_t)0x00000008)
#define TIMER_IE_BRK_EVENT_IE                              ((uint32_t)0x00000010)
#define TIMER_IE_CCR_CAP_EVENT_IE_Msk                      ((uint32_t)0x000001E0)
#define TIMER_IE_CCR_REF_EVENT_IE_Msk                      ((uint32_t)0x00001E00)
#define TIMER_IE_CCR1_CAP_EVENT_IE_Msk                     ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_IE */

/** @defgroup Periph_TIMER_CH_CNTRL2 TIMER CH_CNTRL2
  * @{
  */

/*-- TIMER_CH_CNTRL2:TIMER CH_CNTRL2 Register -----*/

/* Bit field positions: */
#define TIMER_CH_CNTRL2_CHSEL1_Pos                         0
#define TIMER_CH_CNTRL2_CCR1_EN_Pos                        2
#define TIMER_CH_CNTRL2_CCRRLD_Pos                         3

/* Bit field masks: */
#define TIMER_CH_CNTRL2_CHSEL1_Msk                         ((uint32_t)0x00000003)
#define TIMER_CH_CNTRL2_CCR1_EN                            ((uint32_t)0x00000004)
#define TIMER_CH_CNTRL2_CCRRLD                             ((uint32_t)0x00000008)

/** @} */ /* End of group TIMER_CH_CNTRL2 */

/** @defgroup Periph_TIMER_CCR1 TIMER CCR1
  * @{
  */

/*-- TIMER_CCR1:TIMER CCR1 Register -----*/

/* Bit field positions: */
#define TIMER_CCR1_CCR_Pos                                 0

/* Bit field masks: */
#define TIMER_CCR1_CCR_Msk                                 ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_CCR1 */

/** @} */ /* End of group TIMER */


/** @defgroup MDR32F23QI_Periph_PORT PORT
  * @{
  */


/* MDR_PORTx_TypeDef structure */
typedef struct {
    __IO uint32_t   RXTX;                   /*!<PORT Data Register */
    __IO uint32_t   OE;                     /*!<PORT Output Enable Register */
    __IO uint32_t   FUNC;                   /*!<PORT Function Register */
    __IO uint32_t   ANALOG;                 /*!<PORT Analog Function Register */
    __IO uint32_t   PULL;                   /*!<PORT Pull Up/Down Register */
    __IO uint32_t   PD;                     /*!<PORT Driver Mode Register */
    __IO uint32_t   PWR;                    /*!<PORT Power Register */
    __IO uint32_t   GFEN;                   /*!<PORT Filter Configuration Register */
    __IO uint32_t   SETTX;                  /*!<PORT Set output data */
    __IO uint32_t   CLRTX;                  /*!<PORT Reset output data */
    __IO uint32_t   RDTX;                   /*!<PORT Read Output Register */
}MDR_PORT_TypeDef;

/** @defgroup Periph_PORT_RXTX PORT RXTX
  * @{
  */

/*-- PORT_RXTX:PORT RXTX Register -----*/

/* Bit field positions: */
#define PORT_RXTX_RXTX_Pos                                 0

/* Bit field masks: */
#define PORT_RXTX_RXTX_Msk                                 ((uint32_t)0x0000FFFF)

/** @} */ /* End of group PORT_RXTX */

/** @defgroup Periph_PORT_OE PORT OE
  * @{
  */

/*-- PORT_OE:PORT OE Register -----*/

/* Bit field positions: */
#define PORT_OE_OE_Pos                                     0

/* Bit field masks: */
#define PORT_OE_OE_Msk                                     ((uint32_t)0x0000FFFF)

/** @} */ /* End of group PORT_OE */

/** @defgroup Periph_PORT_FUNC PORT FUNC
  * @{
  */

/*-- PORT_FUNC:PORT FUNC Register -----*/

/* Bit field positions: */
#define PORT_FUNC_MODE0_Pos                                0
#define PORT_FUNC_MODE1_Pos                                2
#define PORT_FUNC_MODE2_Pos                                4
#define PORT_FUNC_MODE3_Pos                                6
#define PORT_FUNC_MODE4_Pos                                8
#define PORT_FUNC_MODE5_Pos                                10
#define PORT_FUNC_MODE6_Pos                                12
#define PORT_FUNC_MODE7_Pos                                14
#define PORT_FUNC_MODE8_Pos                                16
#define PORT_FUNC_MODE9_Pos                                18
#define PORT_FUNC_MODE10_Pos                               20
#define PORT_FUNC_MODE11_Pos                               22
#define PORT_FUNC_MODE12_Pos                               24
#define PORT_FUNC_MODE13_Pos                               26
#define PORT_FUNC_MODE14_Pos                               28
#define PORT_FUNC_MODE15_Pos                               30

/* Bit field masks: */
#define PORT_FUNC_MODE0_Msk                                ((uint32_t)0x00000003)
#define PORT_FUNC_MODE1_Msk                                ((uint32_t)0x0000000C)
#define PORT_FUNC_MODE2_Msk                                ((uint32_t)0x00000030)
#define PORT_FUNC_MODE3_Msk                                ((uint32_t)0x000000C0)
#define PORT_FUNC_MODE4_Msk                                ((uint32_t)0x00000300)
#define PORT_FUNC_MODE5_Msk                                ((uint32_t)0x00000C00)
#define PORT_FUNC_MODE6_Msk                                ((uint32_t)0x00003000)
#define PORT_FUNC_MODE7_Msk                                ((uint32_t)0x0000C000)
#define PORT_FUNC_MODE8_Msk                                ((uint32_t)0x00030000)
#define PORT_FUNC_MODE9_Msk                                ((uint32_t)0x000C0000)
#define PORT_FUNC_MODE10_Msk                               ((uint32_t)0x00300000)
#define PORT_FUNC_MODE11_Msk                               ((uint32_t)0x00C00000)
#define PORT_FUNC_MODE12_Msk                               ((uint32_t)0x03000000)
#define PORT_FUNC_MODE13_Msk                               ((uint32_t)0x0C000000)
#define PORT_FUNC_MODE14_Msk                               ((uint32_t)0x30000000)
#define PORT_FUNC_MODE15_Msk                               ((uint32_t)0xC0000000)

/** @} */ /* End of group PORT_FUNC */

/** @defgroup Periph_PORT_ANALOG PORT ANALOG
  * @{
  */

/*-- PORT_ANALOG:PORT ANALOG Register -----*/

/* Bit field positions: */
#define PORT_ANALOG_ANALOG_EN_Pos                          0

/* Bit field masks: */
#define PORT_ANALOG_ANALOG_EN_Msk                          ((uint32_t)0x0000FFFF)

/** @} */ /* End of group PORT_ANALOG */

/** @defgroup Periph_PORT_PULL PORT PULL
  * @{
  */

/*-- PORT_PULL:PORT PULL Register -----*/

/* Bit field positions: */
#define PORT_PULL_PULL_DOWN_Pos                            0
#define PORT_PULL_PULL_UP_Pos                              16

/* Bit field masks: */
#define PORT_PULL_PULL_DOWN_Msk                            ((uint32_t)0x0000FFFF)
#define PORT_PULL_PULL_UP_Msk                              ((uint32_t)0xFFFF0000)

/** @} */ /* End of group PORT_PULL */

/** @defgroup Periph_PORT_PD PORT PD
  * @{
  */

/*-- PORT_PD:PORT PD Register -----*/

/* Bit field positions: */
#define PORT_PD_PD_Pos                                     0
#define PORT_PD_SHM_Pos                                    16

/* Bit field masks: */
#define PORT_PD_PD_Msk                                     ((uint32_t)0x0000FFFF)
#define PORT_PD_SHM_Msk                                    ((uint32_t)0xFFFF0000)

/** @} */ /* End of group PORT_PD */

/** @defgroup Periph_PORT_PWR PORT PWR
  * @{
  */

/*-- PORT_PWR:PORT PWR Register -----*/

/* Bit field positions: */
#define PORT_PWR_PWR0_Pos                                  0
#define PORT_PWR_PWR1_Pos                                  2
#define PORT_PWR_PWR2_Pos                                  4
#define PORT_PWR_PWR3_Pos                                  6
#define PORT_PWR_PWR4_Pos                                  8
#define PORT_PWR_PWR5_Pos                                  10
#define PORT_PWR_PWR6_Pos                                  12
#define PORT_PWR_PWR7_Pos                                  14
#define PORT_PWR_PWR8_Pos                                  16
#define PORT_PWR_PWR9_Pos                                  18
#define PORT_PWR_PWR10_Pos                                 20
#define PORT_PWR_PWR11_Pos                                 22
#define PORT_PWR_PWR12_Pos                                 24
#define PORT_PWR_PWR13_Pos                                 26
#define PORT_PWR_PWR14_Pos                                 28
#define PORT_PWR_PWR15_Pos                                 30

/* Bit field masks: */
#define PORT_PWR_PWR0_Msk                                  ((uint32_t)0x00000003)
#define PORT_PWR_PWR1_Msk                                  ((uint32_t)0x0000000C)
#define PORT_PWR_PWR2_Msk                                  ((uint32_t)0x00000030)
#define PORT_PWR_PWR3_Msk                                  ((uint32_t)0x000000C0)
#define PORT_PWR_PWR4_Msk                                  ((uint32_t)0x00000300)
#define PORT_PWR_PWR5_Msk                                  ((uint32_t)0x00000C00)
#define PORT_PWR_PWR6_Msk                                  ((uint32_t)0x00003000)
#define PORT_PWR_PWR7_Msk                                  ((uint32_t)0x0000C000)
#define PORT_PWR_PWR8_Msk                                  ((uint32_t)0x00030000)
#define PORT_PWR_PWR9_Msk                                  ((uint32_t)0x000C0000)
#define PORT_PWR_PWR10_Msk                                 ((uint32_t)0x00300000)
#define PORT_PWR_PWR11_Msk                                 ((uint32_t)0x00C00000)
#define PORT_PWR_PWR12_Msk                                 ((uint32_t)0x03000000)
#define PORT_PWR_PWR13_Msk                                 ((uint32_t)0x0C000000)
#define PORT_PWR_PWR14_Msk                                 ((uint32_t)0x30000000)
#define PORT_PWR_PWR15_Msk                                 ((uint32_t)0xC0000000)

/** @} */ /* End of group PORT_PWR */

/** @defgroup Periph_PORT_GFEN PORT GFEN
  * @{
  */

/*-- PORT_GFEN:PORT GFEN Register -----*/

/* Bit field positions: */
#define PORT_GFEN_GFEN_Pos                                 0

/* Bit field masks: */
#define PORT_GFEN_GFEN_Msk                                 ((uint32_t)0x0000FFFF)

/** @} */ /* End of group PORT_GFEN */

/** @} */ /* End of group PORT */


/** @defgroup MDR32F23QI_Periph_LCD LCD
  * @{
  */
  
  /* MDR_LCD_TypeDef structure */
typedef struct {
    __IO uint32_t   CR;                   /*!<LCD Control Register */
    __IO uint32_t   ROW1;                 /*!<LCD Data main memory Output BP0 */
    __IO uint32_t   ROW2;                 /*!<LCD Data main memory Output BP1 */
    __IO uint32_t   ROW3;                 /*!<LCD Data main memory Output BP2 */
    __IO uint32_t   ROW4;                 /*!<LCD Data main memory Output BP3 */
    __IO uint32_t   AROW1;                /*!<LCD Data alter memory Output BP3 */
    __IO uint32_t   AROW2;                /*!<LCD Data alter memory Output BP3 */
    __IO uint32_t   AROW3;                /*!<LCD Data alter memory Output BP3 */
    __IO uint32_t   AROW4;                /*!<LCD Data alter memory Output BP3 */
}MDR_LCD_TypeDef;


  /** @defgroup Periph_LCD_CR LCD CR
  * @{
  */

/*-- LCD_CR:LCD CR Register -----*/

/* Bit field positions: */
#define LCD_CR_M_Pos                                    0
#define LCD_CR_B_Pos                                    2
#define LCD_CR_E_Pos                                    3
#define LCD_CR_BF_Pos                                   4
#define LCD_A_Pos                                       6
#define LCD_CR_VLCDON_Pos                               7
#define LCD_CR_DIV_Pos                                  8
#define LCD_CR_CLK_SEL_Pos                              24

/* Bit field masks: */
#define LCD_CR_M_Msk                                   ((uint32_t)0x00000003)
#define LCD_CR_B_Msk                                   ((uint32_t)0x00000004)
#define LCD_CR_E_Msk                                   ((uint32_t)0x00000008)
#define LCD_CR_BF_Msk                                  ((uint32_t)0x00000030)
#define LCD_CR_A_Msk                                   ((uint32_t)0x00000040)
#define LCD_CR_VLCDON_Msk                              ((uint32_t)0x00000080)
#define LCD_CR_DIV_Msk                                 ((uint32_t)0x00FFFF00)
#define LCD_CR_CLK_SEL_Msk                             ((uint32_t)0x01000000)

/** @} */ /* End of group LCD_CR*/

  /** @defgroup Periph_LCD_ROW1 LCD ROW1
  * @{
  */

/*-- LCD_ROW1:LCD ROW1 Register -----*/

/* Bit field positions: */
#define LCD_ROW1_S_Pos                                 0

/* Bit field masks: */
#define LCD_ROW1_S_Msk                                 ((uint32_t)0x3FFFFFFF)

/** @} */ /* End of group LCD_ROW1*/

  /** @defgroup Periph_LCD_ROW2 LCD ROW2
  * @{
  */

/*-- LCD_ROW2:LCD ROW2 Register -----*/

/* Bit field positions: */
#define LCD_ROW2_S_Pos                                 0

/* Bit field masks: */
#define LCD_ROW2_S_Msk                                 ((uint32_t)0x3FFFFFFF)

/** @} */ /* End of group LCD_ROW2*/

  /** @defgroup Periph_LCD_ROW3 LCD ROW3
  * @{
  */

/*-- LCD_ROW3:LCD ROW3 Register -----*/

/* Bit field positions: */
#define LCD_ROW3_S_Pos                                 0

/* Bit field masks: */
#define LCD_ROW3_S_Msk                                 ((uint32_t)0x3FFFFFFF)

/** @} */ /* End of group LCD_ROW3*/

  /** @defgroup Periph_LCD_ROW3 LCD ROW3
  * @{
  */

/*-- LCD_ROW4:LCD ROW4 Register -----*/

/* Bit field positions: */
#define LCD_ROW4_S_Pos                                 0

/* Bit field masks: */
#define LCD_ROW4_S_Msk                                 ((uint32_t)0x3FFFFFFF)

/** @} */ /* End of group LCD_ROW4*/

  /** @defgroup Periph_LCD_AROW1 LCD AROW1
  * @{
  */

/*-- LCD_AROW1:LCD AROW1 Register -----*/

/* Bit field positions: */
#define LCD_AROW1_S_Pos                                 0

/* Bit field masks: */
#define LCD_AROW1_S_Msk                                 ((uint32_t)0x3FFFFFFF)

/** @} */ /* End of group LCD_AROW1*/

  /** @defgroup Periph_LCD_AROW1 LCD AROW1
  * @{
  */

/*-- LCD_AROW2:LCD AROW2 Register -----*/

/* Bit field positions: */
#define LCD_AROW2_S_Pos                                 0

/* Bit field masks: */
#define LCD_AROW2_S_Msk                                 ((uint32_t)0x3FFFFFFF)

/** @} */ /* End of group LCD_AROW2*/

  /** @defgroup Periph_LCD_AROW1 LCD AROW1
  * @{
  */

/*-- LCD_AROW3:LCD AROW3 Register -----*/

/* Bit field positions: */
#define LCD_AROW3_S_Pos                                 0

/* Bit field masks: */
#define LCD_AROW3_S_Msk                                 ((uint32_t)0x3FFFFFFF)

/** @} */ /* End of group LCD_AROW3*/

/** @} */ /* End of group LCD */

/** @defgroup MDR32F23QI_Periph_I2C I2C
  * @{
  */

/* MDR_I2C_TypeDef structure */
typedef struct
{
  __IO uint32_t PRL;
  __IO uint32_t PRH;
  __IO uint32_t CTR;
  __IO uint32_t RXD;
  __IO uint32_t STA;
  __IO uint32_t TXD;
  __IO uint32_t CMD;
}MDR_I2C_TypeDef;


/** @defgroup Periph_I2C_CTR    I2C CTR
  * @{
  */ 

/*-- I2C_CTR: I2C Control Register ---------------------------------*/
/* Bit field positions: */
#define I2C_CTR_S_I2C_Pos                       5
#define I2C_CTR_EN_INT_Pos                      6
#define I2C_CTR_EN_I2C_Pos                      7

/* Bit field masks: */
#define I2C_CTR_S_I2C                           ((uint32_t)0x00000020)
#define I2C_CTR_EN_INT                          ((uint32_t)0x00000040)
#define I2C_CTR_EN_I2C                          ((uint32_t)0x00000080)

/** @} */ /* End of group I2C_CTR */

/** @defgroup Periph_I2C_STA    I2C STA
  * @{
  */ 

/*-- I2C_STA: I2C Status Register ----------------------------------*/
/* Bit field positions: */
#define I2C_STA_INT_Pos                         0
#define I2C_STA_TR_PROG_Pos                     1
#define I2C_STA_LOST_ARB_Pos                    5
#define I2C_STA_BUSY_Pos                        6
#define I2C_STA_RX_ACK_Pos                      7

/* Bit field masks: */
#define I2C_STA_INT                             ((uint32_t)0x00000001)
#define I2C_STA_TR_PROG                         ((uint32_t)0x00000002)
#define I2C_STA_LOST_ARB                        ((uint32_t)0x00000020)
#define I2C_STA_BUSY                            ((uint32_t)0x00000040)
#define I2C_STA_RX_ACK                          ((uint32_t)0x00000080)

/** @} */ /* End of group I2C_STA */

/** @defgroup Periph_I2C_CMD    I2C CMD
  * @{
  */ 

/*-- I2C_CMD: I2C Command Register ---------------------------------*/
/* Bit field positions: */
#define I2C_CMD_CLRINT_Pos                      0
#define I2C_CMD_ACK_Pos                         3
#define I2C_CMD_WR_Pos                          4
#define I2C_CMD_RD_Pos                          5
#define I2C_CMD_STOP_Pos                        6
#define I2C_CMD_START_Pos                       7

/* Bit field masks: */
#define I2C_CMD_CLRINT                          ((uint32_t)0x00000001)
#define I2C_CMD_ACK                             ((uint32_t)0x00000008)
#define I2C_CMD_WR                              ((uint32_t)0x00000010)
#define I2C_CMD_RD                              ((uint32_t)0x00000020)
#define I2C_CMD_STOP                            ((uint32_t)0x00000040)
#define I2C_CMD_START                           ((uint32_t)0x00000080)

/** @} */ /* End of group I2C_CMD */

/** @} */ /* End of group MDR32F23QI_Periph_I2C */


/** @defgroup __Peripheral_Memory_Map Peripheral Memory Map
  * @{
  */

#define MDR_SSP1_BASE                   (0x40000000)
#define MDR_UART0_BASE                 (0x40008000)
#define MDR_UART1_BASE                 (0x40010000)
#define MDR_EEPROM_BASE                (0x40018000)
#define MDR_RST_CLK_BASE               (0x40020000)
#define MDR_I2C_BASE                   (0x40030000)
#define MDR_LCD_BASE                   (0x40038000)
#define MDR_ADC_BASE                   (0x40040000)
#define MDR_WWDG_BASE                  (0x40048000)
#define MDR_IWDG_BASE                  (0x40050000)
#define MDR_POWER_BASE                 (0x40058000)
#define MDR_BKP_BASE                   (0x40060000)
#define MDR_ADCIU_BASE                 (0x40068000)
#define MDR_TIMER0_BASE                (0x40070000)
#define MDR_TIMER1_BASE                (0x40078000)
#define MDR_PORTA_BASE                 (0x40080000)
#define MDR_PORTB_BASE                 (0x40088000)
#define MDR_PORTC_BASE                 (0x40090000)

/** @} */ /* End of group __Peripheral_Memory_Map */

/** @defgroup __Peripheral_declaration Peripheral declaration
  * @{
  */

#define MDR_SSP1                        ((MDR_SSP_TypeDef    *) MDR_SSP1_BASE)
#define MDR_UART0                      ((MDR_UART_TypeDef   *) MDR_UART0_BASE)
#define MDR_UART1                      ((MDR_UART_TypeDef   *) MDR_UART1_BASE)
#define MDR_EEPROM                     ((MDR_EEPROM_TypeDef *) MDR_EEPROM_BASE)
#define MDR_RST_CLK                    ((MDR_RST_CLK_TypeDef*) MDR_RST_CLK_BASE)
#define MDR_I2C                        ((MDR_I2C_TypeDef    *) MDR_I2C_BASE)
#define MDR_LCD                        ((MDR_LCD_TypeDef    *) MDR_LCD_BASE)
#define MDR_ADC                        ((MDR_ADC_TypeDef    *) MDR_ADC_BASE)
#define MDR_WWDG                       ((MDR_WWDG_TypeDef   *) MDR_WWDG_BASE)
#define MDR_IWDG                       ((MDR_IWDG_TypeDef   *) MDR_IWDG_BASE)
#define MDR_POWER                      ((MDR_POWER_TypeDef  *) MDR_POWER_BASE)
#define MDR_BKP                        ((MDR_BKP_TypeDef    *) MDR_BKP_BASE)
#define MDR_ADCIU                      ((MDR_ADCIU_TypeDef  *) MDR_ADCIU_BASE)
#define MDR_TIMER0                     ((MDR_TIMER_TypeDef  *) MDR_TIMER0_BASE)
#define MDR_TIMER1                     ((MDR_TIMER_TypeDef  *) MDR_TIMER1_BASE)
#define MDR_PORTA                      ((MDR_PORT_TypeDef   *) MDR_PORTA_BASE)
#define MDR_PORTB                      ((MDR_PORT_TypeDef   *) MDR_PORTB_BASE)
#define MDR_PORTC                      ((MDR_PORT_TypeDef   *) MDR_PORTC_BASE)


/** @} */ /* End of group __Peripheral_declaration */

#ifdef __cplusplus
}
#endif

/** @} */ /* End of group __MDR32F23QI_Peripheral */

/** @} */ /* End of group MDR32F23QI */

/** @} */ /* End of group __CMSIS */

#endif /* __MDR32F23QI_H */

/*
*
* END OF FILE MDR32F23QI.h */
