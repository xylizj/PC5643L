#include "Platform_Types.h"
#include "FlexPWM.h"
#include "Ioa.h"


extern boolean phase_drive_enable;
extern boolean phase_drive_disable;
extern boolean phase_drive_fault_reset;

extern uint8_t pwm0_sub0_a_duty_set_en;
extern uint8_t pwm0_sub1_a_duty_set_en;
extern uint8_t pwm0_sub2_a_duty_set_en;
extern uint8_t pwm0_sub3_a_duty_set_en;

extern uint8_t pwm0_sub0_a_duty; 
extern uint8_t pwm0_sub1_a_duty; 
extern uint8_t pwm0_sub2_a_duty; 
extern uint8_t pwm0_sub3_a_duty; 
extern uint16_t pwm0_sub3_VAL2;



void Xcp_DataHandle(void)
{
	if(pwm0_sub0_a_duty_set_en==1)
	{
		pwm0_sub0_a_duty_set_en = 0;
		SetFlexPWM0SubXDuty(0, pwm0_sub0_a_duty);		
	}
	if(pwm0_sub1_a_duty_set_en==1)
	{
		pwm0_sub1_a_duty_set_en = 0;
		SetFlexPWM0SubXDuty(1, pwm0_sub1_a_duty);	
	}
	if(pwm0_sub2_a_duty_set_en==1)
	{
		pwm0_sub2_a_duty_set_en = 0;
		SetFlexPWM0SubXDuty(2, pwm0_sub2_a_duty);	
	}
	if(pwm0_sub3_a_duty_set_en==1)
	{
		//pwm0_sub3_a_duty_set_en = 0;
		//SetFlexPWM0Sub3Duty(pwm0_sub3_a_duty);
		SetFlexPWM0Sub3_val2(pwm0_sub3_VAL2);	
	}
	
	if(phase_drive_fault_reset==1)
	{
		phase_drive_fault_reset = 0;
		Ioa_PhaseDrvFaultReset();
	}
	
	
	if(phase_drive_enable==1)
	{
		phase_drive_enable = 0;
		SIU.GPDO[22].R=1;//三相驱动使能，高电平有效	
	}
	
	if(phase_drive_disable==1)
	{
		phase_drive_disable = 0;
		SIU.GPDO[22].R=0;//三相驱动失能	
	}
}

