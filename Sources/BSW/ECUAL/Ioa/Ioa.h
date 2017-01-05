/*******************************************************************************
*
*  FILE
*     Ioa.h
*
*  DESCRIPTION
*     The Header file for IO abstraction
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

#ifndef _IOA_SCR_H_
#define _IOA_SCR_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"
#include "Ioa_Cfg.h"
#include "Ioa_Types.h"

#include "Mcu.h"
//#include "Wdg.h"
//#include "Dio.h"
#include "Adc.h"
#include "Gpt.h"
//#include "EcuM.h"
#include "Siu_Cfg.h"

/*******************************************************************************
* Defines                                                                
*******************************************************************************/
#define CTL_OFF                        0U
#define CTL_ON                         1U
#define CTL_PWM                        2U

#define SHUTDWN_ACTIVE                 0U
#define SHUTDWN_INACTIVE               1U

#define IOA_CTL_OFF    0U
#define IOA_CTL_ON     1U
#define IOA_CTL_NON    2U

/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/
extern uint8_t SID_m_swt_PhaDrvFaultRaw;
extern uint8_t SID_m_swt_ExcDrvFaultRaw;

extern uint8_t SID_m_swt_IGNRaw;
extern uint8_t SID_m_swt_ENRaw;
extern uint8_t SID_m_swt_RsolvDOSRaw;
extern uint8_t SID_m_swt_RsolvLOTRaw;

/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/
extern void Ioa_Init(void);
extern void Ioa_Input(void);
extern void Ioa_Output(void);
extern void Ioa_PhaseDrvFaultReset(void);
extern void Ioa_PhaseDrvDisable(void);
extern void Ioa_PhaseDrvEnable(void);




























#endif /* #ifndef _IOA_H_ */