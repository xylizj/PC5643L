/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: BINARYSEARCH_S16.c
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
#include "BINARYSEARCH_S16.h"

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

/* Lookup Binary Search Utility BINARYSEARCH_S16 */
void BINARYSEARCH_S16(UInt32 *piLeft, UInt32 *piRght, SInt16 u, const
                      SInt16 *pData, UInt32 iHi)
{
    /* Find the location of current input value in the data table. */
    *piLeft = 0U;
    *piRght = iHi;
    if (u <= pData[0] )
    {
        /* Less than or equal to the smallest point in the table. */
        *piRght = 0U;
    }
    else if (u >= pData[iHi] )
    {
        /* Greater than or equal to the largest point in the table. */
        *piLeft = iHi;
    }
    else
    {
        UInt32 i;

        /* Do a binary search. */
        while (( *piRght - *piLeft ) > 1U )
        {
            /* Get the average of the left and right indices using to Floor rounding. */
            i = (*piLeft + *piRght) >> 1;

            /* Move either the right index or the left index so that */
            /*  LeftDataPoint <= CurrentValue < RightDataPoint */
            if (u < pData[i] )
            {
                *piRght = i;
            }
            else
            {
                *piLeft = i;
            }
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
