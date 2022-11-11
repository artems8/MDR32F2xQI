/**
  ******************************************************************************
  * @file    MDR32F23QI_lcd.h
  * @author  Milandr Application Team
  * @version V1.0.0
  * @date    10/11/2022
  * @brief   This file contains all the functions prototypes for the I2C
  *          firmware library.
  ******************************************************************************
  * <br><br>
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MILANDR SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
  * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT {YYYY} Milandr</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F23QI_LCD_H
#define __MDR32F23QI_LCD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F2xQI_config.h"

/** @addtogroup __MDR32F23QI_StdPeriph_Driver MDR32F23QI Standard Peripherial Driver
  * @{
  */

/** @addtogroup LCD
  * @{
  */

/** @defgroup LCD_Exported_Types LCD Exported Types
  * @{
  */

/**
  * @brief LCD Control circuit
  */
  
typedef enum 
{
    LCD_MultPlex_S   = ((uint32_t)0x00),
    LCD_MultPlex_2   = ((uint32_t)0x01),
    LCD_MultPlex_3   = ((uint32_t)0x02),
    LCD_MultPlex_4   = ((uint32_t)0x03)
} LCD_MultPlex_TypeDef;

#define IS_LCD_CONTROL_MUX(MUX)  (((MUX) == LCD_MultPlex_S  ) || \
                                 ((MUX) == LCD_MultPlex_2  ) || \
                                 ((MUX) == LCD_MultPlex_3  ) || \
                                 ((MUX) == LCD_MultPlex_4  ))


/**
  * @brief LCD Bias mode
  */

typedef enum 
{
    LCD_MultBias_3   = ((uint32_t)0x00),
    LCD_MultBias_2   = ((uint32_t)0x01)
} LCD_MultBias_TypeDef;

#define IS_LCD_BIAS(BIAS)        (((BIAS) == LCD_MultBias_3  ) || \
                                 ((BIAS) == LCD_MultBias_2  ))


/**
  * @brief LCD Blink mode
  */
typedef enum 
{
    LCD_Blink_Off   = ((uint32_t)0x00),
    LCD_Blink_2Hz   = ((uint32_t)0x01),
    LCD_Blink_1Hz   = ((uint32_t)0x02),
    LCD_Blink_0Hz5  = ((uint32_t)0x03)
} LCD_BlinkFreq_TypeDef;

#define IS_LCD_BLINK_FREQ(FREQ)  (((FREQ) == LCD_Blink_Off  ) || \
                                 ((FREQ) == LCD_Blink_2Hz  ) || \
                                 ((FREQ) == LCD_Blink_1Hz  ) || \
                                 ((FREQ) == LCD_Blink_0Hz5  ))


/**
  * @brief LCD Circuit select
  */
typedef enum 
{
    LCD_Main_Circuit = ((uint32_t)0x00),
    LCD_Alt_Circuit  = ((uint32_t)0x01)
} LCD_Circuit_TypeDef;

#define IS_LCD_CIRCUIT(CIR)     (((CIR) == LCD_Main_Circuit  ) || \
                                ((CIR) == LCD_Alt_Circuit  ))
/**
  * @brief LCD Vlcd select
  */
typedef enum 
{
    LCD_VLCD_Internal  = ((uint32_t)0x00),
    LCD_VLCD_External  = ((uint32_t)0x01)
} LCD_VLCD_TypeDef;

#define IS_LCD_VLCD(VLCD)       (((VLCD) == LCD_VLCD_Internal  ) || \
                                ((VLCD) == LCD_VLCD_External  ))

/**
  * @brief LCD Clock select
  */
typedef enum 
{
    LCD_CLK_LSE = ((uint32_t)0x00),
    LCD_CLK_LSI = ((uint32_t)0x01)
} LCD_CLK_TypeDef;

#define IS_LCD_CLK(LCK)         (((VLCD) == LCD_CLK_LSE  ) || \
                                ((VLCD) == LCD_CLK_LSI  ))

/**
  * @brief LCD Sreen Data definition
  */
  
typedef struct {

    uint32_t SegmCom0;
    uint32_t SegmCom1;
    uint32_t SegmCom2;
    uint32_t SegmCom3;
} LCD_SreenData;

/**
  * @brief  LCD Init Structure definition
  */
typedef struct
{
    LCD_MultPlex_TypeDef               LCD_MUX;          /*!< Specifies PORT pins to be configured.
                                                              This parameter can be a value of @ref LCD_MultPlex_TypeDef values. */
    LCD_MultBias_TypeDef               LCD_Bias;         /*!< Specifies PORT pins to be configured.
                                                              This parameter can be a value of @ref LCD_MultBias_TypeDef values. */
    LCD_BlinkFreq_TypeDef              LCD_BF_Freq;      /*!< Specifies PORT pins to be configured.
                                                              This parameter can be a value of @ref LCD_BlinkFreq_TypeDef values. */
    LCD_Circuit_TypeDef                LCD_A;            /*!< Specifies PORT pins to be configured.
                                                              This parameter can be a value of @ref LCD_Circuit_TypeDef values. */
    LCD_VLCD_TypeDef                   LCD_VLCDON;       /*!< Specifies PORT pins to be configured.
                                                              This parameter can be a value of @ref LCD_VLCD_TypeDef values. */
    uint16_t                           LCD_DIV;          /*!< Specifies PORT pins to be configured.
                                                              This parameter can be a number between 0x0000 and 0xFFFF.*/
    LCD_CLK_TypeDef                    LCD_CLK;          /*!< Specifies PORT pins to be configured.
                                                              This parameter can be a value of @ref LCD_CLK_TypeDef values. */
} LCD_InitTypeDef;

/** @} */ /* End of group LCD_Exported_Types */

/** @defgroup LCD_Exported_Functions LCD Exported Functions
  * @{
  */
void LCD_DeInit(void);
void LCD_SetScreen(LCD_SreenData *pData);
void LCD_SetScreenAlt(LCD_SreenData *pData);
void LCD_StructInit(LCD_InitTypeDef * LCD_InitStruct);
void LCD_Init (const LCD_InitTypeDef* LCD_InitStruct);
void LCD_Cmd(FunctionalState NewState);


/** @} */ /* End of group LCD_Exported_Functions */

/** @} */ /* End of group LCD */

/** @} */ /* End of group __MDR32F23QI_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F23QI_LCD_H */

/*********************** (C) COPYRIGHT {YYYY} Milandr ****************************
*
* END OF FILE MDR32F23QI_lcd.h */

