/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID_F >
 *
 *  File: SID_F_MCData.h
 *  File Creation Date: 11-May-2016
 *  Code generated on : Wed May 11 09:47:50 2016
 *  Abstraction:
 *  Notes:
 *
 *  Model Information:
 *  Model Name: SID_F
 *  Model Version: 1.513
 *  Model Description:
 *  Creation date:	Mon Apr 21 14:27:52 2014
 *  Last Saved Modification:   Wed May 11 09:46:38 2016
 *
 *  (c)Copyright 2014-2016£¬Wuhan Eureka Control Co., Ltd.
 *******************************************************************************/
/******************************************************************************
 *  Include files
 ******************************************************************************/
#ifndef RTW_HEADER_SID_F_MCData_h_
#define RTW_HEADER_SID_F_MCData_h_

/*****************************************************************************
 *  Defines
 *****************************************************************************/
#include "rtwtypes.h"
#include "Rte_Type.h"

/* Exported data define */
#define DEMCURPHASEU_HIGH_ID           ((UInt16) 0U)
#define DEMCURPHASEV_HIGH_ID           ((UInt16) 0U)

/* Exported data declaration */
extern Boolean AOD_m_swt_PhaseDrvEn;
extern t_Current6 SID_m_i_CurPhaseU;
extern t_Current5 SID_m_i_CurPhaseURaw;
extern t_Current6 SID_m_i_CurPhaseV;
extern t_Current5 SID_m_i_CurPhaseVRaw;
extern t_Current6 SID_m_i_CurPhaseW;
extern t_Current5 SID_m_i_CurPhaseWRaw;
extern t_Angle1 SID_m_phi_RotPos;
extern Boolean SID_m_st_CurPhaseHigh;
extern Boolean SID_m_st_CurPhaseUHigh;
extern Boolean SID_m_st_CurPhaseVHigh;
extern Boolean SID_m_st_CurPhaseWHigh;
extern t_Voltage4 SID_m_u_CurRef;
extern const UInt8 SID_C_ct_CurPhaseHiCntTh;
extern const t_Current5 SID_C_i_CurPhaseHigh;
extern const t_Current5 SID_C_i_CurPhaseHighOffSet;
extern const t_Current5 SID_C_i_CurPhaseMax;
extern const SInt32 SID_C_phi_ZeroPos;

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
#endif                                 /* RTW_HEADER_SID_F_MCData_h_ */

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
