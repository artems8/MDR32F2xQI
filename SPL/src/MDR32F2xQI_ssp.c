/**
  ******************************************************************************
  * @file    MDR32F2xQI_ssp.c
  * @author  Milandr Application Team
  * @version V1.0.0
  * @date    03/11/2022
  * @brief   This file contains all the SSP firmware functions.
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
#include "MDR32F2xQI_ssp.h"

/** @addtogroup __MDR32F2xQI_StdPeriph_Driver MDR32F2xQI Standard Peripherial Driver
  * @{
  */

/** @defgroup SSP SSP
  * @{
  */

/** @defgroup SSP_Private_Defines SSP Private Defines
  * @{
  */

#define CR1_EN_Set                  ((uint16_t)0x0002)  /*!< SSP Enable Mask */
#define CR1_EN_Reset                ((uint16_t)0xFFFD)  /*!< SSP Disable Mask */

/** @} */ /* End of group SSP_Private_Defines */


/** @defgroup SSP_Private_Functions SSP Private Functions
  * @{
  */

/**
  * @brief  Resets the SSPx peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void SSP_DeInit(void)
{
    MDR_SSP1->CR0   = 0;
    MDR_SSP1->CR1   = 0;
    MDR_SSP1->CPSR  = 0;
    MDR_SSP1->IMSC  = 0;
#if defined (USE_MDR32F21QI)
    MDR_SSP1->DMACR = 0;
#endif

    /* Clear SSP ICR[RTIC] and SSP ICR[RORIC] bits */
    MDR_SSP1->ICR = SSP_IT_RT | SSP_IT_ROR;
}

/**
  * @brief  Initializes the SSPx peripheral according to the specified
  *         parameters in the SSP_InitStruct.
  * @param  SSP_InitStruct: pointer to a @ref SSP_InitTypeDef structure
  *         that contains the configuration information for the specified SSP peripheral.
  * @retval None
  */
void SSP_Init(const SSP_InitTypeDef* SSP_InitStruct)
{
    uint32_t tmpreg;

    /* Check the parameters */
    assert_param(IS_SSP_SPEED_FACTOR(SSP_InitStruct->SSP_SCR));
    assert_param(IS_SSP_SPEED_DIVIDER(SSP_InitStruct->SSP_CPSDVSR));
    assert_param(IS_SSP_MODE(SSP_InitStruct->SSP_Mode));
    assert_param(IS_SSP_WORD_LENGTH(SSP_InitStruct->SSP_WordLength));
    assert_param(IS_SSP_SPH(SSP_InitStruct->SSP_SPH));
    assert_param(IS_SSP_SPO(SSP_InitStruct->SSP_SPO));
    assert_param(IS_SSP_FRF(SSP_InitStruct->SSP_FRF));
    assert_param(IS_SSP_HARDWARE_FLOW_CONTROL(SSP_InitStruct->SSP_HardwareFlowControl));

    /* SSP1 CPSR Configuration */
    MDR_SSP1->CPSR = SSP_InitStruct->SSP_CPSDVSR;

    /* SSP1 CR0 Configuration */
    tmpreg = (SSP_InitStruct->SSP_SCR << SSP_CR0_SCR_Pos)
            + SSP_InitStruct->SSP_SPH
            + SSP_InitStruct->SSP_SPO
            + SSP_InitStruct->SSP_FRF
            + SSP_InitStruct->SSP_WordLength;
    MDR_SSP1->CR0 = tmpreg;

    /* SSP1 CR1 Configuration */
    tmpreg = SSP_InitStruct->SSP_HardwareFlowControl + SSP_InitStruct->SSP_Mode;
    MDR_SSP1->CR1 = tmpreg;
}

/**
  * @brief  Fills each SSP_InitStruct member with its default value.
  * @param  SSP_InitStruct: pointer to a @ref SSP_InitTypeDef structure
  *         that is to be initialized.
  * @retval None
  */
void SSP_StructInit(SSP_InitTypeDef* SSP_InitStruct)
{
    /* SSP_InitStruct members default value */
    /* Initialize the SSP max speed */
    SSP_InitStruct->SSP_SCR = 0;
    SSP_InitStruct->SSP_CPSDVSR = 2;
    /* Initialize the SPI_Mode member */
    SSP_InitStruct->SSP_Mode = SSP_ModeMaster;
    /* initialize the SSP_WordLength member */
    SSP_InitStruct->SSP_WordLength = SSP_WordLength8b;
    /* Initialize the SSP_SPH member */
    SSP_InitStruct->SSP_SPH = SSP_SPH_1Edge;
    /* Initialize the SSP_SPO member */
    SSP_InitStruct->SSP_SPO = SSP_SPO_Low;
    /* Initialize the SSP_FRF member */
    SSP_InitStruct->SSP_FRF = SSP_FRF_SPI_Motorola;
    /* Initialize the hardware flow control */
    SSP_InitStruct->SSP_HardwareFlowControl = SSP_HardwareFlowControl_None;
}

/**
  * @brief  Enables or disables the specified SSP peripheral.
  * @param  NewState - @ref FunctionalState - new state of the SSPx peripheral.
  * @retval None
  */
void SSP_Cmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the selected SSP by setting the SSE bit in the CR1 register */
        MDR_SSP1->CR1 |= CR1_EN_Set;
    }
    else
    {
        /* Disable the selected SSP by clearing the SSE bit in the CR1 register */
        MDR_SSP1->CR1 &= CR1_EN_Reset;
    }
}

/**
  * @brief  Enables or disables the specified SSP interrupts.
  * @param  SSP_IT: specifies the SSP interrupt sources to be enabled or disabled.
  *         This parameter can be any combination of @ref SSP_IT_TypeDef values.
  * @param  NewState - @ref FunctionalState - new state of the specified SSPx interrupts.
  * @retval None
  */
void SSP_ITConfig(uint32_t SSP_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SSP_CONFIG_IT(SSP_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        MDR_SSP1->IMSC |= SSP_IT;
    }
    else
    {
        MDR_SSP1->IMSC &= ~SSP_IT;
    }
}

/**
  * @brief  Checks whether the specified SSP interrupt has occurred or not.
  * @param  SSP_IT - @ref SSP_IT_TypeDef - specifies the SSP interrupt source to check.
  * @retval @ref ITStatus - The state of SSP_IT (SET or RESET).
  */
ITStatus SSP_GetITStatus(SSP_IT_TypeDef SSP_IT)

{
    ITStatus bitstatus;

    /* Check the parameters */
    assert_param(IS_SSP_CONFIG_IT(SSP_IT));

    if ( (MDR_SSP1->RIS & SSP_IT) == SSP_IT)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return (bitstatus);
}

/**
  * @brief  Checks whether the specified SSP interrupt (masked) has occurred or not.
  * @param  SSP_IT - @ref SSP_IT_TypeDef - specifies the SSP interrupt source to check.
  * @retval  @ref ITStatus - The state of SSP_IT (SET or RESET).
  */
ITStatus SSP_GetITStatusMasked(SSP_IT_TypeDef SSP_IT)
{
    ITStatus bitstatus;

    /* Check the parameters */
    assert_param(IS_SSP_CONFIG_IT(SSP_IT));

    if (MDR_SSP1->MIS & (uint32_t)SSP_IT)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return (ITStatus)bitstatus;
}

/**
  * @brief  Clears the SSPx’s interrupt pending bits.
  * @param  SSP_IT - @ref SSP_IT_TypeDef - specifies the interrupt pending bit to clear.
  *         This parameter can be one of the following values:
  *           @arg SSP_IT_RT
  *           @arg SSP_IT_ROR
  * @retval None
  */
void SSP_ClearITPendingBit(SSP_IT_TypeDef SSP_IT)
{
    /* Check the parameters */
    assert_param(IS_SSP_RESET_IT(SSP_IT));

    MDR_SSP1->ICR |= (uint32_t)SSP_IT;
}

#if defined (USE_MDR32F21QI)
/**
  * @brief  Enables or disables the SSP’s DMA interface.
  * @param  SSP_DMAReq: specifies the DMA request.
  *         This parameter can be any combination of @ref SSP_DMA_Req_TypeDef values.
  * @param  NewState - @ref FunctionalState - new state of the DMA Request sources.
  * @retval None
  */
void SSP_DMACmd(uint32_t SSP_DMAReq, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SSP_DMAREQ(SSP_DMAReq));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the DMA transfer for selected requests in the SSP DMACR register */
        MDR_SSP1->DMACR |= SSP_DMAReq;
    }
    else
    {
        /* Disable the DMA transfer for selected requests in the SSP DMACR register */
        MDR_SSP1->DMACR &= (uint16_t)~SSP_DMAReq;
    }
}
#endif
/**
  * @brief  Transmits single data through the SSPx peripheral.
  * @param  Data: the data to transmit.
  * @retval None
  */
void SSP_SendData(uint16_t Data)
{
    /* Transmit Data */
    MDR_SSP1->DR = Data;
}

/**
  * @brief  Returns the most recent received data by the SSPx peripheral.
  * @param  None
  * @retval The received data.
  */
uint16_t SSP_ReceiveData(void)
{
    /* Receive Data */
    return ((uint16_t)(MDR_SSP1->DR));
}

/**
  * @brief  Checks whether the specified SSP flag is set or not.
  * @param  SSP_FLAG - @ref SSP_Flags_TypeDef - specifies the flag to check.
  * @retval @ref FlagStatus - The state of SSP_FLAG (SET or RESET).
  */
FlagStatus SSP_GetFlagStatus(SSP_Flags_TypeDef SSP_FLAG)
{
    FlagStatus bitstatus;

    /* Check the parameters */
    assert_param(IS_SSP_FLAG(SSP_FLAG));

    if (MDR_SSP1->SR & (uint32_t)SSP_FLAG)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return (bitstatus);
}

/**
  * @brief  Initializes the SSPx peripheral clock according to the specified parameters.
  * @param  SSP_BRG - @ref SSP_Clock_BRG_TypeDef - specifies the HCLK division factor.
  * @retval None
  */
void SSP_BRGInit(SSP_Clock_BRG_TypeDef SSP_BRG)
{
    uint32_t tmpreg;

    /* Check the parameters */
    assert_param(IS_SSP_CLOCK_BRG(SSP_BRG));

    tmpreg = MDR_RST_CLK->SSP_CLOCK;
    tmpreg |= RST_CLK_SSP_CLOCK_SSP1_CLK_EN;
    tmpreg &= ~RST_CLK_SSP_CLOCK_SSP1_BRG_Msk;
    tmpreg |= SSP_BRG;

    MDR_RST_CLK->SSP_CLOCK = tmpreg;
}

/** @} */ /* End of group SSP_Private_Functions */

/** @} */ /* End of group SSP */

/** @} */ /* End of group __MDR32F2xQI_StdPeriph_Driver */

/*********************** (C) COPYRIGHT {YYYY} Milandr ****************************
*
* END OF FILE MDR32F2xQI_ssp.c */
