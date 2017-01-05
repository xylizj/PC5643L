#include "Gpt.h"
#include "MPC5643L.h"
#include "Adc.h"




/*******************************************************************************
	xyl add comment 20160426
	GPT is named according to AUTOSAR, it is STM in MCU.                         
*******************************************************************************/
void ConfigureSTMChannel0_Int(void) 
{
  STM.CHANNEL[0].CCR.B.CEN = 1;//The channel is enabled
  STM.CHANNEL[0].CIR.B.CIF = 1;//Interrupt request due to a match on the channel
  STM.CHANNEL[0].CMP.R = STM.CNT.R+STM_CH0_CMP_VAL;//Compare value for channel n
}



 
void Gpt_Init()
{
	STM.CR.B.CPS = (120/STM_CLK_MHZ)-1;//Divide system clock by 12, system clock is 120M;
	STM.CR.B.FRZ = 0x1;        				//STM counter NOT continues to run in debug mode;
	STM.CR.B.TEN = 0x0;        // Counter is disable;
	
	STM.CNT.R = 0x0;           //Init the timer count value is  0;
}


void Gpt_StartTimer(void)
{
	STM.CR.B.TEN = 0x1;        // Counter is enable;
}


void Gpt_StopTimer(void)
{
	STM.CR.B.TEN = 0x0;        // Counter is disable;
}