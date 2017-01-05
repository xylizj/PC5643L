#include "AD2S1210.h"

int16_t    SID_m_ct_VelocityRaw;
uint32_t   SID_m_ct_PositionRaw;
uint8_t    SID_m_swt_VelValid;
uint8_t    SID_m_swt_PosValid;
 
uint8_t initAD2S1210(void)
{
  uint32_t ReadData_tmp;
  uint32_t ChkData_tmp;  
  uint16_t i = 0;
  
  SIU.PCR[85].B.OBE = 1;//Output Buffer Enable
  SIU.PCR[84].B.OBE = 1;
  SIU.PCR[19].B.OBE = 1;
  SIU.PCR[94].B.OBE = 1;
  SIU.PCR[18].B.OBE = 1;
  
  SIU.PCR[86].B.OBE = 1;

  SIU.PCR[14].B.IBE = 1;//Input Buffer Enable
  SIU.PCR[15].B.IBE = 1;  
  
  AOD_reg_swt_V10En = 1;//Enable power supply
  
  AOD_reg_swt_RslvCS = 1;
  AOD_reg_swt_RslvSample = 1;
  //set config mode
  AOD_reg_swt_RslvA0 = 1;
  AOD_reg_swt_RslvA1 = 1;
  AOD_reg_swt_RslvCS = 0;//select chip
  
  //Rst AD2S1210
  AOD_reg_swt_RslvRst = 1;
  for (i = 0;i< 200;i ++)  {  }
  AOD_reg_swt_RslvRst = 0;
  for (i = 0;i< 50000;i ++)  {  }
  for (i = 0;i< 50000;i ++)  {  }
  for (i = 0;i< 50000;i ++)  {  }
  for (i = 0;i< 50000;i ++)  {  }
     
  DSPI_1.PUSHR.R = 0x00010091;//EXC Freq
  DSPI_1.PUSHR.R = 0x00010028;//10KHz
  DSPI_1.PUSHR.R = 0x00010092;//control
  DSPI_1.PUSHR.R = 0x08010070;//END OF QUEUE

  for (i = 0;DSPI_1.SR.B.EOQF == 0;i ++)
  {
  	if (i > 2000)
  	{
  		return 0;
  	}
  }	

  ReadData_tmp = DSPI_1.POPR.R;
  ReadData_tmp = DSPI_1.POPR.R;
  ChkData_tmp  = DSPI_1.POPR.R;
  ReadData_tmp = DSPI_1.POPR.R;
  DSPI_1.SR.R = 0x90000000;
  
  if (ChkData_tmp != 0x28)
  {
  	return 0;
  }
  
  AOD_reg_swt_RslvSample = 0;  
  for (i = 0;i< 40;i ++)  {  }  
  AOD_reg_swt_RslvSample = 1;
  
  DSPI_1.PUSHR.R = 0x000100FF;//Fault Reg
  DSPI_1.PUSHR.R = 0x080100FF;
  
  for (i = 0;DSPI_1.SR.B.EOQF == 0;i ++)
  {
  	if (i > 1000)
  	{
  		return 0;
  	}
  }	

  ChkData_tmp = DSPI_1.POPR.R;
  ReadData_tmp = DSPI_1.POPR.R;
  DSPI_1.SR.R = 0x90000000;

  if (ChkData_tmp != 0x70)
  {
  	return 0;
  }  
   
  AOD_reg_swt_RslvSample = 0;  
  for (i = 0;i< 40;i ++)  {  }  
  AOD_reg_swt_RslvSample = 1; //clear fault
  
  //set normal mode
  AOD_reg_swt_RslvA0 = 0;
  AOD_reg_swt_RslvA1 = 0;
//  AOD_reg_swt_RslvCS = 1;//deselect chip   
  
  return 1;
}


uint8_t AD2S1210FaultClear(void)
{
  uint32_t ReadData_tmp;
  uint32_t ChkData_tmp;
  uint16_t i = 0;
 
  AOD_reg_swt_RslvCS = 1;
  AOD_reg_swt_RslvSample = 1;
  //set config mode
  AOD_reg_swt_RslvA0 = 1;
  AOD_reg_swt_RslvA1 = 1;
  AOD_reg_swt_RslvCS = 0;//select chip
  
  AOD_reg_swt_RslvSample = 0;  
  for (i = 0;i< 40;i ++)  {  }  
  AOD_reg_swt_RslvSample = 1;
  
  DSPI_1.PUSHR.R = 0x000100FF;//Fault Reg
  DSPI_1.PUSHR.R = 0x080100FF;
  
  for (i = 0;DSPI_1.SR.B.EOQF == 0;i ++)
  {
  	if (i > 1000)
  	{
  		return 0;
  	}
  }	

  ChkData_tmp = DSPI_1.POPR.R;
  ReadData_tmp = DSPI_1.POPR.R;
  DSPI_1.SR.R = 0x90000000;

  if (ChkData_tmp != 0x70)
  {
  	return 0;
  }  
   
  AOD_reg_swt_RslvSample = 0;  
  for (i = 0;i< 40;i ++)  {  }  
  AOD_reg_swt_RslvSample = 1; //clear fault
  
  //set normal mode
  AOD_reg_swt_RslvA0 = 0;
  AOD_reg_swt_RslvA1 = 0;
//  AOD_reg_swt_RslvCS = 1;//deselect chip   
  
  return 1;	
}


void GetMotorPos(void)
{
  uint16_t i = 0;
  
  AOD_reg_swt_RslvSample = 0;  
  for (i = 0;i< 8;i ++)  {  }  
  AOD_reg_swt_RslvSample = 1;
  
  DSPI_1.PUSHR.R = 0x18010000;//use ctar1
  //DSPI_1.PUSHR.R = 0x08010000;     
}

void ReadMotorPos(void)
{
  
  if (DSPI_1.SR.B.EOQF == 0)
  {
  	SID_m_swt_PosValid = 0;
  	return;
  }
   
  SID_m_ct_PositionRaw = DSPI_1.POPR.R;
  DSPI_1.SR.R = 0x90000000;
  SID_m_swt_PosValid = 1;
}

void GetMotorVel(void)
{
  uint16_t i = 0;
  
  AOD_reg_swt_RslvA1 = 1;//change mode
  
  //AOD_reg_swt_RslvSample = 0;  
  for (i = 0;i< 8;i ++)  {  }  
  //AOD_reg_swt_RslvSample = 1;
  
  DSPI_1.PUSHR.R = 0x18010000;//use ctar1
  //DSPI_1.PUSHR.R = 0x08010000;     
}


void ReadMotorVel(void)
{
  
  if (DSPI_1.SR.B.EOQF == 0)
  {
  	SID_m_swt_VelValid = 0;
  	return;
  }
   
  SID_m_ct_VelocityRaw = (uint16_t)(DSPI_1.POPR.R);
  DSPI_1.SR.R = 0x90000000;
  SID_m_swt_PosValid = 1;
  
  AOD_reg_swt_RslvA1 = 0;//change mode  
}













