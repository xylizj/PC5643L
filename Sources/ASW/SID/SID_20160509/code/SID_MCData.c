/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: SID_MCData.c
 *  File Creation Date: 09-May-2016
 *  Data generated on : Mon May 09 17:13:32 2016
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
 *   Include files
 ******************************************************************************/
#include "rtwtypes.h"
#include "SID_types.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/

/*****************************************************************************
 *   Data Types
 *****************************************************************************/

/*****************************************************************************
 *   Calibration Parameter Definitions
 *****************************************************************************/

/* Exported data definition */
const t_Voltage4 SID_CURX_u_TempExc[23] =
{
    140, 159, 207, 271, 356, 470, 621, 816, 1061, 1354, 1685, 2029, 2357, 2642,
    2867, 3030, 3091, 3140, 3210, 3251, 3275, 3288, 3294
} ;

const t_Voltage4 SID_CURX_u_TempP[23] =
{
    140, 159, 207, 271, 356, 470, 621, 816, 1061, 1354, 1685, 2029, 2357, 2642,
    2867, 3030, 3091, 3140, 3210, 3251, 3275, 3288, 3294
} ;

const t_Voltage4 SID_CURX_u_TempShell[20] =
{
    872, 983, 1040, 1097, 1213, 1270, 1326, 1439, 1547, 1650, 1749, 1841, 1929,
    2011, 2088, 2159, 2226, 2288, 2344, 2389
} ;

const t_Voltage4 SID_CURX_u_TempStator[20] =
{
    872, 983, 1040, 1097, 1213, 1270, 1326, 1439, 1547, 1650, 1749, 1841, 1929,
    2011, 2088, 2159, 2226, 2288, 2344, 2389
} ;

const t_Temp3 SID_CUR_t_TempExc[23] =
{
    1500, 1450, 1350, 1250, 1150, 1050, 950, 850, 750, 650, 550, 450, 350, 250,
    150, 50, 0, -50, -150, -250, -350, -450, -550
} ;

const t_Temp3 SID_CUR_t_TempP[23] =
{
    1500, 1450, 1350, 1250, 1150, 1050, 950, 850, 750, 650, 550, 450, 350, 250,
    150, 50, 0, -50, -150, -250, -350, -450, -550
} ;

const t_Temp3 SID_CUR_t_TempShell[20] =
{
    -400, -40, 140, 320, 680, 860, 1040, 1400, 1760, 2120, 2480, 2840, 3200,
    3560, 3920, 4280, 4640, 5000, 5360, 5720
} ;

const t_Temp3 SID_CUR_t_TempStator[20] =
{
    -400, -40, 140, 320, 680, 860, 1040, 1400, 1760, 2120, 2480, 2840, 3200,
    3560, 3920, 4280, 4640, 5000, 5360, 5720
} ;

const t_TempRatio1 SID_C_t_TempExcFallRate = -300;
const t_Temp3 SID_C_t_TempExcHigh = 1000;
const t_Temp3 SID_C_t_TempExcHighOffset = 20;
const t_Temp3 SID_C_t_TempExcLowOffset = 20;
const t_Temp3 SID_C_t_TempExcPLow = -300;
const t_TempRatio1 SID_C_t_TempExcRiseRate = 300;
const t_Temp3 SID_C_t_TempExcRplcVal = 0;
const t_TempRatio1 SID_C_t_TempPFallRate = -300;
const t_Temp3 SID_C_t_TempPHigh = 1000;
const t_Temp3 SID_C_t_TempPHighOffset = 20;
const t_Temp3 SID_C_t_TempPLow = -450;
const t_Temp3 SID_C_t_TempPLowOffset = 20;
const t_TempRatio1 SID_C_t_TempPRiseRate = 300;
const t_Temp3 SID_C_t_TempPRplcVal = 0;
const t_TempRatio1 SID_C_t_TempShellFallRate = -300;
const t_Temp3 SID_C_t_TempShellHigh = 1000;
const t_Temp3 SID_C_t_TempShellHighOffset = 20;
const t_Temp3 SID_C_t_TempShellLow = -450;
const t_Temp3 SID_C_t_TempShellLowOffset = 20;
const t_TempRatio1 SID_C_t_TempShellRiseRate = 300;
const t_Temp3 SID_C_t_TempShellRplcVal = 0;
const t_TempRatio1 SID_C_t_TempStatorFallRate = -300;
const t_Temp3 SID_C_t_TempStatorHigh = 1000;
const t_Temp3 SID_C_t_TempStatorHighOffset = 20;
const t_Temp3 SID_C_t_TempStatorLow = -450;
const t_Temp3 SID_C_t_TempStatorLowOffset = 20;
const t_TempRatio1 SID_C_t_TempStatorRiseRate = 300;
const t_Temp3 SID_C_t_TempStatorRplcVal = 0;
const t_Timer1 SID_C_ti_ENSwtOffDeb = 200U;
const t_Timer1 SID_C_ti_ENSwtOnDeb = 200U;
const t_Timer1 SID_C_ti_ExcDrvFaultSwtOffDeb = 200U;
const t_Timer1 SID_C_ti_ExcDrvFaultSwtOnDeb = 200U;
const t_Timer1 SID_C_ti_IGNSwtOffDeb = 200U;
const t_Timer1 SID_C_ti_IGNSwtOnDeb = 200U;
const t_Timer1 SID_C_ti_PhaDrvFaultSwtOffDeb = 200U;
const t_Timer1 SID_C_ti_PhaDrvFaultSwtOnDeb = 200U;
const t_Timer1 SID_C_ti_RslvDOSSwtOffDeb = 200U;
const t_Timer1 SID_C_ti_RslvDOSSwtOnDeb = 200U;
const t_Timer1 SID_C_ti_RslvLOTSwtOffDeb = 200U;
const t_Timer1 SID_C_ti_RslvLOTSwtOnDeb = 200U;
const t_Timer1 SID_C_ti_TempExcSRCHighNegDeb = 200U;
const t_Timer1 SID_C_ti_TempExcSRCHighPosDeb = 200U;
const t_Timer1 SID_C_ti_TempExcSRCLowNegDeb = 200U;
const t_Timer1 SID_C_ti_TempExcSRCLowPosDeb = 200U;
const t_Timer1 SID_C_ti_TempPSRCHighNegDeb = 200U;
const t_Timer1 SID_C_ti_TempPSRCHighPosDeb = 200U;
const t_Timer1 SID_C_ti_TempPSRCLowNegDeb = 200U;
const t_Timer1 SID_C_ti_TempPSRCLowPosDeb = 200U;
const t_Timer1 SID_C_ti_TempShellSRCHighNegDeb = 200U;
const t_Timer1 SID_C_ti_TempShellSRCHighPosDeb = 200U;
const t_Timer1 SID_C_ti_TempShellSRCLowNegDeb = 200U;
const t_Timer1 SID_C_ti_TempShellSRCLowPosDeb = 200U;
const t_Timer1 SID_C_ti_TempStatorSRCHighNegDeb = 200U;
const t_Timer1 SID_C_ti_TempStatorSRCHighPosDeb = 200U;
const t_Timer1 SID_C_ti_TempStatorSRCLowNegDeb = 200U;
const t_Timer1 SID_C_ti_TempStatorSRCLowPosDeb = 200U;
const t_Voltage4 SID_C_u_TempExcSRCHigh = 3500;
const t_Voltage4 SID_C_u_TempExcSRCLow = 120;
const t_Voltage4 SID_C_u_TempPSRCHigh = 3500;
const t_Voltage4 SID_C_u_TempPSRCLow = 120;
const t_Voltage4 SID_C_u_TempShellSRCHigh = 2500;
const t_Voltage4 SID_C_u_TempShellSRCLow = 800;
const t_Voltage4 SID_C_u_TempStatorSRCHigh = 2500;
const t_Voltage4 SID_C_u_TempStatorSRCLow = 800;

/*****************************************************************************
 *   Mesurement Variable Definitions
 *****************************************************************************/
t_Current4 CAN_m_i_DISExcMaxCurReq;
t_RotSpd1 CAN_m_n_ESAEndSpdReq;
t_RotSpdPerSec1 CAN_m_nps_ESASpdGradReq;
UInt8 CAN_m_st_ModReq;
Boolean CAN_m_st_ModReqOverTime;
t_Timer1 CAN_m_ti_ESADurMaxReq;
t_Torque2 CAN_m_trq_ESATrqLimReq;
t_TorquePerSec1 CAN_m_trq_NegTrqGradReq;
t_Torque2 CAN_m_trq_NegTrqLimReq;
t_TorquePerSec1 CAN_m_trq_PosTrqGradReq;
t_Torque2 CAN_m_trq_PosTrqLimReq;
t_Torque2 CAN_m_trq_TrqReq;
t_Current4 SID_m_i_CurExc;
t_RotSpd1 SID_m_n_MotSpd;
t_RotSpd1 SID_m_n_MotSpdRaw;
Boolean SID_m_st_TempExcHigh;
Boolean SID_m_st_TempExcLow;
UInt8 SID_m_st_TempExcSRC;
Boolean SID_m_st_TempExcTmpSRC;
Boolean SID_m_st_TempPUHigh;
Boolean SID_m_st_TempPULow;
UInt8 SID_m_st_TempPUSRC;
Boolean SID_m_st_TempPUTmpSRC;
Boolean SID_m_st_TempPVHigh;
Boolean SID_m_st_TempPVLow;
UInt8 SID_m_st_TempPVSRC;
Boolean SID_m_st_TempPVTmpSRC;
Boolean SID_m_st_TempPWHigh;
Boolean SID_m_st_TempPWLow;
UInt8 SID_m_st_TempPWSRC;
Boolean SID_m_st_TempPWTmpSRC;
Boolean SID_m_st_TempShellHigh;
Boolean SID_m_st_TempShellLow;
UInt8 SID_m_st_TempShellSRC;
Boolean SID_m_st_TempShellTmpSRC;
Boolean SID_m_st_TempStatorHigh;
Boolean SID_m_st_TempStatorLow;
UInt8 SID_m_st_TempStatorSRC;
Boolean SID_m_st_TempStatorTmpSRC;
Boolean SID_m_swt_ENDeb;
Boolean SID_m_swt_ExcDrvFaultDeb;
Boolean SID_m_swt_IGNDeb;
Boolean SID_m_swt_PhaDrvFaultDeb;
Boolean SID_m_swt_RslvDOSDeb;
Boolean SID_m_swt_RslvLOTDeb;
t_Pressure4 SID_m_t_TempExc;
t_Temp3 SID_m_t_TempExcLinear;
t_Pressure4 SID_m_t_TempPU;
t_Temp3 SID_m_t_TempPULinear;
t_Pressure4 SID_m_t_TempPV;
t_Temp3 SID_m_t_TempPVLinear;
t_Pressure4 SID_m_t_TempPW;
t_Temp3 SID_m_t_TempPWLinear;
t_Pressure4 SID_m_t_TempShell;
t_Temp3 SID_m_t_TempShellLinear;
t_Pressure4 SID_m_t_TempStator;
t_Temp3 SID_m_t_TempStatorLinear;
t_Voltage4 SID_m_u_TempExc;
t_Voltage4 SID_m_u_TempPU;
t_Voltage4 SID_m_u_TempPV;
t_Voltage4 SID_m_u_TempPW;
t_Voltage4 SID_m_u_TempShell;
t_Voltage4 SID_m_u_TempStator;
t_Voltage4 SID_m_u_V10;
t_Voltage4 SID_m_u_V12;
t_Voltage5 SID_m_u_V48;
t_Voltage4 SID_m_u_V5;

/*****************************************************************************
 *   FUNCTIONS
 *****************************************************************************/

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
