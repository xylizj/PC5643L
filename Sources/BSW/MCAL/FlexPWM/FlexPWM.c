#include "MPC5643L.h"
#include "FlexPWM.h"







void LaunchFlexPWM0_modules012(void) //must load together!!! 20160512 xyl
{
	//FLEXPWM_0.FSTS.R = 0xF;
	FLEXPWM_0.OUTEN.B.PWMA_EN |= 0x7;
	FLEXPWM_0.OUTEN.B.PWMB_EN |= 0x7;

	FLEXPWM_0.MCTRL.B.LDOK |= 0x07;// Read and write: load config values into buffers 
	FLEXPWM_0.MCTRL.B.RUN  |= 0x7;// Channels 0,1,2 - Go!
}

void PWM_PadConfig(void)
{
  /* MPC5643L: Config pad A[11] pin as PWM0_A[0] output */
  SIU.PCR[11].B.PA = 2;  
  /* MPC5643L: Config pad A[10] pin as PWM0_B[0] output */
  SIU.PCR[10].B.PA = 2;  
  /* MPC5643L: Config pad C[15] pin as PWM0_A[1] output */
  SIU.PCR[47].B.PA = 3;  
  /* MPC5643L: Config pad D[0] pin as PWM0_B[1] output */
  SIU.PCR[48].B.PA = 3;
  /* MPC5643L: Config pad A[12] pin as PWM0_A[2] output */
  SIU.PCR[12].B.PA = 2;
  /* MPC5643L: Config pad A[13] pin as PWM0_B[2] output */
  SIU.PCR[13].B.PA = 2;//NOTE!!
  /* MPC5643L: Config pad C[10] pin as PWM0_A[3] output */
  SIU.PCR[42].B.PA = 3;
}


void FlexPWM0Sub0ReloadIntEn(void)
{
	FLEXPWM_0.SUB[0].INTEN.B.RIE = 1;/* Reload Interrupt Enable */
}




void ConfigureFlexPWM0Sub0(void)
{
	FLEXPWM_0.SUB[0].CTRL1.B.FULL = 1;//Full Cycle reload
	FLEXPWM_0.SUB[0].CTRL1.B.HALF = 0;//No half cycle reload
	FLEXPWM_0.SUB[0].CTRL1.B.LDFQ = 1;//Every 2 PWM opportunity
	FLEXPWM_0.SUB[0].CTRL1.B.PRSC = 0;//fclk/1
	//0  take effect at the next PWM  reload if LDOK is set
	//1  take e ffect immediately upon LDOK being set
	FLEXPWM_0.SUB[0].CTRL1.B.LDMOD = 0;
	
	FLEXPWM_0.SUB[0].CTRL2.B.DBGEN = 0;// PWM will not runs in debug mode
	FLEXPWM_0.SUB[0].CTRL2.B.WAITEN = 0;//When set to one, the PWM will continue to run whil e the chip is in WAIT mode
	FLEXPWM_0.SUB[0].CTRL2.B.INDEP = 0;// PWMA & PWMB outputs are complementary
	FLEXPWM_0.SUB[0].CTRL2.B.INIT_SEL = 0;//00 = Local sync (PWMX)  causes initialization
	FLEXPWM_0.SUB[0].CTRL2.B.FRCEN = 1;
	FLEXPWM_0.SUB[0].CTRL2.B.FORCE_SEL = 0b100;//RM page691
	FLEXPWM_0.SUB[0].CTRL2.B.RELOAD_SEL = 0;//RM page691
	FLEXPWM_0.SUB[0].CTRL2.B.CLK_SEL = 0b00;//RM page691,SUB3 must also be 00
	
	//test difference of 0 and 1
	FLEXPWM_0.SUB[0].CTRL2.B.PWM23_INIT = 0;
	FLEXPWM_0.SUB[0].CTRL2.B.PWM45_INIT = 0;

  FLEXPWM_0.SUB[0].INIT.R   = (int16_t)-FLEXPWM0_SUB012_HALF;
	FLEXPWM_0.SUB[0].VAL[0].R = 0;
	FLEXPWM_0.SUB[0].VAL[1].R = FLEXPWM0_SUB012_HALF;    // Max value for counter 
	FLEXPWM_0.SUB[0].VAL[2].R = (int16_t)-((uint16_t)(((uint32_t)(FLEXPWM0_SUB012_HALF*PWM0_SUB012_INIT_DUTY))/100));
	FLEXPWM_0.SUB[0].VAL[3].R = (int16_t)(((uint32_t)(FLEXPWM0_SUB012_HALF*PWM0_SUB012_INIT_DUTY))/100); 
	FLEXPWM_0.SUB[0].DTCNT0.R = FLEXPWM0_DTCNT;//PWM0_H dead time
	FLEXPWM_0.SUB[0].DTCNT1.R = FLEXPWM0_DTCNT;//PWM0_L dead time

  FLEXPWM_0.SUB[0].DISMAP.R   = 0x0000;	// disable fault pin condition
}



void ConfigureFlexPWM0Sub1(void)
{
  FLEXPWM_0.SUB[1].CTRL1.B.FULL = 1;//Full Cycle reload
  FLEXPWM_0.SUB[1].CTRL1.B.HALF = 0;//No half cycle reload
  FLEXPWM_0.SUB[1].CTRL1.B.LDFQ = 0;//Every PWM opportunity
  FLEXPWM_0.SUB[1].CTRL1.B.PRSC = 0;//fclk/1
  //0  take effect at the next PWM  reload if LDOK is set
  //1  take e ffect immediately upon LDOK being set
  FLEXPWM_0.SUB[1].CTRL1.B.LDMOD = 0;
	
	FLEXPWM_0.SUB[1].CTRL2.B.DBGEN = 0;// PWM will not runs in debug mode
	FLEXPWM_0.SUB[1].CTRL2.B.WAITEN = 0;//When set to one, the PWM will continue to run whil e the chip is in WAIT mode
	FLEXPWM_0.SUB[1].CTRL2.B.INDEP = 0;// PWMA & PWMB outputs are complementary
	FLEXPWM_0.SUB[1].CTRL2.B.INIT_SEL = 0;//00 = Local sync (PWMX)  causes initialization
	FLEXPWM_0.SUB[1].CTRL2.B.FRCEN = 1;
	FLEXPWM_0.SUB[1].CTRL2.B.FORCE_SEL = 0b101;//RM page691
	FLEXPWM_0.SUB[1].CTRL2.B.RELOAD_SEL = 1;//RM page691
	FLEXPWM_0.SUB[1].CTRL2.B.CLK_SEL = 0b10;//RM page691
	
	//test difference of 0 and 1
	FLEXPWM_0.SUB[1].CTRL2.B.PWM23_INIT = 0;
	FLEXPWM_0.SUB[1].CTRL2.B.PWM45_INIT = 0;

  FLEXPWM_0.SUB[1].INIT.R   = (int16_t)-FLEXPWM0_SUB012_HALF;
	FLEXPWM_0.SUB[1].VAL[0].R = 0;
	FLEXPWM_0.SUB[1].VAL[1].R = FLEXPWM0_SUB012_HALF;    // Max value for counter 
	FLEXPWM_0.SUB[1].VAL[2].R = (int16_t)-((uint16_t)(((uint32_t)(FLEXPWM0_SUB012_HALF*PWM0_SUB012_INIT_DUTY))/100));
	FLEXPWM_0.SUB[1].VAL[3].R = (int16_t)(((uint32_t)(FLEXPWM0_SUB012_HALF*PWM0_SUB012_INIT_DUTY))/100); 
	FLEXPWM_0.SUB[1].DTCNT0.R = FLEXPWM0_DTCNT;//PWM0_H dead time
	FLEXPWM_0.SUB[1].DTCNT1.R = FLEXPWM0_DTCNT;//PWM0_L dead time

  FLEXPWM_0.SUB[1].DISMAP.R   = 0x0000;	// disable fault pin condition
}


void ConfigureFlexPWM0Sub2(void)
{
  FLEXPWM_0.SUB[2].CTRL1.B.FULL = 1;//Full Cycle reload
  FLEXPWM_0.SUB[2].CTRL1.B.HALF = 0;//No half cycle reload
  FLEXPWM_0.SUB[2].CTRL1.B.LDFQ = 0;//Every PWM opportunity
  FLEXPWM_0.SUB[2].CTRL1.B.PRSC = 0;//fclk/1
  //0  take effect at the next PWM  reload if LDOK is set
  //1  take e ffect immediately upon LDOK being set
  FLEXPWM_0.SUB[2].CTRL1.B.LDMOD = 0;
	
	FLEXPWM_0.SUB[2].CTRL2.B.DBGEN = 0;// PWM will not runs in debug mode
	FLEXPWM_0.SUB[2].CTRL2.B.WAITEN = 0;//When set to one, the PWM will continue to run whil e the chip is in WAIT mode
	FLEXPWM_0.SUB[2].CTRL2.B.INDEP = 0;// PWMA & PWMB outputs are complementary
	FLEXPWM_0.SUB[2].CTRL2.B.INIT_SEL = 0;//00 = Local sync (PWMX)  causes initialization
	FLEXPWM_0.SUB[2].CTRL2.B.FRCEN = 1;
	FLEXPWM_0.SUB[2].CTRL2.B.FORCE_SEL = 0b101;//RM page691
	FLEXPWM_0.SUB[2].CTRL2.B.RELOAD_SEL = 1;//RM page691
	FLEXPWM_0.SUB[2].CTRL2.B.CLK_SEL = 0b10;//RM page691
	
	//test difference of 0 and 1
	FLEXPWM_0.SUB[2].CTRL2.B.PWM23_INIT = 0;
	FLEXPWM_0.SUB[2].CTRL2.B.PWM45_INIT = 0;

  FLEXPWM_0.SUB[2].INIT.R   = (int16_t)-FLEXPWM0_SUB012_HALF;
	FLEXPWM_0.SUB[2].VAL[0].R = 0;
	FLEXPWM_0.SUB[2].VAL[1].R = FLEXPWM0_SUB012_HALF;    // Max value for counter 
	FLEXPWM_0.SUB[2].VAL[2].R = (int16_t)-((uint16_t)(((uint32_t)(FLEXPWM0_SUB012_HALF*PWM0_SUB012_INIT_DUTY))/100));
	FLEXPWM_0.SUB[2].VAL[3].R = (int16_t)(((uint32_t)(FLEXPWM0_SUB012_HALF*PWM0_SUB012_INIT_DUTY))/100); 
	FLEXPWM_0.SUB[2].DTCNT0.R = FLEXPWM0_DTCNT;//PWM0_H dead time
	FLEXPWM_0.SUB[2].DTCNT1.R = FLEXPWM0_DTCNT;//PWM0_L dead time

  FLEXPWM_0.SUB[2].DISMAP.R   = 0x0000;	// disable fault pin condition
}











 
void FlexPWM0Sub3(uint8_t duty_ratio)
{
	FLEXPWM_0.SUB[3].INIT.R   = 0; 					// Initial count value
	FLEXPWM_0.SUB[3].CTRL.B.FULL = 1;		    // No full Cycle reload
	FLEXPWM_0.SUB[3].CTRL.B.HALF = 0;       // Half cycle reload
	FLEXPWM_0.SUB[3].CTRL.B.PRSC= 0;	

	FLEXPWM_0.SUB[3].DISMAP.R   = 0x0000;	// disable fault pin condition

	FLEXPWM_0.SUB[3].CTRL2.B.INDEP = 1;		    // PWMA & PWMB outputs are independent
	
	FLEXPWM_0.SUB[3].VAL[0].R = 0; 		   	// Juste before rising edge
	FLEXPWM_0.SUB[3].VAL[1].R = PWM0_SUB3_A_PERIOD;    // Max value for counter 
	FLEXPWM_0.SUB[3].VAL[2].R = (int16_t)(PWM0_SUB3_A_PERIOD-(uint16_t)(((uint32_t)(PWM0_SUB3_A_PERIOD*duty_ratio))/100));  // PWMA high 
	FLEXPWM_0.SUB[3].VAL[3].R = PWM0_SUB3_A_PERIOD;  			// PWMA Low    

	FLEXPWM_0.OUTEN.B.PWMA_EN |= 0x8;
	//FLEXPWM_0.OUTEN.B.PWMB_EN |= 0x8;
	
	//Load register
	FLEXPWM_0.MCTRL.B.LDOK |= 0x8; 		// Read and write: load config values into buffers 
	FLEXPWM_0.MCTRL.B.RUN  |= 0x8; 		// Channels 3 - Go!
}



int16_t sub0_sts;
int16_t sub1_sts;
int16_t sub2_sts;
int16_t sub0_sts_after;

int16_t sub0_val3;

void FlexPWM0Sub012_ReadSts(void)
{
	sub0_sts = FLEXPWM_0.SUB[0].STS.R ;
	sub1_sts = FLEXPWM_0.SUB[1].STS.R ;
	sub2_sts = FLEXPWM_0.SUB[2].STS.R ;
	sub0_val3 = FLEXPWM_0.SUB[0].VAL[3].R ;
}




void SetFlexPWM0SubXDuty(uint8_t sub_no, uint8_t duty_ratio)
{
	if(duty_ratio>50)
	{
		duty_ratio = 50;	
	}
	
//disable load of register buffer to unlock VALx registers
	FLEXPWM_0.MCTRL.B.CLOK = 1<<sub_no;
	//update VAL2 and VAL3
	FLEXPWM_0.SUB[sub_no].VAL[2].R = (int16_t)-((uint16_t)(((uint32_t)(FLEXPWM0_SUB012_HALF*duty_ratio/10))/100));  // PWMA high 
	FLEXPWM_0.SUB[sub_no].VAL[3].R = (int16_t)(((uint32_t)(FLEXPWM0_SUB012_HALF*duty_ratio/10))/100);  			// PWMA Low    	
	//enable load of register buffer
	//FLEXPWM_0.MCTRL.B.LDOK = (FLEXPWM_0.MCTRL.B.LDOK | (1<<sub_no)); 		// Load config values into buffers for submodule 1	
}


void SetFlexPWM0Sub3Duty(uint8_t duty_ratio)
{
	//disable load of register buffer to unlock VALx registers
	FLEXPWM_0.MCTRL.B.CLOK |= 8;
	//update VAL2 and VAL3
	FLEXPWM_0.SUB[3].VAL[2].R = (int16_t)(PWM0_SUB3_A_PERIOD-(uint16_t)(((uint32_t)(PWM0_SUB3_A_PERIOD*duty_ratio))/100));  // PWMA high 
	FLEXPWM_0.SUB[3].VAL[3].R = PWM0_SUB3_A_PERIOD;
	//enable load of register buffer
	FLEXPWM_0.MCTRL.B.LDOK |= 8;
}




void SetFlexPWM0Sub3_val2(uint16_t val2)
{
	if(val2>((PWM0_SUB3_A_PERIOD/100)*50))
	{
		val2 = (PWM0_SUB3_A_PERIOD/100)*50;
	}
	
	//disable load of register buffer to unlock VALx registers
	FLEXPWM_0.MCTRL.B.CLOK |= 8;
	//update VAL2 and VAL3
	FLEXPWM_0.SUB[3].VAL[2].R = (uint16_t)(PWM0_SUB3_A_PERIOD-(uint16_t)(val2));  // PWMA high 
	//FLEXPWM_0.SUB[3].VAL[3].R = PWM0_SUB3_A_PERIOD;
	//enable load of register buffer
	FLEXPWM_0.MCTRL.B.LDOK |= 8;
}






