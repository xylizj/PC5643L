#ifndef _MCU_H_
#define _MCU_H_

#include "mcu_Cfg.h"

extern void Mcu_Init(void);
extern void Stop_Mode_Entry(void);
extern void RTC_Init_WakeUp(void);

void LowPowerModeAndClks(void);
void disableWatchdog(void);

void LowPowerModeAndClks(void);
extern void Stop_Mode_Entry(void);
extern void RTC_Init_WakeUp(void);

#define Mcu_UseHwIntVector()       (INTC.MCR.B.HVEN = 1)
#define Mcu_UseSwIntVector()       (INTC.MCR.B.HVEN = 0)

#define Mcu_DisableAllInterrupt()   asm(" wrteei 0")

#define Mcu_EnableAllInterrupt()   {INTC.CPR.B.PRI = 0;	asm(" wrteei 1"); }


#define DisableAllInterrupts()   Mcu_DisableAllInterrupt()
#define EnableAllInterrupts()    Mcu_EnableAllInterrupt()
#define SuspendAllInterrupts()   Mcu_DisableAllInterrupt()
#define ResumeAllInterrupts()    Mcu_EnableAllInterrupt()





extern void delay_us(uint16_t n);




#endif