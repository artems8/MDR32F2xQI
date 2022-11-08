;/**
;  ******************************************************************************
;  * @file    MDR32F9Qx_asm.S
;  * @author  Milandr Application Team
;  * @version V2.0.0
;  * @date    18/05/2022
;  * @brief   This file contains assembler functions.
;  ******************************************************************************
;  * <br><br>
;  *
;  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
;  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
;  * TIME. AS A RESULT, MILANDR SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
;  * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
;  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
;  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
;  *
;  * <h2><center>&copy; COPYRIGHT 2022 Milandr</center></h2>
;  ******************************************************************************
;  */

#if defined ( __CC_ARM ) || (( __ARMCC_VERSION ) && ( __ARMCC_VERSION >= 6010050 )) /* Arm Compiler 4/5 || Arm Compiler 6 */
        #define CODESECT        AREA    |EXECUTABLE_MEMORY_SECTION|, CODE, READONLY, ALIGN=2
        #define CODESECT_TYPE

#elif defined ( __IASMARM__ )  /* IAR */
        #define SHT_PROGBITS    0x1
        #define SHF_WRITE       0x1
        #define SHF_EXECINSTR   0x4
        
        #define CODESECT        SECTION .textrw:CODE:NOROOT(2)
        #define CODESECT_TYPE   SECTION_TYPE SHT_PROGBITS, SHF_WRITE | SHF_EXECINSTR
        #define ALIGN           ALIGNRAM 2
        #define PROC
        #define ENDP
        #define EXPORT          PUBLIC
#endif
        
        CODESECT
        CODESECT_TYPE
        THUMB
        
;/**
;  * @brief   Program delay.
;  * @warning Register r0 is not stored on the stack because it is non preserved register.
;  * @param   Loops: Number of the loops.
;  * @retval  None.
;  */
ProgramDelayAsm     PROC
        EXPORT  ProgramDelayAsm
        
        CMP   r0,#0x00
        BEQ   Exit
Loop
        SUBS  r0,r0,#1
        BNE   Loop
Exit
        BX    LR
        ENDP
        
        END
