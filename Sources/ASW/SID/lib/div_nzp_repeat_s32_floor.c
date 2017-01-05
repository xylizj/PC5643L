/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID_F >
 *
 *  File: div_nzp_repeat_s32_floor.c
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
 *  (c)Copyright 2014-2016��Wuhan Eureka Control Co., Ltd.
 *******************************************************************************/
/******************************************************************************
 *   Include files
 ******************************************************************************/
#include "rtwtypes.h"
#include "div_nzp_repeat_u32.h"
#include "div_nzp_repeat_u32_ceiling.h"
#include "div_nzp_repeat_s32_floor.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/

/*****************************************************************************
 *   Data Types
 *****************************************************************************/

/*****************************************************************************
 *   Definitions
 *****************************************************************************/

/*****************************************************************************
 *    Declarations
 *****************************************************************************/

/******************************************************************************
 *   FILE SCOPE DATA
 ******************************************************************************/

/*****************************************************************************
 *   FUNCTIONS
 *****************************************************************************/
SInt32 div_nzp_repeat_s32_floor(SInt32 temp_numerator, SInt32
    temp_denominator, UInt32 temp_nRepeatSub)
{
    SInt32 temp_quotient;
    UInt32 temp_absNumerator;
    UInt32 temp_absDenominator;
    temp_absNumerator = (UInt32)(temp_numerator >= 0 ? temp_numerator :
        -temp_numerator);
    temp_absDenominator = (UInt32)(temp_denominator >= 0 ? temp_denominator :
        -temp_denominator);
    if ((temp_numerator < 0) != (temp_denominator < 0))
    {
        temp_quotient = -(SInt32)div_nzp_repeat_u32_ceiling(temp_absNumerator,
            temp_absDenominator, temp_nRepeatSub);
    }
    else
    {
        temp_quotient = (SInt32)div_nzp_repeat_u32(temp_absNumerator,
            temp_absDenominator, temp_nRepeatSub);
    }

    return temp_quotient;
}

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
