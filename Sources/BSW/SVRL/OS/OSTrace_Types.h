/*******************************************************************************
*
*  FILE
*     OSTrace_Types.h
*
*  DESCRIPTION
*     The Header file for OSTrace Types  
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
*    1.00
*
*******************************************************************************/

#ifndef _OSTRACE_TYPES_H_
#define _OSTRACE_TYPES_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"
#include "OsTimer.h"
/*******************************************************************************
* Defines                                                                
*******************************************************************************/
typedef uint32 OSTrace_ExcTimeType;
typedef uint32 OSTrace_PerTimeType;

typedef struct{
  OsTimer_StopWatchTickType startTick;
  OsTimer_StopWatchTickType stopTick;
  OSTrace_ExcTimeType       CurExcTime;
  OSTrace_ExcTimeType       MaxExcTime;
  OSTrace_PerTimeType       CurPerTime;
  OSTrace_PerTimeType       MaxPerTime;  
}OsTrace_ExcTimeGroupType;

typedef struct{
  OSTrace_ExcTimeType       IdleTime;
  OSTrace_ExcTimeType       MaxIdleTime;
  OSTrace_ExcTimeType       MinIdleTime;  
}OsTrace_IdleTimeType;

/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/

/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/

#endif /* #ifndef _OSTRACE_TYPES_H_ */