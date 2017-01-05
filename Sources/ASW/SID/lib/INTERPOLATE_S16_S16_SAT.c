/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: INTERPOLATE_S16_S16_SAT.c
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
#include "INTERPOLATE_S16_S16_SAT.h"

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

/* Lookup Interpolation INTERPOLATE_S16_S16_SAT */
void INTERPOLATE_S16_S16_SAT(SInt16 *pY, SInt16 yL, SInt16 yR, SInt16 x,
    SInt16 xL, SInt16 xR)
{
    SInt32 bigProd;
    SInt16 yDiff;
    SInt16 xNum;
    SInt16 xDen;
    *pY = yL;

    /* If x is not strictly between xR and xL
     * then an interpolation calculation is not necessary x == xL
     * or not valid.  The invalid situation is expected when the input
     * is beyond the left or right end of the table.  The design is
     * that yL holds the correct value for *pY
     * in invalid situations.
     */
    if ((xR > xL) && (x > xL) )
    {
        xDen = xR;

        {
            SInt32 rtb_s32_tmp;
            rtb_s32_tmp = xDen - xL;
            if (rtb_s32_tmp > 32767)
            {
                rtb_s32_tmp = 32767;
            }
            else
            {
                if (rtb_s32_tmp < -32768)
                {
                    rtb_s32_tmp = -32768;
                }
            }

            xDen = (SInt16)rtb_s32_tmp;
        }

        xNum = x;

        {
            SInt32 rtb_s32_tmp;
            rtb_s32_tmp = xNum - xL;
            if (rtb_s32_tmp > 32767)
            {
                rtb_s32_tmp = 32767;
            }
            else
            {
                if (rtb_s32_tmp < -32768)
                {
                    rtb_s32_tmp = -32768;
                }
            }

            xNum = (SInt16)rtb_s32_tmp;
        }

        yDiff = yR;

        {
            SInt32 rtb_s32_tmp;
            rtb_s32_tmp = yDiff - yL;
            if (rtb_s32_tmp > 32767)
            {
                rtb_s32_tmp = 32767;
            }
            else
            {
                if (rtb_s32_tmp < -32768)
                {
                    rtb_s32_tmp = -32768;
                }
            }

            yDiff = (SInt16)rtb_s32_tmp;
        }

        bigProd = yDiff * xNum;

        {
            SInt32 rtb_s32_tmp;
            rtb_s32_tmp = div_nzp_s32_sat_floor(bigProd, (SInt32)xDen);
            if (rtb_s32_tmp > 32767)
            {
                rtb_s32_tmp = 32767;
            }
            else
            {
                if (rtb_s32_tmp < -32768)
                {
                    rtb_s32_tmp = -32768;
                }
            }

            yDiff = (SInt16)rtb_s32_tmp;
        }

        {
            SInt32 rtb_s32_tmp;
            rtb_s32_tmp = *pY + yDiff;
            if (rtb_s32_tmp > 32767)
            {
                rtb_s32_tmp = 32767;
            }
            else
            {
                if (rtb_s32_tmp < -32768)
                {
                    rtb_s32_tmp = -32768;
                }
            }

            *pY = (SInt16)rtb_s32_tmp;
        }
    }
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
