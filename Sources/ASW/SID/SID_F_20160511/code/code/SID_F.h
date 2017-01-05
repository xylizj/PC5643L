/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID_F >
 *
 *  File: SID_F.h
 *  File Creation Date: 11-May-2016
 *  Code generated on : Wed May 11 14:53:37 2016
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
 *  Include files
 ******************************************************************************/
#ifndef RTW_HEADER_SID_F_h_
#define RTW_HEADER_SID_F_h_
#include <stddef.h>
#ifndef SID_F_COMMON_INCLUDES_
# define SID_F_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "SetErr.h"
#endif                                 /* SID_F_COMMON_INCLUDES_ */

#include "SID_F_types.h"

/* Includes for objects with custom storage classes. */
#include "SID_F_MCData.h"
#include "div_nzp_repeat_s32_floor.h"
#include "div_nzp_s32_floor.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/

/* Macros for accessing real-time model data structure */
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/*****************************************************************************
 *  Data Types
 *****************************************************************************/

/* Block states (auto storage) for system '<S2>/CurPhaseSRC' */
typedef struct
{
    struct
    {
        UInt32 is_c5_SID_F:3;          /* '<S17>/Check_Level' */
        UInt32 is_c2_SID_F:3;          /* '<S15>/Check_Level' */
        UInt32 is_c3_SID_F:3;          /* '<S13>/Check_Level' */
        UInt32 is_active_c5_SID_F:1;   /* '<S17>/Check_Level' */
        UInt32 is_active_c2_SID_F:1;   /* '<S15>/Check_Level' */
        UInt32 is_active_c3_SID_F:1;   /* '<S13>/Check_Level' */
    }
    bitsForTID0;

    UInt16 Count;                    /* '<S17>/Check_Level' */
    UInt16 Count_m;                  /* '<S15>/Check_Level' */
    UInt16 Count_m0;                 /* '<S13>/Check_Level' */
}
t_SID_F_rtDW_CurPhaseSRC;

/*****************************************************************************
 *  Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Declarations
 *****************************************************************************/

/* Extern declarations of internal data for system '<S2>/CurPhaseSRC' */
extern t_SID_F_rtDW_CurPhaseSRC g_SID_F_CurPhaseSRC_DW;

/* Model entry point functions */
extern void SID_F_initialize(void);
extern void SID_F_step(void);

/*****************************************************************************
 *  Global Function Declaration
 *****************************************************************************/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SID_F'
 * '<S1>'   : 'SID_F/SIGNAL'
 * '<S2>'   : 'SID_F/SIGNAL/CurPhase'
 * '<S3>'   : 'SID_F/SIGNAL/CurRef'
 * '<S4>'   : 'SID_F/SIGNAL/Position'
 * '<S5>'   : 'SID_F/SIGNAL/CurPhase/CurPhaseConvert'
 * '<S6>'   : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC'
 * '<S7>'   : 'SID_F/SIGNAL/CurPhase/CurPhaseConvert/CurPhaseUCnvt'
 * '<S8>'   : 'SID_F/SIGNAL/CurPhase/CurPhaseConvert/CurPhaseVCnvt'
 * '<S9>'   : 'SID_F/SIGNAL/CurPhase/CurPhaseConvert/CurPhaseWCnvt'
 * '<S10>'  : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC/Err_process'
 * '<S11>'  : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC/Err_process1'
 * '<S12>'  : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC/Err_process2'
 * '<S13>'  : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC/Err_process/Check_Level'
 * '<S14>'  : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC/Err_process/Check_Level/Check_Level'
 * '<S15>'  : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC/Err_process1/Check_Level'
 * '<S16>'  : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC/Err_process1/Check_Level/Check_Level'
 * '<S17>'  : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC/Err_process2/Check_Level'
 * '<S18>'  : 'SID_F/SIGNAL/CurPhase/CurPhaseSRC/Err_process2/Check_Level/Check_Level'
 */
#endif                                 /* RTW_HEADER_SID_F_h_ */

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
