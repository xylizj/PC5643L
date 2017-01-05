/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: SID.h
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
 *  Include files
 ******************************************************************************/
#ifndef RTW_HEADER_SID_h_
#define RTW_HEADER_SID_h_
#include <stddef.h>
#ifndef SID_COMMON_INCLUDES_
# define SID_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "SetErr.h"
#endif                                 /* SID_COMMON_INCLUDES_ */

#include "SID_types.h"

/* Child system includes */
#include "Eureka_Lib.h"

/* Includes for objects with custom storage classes. */
#include "SID_MCData.h"
#include "Eureka_Macro.h"
#include "LookUp_S16_S16_SAT.h"
#include "div_nzp_s32_floor.h"
#include "mul_s32_s32_s32_sr30.h"

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

/* Block signals for system '<S2>/TempExc' */
typedef struct
{
    UInt8 SRC_Def_Status;            /* '<S35>/SRC_Check' */
    Boolean SRC_Tmp_Def_Flag;        /* '<S35>/SRC_Check' */
}
t_SID_rtB_TempExc;

/* Block states (auto storage) for system '<S2>/TempExc' */
typedef struct
{
    struct
    {
        UInt32 is_c9_SID:2;            /* '<S28>/SignalGradientLimit' */
        UInt32 is_active_c9_SID:1;     /* '<S28>/SignalGradientLimit' */
    }
    bitsForTID0;

    t_Temp3 UnitDelay1_DSTATE;         /* '<S28>/Unit Delay1' */
    SInt16 Signal_Tmp;                /* '<S28>/SignalGradientLimit' */
    Boolean UnitDelay_DSTATE;        /* '<S34>/Unit Delay' */
    Boolean UnitDelay_DSTATE_a;        /* '<S33>/Unit Delay' */
    Boolean Check_Level_MODE;        /* '<S30>/Check_Level' */
    t_SID_rtDW_SRC_Check SRC_Check;    /* '<S31>/SRC_Check' */
}
t_SID_rtDW_TempExc;

/* Block signals for system '<S2>/TempPU' */
typedef struct
{
    t_Pressure4 Signal_Raw;            /* '<S40>/SignalGradientLimit' */
    t_Pressure4 Signal_Delay;          /* '<S40>/SignalGradientLimit' */
    t_Pressure4 DifferenceInputs2;     /* '<S50>/Difference Inputs2' */
    UInt8 SRC_Def_Status;            /* '<S47>/SRC_Check' */
    Boolean SRC_Tmp_Def_Flag;        /* '<S47>/SRC_Check' */
}
t_SID_rtB_TempPU;

/* Block states (auto storage) for system '<S2>/TempPU' */
typedef struct
{
    struct
    {
        UInt32 is_c4_SID:2;            /* '<S40>/SignalGradientLimit' */
        UInt32 is_active_c4_SID:1;     /* '<S40>/SignalGradientLimit' */
    }
    bitsForTID0;

    t_Temp3 UnitDelay1_DSTATE;         /* '<S40>/Unit Delay1' */
    SInt16 Signal_Tmp;                /* '<S40>/SignalGradientLimit' */
    Boolean UnitDelay_DSTATE;        /* '<S46>/Unit Delay' */
    Boolean UnitDelay_DSTATE_m;        /* '<S45>/Unit Delay' */
    Boolean Check_Level_MODE;        /* '<S42>/Check_Level' */
    t_SID_rtDW_SRC_Check SRC_Check;    /* '<S43>/SRC_Check' */
}
t_SID_rtDW_TempPU;

/* Block signals for system '<S2>/TempPV' */
typedef struct
{
    t_Pressure4 Signal_Raw;            /* '<S52>/SignalGradientLimit' */
    t_Pressure4 Signal_Delay;          /* '<S52>/SignalGradientLimit' */
    t_Pressure4 DifferenceInputs2;     /* '<S62>/Difference Inputs2' */
    UInt8 SRC_Def_Status;            /* '<S59>/SRC_Check' */
    Boolean SRC_Tmp_Def_Flag;        /* '<S59>/SRC_Check' */
}
t_SID_rtB_TempPV;

/* Block states (auto storage) for system '<S2>/TempPV' */
typedef struct
{
    struct
    {
        UInt32 is_c1_SID:2;            /* '<S52>/SignalGradientLimit' */
        UInt32 is_active_c1_SID:1;     /* '<S52>/SignalGradientLimit' */
    }
    bitsForTID0;

    t_Temp3 UnitDelay1_DSTATE;         /* '<S52>/Unit Delay1' */
    SInt16 Signal_Tmp;                /* '<S52>/SignalGradientLimit' */
    Boolean UnitDelay_DSTATE;        /* '<S58>/Unit Delay' */
    Boolean UnitDelay_DSTATE_c;        /* '<S57>/Unit Delay' */
    Boolean Check_Level_MODE;        /* '<S54>/Check_Level' */
    t_SID_rtDW_SRC_Check SRC_Check;    /* '<S55>/SRC_Check' */
}
t_SID_rtDW_TempPV;

/* Block signals for system '<S2>/TempPW' */
typedef struct
{
    t_Pressure4 Signal_Raw;            /* '<S64>/SignalGradientLimit' */
    t_Pressure4 Signal_Delay;          /* '<S64>/SignalGradientLimit' */
    t_Pressure4 DifferenceInputs2;     /* '<S74>/Difference Inputs2' */
    UInt8 SRC_Def_Status;            /* '<S71>/SRC_Check' */
    Boolean SRC_Tmp_Def_Flag;        /* '<S71>/SRC_Check' */
}
t_SID_rtB_TempPW;

/* Block states (auto storage) for system '<S2>/TempPW' */
typedef struct
{
    struct
    {
        UInt32 is_c6_SID:2;            /* '<S64>/SignalGradientLimit' */
        UInt32 is_active_c6_SID:1;     /* '<S64>/SignalGradientLimit' */
    }
    bitsForTID0;

    t_Temp3 UnitDelay1_DSTATE;         /* '<S64>/Unit Delay1' */
    SInt16 Signal_Tmp;                /* '<S64>/SignalGradientLimit' */
    Boolean UnitDelay_DSTATE;        /* '<S70>/Unit Delay' */
    Boolean UnitDelay_DSTATE_i;        /* '<S69>/Unit Delay' */
    Boolean Check_Level_MODE;        /* '<S66>/Check_Level' */
    t_SID_rtDW_SRC_Check SRC_Check;    /* '<S67>/SRC_Check' */
}
t_SID_rtDW_TempPW;

/* Block signals for system '<S2>/TempShell' */
typedef struct
{
    UInt8 SRC_Def_Status;            /* '<S83>/SRC_Check' */
    Boolean SRC_Tmp_Def_Flag;        /* '<S83>/SRC_Check' */
}
t_SID_rtB_TempShell;

/* Block states (auto storage) for system '<S2>/TempShell' */
typedef struct
{
    struct
    {
        UInt32 is_c8_SID:2;            /* '<S76>/SignalGradientLimit' */
        UInt32 is_active_c8_SID:1;     /* '<S76>/SignalGradientLimit' */
    }
    bitsForTID0;

    t_Temp3 UnitDelay1_DSTATE;         /* '<S76>/Unit Delay1' */
    SInt16 Signal_Tmp;                /* '<S76>/SignalGradientLimit' */
    Boolean UnitDelay_DSTATE;        /* '<S82>/Unit Delay' */
    Boolean UnitDelay_DSTATE_n;        /* '<S81>/Unit Delay' */
    Boolean Check_Level_MODE;        /* '<S78>/Check_Level' */
    t_SID_rtDW_SRC_Check SRC_Check;    /* '<S79>/SRC_Check' */
}
t_SID_rtDW_TempShell;

/* Block signals for system '<S2>/TempStator' */
typedef struct
{
    UInt8 SRC_Def_Status;            /* '<S95>/SRC_Check' */
    Boolean SRC_Tmp_Def_Flag;        /* '<S95>/SRC_Check' */
}
t_SID_rtB_TempStator;

/* Block states (auto storage) for system '<S2>/TempStator' */
typedef struct
{
    struct
    {
        UInt32 is_c7_SID:2;            /* '<S88>/SignalGradientLimit' */
        UInt32 is_active_c7_SID:1;     /* '<S88>/SignalGradientLimit' */
    }
    bitsForTID0;

    t_Temp3 UnitDelay1_DSTATE;         /* '<S88>/Unit Delay1' */
    SInt16 Signal_Tmp;                /* '<S88>/SignalGradientLimit' */
    Boolean UnitDelay_DSTATE;        /* '<S94>/Unit Delay' */
    Boolean UnitDelay_DSTATE_p;        /* '<S93>/Unit Delay' */
    Boolean Check_Level_MODE;        /* '<S90>/Check_Level' */
    t_SID_rtDW_SRC_Check SRC_Check;    /* '<S91>/SRC_Check' */
}
t_SID_rtDW_TempStator;

/* Block states (auto storage) for system '<S2>/Velocity' */
typedef struct
{
    t_RotSpd1 UnitDelay1_DSTATE;       /* '<S26>/Unit Delay1' */
    t_RotSpd1 UnitDelay2_DSTATE;       /* '<S26>/Unit Delay2' */
    t_RotSpd1 UnitDelay3_DSTATE;       /* '<S26>/Unit Delay3' */
    t_RotSpd1 UnitDelay4_DSTATE;       /* '<S26>/Unit Delay4' */
}
t_SID_rtDW_Velocity;

/* Block signals for system '<S3>/EN_SWT_DEB' */
typedef struct
{
    Boolean swtDeb;                  /* '<S105>/Switch_Debouncing' */
}
t_SID_rtB_EN_SWT_DEB;

/* Block states (auto storage) for system '<S3>/EN_SWT_DEB' */
typedef struct
{
    t_SID_rtDW_Swtich_Debouncing Swtich_Debouncing;/* '<S99>/Swtich_Debouncing' */
}
t_SID_rtDW_EN_SWT_DEB;

/* Block signals for system '<S3>/ExcDrvFault_SWT_DEB' */
typedef struct
{
    Boolean swtDeb;                  /* '<S107>/Switch_Debouncing' */
}
t_SID_rtB_ExcDrvFault_SWT_DEB;

/* Block states (auto storage) for system '<S3>/ExcDrvFault_SWT_DEB' */
typedef struct
{
    t_SID_rtDW_Swtich_Debouncing Swtich_Debouncing;/* '<S100>/Swtich_Debouncing' */
}
t_SID_rtDW_ExcDrvFault_SWT_DEB;

/* Block signals for system '<S3>/IGN_SWT_DEB' */
typedef struct
{
    Boolean swtDeb;                  /* '<S109>/Switch_Debouncing' */
}
t_SID_rtB_IGN_SWT_DEB;

/* Block states (auto storage) for system '<S3>/IGN_SWT_DEB' */
typedef struct
{
    t_SID_rtDW_Swtich_Debouncing Swtich_Debouncing;/* '<S101>/Swtich_Debouncing' */
}
t_SID_rtDW_IGN_SWT_DEB;

/* Block signals for system '<S3>/PhaDrvFault_SWT_DEB' */
typedef struct
{
    Boolean swtDeb;                  /* '<S111>/Switch_Debouncing' */
}
t_SID_rtB_PhaDrvFault_SWT_DEB;

/* Block states (auto storage) for system '<S3>/PhaDrvFault_SWT_DEB' */
typedef struct
{
    t_SID_rtDW_Swtich_Debouncing Swtich_Debouncing;/* '<S102>/Swtich_Debouncing' */
}
t_SID_rtDW_PhaDrvFault_SWT_DEB;

/* Block signals for system '<S3>/ReslvDOS_SWT_DEB' */
typedef struct
{
    Boolean swtDeb;                  /* '<S113>/Switch_Debouncing' */
}
t_SID_rtB_ReslvDOS_SWT_DEB;

/* Block states (auto storage) for system '<S3>/ReslvDOS_SWT_DEB' */
typedef struct
{
    t_SID_rtDW_Swtich_Debouncing Swtich_Debouncing;/* '<S103>/Swtich_Debouncing' */
}
t_SID_rtDW_ReslvDOS_SWT_DEB;

/* Block signals for system '<S3>/RslvLOT_SWT_DEB' */
typedef struct
{
    Boolean swtDeb;                  /* '<S115>/Switch_Debouncing' */
}
t_SID_rtB_RslvLOT_SWT_DEB;

/* Block states (auto storage) for system '<S3>/RslvLOT_SWT_DEB' */
typedef struct
{
    t_SID_rtDW_Swtich_Debouncing Swtich_Debouncing;/* '<S104>/Swtich_Debouncing' */
}
t_SID_rtDW_RslvLOT_SWT_DEB;

/* External inputs (root inport signals with auto storage) */
typedef struct
{
    t_Voltage4 SID_m_ct_TempStatorRaw; /* '<Root>/SID_m_ct_TempStatorRaw' */
}
t_SID_ExternalInputs;

/*****************************************************************************
 *  Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Declarations
 *****************************************************************************/

/* Extern declarations of internal data for system '<S2>/TempExc' */
extern t_SID_rtB_TempExc g_SID_TempExc_B;
extern t_SID_rtDW_TempExc g_SID_TempExc_DW;

/* Extern declarations of internal data for system '<S2>/TempPU' */
extern t_SID_rtB_TempPU g_SID_TempPU_B;
extern t_SID_rtDW_TempPU g_SID_TempPU_DW;

/* Extern declarations of internal data for system '<S2>/TempPV' */
extern t_SID_rtB_TempPV g_SID_TempPV_B;
extern t_SID_rtDW_TempPV g_SID_TempPV_DW;

/* Extern declarations of internal data for system '<S2>/TempPW' */
extern t_SID_rtB_TempPW g_SID_TempPW_B;
extern t_SID_rtDW_TempPW g_SID_TempPW_DW;

/* Extern declarations of internal data for system '<S2>/TempShell' */
extern t_SID_rtB_TempShell g_SID_TempShell_B;
extern t_SID_rtDW_TempShell g_SID_TempShell_DW;

/* Extern declarations of internal data for system '<S2>/TempStator' */
extern t_SID_rtB_TempStator g_SID_TempStator_B;
extern t_SID_rtDW_TempStator g_SID_TempStator_DW;

/* Extern declarations of internal data for system '<S2>/Velocity' */
extern t_SID_rtDW_Velocity g_SID_Velocity_DW;

/* Extern declarations of internal data for system '<S3>/EN_SWT_DEB' */
extern t_SID_rtB_EN_SWT_DEB g_SID_EN_SWT_DEB_B;
extern t_SID_rtDW_EN_SWT_DEB g_SID_EN_SWT_DEB_DW;

/* Extern declarations of internal data for system '<S3>/ExcDrvFault_SWT_DEB' */
extern t_SID_rtB_ExcDrvFault_SWT_DEB g_SID_ExcDrvFault_SWT_DEB_B;
extern t_SID_rtDW_ExcDrvFault_SWT_DEB g_SID_ExcDrvFault_SWT_DEB_DW;

/* Extern declarations of internal data for system '<S3>/IGN_SWT_DEB' */
extern t_SID_rtB_IGN_SWT_DEB g_SID_IGN_SWT_DEB_B;
extern t_SID_rtDW_IGN_SWT_DEB g_SID_IGN_SWT_DEB_DW;

/* Extern declarations of internal data for system '<S3>/PhaDrvFault_SWT_DEB' */
extern t_SID_rtB_PhaDrvFault_SWT_DEB g_SID_PhaDrvFault_SWT_DEB_B;
extern t_SID_rtDW_PhaDrvFault_SWT_DEB g_SID_PhaDrvFault_SWT_DEB_DW;

/* Extern declarations of internal data for system '<S3>/ReslvDOS_SWT_DEB' */
extern t_SID_rtB_ReslvDOS_SWT_DEB g_SID_ReslvDOS_SWT_DEB_B;
extern t_SID_rtDW_ReslvDOS_SWT_DEB g_SID_ReslvDOS_SWT_DEB_DW;

/* Extern declarations of internal data for system '<S3>/RslvLOT_SWT_DEB' */
extern t_SID_rtB_RslvLOT_SWT_DEB g_SID_RslvLOT_SWT_DEB_B;
extern t_SID_rtDW_RslvLOT_SWT_DEB g_SID_RslvLOT_SWT_DEB_DW;

/* External inputs (root inport signals with auto storage) */
extern t_SID_ExternalInputs g_SID_U;

/* Model entry point functions */
extern void SID_initialize(void);
extern void SID_step(void);

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
 * '<Root>' : 'SID'
 * '<S1>'   : 'SID/BUS_SIGNAL'
 * '<S2>'   : 'SID/SENSOR_SIGNAL'
 * '<S3>'   : 'SID/SWITCH'
 * '<S4>'   : 'SID/BUS_SIGNAL/DISExcMaxCurReqConvert'
 * '<S5>'   : 'SID/BUS_SIGNAL/ESADurMaxReqConvert'
 * '<S6>'   : 'SID/BUS_SIGNAL/ESAEndSpdReqConvert'
 * '<S7>'   : 'SID/BUS_SIGNAL/ESASpdGradConvert'
 * '<S8>'   : 'SID/BUS_SIGNAL/ESATrqLimReqConvert'
 * '<S9>'   : 'SID/BUS_SIGNAL/ModReqConvert'
 * '<S10>'  : 'SID/BUS_SIGNAL/NegTrqGradReqConvert'
 * '<S11>'  : 'SID/BUS_SIGNAL/NegTrqLimReqConvert'
 * '<S12>'  : 'SID/BUS_SIGNAL/PosTrqGradReqConvert'
 * '<S13>'  : 'SID/BUS_SIGNAL/PosTrqLimReqConvert'
 * '<S14>'  : 'SID/BUS_SIGNAL/TrqReqConvert'
 * '<S15>'  : 'SID/SENSOR_SIGNAL/CurExc'
 * '<S16>'  : 'SID/SENSOR_SIGNAL/PwrSply_V10'
 * '<S17>'  : 'SID/SENSOR_SIGNAL/PwrSply_V12'
 * '<S18>'  : 'SID/SENSOR_SIGNAL/PwrSply_V48'
 * '<S19>'  : 'SID/SENSOR_SIGNAL/PwrSply_V5'
 * '<S20>'  : 'SID/SENSOR_SIGNAL/TempExc'
 * '<S21>'  : 'SID/SENSOR_SIGNAL/TempPU'
 * '<S22>'  : 'SID/SENSOR_SIGNAL/TempPV'
 * '<S23>'  : 'SID/SENSOR_SIGNAL/TempPW'
 * '<S24>'  : 'SID/SENSOR_SIGNAL/TempShell'
 * '<S25>'  : 'SID/SENSOR_SIGNAL/TempStator'
 * '<S26>'  : 'SID/SENSOR_SIGNAL/Velocity'
 * '<S27>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Check'
 * '<S28>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Evaluation'
 * '<S29>'  : 'SID/SENSOR_SIGNAL/TempExc/TempExc_Convert'
 * '<S30>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Check/Err_process'
 * '<S31>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Check/Signal_deb'
 * '<S32>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Check/Err_process/Check_Level'
 * '<S33>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Check/Err_process/Check_Level/RelayDynamic'
 * '<S34>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Check/Err_process/Check_Level/RelayDynamic1'
 * '<S35>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Check/Signal_deb/SRC_Check'
 * '<S36>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Check/Signal_deb/SRC_Check/SRC_Check'
 * '<S37>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Evaluation/SignalGradientLimit'
 * '<S38>'  : 'SID/SENSOR_SIGNAL/TempExc/Signal_Evaluation/SignalGradientLimit/GradientLmt'
 * '<S39>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Check'
 * '<S40>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Evaluation'
 * '<S41>'  : 'SID/SENSOR_SIGNAL/TempPU/TempPU_Convert'
 * '<S42>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Check/Err_process'
 * '<S43>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Check/Signal_deb'
 * '<S44>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Check/Err_process/Check_Level'
 * '<S45>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Check/Err_process/Check_Level/RelayDynamic'
 * '<S46>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Check/Err_process/Check_Level/RelayDynamic1'
 * '<S47>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Check/Signal_deb/SRC_Check'
 * '<S48>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Check/Signal_deb/SRC_Check/SRC_Check'
 * '<S49>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Evaluation/SignalGradientLimit'
 * '<S50>'  : 'SID/SENSOR_SIGNAL/TempPU/Signal_Evaluation/SignalGradientLimit/GradientLmt'
 * '<S51>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Check'
 * '<S52>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Evaluation'
 * '<S53>'  : 'SID/SENSOR_SIGNAL/TempPV/TempPV_Convert'
 * '<S54>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Check/Err_process'
 * '<S55>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Check/Signal_deb'
 * '<S56>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Check/Err_process/Check_Level'
 * '<S57>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Check/Err_process/Check_Level/RelayDynamic'
 * '<S58>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Check/Err_process/Check_Level/RelayDynamic1'
 * '<S59>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Check/Signal_deb/SRC_Check'
 * '<S60>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Check/Signal_deb/SRC_Check/SRC_Check'
 * '<S61>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Evaluation/SignalGradientLimit'
 * '<S62>'  : 'SID/SENSOR_SIGNAL/TempPV/Signal_Evaluation/SignalGradientLimit/GradientLmt'
 * '<S63>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Check'
 * '<S64>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Evaluation'
 * '<S65>'  : 'SID/SENSOR_SIGNAL/TempPW/TempPW_Convert'
 * '<S66>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Check/Err_process'
 * '<S67>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Check/Signal_deb'
 * '<S68>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Check/Err_process/Check_Level'
 * '<S69>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Check/Err_process/Check_Level/RelayDynamic'
 * '<S70>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Check/Err_process/Check_Level/RelayDynamic1'
 * '<S71>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Check/Signal_deb/SRC_Check'
 * '<S72>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Check/Signal_deb/SRC_Check/SRC_Check'
 * '<S73>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Evaluation/SignalGradientLimit'
 * '<S74>'  : 'SID/SENSOR_SIGNAL/TempPW/Signal_Evaluation/SignalGradientLimit/GradientLmt'
 * '<S75>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Check'
 * '<S76>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Evaluation'
 * '<S77>'  : 'SID/SENSOR_SIGNAL/TempShell/TempShell_Convert'
 * '<S78>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Check/Err_process'
 * '<S79>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Check/Signal_deb'
 * '<S80>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Check/Err_process/Check_Level'
 * '<S81>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Check/Err_process/Check_Level/RelayDynamic'
 * '<S82>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Check/Err_process/Check_Level/RelayDynamic1'
 * '<S83>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Check/Signal_deb/SRC_Check'
 * '<S84>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Check/Signal_deb/SRC_Check/SRC_Check'
 * '<S85>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Evaluation/SignalGradientLimit'
 * '<S86>'  : 'SID/SENSOR_SIGNAL/TempShell/Signal_Evaluation/SignalGradientLimit/GradientLmt'
 * '<S87>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Check'
 * '<S88>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Evaluation'
 * '<S89>'  : 'SID/SENSOR_SIGNAL/TempStator/TempStator_Convert'
 * '<S90>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Check/Err_process'
 * '<S91>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Check/Signal_deb'
 * '<S92>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Check/Err_process/Check_Level'
 * '<S93>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Check/Err_process/Check_Level/RelayDynamic'
 * '<S94>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Check/Err_process/Check_Level/RelayDynamic1'
 * '<S95>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Check/Signal_deb/SRC_Check'
 * '<S96>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Check/Signal_deb/SRC_Check/SRC_Check'
 * '<S97>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Evaluation/SignalGradientLimit'
 * '<S98>'  : 'SID/SENSOR_SIGNAL/TempStator/Signal_Evaluation/SignalGradientLimit/GradientLmt'
 * '<S99>'  : 'SID/SWITCH/EN_SWT_DEB'
 * '<S100>' : 'SID/SWITCH/ExcDrvFault_SWT_DEB'
 * '<S101>' : 'SID/SWITCH/IGN_SWT_DEB'
 * '<S102>' : 'SID/SWITCH/PhaDrvFault_SWT_DEB'
 * '<S103>' : 'SID/SWITCH/ReslvDOS_SWT_DEB'
 * '<S104>' : 'SID/SWITCH/RslvLOT_SWT_DEB'
 * '<S105>' : 'SID/SWITCH/EN_SWT_DEB/Swtich_Debouncing'
 * '<S106>' : 'SID/SWITCH/EN_SWT_DEB/Swtich_Debouncing/Switch_Debouncing'
 * '<S107>' : 'SID/SWITCH/ExcDrvFault_SWT_DEB/Swtich_Debouncing'
 * '<S108>' : 'SID/SWITCH/ExcDrvFault_SWT_DEB/Swtich_Debouncing/Switch_Debouncing'
 * '<S109>' : 'SID/SWITCH/IGN_SWT_DEB/Swtich_Debouncing'
 * '<S110>' : 'SID/SWITCH/IGN_SWT_DEB/Swtich_Debouncing/Switch_Debouncing'
 * '<S111>' : 'SID/SWITCH/PhaDrvFault_SWT_DEB/Swtich_Debouncing'
 * '<S112>' : 'SID/SWITCH/PhaDrvFault_SWT_DEB/Swtich_Debouncing/Switch_Debouncing'
 * '<S113>' : 'SID/SWITCH/ReslvDOS_SWT_DEB/Swtich_Debouncing'
 * '<S114>' : 'SID/SWITCH/ReslvDOS_SWT_DEB/Swtich_Debouncing/Switch_Debouncing'
 * '<S115>' : 'SID/SWITCH/RslvLOT_SWT_DEB/Swtich_Debouncing'
 * '<S116>' : 'SID/SWITCH/RslvLOT_SWT_DEB/Swtich_Debouncing/Switch_Debouncing'
 */
#endif                                 /* RTW_HEADER_SID_h_ */

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
