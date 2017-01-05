/************************************************************************/
/*    Phase-shift PWM with external current limit control               */
/************************************************************************/
/* Desc: Support functions for configuring the Mode and Clock modules   */
/************************************************************************/
/* Author: Yves Briant 
/* Date:   14/03/2010
/************************************************************************/

#include "MPC5643L.h"
#include "clocks_modes.h"

/************************************************************************/
/* void clear_CF(void)													*/
/************************************************************************/
/* Desc: Clear Critical Failure latched by the FCCU 					*/
/************************************************************************/
void clear_CF(void) {
	uint32_t i,a[4];
  
	for(i=0;i<4;i++) {
		FCCU.CFK.R = FCCU_CFK_KEY;
		FCCU.CF_S[i].R = 0xFFFFFFFF;

		while(FCCU.CTRL.B.OPS != 0x3){}           /* wait for the completion of the operation */
		a[i]=FCCU.CF_S[i].R;
	}
}

/************************************************************************/
/* void clear_NCF(void)													*/
/************************************************************************/
/* Desc: Clear Non Critical Failure latched bu the FCCU 				*/
/************************************************************************/
void clear_NCF(void) {
	uint32_t i,b[4];

	for(i=0;i<4;i++){
		FCCU.NCFK.R = FCCU_NCFK_KEY;
		FCCU.NCF_S[i].R = 0xFFFFFFFF;

		while(FCCU.CTRL.B.OPS != 0x3){}           /* wait for the completion of the operation */
		b[i]=FCCU.NCF_S[i].R;
	}
}

/************************************************************************/
/* void ConfigAuxilliaryClocks(void) 									*/
/************************************************************************/
/* Desc: Configure auxilliary clocks									*/
/*       MotorControl: 	FMPLL1 @ 120Mhz									*/
/*		 FlexRay:		FMPLL1 @ 80Mhz									*/
/*		 FlexCAN:		FMPLL0 @ 120Mhz									*/
/************************************************************************/
void ConfigAuxilliaryClocks(void) 
{   	
   //Aux clock 0: MC peripherals 
   CGM.AC0SC.B.SELCTL = CGM_ACXSC_FMPLL0;
   CGM.AC0DC.B.DE0	= 0x1; 
   CGM.AC0DC.B.DIV0	= 0x0; 
   CGM.AC0DC.B.DE1	= 0x1;
   CGM.AC0DC.B.DIV1	= 0x0;
   
   //Aux clock 1 : Flexray
   CGM.AC1SC.B.SELCTL = CGM_ACXSC_FMPLL1_80;		
   CGM.AC1DC.B.DIV0	= 0x0;  
   CGM.AC1DC.B.DE0	= 0x1;
   
   //Aux clock 2: FlexCAN
   CGM.AC2SC.B.SELCTL = CGM_ACXSC_FMPLL0;
   //CGM.AC2SC.B.SELCTL = CGM_ACXSC_FMPLL1_120;	
   CGM.AC2DC.B.DE0	= 0x1;
   CGM.AC2DC.B.DIV0	= 14;  //20160425 XYL MODIFY to set FlexCAN clock 8M
}

/************************************************************************/
/* void ConfigPeripherals(void)		 									*/
/************************************************************************/
/* Desc: Define two Peripheral Configuration							*/
/*       RUNPC[0]: 		- used in DRUN mode   							*/
/*						- DSPI012, FlexCAN01, FR, eTimer2, LINflex01    */
/*						  CRC, SWG										*/
/*		 RUNPC[1]:		- used in RUN0 & RUN1							*/
/*						- ADC01, CTU, eTimer01, FlexPWM01, PIT_RTI		*/
/************************************************************************/
void ConfigPeripherals(void)
{
   // RunPC0 will be used to disable selected peripherals in 'high' power mode
   ME.RUNPC[0].B.RUN3=0;
   ME.RUNPC[0].B.RUN2=0;
   ME.RUNPC[0].B.RUN1=0;
   ME.RUNPC[0].B.RUN0=0;
   //ME.RUNPC[0].B.DRUN=1;	// all peripherals on in DRUN to execute Peripherals setup
   ME.RUNPC[0].B.SAFE=0;
   ME.RUNPC[0].B.TEST=0;
   
   // RunPC1 will be used to enable selected peripherals in 'high' power mode
   ME.RUNPC[1].B.RUN3=0;
   ME.RUNPC[1].B.RUN2=0;
   ME.RUNPC[1].B.RUN1=1;
   ME.RUNPC[1].B.RUN0=1;
   ME.RUNPC[1].B.DRUN=0;
   ME.RUNPC[1].B.SAFE=0;
   ME.RUNPC[1].B.TEST=0;
   
   //Peripherals mode cfg	// Peripheral		//0|DBG_F:1|LP_CFG:3|RUN_CFG:3
   ME.PCTL[4].R =0|DBGm|LPPC0|RUNPC0;	//DSPI0
   ME.PCTL[5].R =0|DBGm|LPPC0|RUNPC1;	//DSPI1
   ME.PCTL[6].R =0|DBGm|LPPC0|RUNPC0;	//DSPI2
   ME.PCTL[16].R=0|DBGm|LPPC0|RUNPC1;	//FlexCAN0
   ME.PCTL[17].R=0|DBGm|LPPC0|RUNPC0;	//FlexCAN1
   ME.PCTL[24].R=0|DBGm|LPPC0|RUNPC0;	//FlexRay
   ME.PCTL[32].R=0|DBGm|LPPC0|RUNPC1;	//ADC0
   ME.PCTL[33].R=0|DBGm|LPPC0|RUNPC1;	//ADC1
   ME.PCTL[35].R=0|DBGm|LPPC0|RUNPC1;	//CTU
   ME.PCTL[38].R=0|DBGm|LPPC0|RUNPC1;	//eTimer0
   ME.PCTL[39].R=0|DBGm|LPPC0|RUNPC1;	//eTimer1
   ME.PCTL[40].R=0|DBGm|LPPC0|RUNPC0;	//eTimer2
   ME.PCTL[41].R=0|DBGm|LPPC0|RUNPC1;	//FlexPWM0
   ME.PCTL[42].R=0|DBGm|LPPC0|RUNPC0;	//FlexPWM1
   ME.PCTL[48].R=0|DBGm|LPPC0|RUNPC0;	//LINFlex0
   ME.PCTL[49].R=0|DBGm|LPPC0|RUNPC0;	//LINFlex1
   ME.PCTL[58].R=0|DBGm|LPPC0|RUNPC0;	//CRC engine
   ME.PCTL[62].R=0|DBGm|LPPC0|RUNPC0;	//SWG
   ME.PCTL[92].R=0|DBGm|LPPC0|RUNPC1;	//PIT
}

/************************************************************************/
/* void ConfigExternalClock(void) 	 									*/
/************************************************************************/
/* Desc: Enable external clock for debugging purpose					*/
/************************************************************************/
void ConfigExternalClock(void) 
{
	//CGM config
	CGM.OCDS_SC.B.SELCTL = CGM_SELCTL_PLL0;
	CGM.OCDS_SC.B.SELDIV = 3; //divide by 8	
	CGM.OC_EN.B.EN = 1;
}

/************************************************************************/
/* void ConfigFMPLLs(void) 	 											*/
/************************************************************************/
/* Desc: Configure PLL reference clocks and divider ration				*/
/* 		Assume an external Xtal at 40Mhz                                */
/* 		FMPLL freq = 40 / 4 x 48 / 4 = 120Mhz           48(0x30)                */
/* 		FMPLL1 sec output = 40 / 4 x 32 / 4 = 80Mhz     48(0x20)        */
/* 		Progressive clock switching enabled                             */
/************************************************************************/
void ConfigFMPLLs(void)
{
  CGM.AC3SC.B.SELCTL = CGM_SELCTL_XOSC;				 //Reference for the FMPLL = XOSC
	CGM.AC4SC.B.SELCTL = CGM_SELCTL_XOSC;
	
	CGM.FMPLL[0].CR.R = 0x0D300100;  //IDF=4;ODF=4;NDIV=48;Enable progressive clock switch
	CGM.FMPLL[1].CR.R = 0x0D200100;  //IDF=4;ODF=4;NDIV=32;Enable progressive clock switch
}

/************************************************************************/
/* void InitializeModesAndClock(void) 	 											*/
/************************************************************************/
/* Desc: Configure PLL reference clocks and divider ration				*/
/* 		Assume an external Xtal at 40Mhz                                */
/* 		FMPLL freq = 40 / 4 x 48 / 4 = 120Mhz                           */
/* 		FMPLL1 sec output = 40 / 4 x 32 / 4 = 80Mhz                     */
/* 		Progressive clock switching enabled                             */
/************************************************************************/
/************************************************************************/
/* Switch to RUN0 mode with Xtal, FMPLL0 and FMPLL1 enabled             */
/************************************************************************/
extern uint8_t ME_SAFE_MODE_flag;
void InitializeModesAndClock(void) 
{
	// If device starts in SAFE mode, clear Fault latched in FCCU and reset the device
	if (ME.GS.B.S_CURRENT_MODE == ME_SAFE_MODE) 
	{ 
		clear_CF();
		clear_NCF();

		RGM.FES.R = 0xFFFF;     // Clear the FES
		RGM.FBRE.B.BE_SOFT_FUNC = 0; // RESET_B is asserted on a software 'functional' reset event.
		ME.MCTL.R = 0x00005AF0; // Change the mode to "reset" & Key
		ME.MCTL.R = 0x0000A50F; // Change the mode to "reset" & Key   	
   }
    
	ConfigFMPLLs();			//Configure PLLs
	ConfigPeripherals();	//Configure Peripherals
  
	ME.MER.R = 0x000025FF; 		  // Enable all mode in mode entry MODE_ENABLE REGISTER
	ME.RUN[0].R = 0x001F0030;     // Configure RUN 0 mode
	ME.RUN[1].R = 0x001F00F4;  	  // Configure RUN 1 mode

	ME.MCTL.R   = 0x40005AF0;      //  go to run 0 mode OPTIONAL
	ME.MCTL.R   = 0x4000A50F;      //  go to run 0 mode optional
	while(ME.GS.B.S_MTRANS==1){}   //  Wait for mode entry to complete
	while(ME.GS.B.S_CURRENT_MODE!=ME_RUN0_MODE){} //  Check RUN0 mode has been entered	

	ME.MCTL.R   = 0x50005AF0;      //  go to run 1 mode
	ME.MCTL.R   = 0x5000A50F;      //  go to run 1 mode
	while(ME.GS.B.S_MTRANS==1){}   //  Wait for mode entry to complete
	while(ME.GS.B.S_CURRENT_MODE!=ME_RUN1_MODE){} //  Check RUN1 mode has been entered
	
	ConfigAuxilliaryClocks();
}
