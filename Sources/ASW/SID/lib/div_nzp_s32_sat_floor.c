/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: div_nzp_s32_sat_floor.c
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
 *   Include files
 ******************************************************************************/
#include "rtwtypes.h"
#include "div_nzp_s32_sat_floor.h"

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
SInt32 div_nzp_s32_sat_floor(SInt32 temp_numerator, SInt32 temp_denominator)
{
    SInt32 temp_quotient;
    UInt32 temp_absNumerator;
    UInt32 temp_absDenominator;
    UInt32 temp_tempAbsQuotient;
    Boolean temp_quotientNeedsNegation;
    temp_absNumerator = (UInt32)(temp_numerator >= 0 ? temp_numerator :
        -temp_numerator);
    temp_absDenominator = (UInt32)(temp_denominator >= 0 ? temp_denominator :
        -temp_denominator);
    temp_quotientNeedsNegation = ((temp_numerator < 0) != (temp_denominator < 0));
    temp_tempAbsQuotient = temp_absNumerator / temp_absDenominator;
    if ((!temp_quotientNeedsNegation) && (temp_tempAbsQuotient >= 2147483647U))
    {
        temp_quotient = MAX_int32_T;
    }
    else if (temp_quotientNeedsNegation && (temp_tempAbsQuotient > 2147483647U))
    {
        temp_quotient = MIN_int32_T;
    }
    else
    {
        if (temp_quotientNeedsNegation)
        {
            temp_absNumerator %= temp_absDenominator;
            if (temp_absNumerator > 0U)
            {
                temp_tempAbsQuotient++;
            }
        }

        temp_quotient = temp_quotientNeedsNegation ? -(SInt32)
            temp_tempAbsQuotient : (SInt32)temp_tempAbsQuotient;
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
