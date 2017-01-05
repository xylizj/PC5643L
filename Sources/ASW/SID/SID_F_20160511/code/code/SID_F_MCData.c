/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID_F >
 *
 *  File: SID_F_MCData.c
 *  File Creation Date: 11-May-2016
 *  Data generated on : Wed May 11 14:53:37 2016
 *  Abstraction:
 *  Notes:
 *
 *  Model Information:
 *  Model Name: SID_F
 *  Model Version: 1.518
 *  Model Description:
 *  Creation date:	Mon Apr 21 14:27:52 2014
 *  Last Saved Modification:   Wed May 11 14:47:49 2016
 *
 *  (c)Copyright 2014-2016£¬Wuhan Eureka Control Co., Ltd.
 *******************************************************************************/
/******************************************************************************
 *   Include files
 ******************************************************************************/
#include "rtwtypes.h"
#include "SID_F_types.h"

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
const UInt8 SID_C_ct_CurPhaseHiCntTh = 5U;
const t_Current5 SID_C_i_CurPhaseHigh = 102400;
const t_Current5 SID_C_i_CurPhaseHighOffSet = 10240;
const t_Current5 SID_C_i_CurPhaseMax = 307200;
const SInt32 SID_C_phi_ZeroPos = 4066276;

/*****************************************************************************
 *   Mesurement Variable Definitions
 *****************************************************************************/
Boolean AOD_m_swt_PhaseDrvEn;
t_Current6 SID_m_i_CurPhaseU;
t_Current5 SID_m_i_CurPhaseURaw;
t_Current6 SID_m_i_CurPhaseV;
t_Current5 SID_m_i_CurPhaseVRaw;
t_Current6 SID_m_i_CurPhaseW;
t_Current5 SID_m_i_CurPhaseWRaw;
t_Angle1 SID_m_phi_RotPos;
Boolean SID_m_st_CurPhaseHigh;
Boolean SID_m_st_CurPhaseUHigh;
Boolean SID_m_st_CurPhaseVHigh;
Boolean SID_m_st_CurPhaseWHigh;
t_Voltage4 SID_m_u_CurRef;

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
