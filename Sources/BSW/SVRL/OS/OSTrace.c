/*******************************************************************************
*
*  FILE
*     OSTrace.c
*
*  DESCRIPTION
*     Task execution time measurement
*      
*       
*  COPYRIGHT
*     (c)Copyright 2008, Wuhan Eureka Control System Co., Ltd. 
*     All rights reserved.
*
*  AUTHOR
*    Gu Bin
*
*  VERSION
*    1.00
*
*******************************************************************************/
/*******************************************************************************
*                      Revision  History 
*                              
*   V1.00   18.11.2008  Gu Bin:  Initial version
*******************************************************************************/

/*******************************************************************************
*  include files                                                 
*******************************************************************************/
#include "OSTrace.h"
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


/*******************************************************************************
* Local Variables definition                         
*******************************************************************************/


_STATIC_ VAR(uint16, TYPEDEF) tStopWatchDuration;
_STATIC_ VAR(uint8, TYPEDEF) delay_count; 
VAR(OsTrace_ExcTimeGroupType, TYPEDEF) osTrace_ExcTime[OSTRACE_ETGROUP_NUM]; 
_STATIC_ VAR(OsTrace_IdleTimeType, TYPEDEF) osTrace_IdleTime; 
_STATIC_ VAR(boolean, TYPEDEF) osTrace_FirstFlag[OSTRACE_ETGROUP_NUM];

/*******************************************************************************
* Local Functions prototypes                         
*******************************************************************************/

/*******************************************************************************
* Global function body                                                
*******************************************************************************/

/****************************************************************************
* NAME:             OSTrace_Init
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: None
* RETURN VALUES:    None
* DESCRIPTION:      Initialization of OsTrace module
*  
* This function must be called after All Timer especailly TIM are intialized ,
* and it's better to directly put after the OsTimer_Init      
****************************************************************************/
FUNC(void,TYPEDEF) OSTrace_Init(void)
{
  uint8 i; 
  OsTimer_StopWatchTickType t0;
  OsTimer_StopWatchTickType t1;

  for (i=0;i<=OSTRACE_ETGROUP_NUM-1;i++)
  {
    osTrace_ExcTime[i].MaxExcTime = 0;
    osTrace_ExcTime[i].MaxPerTime = 0;
    osTrace_FirstFlag[i] = 0;    
  }

  osTrace_IdleTime.MaxIdleTime = 0;
  osTrace_IdleTime.IdleTime = 0;
  osTrace_IdleTime.MinIdleTime = 0xffff; 

  delay_count = 0;

  t0 = OsTimer_GetStopWatch();
  t0 = OsTimer_GetStopWatch();
  t1 = OsTimer_GetStopWatch();
  tStopWatchDuration = (uint16)( t1 - t0 ); 
}

/****************************************************************************
* NAME:             OSTrace_ExcTimeMeasure
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: groupNum - task id number
*                   type - start or stop the measurement tick
* RETURN VALUES:    None
* DESCRIPTION:      measure the execution time of task    
****************************************************************************/
FUNC(void,TYPEDEF) OSTrace_ExcTimeMeasure(uint8 groupNum,uint8 type)
{
 
  if (type == OSTRACE_ETM_START)
  {    
    if (groupNum == TASK10MS)
    {

      if (delay_count > 8)
      {        
        /* osTrace_IdleTime.IdleTime -= osTrace_ExcTime[TASKIdle].CurExcTime * 4;*/
        if (osTrace_IdleTime.IdleTime > osTrace_IdleTime.MaxIdleTime)
        {
          osTrace_IdleTime.MaxIdleTime = osTrace_IdleTime.IdleTime;
        }
        else if (osTrace_IdleTime.IdleTime < osTrace_IdleTime.MinIdleTime)
        {
         osTrace_IdleTime.MinIdleTime = osTrace_IdleTime.IdleTime;
        }

      }
      else
      {
        delay_count++;
      }

      /* Reset Idle Time */
      osTrace_IdleTime.IdleTime = 0;
    }
    if (osTrace_FirstFlag[groupNum] ==  TRUE)
    {
      osTrace_ExcTime[groupNum].CurPerTime =  ((OsTimer_GetStopWatch() - 
      osTrace_ExcTime[groupNum].startTick)/MCU_BUS_FREQ); 

      if (osTrace_ExcTime[groupNum].CurPerTime > osTrace_ExcTime[groupNum].MaxPerTime)
      {
        osTrace_ExcTime[groupNum].MaxPerTime = osTrace_ExcTime[groupNum].CurPerTime;  
      }            

    }
    else
    {
      osTrace_FirstFlag[groupNum] = TRUE;      
    }

    osTrace_ExcTime[groupNum].startTick = OsTimer_GetStopWatch();

  }
  else if (type == OSTRACE_ETM_STOP)
  {
    osTrace_ExcTime[groupNum].stopTick = OsTimer_GetStopWatch();
    osTrace_ExcTime[groupNum].CurExcTime = ((osTrace_ExcTime[groupNum].stopTick -
    osTrace_ExcTime[groupNum].startTick)/MCU_BUS_FREQ);
    osTrace_ExcTime[groupNum].CurExcTime -= (OsTimer_StopWatchTickType)(tStopWatchDuration);                                      

    if (osTrace_ExcTime[groupNum].CurExcTime > osTrace_ExcTime[groupNum].MaxExcTime)
    {
      osTrace_ExcTime[groupNum].MaxExcTime = osTrace_ExcTime[groupNum].CurExcTime;  
    } 

    if (groupNum == TASKIdle)
    {
      osTrace_IdleTime.IdleTime += osTrace_ExcTime[TASKIdle].CurExcTime;
    }

  } 
  else
  {
  /* do nothing */
  } 
}


