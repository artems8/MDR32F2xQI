;/*
; * FILE startup_MDR32F21QI.S
; */

; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000200

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB

; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts - MDR32F21QI Specific 
                DCD     DMA_IRQHandler            ; 0:  DMA Interrupt
                DCD     UART0_IRQHandler          ; 1:  UART0 Interrupt
                DCD     UART1_IRQHandler          ; 2:  UART1 Interrupt
                DCD     SSP1_IRQHandler           ; 3:  SSP1 Interrupt
                DCD     POWER_IRQHandler          ; 4:  Power Detector Interrupt
                DCD     WWDG_IRQHandler           ; 5:  WWDG Interrupt
                DCD     TIMER0_IRQHandler         ; 6:  TIMER0 Interrupt
                DCD     TIMER1_IRQHandler         ; 7:  TIMER1 Interrupt
                DCD     ADC_IRQHandler            ; 8:  ADC Interrupt
                DCD     0                         ; 9:  Reserved
                DCD     BKP_IRQHandler            ; 10: Backup and RTC Interrupt
                DCD     EXT1_IRQHandler           ; 11: EXT_INT1 Interrupt
                DCD     EXT2_IRQHandler	          ; 12: EXT_INT2 Interrupt
                DCD     EXT3_IRQHandler	          ; 13: EXT_INT3 Interrupt
                DCD     ADCUI_F0_IRQHandler       ; 14: ADCIU_F0 Interrupt
                DCD     ADCUI_F1_IRQHandler       ; 15: ADCIU_F1 Interrupt
                DCD     ADCUI_F2_IRQHandler       ; 16: ADCIU_F2 Interrupt
__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset handler
Reset_Handler    PROC
                 EXPORT  Reset_Handler             [WEAK]
        IMPORT  SystemInit
        IMPORT  __main
                 LDR     R0, =SystemInit
                 BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler \
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  DMA_IRQHandler               [WEAK]
                EXPORT  UART0_IRQHandler             [WEAK]
                EXPORT  UART1_IRQHandler             [WEAK]
                EXPORT  SSP1_IRQHandler              [WEAK]
                EXPORT  POWER_IRQHandler             [WEAK]
                EXPORT  WWDG_IRQHandler              [WEAK]
                EXPORT  TIMER0_IRQHandler            [WEAK]
                EXPORT  TIMER1_IRQHandler            [WEAK]
                EXPORT  ADC_IRQHandler               [WEAK]
                EXPORT  BKP_IRQHandler               [WEAK]
                EXPORT  EXT1_IRQHandler              [WEAK]
                EXPORT  EXT2_IRQHandler	             [WEAK]
                EXPORT  EXT3_IRQHandler	             [WEAK]
                EXPORT  ADCUI_F0_IRQHandler          [WEAK]
                EXPORT  ADCUI_F1_IRQHandler          [WEAK]
                EXPORT  ADCUI_F2_IRQHandler          [WEAK]

DMA_IRQHandler
UART0_IRQHandler
UART1_IRQHandler
SSP1_IRQHandler
POWER_IRQHandler
WWDG_IRQHandler
TIMER0_IRQHandler
TIMER1_IRQHandler
ADC_IRQHandler
BKP_IRQHandler
EXT1_IRQHandler
EXT2_IRQHandler
EXT3_IRQHandler
ADCUI_F0_IRQHandler
ADCUI_F1_IRQHandler
ADCUI_F2_IRQHandler
                B       .

                ENDP


                ALIGN


;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END

;/*
;*
;* END OF FILE startup_MDR32F21QI.S */