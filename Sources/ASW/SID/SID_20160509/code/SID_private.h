/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID >
 *
 *  File: SID_private.h
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
#ifndef RTW_HEADER_SID_private_h_
#define RTW_HEADER_SID_private_h_
#include "rtwtypes.h"

/*****************************************************************************
 *  Defines
 *****************************************************************************/
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/*****************************************************************************
 *  Data Types
 *****************************************************************************/

/*****************************************************************************
 *  Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Declarations
 *****************************************************************************/

/* Imported (extern) block signals */
extern UInt8 CAN_m_ct_ModReq;          /* '<Root>/ModReq' */
extern UInt8 CAN_m_ct_TrqReq;          /* '<Root>/TrqReq' */
extern UInt16 CAN_m_ct_PosTrqGradReq;  /* '<Root>/PosTrqGradReq' */
extern UInt16 CAN_m_ct_NegTrqGradReq;  /* '<Root>/NegTrqGradReq' */
extern UInt8 CAN_m_ct_PosTrqLimReq;    /* '<Root>/PosTrqLimReq' */
extern UInt8 CAN_m_ct_NegTrqLimReq;    /* '<Root>/NegTrqLimReq' */
extern SInt16 CAN_m_ct_ESATrqLimReq;   /* '<Root>/ESATrqLimReq' */
extern SInt16 CAN_m_ct_ESASpdGradReq;  /* '<Root>/ESASpdGradReq' */
extern UInt16 CAN_m_ct_ESAEndSpdReq;   /* '<Root>/ESAEndSpdReq' */
extern UInt16 CAN_m_ct_ESADurMaxReq;   /* '<Root>/ESADurMaxReq' */
extern UInt16 CAN_m_ct_DISExcMaxCurReq;/* '<Root>/DISExcMaxCurReq' */
extern UInt16 SID_m_ct_V48Raw;         /* '<Root>/SID_m_ct_V48Raw' */
extern UInt16 SID_m_ct_V12Raw;         /* '<Root>/SID_m_ct_V12Raw' */
extern UInt16 SID_m_ct_V10Raw;         /* '<Root>/SID_m_ct_V10Raw' */
extern UInt16 SID_m_ct_V5Raw;          /* '<Root>/SID_m_ct_V5Raw' */
extern SInt16 SID_m_ct_VelocityRaw;    /* '<Root>/SID_m_ct_VelocityRaw' */
extern UInt16 SID_m_ct_CurExcRaw;      /* '<Root>/SID_m_ct_CurExcRaw' */
extern UInt16 SID_m_ct_TempPURaw;      /* '<Root>/SID_m_ct_TempPURaw' */
extern UInt16 SID_m_ct_TempPVRaw;      /* '<Root>/SID_m_ct_TempPVRaw' */
extern UInt16 SID_m_ct_TempPWRaw;      /* '<Root>/SID_m_ct_TempPWRaw' */
extern UInt16 SID_m_ct_TempShellRaw;   /* '<Root>/SID_m_ct_TempShellRaw' */
extern UInt16 SID_m_ct_TempExcRaw;     /* '<Root>/SID_m_ct_TempExcRaw' */
extern UInt8 SID_m_swt_IGNRaw;         /* '<Root>/SID_m_swt_IGNRaw' */
extern UInt8 SID_m_swt_ENRaw;          /* '<Root>/SID_m_swt_ENRaw' */
extern UInt8 SID_m_swt_RslvDOSRaw;     /* '<Root>/SID_m_swt_RslvDOSRaw' */
extern UInt8 SID_m_swt_RslvLOTRaw;     /* '<Root>/SID_m_swt_RslvLOTRaw' */
extern UInt8 SID_m_swt_PhaDrvFaultRaw; /* '<Root>/SID_m_swt_PhaDrvFaultRaw' */
extern UInt8 SID_m_swt_ExcDrvFaultRaw; /* '<Root>/SID_m_swt_ExcDrvFaultRaw' */
extern void SID_GradientLmt(t_Pressure4 rtu_Signal_Raw, t_Pressure4
    rtu_Signal_Delay, t_Pressure4 *rty_Signal_Out);
extern void SID_CurExc(void);
extern void SID_PwrSply_V10(void);
extern void SID_PwrSply_V12(void);
extern void SID_PwrSply_V48(void);
extern void SID_PwrSply_V5(void);
extern void SID_TempExc_Init(void);
extern void SID_TempExc(void);
extern void SID_TempPU_Init(void);
extern void SID_TempPU(void);
extern void SID_TempPV_Init(void);
extern void SID_TempPV(void);
extern void SID_TempPW_Init(void);
extern void SID_TempPW(void);
extern void SID_TempShell_Init(void);
extern void SID_TempShell(void);
extern void SID_TempStator_Init(void);
extern void SID_TempStator(void);
extern void SID_Velocity(void);
extern void SID_EN_SWT_DEB_Init(void);
extern void SID_EN_SWT_DEB(void);
extern void SID_ExcDrvFault_SWT_DEB_Init(void);
extern void SID_ExcDrvFault_SWT_DEB(void);
extern void SID_IGN_SWT_DEB_Init(void);
extern void SID_IGN_SWT_DEB(void);
extern void SID_PhaDrvFault_SWT_DEB_Init(void);
extern void SID_PhaDrvFault_SWT_DEB(void);
extern void SID_ReslvDOS_SWT_DEB_Init(void);
extern void SID_ReslvDOS_SWT_DEB(void);
extern void SID_RslvLOT_SWT_DEB_Init(void);
extern void SID_RslvLOT_SWT_DEB(void);

/*****************************************************************************
 *  Global Function Declaration
 *****************************************************************************/
#endif                                 /* RTW_HEADER_SID_private_h_ */

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
