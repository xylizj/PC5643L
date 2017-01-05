/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: SID.c
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
#include "SID.h"
#include "SID_private.h"
#include "VFB.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/

/* Named constants for Chart: '<S28>/SignalGradientLimit' */
#define MACRO_IN_Init                  ((UInt8)1U)
#define MACRO_IN_Process               ((UInt8)2U)

/* Named constants for Chart: '<S40>/SignalGradientLimit' */
#define MACRO_IN_Init_d                ((UInt8)1U)
#define MACRO_IN_Process_n             ((UInt8)2U)

/* Named constants for Chart: '<S52>/SignalGradientLimit' */
#define MACRO_IN_Init_c                ((UInt8)1U)
#define MACRO_IN_Process_p             ((UInt8)2U)

/* Named constants for Chart: '<S64>/SignalGradientLimit' */
#define MACRO_IN_Init_b                ((UInt8)1U)
#define MACRO_IN_Process_h             ((UInt8)2U)

/* Named constants for Chart: '<S76>/SignalGradientLimit' */
#define MACRO_IN_Init_g                ((UInt8)1U)
#define MACRO_IN_Process_e             ((UInt8)2U)

/* Named constants for Chart: '<S88>/SignalGradientLimit' */
#define MACRO_IN_Init_m                ((UInt8)1U)
#define MACRO_IN_Process_d             ((UInt8)2U)

/*****************************************************************************
 *   Data Types
 *****************************************************************************/

/*****************************************************************************
 *   Definitions
 *****************************************************************************/

/* External inputs (root inport signals with auto storage) */
t_SID_ExternalInputs g_SID_U;

/*****************************************************************************
 *    Declarations
 *****************************************************************************/

/* Declare variables for internal data of system '<S2>/TempExc' */
t_SID_rtB_TempExc g_SID_TempExc_B;
t_SID_rtDW_TempExc g_SID_TempExc_DW;

/* Declare variables for internal data of system '<S2>/TempPU' */
t_SID_rtB_TempPU g_SID_TempPU_B;
t_SID_rtDW_TempPU g_SID_TempPU_DW;

/* Declare variables for internal data of system '<S2>/TempPV' */
t_SID_rtB_TempPV g_SID_TempPV_B;
t_SID_rtDW_TempPV g_SID_TempPV_DW;

/* Declare variables for internal data of system '<S2>/TempPW' */
t_SID_rtB_TempPW g_SID_TempPW_B;
t_SID_rtDW_TempPW g_SID_TempPW_DW;

/* Declare variables for internal data of system '<S2>/TempShell' */
t_SID_rtB_TempShell g_SID_TempShell_B;
t_SID_rtDW_TempShell g_SID_TempShell_DW;

/* Declare variables for internal data of system '<S2>/TempStator' */
t_SID_rtB_TempStator g_SID_TempStator_B;
t_SID_rtDW_TempStator g_SID_TempStator_DW;

/* Declare variables for internal data of system '<S2>/Velocity' */
t_SID_rtDW_Velocity g_SID_Velocity_DW;

/* Declare variables for internal data of system '<S3>/EN_SWT_DEB' */
t_SID_rtB_EN_SWT_DEB g_SID_EN_SWT_DEB_B;
t_SID_rtDW_EN_SWT_DEB g_SID_EN_SWT_DEB_DW;

/* Declare variables for internal data of system '<S3>/ExcDrvFault_SWT_DEB' */
t_SID_rtB_ExcDrvFault_SWT_DEB g_SID_ExcDrvFault_SWT_DEB_B;
t_SID_rtDW_ExcDrvFault_SWT_DEB g_SID_ExcDrvFault_SWT_DEB_DW;

/* Declare variables for internal data of system '<S3>/IGN_SWT_DEB' */
t_SID_rtB_IGN_SWT_DEB g_SID_IGN_SWT_DEB_B;
t_SID_rtDW_IGN_SWT_DEB g_SID_IGN_SWT_DEB_DW;

/* Declare variables for internal data of system '<S3>/PhaDrvFault_SWT_DEB' */
t_SID_rtB_PhaDrvFault_SWT_DEB g_SID_PhaDrvFault_SWT_DEB_B;
t_SID_rtDW_PhaDrvFault_SWT_DEB g_SID_PhaDrvFault_SWT_DEB_DW;

/* Declare variables for internal data of system '<S3>/ReslvDOS_SWT_DEB' */
t_SID_rtB_ReslvDOS_SWT_DEB g_SID_ReslvDOS_SWT_DEB_B;
t_SID_rtDW_ReslvDOS_SWT_DEB g_SID_ReslvDOS_SWT_DEB_DW;

/* Declare variables for internal data of system '<S3>/RslvLOT_SWT_DEB' */
t_SID_rtB_RslvLOT_SWT_DEB g_SID_RslvLOT_SWT_DEB_B;
t_SID_rtDW_RslvLOT_SWT_DEB g_SID_RslvLOT_SWT_DEB_DW;

/******************************************************************************
 *   FILE SCOPE DATA
 ******************************************************************************/

/*****************************************************************************
 *   FUNCTIONS
 *****************************************************************************/

/* Output and update for atomic system: '<S2>/CurExc' */
void SID_CurExc(void)
{
    /* Gain: '<S15>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_CurExcRaw'
     */
    SID_m_i_CurExc = (SInt16)((SInt16)SID_m_ct_CurExcRaw << 2);
}

/* Output and update for atomic system: '<S2>/PwrSply_V10' */
void SID_PwrSply_V10(void)
{
    /* Gain: '<S16>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_V10Raw'
     */
    SID_m_u_V10 = (SInt16)(9075U * SID_m_ct_V10Raw >> 10);
}

/* Output and update for atomic system: '<S2>/PwrSply_V12' */
void SID_PwrSply_V12(void)
{
    /* Gain: '<S17>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_V12Raw'
     */
    SID_m_u_V12 = (SInt16)(9075U * SID_m_ct_V12Raw >> 10);
}

/* Output and update for atomic system: '<S2>/PwrSply_V48' */
void SID_PwrSply_V48(void)
{
    /* Gain: '<S18>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_V48Raw'
     */
    SID_m_u_V48 = (SInt32)(4*(34650U/5) * SID_m_ct_V48Raw ) << 1;
}

/* Output and update for atomic system: '<S2>/PwrSply_V5' */
void SID_PwrSply_V5(void)
{
    /* Gain: '<S19>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_V5Raw'
     */
    SID_m_u_V5 = (SInt16)(9075U * SID_m_ct_V5Raw >> 10);
}

/* Initial conditions for atomic system: '<S2>/TempExc' */
void SID_TempExc_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S31>/SRC_Check' */
    SID_SRC_Check_Init(&g_SID_TempExc_B.SRC_Def_Status,
                       &g_SID_TempExc_B.SRC_Tmp_Def_Flag);

    /* End of InitializeConditions for SubSystem: '<S31>/SRC_Check' */
}

/* Output and update for atomic system: '<S2>/TempExc' */
void SID_TempExc(void)
{
    /* local block i/o variables */
    UInt8 lbo_DataTypeConversion1;
    Boolean lbo_Switch_ky;
    t_Temp3 lbo_Switch5;
    t_Temp3 lbo_Switch_c3;
    t_Timer2 lbo_Divide;
    SInt32 lbo_Switch2;
    t_Pressure4 lbo_DifferenceInputs1;

    /* Gain: '<S29>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_TempExcRaw'
     */
    SID_m_u_TempExc = (SInt16)(825U * SID_m_ct_TempExcRaw >> 10);

    /* Lookup: '<S31>/SID_CUR_t_TempPU'
     * About '<S31>/SID_CUR_t_TempPU':
     * Input0  Data Type:  Integer        S16
     * Output0 Data Type:  Fixed Point    S16  2^-4  FSlope 1.6
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_S16_S16_SAT( &(SID_m_t_TempExcLinear), (&(SID_CUR_t_TempExc[0])),
                       SID_m_u_TempExc, (&(SID_CURX_u_TempExc[0])), 22U);

    /* Outputs for Atomic SubSystem: '<S31>/SRC_Check' */

    /* Constant: '<S31>/clear5' incorporates:
     *  Constant: '<S31>/SID_C_ti_DPSSRCHighNegDeb'
     *  Constant: '<S31>/SID_C_ti_DPSSRCHighPosDeb'
     *  Constant: '<S31>/SID_C_ti_DPSSRCLowNegDeb'
     *  Constant: '<S31>/SID_C_ti_DPSSRCLowPosDeb'
     *  Constant: '<S31>/SID_C_u_DPSSRCHigh '
     *  Constant: '<S31>/SID_C_u_DPSSRCLow'
     *  Constant: '<S31>/ST_DPS_PROCESS'
     */
    SID_SRC_Check(0U, SID_m_u_TempExc, SID_C_u_TempExcSRCHigh,
                  SID_C_u_TempExcSRCLow, SID_C_ti_TempExcSRCHighPosDeb,
                  SID_C_ti_TempExcSRCHighNegDeb, SID_C_ti_TempExcSRCLowPosDeb,
                  SID_C_ti_TempExcSRCLowNegDeb, ST_TEMPEXC_PROCESS,
                  &g_SID_TempExc_B.SRC_Def_Status,
                  &g_SID_TempExc_B.SRC_Tmp_Def_Flag, &g_SID_TempExc_DW.SRC_Check);

    /* End of Outputs for SubSystem: '<S31>/SRC_Check' */

    /* SignalConversion: '<S31>/TmpSignal ConversionAtSRC_CheckOutport1' */
    SID_m_st_TempExcSRC = g_SID_TempExc_B.SRC_Def_Status;

    /* Outputs for Enabled SubSystem: '<S30>/Check_Level' incorporates:
     *  EnablePort: '<S32>/Enable'
     */
    /* Logic: '<S30>/Logical Operator2' */
    if (!(SID_m_st_TempExcSRC != 0))
    {
        if (!g_SID_TempExc_DW.Check_Level_MODE)
        {
            g_SID_TempExc_DW.Check_Level_MODE = true;
        }

        /* Switch: '<S34>/Switch' incorporates:
         *  Constant: '<S27>/Constant1'
         *  Constant: '<S27>/Constant10'
         *  Constant: '<S34>/Constant'
         *  RelationalOperator: '<S34>/Relational Operator'
         *  RelationalOperator: '<S34>/Relational Operator1'
         *  Sum: '<S32>/Add3'
         *  Switch: '<S34>/Switch1'
         *  UnitDelay: '<S34>/Unit Delay'
         *
         * Block description for '<S27>/Constant1':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S27>/Constant10':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempExcLinear >= (SInt16)(SID_C_t_TempExcLowOffset +
                SID_C_t_TempExcPLow))
        {
            lbo_Switch_ky = true;
        }
        else if (SID_m_t_TempExcLinear <= SID_C_t_TempExcPLow)
        {
            /* Switch: '<S34>/Switch1' incorporates:
             *  Constant: '<S34>/Constant1'
             */
            lbo_Switch_ky = false;
        }
        else
        {
            lbo_Switch_ky = g_SID_TempExc_DW.UnitDelay_DSTATE;
        }

        /* End of Switch: '<S34>/Switch' */

        /* Logic: '<S32>/Logical Operator2' */
        SID_m_st_TempExcLow = !lbo_Switch_ky;

        /* Switch: '<S33>/Switch' incorporates:
         *  Constant: '<S27>/Constant2'
         *  Constant: '<S27>/Constant8'
         *  Constant: '<S33>/Constant'
         *  RelationalOperator: '<S33>/Relational Operator'
         *  RelationalOperator: '<S33>/Relational Operator1'
         *  Sum: '<S32>/Add1'
         *  Switch: '<S33>/Switch1'
         *
         * Block description for '<S27>/Constant2':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S27>/Constant8':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempExcLinear >= SID_C_t_TempExcHigh)
        {
            SID_m_st_TempExcHigh = true;
        }
        else if (SID_m_t_TempExcLinear <= (SInt16)(SID_C_t_TempExcHigh -
                  SID_C_t_TempExcHighOffset))
        {
            /* Switch: '<S33>/Switch1' incorporates:
             *  Constant: '<S33>/Constant1'
             */
            SID_m_st_TempExcHigh = false;
        }
        else
        {
            /* Switch: '<S33>/Switch1' incorporates:
             *  UnitDelay: '<S33>/Unit Delay'
             */
            SID_m_st_TempExcHigh = g_SID_TempExc_DW.UnitDelay_DSTATE_a;
        }

        /* End of Switch: '<S33>/Switch' */

        /* Update for UnitDelay: '<S34>/Unit Delay' */
        g_SID_TempExc_DW.UnitDelay_DSTATE = lbo_Switch_ky;

        /* Update for UnitDelay: '<S33>/Unit Delay' */
        g_SID_TempExc_DW.UnitDelay_DSTATE_a = SID_m_st_TempExcHigh;
    }
    else
    {
        if (g_SID_TempExc_DW.Check_Level_MODE)
        {
            /* Disable for Outport: '<S32>/SigHigh_st' */
            SID_m_st_TempExcHigh = false;

            /* Disable for Outport: '<S32>/SigLow_st' */
            SID_m_st_TempExcLow = false;
            g_SID_TempExc_DW.Check_Level_MODE = false;
        }
    }

    /* End of Logic: '<S30>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S30>/Check_Level' */

    /* DataTypeConversion: '<S30>/Data Type Conversion2' */
    lbo_DataTypeConversion1 = (UInt8)SID_m_st_TempExcHigh;

    /*
     * Block description for '<S27>/Constant3':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S30>/sfun_SetErr_SigHigh' incorporates:
     *  Constant: '<S27>/Constant3'
     *
     * Block description for '<S27>/Constant3':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPEXC_HIGH_ID, lbo_DataTypeConversion1);

    /* DataTypeConversion: '<S30>/Data Type Conversion3' */
    lbo_DataTypeConversion1 = (UInt8)SID_m_st_TempExcLow;

    /*
     * Block description for '<S27>/Constant6':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S30>/sfun_SetErr_SigLow' incorporates:
     *  Constant: '<S27>/Constant6'
     *
     * Block description for '<S27>/Constant6':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPEXC_LOW_ID, lbo_DataTypeConversion1);

    /* DataTypeConversion: '<S30>/Data Type Conversion' incorporates:
     *  Constant: '<S30>/Constant1'
     *  RelationalOperator: '<S30>/Relational Operator'
     *
     * Block description for '<S30>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1 = (UInt8)(SID_m_st_TempExcSRC == SRC_HIGH_DEF);

    /*
     * Block description for '<S27>/Constant9':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S30>/sfun_SetErr_SrcH' incorporates:
     *  Constant: '<S27>/Constant9'
     *
     * Block description for '<S27>/Constant9':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPEXC_SRCH_ID, lbo_DataTypeConversion1);

    /* DataTypeConversion: '<S30>/Data Type Conversion1' incorporates:
     *  Constant: '<S30>/Constant2'
     *  RelationalOperator: '<S30>/Relational Operator1'
     *
     * Block description for '<S30>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1 = (UInt8)(SID_m_st_TempExcSRC == SRC_LOW_DEF);

    /*
     * Block description for '<S27>/Constant5':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S30>/sfun_SetErr_SrcL' incorporates:
     *  Constant: '<S27>/Constant5'
     *
     * Block description for '<S27>/Constant5':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPEXC_SRCL_ID, lbo_DataTypeConversion1);

    /* SignalConversion: '<S31>/TmpSignal ConversionAtSRC_CheckOutport2' */
    SID_m_st_TempExcTmpSRC = g_SID_TempExc_B.SRC_Tmp_Def_Flag;

    /* Switch: '<S28>/Switch5' incorporates:
     *  UnitDelay: '<S28>/Unit Delay1'
     */
    if (SID_m_st_TempExcTmpSRC)
    {
        lbo_Switch5 = g_SID_TempExc_DW.UnitDelay1_DSTATE;
    }
    else
    {
        lbo_Switch5 = SID_m_t_TempExcLinear;
    }

    /* End of Switch: '<S28>/Switch5' */

    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S28>/Constant8'
     *
     * Block description for '<S28>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (SID_m_st_TempExcSRC != 0)
    {
        lbo_Switch_c3 = SID_C_t_TempExcRplcVal;
    }
    else
    {
        lbo_Switch_c3 = lbo_Switch5;
    }

    /* End of Switch: '<S28>/Switch' */

    /* Chart: '<S28>/SignalGradientLimit' incorporates:
     *  Sum: '<S38>/Difference Inputs2'
     */
    /* Gateway: SENSOR_SIGNAL/TempExc/Signal_Evaluation/SignalGradientLimit */
    /* During: SENSOR_SIGNAL/TempExc/Signal_Evaluation/SignalGradientLimit */
    if (g_SID_TempExc_DW.bitsForTID0.is_active_c9_SID == 0U)
    {
        /* Entry: SENSOR_SIGNAL/TempExc/Signal_Evaluation/SignalGradientLimit */
        g_SID_TempExc_DW.bitsForTID0.is_active_c9_SID = 1U;

        /* Entry Internal: SENSOR_SIGNAL/TempExc/Signal_Evaluation/SignalGradientLimit */
        /* Transition: '<S37>:17' */
        g_SID_TempExc_DW.bitsForTID0.is_c9_SID = MACRO_IN_Init;

        /* Entry 'Init': '<S37>:1' */
        SID_m_t_TempExc = lbo_Switch_c3;
        g_SID_TempExc_DW.Signal_Tmp = lbo_Switch_c3;
    }
    else if (g_SID_TempExc_DW.bitsForTID0.is_c9_SID == MACRO_IN_Init)
    {
        /* During 'Init': '<S37>:1' */
        /* Transition: '<S37>:3' */
        g_SID_TempExc_DW.bitsForTID0.is_c9_SID = MACRO_IN_Process;

        /* Outputs for Function Call SubSystem: '<S37>/GradientLmt' */
        /* Sum: '<S38>/Difference Inputs1' */
        /* Entry 'Process': '<S37>:2' */
        /* Simulink Function 'GradientLmt': '<S37>:7' */
        lbo_DifferenceInputs1 = (SInt16)(lbo_Switch_c3 -
            g_SID_TempExc_DW.Signal_Tmp);

        /* Product: '<S38>/Divide' incorporates:
         *  Constant: '<S38>/Constant13'
         *
         * Block description for '<S38>/Constant13':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        lbo_Divide = (t_Timer2)(((UInt32)ST_TEMPEXC_PROCESS << 6) / 125U *
                                125U >> 6);

        /* Product: '<S38>/delta rise limit' incorporates:
         *  Constant: '<S38>/Constant11'
         *
         * Block description for '<S38>/Constant11':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        lbo_Switch2 = SID_C_t_TempExcRiseRate * lbo_Divide;

        /* Switch: '<S38>/Switch2' incorporates:
         *  RelationalOperator: '<S38>/UpperRelop'
         */
        if (!(lbo_DifferenceInputs1 * 1000 >= lbo_Switch2))
        {
            /* Product: '<S38>/delta fall limit' incorporates:
             *  Constant: '<S38>/Constant12'
             *
             * Block description for '<S38>/Constant12':
             *  For Constants, Enter name in block in all CAPS
             *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
             */
            lbo_Switch2 = SID_C_t_TempExcFallRate * lbo_Divide;

            /* Switch: '<S38>/Switch' incorporates:
             *  RelationalOperator: '<S38>/LowerRelop'
             */
            if (!(lbo_DifferenceInputs1 * 1000 <= lbo_Switch2))
            {
                lbo_Switch2 = lbo_DifferenceInputs1 * 1000;
            }

            /* End of Switch: '<S38>/Switch' */
        }

        /* End of Switch: '<S38>/Switch2' */
        SID_m_t_TempExc = (SInt16)(((g_SID_TempExc_DW.Signal_Tmp << 8) +
            mul_s32_s32_s32_sr30(lbo_Switch2, 274877907)) >> 8);

        /* End of Outputs for SubSystem: '<S37>/GradientLmt' */
        g_SID_TempExc_DW.Signal_Tmp = lbo_Switch_c3;
    }
    else
    {
        /* During 'Process': '<S37>:2' */
    }

    /* End of Chart: '<S28>/SignalGradientLimit' */

    /* Update for UnitDelay: '<S28>/Unit Delay1' */
    g_SID_TempExc_DW.UnitDelay1_DSTATE = lbo_Switch5;
}

/*
 * Output and update for function-call system:
 *    '<S49>/GradientLmt'
 *    '<S61>/GradientLmt'
 *    '<S73>/GradientLmt'
 */
void SID_GradientLmt(t_Pressure4 rtu_Signal_Raw, t_Pressure4 rtu_Signal_Delay,
                     t_Pressure4 *rty_Signal_Out)
{
    t_Timer2 lbo_Divide_d;
    SInt32 lbo_Switch2_f;
    t_Pressure4 lbo_DifferenceInputs1_m;

    /* Sum: '<S50>/Difference Inputs1' */
    lbo_DifferenceInputs1_m = (SInt16)(rtu_Signal_Raw - rtu_Signal_Delay);

    /* Product: '<S50>/Divide' incorporates:
     *  Constant: '<S50>/Constant13'
     *
     * Block description for '<S50>/Constant13':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_Divide_d = (t_Timer2)(((UInt32)ST_TEMPP_PROCESS << 6) / 125U * 125U >>
        6);

    /* Product: '<S50>/delta rise limit' incorporates:
     *  Constant: '<S50>/Constant11'
     *
     * Block description for '<S50>/Constant11':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_Switch2_f = SID_C_t_TempPRiseRate * lbo_Divide_d;

    /* Switch: '<S50>/Switch2' incorporates:
     *  RelationalOperator: '<S50>/UpperRelop'
     */
    if (!(lbo_DifferenceInputs1_m * 1000 >= lbo_Switch2_f))
    {
        /* Product: '<S50>/delta fall limit' incorporates:
         *  Constant: '<S50>/Constant12'
         *
         * Block description for '<S50>/Constant12':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        lbo_Switch2_f = SID_C_t_TempPFallRate * lbo_Divide_d;

        /* Switch: '<S50>/Switch' incorporates:
         *  RelationalOperator: '<S50>/LowerRelop'
         */
        if (!(lbo_DifferenceInputs1_m * 1000 <= lbo_Switch2_f))
        {
            lbo_Switch2_f = lbo_DifferenceInputs1_m * 1000;
        }

        /* End of Switch: '<S50>/Switch' */
    }

    /* End of Switch: '<S50>/Switch2' */

    /* Sum: '<S50>/Difference Inputs2' */
    *rty_Signal_Out = (SInt16)(((rtu_Signal_Delay << 8) + mul_s32_s32_s32_sr30
        (lbo_Switch2_f, 274877907)) >> 8);
}

/* Initial conditions for atomic system: '<S2>/TempPU' */
void SID_TempPU_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S43>/SRC_Check' */
    SID_SRC_Check_Init(&g_SID_TempPU_B.SRC_Def_Status,
                       &g_SID_TempPU_B.SRC_Tmp_Def_Flag);

    /* End of InitializeConditions for SubSystem: '<S43>/SRC_Check' */
}

/* Output and update for atomic system: '<S2>/TempPU' */
void SID_TempPU(void)
{
    /* local block i/o variables */
    UInt8 lbo_DataTypeConversion1_f;
    Boolean lbo_Switch_oa;
    t_Temp3 lbo_Switch5;
    t_Temp3 lbo_Switch_g;

    /* Gain: '<S41>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_TempPURaw'
     */
    SID_m_u_TempPU = (SInt16)(825U * SID_m_ct_TempPURaw >> 10);

    /* Lookup: '<S43>/SID_CUR_t_TempPU'
     * About '<S43>/SID_CUR_t_TempPU':
     * Input0  Data Type:  Integer        S16
     * Output0 Data Type:  Fixed Point    S16  2^-4  FSlope 1.6
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_S16_S16_SAT( &(SID_m_t_TempPULinear), (&(SID_CUR_t_TempP[0])),
                       SID_m_u_TempPU, (&(SID_CURX_u_TempP[0])), 22U);

    /* Outputs for Atomic SubSystem: '<S43>/SRC_Check' */

    /* Constant: '<S43>/clear5' incorporates:
     *  Constant: '<S43>/SID_C_ti_DPSSRCHighNegDeb'
     *  Constant: '<S43>/SID_C_ti_DPSSRCHighPosDeb'
     *  Constant: '<S43>/SID_C_ti_DPSSRCLowNegDeb'
     *  Constant: '<S43>/SID_C_ti_DPSSRCLowPosDeb'
     *  Constant: '<S43>/SID_C_u_DPSSRCHigh '
     *  Constant: '<S43>/SID_C_u_DPSSRCLow'
     *  Constant: '<S43>/ST_DPS_PROCESS'
     */
    SID_SRC_Check(0U, SID_m_u_TempPU, SID_C_u_TempPSRCHigh, SID_C_u_TempPSRCLow,
                  SID_C_ti_TempPSRCHighPosDeb, SID_C_ti_TempPSRCHighNegDeb,
                  SID_C_ti_TempPSRCLowPosDeb, SID_C_ti_TempPSRCLowNegDeb,
                  ST_TEMPP_PROCESS, &g_SID_TempPU_B.SRC_Def_Status,
                  &g_SID_TempPU_B.SRC_Tmp_Def_Flag, &g_SID_TempPU_DW.SRC_Check);

    /* End of Outputs for SubSystem: '<S43>/SRC_Check' */

    /* SignalConversion: '<S43>/TmpSignal ConversionAtSRC_CheckOutport1' */
    SID_m_st_TempPUSRC = g_SID_TempPU_B.SRC_Def_Status;

    /* Outputs for Enabled SubSystem: '<S42>/Check_Level' incorporates:
     *  EnablePort: '<S44>/Enable'
     */
    /* Logic: '<S42>/Logical Operator2' */
    if (!(SID_m_st_TempPUSRC != 0))
    {
        if (!g_SID_TempPU_DW.Check_Level_MODE)
        {
            g_SID_TempPU_DW.Check_Level_MODE = true;
        }

        /* Switch: '<S46>/Switch' incorporates:
         *  Constant: '<S39>/Constant1'
         *  Constant: '<S39>/Constant10'
         *  Constant: '<S46>/Constant'
         *  RelationalOperator: '<S46>/Relational Operator'
         *  RelationalOperator: '<S46>/Relational Operator1'
         *  Sum: '<S44>/Add3'
         *  Switch: '<S46>/Switch1'
         *  UnitDelay: '<S46>/Unit Delay'
         *
         * Block description for '<S39>/Constant1':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S39>/Constant10':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempPULinear >= (SInt16)(SID_C_t_TempPLowOffset +
                SID_C_t_TempPLow))
        {
            lbo_Switch_oa = true;
        }
        else if (SID_m_t_TempPULinear <= SID_C_t_TempPLow)
        {
            /* Switch: '<S46>/Switch1' incorporates:
             *  Constant: '<S46>/Constant1'
             */
            lbo_Switch_oa = false;
        }
        else
        {
            lbo_Switch_oa = g_SID_TempPU_DW.UnitDelay_DSTATE;
        }

        /* End of Switch: '<S46>/Switch' */

        /* Logic: '<S44>/Logical Operator2' */
        SID_m_st_TempPULow = !lbo_Switch_oa;

        /* Switch: '<S45>/Switch' incorporates:
         *  Constant: '<S39>/Constant2'
         *  Constant: '<S39>/Constant8'
         *  Constant: '<S45>/Constant'
         *  RelationalOperator: '<S45>/Relational Operator'
         *  RelationalOperator: '<S45>/Relational Operator1'
         *  Sum: '<S44>/Add1'
         *  Switch: '<S45>/Switch1'
         *
         * Block description for '<S39>/Constant2':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S39>/Constant8':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempPULinear >= SID_C_t_TempPHigh)
        {
            SID_m_st_TempPUHigh = true;
        }
        else if (SID_m_t_TempPULinear <= (SInt16)(SID_C_t_TempPHigh -
                  SID_C_t_TempPHighOffset))
        {
            /* Switch: '<S45>/Switch1' incorporates:
             *  Constant: '<S45>/Constant1'
             */
            SID_m_st_TempPUHigh = false;
        }
        else
        {
            /* Switch: '<S45>/Switch1' incorporates:
             *  UnitDelay: '<S45>/Unit Delay'
             */
            SID_m_st_TempPUHigh = g_SID_TempPU_DW.UnitDelay_DSTATE_m;
        }

        /* End of Switch: '<S45>/Switch' */

        /* Update for UnitDelay: '<S46>/Unit Delay' */
        g_SID_TempPU_DW.UnitDelay_DSTATE = lbo_Switch_oa;

        /* Update for UnitDelay: '<S45>/Unit Delay' */
        g_SID_TempPU_DW.UnitDelay_DSTATE_m = SID_m_st_TempPUHigh;
    }
    else
    {
        if (g_SID_TempPU_DW.Check_Level_MODE)
        {
            /* Disable for Outport: '<S44>/SigHigh_st' */
            SID_m_st_TempPUHigh = false;

            /* Disable for Outport: '<S44>/SigLow_st' */
            SID_m_st_TempPULow = false;
            g_SID_TempPU_DW.Check_Level_MODE = false;
        }
    }

    /* End of Logic: '<S42>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S42>/Check_Level' */

    /* DataTypeConversion: '<S42>/Data Type Conversion2' */
    lbo_DataTypeConversion1_f = (UInt8)SID_m_st_TempPUHigh;

    /*
     * Block description for '<S39>/Constant3':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S42>/sfun_SetErr_SigHigh' incorporates:
     *  Constant: '<S39>/Constant3'
     *
     * Block description for '<S39>/Constant3':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPU_HIGH_ID, lbo_DataTypeConversion1_f);

    /* DataTypeConversion: '<S42>/Data Type Conversion3' */
    lbo_DataTypeConversion1_f = (UInt8)SID_m_st_TempPULow;

    /*
     * Block description for '<S39>/Constant6':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S42>/sfun_SetErr_SigLow' incorporates:
     *  Constant: '<S39>/Constant6'
     *
     * Block description for '<S39>/Constant6':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPU_LOW_ID, lbo_DataTypeConversion1_f);

    /* DataTypeConversion: '<S42>/Data Type Conversion' incorporates:
     *  Constant: '<S42>/Constant1'
     *  RelationalOperator: '<S42>/Relational Operator'
     *
     * Block description for '<S42>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_f = (UInt8)(SID_m_st_TempPUSRC == SRC_HIGH_DEF);

    /*
     * Block description for '<S39>/Constant9':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S42>/sfun_SetErr_SrcH' incorporates:
     *  Constant: '<S39>/Constant9'
     *
     * Block description for '<S39>/Constant9':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPU_SRCH_ID, lbo_DataTypeConversion1_f);

    /* DataTypeConversion: '<S42>/Data Type Conversion1' incorporates:
     *  Constant: '<S42>/Constant2'
     *  RelationalOperator: '<S42>/Relational Operator1'
     *
     * Block description for '<S42>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_f = (UInt8)(SID_m_st_TempPUSRC == SRC_LOW_DEF);

    /*
     * Block description for '<S39>/Constant5':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S42>/sfun_SetErr_SrcL' incorporates:
     *  Constant: '<S39>/Constant5'
     *
     * Block description for '<S39>/Constant5':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPU_SRCL_ID, lbo_DataTypeConversion1_f);

    /* SignalConversion: '<S43>/TmpSignal ConversionAtSRC_CheckOutport2' */
    SID_m_st_TempPUTmpSRC = g_SID_TempPU_B.SRC_Tmp_Def_Flag;

    /* Switch: '<S40>/Switch5' incorporates:
     *  UnitDelay: '<S40>/Unit Delay1'
     */
    if (SID_m_st_TempPUTmpSRC)
    {
        lbo_Switch5 = g_SID_TempPU_DW.UnitDelay1_DSTATE;
    }
    else
    {
        lbo_Switch5 = SID_m_t_TempPULinear;
    }

    /* End of Switch: '<S40>/Switch5' */

    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Constant8'
     *
     * Block description for '<S40>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (SID_m_st_TempPUSRC != 0)
    {
        lbo_Switch_g = SID_C_t_TempPRplcVal;
    }
    else
    {
        lbo_Switch_g = lbo_Switch5;
    }

    /* End of Switch: '<S40>/Switch' */

    /* Chart: '<S40>/SignalGradientLimit' */
    /* Gateway: SENSOR_SIGNAL/TempPU/Signal_Evaluation/SignalGradientLimit */
    /* During: SENSOR_SIGNAL/TempPU/Signal_Evaluation/SignalGradientLimit */
    if (g_SID_TempPU_DW.bitsForTID0.is_active_c4_SID == 0U)
    {
        /* Entry: SENSOR_SIGNAL/TempPU/Signal_Evaluation/SignalGradientLimit */
        g_SID_TempPU_DW.bitsForTID0.is_active_c4_SID = 1U;

        /* Entry Internal: SENSOR_SIGNAL/TempPU/Signal_Evaluation/SignalGradientLimit */
        /* Transition: '<S49>:17' */
        g_SID_TempPU_DW.bitsForTID0.is_c4_SID = MACRO_IN_Init_d;

        /* Entry 'Init': '<S49>:1' */
        SID_m_t_TempPU = lbo_Switch_g;
        g_SID_TempPU_DW.Signal_Tmp = lbo_Switch_g;
    }
    else if (g_SID_TempPU_DW.bitsForTID0.is_c4_SID == MACRO_IN_Init_d)
    {
        /* During 'Init': '<S49>:1' */
        /* Transition: '<S49>:3' */
        g_SID_TempPU_DW.bitsForTID0.is_c4_SID = MACRO_IN_Process_n;

        /* Entry 'Process': '<S49>:2' */
        /* Simulink Function 'GradientLmt': '<S49>:7' */
        g_SID_TempPU_B.Signal_Raw = lbo_Switch_g;
        g_SID_TempPU_B.Signal_Delay = g_SID_TempPU_DW.Signal_Tmp;

        /* Outputs for Function Call SubSystem: '<S49>/GradientLmt' */
        SID_GradientLmt(g_SID_TempPU_B.Signal_Raw, g_SID_TempPU_B.Signal_Delay,
                        &g_SID_TempPU_B.DifferenceInputs2);

        /* End of Outputs for SubSystem: '<S49>/GradientLmt' */
        SID_m_t_TempPU = g_SID_TempPU_B.DifferenceInputs2;
        g_SID_TempPU_DW.Signal_Tmp = lbo_Switch_g;
    }
    else
    {
        /* During 'Process': '<S49>:2' */
    }

    /* End of Chart: '<S40>/SignalGradientLimit' */

    /* Update for UnitDelay: '<S40>/Unit Delay1' */
    g_SID_TempPU_DW.UnitDelay1_DSTATE = lbo_Switch5;
}

/* Initial conditions for atomic system: '<S2>/TempPV' */
void SID_TempPV_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S55>/SRC_Check' */
    SID_SRC_Check_Init(&g_SID_TempPV_B.SRC_Def_Status,
                       &g_SID_TempPV_B.SRC_Tmp_Def_Flag);

    /* End of InitializeConditions for SubSystem: '<S55>/SRC_Check' */
}

/* Output and update for atomic system: '<S2>/TempPV' */
void SID_TempPV(void)
{
    /* local block i/o variables */
    UInt8 lbo_DataTypeConversion1_l;
    Boolean lbo_Switch_f;
    t_Temp3 lbo_Switch5;
    t_Temp3 lbo_Switch_c;

    /* Gain: '<S53>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_TempPVRaw'
     */
    SID_m_u_TempPV = (SInt16)(825U * SID_m_ct_TempPVRaw >> 10);

    /* Lookup: '<S55>/SID_CUR_t_TempPU'
     * About '<S55>/SID_CUR_t_TempPU':
     * Input0  Data Type:  Integer        S16
     * Output0 Data Type:  Fixed Point    S16  2^-4  FSlope 1.6
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_S16_S16_SAT( &(SID_m_t_TempPVLinear), (&(SID_CUR_t_TempP[0])),
                       SID_m_u_TempPV, (&(SID_CURX_u_TempP[0])), 22U);

    /* Outputs for Atomic SubSystem: '<S55>/SRC_Check' */

    /* Constant: '<S55>/clear5' incorporates:
     *  Constant: '<S55>/SID_C_ti_DPSSRCHighNegDeb'
     *  Constant: '<S55>/SID_C_ti_DPSSRCHighPosDeb'
     *  Constant: '<S55>/SID_C_ti_DPSSRCLowNegDeb'
     *  Constant: '<S55>/SID_C_ti_DPSSRCLowPosDeb'
     *  Constant: '<S55>/SID_C_u_DPSSRCHigh '
     *  Constant: '<S55>/SID_C_u_DPSSRCLow'
     *  Constant: '<S55>/ST_DPS_PROCESS'
     */
    SID_SRC_Check(0U, SID_m_u_TempPV, SID_C_u_TempPSRCHigh, SID_C_u_TempPSRCLow,
                  SID_C_ti_TempPSRCHighPosDeb, SID_C_ti_TempPSRCHighNegDeb,
                  SID_C_ti_TempPSRCLowPosDeb, SID_C_ti_TempPSRCLowNegDeb,
                  ST_TEMPP_PROCESS, &g_SID_TempPV_B.SRC_Def_Status,
                  &g_SID_TempPV_B.SRC_Tmp_Def_Flag, &g_SID_TempPV_DW.SRC_Check);

    /* End of Outputs for SubSystem: '<S55>/SRC_Check' */

    /* SignalConversion: '<S55>/TmpSignal ConversionAtSRC_CheckOutport1' */
    SID_m_st_TempPVSRC = g_SID_TempPV_B.SRC_Def_Status;

    /* Outputs for Enabled SubSystem: '<S54>/Check_Level' incorporates:
     *  EnablePort: '<S56>/Enable'
     */
    /* Logic: '<S54>/Logical Operator2' */
    if (!(SID_m_st_TempPVSRC != 0))
    {
        if (!g_SID_TempPV_DW.Check_Level_MODE)
        {
            g_SID_TempPV_DW.Check_Level_MODE = true;
        }

        /* Switch: '<S58>/Switch' incorporates:
         *  Constant: '<S51>/Constant1'
         *  Constant: '<S51>/Constant10'
         *  Constant: '<S58>/Constant'
         *  RelationalOperator: '<S58>/Relational Operator'
         *  RelationalOperator: '<S58>/Relational Operator1'
         *  Sum: '<S56>/Add3'
         *  Switch: '<S58>/Switch1'
         *  UnitDelay: '<S58>/Unit Delay'
         *
         * Block description for '<S51>/Constant1':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S51>/Constant10':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempPVLinear >= (SInt16)(SID_C_t_TempPLowOffset +
                SID_C_t_TempPLow))
        {
            lbo_Switch_f = true;
        }
        else if (SID_m_t_TempPVLinear <= SID_C_t_TempPLow)
        {
            /* Switch: '<S58>/Switch1' incorporates:
             *  Constant: '<S58>/Constant1'
             */
            lbo_Switch_f = false;
        }
        else
        {
            lbo_Switch_f = g_SID_TempPV_DW.UnitDelay_DSTATE;
        }

        /* End of Switch: '<S58>/Switch' */

        /* Logic: '<S56>/Logical Operator2' */
        SID_m_st_TempPVLow = !lbo_Switch_f;

        /* Switch: '<S57>/Switch' incorporates:
         *  Constant: '<S51>/Constant2'
         *  Constant: '<S51>/Constant8'
         *  Constant: '<S57>/Constant'
         *  RelationalOperator: '<S57>/Relational Operator'
         *  RelationalOperator: '<S57>/Relational Operator1'
         *  Sum: '<S56>/Add1'
         *  Switch: '<S57>/Switch1'
         *
         * Block description for '<S51>/Constant2':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S51>/Constant8':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempPVLinear >= SID_C_t_TempPHigh)
        {
            SID_m_st_TempPVHigh = true;
        }
        else if (SID_m_t_TempPVLinear <= (SInt16)(SID_C_t_TempPHigh -
                  SID_C_t_TempPHighOffset))
        {
            /* Switch: '<S57>/Switch1' incorporates:
             *  Constant: '<S57>/Constant1'
             */
            SID_m_st_TempPVHigh = false;
        }
        else
        {
            /* Switch: '<S57>/Switch1' incorporates:
             *  UnitDelay: '<S57>/Unit Delay'
             */
            SID_m_st_TempPVHigh = g_SID_TempPV_DW.UnitDelay_DSTATE_c;
        }

        /* End of Switch: '<S57>/Switch' */

        /* Update for UnitDelay: '<S58>/Unit Delay' */
        g_SID_TempPV_DW.UnitDelay_DSTATE = lbo_Switch_f;

        /* Update for UnitDelay: '<S57>/Unit Delay' */
        g_SID_TempPV_DW.UnitDelay_DSTATE_c = SID_m_st_TempPVHigh;
    }
    else
    {
        if (g_SID_TempPV_DW.Check_Level_MODE)
        {
            /* Disable for Outport: '<S56>/SigHigh_st' */
            SID_m_st_TempPVHigh = false;

            /* Disable for Outport: '<S56>/SigLow_st' */
            SID_m_st_TempPVLow = false;
            g_SID_TempPV_DW.Check_Level_MODE = false;
        }
    }

    /* End of Logic: '<S54>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S54>/Check_Level' */

    /* DataTypeConversion: '<S54>/Data Type Conversion2' */
    lbo_DataTypeConversion1_l = (UInt8)SID_m_st_TempPVHigh;

    /*
     * Block description for '<S51>/Constant3':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S54>/sfun_SetErr_SigHigh' incorporates:
     *  Constant: '<S51>/Constant3'
     *
     * Block description for '<S51>/Constant3':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPV_HIGH_ID, lbo_DataTypeConversion1_l);

    /* DataTypeConversion: '<S54>/Data Type Conversion3' */
    lbo_DataTypeConversion1_l = (UInt8)SID_m_st_TempPVLow;

    /*
     * Block description for '<S51>/Constant6':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S54>/sfun_SetErr_SigLow' incorporates:
     *  Constant: '<S51>/Constant6'
     *
     * Block description for '<S51>/Constant6':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPV_LOW_ID, lbo_DataTypeConversion1_l);

    /* DataTypeConversion: '<S54>/Data Type Conversion' incorporates:
     *  Constant: '<S54>/Constant1'
     *  RelationalOperator: '<S54>/Relational Operator'
     *
     * Block description for '<S54>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_l = (UInt8)(SID_m_st_TempPVSRC == SRC_HIGH_DEF);

    /*
     * Block description for '<S51>/Constant9':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S54>/sfun_SetErr_SrcH' incorporates:
     *  Constant: '<S51>/Constant9'
     *
     * Block description for '<S51>/Constant9':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPV_SRCH_ID, lbo_DataTypeConversion1_l);

    /* DataTypeConversion: '<S54>/Data Type Conversion1' incorporates:
     *  Constant: '<S54>/Constant2'
     *  RelationalOperator: '<S54>/Relational Operator1'
     *
     * Block description for '<S54>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_l = (UInt8)(SID_m_st_TempPVSRC == SRC_LOW_DEF);

    /*
     * Block description for '<S51>/Constant5':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S54>/sfun_SetErr_SrcL' incorporates:
     *  Constant: '<S51>/Constant5'
     *
     * Block description for '<S51>/Constant5':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPV_SRCL_ID, lbo_DataTypeConversion1_l);

    /* SignalConversion: '<S55>/TmpSignal ConversionAtSRC_CheckOutport2' */
    SID_m_st_TempPVTmpSRC = g_SID_TempPV_B.SRC_Tmp_Def_Flag;

    /* Switch: '<S52>/Switch5' incorporates:
     *  UnitDelay: '<S52>/Unit Delay1'
     */
    if (SID_m_st_TempPVTmpSRC)
    {
        lbo_Switch5 = g_SID_TempPV_DW.UnitDelay1_DSTATE;
    }
    else
    {
        lbo_Switch5 = SID_m_t_TempPVLinear;
    }

    /* End of Switch: '<S52>/Switch5' */

    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S52>/Constant8'
     *
     * Block description for '<S52>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (SID_m_st_TempPVSRC != 0)
    {
        lbo_Switch_c = SID_C_t_TempPRplcVal;
    }
    else
    {
        lbo_Switch_c = lbo_Switch5;
    }

    /* End of Switch: '<S52>/Switch' */

    /* Chart: '<S52>/SignalGradientLimit' */
    /* Gateway: SENSOR_SIGNAL/TempPV/Signal_Evaluation/SignalGradientLimit */
    /* During: SENSOR_SIGNAL/TempPV/Signal_Evaluation/SignalGradientLimit */
    if (g_SID_TempPV_DW.bitsForTID0.is_active_c1_SID == 0U)
    {
        /* Entry: SENSOR_SIGNAL/TempPV/Signal_Evaluation/SignalGradientLimit */
        g_SID_TempPV_DW.bitsForTID0.is_active_c1_SID = 1U;

        /* Entry Internal: SENSOR_SIGNAL/TempPV/Signal_Evaluation/SignalGradientLimit */
        /* Transition: '<S61>:17' */
        g_SID_TempPV_DW.bitsForTID0.is_c1_SID = MACRO_IN_Init_c;

        /* Entry 'Init': '<S61>:1' */
        SID_m_t_TempPV = lbo_Switch_c;
        g_SID_TempPV_DW.Signal_Tmp = lbo_Switch_c;
    }
    else if (g_SID_TempPV_DW.bitsForTID0.is_c1_SID == MACRO_IN_Init_c)
    {
        /* During 'Init': '<S61>:1' */
        /* Transition: '<S61>:3' */
        g_SID_TempPV_DW.bitsForTID0.is_c1_SID = MACRO_IN_Process_p;

        /* Entry 'Process': '<S61>:2' */
        /* Simulink Function 'GradientLmt': '<S61>:7' */
        g_SID_TempPV_B.Signal_Raw = lbo_Switch_c;
        g_SID_TempPV_B.Signal_Delay = g_SID_TempPV_DW.Signal_Tmp;

        /* Outputs for Function Call SubSystem: '<S61>/GradientLmt' */
        SID_GradientLmt(g_SID_TempPV_B.Signal_Raw, g_SID_TempPV_B.Signal_Delay,
                        &g_SID_TempPV_B.DifferenceInputs2);

        /* End of Outputs for SubSystem: '<S61>/GradientLmt' */
        SID_m_t_TempPV = g_SID_TempPV_B.DifferenceInputs2;
        g_SID_TempPV_DW.Signal_Tmp = lbo_Switch_c;
    }
    else
    {
        /* During 'Process': '<S61>:2' */
    }

    /* End of Chart: '<S52>/SignalGradientLimit' */

    /* Update for UnitDelay: '<S52>/Unit Delay1' */
    g_SID_TempPV_DW.UnitDelay1_DSTATE = lbo_Switch5;
}

/* Initial conditions for atomic system: '<S2>/TempPW' */
void SID_TempPW_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S67>/SRC_Check' */
    SID_SRC_Check_Init(&g_SID_TempPW_B.SRC_Def_Status,
                       &g_SID_TempPW_B.SRC_Tmp_Def_Flag);

    /* End of InitializeConditions for SubSystem: '<S67>/SRC_Check' */
}

/* Output and update for atomic system: '<S2>/TempPW' */
void SID_TempPW(void)
{
    /* local block i/o variables */
    UInt8 lbo_DataTypeConversion1_o;
    Boolean lbo_Switch_kd;
    t_Temp3 lbo_Switch5;
    t_Temp3 lbo_Switch_e;

    /* Gain: '<S65>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_TempPWRaw'
     */
    SID_m_u_TempPW = (SInt16)(825U * SID_m_ct_TempPWRaw >> 10);

    /* Lookup: '<S67>/SID_CUR_t_TempPU'
     * About '<S67>/SID_CUR_t_TempPU':
     * Input0  Data Type:  Integer        S16
     * Output0 Data Type:  Fixed Point    S16  2^-4  FSlope 1.6
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_S16_S16_SAT( &(SID_m_t_TempPWLinear), (&(SID_CUR_t_TempP[0])),
                       SID_m_u_TempPW, (&(SID_CURX_u_TempP[0])), 22U);

    /* Outputs for Atomic SubSystem: '<S67>/SRC_Check' */

    /* Constant: '<S67>/clear5' incorporates:
     *  Constant: '<S67>/SID_C_ti_DPSSRCHighNegDeb'
     *  Constant: '<S67>/SID_C_ti_DPSSRCHighPosDeb'
     *  Constant: '<S67>/SID_C_ti_DPSSRCLowNegDeb'
     *  Constant: '<S67>/SID_C_ti_DPSSRCLowPosDeb'
     *  Constant: '<S67>/SID_C_u_DPSSRCHigh '
     *  Constant: '<S67>/SID_C_u_DPSSRCLow'
     *  Constant: '<S67>/ST_DPS_PROCESS'
     */
    SID_SRC_Check(0U, SID_m_u_TempPW, SID_C_u_TempPSRCHigh, SID_C_u_TempPSRCLow,
                  SID_C_ti_TempPSRCHighPosDeb, SID_C_ti_TempPSRCHighNegDeb,
                  SID_C_ti_TempPSRCLowPosDeb, SID_C_ti_TempPSRCLowNegDeb,
                  ST_TEMPP_PROCESS, &g_SID_TempPW_B.SRC_Def_Status,
                  &g_SID_TempPW_B.SRC_Tmp_Def_Flag, &g_SID_TempPW_DW.SRC_Check);

    /* End of Outputs for SubSystem: '<S67>/SRC_Check' */

    /* SignalConversion: '<S67>/TmpSignal ConversionAtSRC_CheckOutport1' */
    SID_m_st_TempPWSRC = g_SID_TempPW_B.SRC_Def_Status;

    /* Outputs for Enabled SubSystem: '<S66>/Check_Level' incorporates:
     *  EnablePort: '<S68>/Enable'
     */
    /* Logic: '<S66>/Logical Operator2' */
    if (!(SID_m_st_TempPWSRC != 0))
    {
        if (!g_SID_TempPW_DW.Check_Level_MODE)
        {
            g_SID_TempPW_DW.Check_Level_MODE = true;
        }

        /* Switch: '<S70>/Switch' incorporates:
         *  Constant: '<S63>/Constant1'
         *  Constant: '<S63>/Constant10'
         *  Constant: '<S70>/Constant'
         *  RelationalOperator: '<S70>/Relational Operator'
         *  RelationalOperator: '<S70>/Relational Operator1'
         *  Sum: '<S68>/Add3'
         *  Switch: '<S70>/Switch1'
         *  UnitDelay: '<S70>/Unit Delay'
         *
         * Block description for '<S63>/Constant1':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S63>/Constant10':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempPWLinear >= (SInt16)(SID_C_t_TempPLowOffset +
                SID_C_t_TempPLow))
        {
            lbo_Switch_kd = true;
        }
        else if (SID_m_t_TempPWLinear <= SID_C_t_TempPLow)
        {
            /* Switch: '<S70>/Switch1' incorporates:
             *  Constant: '<S70>/Constant1'
             */
            lbo_Switch_kd = false;
        }
        else
        {
            lbo_Switch_kd = g_SID_TempPW_DW.UnitDelay_DSTATE;
        }

        /* End of Switch: '<S70>/Switch' */

        /* Logic: '<S68>/Logical Operator2' */
        SID_m_st_TempPWLow = !lbo_Switch_kd;

        /* Switch: '<S69>/Switch' incorporates:
         *  Constant: '<S63>/Constant2'
         *  Constant: '<S63>/Constant8'
         *  Constant: '<S69>/Constant'
         *  RelationalOperator: '<S69>/Relational Operator'
         *  RelationalOperator: '<S69>/Relational Operator1'
         *  Sum: '<S68>/Add1'
         *  Switch: '<S69>/Switch1'
         *
         * Block description for '<S63>/Constant2':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S63>/Constant8':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempPWLinear >= SID_C_t_TempPHigh)
        {
            SID_m_st_TempPWHigh = true;
        }
        else if (SID_m_t_TempPWLinear <= (SInt16)(SID_C_t_TempPHigh -
                  SID_C_t_TempPHighOffset))
        {
            /* Switch: '<S69>/Switch1' incorporates:
             *  Constant: '<S69>/Constant1'
             */
            SID_m_st_TempPWHigh = false;
        }
        else
        {
            /* Switch: '<S69>/Switch1' incorporates:
             *  UnitDelay: '<S69>/Unit Delay'
             */
            SID_m_st_TempPWHigh = g_SID_TempPW_DW.UnitDelay_DSTATE_i;
        }

        /* End of Switch: '<S69>/Switch' */

        /* Update for UnitDelay: '<S70>/Unit Delay' */
        g_SID_TempPW_DW.UnitDelay_DSTATE = lbo_Switch_kd;

        /* Update for UnitDelay: '<S69>/Unit Delay' */
        g_SID_TempPW_DW.UnitDelay_DSTATE_i = SID_m_st_TempPWHigh;
    }
    else
    {
        if (g_SID_TempPW_DW.Check_Level_MODE)
        {
            /* Disable for Outport: '<S68>/SigHigh_st' */
            SID_m_st_TempPWHigh = false;

            /* Disable for Outport: '<S68>/SigLow_st' */
            SID_m_st_TempPWLow = false;
            g_SID_TempPW_DW.Check_Level_MODE = false;
        }
    }

    /* End of Logic: '<S66>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S66>/Check_Level' */

    /* DataTypeConversion: '<S66>/Data Type Conversion2' */
    lbo_DataTypeConversion1_o = (UInt8)SID_m_st_TempPWHigh;

    /*
     * Block description for '<S63>/Constant3':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S66>/sfun_SetErr_SigHigh' incorporates:
     *  Constant: '<S63>/Constant3'
     *
     * Block description for '<S63>/Constant3':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPW_HIGH_ID, lbo_DataTypeConversion1_o);

    /* DataTypeConversion: '<S66>/Data Type Conversion3' */
    lbo_DataTypeConversion1_o = (UInt8)SID_m_st_TempPWLow;

    /*
     * Block description for '<S63>/Constant6':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S66>/sfun_SetErr_SigLow' incorporates:
     *  Constant: '<S63>/Constant6'
     *
     * Block description for '<S63>/Constant6':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPW_LOW_ID, lbo_DataTypeConversion1_o);

    /* DataTypeConversion: '<S66>/Data Type Conversion' incorporates:
     *  Constant: '<S66>/Constant1'
     *  RelationalOperator: '<S66>/Relational Operator'
     *
     * Block description for '<S66>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_o = (UInt8)(SID_m_st_TempPWSRC == SRC_HIGH_DEF);

    /*
     * Block description for '<S63>/Constant9':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S66>/sfun_SetErr_SrcH' incorporates:
     *  Constant: '<S63>/Constant9'
     *
     * Block description for '<S63>/Constant9':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPW_SRCH_ID, lbo_DataTypeConversion1_o);

    /* DataTypeConversion: '<S66>/Data Type Conversion1' incorporates:
     *  Constant: '<S66>/Constant2'
     *  RelationalOperator: '<S66>/Relational Operator1'
     *
     * Block description for '<S66>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_o = (UInt8)(SID_m_st_TempPWSRC == SRC_LOW_DEF);

    /*
     * Block description for '<S63>/Constant5':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S66>/sfun_SetErr_SrcL' incorporates:
     *  Constant: '<S63>/Constant5'
     *
     * Block description for '<S63>/Constant5':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPPW_SRCL_ID, lbo_DataTypeConversion1_o);

    /* SignalConversion: '<S67>/TmpSignal ConversionAtSRC_CheckOutport2' */
    SID_m_st_TempPWTmpSRC = g_SID_TempPW_B.SRC_Tmp_Def_Flag;

    /* Switch: '<S64>/Switch5' incorporates:
     *  UnitDelay: '<S64>/Unit Delay1'
     */
    if (SID_m_st_TempPWTmpSRC)
    {
        lbo_Switch5 = g_SID_TempPW_DW.UnitDelay1_DSTATE;
    }
    else
    {
        lbo_Switch5 = SID_m_t_TempPWLinear;
    }

    /* End of Switch: '<S64>/Switch5' */

    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S64>/Constant8'
     *
     * Block description for '<S64>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (SID_m_st_TempPWSRC != 0)
    {
        lbo_Switch_e = SID_C_t_TempPRplcVal;
    }
    else
    {
        lbo_Switch_e = lbo_Switch5;
    }

    /* End of Switch: '<S64>/Switch' */

    /* Chart: '<S64>/SignalGradientLimit' */
    /* Gateway: SENSOR_SIGNAL/TempPW/Signal_Evaluation/SignalGradientLimit */
    /* During: SENSOR_SIGNAL/TempPW/Signal_Evaluation/SignalGradientLimit */
    if (g_SID_TempPW_DW.bitsForTID0.is_active_c6_SID == 0U)
    {
        /* Entry: SENSOR_SIGNAL/TempPW/Signal_Evaluation/SignalGradientLimit */
        g_SID_TempPW_DW.bitsForTID0.is_active_c6_SID = 1U;

        /* Entry Internal: SENSOR_SIGNAL/TempPW/Signal_Evaluation/SignalGradientLimit */
        /* Transition: '<S73>:17' */
        g_SID_TempPW_DW.bitsForTID0.is_c6_SID = MACRO_IN_Init_b;

        /* Entry 'Init': '<S73>:1' */
        SID_m_t_TempPW = lbo_Switch_e;
        g_SID_TempPW_DW.Signal_Tmp = lbo_Switch_e;
    }
    else if (g_SID_TempPW_DW.bitsForTID0.is_c6_SID == MACRO_IN_Init_b)
    {
        /* During 'Init': '<S73>:1' */
        /* Transition: '<S73>:3' */
        g_SID_TempPW_DW.bitsForTID0.is_c6_SID = MACRO_IN_Process_h;

        /* Entry 'Process': '<S73>:2' */
        /* Simulink Function 'GradientLmt': '<S73>:7' */
        g_SID_TempPW_B.Signal_Raw = lbo_Switch_e;
        g_SID_TempPW_B.Signal_Delay = g_SID_TempPW_DW.Signal_Tmp;

        /* Outputs for Function Call SubSystem: '<S73>/GradientLmt' */
        SID_GradientLmt(g_SID_TempPW_B.Signal_Raw, g_SID_TempPW_B.Signal_Delay,
                        &g_SID_TempPW_B.DifferenceInputs2);

        /* End of Outputs for SubSystem: '<S73>/GradientLmt' */
        SID_m_t_TempPW = g_SID_TempPW_B.DifferenceInputs2;
        g_SID_TempPW_DW.Signal_Tmp = lbo_Switch_e;
    }
    else
    {
        /* During 'Process': '<S73>:2' */
    }

    /* End of Chart: '<S64>/SignalGradientLimit' */

    /* Update for UnitDelay: '<S64>/Unit Delay1' */
    g_SID_TempPW_DW.UnitDelay1_DSTATE = lbo_Switch5;
}

/* Initial conditions for atomic system: '<S2>/TempShell' */
void SID_TempShell_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S79>/SRC_Check' */
    SID_SRC_Check_Init(&g_SID_TempShell_B.SRC_Def_Status,
                       &g_SID_TempShell_B.SRC_Tmp_Def_Flag);

    /* End of InitializeConditions for SubSystem: '<S79>/SRC_Check' */
}

/* Output and update for atomic system: '<S2>/TempShell' */
void SID_TempShell(void)
{
    /* local block i/o variables */
    UInt8 lbo_DataTypeConversion1_a;
    Boolean lbo_Switch_ba;
    t_Temp3 lbo_Switch5;
    t_Temp3 lbo_Switch_a;
    t_Timer2 lbo_Divide;
    SInt32 lbo_Switch2;
    t_Pressure4 lbo_DifferenceInputs1;

    /* Gain: '<S77>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_TempShellRaw'
     */
    SID_m_u_TempShell = (SInt16)(825U * SID_m_ct_TempShellRaw >> 10);

    /* Lookup: '<S79>/SID_CUR_t_TempPU'
     * About '<S79>/SID_CUR_t_TempPU':
     * Input0  Data Type:  Integer        S16
     * Output0 Data Type:  Fixed Point    S16  2^-4  FSlope 1.6
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_S16_S16_SAT( &(SID_m_t_TempShellLinear), (&(SID_CUR_t_TempShell[0])),
                       SID_m_u_TempShell, (&(SID_CURX_u_TempShell[0])), 19U);

    /* Outputs for Atomic SubSystem: '<S79>/SRC_Check' */

    /* Constant: '<S79>/clear5' incorporates:
     *  Constant: '<S79>/SID_C_ti_DPSSRCHighNegDeb'
     *  Constant: '<S79>/SID_C_ti_DPSSRCHighPosDeb'
     *  Constant: '<S79>/SID_C_ti_DPSSRCLowNegDeb'
     *  Constant: '<S79>/SID_C_ti_DPSSRCLowPosDeb'
     *  Constant: '<S79>/SID_C_u_DPSSRCHigh '
     *  Constant: '<S79>/SID_C_u_DPSSRCLow'
     *  Constant: '<S79>/ST_DPS_PROCESS'
     */
    SID_SRC_Check(0U, SID_m_u_TempShell, SID_C_u_TempShellSRCHigh,
                  SID_C_u_TempShellSRCLow, SID_C_ti_TempShellSRCHighPosDeb,
                  SID_C_ti_TempShellSRCHighNegDeb,
                  SID_C_ti_TempShellSRCLowPosDeb, SID_C_ti_TempShellSRCLowNegDeb,
                  ST_TEMPSHELL_PROCESS, &g_SID_TempShell_B.SRC_Def_Status,
                  &g_SID_TempShell_B.SRC_Tmp_Def_Flag,
                  &g_SID_TempShell_DW.SRC_Check);

    /* End of Outputs for SubSystem: '<S79>/SRC_Check' */

    /* SignalConversion: '<S79>/TmpSignal ConversionAtSRC_CheckOutport1' */
    SID_m_st_TempShellSRC = g_SID_TempShell_B.SRC_Def_Status;

    /* Outputs for Enabled SubSystem: '<S78>/Check_Level' incorporates:
     *  EnablePort: '<S80>/Enable'
     */
    /* Logic: '<S78>/Logical Operator2' */
    if (!(SID_m_st_TempShellSRC != 0))
    {
        if (!g_SID_TempShell_DW.Check_Level_MODE)
        {
            g_SID_TempShell_DW.Check_Level_MODE = true;
        }

        /* Switch: '<S82>/Switch' incorporates:
         *  Constant: '<S75>/Constant1'
         *  Constant: '<S75>/Constant10'
         *  Constant: '<S82>/Constant'
         *  RelationalOperator: '<S82>/Relational Operator'
         *  RelationalOperator: '<S82>/Relational Operator1'
         *  Sum: '<S80>/Add3'
         *  Switch: '<S82>/Switch1'
         *  UnitDelay: '<S82>/Unit Delay'
         *
         * Block description for '<S75>/Constant1':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S75>/Constant10':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempShellLinear >= (SInt16)(SID_C_t_TempShellLowOffset +
                SID_C_t_TempShellLow))
        {
            lbo_Switch_ba = true;
        }
        else if (SID_m_t_TempShellLinear <= SID_C_t_TempShellLow)
        {
            /* Switch: '<S82>/Switch1' incorporates:
             *  Constant: '<S82>/Constant1'
             */
            lbo_Switch_ba = false;
        }
        else
        {
            lbo_Switch_ba = g_SID_TempShell_DW.UnitDelay_DSTATE;
        }

        /* End of Switch: '<S82>/Switch' */

        /* Logic: '<S80>/Logical Operator2' */
        SID_m_st_TempShellLow = !lbo_Switch_ba;

        /* Switch: '<S81>/Switch' incorporates:
         *  Constant: '<S75>/Constant2'
         *  Constant: '<S75>/Constant8'
         *  Constant: '<S81>/Constant'
         *  RelationalOperator: '<S81>/Relational Operator'
         *  RelationalOperator: '<S81>/Relational Operator1'
         *  Sum: '<S80>/Add1'
         *  Switch: '<S81>/Switch1'
         *
         * Block description for '<S75>/Constant2':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S75>/Constant8':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempShellLinear >= SID_C_t_TempShellHigh)
        {
            SID_m_st_TempShellHigh = true;
        }
        else if (SID_m_t_TempShellLinear <= (SInt16)(SID_C_t_TempShellHigh -
                  SID_C_t_TempShellHighOffset))
        {
            /* Switch: '<S81>/Switch1' incorporates:
             *  Constant: '<S81>/Constant1'
             */
            SID_m_st_TempShellHigh = false;
        }
        else
        {
            /* Switch: '<S81>/Switch1' incorporates:
             *  UnitDelay: '<S81>/Unit Delay'
             */
            SID_m_st_TempShellHigh = g_SID_TempShell_DW.UnitDelay_DSTATE_n;
        }

        /* End of Switch: '<S81>/Switch' */

        /* Update for UnitDelay: '<S82>/Unit Delay' */
        g_SID_TempShell_DW.UnitDelay_DSTATE = lbo_Switch_ba;

        /* Update for UnitDelay: '<S81>/Unit Delay' */
        g_SID_TempShell_DW.UnitDelay_DSTATE_n = SID_m_st_TempShellHigh;
    }
    else
    {
        if (g_SID_TempShell_DW.Check_Level_MODE)
        {
            /* Disable for Outport: '<S80>/SigHigh_st' */
            SID_m_st_TempShellHigh = false;

            /* Disable for Outport: '<S80>/SigLow_st' */
            SID_m_st_TempShellLow = false;
            g_SID_TempShell_DW.Check_Level_MODE = false;
        }
    }

    /* End of Logic: '<S78>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S78>/Check_Level' */

    /* DataTypeConversion: '<S78>/Data Type Conversion2' */
    lbo_DataTypeConversion1_a = (UInt8)SID_m_st_TempShellHigh;

    /*
     * Block description for '<S75>/Constant3':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S78>/sfun_SetErr_SigHigh' incorporates:
     *  Constant: '<S75>/Constant3'
     *
     * Block description for '<S75>/Constant3':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPSHELL_HIGH_ID, lbo_DataTypeConversion1_a);

    /* DataTypeConversion: '<S78>/Data Type Conversion3' */
    lbo_DataTypeConversion1_a = (UInt8)SID_m_st_TempShellLow;

    /*
     * Block description for '<S75>/Constant6':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S78>/sfun_SetErr_SigLow' incorporates:
     *  Constant: '<S75>/Constant6'
     *
     * Block description for '<S75>/Constant6':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPSHELL_LOW_ID, lbo_DataTypeConversion1_a);

    /* DataTypeConversion: '<S78>/Data Type Conversion' incorporates:
     *  Constant: '<S78>/Constant1'
     *  RelationalOperator: '<S78>/Relational Operator'
     *
     * Block description for '<S78>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_a = (UInt8)(SID_m_st_TempShellSRC == SRC_HIGH_DEF);

    /*
     * Block description for '<S75>/Constant9':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S78>/sfun_SetErr_SrcH' incorporates:
     *  Constant: '<S75>/Constant9'
     *
     * Block description for '<S75>/Constant9':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPSHELL_SRCH_ID, lbo_DataTypeConversion1_a);

    /* DataTypeConversion: '<S78>/Data Type Conversion1' incorporates:
     *  Constant: '<S78>/Constant2'
     *  RelationalOperator: '<S78>/Relational Operator1'
     *
     * Block description for '<S78>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_a = (UInt8)(SID_m_st_TempShellSRC == SRC_LOW_DEF);

    /*
     * Block description for '<S75>/Constant5':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S78>/sfun_SetErr_SrcL' incorporates:
     *  Constant: '<S75>/Constant5'
     *
     * Block description for '<S75>/Constant5':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPSHELL_SRCL_ID, lbo_DataTypeConversion1_a);

    /* SignalConversion: '<S79>/TmpSignal ConversionAtSRC_CheckOutport2' */
    SID_m_st_TempShellTmpSRC = g_SID_TempShell_B.SRC_Tmp_Def_Flag;

    /* Switch: '<S76>/Switch5' incorporates:
     *  UnitDelay: '<S76>/Unit Delay1'
     */
    if (SID_m_st_TempShellTmpSRC)
    {
        lbo_Switch5 = g_SID_TempShell_DW.UnitDelay1_DSTATE;
    }
    else
    {
        lbo_Switch5 = SID_m_t_TempShellLinear;
    }

    /* End of Switch: '<S76>/Switch5' */

    /* Switch: '<S76>/Switch' incorporates:
     *  Constant: '<S76>/Constant8'
     *
     * Block description for '<S76>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (SID_m_st_TempShellSRC != 0)
    {
        lbo_Switch_a = SID_C_t_TempShellRplcVal;
    }
    else
    {
        lbo_Switch_a = lbo_Switch5;
    }

    /* End of Switch: '<S76>/Switch' */

    /* Chart: '<S76>/SignalGradientLimit' incorporates:
     *  Sum: '<S86>/Difference Inputs2'
     */
    /* Gateway: SENSOR_SIGNAL/TempShell/Signal_Evaluation/SignalGradientLimit */
    /* During: SENSOR_SIGNAL/TempShell/Signal_Evaluation/SignalGradientLimit */
    if (g_SID_TempShell_DW.bitsForTID0.is_active_c8_SID == 0U)
    {
        /* Entry: SENSOR_SIGNAL/TempShell/Signal_Evaluation/SignalGradientLimit */
        g_SID_TempShell_DW.bitsForTID0.is_active_c8_SID = 1U;

        /* Entry Internal: SENSOR_SIGNAL/TempShell/Signal_Evaluation/SignalGradientLimit */
        /* Transition: '<S85>:17' */
        g_SID_TempShell_DW.bitsForTID0.is_c8_SID = MACRO_IN_Init_g;

        /* Entry 'Init': '<S85>:1' */
        SID_m_t_TempShell = lbo_Switch_a;
        g_SID_TempShell_DW.Signal_Tmp = lbo_Switch_a;
    }
    else if (g_SID_TempShell_DW.bitsForTID0.is_c8_SID == MACRO_IN_Init_g)
    {
        /* During 'Init': '<S85>:1' */
        /* Transition: '<S85>:3' */
        g_SID_TempShell_DW.bitsForTID0.is_c8_SID = MACRO_IN_Process_e;

        /* Outputs for Function Call SubSystem: '<S85>/GradientLmt' */
        /* Sum: '<S86>/Difference Inputs1' */
        /* Entry 'Process': '<S85>:2' */
        /* Simulink Function 'GradientLmt': '<S85>:7' */
        lbo_DifferenceInputs1 = (SInt16)(lbo_Switch_a -
            g_SID_TempShell_DW.Signal_Tmp);

        /* Product: '<S86>/Divide' incorporates:
         *  Constant: '<S86>/Constant13'
         *
         * Block description for '<S86>/Constant13':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        lbo_Divide = (t_Timer2)(((UInt32)ST_TEMPP_PROCESS << 6) / 125U * 125U >>
                                6);

        /* Product: '<S86>/delta rise limit' incorporates:
         *  Constant: '<S86>/Constant11'
         *
         * Block description for '<S86>/Constant11':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        lbo_Switch2 = SID_C_t_TempShellRiseRate * lbo_Divide;

        /* Switch: '<S86>/Switch2' incorporates:
         *  RelationalOperator: '<S86>/UpperRelop'
         */
        if (!(lbo_DifferenceInputs1 * 1000 >= lbo_Switch2))
        {
            /* Product: '<S86>/delta fall limit' incorporates:
             *  Constant: '<S86>/Constant12'
             *
             * Block description for '<S86>/Constant12':
             *  For Constants, Enter name in block in all CAPS
             *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
             */
            lbo_Switch2 = SID_C_t_TempShellFallRate * lbo_Divide;

            /* Switch: '<S86>/Switch' incorporates:
             *  RelationalOperator: '<S86>/LowerRelop'
             */
            if (!(lbo_DifferenceInputs1 * 1000 <= lbo_Switch2))
            {
                lbo_Switch2 = lbo_DifferenceInputs1 * 1000;
            }

            /* End of Switch: '<S86>/Switch' */
        }

        /* End of Switch: '<S86>/Switch2' */
        SID_m_t_TempShell = (SInt16)(((g_SID_TempShell_DW.Signal_Tmp << 8) +
            mul_s32_s32_s32_sr30(lbo_Switch2, 274877907)) >> 8);

        /* End of Outputs for SubSystem: '<S85>/GradientLmt' */
        g_SID_TempShell_DW.Signal_Tmp = lbo_Switch_a;
    }
    else
    {
        /* During 'Process': '<S85>:2' */
    }

    /* End of Chart: '<S76>/SignalGradientLimit' */

    /* Update for UnitDelay: '<S76>/Unit Delay1' */
    g_SID_TempShell_DW.UnitDelay1_DSTATE = lbo_Switch5;
}

/* Initial conditions for atomic system: '<S2>/TempStator' */
void SID_TempStator_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S91>/SRC_Check' */
    SID_SRC_Check_Init(&g_SID_TempStator_B.SRC_Def_Status,
                       &g_SID_TempStator_B.SRC_Tmp_Def_Flag);

    /* End of InitializeConditions for SubSystem: '<S91>/SRC_Check' */
}

/* Output and update for atomic system: '<S2>/TempStator' */
void SID_TempStator(void)
{
    /* local block i/o variables */
    UInt8 lbo_DataTypeConversion1_j;
    Boolean lbo_Switch_d;
    t_Temp3 lbo_Switch5;
    t_Temp3 lbo_Switch_g;
    t_Timer2 lbo_Divide;
    SInt32 lbo_Switch2;
    t_Pressure4 lbo_DifferenceInputs1;

    /* Gain: '<S89>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_TempStatorRaw'
     */
    //SID_m_u_TempStator = (t_Voltage4)(825 * g_SID_U.SID_m_ct_TempStatorRaw >> 10);
    SID_m_u_TempStator = (t_Voltage4)(825 * SID_m_ct_TempStatorRaw >> 10);

    /* Lookup: '<S91>/SID_CUR_t_TempPU'
     * About '<S91>/SID_CUR_t_TempPU':
     * Input0  Data Type:  Integer        S16
     * Output0 Data Type:  Fixed Point    S16  2^-4  FSlope 1.6
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_S16_S16_SAT( &(SID_m_t_TempStatorLinear), (&(SID_CUR_t_TempStator[0])),
                       SID_m_u_TempStator, (&(SID_CURX_u_TempStator[0])), 19U);

    /* Outputs for Atomic SubSystem: '<S91>/SRC_Check' */

    /* Constant: '<S91>/clear5' incorporates:
     *  Constant: '<S91>/SID_C_ti_DPSSRCHighNegDeb'
     *  Constant: '<S91>/SID_C_ti_DPSSRCHighPosDeb'
     *  Constant: '<S91>/SID_C_ti_DPSSRCLowNegDeb'
     *  Constant: '<S91>/SID_C_ti_DPSSRCLowPosDeb'
     *  Constant: '<S91>/SID_C_u_DPSSRCHigh '
     *  Constant: '<S91>/SID_C_u_DPSSRCLow'
     *  Constant: '<S91>/ST_DPS_PROCESS'
     */
    SID_SRC_Check(0U, SID_m_u_TempStator, SID_C_u_TempStatorSRCHigh,
                  SID_C_u_TempStatorSRCLow, SID_C_ti_TempStatorSRCHighPosDeb,
                  SID_C_ti_TempStatorSRCHighNegDeb,
                  SID_C_ti_TempStatorSRCLowPosDeb,
                  SID_C_ti_TempStatorSRCLowNegDeb, ST_TEMPSTATOR_PROCESS,
                  &g_SID_TempStator_B.SRC_Def_Status,
                  &g_SID_TempStator_B.SRC_Tmp_Def_Flag,
                  &g_SID_TempStator_DW.SRC_Check);

    /* End of Outputs for SubSystem: '<S91>/SRC_Check' */

    /* SignalConversion: '<S91>/TmpSignal ConversionAtSRC_CheckOutport1' */
    SID_m_st_TempStatorSRC = g_SID_TempStator_B.SRC_Def_Status;

    /* Outputs for Enabled SubSystem: '<S90>/Check_Level' incorporates:
     *  EnablePort: '<S92>/Enable'
     */
    /* Logic: '<S90>/Logical Operator2' */
    if (!(SID_m_st_TempStatorSRC != 0))
    {
        if (!g_SID_TempStator_DW.Check_Level_MODE)
        {
            g_SID_TempStator_DW.Check_Level_MODE = true;
        }

        /* Switch: '<S94>/Switch' incorporates:
         *  Constant: '<S87>/Constant1'
         *  Constant: '<S87>/Constant10'
         *  Constant: '<S94>/Constant'
         *  RelationalOperator: '<S94>/Relational Operator'
         *  RelationalOperator: '<S94>/Relational Operator1'
         *  Sum: '<S92>/Add3'
         *  Switch: '<S94>/Switch1'
         *  UnitDelay: '<S94>/Unit Delay'
         *
         * Block description for '<S87>/Constant1':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S87>/Constant10':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempStatorLinear >= (SInt16)(SID_C_t_TempStatorLowOffset +
                SID_C_t_TempStatorLow))
        {
            lbo_Switch_d = true;
        }
        else if (SID_m_t_TempStatorLinear <= SID_C_t_TempStatorLow)
        {
            /* Switch: '<S94>/Switch1' incorporates:
             *  Constant: '<S94>/Constant1'
             */
            lbo_Switch_d = false;
        }
        else
        {
            lbo_Switch_d = g_SID_TempStator_DW.UnitDelay_DSTATE;
        }

        /* End of Switch: '<S94>/Switch' */

        /* Logic: '<S92>/Logical Operator2' */
        SID_m_st_TempStatorLow = !lbo_Switch_d;

        /* Switch: '<S93>/Switch' incorporates:
         *  Constant: '<S87>/Constant2'
         *  Constant: '<S87>/Constant8'
         *  Constant: '<S93>/Constant'
         *  RelationalOperator: '<S93>/Relational Operator'
         *  RelationalOperator: '<S93>/Relational Operator1'
         *  Sum: '<S92>/Add1'
         *  Switch: '<S93>/Switch1'
         *
         * Block description for '<S87>/Constant2':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         *
         * Block description for '<S87>/Constant8':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        if (SID_m_t_TempStatorLinear >= SID_C_t_TempStatorHigh)
        {
            SID_m_st_TempStatorHigh = true;
        }
        else if (SID_m_t_TempStatorLinear <= (SInt16)(SID_C_t_TempStatorHigh -
                  SID_C_t_TempStatorHighOffset))
        {
            /* Switch: '<S93>/Switch1' incorporates:
             *  Constant: '<S93>/Constant1'
             */
            SID_m_st_TempStatorHigh = false;
        }
        else
        {
            /* Switch: '<S93>/Switch1' incorporates:
             *  UnitDelay: '<S93>/Unit Delay'
             */
            SID_m_st_TempStatorHigh = g_SID_TempStator_DW.UnitDelay_DSTATE_p;
        }

        /* End of Switch: '<S93>/Switch' */

        /* Update for UnitDelay: '<S94>/Unit Delay' */
        g_SID_TempStator_DW.UnitDelay_DSTATE = lbo_Switch_d;

        /* Update for UnitDelay: '<S93>/Unit Delay' */
        g_SID_TempStator_DW.UnitDelay_DSTATE_p = SID_m_st_TempStatorHigh;
    }
    else
    {
        if (g_SID_TempStator_DW.Check_Level_MODE)
        {
            /* Disable for Outport: '<S92>/SigHigh_st' */
            SID_m_st_TempStatorHigh = false;

            /* Disable for Outport: '<S92>/SigLow_st' */
            SID_m_st_TempStatorLow = false;
            g_SID_TempStator_DW.Check_Level_MODE = false;
        }
    }

    /* End of Logic: '<S90>/Logical Operator2' */
    /* End of Outputs for SubSystem: '<S90>/Check_Level' */

    /* DataTypeConversion: '<S90>/Data Type Conversion2' */
    lbo_DataTypeConversion1_j = (UInt8)SID_m_st_TempStatorHigh;

    /*
     * Block description for '<S87>/Constant3':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S90>/sfun_SetErr_SigHigh' incorporates:
     *  Constant: '<S87>/Constant3'
     *
     * Block description for '<S87>/Constant3':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPSTATOR_HIGH_ID, lbo_DataTypeConversion1_j);

    /* DataTypeConversion: '<S90>/Data Type Conversion3' */
    lbo_DataTypeConversion1_j = (UInt8)SID_m_st_TempStatorLow;

    /*
     * Block description for '<S87>/Constant6':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S90>/sfun_SetErr_SigLow' incorporates:
     *  Constant: '<S87>/Constant6'
     *
     * Block description for '<S87>/Constant6':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPSTATOR_LOW_ID, lbo_DataTypeConversion1_j);

    /* DataTypeConversion: '<S90>/Data Type Conversion' incorporates:
     *  Constant: '<S90>/Constant1'
     *  RelationalOperator: '<S90>/Relational Operator'
     *
     * Block description for '<S90>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_j = (UInt8)(SID_m_st_TempStatorSRC == SRC_HIGH_DEF);

    /*
     * Block description for '<S87>/Constant9':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S90>/sfun_SetErr_SrcH' incorporates:
     *  Constant: '<S87>/Constant9'
     *
     * Block description for '<S87>/Constant9':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPSTATOR_SRCH_ID, lbo_DataTypeConversion1_j);

    /* DataTypeConversion: '<S90>/Data Type Conversion1' incorporates:
     *  Constant: '<S90>/Constant2'
     *  RelationalOperator: '<S90>/Relational Operator1'
     *
     * Block description for '<S90>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    lbo_DataTypeConversion1_j = (UInt8)(SID_m_st_TempStatorSRC == SRC_LOW_DEF);

    /*
     * Block description for '<S87>/Constant5':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */

    /* S-Function (sfun_SetErr): '<S90>/sfun_SetErr_SrcL' incorporates:
     *  Constant: '<S87>/Constant5'
     *
     * Block description for '<S87>/Constant5':
     *   For Constants, Enter name in block in all CAPS
     *   and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    Dem_SetError( DEMTEMPSTATOR_SRCL_ID, lbo_DataTypeConversion1_j);

    /* SignalConversion: '<S91>/TmpSignal ConversionAtSRC_CheckOutport2' */
    SID_m_st_TempStatorTmpSRC = g_SID_TempStator_B.SRC_Tmp_Def_Flag;

    /* Switch: '<S88>/Switch5' incorporates:
     *  UnitDelay: '<S88>/Unit Delay1'
     */
    if (SID_m_st_TempStatorTmpSRC)
    {
        lbo_Switch5 = g_SID_TempStator_DW.UnitDelay1_DSTATE;
    }
    else
    {
        lbo_Switch5 = SID_m_t_TempStatorLinear;
    }

    /* End of Switch: '<S88>/Switch5' */

    /* Switch: '<S88>/Switch' incorporates:
     *  Constant: '<S88>/Constant8'
     *
     * Block description for '<S88>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (SID_m_st_TempStatorSRC != 0)
    {
        lbo_Switch_g = SID_C_t_TempStatorRplcVal;
    }
    else
    {
        lbo_Switch_g = lbo_Switch5;
    }

    /* End of Switch: '<S88>/Switch' */

    /* Chart: '<S88>/SignalGradientLimit' incorporates:
     *  Sum: '<S98>/Difference Inputs2'
     */
    /* Gateway: SENSOR_SIGNAL/TempStator/Signal_Evaluation/SignalGradientLimit */
    /* During: SENSOR_SIGNAL/TempStator/Signal_Evaluation/SignalGradientLimit */
    if (g_SID_TempStator_DW.bitsForTID0.is_active_c7_SID == 0U)
    {
        /* Entry: SENSOR_SIGNAL/TempStator/Signal_Evaluation/SignalGradientLimit */
        g_SID_TempStator_DW.bitsForTID0.is_active_c7_SID = 1U;

        /* Entry Internal: SENSOR_SIGNAL/TempStator/Signal_Evaluation/SignalGradientLimit */
        /* Transition: '<S97>:17' */
        g_SID_TempStator_DW.bitsForTID0.is_c7_SID = MACRO_IN_Init_m;

        /* Entry 'Init': '<S97>:1' */
        SID_m_t_TempStator = lbo_Switch_g;
        g_SID_TempStator_DW.Signal_Tmp = lbo_Switch_g;
    }
    else if (g_SID_TempStator_DW.bitsForTID0.is_c7_SID == MACRO_IN_Init_m)
    {
        /* During 'Init': '<S97>:1' */
        /* Transition: '<S97>:3' */
        g_SID_TempStator_DW.bitsForTID0.is_c7_SID = MACRO_IN_Process_d;

        /* Outputs for Function Call SubSystem: '<S97>/GradientLmt' */
        /* Sum: '<S98>/Difference Inputs1' */
        /* Entry 'Process': '<S97>:2' */
        /* Simulink Function 'GradientLmt': '<S97>:7' */
        lbo_DifferenceInputs1 = (SInt16)(lbo_Switch_g -
            g_SID_TempStator_DW.Signal_Tmp);

        /* Product: '<S98>/Divide' incorporates:
         *  Constant: '<S98>/Constant13'
         *
         * Block description for '<S98>/Constant13':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        lbo_Divide = (t_Timer2)(((UInt32)ST_TEMPSTATOR_PROCESS << 6) / 125U *
                                125U >> 6);

        /* Product: '<S98>/delta rise limit' incorporates:
         *  Constant: '<S98>/Constant11'
         *
         * Block description for '<S98>/Constant11':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        lbo_Switch2 = SID_C_t_TempStatorRiseRate * lbo_Divide;

        /* Switch: '<S98>/Switch2' incorporates:
         *  RelationalOperator: '<S98>/UpperRelop'
         */
        if (!(lbo_DifferenceInputs1 * 1000 >= lbo_Switch2))
        {
            /* Product: '<S98>/delta fall limit' incorporates:
             *  Constant: '<S98>/Constant12'
             *
             * Block description for '<S98>/Constant12':
             *  For Constants, Enter name in block in all CAPS
             *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
             */
            lbo_Switch2 = SID_C_t_TempStatorFallRate * lbo_Divide;

            /* Switch: '<S98>/Switch' incorporates:
             *  RelationalOperator: '<S98>/LowerRelop'
             */
            if (!(lbo_DifferenceInputs1 * 1000 <= lbo_Switch2))
            {
                lbo_Switch2 = lbo_DifferenceInputs1 * 1000;
            }

            /* End of Switch: '<S98>/Switch' */
        }

        /* End of Switch: '<S98>/Switch2' */
        SID_m_t_TempStator = (SInt16)(((g_SID_TempStator_DW.Signal_Tmp << 8) +
            mul_s32_s32_s32_sr30(lbo_Switch2, 274877907)) >> 8);

        /* End of Outputs for SubSystem: '<S97>/GradientLmt' */
        g_SID_TempStator_DW.Signal_Tmp = lbo_Switch_g;
    }
    else
    {
        /* During 'Process': '<S97>:2' */
    }

    /* End of Chart: '<S88>/SignalGradientLimit' */

    /* Update for UnitDelay: '<S88>/Unit Delay1' */
    g_SID_TempStator_DW.UnitDelay1_DSTATE = lbo_Switch5;
}

/* Output and update for atomic system: '<S2>/Velocity' */
void SID_Velocity(void)
{
    t_RotSpd1 lbo_UnitDelay1_eg;
    t_RotSpd1 lbo_UnitDelay2;
    t_RotSpd1 lbo_UnitDelay3;

    /* Gain: '<S26>/Gain' incorporates:
     *  Inport: '<Root>/SID_m_ct_VelocityRaw'
     */
    SID_m_n_MotSpdRaw = (SInt16)(9375 * SID_m_ct_VelocityRaw >> 11);

    /* UnitDelay: '<S26>/Unit Delay1' */
    lbo_UnitDelay1_eg = g_SID_Velocity_DW.UnitDelay1_DSTATE;

    /* UnitDelay: '<S26>/Unit Delay2' */
    lbo_UnitDelay2 = g_SID_Velocity_DW.UnitDelay2_DSTATE;

    /* UnitDelay: '<S26>/Unit Delay3' */
    lbo_UnitDelay3 = g_SID_Velocity_DW.UnitDelay3_DSTATE;

    /* Product: '<S26>/Divide' incorporates:
     *  Sum: '<S26>/Add1'
     *  UnitDelay: '<S26>/Unit Delay1'
     *  UnitDelay: '<S26>/Unit Delay2'
     *  UnitDelay: '<S26>/Unit Delay3'
     *  UnitDelay: '<S26>/Unit Delay4'
     */
    SID_m_n_MotSpd = (SInt16)div_nzp_s32_floor((((SID_m_n_MotSpdRaw +
        g_SID_Velocity_DW.UnitDelay1_DSTATE) +
        g_SID_Velocity_DW.UnitDelay2_DSTATE) +
        g_SID_Velocity_DW.UnitDelay3_DSTATE) +
        g_SID_Velocity_DW.UnitDelay4_DSTATE, 5);

    /* Update for UnitDelay: '<S26>/Unit Delay1' */
    g_SID_Velocity_DW.UnitDelay1_DSTATE = SID_m_n_MotSpdRaw;

    /* Update for UnitDelay: '<S26>/Unit Delay2' */
    g_SID_Velocity_DW.UnitDelay2_DSTATE = lbo_UnitDelay1_eg;

    /* Update for UnitDelay: '<S26>/Unit Delay3' */
    g_SID_Velocity_DW.UnitDelay3_DSTATE = lbo_UnitDelay2;

    /* Update for UnitDelay: '<S26>/Unit Delay4' */
    g_SID_Velocity_DW.UnitDelay4_DSTATE = lbo_UnitDelay3;
}

/* Initial conditions for atomic system: '<S3>/EN_SWT_DEB' */
void SID_EN_SWT_DEB_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S99>/Swtich_Debouncing' */
    SID_Swtich_Debouncing_Init(&g_SID_EN_SWT_DEB_B.swtDeb);

    /* End of InitializeConditions for SubSystem: '<S99>/Swtich_Debouncing' */
}

/* Output and update for atomic system: '<S3>/EN_SWT_DEB' */
void SID_EN_SWT_DEB(void)
{
    /* Outputs for Atomic SubSystem: '<S99>/Swtich_Debouncing' */

    /* Inport: '<Root>/SID_m_swt_ENRaw' incorporates:
     *  Constant: '<S99>/Constant1'
     *  Constant: '<S99>/Constant4'
     *  Constant: '<S99>/Constant8'
     *
     * Block description for '<S99>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S99>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S99>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    SID_Swtich_Debouncing(SID_m_swt_ENRaw, SID_C_ti_ENSwtOffDeb,
                          SID_C_ti_ENSwtOnDeb, ST_EN_PROCESS,
                          &g_SID_EN_SWT_DEB_B.swtDeb,
                          &g_SID_EN_SWT_DEB_DW.Swtich_Debouncing);

    /* End of Outputs for SubSystem: '<S99>/Swtich_Debouncing' */

    /* SignalConversion: '<S99>/TmpSignal ConversionAtSwtich_DebouncingOutport1' */
    SID_m_swt_ENDeb = g_SID_EN_SWT_DEB_B.swtDeb;
}

/* Initial conditions for atomic system: '<S3>/ExcDrvFault_SWT_DEB' */
void SID_ExcDrvFault_SWT_DEB_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S100>/Swtich_Debouncing' */
    SID_Swtich_Debouncing_Init(&g_SID_ExcDrvFault_SWT_DEB_B.swtDeb);

    /* End of InitializeConditions for SubSystem: '<S100>/Swtich_Debouncing' */
}

/* Output and update for atomic system: '<S3>/ExcDrvFault_SWT_DEB' */
void SID_ExcDrvFault_SWT_DEB(void)
{
    /* Outputs for Atomic SubSystem: '<S100>/Swtich_Debouncing' */

    /* Inport: '<Root>/SID_m_swt_ExcDrvFaultRaw' incorporates:
     *  Constant: '<S100>/Constant1'
     *  Constant: '<S100>/Constant4'
     *  Constant: '<S100>/Constant8'
     *
     * Block description for '<S100>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S100>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S100>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    SID_Swtich_Debouncing(SID_m_swt_ExcDrvFaultRaw,
                          SID_C_ti_ExcDrvFaultSwtOffDeb,
                          SID_C_ti_ExcDrvFaultSwtOnDeb, ST_EXCDRVFAULT_PROCESS,
                          &g_SID_ExcDrvFault_SWT_DEB_B.swtDeb,
                          &g_SID_ExcDrvFault_SWT_DEB_DW.Swtich_Debouncing);

    /* End of Outputs for SubSystem: '<S100>/Swtich_Debouncing' */

    /* SignalConversion: '<S100>/TmpSignal ConversionAtSwtich_DebouncingOutport1' */
    SID_m_swt_ExcDrvFaultDeb = g_SID_ExcDrvFault_SWT_DEB_B.swtDeb;
}

/* Initial conditions for atomic system: '<S3>/IGN_SWT_DEB' */
void SID_IGN_SWT_DEB_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S101>/Swtich_Debouncing' */
    SID_Swtich_Debouncing_Init(&g_SID_IGN_SWT_DEB_B.swtDeb);

    /* End of InitializeConditions for SubSystem: '<S101>/Swtich_Debouncing' */
}

/* Output and update for atomic system: '<S3>/IGN_SWT_DEB' */
void SID_IGN_SWT_DEB(void)
{
    /* Outputs for Atomic SubSystem: '<S101>/Swtich_Debouncing' */

    /* Inport: '<Root>/SID_m_swt_IGNRaw' incorporates:
     *  Constant: '<S101>/Constant1'
     *  Constant: '<S101>/Constant4'
     *  Constant: '<S101>/Constant8'
     *
     * Block description for '<S101>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S101>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S101>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    SID_Swtich_Debouncing(SID_m_swt_IGNRaw, SID_C_ti_IGNSwtOffDeb,
                          SID_C_ti_IGNSwtOnDeb, ST_IGN_PROCESS,
                          &g_SID_IGN_SWT_DEB_B.swtDeb,
                          &g_SID_IGN_SWT_DEB_DW.Swtich_Debouncing);

    /* End of Outputs for SubSystem: '<S101>/Swtich_Debouncing' */

    /* SignalConversion: '<S101>/TmpSignal ConversionAtSwtich_DebouncingOutport1' */
    SID_m_swt_IGNDeb = g_SID_IGN_SWT_DEB_B.swtDeb;
}

/* Initial conditions for atomic system: '<S3>/PhaDrvFault_SWT_DEB' */
void SID_PhaDrvFault_SWT_DEB_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S102>/Swtich_Debouncing' */
    SID_Swtich_Debouncing_Init(&g_SID_PhaDrvFault_SWT_DEB_B.swtDeb);

    /* End of InitializeConditions for SubSystem: '<S102>/Swtich_Debouncing' */
}

/* Output and update for atomic system: '<S3>/PhaDrvFault_SWT_DEB' */
void SID_PhaDrvFault_SWT_DEB(void)
{
    /* Outputs for Atomic SubSystem: '<S102>/Swtich_Debouncing' */

    /* Inport: '<Root>/SID_m_swt_PhaDrvFaultRaw' incorporates:
     *  Constant: '<S102>/Constant1'
     *  Constant: '<S102>/Constant4'
     *  Constant: '<S102>/Constant8'
     *
     * Block description for '<S102>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S102>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S102>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    SID_Swtich_Debouncing(SID_m_swt_PhaDrvFaultRaw,
                          SID_C_ti_PhaDrvFaultSwtOffDeb,
                          SID_C_ti_PhaDrvFaultSwtOnDeb, ST_PHADRVFAULT_PROCESS,
                          &g_SID_PhaDrvFault_SWT_DEB_B.swtDeb,
                          &g_SID_PhaDrvFault_SWT_DEB_DW.Swtich_Debouncing);

    /* End of Outputs for SubSystem: '<S102>/Swtich_Debouncing' */

    /* SignalConversion: '<S102>/TmpSignal ConversionAtSwtich_DebouncingOutport1' */
    SID_m_swt_PhaDrvFaultDeb = g_SID_PhaDrvFault_SWT_DEB_B.swtDeb;
}

/* Initial conditions for atomic system: '<S3>/ReslvDOS_SWT_DEB' */
void SID_ReslvDOS_SWT_DEB_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S103>/Swtich_Debouncing' */
    SID_Swtich_Debouncing_Init(&g_SID_ReslvDOS_SWT_DEB_B.swtDeb);

    /* End of InitializeConditions for SubSystem: '<S103>/Swtich_Debouncing' */
}

/* Output and update for atomic system: '<S3>/ReslvDOS_SWT_DEB' */
void SID_ReslvDOS_SWT_DEB(void)
{
    /* Outputs for Atomic SubSystem: '<S103>/Swtich_Debouncing' */

    /* Inport: '<Root>/SID_m_swt_RslvDOSRaw' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Constant: '<S103>/Constant4'
     *  Constant: '<S103>/Constant8'
     *
     * Block description for '<S103>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S103>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S103>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    SID_Swtich_Debouncing(SID_m_swt_RslvDOSRaw, SID_C_ti_RslvDOSSwtOffDeb,
                          SID_C_ti_RslvDOSSwtOnDeb, ST_RSLVDOS_PROCESS,
                          &g_SID_ReslvDOS_SWT_DEB_B.swtDeb,
                          &g_SID_ReslvDOS_SWT_DEB_DW.Swtich_Debouncing);

    /* End of Outputs for SubSystem: '<S103>/Swtich_Debouncing' */

    /* SignalConversion: '<S103>/TmpSignal ConversionAtSwtich_DebouncingOutport1' */
    SID_m_swt_RslvDOSDeb = g_SID_ReslvDOS_SWT_DEB_B.swtDeb;
}

/* Initial conditions for atomic system: '<S3>/RslvLOT_SWT_DEB' */
void SID_RslvLOT_SWT_DEB_Init(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S104>/Swtich_Debouncing' */
    SID_Swtich_Debouncing_Init(&g_SID_RslvLOT_SWT_DEB_B.swtDeb);

    /* End of InitializeConditions for SubSystem: '<S104>/Swtich_Debouncing' */
}

/* Output and update for atomic system: '<S3>/RslvLOT_SWT_DEB' */
void SID_RslvLOT_SWT_DEB(void)
{
    /* Outputs for Atomic SubSystem: '<S104>/Swtich_Debouncing' */

    /* Inport: '<Root>/SID_m_swt_RslvLOTRaw' incorporates:
     *  Constant: '<S104>/Constant1'
     *  Constant: '<S104>/Constant4'
     *  Constant: '<S104>/Constant8'
     *
     * Block description for '<S104>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S104>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S104>/Constant8':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    SID_Swtich_Debouncing(SID_m_swt_RslvLOTRaw, SID_C_ti_RslvLOTSwtOffDeb,
                          SID_C_ti_RslvLOTSwtOnDeb, ST_RSLVLOT_PROCESS,
                          &g_SID_RslvLOT_SWT_DEB_B.swtDeb,
                          &g_SID_RslvLOT_SWT_DEB_DW.Swtich_Debouncing);

    /* End of Outputs for SubSystem: '<S104>/Swtich_Debouncing' */

    /* SignalConversion: '<S104>/TmpSignal ConversionAtSwtich_DebouncingOutport1' */
    SID_m_swt_RslvLOTDeb = g_SID_RslvLOT_SWT_DEB_B.swtDeb;
}

/* Model step function */
void SID_step(void)
{
    UInt8 lbo_Switch1_m;
    SInt16 lbo_Switch;
    UInt16 lbo_Switch1;
    SInt32 temp_u0;
    SInt8 temp_tmp;

    /* Outputs for Atomic SubSystem: '<S3>/IGN_SWT_DEB' */
    SID_IGN_SWT_DEB();

    /* End of Outputs for SubSystem: '<S3>/IGN_SWT_DEB' */

    /* Outputs for Atomic SubSystem: '<S3>/EN_SWT_DEB' */
    SID_EN_SWT_DEB();

    /* End of Outputs for SubSystem: '<S3>/EN_SWT_DEB' */

    /* Outputs for Atomic SubSystem: '<S3>/ReslvDOS_SWT_DEB' */
    //SID_ReslvDOS_SWT_DEB();

    /* End of Outputs for SubSystem: '<S3>/ReslvDOS_SWT_DEB' */

    /* Outputs for Atomic SubSystem: '<S3>/RslvLOT_SWT_DEB' */
    //SID_RslvLOT_SWT_DEB();

    /* End of Outputs for SubSystem: '<S3>/RslvLOT_SWT_DEB' */

    /* Outputs for Atomic SubSystem: '<S3>/PhaDrvFault_SWT_DEB' */
    SID_PhaDrvFault_SWT_DEB();

    /* End of Outputs for SubSystem: '<S3>/PhaDrvFault_SWT_DEB' */

    /* Outputs for Atomic SubSystem: '<S3>/ExcDrvFault_SWT_DEB' */
    SID_ExcDrvFault_SWT_DEB();

    /* End of Outputs for SubSystem: '<S3>/ExcDrvFault_SWT_DEB' */

    /* Outputs for Atomic SubSystem: '<S2>/PwrSply_V48' */
    SID_PwrSply_V48();

    /* End of Outputs for SubSystem: '<S2>/PwrSply_V48' */

    /* Outputs for Atomic SubSystem: '<S2>/PwrSply_V12' */
    SID_PwrSply_V12();

    /* End of Outputs for SubSystem: '<S2>/PwrSply_V12' */

    /* Outputs for Atomic SubSystem: '<S2>/PwrSply_V10' */
    SID_PwrSply_V10();

    /* End of Outputs for SubSystem: '<S2>/PwrSply_V10' */

    /* Outputs for Atomic SubSystem: '<S2>/PwrSply_V5' */
    SID_PwrSply_V5();

    /* End of Outputs for SubSystem: '<S2>/PwrSply_V5' */

    /* Outputs for Atomic SubSystem: '<S2>/Velocity' */
    SID_Velocity();

    /* End of Outputs for SubSystem: '<S2>/Velocity' */

    /* Outputs for Atomic SubSystem: '<S2>/CurExc' */
    SID_CurExc();

    /* End of Outputs for SubSystem: '<S2>/CurExc' */

    /* Outputs for Atomic SubSystem: '<S2>/TempPU' */
    SID_TempPU();

    /* End of Outputs for SubSystem: '<S2>/TempPU' */

    /* Outputs for Atomic SubSystem: '<S2>/TempPV' */
    SID_TempPV();

    /* End of Outputs for SubSystem: '<S2>/TempPV' */

    /* Outputs for Atomic SubSystem: '<S2>/TempPW' */
    SID_TempPW();

    /* End of Outputs for SubSystem: '<S2>/TempPW' */

    /* Outputs for Atomic SubSystem: '<S2>/TempStator' */
    SID_TempStator();

    /* End of Outputs for SubSystem: '<S2>/TempStator' */

    /* Outputs for Atomic SubSystem: '<S2>/TempShell' */
    SID_TempShell();

    /* End of Outputs for SubSystem: '<S2>/TempShell' */

    /* Outputs for Atomic SubSystem: '<S2>/TempExc' */
    SID_TempExc();

    /* End of Outputs for SubSystem: '<S2>/TempExc' */

    /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
     *  Constant: '<S9>/Constant1'
     *  Inport: '<Root>/ModReq'
     *
     * Block description for '<S9>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    CAN_m_st_ModReqOverTime = (CAN_m_ct_ModReq == 255);

    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S9>/Constant2'
     *  Inport: '<Root>/ModReq'
     *
     * Block description for '<S9>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_st_ModReqOverTime)
    {
        CAN_m_st_ModReq = 1U;
    }
    else
    {
        CAN_m_st_ModReq = CAN_m_ct_ModReq;
    }

    /* End of Switch: '<S9>/Switch' */

    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S14>/Constant2'
     *  Constant: '<S14>/Constant4'
     *  Inport: '<Root>/TrqReq'
     *  Product: '<S14>/Product'
     *  RelationalOperator: '<S14>/Relational Operator'
     *  Sum: '<S14>/Add'
     *
     * Block description for '<S14>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S14>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S14>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_ct_TrqReq == 255)
    {
        lbo_Switch1_m = 0U;
    }
    else
    {
        lbo_Switch1_m = (UInt8)((CAN_m_ct_TrqReq >> 1) - 44);
    }

    /* End of Switch: '<S14>/Switch' */

    /* Saturate: '<S14>/Saturation' */
    temp_u0 = lbo_Switch1_m << 16;
    if (temp_u0 <= 3604480)
    {
        CAN_m_trq_TrqReq = temp_u0;
    }
    else
    {
        CAN_m_trq_TrqReq = 3604480;
    }

    /* End of Saturate: '<S14>/Saturation' */

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Inport: '<Root>/PosTrqGradReq'
     *  RelationalOperator: '<S12>/Relational Operator1'
     *
     * Block description for '<S12>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_ct_PosTrqGradReq == 65535)
    {
        /* Saturate: '<S12>/Saturation' incorporates:
         *  Constant: '<S12>/Constant2'
         *
         * Block description for '<S12>/Constant2':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        CAN_m_trq_PosTrqGradReq = 100;
    }
    else
    {
        /* Saturate: '<S12>/Saturation' */
        CAN_m_trq_PosTrqGradReq = (UInt8)CAN_m_ct_PosTrqGradReq;
    }

    /* End of Switch: '<S12>/Switch' */

    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Inport: '<Root>/NegTrqGradReq'
     *  RelationalOperator: '<S10>/Relational Operator'
     *
     * Block description for '<S10>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_ct_NegTrqGradReq == 65535)
    {
        /* Saturate: '<S10>/Saturation' incorporates:
         *  Constant: '<S10>/Constant2'
         *
         * Block description for '<S10>/Constant2':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        temp_u0 = -100;
    }
    else
    {
        /* Saturate: '<S10>/Saturation' incorporates:
         *  Constant: '<S10>/Constant4'
         *  Sum: '<S10>/Add'
         *
         * Block description for '<S10>/Constant4':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        temp_u0 = (SInt8)(CAN_m_ct_NegTrqGradReq - 1000);
    }

    /* End of Switch: '<S10>/Switch' */

    /* Saturate: '<S10>/Saturation' */
    if (temp_u0 <= 0)
    {
        CAN_m_trq_NegTrqGradReq = (t_TorquePerSec1)temp_u0;
    }
    else
    {
        CAN_m_trq_NegTrqGradReq = 0;
    }

    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant2'
     *  Inport: '<Root>/PosTrqLimReq'
     *  RelationalOperator: '<S13>/Relational Operator'
     *
     * Block description for '<S13>/Constant1':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S13>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_ct_PosTrqLimReq == 255)
    {
        lbo_Switch1_m = 30U;
    }
    else
    {
        lbo_Switch1_m = CAN_m_ct_PosTrqLimReq;
    }

    /* End of Switch: '<S13>/Switch' */

    /* Saturate: '<S13>/Saturation' */
    temp_u0 = lbo_Switch1_m << 16;
    if (temp_u0 <= 3604480)
    {
        CAN_m_trq_PosTrqLimReq = temp_u0;
    }
    else
    {
        CAN_m_trq_PosTrqLimReq = 3604480;
    }

    /* End of Saturate: '<S13>/Saturation' */

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S11>/Constant3'
     *  Constant: '<S11>/Constant4'
     *  Inport: '<Root>/NegTrqLimReq'
     *  RelationalOperator: '<S11>/Relational Operator1'
     *  Sum: '<S11>/Add'
     *
     * Block description for '<S11>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S11>/Constant3':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S11>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_ct_NegTrqLimReq == 255)
    {
        temp_tmp = -30;
    }
    else
    {
        temp_tmp = (SInt8)(CAN_m_ct_NegTrqLimReq - 44);
    }

    /* End of Switch: '<S11>/Switch' */

    /* Saturate: '<S11>/Saturation' */
    temp_u0 = temp_tmp << 16;
    if (temp_u0 > 0)
    {
        CAN_m_trq_NegTrqLimReq = 0;
    }
    else if (temp_u0 < -2883584)
    {
        CAN_m_trq_NegTrqLimReq = -2883584;
    }
    else
    {
        CAN_m_trq_NegTrqLimReq = temp_u0;
    }

    /* End of Saturate: '<S11>/Saturation' */

    /* Saturate: '<S8>/Saturation' */
    CAN_m_trq_ESATrqLimReq = 0;

    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Inport: '<Root>/ESASpdGradReq'
     *  RelationalOperator: '<S7>/Relational Operator1'
     *
     * Block description for '<S7>/Constant2':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_ct_ESASpdGradReq == 32767)
    {
        lbo_Switch = -2000;
    }
    else
    {
        lbo_Switch = CAN_m_ct_ESASpdGradReq;
    }

    /* End of Switch: '<S7>/Switch' */

    /* Saturate: '<S7>/Saturation' */
    temp_u0 = lbo_Switch << 15;
    if (temp_u0 > 0)
    {
        CAN_m_nps_ESASpdGradReq = 0;
    }
    else if (temp_u0 < -262144000)
    {
        CAN_m_nps_ESASpdGradReq = -262144000;
    }
    else
    {
        CAN_m_nps_ESASpdGradReq = temp_u0;
    }

    /* End of Saturate: '<S7>/Saturation' */

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/Constant4'
     *  Inport: '<Root>/ESAEndSpdReq'
     *  RelationalOperator: '<S6>/Relational Operator1'
     *
     * Block description for '<S6>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_ct_ESAEndSpdReq == 65535)
    {
        /* Saturate: '<S6>/Saturation' incorporates:
         *  Constant: '<S6>/Constant3'
         *
         * Block description for '<S6>/Constant3':
         *  For Constants, Enter name in block in all CAPS
         *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
         */
        CAN_m_n_ESAEndSpdReq = 100;
    }
    else
    {
        /* Saturate: '<S6>/Saturation' */
        CAN_m_n_ESAEndSpdReq = (UInt8)CAN_m_ct_ESAEndSpdReq;
    }

    /* End of Switch: '<S6>/Switch1' */

    /* Switch: '<S5>/Switch1' incorporates:
     *  Constant: '<S5>/Constant3'
     *  Constant: '<S5>/Constant4'
     *  Inport: '<Root>/ESADurMaxReq'
     *  Product: '<S5>/Product'
     *  RelationalOperator: '<S5>/Relational Operator1'
     *
     * Block description for '<S5>/Constant3':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S5>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_ct_ESADurMaxReq == 65535)
    {
        lbo_Switch1 = 1000U;
    }
    else
    {
        lbo_Switch1 = (UInt16)(CAN_m_ct_ESADurMaxReq * 13U >> 7);
    }

    /* End of Switch: '<S5>/Switch1' */

    /* Saturate: '<S5>/Saturation' */
    if (lbo_Switch1 <= 2000)
    {
        CAN_m_ti_ESADurMaxReq = lbo_Switch1;
    }
    else
    {
        CAN_m_ti_ESADurMaxReq = 2000U;
    }

    /* End of Saturate: '<S5>/Saturation' */

    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Constant: '<S4>/Constant4'
     *  Inport: '<Root>/DISExcMaxCurReq'
     *  Product: '<S4>/Product'
     *  RelationalOperator: '<S4>/Relational Operator1'
     *
     * Block description for '<S4>/Constant3':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     *
     * Block description for '<S4>/Constant4':
     *  For Constants, Enter name in block in all CAPS
     *  and specify as a constant in the .dct file.  If done in this fashion, no line label is required and the most efficient code is generated.  Label with a text note the constant value to be used.
     */
    if (CAN_m_ct_DISExcMaxCurReq == 65535)
    {
        lbo_Switch1_m = 2U;
    }
    else
    {
        lbo_Switch1_m = (UInt8)(CAN_m_ct_DISExcMaxCurReq * 13U >> 7);
    }

    /* End of Switch: '<S4>/Switch1' */

    /* Saturate: '<S4>/Saturation' */
    if ((lbo_Switch1_m << 10) <= 5120)
    {
        if (lbo_Switch1_m > 31)
        {
            CAN_m_i_DISExcMaxCurReq = MAX_int16_T;
        }
        else
        {
            CAN_m_i_DISExcMaxCurReq = (SInt16)(lbo_Switch1_m << 10);
        }
    }
    else
    {
        CAN_m_i_DISExcMaxCurReq = 5120;
    }

    /* End of Saturate: '<S4>/Saturation' */
}

/* Model initialize function */
void SID_initialize(void)
{
    /* InitializeConditions for Atomic SubSystem: '<S3>/IGN_SWT_DEB' */
    SID_IGN_SWT_DEB_Init();

    /* End of InitializeConditions for SubSystem: '<S3>/IGN_SWT_DEB' */

    /* InitializeConditions for Atomic SubSystem: '<S3>/EN_SWT_DEB' */
    SID_EN_SWT_DEB_Init();

    /* End of InitializeConditions for SubSystem: '<S3>/EN_SWT_DEB' */

    /* InitializeConditions for Atomic SubSystem: '<S3>/ReslvDOS_SWT_DEB' */
    SID_ReslvDOS_SWT_DEB_Init();

    /* End of InitializeConditions for SubSystem: '<S3>/ReslvDOS_SWT_DEB' */

    /* InitializeConditions for Atomic SubSystem: '<S3>/RslvLOT_SWT_DEB' */
    SID_RslvLOT_SWT_DEB_Init();

    /* End of InitializeConditions for SubSystem: '<S3>/RslvLOT_SWT_DEB' */

    /* InitializeConditions for Atomic SubSystem: '<S3>/PhaDrvFault_SWT_DEB' */
    SID_PhaDrvFault_SWT_DEB_Init();

    /* End of InitializeConditions for SubSystem: '<S3>/PhaDrvFault_SWT_DEB' */

    /* InitializeConditions for Atomic SubSystem: '<S3>/ExcDrvFault_SWT_DEB' */
    SID_ExcDrvFault_SWT_DEB_Init();

    /* End of InitializeConditions for SubSystem: '<S3>/ExcDrvFault_SWT_DEB' */

    /* InitializeConditions for Atomic SubSystem: '<S2>/TempPU' */
    SID_TempPU_Init();

    /* End of InitializeConditions for SubSystem: '<S2>/TempPU' */

    /* InitializeConditions for Atomic SubSystem: '<S2>/TempPV' */
    SID_TempPV_Init();

    /* End of InitializeConditions for SubSystem: '<S2>/TempPV' */

    /* InitializeConditions for Atomic SubSystem: '<S2>/TempPW' */
    SID_TempPW_Init();

    /* End of InitializeConditions for SubSystem: '<S2>/TempPW' */

    /* InitializeConditions for Atomic SubSystem: '<S2>/TempStator' */
    SID_TempStator_Init();

    /* End of InitializeConditions for SubSystem: '<S2>/TempStator' */

    /* InitializeConditions for Atomic SubSystem: '<S2>/TempShell' */
    SID_TempShell_Init();

    /* End of InitializeConditions for SubSystem: '<S2>/TempShell' */

    /* InitializeConditions for Atomic SubSystem: '<S2>/TempExc' */
    SID_TempExc_Init();

    /* End of InitializeConditions for SubSystem: '<S2>/TempExc' */
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
