/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: Eureka_Lib.c
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
 *   Include files
 ******************************************************************************/
#include "Eureka_Lib.h"

/* Include model header file for global data */
#include "SID.h"
#include "SID_private.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/

/* Named constants for Chart: '<S35>/SRC_Check' */
#define MACRO_IN_Defect                ((UInt8)1U)
#define MACRO_IN_NO_ACTIVE_CHILD       ((UInt8)0U)
#define MACRO_IN_NO_Defect             ((UInt8)2U)
#define MACRO_IN_SRC_High_Confimed     ((UInt8)1U)
#define MACRO_IN_SRC_High_Debouncing   ((UInt8)2U)
#define MACRO_IN_SRC_High_Healing      ((UInt8)3U)
#define MACRO_IN_SRC_Low_Confimed      ((UInt8)4U)
#define MACRO_IN_SRC_Low_Debouncing    ((UInt8)5U)
#define MACRO_IN_SRC_Low_Healing       ((UInt8)6U)

/* Named constants for Chart: '<S105>/Switch_Debouncing' */
#define MACRO_IN_Switch_OFF            ((UInt8)1U)
#define MACRO_IN_Switch_OFF_Debouncing ((UInt8)2U)
#define MACRO_IN_Switch_ON             ((UInt8)3U)
#define MACRO_IN_Switch_ON_Debouncing  ((UInt8)4U)

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

/*
 * Initial conditions for atomic system:
 *    '<S31>/SRC_Check'
 *    '<S43>/SRC_Check'
 *    '<S55>/SRC_Check'
 *    '<S67>/SRC_Check'
 *    '<S79>/SRC_Check'
 *    '<S91>/SRC_Check'
 */
void SID_SRC_Check_Init(UInt8 *rty_SRC_Def_Status, Boolean
                        *rty_SRC_Tmp_Def_Flag)
{
    /* InitializeConditions for Chart: '<S35>/SRC_Check' */
    *rty_SRC_Def_Status = 0U;
    *rty_SRC_Tmp_Def_Flag = false;
}

/*
 * Output and update for atomic system:
 *    '<S31>/SRC_Check'
 *    '<S43>/SRC_Check'
 *    '<S55>/SRC_Check'
 *    '<S67>/SRC_Check'
 *    '<S79>/SRC_Check'
 *    '<S91>/SRC_Check'
 */
void SID_SRC_Check(UInt8 rtu_Clear_Def_Flag, t_Voltage4 rtu_Sig_Volt,
                   t_Voltage4 rtu_Par_SRC_H_Threshold, t_Voltage4
                   rtu_Par_SRC_L_Threshold, t_Timer1 rtu_Par_SRC_H_PosDeb,
                   t_Timer1 rtu_Par_SRC_H_NegDeb, t_Timer1 rtu_Par_SRC_L_PosDeb,
                   t_Timer1 rtu_Par_SRC_L_NegDeb, t_Timer1 rtu_Par_SampleTime,
                   UInt8 *rty_SRC_Def_Status, Boolean *rty_SRC_Tmp_Def_Flag,
                   t_SID_rtDW_SRC_Check *localDW)
{
    /* Chart: '<S35>/SRC_Check' */
    /* Gateway: SRC_Check/SRC_Check */
    /* During: SRC_Check/SRC_Check */
    if (localDW->bitsForTID0.is_active_c3_Ref_Lib == 0U)
    {
        /* Entry: SRC_Check/SRC_Check */
        localDW->bitsForTID0.is_active_c3_Ref_Lib = 1U;

        /* Entry Internal: SRC_Check/SRC_Check */
        /* Transition: '<S36>:1' */
        localDW->bitsForTID0.is_c3_Ref_Lib = MACRO_IN_NO_Defect;

        /* Entry 'NO_Defect': '<S36>:4' */
        *rty_SRC_Def_Status = SRC_NON_DEF;
    }
    else if (localDW->bitsForTID0.is_c3_Ref_Lib == MACRO_IN_Defect)
    {
        /* During 'Defect': '<S36>:45' */
        if (rtu_Clear_Def_Flag != 0)
        {
            /* Transition: '<S36>:46' */
            /* Exit Internal 'Defect': '<S36>:45' */
            switch (localDW->bitsForTID0.is_Defect)
            {
              case MACRO_IN_SRC_High_Debouncing:
                /* Exit 'SRC_High_Debouncing': '<S36>:14' */
                *rty_SRC_Tmp_Def_Flag = false;
                localDW->bitsForTID0.is_Defect = MACRO_IN_NO_ACTIVE_CHILD;
                break;

              case MACRO_IN_SRC_Low_Debouncing:
                /* Exit 'SRC_Low_Debouncing': '<S36>:7' */
                *rty_SRC_Tmp_Def_Flag = false;
                localDW->bitsForTID0.is_Defect = MACRO_IN_NO_ACTIVE_CHILD;
                break;

              default:
                localDW->bitsForTID0.is_Defect = MACRO_IN_NO_ACTIVE_CHILD;
                break;
            }

            localDW->bitsForTID0.is_c3_Ref_Lib = MACRO_IN_NO_Defect;

            /* Entry 'NO_Defect': '<S36>:4' */
            *rty_SRC_Def_Status = SRC_NON_DEF;
        }
        else
        {
            switch (localDW->bitsForTID0.is_Defect)
            {
              case MACRO_IN_SRC_High_Confimed:
                /* During 'SRC_High_Confimed': '<S36>:16' */
                if (rtu_Sig_Volt <= rtu_Par_SRC_H_Threshold)
                {
                    /* Transition: '<S36>:21' */
                    localDW->bitsForTID0.is_Defect = MACRO_IN_SRC_High_Healing;

                    /* Entry 'SRC_High_Healing': '<S36>:18' */
                    localDW->local_Timer = rtu_Par_SampleTime;
                }
                break;

              case MACRO_IN_SRC_High_Debouncing:
                /* During 'SRC_High_Debouncing': '<S36>:14' */
                if (rtu_Sig_Volt <= rtu_Par_SRC_H_Threshold)
                {
                    /* Transition: '<S36>:10' */
                    /* Exit 'SRC_High_Debouncing': '<S36>:14' */
                    *rty_SRC_Tmp_Def_Flag = false;
                    localDW->bitsForTID0.is_Defect = MACRO_IN_NO_ACTIVE_CHILD;
                    localDW->bitsForTID0.is_c3_Ref_Lib = MACRO_IN_NO_Defect;

                    /* Entry 'NO_Defect': '<S36>:4' */
                    *rty_SRC_Def_Status = SRC_NON_DEF;
                }
                else if (localDW->local_Timer > rtu_Par_SRC_H_PosDeb)
                {
                    /* Transition: '<S36>:17' */
                    /* Exit 'SRC_High_Debouncing': '<S36>:14' */
                    *rty_SRC_Tmp_Def_Flag = false;
                    localDW->bitsForTID0.is_Defect = MACRO_IN_SRC_High_Confimed;

                    /* Entry 'SRC_High_Confimed': '<S36>:16' */
                    *rty_SRC_Def_Status = SRC_HIGH_DEF;
                }
                else
                {
                    localDW->local_Timer += rtu_Par_SampleTime;
                }
                break;

              case MACRO_IN_SRC_High_Healing:
                /* During 'SRC_High_Healing': '<S36>:18' */
                if (localDW->local_Timer > rtu_Par_SRC_H_NegDeb)
                {
                    /* Transition: '<S36>:20' */
                    localDW->bitsForTID0.is_Defect = MACRO_IN_NO_ACTIVE_CHILD;
                    localDW->bitsForTID0.is_c3_Ref_Lib = MACRO_IN_NO_Defect;

                    /* Entry 'NO_Defect': '<S36>:4' */
                    *rty_SRC_Def_Status = SRC_NON_DEF;
                }
                else if (rtu_Sig_Volt > rtu_Par_SRC_H_Threshold)
                {
                    /* Transition: '<S36>:27' */
                    localDW->bitsForTID0.is_Defect = MACRO_IN_SRC_High_Confimed;

                    /* Entry 'SRC_High_Confimed': '<S36>:16' */
                    *rty_SRC_Def_Status = SRC_HIGH_DEF;
                }
                else
                {
                    localDW->local_Timer += rtu_Par_SampleTime;
                }
                break;

              case MACRO_IN_SRC_Low_Confimed:
                /* During 'SRC_Low_Confimed': '<S36>:25' */
                if (rtu_Sig_Volt >= rtu_Par_SRC_L_Threshold)
                {
                    /* Transition: '<S36>:29' */
                    localDW->bitsForTID0.is_Defect = MACRO_IN_SRC_Low_Healing;

                    /* Entry 'SRC_Low_Healing': '<S36>:28' */
                    localDW->local_Timer = rtu_Par_SampleTime;
                }
                break;

              case MACRO_IN_SRC_Low_Debouncing:
                /* During 'SRC_Low_Debouncing': '<S36>:7' */
                if (rtu_Sig_Volt >= rtu_Par_SRC_L_Threshold)
                {
                    /* Transition: '<S36>:32' */
                    /* Exit 'SRC_Low_Debouncing': '<S36>:7' */
                    *rty_SRC_Tmp_Def_Flag = false;
                    localDW->bitsForTID0.is_Defect = MACRO_IN_NO_ACTIVE_CHILD;
                    localDW->bitsForTID0.is_c3_Ref_Lib = MACRO_IN_NO_Defect;

                    /* Entry 'NO_Defect': '<S36>:4' */
                    *rty_SRC_Def_Status = SRC_NON_DEF;
                }
                else if (localDW->local_Timer > rtu_Par_SRC_L_PosDeb)
                {
                    /* Transition: '<S36>:26' */
                    /* Exit 'SRC_Low_Debouncing': '<S36>:7' */
                    *rty_SRC_Tmp_Def_Flag = false;
                    localDW->bitsForTID0.is_Defect = MACRO_IN_SRC_Low_Confimed;

                    /* Entry 'SRC_Low_Confimed': '<S36>:25' */
                    *rty_SRC_Def_Status = SRC_LOW_DEF;
                }
                else
                {
                    localDW->local_Timer += rtu_Par_SampleTime;
                }
                break;

              default:
                /* During 'SRC_Low_Healing': '<S36>:28' */
                if (localDW->local_Timer > rtu_Par_SRC_L_NegDeb)
                {
                    /* Transition: '<S36>:31' */
                    localDW->bitsForTID0.is_Defect = MACRO_IN_NO_ACTIVE_CHILD;
                    localDW->bitsForTID0.is_c3_Ref_Lib = MACRO_IN_NO_Defect;

                    /* Entry 'NO_Defect': '<S36>:4' */
                    *rty_SRC_Def_Status = SRC_NON_DEF;
                }
                else if (rtu_Sig_Volt < rtu_Par_SRC_L_Threshold)
                {
                    /* Transition: '<S36>:30' */
                    localDW->bitsForTID0.is_Defect = MACRO_IN_SRC_Low_Confimed;

                    /* Entry 'SRC_Low_Confimed': '<S36>:25' */
                    *rty_SRC_Def_Status = SRC_LOW_DEF;
                }
                else
                {
                    localDW->local_Timer += rtu_Par_SampleTime;
                }
                break;
            }
        }
    }
    else
    {
        /* During 'NO_Defect': '<S36>:4' */
        if ((rtu_Sig_Volt > rtu_Par_SRC_H_Threshold) && (!(rtu_Clear_Def_Flag !=
              0)))
        {
            /* Transition: '<S36>:8' */
            localDW->bitsForTID0.is_c3_Ref_Lib = MACRO_IN_Defect;
            localDW->bitsForTID0.is_Defect = MACRO_IN_SRC_High_Debouncing;

            /* Entry 'SRC_High_Debouncing': '<S36>:14' */
            localDW->local_Timer = rtu_Par_SampleTime;
            *rty_SRC_Tmp_Def_Flag = true;
        }
        else
        {
            if ((rtu_Sig_Volt < rtu_Par_SRC_L_Threshold) &&
                    (!(rtu_Clear_Def_Flag != 0)))
            {
                /* Transition: '<S36>:9' */
                localDW->bitsForTID0.is_c3_Ref_Lib = MACRO_IN_Defect;
                localDW->bitsForTID0.is_Defect = MACRO_IN_SRC_Low_Debouncing;

                /* Entry 'SRC_Low_Debouncing': '<S36>:7' */
                localDW->local_Timer = rtu_Par_SampleTime;
                *rty_SRC_Tmp_Def_Flag = true;
            }
        }
    }

    /* End of Chart: '<S35>/SRC_Check' */
}

/*
 * Initial conditions for atomic system:
 *    '<S99>/Swtich_Debouncing'
 *    '<S100>/Swtich_Debouncing'
 *    '<S101>/Swtich_Debouncing'
 *    '<S102>/Swtich_Debouncing'
 *    '<S103>/Swtich_Debouncing'
 *    '<S104>/Swtich_Debouncing'
 */
void SID_Swtich_Debouncing_Init(Boolean *rty_swtDeb)
{
    /* InitializeConditions for Chart: '<S105>/Switch_Debouncing' */
    *rty_swtDeb = false;
}

/*
 * Output and update for atomic system:
 *    '<S99>/Swtich_Debouncing'
 *    '<S100>/Swtich_Debouncing'
 *    '<S101>/Swtich_Debouncing'
 *    '<S102>/Swtich_Debouncing'
 *    '<S103>/Swtich_Debouncing'
 *    '<S104>/Swtich_Debouncing'
 */
void SID_Swtich_Debouncing(UInt8 rtu_swtRaw, t_Timer1 rtu_Par_SwtOffDebTime,
    t_Timer1 rtu_Par_SwtOnDebTime, t_Timer1 rtu_Par_SampleTime, Boolean
    *rty_swtDeb, t_SID_rtDW_Swtich_Debouncing *localDW)
{
    /* Chart: '<S105>/Switch_Debouncing' */
    /* Gateway: Swtich_Debouncing/Switch_Debouncing */
    /* During: Swtich_Debouncing/Switch_Debouncing */
    if (localDW->bitsForTID0.is_active_c5_Ref_Lib == 0U)
    {
        /* Entry: Swtich_Debouncing/Switch_Debouncing */
        localDW->bitsForTID0.is_active_c5_Ref_Lib = 1U;

        /* Entry Internal: Swtich_Debouncing/Switch_Debouncing */
        /* Transition: '<S106>:2' */
        localDW->bitsForTID0.is_c5_Ref_Lib = MACRO_IN_Switch_OFF;

        /* Entry 'Switch_OFF': '<S106>:1' */
        *rty_swtDeb = SWT_OFF;
    }
    else
    {
        switch (localDW->bitsForTID0.is_c5_Ref_Lib)
        {
          case MACRO_IN_Switch_OFF:
            /* During 'Switch_OFF': '<S106>:1' */
            if (rtu_swtRaw == SWT_ON)
            {
                /* Transition: '<S106>:12' */
                localDW->bitsForTID0.is_c5_Ref_Lib =
                    MACRO_IN_Switch_ON_Debouncing;

                /* Entry 'Switch_ON_Debouncing': '<S106>:3' */
                localDW->localTimer = rtu_Par_SampleTime;
            }
            break;

          case MACRO_IN_Switch_OFF_Debouncing:
            /* During 'Switch_OFF_Debouncing': '<S106>:5' */
            if (localDW->localTimer > rtu_Par_SwtOffDebTime)
            {
                /* Transition: '<S106>:21' */
                localDW->bitsForTID0.is_c5_Ref_Lib = MACRO_IN_Switch_OFF;

                /* Entry 'Switch_OFF': '<S106>:1' */
                *rty_swtDeb = SWT_OFF;
            }
            else if (rtu_swtRaw == SWT_ON)
            {
                /* Transition: '<S106>:20' */
                localDW->bitsForTID0.is_c5_Ref_Lib = MACRO_IN_Switch_ON;

                /* Entry 'Switch_ON': '<S106>:4' */
                *rty_swtDeb = SWT_ON;
            }
            else
            {
                localDW->localTimer += rtu_Par_SampleTime;
            }
            break;

          case MACRO_IN_Switch_ON:
            /* During 'Switch_ON': '<S106>:4' */
            if (rtu_swtRaw == SWT_OFF)
            {
                /* Transition: '<S106>:19' */
                localDW->bitsForTID0.is_c5_Ref_Lib =
                    MACRO_IN_Switch_OFF_Debouncing;

                /* Entry 'Switch_OFF_Debouncing': '<S106>:5' */
                localDW->localTimer = rtu_Par_SampleTime;
            }
            break;

          default:
            /* During 'Switch_ON_Debouncing': '<S106>:3' */
            if (localDW->localTimer > rtu_Par_SwtOnDebTime)
            {
                /* Transition: '<S106>:16' */
                localDW->bitsForTID0.is_c5_Ref_Lib = MACRO_IN_Switch_ON;

                /* Entry 'Switch_ON': '<S106>:4' */
                *rty_swtDeb = SWT_ON;
            }
            else if (rtu_swtRaw == SWT_OFF)
            {
                /* Transition: '<S106>:15' */
                localDW->bitsForTID0.is_c5_Ref_Lib = MACRO_IN_Switch_OFF;

                /* Entry 'Switch_OFF': '<S106>:1' */
                *rty_swtDeb = SWT_OFF;
            }
            else
            {
                localDW->localTimer += rtu_Par_SampleTime;
            }
            break;
        }
    }

    /* End of Chart: '<S105>/Switch_Debouncing' */
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
