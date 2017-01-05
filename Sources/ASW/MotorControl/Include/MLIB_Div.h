/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*
******************************************************************************/
/*!
*
* @file       MLIB_Div.h
*
* @version    1.0.50.0
*
* @date       Nov-9-2015
*
* @brief      Header file for MLIB_Div function
*
******************************************************************************/
#ifndef MLIB_DIV_H
#define MLIB_DIV_H
/*!
@if MLIB_GROUP
    @addtogroup MLIB_GROUP
@else
    @defgroup MLIB_GROUP   MLIB
@endif
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section MLIB_Div_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section MLIB_Div_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section MLIB_Div_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section MLIB_Div_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*
* @section MLIB_Div_h_REF_5
* Violates MISRA 2004 Required Rule 8.5, Object/function definition in header file.
* Allowing the inline functions significantly increase the speed of the library thus the lowest
* layer (MLIB) is implemented as inline. This approach removes the overhead caused by standard
* function calling.
*
* @section MLIB_Div_h_REF_6
* Violates MISRA 2004 Required Rule 12.7, Bitwise operator applied to signed underlying type.
* The fractional arithmetic requires the bit-wise operations on signed values.
*/
#include "SWLIBS_Defines.h"
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_ShL.h"
  #include "MLIB_ShLSat.h"
  #include "MLIB_ShR.h"
  #include "MLIB_AbsSat.h"
  #include "MLIB_Norm.h"
#else
  /* Following includes serve for Freescale internal testing purposes only.
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_ShL.h"
  #include "CCOV_MLIB_ShLSat.h"
  #include "CCOV_MLIB_ShR.h"
  #include "CCOV_MLIB_AbsSat.h"
  #include "CCOV_MLIB_Norm.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  /*
  * @violates @ref MLIB_Div_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
  * @violates @ref MLIB_Div_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_Div_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter
  * in definition of macro.
  */
  #define MLIB_Div(...)     macro_dispatcher(MLIB_Div, __VA_ARGS__)(__VA_ARGS__)     /*!< This function divides the first parameter by the second one. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref MLIB_Div_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_Div_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_Div_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00119 */
    #define MLIB_Div_Dsptchr_2(In1,In2)     MLIB_Div_Dsptchr_3(In1,In2,F32)       /*!< Function dispatcher for MLIB_Div_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref MLIB_Div_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_Div_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_Div_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00119 */
    #define MLIB_Div_Dsptchr_2(In1,In2)     MLIB_Div_Dsptchr_3(In1,In2,F16)       /*!< Function dispatcher for MLIB_Div_Dsptchr_2, do not modify!!! */
  #endif
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /*
    * @violates @ref MLIB_Div_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_Div_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_Div_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00119 */
    #define MLIB_Div_Dsptchr_2(In1,In2)     MLIB_Div_Dsptchr_3(In1,In2,FLT)       /*!< Function dispatcher for MLIB_Div_Dsptchr_2, do not modify!!! */
  #endif
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  /*
  * @violates @ref MLIB_Div_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
  * @violates @ref MLIB_Div_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_Div_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter
  * in definition of macro.
  */
  #define MLIB_Div_Dsptchr_3(In1,In2,Impl)    MLIB_Div_Dsptchr_(In1,In2,Impl)     /*!< Function dispatcher for MLIB_Div_Dsptchr_3, do not modify!!! */

  /*
  * @violates @ref MLIB_Div_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
  * @violates @ref MLIB_Div_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_Div_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter
  * in definition of macro.
  * @violates @ref MLIB_Div_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
  */
  /** @remarks Implements DMLIB00121 */
  #define MLIB_Div_Dsptchr_(In1,In2,Impl)     MLIB_Div_##Impl(In1,In2)            /*!< Function dispatcher for MLIB_Div_Dsptchr_, do not modify!!! */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/
static inline tFrac32 Div_F32_C(register tFrac32 f32In1, register tFrac32 f32In2)
/*
* @violates @ref MLIB_Div_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Div_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
  * header file.
  */
  register tFrac32 f32Return;
  /*
  * @violates @ref MLIB_Div_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
  * header file.
  */
  register tU16 u16i=(tU16)0U;

  if (f32In2 == (tFrac32)0){
    f32Return = (f32In1 > (tFrac32)0) ? INT32TOF32(INT32_MAX) : INT32TOF32(INT32_MIN);
  }else{
    /* Only the f32In1 < f32In2 case is handled with normalisation, as for the f32In1 <= f32In2 the output is undefined */
    /* Normalize the input values to get the max. precision */
    u16i = MLIB_Norm_F32(f32In2);
    /* Shift left the input values to get the best precision */
    f32In1 = MLIB_ShL_F32(f32In1,u16i);
    f32In2 = MLIB_ShL_F32(f32In2,u16i);

    /*
    * @violates @ref MLIB_Div_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
    * signed underlying type (>>).
    */
    f32Return = INT32TOF32(F32TOINT32(f32In1)/F32TOINT32(f32In2>>(tU16)16));
    f32Return = MLIB_ShLSat_F32(f32Return,(tU16)15);
  }
  return(f32Return);
}


static inline tFrac16 Div_F16_C(register tFrac16 f16In1, register tFrac16 f16In2)
/*
* @violates @ref MLIB_Div_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Div_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
  * header file.
  */
  register tFrac16 f16Return;

  if (f16In2 == (tFrac16)0){
    f16Return = (f16In1 > (tFrac16)0) ? INT16TOF16(INT16_MAX) : INT16TOF16(INT16_MIN);
  }else{
    /*
    * @violates @ref MLIB_Div_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
    * signed underlying type (<<).
    */
    f16Return = INT16TOF16(INT32TOINT16((F16TOINT32(f16In1)<<(tU16)15)/F16TOINT32(f16In2)));
  }
  return(f16Return);
}




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function divides the first parameter by the second one.

@param[in]         f32In1     Numerator of division.

@param[in]         f32In2     Denominator of division.

@return       Division of two input values.

@details      This inline function returns the division of two input values. The first input value is numerator and the
              second input value is denominator. The input values as well as output value is considered as 32-bit
              fractional data type. The output saturation is not implemented in this function, thus in case the
              numerator is greater or equal to denominator, the output value is undefined. As the division by zero can
              be handled differently on each platform and potentially can cause the core exception, the division by zero
              is handled separately.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Div_F32
              \image rtf divEq1_f32.math "MLIB_Div_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
              The overflow is not detected in this function.
*/
/*!

@warning      Due to effectivity reason the division is held in 16-bit precision.

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1, f32In2;
tFrac32 f32Out;

void main(void)
{
  // input value 1 = 0.25
  f32In1  = FRAC32(0.25);
  // input value 2 = 0.5
  f32In2  = FRAC32(0.5);

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_Div_F32(f32In1, f32In2);

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_Div(f32In1, f32In2, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(0.5) = 0x40000000
  f32Out = MLIB_Div(f32In1, f32In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00120, DMLIB00107, DMLIB00116, DMLIB00118, DMLIB00108, DMLIB00111 */
static inline tFrac32 MLIB_Div_F32(register tFrac32 f32In1, register tFrac32 f32In2)
/*
* @violates @ref MLIB_Div_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /** @remarks Implements DMLIB00117 */
  return(Div_F32_C(f32In1, f32In2));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function divides the first parameter by the second one.

@param[in]         f16In1     Numerator of division.

@param[in]         f16In2     Denominator of division.

@return       Division of two input values.

@details      This inline function returns the division of two input values. The first input value is numerator and the
              second input value is denominator. The input values as well as output value is considered as 16-bit
              fractional data type. The output saturation is not implemented in this function, thus in case the
              numerator is greater or equal to denominator, the output value is undefined. As the division by zero can
              be handled differently on each platform and potentially can cause the core exception, the division by zero
              is handled separately.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Div_F16
              \image rtf divEq1_f16.math "MLIB_Div_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
              The overflow is not detected in this function.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1, f16In2;
tFrac16 f16Out;

void main(void)
{
  // input value 1 = 0.25
  f16In1  = FRAC16(0.25);
  // input value 2 = 0.5
  f16In2  = FRAC16(0.5);

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_Div_F16(f16In1, f16In2);

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_Div(f16In1, f16In2, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(0.5) = 0x4000
  f16Out = MLIB_Div(f16In1, f16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00120, DMLIB00107, DMLIB00115, DMLIB00118, DMLIB00109, DMLIB00112 */
static inline tFrac16 MLIB_Div_F16(register tFrac16 f16In1, register tFrac16 f16In2)
/*
* @violates @ref MLIB_Div_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /** @remarks Implements DMLIB00117 */
  return(Div_F16_C(f16In1, f16In2));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function divides the first parameter by the second one.

@param[in]         fltIn1     Numerator of division.

@param[in]         fltIn2     Denominator of division.

@return       Division of two input values.

@details      This inline function returns the division of two input values. The first input value is numerator and the
              second input value is denominator. The input values as well as output value is considered as single
              precision floating point data type.
*/
/*!
              If the second input value is zero, a floating-point data exception division by zero
              (SPEFSCR.FDBZ) will be asserted. If any of the inputs is infinity, NaN, or a
              denormalized value, or if both inputs are zero, a floating-point invalid
              operation/input error exception will be asserted (SPEFSCR.FINV).
*/
/*!

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Div_FLT
              \image rtf divEq1_flt.math "MLIB_Div_Eq1"

@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1, fltIn2;
tFloat fltOut;

void main(void)
{
  // input value 1 = 0.25
  fltIn1  = 0.25;
  // input value 2 = 0.5
  fltIn2  = 0.5;

  // output should be 0.5
  fltOut = MLIB_Div_FLT(fltIn1, fltIn2);

  // output should be 0.5
  fltOut = MLIB_Div(fltIn1, fltIn2, FLT);

  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

// output should be 0.5
  fltOut = MLIB_Div(fltIn1, fltIn2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00120, DMLIB00107, DMLIB00114, DMLIB00118, DMLIB00110, DMLIB00113 */
static inline tFloat MLIB_Div_FLT(register tFloat fltIn1, register tFloat fltIn2)
/*
* @violates @ref MLIB_Div_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /** @remarks Implements DMLIB00117 */
  return((tFloat)(fltIn1 / fltIn2));
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_DIV_H */
