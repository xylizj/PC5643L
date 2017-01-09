/*******************************************************************************
*
*  FILE
*     Ioa.c
*
*  DESCRIPTION
*     Source File for IO abstraction   
*      
*       
*  COPYRIGHT
*     
*     All rights reserved.
*
*  AUTHOR
*   
*
*  VERSION
*    1.0.0
*
*******************************************************************************/

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Ioa.h"
//#include "Dem.h"


/*******************************************************************************
* Defines                                                                
*******************************************************************************/

/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Constant definition                         
*******************************************************************************/

/*******************************************************************************
* Local Constant definition                         
*******************************************************************************/

/*******************************************************************************
* Global Variables definition                         
*******************************************************************************/
uint8_t SID_m_swt_PhaDrvFaultRaw;
uint8_t SID_m_swt_ExcDrvFaultRaw;

uint8_t SID_m_swt_IGNRaw;
uint8_t SID_m_swt_ENRaw;
uint8_t SID_m_swt_RsolvDOSRaw;
uint8_t SID_m_swt_RsolvLOTRaw;



void Ioa_Init(void)
{
	//Ioa_GPIOInit();
	/*SIU.PCR[CTL_PHASE_DRV_ENABLE_PAD_NUM].B.OBE = 1;//三相驱动使能，高电平有效
	Ioa_PhaseDrvDisable();
	SIU.PCR[CTL_PHASE_DRV_FAULT_RESET_PAD_NUM].B.OBE = 1;//三相预驱故障复位，默认输出低电平
	Ioa_PhaseDrvFaultReset();
	
	SIU.PCR[I_S_PHASEFLT_PAD_NUM].B.IBE = 1;
	SIU.PCR[I_S_EXCFLT_PAD_NUM].B.IBE = 1;*/
	
	//SIU.PCR[O_S_SysPWRCtrl_PAD_NUM].B.OBE = 1;
}


_STATIC_ void Ioa_ReadSwtValue(void)
{
  SID_m_swt_PhaDrvFaultRaw = !GET_STATUS(I_S_PHASEFLT_PAD_NUM);
  SID_m_swt_ExcDrvFaultRaw = !GET_STATUS(I_S_EXCFLT_PAD_NUM);    	   
}


void Ioa_Input(void)
{
	Ioa_ReadSwtValue();
}


void Ioa_PhaseDrvEnable(void)
{
	SET_STATUS(CTL_PHASE_DRV_ENABLE_PAD_NUM);
}

void Ioa_PhaseDrvDisable(void)
{
	RESET_STATUS(CTL_PHASE_DRV_ENABLE_PAD_NUM);
}


void Ioa_PhaseDrvFaultReset(void)
{
	SIU.GPDO[CTL_PHASE_DRV_FAULT_RESET_PAD_NUM].R=1;
	delay_us(25);
	SIU.GPDO[CTL_PHASE_DRV_FAULT_RESET_PAD_NUM].R=0;
}

void Ioa_Output(void)
{
	SIU.GPDO[O_S_SysPWRCtrl_PAD_NUM].R=1;
	
}
