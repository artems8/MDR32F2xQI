/**
  ******************************************************************************
  * @file    MDR32F2xQI_uart.c
  * @author  Milandr Application Team
  * @version V1.0.0
  * @date    03/11/2022
  * @brief   This file contains all the UART firmware functions.
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
#include "MDR32F2xQI_uart.h"
#include "MDR32F2xQI_rst_clk.h"

/** @addtogroup __MDR32F2xQI_StdPeriph_Driver MDR32F2xQI Standard Peripherial Driver
  * @{
  */

/** @defgroup UART UART
  * @{
  */

/** @defgroup UART_Private_Defines UART Private Defines
  * @{
  */

#define IS_UART_ALL_PERIPH(PERIPH)      (((PERIPH) == MDR_UART0) || \
                                         ((PERIPH) == MDR_UART1))

#define CR_EN_Set               ((uint16_t)0x0001)  /*!< UART Enable Mask */
#define CR_EN_Reset             ((uint16_t)0xFFFE)  /*!< UART Disable Mask */

#define CR_SIREN_Set            ((uint16_t)0x0002)  /*!< UART IrDA mode Enable Mask */
#define CR_SIREN_Reset          ((uint16_t)0xFFFD)  /*!< UART IrDA mode Disable Mask */

#define CR_FC_Mask              ((uint16_t)0xFF80)  /*!< UART CR Flow control Bits Mask */

#define LCR_H_BRK_Set           ((uint16_t)0x0001)  /*!< UART Break Line Set Mask */
#define LCR_H_BRK_Reset         ((uint16_t)0xFFFE)  /*!< UART Break Line Reset Mask */
#define LCR_H_Clear_Mask        ((uint16_t)0x00FF)  /*!< UART LCR_H Mask */

#define FBRD_Fract_Mask         ((uint16_t)0x003F)  /*!< Fractional divider Mask */

#define IrLPBaud16              ((uint32_t)1843200) /*!< F_IrLPBaud16 nominal frequency Hz */

#define UART0_BRG_Mask          ((uint32_t)0x0007)  /*!< UART0 clock divider Mask */
#define UART1_BRG_Mask          ((uint32_t)0x0700)  /*!< UART1 clock divider Mask */
#define UART1_BRG_Offs          ((uint32_t)0x0008)  /*!< UART1 clock divider Offset */

/** @} */ /* End of group UART_Private_Defines */


/** @defgroup UART_Private_Functions UART Private Functions
  * @{
  */

/**
  * @brief  Resets the UARTx peripheral registers to their default reset values.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: MDR_UART0, MDR_UART1.
  * @retval None.
  */
void UART_DeInit(MDR_UART_TypeDef* UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    /* Clear UART CR */
    UARTx->CR      = 0;
    UARTx->LCR_H   = 0;
    UARTx->RSR_ECR = 0;
    UARTx->FR      = UART_FLAG_TXFE | UART_FLAG_RXFE;
    UARTx->ILPR    = 0;
    UARTx->IBRD    = 0;
    UARTx->FBRD    = 0;
    UARTx->IFLS    = UART_IT_FIFO_LVL_8words;
    UARTx->IMSC    = 0;
#if defined (USE_MDR32F21QI)
    UARTx->DMACR   = 0;
#endif

    /* Set UART CR[RXE] and UART CR[TXE] bits */
    UARTx->CR = UART_HardwareFlowControl_RXE | UART_HardwareFlowControl_TXE;
}

/**
  * @brief  Initializes the UARTx peripheral according to the specified
  *         parameters in the UART_InitStruct.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: MDR_UART0, MDR_UART1.
  * @param  UART_InitStruct: pointer to a @ref UART_InitTypeDef structure
  *         that contains the configuration information for the specified UART peripheral.
  * @retval @ref ErrorStatus - The Baud Rate status.
  */
ErrorStatus UART_Init(MDR_UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct)
{
    uint32_t tmpreg, uartclock;
    uint32_t realspeed;
    uint32_t divider;
    uint32_t integerdivider;
    uint32_t fractionaldivider;
    int32_t speederror;
    RST_CLK_FreqTypeDef RST_CLK_Clocks;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_BAUDRATE(UART_InitStruct->UART_BaudRate));
    assert_param(IS_UART_WORD_LENGTH(UART_InitStruct->UART_WordLength));
    assert_param(IS_UART_STOPBITS(UART_InitStruct->UART_StopBits));
    assert_param(IS_UART_PARITY(UART_InitStruct->UART_Parity));
    assert_param(IS_UART_FIFOMODE(UART_InitStruct->UART_FIFOMode));
    assert_param(IS_UART_HARDWARE_FLOW_CONTROL(UART_InitStruct->UART_HardwareFlowControl));

    /* Configure the UART Baud Rate */
    RST_CLK_GetClocksFreq(&RST_CLK_Clocks);

    if (UARTx == MDR_UART0)
    {
        uartclock = RST_CLK_Clocks.UART_Frequency[0];
    }
    else if (UARTx == MDR_UART1)
    {
        uartclock = RST_CLK_Clocks.UART_Frequency[1];
    }

    /* Determine the integer part */
    divider = uartclock / (UART_InitStruct->UART_BaudRate >> 2);
    integerdivider = divider >> 6;
    /* Determine the fractional part */
    fractionaldivider = (divider & FBRD_Fract_Mask);
    /* Determine the speed error */
    realspeed = (uartclock * 4) / ((integerdivider * 64) + fractionaldivider);
    speederror = ((realspeed - UART_InitStruct->UART_BaudRate) * 128)
            / UART_InitStruct->UART_BaudRate;
    if ((speederror > 2)||(speederror < -2))
    {
#if defined (MDR_LEGACY_SUPPORT) && (MDR_LEGACY_SUPPORT) == 153
        return BaudRateInvalid;
#else
        return ERROR;
#endif
    }
    /* Write UART Baud Rate */
    UARTx->IBRD = integerdivider;
    UARTx->FBRD = fractionaldivider;

    /* UART LCR_H configuration */
    /* Set the WLEN bits according to UART_WordLength value */
    /* Set STP2 bit according to UART_StopBits value */
    /* Set PEN, EPS and SPS bits according to UART_Parity value */
    /* Set FEN bit according to UART_FIFOMode value */
    tmpreg = UARTx->LCR_H;
    tmpreg |= UART_InitStruct->UART_WordLength | UART_InitStruct->UART_StopBits
            | UART_InitStruct->UART_Parity | UART_InitStruct->UART_FIFOMode;
    UARTx->LCR_H = tmpreg;

    /* UART CR configuration */
    tmpreg = UARTx->CR;
    /* Clear UART CR Flow control bits */
    tmpreg &= ~CR_FC_Mask;
    /* Set UART CR Flow control bits */
    tmpreg |= UART_InitStruct->UART_HardwareFlowControl;
    /* Write to UART CR */
    UARTx->CR = tmpreg;

#if defined (MDR_LEGACY_SUPPORT) && (MDR_LEGACY_SUPPORT) == 153
    return BaudRateValid;
#else
    return SUCCESS;
#endif
}

/**
  * @brief  Fills each UART_InitStruct member with its default value.
  * @param  UART_InitStruct: pointer to a @ref UART_InitTypeDef structure
  *         that is to be initialized.
  * @retval None
  */
void UART_StructInit(UART_InitTypeDef* UART_InitStruct)
{
    /* UART_InitStruct members default value */
    UART_InitStruct->UART_BaudRate            = 9600;
    UART_InitStruct->UART_WordLength          = UART_WordLength5b;
    UART_InitStruct->UART_StopBits            = UART_StopBits1;
    UART_InitStruct->UART_Parity              = UART_Parity_No;
    UART_InitStruct->UART_FIFOMode            = UART_FIFO_OFF;
    UART_InitStruct->UART_HardwareFlowControl = UART_HardwareFlowControl_RXE | UART_HardwareFlowControl_TXE;
}

/**
  * @brief  Enables or disables the specified UART peripheral.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: MDR_UART0, MDR_UART1.
  * @param  NewState - @ref FunctionalState - new state of the UARTx peripheral.
  * @retval None
  */
void UART_Cmd(MDR_UART_TypeDef* UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the selected UART by setting the UARTEN bit in the CR register */
        UARTx->CR |= CR_EN_Set;
    }
    else
    {
        /* Disable the selected UART by clearing the UARTEN bit in the CR register */
        UARTx->CR &= CR_EN_Reset;
    }
}

/**
  * @brief  Enables or disables the specified UART interrupts.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: MDR_UART0, MDR_UART1.
  * @param  UART_IT: specifies the UART interrupt sources to be enabled or disabled.
  *         This parameter can be any combination of @ref UART_IT_TypeDef values.
  * @param  NewState - @ref FunctionalState - new state of the specified UARTx interrupts.
  * @retval None
  */
void UART_ITConfig(MDR_UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_CONFIG_ITS(UART_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        UARTx->IMSC |= UART_IT;
    }
    else
    {
        UARTx->IMSC &= ~UART_IT;
    }
}

/**
  * @brief  Checks whether the specified UART interrupt has occurred or not.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  UART_IT - @ref UART_IT_TypeDef - specifies the UART interrupt source to check.
  * @retval @ref ITStatus - The state of UART_IT (SET or RESET).
  */
ITStatus UART_GetITStatus(MDR_UART_TypeDef* UARTx, UART_IT_TypeDef UART_IT)
{
    ITStatus bitstatus;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_CONFIG_IT(UART_IT));

    if ((UARTx->RIS & (uint32_t)UART_IT) == (uint32_t)UART_IT)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
  * @brief  Checks whether the specified UART interrupt (masked) has occurred or not.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  UART_IT - @ref UART_IT_TypeDef - specifies the UART interrupt source to check.
  * @retval @ref ITStatus - The state of UART_IT (SET or RESET).
  */
ITStatus UART_GetITStatusMasked(MDR_UART_TypeDef* UARTx, UART_IT_TypeDef UART_IT)
{
    ITStatus bitstatus;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_CONFIG_IT(UART_IT));

    if (UARTx->MIS & (uint32_t)UART_IT)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
  * @brief  Clears the UARTx's interrupt pending bits.
  * @param  UARTx: Select the UART or the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  UART_IT: specifies the interrupt pending bit to clear.
  *         This parameter can be any combination of @ref UART_IT_TypeDef values.
  * @retval None
  */
void UART_ClearITPendingBit(MDR_UART_TypeDef* UARTx, uint32_t UART_IT)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_CONFIG_IT(UART_IT));

    UARTx->ICR |= UART_IT;
}

#if defined (USE_MDR32F21QI)
/**
  * @brief  Specified the UART DMA buffer interrupt level.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  UART_IT_RB_LVL - @ref UART_IT_FIFO_TypeDef - specifies the receiver buffer.
  * @param  UART_IT_TB_LVL - @ref UART_IT_FIFO_TypeDef - specifies the transmitter buffer.
  * @retval None
  */
void UART_DMAConfig(MDR_UART_TypeDef* UARTx, UART_IT_FIFO_TypeDef UART_IT_RB_LVL, UART_IT_FIFO_TypeDef UART_IT_TB_LVL)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_IT_FIFO_LVL(UART_IT_RB_LVL));
    assert_param(IS_UART_IT_FIFO_LVL(UART_IT_TB_LVL));

    UARTx->IFLS = ((uint32_t)UART_IT_RB_LVL << 3) | (uint32_t)UART_IT_TB_LVL;
}

/**
  * @brief  Enables or disables the UART's DMA interface.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  UART_DMAReq: specifies the DMA request.
  *         This parameter can be any combination of @ref UART_DMA_Req_TypeDef values.
  * @param  NewState: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @note The DMA mode is not available for UART5.
  * @retval None
  */
void UART_DMACmd(MDR_UART_TypeDef* UARTx, uint32_t UART_DMAReq, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_DMAREQ(UART_DMAReq));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the DMA transfer for selected requests and DMAONERR bit
        in the UART DMACR register */
        UARTx->DMACR |= UART_DMAReq;
    }
    else
    {
        /* Disable the DMA transfer for selected requests and DMAONERR bit
        in the UART DMACR register */
        UARTx->DMACR &= (uint16_t)~UART_DMAReq;
    }
}
#endif

/**
  * @brief  Transmits single data through the UARTx peripheral.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  Data: the data to transmit.
  * @retval None
  */
void UART_SendData(MDR_UART_TypeDef* UARTx, uint8_t Data)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_DATA(Data));

    /* Transmit Data */
    UARTx->DR = (uint16_t)Data;
}

/**
  * @brief  Returns the most recent received data by the UARTx peripheral.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @retval The received data (7:0) and error flags (11:8).
  */
uint16_t UART_ReceiveData(MDR_UART_TypeDef* UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    /* Receive Data */
    return (uint16_t)(UARTx->DR);
}

/**
  * @brief  Break transmit.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  NewState - @ref FunctionalState - new state of the Line.
  * @retval None
  */
void UART_BreakLine(MDR_UART_TypeDef* UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Set BRK bit in the UART LCR_H register */
        UARTx->LCR_H |= LCR_H_BRK_Set;
    }
    else
    {
        /* Reset BRK bit in the UART LCR_H register */
        UARTx->LCR_H |= LCR_H_BRK_Reset;
    }
}

/**
  * @brief  Configures the UART's IrDA interface.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  UART_IrDAMode - @ref UART_IrDA_Mode_TypeDef - specifies the IrDA mode.
  * @retval None
  */
void UART_IrDAConfig(MDR_UART_TypeDef* UARTx, UART_IrDA_Mode_TypeDef UART_IrDAMode)
{
    uint32_t cpuclock;
    RST_CLK_FreqTypeDef RST_CLK_Clocks;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_IRDA_MODE(UART_IrDAMode));

    if (UART_IrDAMode == UART_IrDAMode_LowPower)
    {
        /* Configure the UART ILPR */
        RST_CLK_GetClocksFreq(&RST_CLK_Clocks);
        cpuclock = RST_CLK_Clocks.CPU_CLK_Frequency;
        UARTx->ILPR = cpuclock / IrLPBaud16;
    }

    UARTx->CR |= UART_IrDAMode;
}

/**
  * @brief  Enables or disables the UART's IrDA interface.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  NewState - @ref FunctionalState - new state of the IrDA mode.
  * @retval None
  */
void UART_IrDACmd(MDR_UART_TypeDef* UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Set SIREN bit in the UART CR register */
        UARTx->CR |= CR_SIREN_Set;
    }
    else
    {
        /* Reset SIREN bit in the UART CR register */
        UARTx->CR |= CR_SIREN_Reset;
    }
}

/**
  * @brief  Checks whether the specified UART flag is set or not.
  * @param  UARTx: Select the UART or the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0, UART1.
  * @param  UART_FLAG - @ref UART_Flags_TypeDef - specifies the flag to check.
  * @retval @ref FlagStatus - The state of UART_FLAG (SET or RESET).
  */
FlagStatus UART_GetFlagStatus(MDR_UART_TypeDef* UARTx, UART_Flags_TypeDef UART_FLAG)
{
    FlagStatus bitstatus;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_FLAG(UART_FLAG));

    if (UARTx->FR & (uint32_t)UART_FLAG)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
  * @brief  Initializes the UARTx peripheral Clock according to the
  *         specified parameters.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0, UART1.
  * @param  UART_BRG - @ref UART_Clock_BRG_TypeDef - specifies the HCLK division factor.
  * @retval None
  */
void UART_BRGInit(MDR_UART_TypeDef* UARTx, UART_Clock_BRG_TypeDef UART_BRG)
{
    uint32_t tmpreg;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_CLOCK_BRG(UART_BRG));

    tmpreg = MDR_RST_CLK->UART_CLOCK;

    if (UARTx == MDR_UART0)
    {
        tmpreg |= RST_CLK_UART_CLOCK_UART0_CLK_EN;
        tmpreg &= ~RST_CLK_UART_CLOCK_UART0_BRG_Msk;
        tmpreg |= (uint32_t)UART_BRG;
    }
    else if (UARTx == MDR_UART1)
    {
        tmpreg |= RST_CLK_UART_CLOCK_UART1_CLK_EN;
        tmpreg &= ~RST_CLK_UART_CLOCK_UART1_BRG_Msk;
        tmpreg |= ((uint32_t)UART_BRG << 8);
    }

    MDR_RST_CLK->UART_CLOCK = tmpreg;
}

/** @} */ /* End of group UART_Private_Functions */

/** @} */ /* End of group UART */

/** @} */ /* End of group __MDR32F2xQI_StdPeriph_Driver */

/*********************** (C) COPYRIGHT {YYYY} Milandr ****************************
*
* END OF FILE MDR32F2xQI_uart.c */
