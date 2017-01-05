/*******************************************************************************
*
*  FILE
*     OSTrace.h
*
*  DESCRIPTION
*     the header file of OsTrace
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

#ifndef _OSTRACE_H_
#define _OSTRACE_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "OSTimer.h"
#include "OSTrace_Types.h"                        
/*******************************************************************************
* definition                                                 
*******************************************************************************/
#define TASKIdle              0   /* Do not modify it */
#define TASK1MS               1   
//#define TASK2MS             
//#define TASK5MS                
#define TASK10MS              2   /* Do not modify it */
#define TASK100MS             3  
#define OSTRACE_ETGROUP_NUM   4

#define OSTRACE_ETM_START     0U
#define OSTRACE_ETM_STOP      1U
/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/
extern VAR(OsTrace_ExcTimeGroupType, TYPEDEF) osTrace_ExcTime[OSTRACE_ETGROUP_NUM]; 

/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/
extern FUNC(void,TYPEDEF) OSTrace_Init(void);
extern FUNC(void,TYPEDEF) OSTrace_ExcTimeMeasure(uint8 groupNum,uint8 type);

#endif /* #ifndef _OSTRACE_H_ */