/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: SID_MCData.h
 *  File Creation Date: 09-May-2016
 *  Code generated on : Mon May 09 17:13:32 2016
 *  Abstraction:
 *  Notes:
 *
 *  Model Information:
 *  Model Name: SID
 *  Model Version: 1.566
 *  Model Description:
 *  Creation date:	Mon Apr 21 14:27:52 2014
 *  Last Saved Modification:   Mon May 09 11:52:58 2016
 *
 *  (c)Copyright 2014-2016£¬Wuhan Eureka Control Co., Ltd.
 *******************************************************************************/
/******************************************************************************
 *  Include files
 ******************************************************************************/
#ifndef RTW_HEADER_SID_MCData_h_
#define RTW_HEADER_SID_MCData_h_

/*****************************************************************************
 *  Defines
 *****************************************************************************/
#include "rtwtypes.h"
#include "Rte_Type.h"

/* Exported data define */
#define DEMTEMPEXC_HIGH_ID             ((UInt16) 0U)
#define DEMTEMPEXC_LOW_ID              ((UInt16) 0U)
#define DEMTEMPEXC_SRCH_ID             ((UInt16) 0U)
#define DEMTEMPEXC_SRCL_ID             ((UInt16) 0U)
#define DEMTEMPPU_HIGH_ID              ((UInt16) 0U)
#define DEMTEMPPU_LOW_ID               ((UInt16) 0U)
#define DEMTEMPPU_SRCH_ID              ((UInt16) 0U)
#define DEMTEMPPU_SRCL_ID              ((UInt16) 0U)
#define DEMTEMPPV_HIGH_ID              ((UInt16) 0U)
#define DEMTEMPPV_LOW_ID               ((UInt16) 0U)
#define DEMTEMPPV_SRCH_ID              ((UInt16) 0U)
#define DEMTEMPPV_SRCL_ID              ((UInt16) 0U)
#define DEMTEMPPW_HIGH_ID              ((UInt16) 0U)
#define DEMTEMPPW_LOW_ID               ((UInt16) 0U)
#define DEMTEMPPW_SRCH_ID              ((UInt16) 0U)
#define DEMTEMPPW_SRCL_ID              ((UInt16) 0U)
#define DEMTEMPSHELL_HIGH_ID           ((UInt16) 0U)
#define DEMTEMPSHELL_LOW_ID            ((UInt16) 0U)
#define DEMTEMPSHELL_SRCH_ID           ((UInt16) 0U)
#define DEMTEMPSHELL_SRCL_ID           ((UInt16) 0U)
#define DEMTEMPSTATOR_HIGH_ID          ((UInt16) 0U)
#define DEMTEMPSTATOR_LOW_ID           ((UInt16) 0U)
#define DEMTEMPSTATOR_SRCH_ID          ((UInt16) 0U)
#define DEMTEMPSTATOR_SRCL_ID          ((UInt16) 0U)

/* Exported data declaration */
extern t_Current4 CAN_m_i_DISExcMaxCurReq;
extern t_RotSpd1 CAN_m_n_ESAEndSpdReq;
extern t_RotSpdPerSec1 CAN_m_nps_ESASpdGradReq;
extern UInt8 CAN_m_st_ModReq;
extern Boolean CAN_m_st_ModReqOverTime;
extern t_Timer1 CAN_m_ti_ESADurMaxReq;
extern t_Torque2 CAN_m_trq_ESATrqLimReq;
extern t_TorquePerSec1 CAN_m_trq_NegTrqGradReq;
extern t_Torque2 CAN_m_trq_NegTrqLimReq;
extern t_TorquePerSec1 CAN_m_trq_PosTrqGradReq;
extern t_Torque2 CAN_m_trq_PosTrqLimReq;
extern t_Torque2 CAN_m_trq_TrqReq;
extern t_Current4 SID_m_i_CurExc;
extern t_RotSpd1 SID_m_n_MotSpd;
extern t_RotSpd1 SID_m_n_MotSpdRaw;
extern Boolean SID_m_st_TempExcHigh;
extern Boolean SID_m_st_TempExcLow;
extern UInt8 SID_m_st_TempExcSRC;
extern Boolean SID_m_st_TempExcTmpSRC;
extern Boolean SID_m_st_TempPUHigh;
extern Boolean SID_m_st_TempPULow;
extern UInt8 SID_m_st_TempPUSRC;
extern Boolean SID_m_st_TempPUTmpSRC;
extern Boolean SID_m_st_TempPVHigh;
extern Boolean SID_m_st_TempPVLow;
extern UInt8 SID_m_st_TempPVSRC;
extern Boolean SID_m_st_TempPVTmpSRC;
extern Boolean SID_m_st_TempPWHigh;
extern Boolean SID_m_st_TempPWLow;
extern UInt8 SID_m_st_TempPWSRC;
extern Boolean SID_m_st_TempPWTmpSRC;
extern Boolean SID_m_st_TempShellHigh;
extern Boolean SID_m_st_TempShellLow;
extern UInt8 SID_m_st_TempShellSRC;
extern Boolean SID_m_st_TempShellTmpSRC;
extern Boolean SID_m_st_TempStatorHigh;
extern Boolean SID_m_st_TempStatorLow;
extern UInt8 SID_m_st_TempStatorSRC;
extern Boolean SID_m_st_TempStatorTmpSRC;
extern Boolean SID_m_swt_ENDeb;
extern Boolean SID_m_swt_ExcDrvFaultDeb;
extern Boolean SID_m_swt_IGNDeb;
extern Boolean SID_m_swt_PhaDrvFaultDeb;
extern Boolean SID_m_swt_RslvDOSDeb;
extern Boolean SID_m_swt_RslvLOTDeb;
extern t_Pressure4 SID_m_t_TempExc;
extern t_Temp3 SID_m_t_TempExcLinear;
extern t_Pressure4 SID_m_t_TempPU;
extern t_Temp3 SID_m_t_TempPULinear;
extern t_Pressure4 SID_m_t_TempPV;
extern t_Temp3 SID_m_t_TempPVLinear;
extern t_Pressure4 SID_m_t_TempPW;
extern t_Temp3 SID_m_t_TempPWLinear;
extern t_Pressure4 SID_m_t_TempShell;
extern t_Temp3 SID_m_t_TempShellLinear;
extern t_Pressure4 SID_m_t_TempStator;
extern t_Temp3 SID_m_t_TempStatorLinear;
extern t_Voltage4 SID_m_u_TempExc;
extern t_Voltage4 SID_m_u_TempPU;
extern t_Voltage4 SID_m_u_TempPV;
extern t_Voltage4 SID_m_u_TempPW;
extern t_Voltage4 SID_m_u_TempShell;
extern t_Voltage4 SID_m_u_TempStator;
extern t_Voltage4 SID_m_u_V10;
extern t_Voltage4 SID_m_u_V12;
extern t_Voltage5 SID_m_u_V48;
extern t_Voltage4 SID_m_u_V5;
extern const t_Voltage4 SID_CURX_u_TempExc[23];
extern const t_Voltage4 SID_CURX_u_TempP[23];
extern const t_Voltage4 SID_CURX_u_TempShell[20];
extern const t_Voltage4 SID_CURX_u_TempStator[20];
extern const t_Temp3 SID_CUR_t_TempExc[23];
extern const t_Temp3 SID_CUR_t_TempP[23];
extern const t_Temp3 SID_CUR_t_TempShell[20];
extern const t_Temp3 SID_CUR_t_TempStator[20];
extern const t_TempRatio1 SID_C_t_TempExcFallRate;
extern const t_Temp3 SID_C_t_TempExcHigh;
extern const t_Temp3 SID_C_t_TempExcHighOffset;
extern const t_Temp3 SID_C_t_TempExcLowOffset;
extern const t_Temp3 SID_C_t_TempExcPLow;
extern const t_TempRatio1 SID_C_t_TempExcRiseRate;
extern const t_Temp3 SID_C_t_TempExcRplcVal;
extern const t_TempRatio1 SID_C_t_TempPFallRate;
extern const t_Temp3 SID_C_t_TempPHigh;
extern const t_Temp3 SID_C_t_TempPHighOffset;
extern const t_Temp3 SID_C_t_TempPLow;
extern const t_Temp3 SID_C_t_TempPLowOffset;
extern const t_TempRatio1 SID_C_t_TempPRiseRate;
extern const t_Temp3 SID_C_t_TempPRplcVal;
extern const t_TempRatio1 SID_C_t_TempShellFallRate;
extern const t_Temp3 SID_C_t_TempShellHigh;
extern const t_Temp3 SID_C_t_TempShellHighOffset;
extern const t_Temp3 SID_C_t_TempShellLow;
extern const t_Temp3 SID_C_t_TempShellLowOffset;
extern const t_TempRatio1 SID_C_t_TempShellRiseRate;
extern const t_Temp3 SID_C_t_TempShellRplcVal;
extern const t_TempRatio1 SID_C_t_TempStatorFallRate;
extern const t_Temp3 SID_C_t_TempStatorHigh;
extern const t_Temp3 SID_C_t_TempStatorHighOffset;
extern const t_Temp3 SID_C_t_TempStatorLow;
extern const t_Temp3 SID_C_t_TempStatorLowOffset;
extern const t_TempRatio1 SID_C_t_TempStatorRiseRate;
extern const t_Temp3 SID_C_t_TempStatorRplcVal;
extern const t_Timer1 SID_C_ti_ENSwtOffDeb;
extern const t_Timer1 SID_C_ti_ENSwtOnDeb;
extern const t_Timer1 SID_C_ti_ExcDrvFaultSwtOffDeb;
extern const t_Timer1 SID_C_ti_ExcDrvFaultSwtOnDeb;
extern const t_Timer1 SID_C_ti_IGNSwtOffDeb;
extern const t_Timer1 SID_C_ti_IGNSwtOnDeb;
extern const t_Timer1 SID_C_ti_PhaDrvFaultSwtOffDeb;
extern const t_Timer1 SID_C_ti_PhaDrvFaultSwtOnDeb;
extern const t_Timer1 SID_C_ti_RslvDOSSwtOffDeb;
extern const t_Timer1 SID_C_ti_RslvDOSSwtOnDeb;
extern const t_Timer1 SID_C_ti_RslvLOTSwtOffDeb;
extern const t_Timer1 SID_C_ti_RslvLOTSwtOnDeb;
extern const t_Timer1 SID_C_ti_TempExcSRCHighNegDeb;
extern const t_Timer1 SID_C_ti_TempExcSRCHighPosDeb;
extern const t_Timer1 SID_C_ti_TempExcSRCLowNegDeb;
extern const t_Timer1 SID_C_ti_TempExcSRCLowPosDeb;
extern const t_Timer1 SID_C_ti_TempPSRCHighNegDeb;
extern const t_Timer1 SID_C_ti_TempPSRCHighPosDeb;
extern const t_Timer1 SID_C_ti_TempPSRCLowNegDeb;
extern const t_Timer1 SID_C_ti_TempPSRCLowPosDeb;
extern const t_Timer1 SID_C_ti_TempShellSRCHighNegDeb;
extern const t_Timer1 SID_C_ti_TempShellSRCHighPosDeb;
extern const t_Timer1 SID_C_ti_TempShellSRCLowNegDeb;
extern const t_Timer1 SID_C_ti_TempShellSRCLowPosDeb;
extern const t_Timer1 SID_C_ti_TempStatorSRCHighNegDeb;
extern const t_Timer1 SID_C_ti_TempStatorSRCHighPosDeb;
extern const t_Timer1 SID_C_ti_TempStatorSRCLowNegDeb;
extern const t_Timer1 SID_C_ti_TempStatorSRCLowPosDeb;
extern const t_Voltage4 SID_C_u_TempExcSRCHigh;
extern const t_Voltage4 SID_C_u_TempExcSRCLow;
extern const t_Voltage4 SID_C_u_TempPSRCHigh;
extern const t_Voltage4 SID_C_u_TempPSRCLow;
extern const t_Voltage4 SID_C_u_TempShellSRCHigh;
extern const t_Voltage4 SID_C_u_TempShellSRCLow;
extern const t_Voltage4 SID_C_u_TempStatorSRCHigh;
extern const t_Voltage4 SID_C_u_TempStatorSRCLow;

/*****************************************************************************
 *  Data Types
 *****************************************************************************/

/*****************************************************************************
 *  Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Declarations
 *****************************************************************************/

/*****************************************************************************
 *  Global Function Declaration
 *****************************************************************************/
#endif                                 /* RTW_HEADER_SID_MCData_h_ */

/*======================== TOOL VERSION INFORMATION ==========================*
 * MATLAB 8.3 (R2014a)27-Dec-2013                                             *
 * Simulink 8.3 (R2014a)27-Dec-2013                                           *
 * Simulink Coder 8.6 (R2014a)27-Dec-2013                                     *
 * Embedded Coder 6.6 (R2014a)27-Dec-2013                                     *
 * Stateflow 8.3 (R2014a)27-Dec-2013                                          *
 * Fixed-Point Designer 4.2 (R2014a)27-Dec-2013                               *
 *============================================================================*/

/*======================= LICENSE IN USE INFORMATION =========================*
 * fixed_point_toolbox                                                        *
 * matlab_coder                                                               *
 * real-time_workshop                                                         *
 * rtw_embedded_coder                                                         *
 * simulink                                                                   *
 * stateflow                                                                  *
 *============================================================================*/
