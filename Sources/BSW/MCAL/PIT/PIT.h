#ifndef _PIT_H_
#define _PIT_H_

// Define IRQ#
#define PIT0 59


extern void PIT0_Isr( void );
extern void PIT0_Init(void);
extern void PIT0_Enable(void);
extern void PIT1_Init(void);
extern void PIT1_Enable(void);
extern void PIT0_Disable(void);
extern void PIT1_Init(void);
extern void PIT1_Delay(uint32_t usDly);

































#endif/*_PIT_H_*/