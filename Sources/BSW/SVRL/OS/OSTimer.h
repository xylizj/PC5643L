/*******************************************************************************
*
*  FILE
*     OSTimer.h
*
*  DESCRIPTION
*     OSTimer module header file
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

#ifndef _OSTIMER_H_
#define _OSTIMER_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "OSTimer_Cfg.h"
#include "OSTimer_Types.h"
#include "OSTimer_Cbk.h"
#include "Gpt.h"
/*******************************************************************************
* definition                                                
*******************************************************************************/
#define OSMS   1000000UL

#define MS2NS(a)  (a*OSMS) 

#define OsTimer_GetMinutes()  (OsTimer_GetSeconds()/60)
#define OsTimer_GetHours()    (OsTimer_GetMinutes()/60)
#define OsTimer_GetDays()     ((uint16)(OsTimer_GetHours()/24))

/*******************************************************************************
* Macro                                                 
*******************************************************************************/

/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/

/*******************************************************************************
* Global functions declaration                                                
*******************************************************************************/


extern FUNC(osTimer_MSecondType, TYPEDEF) OsTimer_GetMSeconds(void);
extern FUNC(osTimer_SecondType, TYPEDEF) OsTimer_GetSeconds(void);
extern FUNC(boolean, TYPEDEF) OsTimer_CheckTimeOut(osTime_MSecTickType timeStart,osTime_MSecTickType timeOut);
extern FUNC(void, TYPEDEF) OsTimer_Increment(osTimer_MSecondType msec);
extern FUNC(osTime_MSecTickType, TYPEDEF) OsTimer_GetMSecondsTick(void);
extern FUNC(void, TYPEDEF) OsTimer_Init(void);
extern FUNC(OsTimer_StopWatchTickType, TYPEDEF) OsTimer_GetStopWatch(void);


#endif  /* #ifndef _OSTIMER_H_ */
