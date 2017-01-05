/*******************************************************************************
*
*  FILE
*     Dem_Appl.c
*
*  DESCRIPTION
*       
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
*    1.1.0
*
*******************************************************************************/

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Dem.h"
#include "VFB.h"
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
extern uint16 EEC1_EngSpd;
/*******************************************************************************
* Global Variables definition                         
*******************************************************************************/

/*******************************************************************************
* Local Variables definition                         
*******************************************************************************/
_STATIC_ VAR(boolean,DEM_VAR) dem_DrvCycleReachFlag; 
_STATIC_ boolean dem_WarmUpCycleReachFlag; 
_STATIC_ uint8 dem_CltTempInit;
_STATIC_ boolean dem_CltTempInitFlg;




/*******************************************************************************
* Local Functions prototypes                         
*******************************************************************************/


/*******************************************************************************
*  Global Functions Body                                   
*******************************************************************************/
//#pragma CODE_SEG __NEAR_SEG NON_BANKED //masked by xyl 2015-08-04

/*******************************************************************************
* NAME:             Dem_ApplDrvCycleRisingEdge
* CALLED BY:        Dem_MainFunction
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    E_OK: Driving Cycle is reached
*                   E_NOT_OK: Driving Cycle is not reached.
* DESCRIPTION:      Get the Error Status (Freeze Frame)  
*******************************************************************************/
FUNC(void,DEM_CODE) Dem_ApplDrvCycleRisingEdge(void)
{
  if (dem_DrvCycleReachFlag == FALSE)
  {    
    /* Implemented by the customer*/
    if ((EEC1_EngSpd > 1600)&&(EEC1_EngSpd<0xFE00))  
    {	
      dem_DrvCycleReachFlag = TRUE;
      
      Dem_UpdateOperCycle();
    }     
  }      
}

FUNC(Std_ReturnType,DEM_CODE) Dem_ApplWarmUpCycleRisingEdge(void)
{
  /* Implemented by the customer*/
 
  if (dem_WarmUpCycleReachFlag == FALSE)
  {
    if (
        (dem_CltTempInitFlg == FALSE) && 
         (EEC1_EngSpd == 0) &&
         (ET1_EngClntTemp < 0xFE)
        )
    {
      dem_CltTempInit = ET1_EngClntTemp;
      dem_CltTempInitFlg =  TRUE;
    }
    
    if (
        (dem_CltTempInitFlg == TRUE) &&
         (EEC1_EngSpd != 0) &&
         (ET1_EngClntTemp < 0xFE)
        ) 
    {
      /* Coolant Temperature over 70degC and rising at least 22 degC*/
      if (
          (ET1_EngClntTemp > 110) &&
          ((ET1_EngClntTemp - dem_CltTempInit) > 22)
         )
      {
        dem_WarmUpCycleReachFlag = TRUE;
        return E_OK; 
      }
         
    }
  }
  
  return (E_NOT_OK);  
  
}

//#pragma CODE_SEG DEFAULT



//!<	====================================================================
//!<	================	add by xyl 2015-08-04	=================
/* Monitor status since DTCs cleared   */
Std_ReturnType Dem_ApplGetPID01(uint8 *txBuffer)
{
	txBuffer[0] = Dem_GetEmRelatedDtcNumAMil();
	txBuffer[1] = 0;
	txBuffer[2] = 0;
	txBuffer[3] = 0;
	
	return E_OK;
}

/* Calculated LOAD Value  */
Std_ReturnType Dem_ApplGetPID04(uint8 *txBuffer)
{
	uint8 temp;
	
  if (EEC2_EngLoad > 125)
  {
    temp = 0;  
  }else if (EEC2_EngLoad > 100)
  {
    temp = 255;
  }else
  {
    temp = ((uint16)(EEC2_EngLoad) * 255)/100;
  }

	txBuffer[0] = temp;
	
	return E_OK;
}

/* Engine Coolant Temperature */
Std_ReturnType Dem_ApplGetPID05(uint8 *txBuffer)
{
	uint8 temp;
	
  if (ET1_EngClntTemp > 250)
  {
    temp = 0;  
  }else
  {
    temp = ET1_EngClntTemp;
  }
  
  txBuffer[0] = temp;            
	
	return E_OK;
}

/* Intake manifold absolute pressure */
Std_ReturnType Dem_ApplGetPID0B(uint8 *txBuffer)
{
	uint8 temp;
	
  if (IC1_BoostPressure > 250)
  {
    temp = 0;  
  }else if (IC1_BoostPressure > 0x7F)
  {
    temp = 0xFF;
  }else
  {
    temp = IC1_BoostPressure << 1;
  }

  txBuffer[0] = temp;            
	
	return E_OK;
}

/* Engine RPM   */
Std_ReturnType Dem_ApplGetPID0C(uint8 *txBuffer)
{
	uint16 temp;
            
  if (EEC1_EngSpd >= 0xFF00)
  {
    temp = 0; 
  }else
  {
    temp = EEC1_EngSpd >> 1;
  }

	*(uint16 *)(txBuffer) = temp;
	
	return E_OK;
}

/* Vehicle Speed Sensor  */
Std_ReturnType Dem_ApplGetPID0D(uint8 *txBuffer)
{
	uint8 temp;
	
	if (TCO1_VehSpd >= 0xFF00)
  {
    temp = 0;  
  }else
  {
    temp = (uint8)(TCO1_VehSpd >> 8);
  }

  txBuffer[0] = temp;            	
	
	return E_OK;
}

/* Intake Air Temperature  */
Std_ReturnType Dem_ApplGetPID0F(uint8 *txBuffer)
{
  uint8 temp;
  if (IC1_BoostTemp > 250)
  {
    temp = 0;  
  }else
  {
    temp = IC1_BoostTemp;
  } 
	
	txBuffer[0] = temp;
	txBuffer[1] = 0;//add to take a empty place
	
	return E_OK;
}

/* OBD requirements to which vehicle is designed */
Std_ReturnType Dem_ApplGetPID1C(uint8 *txBuffer)
{
	txBuffer[0] = 0X01;//OBD II
	
	return E_OK;
}



/* Calculated LOAD Value  */
Std_ReturnType Dem_ApplGetPID04FreezeData(uint8 *txBuffer)
{
	txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].EngLoad;
	
	return E_OK;
}


/* Engine Coolant Temperature */
Std_ReturnType Dem_ApplGetPID05FreezeData(uint8 *txBuffer)
{
  txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].EngTemp;            
	
	return E_OK;
}

/* Intake manifold absolute pressure */
Std_ReturnType Dem_ApplGetPID0BFreezeData(uint8 *txBuffer)
{
  txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].BoostPressure;            
	
	return E_OK;
}

/* Engine RPM   */
Std_ReturnType Dem_ApplGetPID0CFreezeData(uint8 *txBuffer)
{
	txBuffer[0] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].EngSpd & 0xFF);
	txBuffer[1] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].EngSpd>>8);

	return E_OK;
}

/* Vehicle Speed Sensor  */
Std_ReturnType Dem_ApplGetPID0DFreezeData(uint8 *txBuffer)
{
	txBuffer[0] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Velocity & 0xFF);
	txBuffer[1] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Velocity>>8);

	return E_OK;
}

Std_ReturnType Dem_ApplGetPIDE1FreezeData(uint8 *txBuffer)
{
	txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].EngTrqMode;
	
	return E_OK;
}

Std_ReturnType Dem_ApplGetPIDE2FreezeData(uint8 *txBuffer)
{
  txBuffer[0] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Odometer>>0);
  txBuffer[1] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Odometer>>8);
  txBuffer[2] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Odometer>>16);
  txBuffer[3] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Odometer>>24);
	
	return E_OK;
}

Std_ReturnType Dem_ApplGetPIDE3FreezeData(uint8 *txBuffer)
{
  txBuffer[0] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].BattVolt>>0);
  txBuffer[1] = (uint8)(dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].BattVolt>>8);
	
	return E_OK;
}


Std_ReturnType Dem_ApplGetPIDE4FreezeData(uint8 *txBuffer)
{
	txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Year;
	return E_OK;
}

Std_ReturnType Dem_ApplGetPIDE5FreezeData(uint8 *txBuffer)
{
	txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Month;
	return E_OK;
}

Std_ReturnType Dem_ApplGetPIDE6FreezeData(uint8 *txBuffer)
{
	txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Day;
	return E_OK;
}

Std_ReturnType Dem_ApplGetPIDE7FreezeData(uint8 *txBuffer)
{
	txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Hour;
	return E_OK;
}

Std_ReturnType Dem_ApplGetPIDE8FreezeData(uint8 *txBuffer)
{
	txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Minute;
	return E_OK;
}

Std_ReturnType Dem_ApplGetPIDE9FreezeData(uint8 *txBuffer)
{
	txBuffer[0] = dem_ErrMemoEntry[dem_MemEntryNextEmpty-1].Second;
	return E_OK;
}

const uint8 Dcm_C_Vin[OBD_VIN_LENGTH] = 
{
	'L','D','C','9','1','3','L','2','2','4','0','0','0','0','0','2','3'
};

Std_ReturnType Dem_ApplInfoType02(uint8 *txBuffer)//VIN
{
	uint8 i;
	
	for(i=0; i<OBD_VIN_LENGTH; i++)
	{
		txBuffer[i] = Dcm_C_Vin[i];	
	}
	
	return E_OK;
}




const uint8 Dcm_C_Calid[OBD_CALID_LENGTH] = 
{
	'J','M','A','*','4','3','1','2','9','9','1','1','0','0','0','0'
};

Std_ReturnType Dem_ApplInfoType04(uint8 *txBuffer)//CALID
{
	uint8 i;
	
	for(i=0; i<OBD_CALID_LENGTH; i++)
	{
		txBuffer[i] = Dcm_C_Calid[i];	
	}
	
	return E_OK;
}

/*******************************************************************************
*  Local Functions Body                                   
*******************************************************************************/


