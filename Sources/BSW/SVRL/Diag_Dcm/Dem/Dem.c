/*******************************************************************************
*
*  FILE
*     Dem.c
*
*  DESCRIPTION
*     Source Code File for Dem Module  
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
#include "Det.h"
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
boolean dem_TrqLmtOut;
boolean Dem_stClear;
Dem_FaultMemType dem_ErrMemoEntry[DEM_MEM_ENTRY_NUM];
uint8 dem_MemEntryNextEmpty;



uint16 dem_EngFaultCurr[DEM_ENG_FAULT_WORD];
uint16 dem_EngFaultOld[DEM_ENG_FAULT_WORD];


const uint16 Hex[16]=
{
  0x8000,
  0x4000,
  0x2000,  
  0x1000,
  0x0800,  
  0x0400,
  0x0200,
  0x0100,
  0x80,
  0x40,
  0x20,
  0x10,
  0x08,
  0x04,
  0x02,
  0x01,
};

/*******************************************************************************
* Local Constant definition                         
*******************************************************************************/

/*******************************************************************************
* Global Variables definition                         
*******************************************************************************/


/*******************************************************************************
* Local Variables definition                         
*******************************************************************************/
_STATIC_ uint8 dem_ClrCnt;
_STATIC_ Dem_FaultStatusType dem_errStatus[DEM_EVENT_TOT_NUM];
_STATIC_ boolean Dem_stClearOld;
_STATIC_ boolean dem_StatusErrFlg;


/*******************************************************************************
* Local Functions prototypes                         
*******************************************************************************/
_STATIC_ Dem_ChksumType DEM_CODE Dem_FaultMemChksumCal(void);
_STATIC_ void DEM_CODE Dem_ErrMemUpdate(Dem_EventIdType EventId, uint8 EventStatus);
_STATIC_ void DEM_CODE Dem_FaultMemClrUpdateEntry(uint8 entryNum);
_STATIC_ void DEM_CODE Dem_ErrStoreToEmptyEntry(Dem_EventIdType EventId,uint8 entryNum);
_STATIC_ void DEM_CODE Dem_UpdateState(void);
_STATIC_ void DEM_CODE Dem_ErrStatusInit(void);
_STATIC_ void DEM_CODE Dem_SetTrqLmtCounter(uint8 entryNum); 
_STATIC_ void DEM_CODE Dem_SetDeleteCounter(uint8 entryNum);
_STATIC_ void DEM_CODE Dem_TrqLmtOutput(void);
_STATIC_ void DEM_CODE Dem_UpdateEngRunCounter(void);
_STATIC_ void DEM_CODE Dem_UpdateWarmUpCycleCounter(void);
_STATIC_ void DEM_CODE Dem_UpdateTimeCounter(void);
_STATIC_ void DEM_CODE Dem_SetPostHealCounter(uint8 entryNum);
_STATIC_ void DEM_CODE Dem_FaultMemClrEntry(uint8 entryNum);
_STATIC_ void DEM_CODE Dem_StoreFreezeFrame(uint8 entry);
/*******************************************************************************
*  Global Functions Body                                   
*******************************************************************************/
//#pragma CODE_SEG __NEAR_SEG NON_BANKED //masked by xyl 2015-08-04
/*******************************************************************************
* NAME:             Dem_Init
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      Initialize Fault Memory   
*******************************************************************************/
void DEM_CODE Dem_Init(void)
{
   Dem_ErrStatusInit();        
}
/*******************************************************************************
* NAME:             Dem_SetError
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Dem_EventIdType EventId:
*                   uint8* buffer: Data Buffer Pointer
* RETURN VALUES:    Void
* DESCRIPTION:      Set the Error Status 
*******************************************************************************/
Std_ReturnType DEM_CODE Dem_SetError(Dem_EventIdType EventId, uint8 EventStatus)
{
#if 0  

#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (EventId >= DEM_EVENT_TOT_NUM)
  {
    Det_ReportError(DEM_MODULE_ID,DEM_INSTANCE_ID,DEM_API_SETERROR_ID,DEM_E_INVALID_INDEX);
    return E_NOT_OK;
  }
  if (EventStatus > DEM_ERR_STATUS_MAX)
  {
    Det_ReportError(DEM_MODULE_ID,DEM_INSTANCE_ID,DEM_API_SETERROR_ID,DEM_E_INVALID_ERRSTATUS);
    return E_NOT_OK;
  }
#endif   
  
  if (dem_errStatus[EventId].Bits.active!= EventStatus)
  { 
    dem_errStatus[EventId].Bits.active = EventStatus;	
    Dem_ErrMemUpdate(EventId,EventStatus); 
  }
  /* UPDATE THE FAULT MEM WHENEVER THE FAULT IS ACTIVE AND NOT IN MEM */
  else if ((dem_errStatus[EventId].Bits.active == TRUE) &&\
    (dem_errStatus[EventId].Bits.mem == FALSE))
  {
    Dem_ErrMemUpdate(EventId,EventStatus);  
  }
  return E_OK;
  #endif
}

/*******************************************************************************
* NAME:             Dem_GetError
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Dem_EventIdType EventId:
* RETURN VALUES:    uint8: Error Status
* DESCRIPTION:      Get the Error Status 
*******************************************************************************/
uint8 DEM_CODE Dem_GetError(Dem_EventIdType EventId)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (EventId >= DEM_EVENT_TOT_NUM)
  {
    Det_ReportError(DEM_MODULE_ID,DEM_INSTANCE_ID,DEM_API_SETERROR_ID,DEM_E_INVALID_INDEX);
    return E_NOT_OK;
  }
#endif
  return (dem_errStatus[EventId].Bits.active);
}



/*******************************************************************************
* NAME:             Dem_MainFunction
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      Must be called cyclely,  1 second
*******************************************************************************/
void DEM_CODE Dem_MainFunction(void)
{ 
  //Dem_ChkEngFault();
  
  Dem_ApplDrvCycleRisingEdge(); 

  if(DEM_ENG_RUN() != 0)
  {	
    Dem_UpdateEngRunCounter();		
  }
  
  if (Dem_ApplWarmUpCycleRisingEdge() == E_OK)
  {
    Dem_UpdateWarmUpCycleCounter();  
  }
  
  Dem_UpdateTimeCounter();
  
  Dem_UpdateState();     
  
  /* Clear the Fault Memory using Calibration Tool */
  if ((Dem_stClear_C == TRUE)&&(Dem_stClearOld != Dem_stClear_C))
  {
    Dem_FaultMemClearAll();    
  }
  Dem_stClearOld = Dem_stClear_C;
  
  /* Delay the Clear to reset the Application Fault Monitoring */
  if (Dem_stClear == TRUE)
  {
    dem_ClrCnt++;
    if (dem_ClrCnt > DEM_CLR_DELAY)
    {
      Dem_stClear = FALSE;
      dem_ClrCnt = 0;
    }  
  }
  
  Dem_TrqLmtOutput(); 
}


void Dem_UpdEngFaultCnt(void)
{
	uint8 index;
	Dem_EventIdType eventId; 
	
	for (index=0;index<dem_MemEntryNextEmpty;index++)
	{
	  eventId = (dem_ErrMemoEntry[index].EventId - 1);
	  
	  if (eventId >= EVENT_NUM_ENG_FAULT_START)
	  {	    
    	  if (dem_ErrMemoEntry[index].StsUpdCnt != 0)
    	  {
    	    dem_ErrMemoEntry[index].StsUpdCnt--;  
    	  }
	  }
	}   
}
/*******************************************************************************
* NAME:             Dem_DM1Assembly
* CALLED BY:        J1939
* PRECONDITIONS:    
* INPUT PARAMETERS: uint8* dataPtr : pointer to data buffer
*                   uint8 maxErrNum: max error Number that the buffer could 
*                                    store
* RETURN VALUES:    uint8:  data length of the error 
* DESCRIPTION:      Assembly the Error Information that DM1 message required.
*******************************************************************************/
uint8 DEM_CODE Dem_DM1Assembly(uint8* dataPtr,uint8 maxErrNum)
{
  Dem_EventIdType err_Index;
  uint8 index;  
  uint8 errActiveNum;
  uint8* tmpDataPtr;
  uint16 lampStatus;
  
  /* Initialize max error class and active error number */
  errActiveNum = 0;
  lampStatus = 0;
  
  tmpDataPtr = dataPtr + 2;
  /* Search for the Error which is already in the Error memory */  
	for (index=0; index < dem_MemEntryNextEmpty; index++)
	{
	  if ( 
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_CONFIRMED) || 
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_HEALING) ||
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_POST_HEAL))
	  {
      err_Index = (dem_ErrMemoEntry[index].EventId - 1);
      
      if (err_Index >= EVENT_NUM_ENG_FAULT_START)
      {
        uint8 engFaultIndex;
        lampStatus |= MIL_LAMP_ON; 
        errActiveNum++;
        engFaultIndex =  err_Index - EVENT_NUM_ENG_FAULT_START;
        *(uint32*)(tmpDataPtr) = Dem_EngFaultCode[engFaultIndex].SPN_FMI ;
        *(tmpDataPtr+3) = dem_ErrMemoEntry[index].ErrOccurCounter;
        tmpDataPtr +=4;
      }else
      {
        lampStatus |= Dem_ErrJ1939FaultCode[err_Index].LampStatus;

        if (dem_ErrMemoEntry[index].ErrState != DEM_ERRMEM_POST_HEAL)
        {        
    	    errActiveNum++;
          
          *tmpDataPtr = (uint8)(Dem_ErrJ1939FaultCode[err_Index].SPN & 0xFF);
          *(tmpDataPtr+1) = (uint8)((Dem_ErrJ1939FaultCode[err_Index].SPN>>8)& 0xFF);
          *(tmpDataPtr+2) = Dem_ErrJ1939FaultCode[err_Index].FMI;
          *(tmpDataPtr+3) = dem_ErrMemoEntry[index].ErrOccurCounter;
          tmpDataPtr +=4;
        }
      }
      
 	    if (errActiveNum >=maxErrNum)
      {
        break;
      } 
	  }
	}

  *((uint16*)(dataPtr)) = lampStatus;     
	
	return (4*errActiveNum+2);
}

/*******************************************************************************
* NAME:             Dem_DM4Assembly
* CALLED BY:        J1939
* PRECONDITIONS:    
* INPUT PARAMETERS: uint8* dataPtr : pointer to data buffer
*                   uint8 maxErrNum: max error Number that the buffer could 
*                                    store
* RETURN VALUES:    uint8:  data length of the error 
* DESCRIPTION:      Assembly the Error Information that DM1 message required.
*******************************************************************************/
uint8 DEM_CODE Dem_DM4Assembly(uint8* dataPtr,uint8 maxErrNum)
{
  Dem_EventIdType err_Index;
  uint8 index;  
  uint8 errActiveNum;
  uint8* tmpDataPtr;
  
  /* Initialize max error class and active error number */
  errActiveNum = 0;
  
  tmpDataPtr = dataPtr + 1;
  /* Search for the Error which is already in the Error memory */  
	for (index=0; index < dem_MemEntryNextEmpty; index++)
	{
	  if ( 
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_CONFIRMED) || 
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_HEALING) ||
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_POST_HEAL)||
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_DELETING))
	  {
	    errActiveNum++;

      err_Index = (dem_ErrMemoEntry[index].EventId - 1);
      if (err_Index >= EVENT_NUM_ENG_FAULT_START)
      {
        uint8 engFaultIndex;
        engFaultIndex =  err_Index - EVENT_NUM_ENG_FAULT_START;
        *(uint32*)(tmpDataPtr) = Dem_EngFaultCode[engFaultIndex].SPN_FMI ;
      }else
      {
        *tmpDataPtr = (uint8)(Dem_ErrJ1939FaultCode[err_Index].SPN & 0xFF);
        *(tmpDataPtr+1) = (uint8)((Dem_ErrJ1939FaultCode[err_Index].SPN>>8)& 0xFF);
        *(tmpDataPtr+2) = Dem_ErrJ1939FaultCode[err_Index].FMI;        
      }

      *(tmpDataPtr+3) = dem_ErrMemoEntry[index].ErrOccurCounter;
      *(tmpDataPtr+4) = dem_ErrMemoEntry[index].EngTrqMode;
      *(tmpDataPtr+5) = dem_ErrMemoEntry[index].BoostPressure;
      *(tmpDataPtr+6) = (uint8)(dem_ErrMemoEntry[index].EngSpd & 0xFF);
      *(tmpDataPtr+7) = (uint8)(dem_ErrMemoEntry[index].EngSpd>>8);
      *(tmpDataPtr+8) = dem_ErrMemoEntry[index].EngLoad;
      *(tmpDataPtr+9) = dem_ErrMemoEntry[index].EngTemp;
      *(tmpDataPtr+10) = (uint8)(dem_ErrMemoEntry[index].Velocity & 0xFF);
      *(tmpDataPtr+11) = (uint8)(dem_ErrMemoEntry[index].Velocity>>8);
      *(tmpDataPtr+12) = (uint8)(dem_ErrMemoEntry[index].Odometer&0xFF);
      *(tmpDataPtr+13) = (uint8)((dem_ErrMemoEntry[index].Odometer &0xFF00)>>8);
      *(tmpDataPtr+14) = (uint8)((dem_ErrMemoEntry[index].Odometer&0xFF0000)>>16);
      *(tmpDataPtr+15) = (uint8)((dem_ErrMemoEntry[index].Odometer>>24));
      *(tmpDataPtr+16) = (uint8)(dem_ErrMemoEntry[index].BattVolt & 0xFF);
      *(tmpDataPtr+17) = (uint8)(dem_ErrMemoEntry[index].BattVolt>>8);
      *(tmpDataPtr+18) = dem_ErrMemoEntry[index].Year;
      *(tmpDataPtr+19) = dem_ErrMemoEntry[index].Month;
      *(tmpDataPtr+20) = dem_ErrMemoEntry[index].Day;
      *(tmpDataPtr+21) = dem_ErrMemoEntry[index].Hour;
      *(tmpDataPtr+22) = dem_ErrMemoEntry[index].Minute;
      *(tmpDataPtr+23) = dem_ErrMemoEntry[index].Second;
      *(tmpDataPtr+24) = dem_ErrMemoEntry[index].ErrState;
      *(tmpDataPtr+25) = (uint8)(dem_ErrMemoEntry[index].EngRunTimeSinceMILOn&0xFF);
      *(tmpDataPtr+26) = (uint8)((dem_ErrMemoEntry[index].EngRunTimeSinceMILOn &0xFF00)>>8);
      *(tmpDataPtr+27) = (uint8)((dem_ErrMemoEntry[index].EngRunTimeSinceMILOn&0xFF0000)>>16);
      *(tmpDataPtr+28) = (uint8)((dem_ErrMemoEntry[index].EngRunTimeSinceMILOn>>24));         
      
      tmpDataPtr += DEM_DM4_FREEZE_FRAME_LENGTH;

	    if (errActiveNum >=maxErrNum)
	    {
	      break;
	    }
	  }
	}

  if (errActiveNum == 0)
  {
    *(dataPtr) = 0;
    *(dataPtr+1) = 0;
    *(dataPtr+2) = 0;
    *(dataPtr+3) = 0;
    *(dataPtr+4) = 0;
    return 5;  
  }else
  {    
    *((uint8*)(dataPtr)) = DEM_DM4_FREEZE_FRAME_LENGTH;     	
  	return (DEM_DM4_FREEZE_FRAME_LENGTH*errActiveNum+1); 
  }
}

/*******************************************************************************
* NAME:             Dem_FaultMemClearAll
* CALLED BY:        Dcm
* PRECONDITIONS:    
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      Clear whole fault memory
*******************************************************************************/
void DEM_CODE Dem_FaultMemClearAll(void)
{
  uint8 index;
  
  for(index = 0; index < DEM_MEM_ENTRY_NUM; index++)
  {
    Dem_FaultMemClrEntry(index);
  }
  
  for(index = 0; index < DEM_EVENT_TOT_NUM; index++ )
  {
    dem_errStatus[index].byte = (0);
  }
  Dem_stClear = TRUE;
  dem_MemEntryNextEmpty = 0;  
}

/*******************************************************************************
*  Local Functions Body                                   
*******************************************************************************/
 void DEM_CODE Dem_ChkEngFault(void)
{
  uint8 index;
  uint8 index1;
  

  /* DM1_E not received, do nothing */
  if (DM1E_FaultNum ==0xFF)
  {
    return;
  }
  
  /* check to activate the defect */   
  for (index = 0; index<DM1E_FaultNum; index++)
  {
    /* binary search */
    //sint16 mid;
    //sint16 front;
    //sint16 back; //20160518 XYL
    uint8 mid;
    uint8 front;
    uint8 back;
    uint8 result;
      
    mid = 0;
    front = 0;
    back = DEM_ENG_FAULT_NUM - 1;
    result = 0xFF;
    
    while (front<=back)
    {
      mid = (front + back)/2;
      if (Dem_EngFaultCode[mid].SPN_FMI == DM1E_FaultCode[index])
      {
        result = mid;
        break;
      }
      if (Dem_EngFaultCode[mid].SPN_FMI < DM1E_FaultCode[index])
      {
        front = mid + 1;
      }else
      {
        back =  mid - 1;
      }
    }

    /*
    result = Binary_search(Dem_EngFaultCode,DEM_ENG_FAULT_NUM,DM1E_FaultCode[index]);
    */
    if (result != 0xFF)
    {
        Dem_SetError(result + EVENT_NUM_ENG_FAULT_START,DEM_ERRMEM_ACTIVE);
        dem_EngFaultCurr[result/16] |= Hex[result&0xF];          
    }
  }
 
 /* check to deactivate the defect */    
 for (index = 0; index<DEM_ENG_FAULT_WORD; index++)
 {
    uint16 temp;
    temp = dem_EngFaultOld[index] & (~ dem_EngFaultCurr[index]); 
    if (temp != 0)
    {
      for (index1=0;index1<16;index1++)
      {
        if ((temp & Hex[index1]) != 0)
        {
          uint8 eventid;
          eventid = index*16 + index1 + EVENT_NUM_ENG_FAULT_START; 
          Dem_SetError(eventid,DEM_ERRMEM_PASSIVE);  
        }
      }
    }
    dem_EngFaultOld[index] = dem_EngFaultCurr[index];
    dem_EngFaultCurr[index] = 0;        
 }    
}

/*******************************************************************************
* NAME:             Dem_ErrStatusInit
* CALLED BY:        Dem
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      Initialize the Error Status
*******************************************************************************/
_STATIC_ void DEM_CODE Dem_ErrStatusInit(void)
{
  uint8 index;
  Dem_EventIdType err_Index;  
    
  for (index = 0;index < DEM_MEM_ENTRY_NUM;index++)
  {   
    if (dem_ErrMemoEntry[index].ErrState==DEM_ERRMEM_PASSIVE)
    {
      dem_MemEntryNextEmpty = index;
      do
      {
      	dem_ErrMemoEntry[index].CycCntSinceErrOccur = 0;
      	index ++;	
      }while(index < DEM_MEM_ENTRY_NUM);
      return;  
    }
    
    if (dem_ErrMemoEntry[index].ErrState>DEM_ERRMEM_DELETING) 
    {
      dem_MemEntryNextEmpty = index;
      dem_StatusErrFlg = TRUE;
      return;
    }

    err_Index = (dem_ErrMemoEntry[index].EventId - 1);
    if (err_Index >= EVENT_NUM_MAX)
    {
      dem_MemEntryNextEmpty = index;
      dem_StatusErrFlg = TRUE;
      return;
    }
            
    if ((dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_CONFIRMED)||
      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_ACTIVE)
      )
    {      
      dem_errStatus[err_Index].Bits.active = DEM_ERRMEM_ACTIVE;
      dem_errStatus[err_Index].Bits.mem = TRUE;
      
      /* Initialize Engine Fault History Status*/
      if (err_Index >= EVENT_NUM_ENG_FAULT_START)
      {
        uint8 engFaultNum;
        engFaultNum = err_Index - EVENT_NUM_ENG_FAULT_START; 
        dem_EngFaultOld[engFaultNum/16] |= Hex[engFaultNum&0xF];  
      }
    }
    else if (((dem_ErrMemoEntry[index].ErrState) == DEM_ERRMEM_HEALING)||
      ((dem_ErrMemoEntry[index].ErrState) == DEM_ERRMEM_POST_HEAL)||
      ((dem_ErrMemoEntry[index].ErrState) == DEM_ERRMEM_DELETING)
      )
    {
      dem_errStatus[err_Index].Bits.mem = TRUE;
    }
    
  }
  dem_MemEntryNextEmpty = DEM_MEM_ENTRY_NUM;    
}

_STATIC_ void DEM_CODE Dem_UpdateEngRunCounter(void)
{
	uint8 index;
	Dem_EventIdType eventId; 
	
	for (index=0;index<dem_MemEntryNextEmpty;index++)
	{
	  dem_ErrMemoEntry[index].EngRunTimeSinceMILOn++;
	  
	  eventId = (dem_ErrMemoEntry[index].EventId - 1);
	  if (eventId < EVENT_NUM_ENG_FAULT_START)
	  {	    
  	  if (
  	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_DELETING)||
  	      ((Dem_ErrJ1939FaultCode[eventId].CounterType == COUNTER_ENG_RUN)&&
  	        (dem_ErrMemoEntry[index].ErrState < DEM_ERRMEM_POST_HEAL))
  	      )
  	  {
    	  if(dem_ErrMemoEntry[index].StsUpdCnt != 0)
    	  {
    	    dem_ErrMemoEntry[index].StsUpdCnt--;  
    	  }
  	  }	  
  	  
  	  if (
  	    (dem_ErrMemoEntry[index].TrqLmtEngRunCnt != 0)&&
  	    (dem_ErrMemoEntry[index].TrqLmtEngRunCnt != DEM_NO_TRQ_LMT)
  	    )
  	  {
  	    dem_ErrMemoEntry[index].TrqLmtEngRunCnt--;
  	  }
	  }
	}  
}

_STATIC_ void DEM_CODE Dem_UpdateWarmUpCycleCounter(void)
{
	uint8 index;
	
	for (index=0;index<dem_MemEntryNextEmpty;index++)
	{
	  if((dem_ErrMemoEntry[index].WarmUpCycleCounter != 0)&&(dem_ErrMemoEntry[index].WarmUpCycleCounter!=0xFF))
	  {
	    dem_ErrMemoEntry[index].WarmUpCycleCounter--;  
	  }	  
	}  
}

_STATIC_ void DEM_CODE Dem_UpdateTimeCounter(void)
{
	uint8 index;
	Dem_EventIdType eventId; 
	
	for (index=0;index<dem_MemEntryNextEmpty;index++)
	{
	  eventId = (dem_ErrMemoEntry[index].EventId - 1);
	  
	  if (eventId < EVENT_NUM_ENG_FAULT_START)
	  {	    
  	  if (Dem_ErrJ1939FaultCode[eventId].CounterType == COUNTER_TIME)
  	  {
    	  if ((dem_ErrMemoEntry[index].StsUpdCnt != 0)&&
  	        (dem_ErrMemoEntry[index].ErrState < DEM_ERRMEM_POST_HEAL))
    	  {
    	    dem_ErrMemoEntry[index].StsUpdCnt--;  
    	  }
  	  }
	  }
	}  
}

/*******************************************************************************
* NAME:             Dem_UpdateState
* CALLED BY:        Dem
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      Update the Healing Counter and remove the defect if
*                   Counter become zero.
*******************************************************************************/
_STATIC_ void DEM_CODE Dem_UpdateState(void)
{
	uint8 index;
	
	for (index=0;index<dem_MemEntryNextEmpty;index++)
	{
    
		if (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_HEALING)
		{			
			if(dem_ErrMemoEntry[index].StsUpdCnt == 0)
			{
				dem_ErrMemoEntry[index].ErrState = DEM_ERRMEM_POST_HEAL;
				
				Dem_SetPostHealCounter(index);
			}
		}else if (dem_ErrMemoEntry[index].ErrState==DEM_ERRMEM_POST_HEAL)
		{
			if(dem_ErrMemoEntry[index].StsUpdCnt == 0)
			{
				dem_ErrMemoEntry[index].ErrState = DEM_ERRMEM_DELETING;
				
				dem_ErrMemoEntry[index].TrqLmtEngRunCnt = 0;
				
				Dem_SetDeleteCounter(index);
			}		
		}
		else if (dem_ErrMemoEntry[index].ErrState==DEM_ERRMEM_ACTIVE)
		{
			if(dem_ErrMemoEntry[index].StsUpdCnt==0)
			{
				dem_ErrMemoEntry[index].ErrState = DEM_ERRMEM_CONFIRMED;
				dem_ErrMemoEntry[index].ErrOccurCounter = 1;											
				dem_ErrMemoEntry[index].EngRunTimeSinceMILOn = 0;// 
				
				Dem_StoreFreezeFrame(index);       	
				
				Dem_SetTrqLmtCounter(index);
			}
		}else if (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_DELETING)
		{
			if ((dem_ErrMemoEntry[index].StsUpdCnt == 0)||(dem_ErrMemoEntry[index].WarmUpCycleCounter == 0))
			{
			  Dem_FaultMemClrUpdateEntry(index);
			}
		}
	}
}

/*******************************************************************************
* NAME:             Dem_FaultMemChksumCal
* CALLED BY:        Dem
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Dem_ChksumType: Chksum value
* DESCRIPTION:      Calculate Chksum
*******************************************************************************/
_STATIC_ Dem_ChksumType DEM_CODE Dem_FaultMemChksumCal(void)
{
  Dem_ChksumType chksum;
  uint16 index;
  uint16 errMemSize;
  uint16 * dataPtr;
 
  chksum = 0;
  errMemSize =  (sizeof(dem_ErrMemoEntry)/2);
  dataPtr = (uint16 *)(&dem_ErrMemoEntry[0]); 
  
  for (index = 0; index <errMemSize ; index++)
  {
    chksum += *dataPtr;
    dataPtr++;  
  }
  return (chksum);
}

/*******************************************************************************
* NAME:             Dem_FaultMemClrUpdateEntry
* CALLED BY:        Dem
* PRECONDITIONS:
* INPUT PARAMETERS: uint8 entryNum
* RETURN VALUES:    Void
* DESCRIPTION:      Delete One Error Memory Entry
*******************************************************************************/   		 	
_STATIC_ void DEM_CODE Dem_FaultMemClrUpdateEntry(uint8 entryNum)
{
	uint8 entryLastNum;
	uint8 eventId;

	
#if (DEM_DEV_ERROR_DETECT == STD_ON)	
	/* if there is no fault in memory */
	if (dem_MemEntryNextEmpty == 0)
  {
    Det_ReportError(DEM_MODULE_ID,DEM_INSTANCE_ID,DEM_API_SETERROR_ID,DEM_E_INVALID_INDEX);
    return;
	}
	
	if (entryNum > entryLastNum)
  {
    Det_ReportError(DEM_MODULE_ID,DEM_INSTANCE_ID,DEM_API_SETERROR_ID,DEM_E_INVALID_INDEX);
    return;
	}
#endif
		

	entryLastNum = dem_MemEntryNextEmpty - 1;
	
  eventId = (dem_ErrMemoEntry[entryNum].EventId - 1);
  	
	dem_errStatus[eventId].Bits.mem = 0;
	
	if (entryNum < entryLastNum)
	{  	  
	  /*MemCpy2(&(dem_ErrMemoEntry[entryNum]),&(dem_ErrMemoEntry[entryLastNum]) \
	           ,sizeof(dem_ErrMemoEntry[0]));*/
	  memcpy(&(dem_ErrMemoEntry[entryNum]),&(dem_ErrMemoEntry[entryLastNum]) \
	           ,sizeof(dem_ErrMemoEntry[0]));
  }
  
  Dem_FaultMemClrEntry(entryLastNum);
  
  dem_MemEntryNextEmpty--;                                                            	
} 


_STATIC_ void DEM_CODE Dem_FaultMemClrEntry(uint8 entryNum)
{
	uint8* dataPtr;
	uint8 index;
	
  dataPtr = (uint8*)(&(dem_ErrMemoEntry[entryNum]));
  
  for (index =0; index<sizeof(dem_ErrMemoEntry[0]); index++)
  {
    *dataPtr=0;
    dataPtr++;
  }	
}

/*******************************************************************************
* NAME:             Dem_ErrMemUpdate
* CALLED BY:        Dem
* PRECONDITIONS:
* INPUT PARAMETERS: Dem_EventIdType EventId
*                   uint8 EventStatus
* RETURN VALUES:    Void
* DESCRIPTION:      Update Error Memory
*******************************************************************************/ 
_STATIC_ void DEM_CODE Dem_ErrMemUpdate(Dem_EventIdType EventId,uint8 EventStatus)
{ 
  uint8 index;
#if (DEM_DEV_ERROR_DETECT == STD_ON)	
	if (EventId >= DEM_EVENT_TOT_NUM)
	{
	  Det_ReportError(DEM_MODULE_ID,DEM_INSTANCE_ID,DEM_API_ERRMEMUPDATE_ID,DEM_E_INVALID_INDEX);
	}
#endif	
	
  /* Search for the Error which is already in the Error memory */  
	for (index=0; index < dem_MemEntryNextEmpty; index++)
	{		
		if (dem_ErrMemoEntry[index].EventId == (EventId + 1))
		{
		  if ((dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_ACTIVE) \
		      && (EventStatus == DEM_ERRMEM_PASSIVE))
		  {
		    Dem_FaultMemClrUpdateEntry(index);      
		  }
		  else if ((dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_CONFIRMED) \
		      && (EventStatus == DEM_ERRMEM_PASSIVE))
		  {      
        dem_ErrMemoEntry[index].ErrState = DEM_ERRMEM_HEALING;
        
        /* Initialize the healing counter */
        if (EventId >= EVENT_NUM_ENG_FAULT_START)
        {
          dem_ErrMemoEntry[index].StsUpdCnt = DEM_ENG_FAULT_HEALING_CNT; 
        }else
        {
          dem_ErrMemoEntry[index].StsUpdCnt = Dem_ErrJ1939FaultCode[EventId].HealingCounter;
        }              
	    }
		  else if ((dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_HEALING) \
		      && (EventStatus == DEM_ERRMEM_ACTIVE))
		  {
		  	dem_ErrMemoEntry[index].CycCntSinceErrOccur = 0;
		  	dem_ErrMemoEntry[index].ErrState=DEM_ERRMEM_CONFIRMED;
		  	Dem_StoreFreezeFrame(index);  
		  }
		  else if ((dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_POST_HEAL) \
		      && (EventStatus == DEM_ERRMEM_ACTIVE))
		  {
		  	dem_ErrMemoEntry[index].CycCntSinceErrOccur = 0;
				dem_ErrMemoEntry[index].ErrState=DEM_ERRMEM_CONFIRMED;
		  	Dem_StoreFreezeFrame(index);  
		  }
		  else if ((dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_DELETING) \
		      && (EventStatus == DEM_ERRMEM_ACTIVE))
		  {
		  	dem_ErrMemoEntry[index].CycCntSinceErrOccur = 0;
				dem_ErrMemoEntry[index].ErrState = DEM_ERRMEM_CONFIRMED;
		    Dem_StoreFreezeFrame(index);  
		    Dem_SetTrqLmtCounter(index);
        if (dem_ErrMemoEntry[index].ErrOccurCounter < 126)
        {
          dem_ErrMemoEntry[index].ErrOccurCounter++;
        }		    
		  }
		  /* Found it, jump out of the cycle */
		  return;        
		}
  }

  /* Check if EventStatus is Active */
  if (EventStatus == DEM_ERRMEM_ACTIVE)
  {
    /* Add err in empty Entry */ 
    if (dem_MemEntryNextEmpty < DEM_MEM_ENTRY_NUM)
    {
      Dem_ErrStoreToEmptyEntry(EventId,dem_MemEntryNextEmpty);      	
    	dem_MemEntryNextEmpty++;
    	return;
    }
    else
    {          
      uint8 minClass = DEM_MAX_ERR_CLASS;
      uint8 minClass_EntryNum;
      uint8 minClass_ErrIndex;
      /* Look for the minium class entry in the error memory */
      for (index=0;index<DEM_MEM_ENTRY_NUM;index++)
      {           
        if (minClass > dem_ErrMemoEntry[index].ErrClass)
        {
        	minClass = dem_ErrMemoEntry[index].ErrClass;
        	minClass_EntryNum = index;
        	minClass_ErrIndex = (dem_ErrMemoEntry[index].EventId - 1);
        }        
      } /* for */
    	
    	if (EventId >= EVENT_NUM_ENG_FAULT_START)
    	{
    	  if (DEM_ENG_FAULT_ERR_CLASS > minClass)
    	  {    	    
        	Dem_FaultMemClrEntry(minClass_EntryNum);
        	Dem_ErrStoreToEmptyEntry(EventId,minClass_EntryNum);
        	dem_errStatus[minClass_ErrIndex].Bits.mem = FALSE;
      	}
    	}
    	else 
    	{                  
      	if (Dem_ErrJ1939FaultCode[EventId].ErrorClass > minClass)
      	{
					Dem_FaultMemClrEntry(minClass_EntryNum);
					Dem_ErrStoreToEmptyEntry(EventId,minClass_EntryNum);
					dem_errStatus[minClass_ErrIndex].Bits.mem = FALSE;      		
      	}
    	}
  	}
  }   	
}

/*******************************************************************************	
* NAME:             Dem_ErrStoreToEmptyEntry
* CALLED BY:        Dem
* PRECONDITIONS:
* INPUT PARAMETERS: Dem_EventIdType EventId
*                   uint8 entryNum
* RETURN VALUES:    Void
* DESCRIPTION:      Store one Error To Memory
*******************************************************************************/ 
_STATIC_ void DEM_CODE Dem_ErrStoreToEmptyEntry(Dem_EventIdType EventId,uint8 entryNum)
{
  
  dem_errStatus[EventId].Bits.mem = TRUE;
  if (EventId >= EVENT_NUM_ENG_FAULT_START)
  {
    dem_ErrMemoEntry[entryNum].StsUpdCnt = DEM_ENG_FAULT_CONFIRM_CNT; 
    dem_ErrMemoEntry[entryNum].ErrClass = DEM_ENG_FAULT_ERR_CLASS;  
  }else
  {
    dem_ErrMemoEntry[entryNum].StsUpdCnt = Dem_ErrJ1939FaultCode[EventId].ConfirmCounter; 
    dem_ErrMemoEntry[entryNum].ErrClass = Dem_ErrJ1939FaultCode[EventId].ErrorClass;   
  }
  dem_ErrMemoEntry[entryNum].EventId = (EventId + 1);

  dem_ErrMemoEntry[entryNum].ErrState = DEM_ERRMEM_ACTIVE;
  dem_ErrMemoEntry[entryNum].ErrOccurCounter = 0;

  // unnecessary to set torque limit counter
  //dem_ErrMemoEntry[entryNum].TrqLmtEngRunCnt = 0xFFFFFFFF; 
                                                          
}

_STATIC_ void DEM_CODE Dem_SetTrqLmtCounter(uint8 entryNum)
{
  uint8 EventId;
  
  EventId = (dem_ErrMemoEntry[entryNum].EventId - 1);

  if (EventId >= EVENT_NUM_ENG_FAULT_START)
  {
    dem_ErrMemoEntry[entryNum].TrqLmtEngRunCnt = DEM_NO_TRQ_LMT; 
  }else
  {    
    if (Dem_ErrJ1939FaultCode[EventId].TorqueLimitType == TRQ_LMT_IMM)
    {
      dem_ErrMemoEntry[entryNum].TrqLmtEngRunCnt = 0;  
    }else if (Dem_ErrJ1939FaultCode[EventId].TorqueLimitType == TRQ_LMT_50H)
    {
  #ifndef OBD_TEST
      dem_ErrMemoEntry[entryNum].TrqLmtEngRunCnt = HOURS(50);   
  #else
      dem_ErrMemoEntry[entryNum].TrqLmtEngRunCnt = MINUTES(1);
  #endif
    }else
    {
      dem_ErrMemoEntry[entryNum].TrqLmtEngRunCnt = DEM_NO_TRQ_LMT; 
    }
  }
}

_STATIC_ void DEM_CODE Dem_SetDeleteCounter(uint8 entryNum)
{
  uint8 EventId;
  
  EventId = (dem_ErrMemoEntry[entryNum].EventId - 1);

  if (EventId >= EVENT_NUM_ENG_FAULT_START)
  {
  	  #ifndef OBD_TEST
  	  dem_ErrMemoEntry[entryNum].StsUpdCnt = DEM_ENG_FAULT_DELETE_CNT;
  	  #else
  	  dem_ErrMemoEntry[entryNum].StsUpdCnt = 10;
  	  #endif
  	  dem_ErrMemoEntry[entryNum].WarmUpCycleCounter = 0xFF;
  }else
  {    
  	if (Dem_ErrJ1939FaultCode[EventId].ErrorType == ERASABLE)
  	{				  
  	  #ifndef OBD_TEST
  	  dem_ErrMemoEntry[entryNum].StsUpdCnt = HOURS(100);
  	  #else
  	  dem_ErrMemoEntry[entryNum].StsUpdCnt = SECONDS(30);
  	  #endif
  	 	  
  	  dem_ErrMemoEntry[entryNum].WarmUpCycleCounter = 40;
  	}else if(Dem_ErrJ1939FaultCode[EventId].ErrorType == NON_ERASABLE)
  	{
  	  #ifndef OBD_TEST
  	  dem_ErrMemoEntry[entryNum].StsUpdCnt = HOURS(9600);
  	  #else
  	  dem_ErrMemoEntry[entryNum].StsUpdCnt = MINUTES(1);
  	  #endif	  
  	  dem_ErrMemoEntry[entryNum].WarmUpCycleCounter = 0xFF;
  	}else if(Dem_ErrJ1939FaultCode[EventId].ErrorType == IMMEDIATE_ERASE)
  	{
  	  dem_ErrMemoEntry[entryNum].StsUpdCnt = 0;
  	}
  }
}

_STATIC_ void DEM_CODE Dem_SetPostHealCounter(uint8 entryNum)
{
  uint8 EventId;
  
  EventId = (dem_ErrMemoEntry[entryNum].EventId - 1);
  if (EventId >= EVENT_NUM_ENG_FAULT_START)
  {
    dem_ErrMemoEntry[entryNum].StsUpdCnt = 0;
  }else
  {
  	if (Dem_ErrJ1939FaultCode[EventId].ErrorType == ERASABLE)
  	{				  
  	  dem_ErrMemoEntry[entryNum].StsUpdCnt = 3;
  	}
  	else 
  	{
  	  dem_ErrMemoEntry[entryNum].StsUpdCnt = 0;
  	}  
  }
}


_STATIC_ void DEM_CODE Dem_TrqLmtOutput(void)
{
	uint8 index;
	
	for (index=0; index < dem_MemEntryNextEmpty; index++)
	{
	  if (
	      (dem_ErrMemoEntry[index].ErrState >= DEM_ERRMEM_CONFIRMED)&&
	      (dem_ErrMemoEntry[index].ErrState <= DEM_ERRMEM_POST_HEAL)
	      )
	  {	    
  	  if (dem_ErrMemoEntry[index].TrqLmtEngRunCnt == 0)
  	  {
  	    dem_TrqLmtOut = TRUE;
  	    return;  
  	  }
	  }
	}
	dem_TrqLmtOut = FALSE;
}

void DEM_CODE Dem_UpdateOperCycle(void)
{
	uint8 index;
	
	for (index=0; index < dem_MemEntryNextEmpty; index++)
	{
	  if (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_POST_HEAL)
	  {
      if (dem_ErrMemoEntry[index].StsUpdCnt != 0)
      {
        dem_ErrMemoEntry[index].StsUpdCnt--;
      }
	  }
	  
	  //2015-09-23, lzy, 
	  if(dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_CONFIRMED)
	  {
	     dem_ErrMemoEntry[index].CycCntSinceErrOccur++;
	  }
	}  
}

uint8 DEM_CODE Dem_GetEmRelatedDtcNumAMil(void)
{
	uint8 num;
  uint8 EventId;
  uint8 index;
  	
	num = 0;
	for (index=0; index < dem_MemEntryNextEmpty; index++)
	{
	  if ( 
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_CONFIRMED) || 
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_HEALING) ||
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_POST_HEAL))
	  {
	    EventId = (dem_ErrMemoEntry[index].EventId - 1);
	    
  	  if (EventId >= EVENT_NUM_ENG_FAULT_START)
  	  {
  	    num++;  
  	  }/**/
  	  else 
  	  {
  	    if ((Dem_ErrJ1939FaultCode[EventId].dtcKind & DEM_DTC_EMMISSION_TYPE)== DEM_DTC_EMMISSION_TYPE)
  	    	num++;
  	  }  	    
	  }
	}
	
	/* MIL on if it's emission related defect */
	if (num == 0)
	{
	  return (0);
	}else
	{
	  return (0x80|num);
	} 
}

uint8 DEM_CODE Dem_ReqEmRelatedDTC(uint8* buffer)
{
	uint8 num;
  uint8 EventId;
  uint8 index;
  uint8* tmpDataPtr;
   
  tmpDataPtr = buffer + 1;  
	num = 0;
	for (index=0; index < dem_MemEntryNextEmpty; index++)
	{
	  if ((dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_CONFIRMED) || 
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_HEALING) ||
	      (dem_ErrMemoEntry[index].ErrState == DEM_ERRMEM_POST_HEAL))
	  {
      EventId = (dem_ErrMemoEntry[index].EventId - 1);
      
      if (EventId >= EVENT_NUM_ENG_FAULT_START)
  	  {
  	    num++;
  	    *((uint16*)(tmpDataPtr)) = Dem_EngFaultCode[EventId - EVENT_NUM_ENG_FAULT_START].Dtc;
        tmpDataPtr +=2;  
  	  }else if ((Dem_ErrJ1939FaultCode[EventId].dtcKind & DEM_DTC_EMMISSION_TYPE)== DEM_DTC_EMMISSION_TYPE)
  	  {
        num++;
        *((uint16*)(tmpDataPtr)) = (uint16)(Dem_ErrJ1939FaultCode[EventId].DtcCode>>8);
        tmpDataPtr +=2;
  	  }
	  }
	}
	buffer[0] = num;

	return (num*2+1);
}

uint8 DEM_CODE Dem_ReprotDtcByStatusMask(uint8* buffer)
{
	uint8 num;
  uint8 EventId;
  uint8 index;
  uint8* tmpDataPtr;
   
  tmpDataPtr = buffer + 1;  
	num = 0;
	for (index=0; index < dem_MemEntryNextEmpty; index++)
	{
      EventId = (dem_ErrMemoEntry[index].EventId - 1);
      num++;
      
      if (EventId >= EVENT_NUM_ENG_FAULT_START)
      {
        *((uint32*)(tmpDataPtr)) = (uint32)(Dem_EngFaultCode[EventId - EVENT_NUM_ENG_FAULT_START].Dtc <<16);
      }else
      {
        *((uint32*)(tmpDataPtr)) = Dem_ErrJ1939FaultCode[EventId].DtcCode<<8;
      }
      *((uint8*)(tmpDataPtr+3)) = dem_ErrMemoEntry[index].ErrState;
      tmpDataPtr +=4;
	}
	
	if (num == 0)
	{
	  buffer[0] = 0;  
	}
	else
	{
	  buffer[0] = 0x01;  
	}	

	return (num*4+1);  
}

uint8 DEM_CODE Dem_ReprotDtcSnapshotbyDTCNum(uint8* buffer)
{
  uint32 dtc;
	uint8 num;
  uint8 EventId;
  uint8 index;  
  
  dtc = *(uint32*)(&buffer[0])>>8;
     
	num = 0xFF;
	for (index=0; index < dem_MemEntryNextEmpty; index++)
	{
    EventId = (dem_ErrMemoEntry[index].EventId - 1);
    if (EventId >= EVENT_NUM_ENG_FAULT_START)
    {
      if (Dem_EngFaultCode[EventId - EVENT_NUM_ENG_FAULT_START].Dtc == dtc)
      {        
        num = index;
        break;
      }
    }else if (Dem_ErrJ1939FaultCode[EventId].DtcCode == dtc)
    {
      num = index;
      break;
    }
	}
	
	if (num!=0xFF)
	{
	  buffer[3] = dem_ErrMemoEntry[num].ErrState;
	  buffer[4] = 0x01;
	  buffer[5] = 0x11;
	  buffer[6] = 0x22;
    buffer[7]  = dem_ErrMemoEntry[num].ErrOccurCounter;
    buffer[8]  = dem_ErrMemoEntry[num].EngTrqMode;
    buffer[9] = dem_ErrMemoEntry[num].BoostPressure;
    buffer[10] = (uint8)(dem_ErrMemoEntry[num].EngSpd & 0xFF);
    buffer[11] = (uint8)(dem_ErrMemoEntry[num].EngSpd>>8);
    buffer[12] = dem_ErrMemoEntry[num].EngLoad;
    buffer[13] = dem_ErrMemoEntry[num].EngTemp;
    buffer[14] = (uint8)(dem_ErrMemoEntry[num].Velocity & 0xFF);
    buffer[15] = (uint8)(dem_ErrMemoEntry[num].Velocity>>8);
    buffer[16] = (uint8)(dem_ErrMemoEntry[num].Odometer&0xFF);
    buffer[17] = (uint8)((dem_ErrMemoEntry[num].Odometer &0xFF00)>>8);
    buffer[18] = (uint8)((dem_ErrMemoEntry[num].Odometer&0xFF0000)>>16);
    buffer[19] = (uint8)((dem_ErrMemoEntry[num].Odometer>>24));
    buffer[20] = (uint8)(dem_ErrMemoEntry[num].BattVolt & 0xFF);
    buffer[21] = (uint8)(dem_ErrMemoEntry[num].BattVolt>>8);
    buffer[22] = dem_ErrMemoEntry[num].Year;
    buffer[23] = dem_ErrMemoEntry[num].Month;
    buffer[24] = dem_ErrMemoEntry[num].Day;
    buffer[25] = dem_ErrMemoEntry[num].Hour;
    buffer[26] = dem_ErrMemoEntry[num].Minute;
    buffer[27] = dem_ErrMemoEntry[num].Second;
    buffer[28] = dem_ErrMemoEntry[num].ErrState;
    buffer[29] = (uint8)(dem_ErrMemoEntry[num].EngRunTimeSinceMILOn&0xFF);
    buffer[30] = (uint8)((dem_ErrMemoEntry[num].EngRunTimeSinceMILOn &0xFF00)>>8);
    buffer[31] = (uint8)((dem_ErrMemoEntry[num].EngRunTimeSinceMILOn&0xFF0000)>>16);
    buffer[32] = (uint8)((dem_ErrMemoEntry[num].EngRunTimeSinceMILOn>>24)); 
    buffer[33] = (uint8)(dem_ErrMemoEntry[num].Nox & 0xFF);
    buffer[34] = (uint8)(dem_ErrMemoEntry[num].Nox>>8);
    buffer[35] = (uint8)(dem_ErrMemoEntry[num].UreaLvl & 0xFF);
    buffer[36] = (uint8)(dem_ErrMemoEntry[num].UreaLvl>>8);
      	  
	  return (37);  
	    
	}else
	{
	  buffer[3]= 0x00;
	  return (4);    
	}  
}



void DEM_CODE Dem_TestClrFault(uint8 type, boolean complete)
{
  uint8 index;
  uint8 EventId;
  
  for(index = 0; index < dem_MemEntryNextEmpty; index++)
  {
    EventId = (dem_ErrMemoEntry[index].EventId - 1);
    if (EventId >= EVENT_NUM_ENG_FAULT_START)
    {
      if ((type & DEM_DTC_EMMISSION_TYPE)!=0)
      {
        Dem_FaultMemClrUpdateEntry(index);  
        dem_errStatus[EventId].byte = 0;          
      }
    }else if ((Dem_ErrJ1939FaultCode[EventId].dtcKind & type)!=0)
	  {
      if ((complete == TRUE)||(Dem_ErrJ1939FaultCode[EventId].ErrorType != NON_ERASABLE))
      {
        Dem_FaultMemClrUpdateEntry(index);  
        dem_errStatus[EventId].byte = 0;  
      }
	  }
  }     
}

_STATIC_ void DEM_CODE Dem_StoreFreezeFrame(uint8 index)
{
	dem_ErrMemoEntry[index].EngTrqMode = EEC1_EngTrqMode;//PIDE1
	dem_ErrMemoEntry[index].BoostPressure = IC1_BoostPressure;//PID0B
	dem_ErrMemoEntry[index].EngSpd = EEC1_EngSpd;//PID0C
	dem_ErrMemoEntry[index].EngLoad = EEC2_EngLoad;//PID04
	dem_ErrMemoEntry[index].EngTemp = ET1_EngClntTemp;//PID05 
	dem_ErrMemoEntry[index].Velocity = TCO1_VehSpd;//PID0D
	dem_ErrMemoEntry[index].Odometer = VD_TotalDistance;//PIDE2
	dem_ErrMemoEntry[index].BattVolt =	(uint16)((uint32)(ecu_BattVoltActRaw) * 100 / 1023);//PIDE3
	dem_ErrMemoEntry[index].Year = TD_Year;//PIDE4
	dem_ErrMemoEntry[index].Month = TD_Month;//PIDE4
	dem_ErrMemoEntry[index].Day = TD_Day;//PIDE4
	dem_ErrMemoEntry[index].Hour = TD_Hour;//PIDE4
  dem_ErrMemoEntry[index].Minute = TD_Minute;//PIDE4
  dem_ErrMemoEntry[index].Second = TD_Second;//PIDE4   
  dem_ErrMemoEntry[index].Nox = ATS_Nox;                //add by mt 20150828
  //dem_ErrMemoEntry[index].UreaLvl = SID_m_pc_UreaLvl;   //add by mt 20150828
}


				
#pragma CODE_SEG DEFAULT

//!<	====================================================================
//!<	================	add by xyl 2015-08-04	=================
Std_ReturnType Dem_GetDTCOfOBDFreezeFrame(uint8 FrameNumber, uint32* DTC )
{
  uint8 EventId;
  uint8 index;
   
	index = dem_MemEntryNextEmpty;
	
	if(0==index)
	{
		return E_NOT_OK;
	}
	else
	{
		if(dem_ErrMemoEntry[index-1].ErrState == DEM_ERRMEM_CONFIRMED)
    {
      EventId = (dem_ErrMemoEntry[index-1].EventId - 1);
      *DTC = Dem_ErrJ1939FaultCode[EventId].DtcCode<<8;
      return E_OK;
    }
    else
    {
    	return E_NOT_OK;	
    }
	}
}



/*Std_ReturnType Dem_GetOBDFreezeFrameData(uint8 PID, uint8* buffer, uint8* BufSize)
{
  uint8 EventId;
  uint8 index;
   
	index = dem_MemEntryNextEmpty;
	
	if(0==index)//before this, PID02 must be done to check if FreezeFrame exist
	{
		buffer[0]= 0x00;
	  * BufSize = (1);
	  return E_NOT_OK;   
	}
	else
	{
		switch(PID)	
		{
			case 0x04:
			{
				buffer[0] = dem_ErrMemoEntry[index-1].EngLoad;
				* BufSize = 1;	
			}
			break;
			
			case 0x05:
			{
				buffer[0] = dem_ErrMemoEntry[index-1].EngTemp;
				* BufSize = 1;	
			}
			break;
			
			case 0x0B:
			{
				buffer[0] = dem_ErrMemoEntry[index-1].BoostPressure;
				* BufSize = 1;	
			}
			break;

			case 0x0C:
			{
				buffer[0] = (uint8)(dem_ErrMemoEntry[index-1].EngSpd & 0xFF);
    		buffer[1] = (uint8)(dem_ErrMemoEntry[index-1].EngSpd>>8);
				* BufSize = 2;	
			}
			break;
			
			case 0x0D:
			{
				buffer[0] = (uint8)(dem_ErrMemoEntry[index-1].Velocity & 0xFF);
    		buffer[1] = (uint8)(dem_ErrMemoEntry[index-1].Velocity>>8);
				* BufSize = 2;	
			}
			break;

			case 0xE1:
			{
				buffer[0] = dem_ErrMemoEntry[index-1].EngTrqMode;
				* BufSize = 1;	
			}
			break;

			case 0xE2:
			{
		    buffer[0] = (uint8)(dem_ErrMemoEntry[index-1].Odometer>>0);
		    buffer[1] = (uint8)(dem_ErrMemoEntry[index-1].Odometer>>8);
		    buffer[2] = (uint8)(dem_ErrMemoEntry[index-1].Odometer>>16);
		    buffer[3] = (uint8)(dem_ErrMemoEntry[index-1].Odometer>>24);
				* BufSize = 4;	
			}
			break;

			case 0xE3:
			{
		    buffer[0] = (uint8)(dem_ErrMemoEntry[index-1].BattVolt>>0);
		    buffer[1] = (uint8)(dem_ErrMemoEntry[index-1].BattVolt>>8);
				* BufSize = 2;	
			}
			break;

			case 0xE4:
			{
				buffer[0] = dem_ErrMemoEntry[index-1].Year;
				buffer[1] = dem_ErrMemoEntry[index-1].Month;
				buffer[2] = dem_ErrMemoEntry[index-1].Day;
				buffer[3] = dem_ErrMemoEntry[index-1].Hour;
				buffer[4] = dem_ErrMemoEntry[index-1].Minute;
				buffer[5] = dem_ErrMemoEntry[index-1].Second;
				* BufSize = 6;	
			}
			break;
		}
		
		return E_OK;
	}
}*/
