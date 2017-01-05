/************************************************************************/
/* File Name:      Sysclk.c
/* Description:    system clock definition
/* Comments:       Pll
/*
/* Version     Date           Author           Remark
/* -------  ----------   --------------   ------------------------------      
/*
/************************************************************************/

/* include */
#include "mcu.h"
#include "clocks_modes.h"
//#include "VFB.h"
/***************************************************/
/*  function name:  Mcu_Init() 
/*  description:    initialize the can module
/*  parameters:     none
/*  return values:  none
/*  remark:
/***************************************************/
void Mcu_Init(void)
{
  InitializeModesAndClock();    /* Initialize mode entries and system clock */
  disableWatchdog();      /* Disable watchdog */
}

//----------------------------------------------------//
void disableWatchdog(void) 
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  //SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
	SWT.CR.B.WEN = 0x0;
}        

void EnableWatchdog(void)
{
	SWT.SR.R = 0x0000c520;     // Write keys to clear soft lock bit
	SWT.SR.R = 0x0000d928;
	SWT.TO.B.WTO = 0x0002EE20; //watch dog 1.5s;
	SWT.CR.R = 0x8000010F;   // watch dog Eanble;
}

void FeedWatchdog(void)
{
	SWT.SR.R = 0x0000a602;  // Write keys to feed watchdog
	SWT.SR.R = 0x0000b480;
}



void enableIrq(void) 
{
    INTC.CPR.B.PRI = 0;          /* Single Core: Lower INTC's current priority */
    asm(" wrteei 1");	    	   /* Enable external interrupts */
}

void disableIrq(void)
{
   	asm(" wrteei 0");           /* Unable external interrupts */	
}





void delay_us(uint16_t n)
{
	uint32_t i;
	for(i=0;i<8*n;i++);	
}


