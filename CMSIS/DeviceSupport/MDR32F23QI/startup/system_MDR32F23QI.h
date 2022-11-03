/**
  * FILE system_MDR32F23QI.h
  */

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @defgroup MDR32F23QI
 *  @{
 */

/** @defgroup __MDR32F23QI MDR32F23QI System
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_MDR32F23QI_H
#define __SYSTEM_MDR32F23QI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>                      /* standard types definitions */

/** @addtogroup __MDR32F23QI_System_Exported_Variables MDR32F23QI System Exported Variables
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock)
                                           *   default value */

/** @} */ /* End of group __MDR32F23QI_System_Exported_Variables */

/** @addtogroup __MDR32F23QI_System_Exported_Functions MDR32F23QI System Exported Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

/** @} */ /* End of group __MDR32F23QI_System_Exported_Functions */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /*__SYSTEM_MDR32F23QI_H */

/** @} */ /* End of group __MDR32F23QI */

/** @} */ /* End of group MDR32F23QI */

/** @} */ /* End of group __CMSIS */

/*
*
* END OF FILE system_MDR32F23QI.h */
