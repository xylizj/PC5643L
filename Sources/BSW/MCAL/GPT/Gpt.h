
#ifndef _GPT_H_
#define _GPT_H_

#include "typedefs.h"

#define STM_CLK_MHZ 10

#define STM_CH0_CMP_VAL (STM_CLK_MHZ*200)//10Mhz,  us

//use marco instead function to improve performance,xyl 20160426
//GPT is named according to AUTOSAR, it is STM in MCU.
#define Gpt_GetCurrentCnt() (uint32_t)(STM.CNT.R)
//extern uint32_t Gpt_GetCurrentCnt(void);
extern void Gpt_Init(void);
extern void ConfigureSTMChannel0_Int(void); 
extern void Gpt_StopTimer(void);
extern void Gpt_StartTimer(void);


#endif