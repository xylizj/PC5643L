/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID_F >
 *
 *  File: SID_F.c
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
 *   Include files
 ******************************************************************************/
#include "SID_F.h"
#include "SID_F_private.h"
#include "VFB.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/

/* Named constants for Chart: '<S13>/Check_Level' */
#define MACRO_IN_Confirm               ((UInt8)1U)
#define MACRO_IN_Init                  ((UInt8)2U)
#define MACRO_IN_UnderThrhCnt          ((UInt8)3U)
#define MACRO_IN_UpThrhCnt             ((UInt8)4U)

/*****************************************************************************
 *   Data Types
 *****************************************************************************/

/*****************************************************************************
 *   Definitions
 *****************************************************************************/

/*****************************************************************************
 *    Declarations
 *****************************************************************************/

/* Declare variables for internal data of system '<S2>/CurPhaseSRC' */
t_SID_F_rtDW_CurPhaseSRC g_SID_F_CurPhaseSRC_DW;

/******************************************************************************
 *   FILE SCOPE DATA
 ******************************************************************************/

/*****************************************************************************
 *   FUNCTIONS
 *****************************************************************************/

/* Output and update for atomic system: '<S5>/CurPhaseUCnvt' */
void SID_F_CurPhaseUCnvt(void)
{
    /* Gain: '<S7>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_CurPhaseURaw'
     *  Inport: '<Root>/SID_m_ct_CurRefRaw'
     *  Sum: '<S7>/Add'
     */
    SID_m_i_CurPhaseURaw = (SInt32)((SInt16)(SID_m_ct_CurPhaseURaw -
        2030) * 150U);

    /* Product: '<S7>/Product' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    /*SID_m_i_CurPhaseU = div_nzp_repeat_s32_floor(SID_m_i_CurPhaseURaw,
        SID_C_i_CurPhaseMax, 31U);*/
    SID_m_i_CurPhaseU = (SID_m_i_CurPhaseURaw/300)<<21;
}

/* Output and update for atomic system: '<S5>/CurPhaseVCnvt' */
void SID_F_CurPhaseVCnvt(void)
{
    /* Gain: '<S8>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_CurPhaseVRaw'
     *  Inport: '<Root>/SID_m_ct_CurRefRaw'
     *  Sum: '<S8>/Add'
     */
    SID_m_i_CurPhaseVRaw = (SInt32)((SInt16)(SID_m_ct_CurPhaseVRaw -
        2060) * 150U);

    /* Product: '<S8>/Product' incorporates:
     *  Constant: '<S8>/Constant2'
     */
    /*SID_m_i_CurPhaseV = div_nzp_repeat_s32_floor(SID_m_i_CurPhaseVRaw,
        SID_C_i_CurPhaseMax, 31U);*/
        SID_m_i_CurPhaseV = (SID_m_i_CurPhaseVRaw/300)<<21;
}

/* Output and update for atomic system: '<S5>/CurPhaseWCnvt' */
void SID_F_CurPhaseWCnvt(void)
{
    /* Gain: '<S9>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_CurPhaseWRaw'
     *  Inport: '<Root>/SID_m_ct_CurRefRaw'
     *  Sum: '<S9>/Add'
     */
    SID_m_i_CurPhaseWRaw = (SInt32)((SInt16)(SID_m_ct_CurPhaseWRaw -
        2013) * 150U);

    /* Product: '<S9>/Product' incorporates:
     *  Constant: '<S9>/Constant2'
     */
    /*SID_m_i_CurPhaseW = div_nzp_repeat_s32_floor(SID_m_i_CurPhaseWRaw,
        SID_C_i_CurPhaseMax, 31U);*/
                SID_m_i_CurPhaseW = (SID_m_i_CurPhaseWRaw/300)<<21;

}

/* Output and update for atomic system: '<S2>/CurPhaseSRC' */
void SID_F_CurPhaseSRC(void)
{
    /* local block i/o variables */
    UInt8 lbo_DataTypeConversion2;
    t_Current5 lbo_Abs;
    SInt32 temp_qY;

    /* Abs: '<S6>/Abs' */
    if (SID_m_i_CurPhaseURaw < 0)
    {
        lbo_Abs = -SID_m_i_CurPhaseURaw;
    }
    else
    {
        lbo_Abs = SID_m_i_CurPhaseURaw;
    }

    /* End of Abs: '<S6>/Abs' */

    /* Chart: '<S13>/Check_Level' incorporates:
     *  Constant: '<S6>/Constant10'
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant3'
     */
    /* Gateway: SIGNAL/CurPhase/CurPhaseSRC/Err_process/Check_Level/Check_Level */
    /* During: SIGNAL/CurPhase/CurPhaseSRC/Err_process/Check_Level/Check_Level */
    if (g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_active_c3_SID_F == 0U)
    {
        /* Entry: SIGNAL/CurPhase/CurPhaseSRC/Err_process/Check_Level/Check_Level */
        g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_active_c3_SID_F = 1U;

        /* Entry Internal: SIGNAL/CurPhase/CurPhaseSRC/Err_process/Check_Level/Check_Level */
        /* Transition: '<S14>:9' */
        g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c3_SID_F = MACRO_IN_Init;

        /* Entry 'Init': '<S14>:6' */
        SID_m_st_CurPhaseUHigh = false;
    }
    else
    {
        switch (g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c3_SID_F)
        {
          case MACRO_IN_Confirm:
            /* During 'Confirm': '<S14>:17' */
            temp_qY = SID_C_i_CurPhaseHigh - SID_C_i_CurPhaseHighOffSet;
            if ((SID_C_i_CurPhaseHigh < 0) && ((SID_C_i_CurPhaseHighOffSet >= 0)
                 && (temp_qY >= 0)))
            {
                temp_qY = MIN_int32_T;
            }
            else
            {
                if ((SID_C_i_CurPhaseHigh >= 0) && ((SID_C_i_CurPhaseHighOffSet <
                      0) && (temp_qY < 0)))
                {
                    temp_qY = MAX_int32_T;
                }
            }

            if (lbo_Abs < temp_qY)
            {
                /* Transition: '<S14>:18' */
                /* Exit 'Confirm': '<S14>:17' */
                g_SID_F_CurPhaseSRC_DW.Count_m0 = 0U;
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c3_SID_F = MACRO_IN_Init;

                /* Entry 'Init': '<S14>:6' */
                SID_m_st_CurPhaseUHigh = false;
            }
            break;

          case MACRO_IN_Init:
            /* During 'Init': '<S14>:6' */
            if (lbo_Abs >= SID_C_i_CurPhaseHigh)
            {
                /* Transition: '<S14>:15' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c3_SID_F =
                    MACRO_IN_UpThrhCnt;

                /* Entry 'UpThrhCnt': '<S14>:7' */
                SID_m_st_CurPhaseUHigh = false;
            }
            break;

          case MACRO_IN_UnderThrhCnt:
            /* During 'UnderThrhCnt': '<S14>:23' */
            if (lbo_Abs >= SID_C_i_CurPhaseHigh)
            {
                /* Transition: '<S14>:24' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c3_SID_F =
                    MACRO_IN_UpThrhCnt;

                /* Entry 'UpThrhCnt': '<S14>:7' */
                SID_m_st_CurPhaseUHigh = false;
            }
            else if (g_SID_F_CurPhaseSRC_DW.Count_m0 == 0)
            {
                /* Transition: '<S14>:25' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c3_SID_F = MACRO_IN_Init;

                /* Entry 'Init': '<S14>:6' */
                SID_m_st_CurPhaseUHigh = false;
            }
            else
            {
                lbo_Abs = g_SID_F_CurPhaseSRC_DW.Count_m0 - 1;
                if (lbo_Abs < 0)
                {
                    lbo_Abs = 0;
                }

                g_SID_F_CurPhaseSRC_DW.Count_m0 = (UInt16)lbo_Abs;
            }
            break;

          default:
            /* During 'UpThrhCnt': '<S14>:7' */
            if (g_SID_F_CurPhaseSRC_DW.Count_m0 >= SID_C_ct_CurPhaseHiCntTh)
            {
                /* Transition: '<S14>:21' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c3_SID_F =
                    MACRO_IN_Confirm;

                /* Entry 'Confirm': '<S14>:17' */
                SID_m_st_CurPhaseUHigh = true;
            }
            else
            {
                temp_qY = SID_C_i_CurPhaseHigh - SID_C_i_CurPhaseHighOffSet;
                if ((SID_C_i_CurPhaseHigh < 0) && ((SID_C_i_CurPhaseHighOffSet >=
                      0) && (temp_qY >= 0)))
                {
                    temp_qY = MIN_int32_T;
                }
                else
                {
                    if ((SID_C_i_CurPhaseHigh >= 0) &&
                            ((SID_C_i_CurPhaseHighOffSet < 0) && (temp_qY < 0)))
                    {
                        temp_qY = MAX_int32_T;
                    }
                }

                if (lbo_Abs < temp_qY)
                {
                    /* Transition: '<S14>:20' */
                    g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c3_SID_F =
                        MACRO_IN_UnderThrhCnt;

                    /* Entry 'UnderThrhCnt': '<S14>:23' */
                    SID_m_st_CurPhaseUHigh = false;
                }
                else
                {
                    lbo_Abs = g_SID_F_CurPhaseSRC_DW.Count_m0 + 1;
                    if (lbo_Abs > 65535)
                    {
                        lbo_Abs = 65535;
                    }

                    g_SID_F_CurPhaseSRC_DW.Count_m0 = (UInt16)lbo_Abs;
                }
            }
            break;
        }
    }

    /* End of Chart: '<S13>/Check_Level' */

    /* Abs: '<S6>/Abs1' */
    if (SID_m_i_CurPhaseVRaw < 0)
    {
        lbo_Abs = -SID_m_i_CurPhaseVRaw;
    }
    else
    {
        lbo_Abs = SID_m_i_CurPhaseVRaw;
    }

    /* End of Abs: '<S6>/Abs1' */

    /* Chart: '<S15>/Check_Level' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant11'
     *  Constant: '<S6>/Constant5'
     */
    /* Gateway: SIGNAL/CurPhase/CurPhaseSRC/Err_process1/Check_Level/Check_Level */
    /* During: SIGNAL/CurPhase/CurPhaseSRC/Err_process1/Check_Level/Check_Level */
    if (g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_active_c2_SID_F == 0U)
    {
        /* Entry: SIGNAL/CurPhase/CurPhaseSRC/Err_process1/Check_Level/Check_Level */
        g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_active_c2_SID_F = 1U;

        /* Entry Internal: SIGNAL/CurPhase/CurPhaseSRC/Err_process1/Check_Level/Check_Level */
        /* Transition: '<S16>:9' */
        g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c2_SID_F = MACRO_IN_Init;

        /* Entry 'Init': '<S16>:6' */
        SID_m_st_CurPhaseVHigh = false;
    }
    else
    {
        switch (g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c2_SID_F)
        {
          case MACRO_IN_Confirm:
            /* During 'Confirm': '<S16>:17' */
            temp_qY = SID_C_i_CurPhaseHigh - SID_C_i_CurPhaseHighOffSet;
            if ((SID_C_i_CurPhaseHigh < 0) && ((SID_C_i_CurPhaseHighOffSet >= 0)
                 && (temp_qY >= 0)))
            {
                temp_qY = MIN_int32_T;
            }
            else
            {
                if ((SID_C_i_CurPhaseHigh >= 0) && ((SID_C_i_CurPhaseHighOffSet <
                      0) && (temp_qY < 0)))
                {
                    temp_qY = MAX_int32_T;
                }
            }

            if (lbo_Abs < temp_qY)
            {
                /* Transition: '<S16>:18' */
                /* Exit 'Confirm': '<S16>:17' */
                g_SID_F_CurPhaseSRC_DW.Count_m = 0U;
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c2_SID_F = MACRO_IN_Init;

                /* Entry 'Init': '<S16>:6' */
                SID_m_st_CurPhaseVHigh = false;
            }
            break;

          case MACRO_IN_Init:
            /* During 'Init': '<S16>:6' */
            if (lbo_Abs >= SID_C_i_CurPhaseHigh)
            {
                /* Transition: '<S16>:15' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c2_SID_F =
                    MACRO_IN_UpThrhCnt;

                /* Entry 'UpThrhCnt': '<S16>:7' */
                SID_m_st_CurPhaseVHigh = false;
            }
            break;

          case MACRO_IN_UnderThrhCnt:
            /* During 'UnderThrhCnt': '<S16>:23' */
            if (lbo_Abs >= SID_C_i_CurPhaseHigh)
            {
                /* Transition: '<S16>:24' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c2_SID_F =
                    MACRO_IN_UpThrhCnt;

                /* Entry 'UpThrhCnt': '<S16>:7' */
                SID_m_st_CurPhaseVHigh = false;
            }
            else if (g_SID_F_CurPhaseSRC_DW.Count_m == 0)
            {
                /* Transition: '<S16>:25' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c2_SID_F = MACRO_IN_Init;

                /* Entry 'Init': '<S16>:6' */
                SID_m_st_CurPhaseVHigh = false;
            }
            else
            {
                lbo_Abs = g_SID_F_CurPhaseSRC_DW.Count_m - 1;
                if (lbo_Abs < 0)
                {
                    lbo_Abs = 0;
                }

                g_SID_F_CurPhaseSRC_DW.Count_m = (UInt16)lbo_Abs;
            }
            break;

          default:
            /* During 'UpThrhCnt': '<S16>:7' */
            if (g_SID_F_CurPhaseSRC_DW.Count_m >= SID_C_ct_CurPhaseHiCntTh)
            {
                /* Transition: '<S16>:21' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c2_SID_F =
                    MACRO_IN_Confirm;

                /* Entry 'Confirm': '<S16>:17' */
                SID_m_st_CurPhaseVHigh = true;
            }
            else
            {
                temp_qY = SID_C_i_CurPhaseHigh - SID_C_i_CurPhaseHighOffSet;
                if ((SID_C_i_CurPhaseHigh < 0) && ((SID_C_i_CurPhaseHighOffSet >=
                      0) && (temp_qY >= 0)))
                {
                    temp_qY = MIN_int32_T;
                }
                else
                {
                    if ((SID_C_i_CurPhaseHigh >= 0) &&
                            ((SID_C_i_CurPhaseHighOffSet < 0) && (temp_qY < 0)))
                    {
                        temp_qY = MAX_int32_T;
                    }
                }

                if (lbo_Abs < temp_qY)
                {
                    /* Transition: '<S16>:20' */
                    g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c2_SID_F =
                        MACRO_IN_UnderThrhCnt;

                    /* Entry 'UnderThrhCnt': '<S16>:23' */
                    SID_m_st_CurPhaseVHigh = false;
                }
                else
                {
                    lbo_Abs = g_SID_F_CurPhaseSRC_DW.Count_m + 1;
                    if (lbo_Abs > 65535)
                    {
                        lbo_Abs = 65535;
                    }

                    g_SID_F_CurPhaseSRC_DW.Count_m = (UInt16)lbo_Abs;
                }
            }
            break;
        }
    }

    /* End of Chart: '<S15>/Check_Level' */

    /* Abs: '<S6>/Abs2' */
    if (SID_m_i_CurPhaseWRaw < 0)
    {
        lbo_Abs = -SID_m_i_CurPhaseWRaw;
    }
    else
    {
        lbo_Abs = SID_m_i_CurPhaseWRaw;
    }

    /* End of Abs: '<S6>/Abs2' */

    /* Chart: '<S17>/Check_Level' incorporates:
     *  Constant: '<S6>/Constant12'
     *  Constant: '<S6>/Constant7'
     *  Constant: '<S6>/Constant8'
     */
    /* Gateway: SIGNAL/CurPhase/CurPhaseSRC/Err_process2/Check_Level/Check_Level */
    /* During: SIGNAL/CurPhase/CurPhaseSRC/Err_process2/Check_Level/Check_Level */
    if (g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_active_c5_SID_F == 0U)
    {
        /* Entry: SIGNAL/CurPhase/CurPhaseSRC/Err_process2/Check_Level/Check_Level */
        g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_active_c5_SID_F = 1U;

        /* Entry Internal: SIGNAL/CurPhase/CurPhaseSRC/Err_process2/Check_Level/Check_Level */
        /* Transition: '<S18>:9' */
        g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c5_SID_F = MACRO_IN_Init;

        /* Entry 'Init': '<S18>:6' */
        SID_m_st_CurPhaseWHigh = false;
    }
    else
    {
        switch (g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c5_SID_F)
        {
          case MACRO_IN_Confirm:
            /* During 'Confirm': '<S18>:17' */
            temp_qY = SID_C_i_CurPhaseHigh - SID_C_i_CurPhaseHighOffSet;
            if ((SID_C_i_CurPhaseHigh < 0) && ((SID_C_i_CurPhaseHighOffSet >= 0)
                 && (temp_qY >= 0)))
            {
                temp_qY = MIN_int32_T;
            }
            else
            {
                if ((SID_C_i_CurPhaseHigh >= 0) && ((SID_C_i_CurPhaseHighOffSet <
                      0) && (temp_qY < 0)))
                {
                    temp_qY = MAX_int32_T;
                }
            }

            if (lbo_Abs < temp_qY)
            {
                /* Transition: '<S18>:18' */
                /* Exit 'Confirm': '<S18>:17' */
                g_SID_F_CurPhaseSRC_DW.Count = 0U;
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c5_SID_F = MACRO_IN_Init;

                /* Entry 'Init': '<S18>:6' */
                SID_m_st_CurPhaseWHigh = false;
            }
            break;

          case MACRO_IN_Init:
            /* During 'Init': '<S18>:6' */
            if (lbo_Abs >= SID_C_i_CurPhaseHigh)
            {
                /* Transition: '<S18>:15' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c5_SID_F =
                    MACRO_IN_UpThrhCnt;

                /* Entry 'UpThrhCnt': '<S18>:7' */
                SID_m_st_CurPhaseWHigh = false;
            }
            break;

          case MACRO_IN_UnderThrhCnt:
            /* During 'UnderThrhCnt': '<S18>:23' */
            if (lbo_Abs >= SID_C_i_CurPhaseHigh)
            {
                /* Transition: '<S18>:24' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c5_SID_F =
                    MACRO_IN_UpThrhCnt;

                /* Entry 'UpThrhCnt': '<S18>:7' */
                SID_m_st_CurPhaseWHigh = false;
            }
            else if (g_SID_F_CurPhaseSRC_DW.Count == 0)
            {
                /* Transition: '<S18>:25' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c5_SID_F = MACRO_IN_Init;

                /* Entry 'Init': '<S18>:6' */
                SID_m_st_CurPhaseWHigh = false;
            }
            else
            {
                lbo_Abs = g_SID_F_CurPhaseSRC_DW.Count - 1;
                if (lbo_Abs < 0)
                {
                    lbo_Abs = 0;
                }

                g_SID_F_CurPhaseSRC_DW.Count = (UInt16)lbo_Abs;
            }
            break;

          default:
            /* During 'UpThrhCnt': '<S18>:7' */
            if (g_SID_F_CurPhaseSRC_DW.Count >= SID_C_ct_CurPhaseHiCntTh)
            {
                /* Transition: '<S18>:21' */
                g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c5_SID_F =
                    MACRO_IN_Confirm;

                /* Entry 'Confirm': '<S18>:17' */
                SID_m_st_CurPhaseWHigh = true;
            }
            else
            {
                temp_qY = SID_C_i_CurPhaseHigh - SID_C_i_CurPhaseHighOffSet;
                if ((SID_C_i_CurPhaseHigh < 0) && ((SID_C_i_CurPhaseHighOffSet >=
                      0) && (temp_qY >= 0)))
                {
                    temp_qY = MIN_int32_T;
                }
                else
                {
                    if ((SID_C_i_CurPhaseHigh >= 0) &&
                            ((SID_C_i_CurPhaseHighOffSet < 0) && (temp_qY < 0)))
                    {
                        temp_qY = MAX_int32_T;
                    }
                }

                if (lbo_Abs < temp_qY)
                {
                    /* Transition: '<S18>:20' */
                    g_SID_F_CurPhaseSRC_DW.bitsForTID0.is_c5_SID_F =
                        MACRO_IN_UnderThrhCnt;

                    /* Entry 'UnderThrhCnt': '<S18>:23' */
                    SID_m_st_CurPhaseWHigh = false;
                }
                else
                {
                    lbo_Abs = g_SID_F_CurPhaseSRC_DW.Count + 1;
                    if (lbo_Abs > 65535)
                    {
                        lbo_Abs = 65535;
                    }

                    g_SID_F_CurPhaseSRC_DW.Count = (UInt16)lbo_Abs;
                }
            }
            break;
        }
    }

    /* End of Chart: '<S17>/Check_Level' */

    /* Logic: '<S6>/Logical Operator' */
    SID_m_st_CurPhaseHigh = (SID_m_st_CurPhaseUHigh || SID_m_st_CurPhaseVHigh ||
        SID_m_st_CurPhaseWHigh);

    /* DataStoreWrite: '<S6>/Data Store Write' */
    AOD_m_swt_PhaseDrvEn = SID_m_st_CurPhaseHigh;

    /* DataTypeConversion: '<S10>/Data Type Conversion2' */
    lbo_DataTypeConversion2 = (UInt8)SID_m_st_CurPhaseUHigh;

    /*
     * Block description for '<S6>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S10>/sfun_SetErr_High' incorporates:
     *  Constant: '<S6>/Constant4'
     *
     * Block description for '<S6>/Constant4':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMCURPHASEU_HIGH_ID, lbo_DataTypeConversion2);

    /* DataTypeConversion: '<S11>/Data Type Conversion2' */
    lbo_DataTypeConversion2 = (UInt8)SID_m_st_CurPhaseVHigh;

    /*
     * Block description for '<S6>/Constant6':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S11>/sfun_SetErr_High' incorporates:
     *  Constant: '<S6>/Constant6'
     *
     * Block description for '<S6>/Constant6':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMCURPHASEV_HIGH_ID, lbo_DataTypeConversion2);

    /* DataTypeConversion: '<S12>/Data Type Conversion2' */
    lbo_DataTypeConversion2 = (UInt8)SID_m_st_CurPhaseWHigh;

    /*
     * Block description for '<S6>/Constant9':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S12>/sfun_SetErr_High' incorporates:
     *  Constant: '<S6>/Constant9'
     *
     * Block description for '<S6>/Constant9':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMCURPHASEU_HIGH_ID, lbo_DataTypeConversion2);
}

/* Output and update for atomic system: '<S1>/CurRef' */
void SID_F_CurRef(void)
{
    /* Gain: '<S3>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_CurRefRaw'
     */
    SID_m_u_CurRef = (SInt16)(825U * SID_m_ct_CurRefRaw >> 10);
}

/* Output and update for atomic system: '<S1>/Position' */
uint32_t angle_x;
uint32_t angle_zero = 19627;
uint32_t angle_y;
int32_t angle_z;
void SID_F_Position(void)
{
	angle_x = SID_m_ct_PositionRaw *2 + angle_zero;
	angle_y = angle_x % 65536;
	
	if(angle_y>=32768)//[-1,1)
	{
		angle_z = (int32_t)(angle_y - 65536);
	}
	else
	{
		angle_z = angle_y;
	}
	
	angle_z <<= 16;
	
	SID_m_phi_RotPos = angle_z;
}









/* Model step function */
void SID_F_step(void)
{
    /* Outputs for Atomic SubSystem: '<S1>/Position' */
    SID_F_Position();

    /* End of Outputs for SubSystem: '<S1>/Position' */

    /* Outputs for Atomic SubSystem: '<S5>/CurPhaseUCnvt' */
    SID_F_CurPhaseUCnvt();

    /* End of Outputs for SubSystem: '<S5>/CurPhaseUCnvt' */

    /* Outputs for Atomic SubSystem: '<S5>/CurPhaseVCnvt' */
    SID_F_CurPhaseVCnvt();

    /* End of Outputs for SubSystem: '<S5>/CurPhaseVCnvt' */

    /* Outputs for Atomic SubSystem: '<S5>/CurPhaseWCnvt' */
    SID_F_CurPhaseWCnvt();

    /* End of Outputs for SubSystem: '<S5>/CurPhaseWCnvt' */

    /* Outputs for Atomic SubSystem: '<S2>/CurPhaseSRC' */
    //SID_F_CurPhaseSRC();

    /* End of Outputs for SubSystem: '<S2>/CurPhaseSRC' */

    /* Outputs for Atomic SubSystem: '<S1>/CurRef' */
    //SID_F_CurRef();

    /* End of Outputs for SubSystem: '<S1>/CurRef' */
}

/* Model initialize function */
void SID_F_initialize(void)
{
    /* (no initialization code required) */
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
