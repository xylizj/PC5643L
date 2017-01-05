#include "MPC5643L.h"
#include "PIT.h"
#include "IntcInterrupts.h"

/********************************************************************/
void PIT0_Init(void)
{
 //INTC_InstallINTCInterruptHandler(PIT0_Isr, PIT0, 1);

 PIT.PITMCR.R      = 0x01;// Enable clk for PIT, stop PITs in debug mode
 //PIT.PITMCR.R      = 0x00;// Enable clk for PIT,  PITs continue to run in debug mode
 
 PIT.CH[0].LDVAL.R = 12000;       // Timeout=LDVAL/SYSCLKS = 120/120M = 1us
 PIT.CH[0].TFLG.B.TIF = 1;           // Clear PIT 0 flag by writing 1

 //PIT.CH[0].TCTRL.B.TEN = 1;
 //PIT.CH[0].TCTRL.B.TIE = 1;      // Enable interrupt from PIT0
 //PIT.CH[0].TCTRL.B.TEN = 0;
}


void PIT1_Init(void)
{
 //PIT.PITMCR.R      = 0x01;// Enable clk for PIT, stop PITs in debug mode
 PIT.PITMCR.R      = 0x00;// Enable clk for PIT,  PITs continue to run in debug mode
 
 PIT.CH[1].LDVAL.R = 12000;       // Timeout=LDVAL/SYSCLKS = 120/120M = 1us
 PIT.CH[1].TFLG.B.TIF = 1;           // Clear PIT 0 flag by writing 1
}


void PIT0_Enable(void)
{
 PIT.CH[0].TCTRL.B.TEN = 1;      // start PIT0 counting 0xC3FF0000UL+0x100+8
}

void PIT1_Enable(void)
{
 PIT.CH[1].TCTRL.B.TEN = 1;      // start PIT0 counting 0xC3FF0000UL+0x100+8
}


void PIT0_Disable(void)
{
 PIT.CH[0].TCTRL.B.TEN = 0;      // stop PIT0 counting
}














//=====PIT0_Isr=======================================================
/*void PIT0_Isr( void ) 
{
 PIT.CH[0].TFLG.B.TIF = 1;           // Clear PIT 0 flag by writing 1
 
 charTimer0OV = 1;
 
 PIT_OS_NumCount++;
 //while(!PIT.CH[0].TFLG.R) {};    // wait entire period in loop; only for debugging purposes in order to visualize nesting from PIT1_Isr                                   
}*/




void PIT0_Isr(void)
{
 PIT0_Disable();	 
 PIT.CH[0].TFLG.B.TIF = 1;           // Clear PIT 0 flag by writing 1
 
 SchM_Period1Ms();

 PIT0_Enable();  
}



void PIT1_Delay(uint32_t usDly)
{
 
 	PIT.CH[1].LDVAL.R = 64 * usDly;
 	PIT.CH[1].TCTRL.R = 0x1;
	
	while(!PIT.CH[1].TFLG.B.TIF){}
	PIT.CH[1].TFLG.B.TIF = 1;
	
	PIT.CH[1].TCTRL.R = 0x0;
}