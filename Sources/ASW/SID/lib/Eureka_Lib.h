/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: Eureka_Lib.h
 *  File Creation Date: 09-May-2016
 *  Code generated on : Mon May 09 13:28:12 2016
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
#ifndef RTW_HEADER_Eureka_Lib_h_
#define RTW_HEADER_Eureka_Lib_h_
#ifndef SID_COMMON_INCLUDES_
# define SID_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "SetErr.h"
#endif                                 /* SID_COMMON_INCLUDES_ */

#include "SID_types.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/

/*****************************************************************************
 *  Data Types
 *****************************************************************************/

/* Block states (auto storage) for system '<S31>/SRC_Check' */
typedef struct
{
    struct
    {
        UInt32 is_Defect:3;            /* '<S35>/SRC_Check' */
        UInt32 is_c3_Ref_Lib:2;        /* '<S35>/SRC_Check' */
        UInt32 is_active_c3_Ref_Lib:1; /* '<S35>/SRC_Check' */
    }
    bitsForTID0;

    UInt16 local_Timer;              /* '<S35>/SRC_Check' */
}
t_SID_rtDW_SRC_Check;

/* Block states (auto storage) for system '<S99>/Swtich_Debouncing' */
typedef struct
{
    struct
    {
        UInt32 is_c5_Ref_Lib:3;        /* '<S105>/Switch_Debouncing' */
        UInt32 is_active_c5_Ref_Lib:1; /* '<S105>/Switch_Debouncing' */
    }
    bitsForTID0;

    UInt16 localTimer;               /* '<S105>/Switch_Debouncing' */
}
t_SID_rtDW_Swtich_Debouncing;

/*****************************************************************************
 *  Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Declarations
 *****************************************************************************/
extern void SID_SRC_Check_Init(UInt8 *rty_SRC_Def_Status, Boolean
    *rty_SRC_Tmp_Def_Flag);
extern void SID_SRC_Check(UInt8 rtu_Clear_Def_Flag, t_Voltage4 rtu_Sig_Volt,
    t_Voltage4 rtu_Par_SRC_H_Threshold, t_Voltage4 rtu_Par_SRC_L_Threshold,
    t_Timer1 rtu_Par_SRC_H_PosDeb, t_Timer1 rtu_Par_SRC_H_NegDeb, t_Timer1
    rtu_Par_SRC_L_PosDeb, t_Timer1 rtu_Par_SRC_L_NegDeb, t_Timer1
    rtu_Par_SampleTime, UInt8 *rty_SRC_Def_Status, Boolean
    *rty_SRC_Tmp_Def_Flag, t_SID_rtDW_SRC_Check *localDW);
extern void SID_Swtich_Debouncing_Init(Boolean *rty_swtDeb);
extern void SID_Swtich_Debouncing(UInt8 rtu_swtRaw, t_Timer1
    rtu_Par_SwtOffDebTime, t_Timer1 rtu_Par_SwtOnDebTime, t_Timer1
    rtu_Par_SampleTime, Boolean *rty_swtDeb, t_SID_rtDW_Swtich_Debouncing
    *localDW);

/*****************************************************************************
 *  Global Function Declaration
 *****************************************************************************/
#endif                                 /* RTW_HEADER_Eureka_Lib_h_ */

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
