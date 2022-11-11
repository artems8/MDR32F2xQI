/**
  ******************************************************************************
  * @file    MDR32F23QI_lcd.c
  * @author  Milandr Application Team
  * @version V1.0.0
  * @date    11/11/2022
  * @brief   This file contains all the RST_CLK firmware functions.
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

/* Includes ------------------------------------------------------------------*/
#include "MDR32F23QI_lcd.h"

/** @addtogroup __MDR32F23QI_StdPeriph_Driver MDR1986BE4 Standard Peripherial Driver
  * @{
  */

/** @addtogroup LCD LCD
  * @{
  */



/** @defgroup LCD_Private_Defines LCD Private Defines
  * @{
  */  
  
#define IS_LCD_DIV(DIV)                   ((DIV) <= 0xFFFF)

/** @} */ /* End of group LCD_Private_Defines */  

/** @defgroup LCD_Private_Functions LCD Private Functions
  * @{
  */
/**
  * @brief  Resets the LCD peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */

void LCD_DeInit(void)
{
  MDR_LCD->CR = 0;
  MDR_LCD->ROW1 = 0;
  MDR_LCD->ROW2 = 0;
  MDR_LCD->ROW3 = 0;
  MDR_LCD->ROW4 = 0;
  MDR_LCD->AROW1 = 0;
  MDR_LCD->AROW2 = 0;
  MDR_LCD->AROW3 = 0;
  MDR_LCD->AROW4 = 0;
}

/**
  * @brief  Set main memory data the LCD peripheral of the BP0-3 outputs.
  * @param  pData: Pointer  @ref LCD_SreenData to structure from data rows.
  * @retval None.
  */
void LCD_SetScreen(LCD_SreenData *pData)
{
  MDR_LCD->ROW1 = pData->SegmCom0;
  MDR_LCD->ROW2 = pData->SegmCom1;
  MDR_LCD->ROW3 = pData->SegmCom2;
  MDR_LCD->ROW4 = pData->SegmCom3;  
}

/**
  * @brief  Set a alternative memory data the LCD peripheral of the BP0-3 outputs.
  * @param  pData: Pointer  @ref LCD_SreenData to structure from data rows.
  * @retval None.
  */
void LCD_SetScreenAlt(LCD_SreenData *pData)
{
  MDR_LCD->AROW1 = pData->SegmCom0;
  MDR_LCD->AROW2 = pData->SegmCom1;
  MDR_LCD->AROW3 = pData->SegmCom2;
  MDR_LCD->AROW4 = pData->SegmCom3;
}

/**
  * @brief  Fills each LCD_InitStruct member with its default value.
  * @param  SPW_InitStruct: pointer to a @ref LCD_InitStruct structure which will be initialized.
  * @retval None
  */
void LCD_StructInit(LCD_InitTypeDef * LCD_InitStruct)
{
    /* General config */
    LCD_InitStruct->LCD_MUX     = LCD_MultPlex_S;
    LCD_InitStruct->LCD_Bias    = LCD_MultBias_3;
    LCD_InitStruct->LCD_BF_Freq = LCD_Blink_Off;
    LCD_InitStruct->LCD_A       = LCD_Main_Circuit;
    LCD_InitStruct->LCD_VLCDON  = LCD_VLCD_Internal;
    LCD_InitStruct->LCD_DIV     =0;
    LCD_InitStruct->LCD_CLK     = LCD_CLK_LSE;
    
}

/**
  * @brief  Initializes the LCD peripheral according to the specified
  *         parameters in the LCD_InitStruct.
  * @param  LCD_InitStruct: pointer to a LCD_InitTypeDef structure
  *         that contains the configuration information for the specified LCD peripheral.
  * @retval None
  */
void LCD_Init (const LCD_InitTypeDef* LCD_InitStruct)
{
    uint32_t tmpreg_CR;
    
    /* Check the parameters */
    assert_param(IS_LCD_CONTROL_MUX(LCD_InitStruct->LCD_MUX));
    assert_param(IS_LCD_BIAS(LCD_InitStruct->LCD_Bias));
    assert_param(IS_LCD_BLINK_FREQ(LCD_InitStruct->LCD_BF_Freq));
    assert_param(IS_LCD_CIRCUIT(LCD_InitStruct->LCD_A));
    assert_param(IS_LCD_VLCD(LCD_InitStruct->LCD_VLCDON));
    assert_param(IS_LCD_CIRCUIT(LCD_InitStruct->LCD_A));
    assert_param(IS_LCD_DIV(LCD_InitStruct->DIV));
    assert_param(IS_LCD_CLK(CD_InitStruct->LCD_CLK ));
    
    /* Config the LCD control register */
    tmpreg_CR = (LCD_InitStruct->LCD_MUX << LCD_CR_M_Pos)
                   | (LCD_InitStruct->LCD_Bias << LCD_CR_B_Pos)
                   | (LCD_InitStruct->LCD_BF_Freq << LCD_CR_BF_Pos)
                   | (LCD_InitStruct->LCD_A << LCD_A_Pos)
                   | (LCD_InitStruct->LCD_VLCDON << LCD_CR_VLCDON_Pos)
                   | (LCD_InitStruct->LCD_DIV << LCD_CR_DIV_Pos)
                   | (LCD_InitStruct->LCD_CLK << LCD_CR_CLK_SEL_Pos);
    
    MDR_LCD->CR = tmpreg_CR;
}

/**
  * @brief  Enables or disables the specified LCD peripheral.
  * @param  NewState - @ref FunctionalState - new state of the LCD peripheral.
  * @retval None.
  */
void LCD_Cmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if(NewState != DISABLE)
    {
        MDR_LCD->CR |= LCD_CR_E_Msk;
    }
    else
    {
        MDR_LCD->CR &= ~LCD_CR_E_Msk;
    }
}

/** @} */ /* End of group LCD_Private_Functions */

/** @} */ /* End of group LCD */

/** @} */ /* End of group __MDR32F23QI_StdPeriph_Driver */

/*********************** (C) COPYRIGHT {YYYY} Milandr ****************************
*
* END OF FILE MDR32F23QI_lcd.c */


