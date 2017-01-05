/*******************************************************************************
*
*  FILE
*     OSTimer.c
*
*  DESCRIPTION
*     OsTimer management and update
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
* include files                                                 
*******************************************************************************/
#include "OSTimer.h"
#include "Gpt.h"
#include "Det.h"
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
*  local variables definition                                               
*******************************************************************************/
_STATIC_  VAR(osTimer_MSecondType, TYPEDEF) osTimer_MSec; 

_STATIC_  VAR(osTimer_SecondType, TYPEDEF) osTimer_Sec;
  
_STATIC_  VAR(osTime_MSecTickType, TYPEDEF) osTime_MSecTick;    
/*******************************************************************************
* Local Functions prototypes                         
*******************************************************************************/

/*******************************************************************************
*  Global Functions Body                                   
*******************************************************************************/

/****************************************************************************
* NAME:             OsTimer_Init
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: None
* RETURN VALUES:    None
* DESCRIPTION:      OsTimer initialization       
****************************************************************************/


FUNC(void, TYPEDEF) OsTimer_Init(void)
{  
  osTimer_MSec     = 0;
  osTimer_Sec      = 0;
  osTime_MSecTick  = 0;
}

/****************************************************************************
* NAME:             OsTimer_Increment
* CALLED BY:        ISR
* PRECONDITIONS:    
* INPUT PARAMETERS: msec -  millisecond to increase
* RETURN VALUES:    None
* DESCRIPTION:      Increase the Timer      
****************************************************************************/
FUNC(void, TYPEDEF) OsTimer_Increment(osTimer_MSecondType msec)
{  
  osTimer_MSec += msec;
  if (osTimer_MSec >= 1000U)
  {
    osTimer_Sec += 1;
    osTimer_MSec -= 1000U;
  }
  /* Tick used for alarm function*/
  osTime_MSecTick += msec;

  /* keep the Stop watch high word updated */
  /* OsTimer_GetStopWatch(); */
}

/****************************************************************************
* NAME:             OsTimer_GetSeconds
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: None
* RETURN VALUES:    the current seconds that MCU runs
* DESCRIPTION:      Get current Seconds        
****************************************************************************/
FUNC(osTimer_SecondType, TYPEDEF) OsTimer_GetSeconds(void)
{
  osTimer_SecondType value;
  
  SuspendAllInterrupts();
  value = osTimer_Sec;
  ResumeAllInterrupts();
  return value;
}

/****************************************************************************
* NAME:             OsTimer_GetMSeconds
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: None
* RETURN VALUES:    the current milli seconds
* DESCRIPTION:      Get current milli Seconds        
****************************************************************************/
FUNC(osTimer_MSecondType, TYPEDEF) OsTimer_GetMSeconds(void)
{
  osTimer_MSecondType value;
  
  SuspendAllInterrupts();
  value = osTimer_MSec;
  ResumeAllInterrupts();
  return value;
}

/****************************************************************************
* NAME:             OsTimer_GetMSecondsTick
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: None
* RETURN VALUES:    the current time tick
* DESCRIPTION:      Get current time tick (Unit: ms )        
****************************************************************************/
FUNC(osTime_MSecTickType, TYPEDEF) OsTimer_GetMSecondsTick(void)
{
/*
  osTime_MSecTickType value;

  
  SuspendAllInterrupts();
  value = osTime_MSecTick;
  ResumeAllInterrupts();
  return value;
*/
	return Gpt_GetCurrentCnt();   
  
}

/****************************************************************************
* NAME:             OsTimer_CheckTimeOut
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: timeStart - start tick
*                   timeNow   - current tick
*                   timeOut   - expired tick
* RETURN VALUES:    whether timer is expired 
* DESCRIPTION:      check if specified time is expired        
****************************************************************************/
FUNC(boolean, TYPEDEF) OsTimer_CheckTimeOut(osTime_MSecTickType timeStart,osTime_MSecTickType timeOut)
{  
  osTime_MSecTickType timerActivateVal;  
  osTime_MSecTickType timeNow;
  
  timeNow = Gpt_GetCurrentCnt();
  timerActivateVal =  timeOut + timeStart;

  if (timerActivateVal > timeStart)
  {
    if ((timeNow >= timerActivateVal) || (timeNow < timeStart))
    {
      return TRUE;
    }
  } 
  else if ((timeNow >= timerActivateVal) && (timeNow < timeStart))
  {
    return TRUE;
  }
  return FALSE;
}

/****************************************************************************
* NAME:             OsTimer_GetStopWatch
* CALLED BY:        OsTrace and Ostimer function
* PRECONDITIONS:    
* INPUT PARAMETERS: None
* RETURN VALUES:    current time tick (uint: us)
* DESCRIPTION:      get current time tick from MCU's timer register
*                   (Timer hardware must be configured properly )
****************************************************************************/
FUNC(OsTimer_StopWatchTickType, TYPEDEF) OsTimer_GetStopWatch(void)
{
  OsTimer_StopWatchTickType curValue = (OsTimer_StopWatchTickType)(Gpt_GetCurrentCnt());
  return curValue; 
}

