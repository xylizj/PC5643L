/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: mul_wide_s32.c
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
#include "mul_wide_s32.h"

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
void mul_wide_s32(SInt32 temp_in0, SInt32 temp_in1, UInt32
                  *temp_ptrOutBitsHi, UInt32 *temp_ptrOutBitsLo)
{
    UInt32 temp_absIn0;
    UInt32 temp_absIn1;
    UInt32 temp_in0Lo;
    UInt32 temp_in0Hi;
    UInt32 temp_in1Hi;
    UInt32 temp_productHiLo;
    UInt32 temp_productLoHi;
    temp_absIn0 = (UInt32)(temp_in0 < 0 ? -temp_in0 : temp_in0);
    temp_absIn1 = (UInt32)(temp_in1 < 0 ? -temp_in1 : temp_in1);
    temp_in0Hi = temp_absIn0 >> 16U;
    temp_in0Lo = temp_absIn0 & 65535U;
    temp_in1Hi = temp_absIn1 >> 16U;
    temp_absIn0 = temp_absIn1 & 65535U;
    temp_productHiLo = temp_in0Hi * temp_absIn0;
    temp_productLoHi = temp_in0Lo * temp_in1Hi;
    temp_absIn0 *= temp_in0Lo;
    temp_absIn1 = 0U;
    temp_in0Lo = (temp_productLoHi << 16U) + temp_absIn0;
    if (temp_in0Lo < temp_absIn0)
    {
        temp_absIn1 = 1U;
    }

    temp_absIn0 = temp_in0Lo;
    temp_in0Lo += temp_productHiLo << 16U;
    if (temp_in0Lo < temp_absIn0)
    {
        temp_absIn1++;
    }

    temp_absIn0 = (((temp_productLoHi >> 16U) + (temp_productHiLo >> 16U)) +
                   temp_in0Hi * temp_in1Hi) + temp_absIn1;
    if (!((temp_in0 == 0) || ((temp_in1 == 0) || ((temp_in0 > 0) == (temp_in1 >
            0)))))
    {
        temp_absIn0 = ~temp_absIn0;
        temp_in0Lo = ~temp_in0Lo;
        temp_in0Lo++;
        if (temp_in0Lo == 0U)
        {
            temp_absIn0++;
        }
    }

    *temp_ptrOutBitsHi = temp_absIn0;
    *temp_ptrOutBitsLo = temp_in0Lo;
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
