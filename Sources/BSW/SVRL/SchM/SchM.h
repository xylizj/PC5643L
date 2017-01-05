/*******************************************************************************
*
*  FILE
*     SchM.h
*
*  DESCRIPTION
*     The Header file for BSW Scheduler
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
*    0.01
*
*******************************************************************************/

#ifndef _SCHM_H_
#define _SCHM_H_



/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"
#include "Ioa.h"

/*******************************************************************************
* Defines                                                                
*******************************************************************************/

#define USE_XCP
#define USE_INTC


#define MOTOR0

#ifdef MOTOR0
#undef MOTOR1
#else
#define MOTOR1
#endif
/*******************************************************************************
* Macros                                                                
*******************************************************************************/


/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/

/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/
extern void SchM_BSW_Init(void);
extern void SchM_ASW_Init();
extern void SchM_MainFunction(void);
extern void SchM_Period1Ms(void);
extern void SchM_Period2Ms(void);
extern void SchM_Period10Ms(void);
extern void SchM_Period100Ms(void);
























#endif /* #ifndef _SCHM_H_ */