/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*
******************************************************************************/
/*!
*
* @file       MLIB_VMac.h
*
* @version    1.0.63.0
*
* @date       Aug-5-2015
*
* @brief      Header file for MLIB_VMac function
*
******************************************************************************/
#ifndef MLIB_VMAC_H
#define MLIB_VMAC_H

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
* @section MLIB_VMac_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section MLIB_VMac_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section MLIB_VMac_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section MLIB_VMac_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*
* @section MLIB_VMac_h_REF_5
* Violates MISRA 2004 Required Rule 8.5, Object/function definition in header file.
* Allowing the inline functions significantly increase the speed of the library thus the lowest
* layer (MLIB) is implemented as inline. This approach removes the overhead caused by standard
* function calling.
*
* @section MLIB_VMac_h_REF_6
* Violates MISRA 2004 Required Rule 12.7, Bitwise operator applied to signed underlying type.
* The fractional arithmetic requires the bit-wise operations on signed values.
*/
#include "SWLIBS_Defines.h"
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_Add.h"
  #include "MLIB_Mul.h"
  #include "MLIB_Mnac.h"
#else
  /* Following includes serve for Freescale internal testing purposes only.
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_Add.h"
  #include "CCOV_MLIB_Mul.h"
  #include "CCOV_MLIB_Mnac.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  /*
  * @violates @ref MLIB_VMac_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
  * @violates @ref MLIB_VMac_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_VMac_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter
  * in definition of macro.
  */
  #define MLIB_VMac(...)     macro_dispatcher(MLIB_VMac, __VA_ARGS__)(__VA_ARGS__)     /*!< This function implements the vector multiply accumulate function. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref MLIB_VMac_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_VMac_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_VMac_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00240 */
    #define MLIB_VMac_Dsptchr_4(In1,In2,In3,In4)     MLIB_VMac_Dsptchr_5(In1,In2,In3,In4,F32)     /*!< Function dispatcher for MLIB_VMac_Dsptchr_4, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref MLIB_VMac_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_VMac_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_VMac_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00240 */
    #define MLIB_VMac_Dsptchr_4(In1,In2,In3,In4)     MLIB_VMac_Dsptchr_5(In1,In2,In3,In4,F16)     /*!< Function dispatcher for MLIB_VMac_Dsptchr_4, do not modify!!! */
  #endif
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /*
    * @violates @ref MLIB_VMac_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_VMac_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_VMac_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00240 */
    #define MLIB_VMac_Dsptchr_4(In1,In2,In3,In4)     MLIB_VMac_Dsptchr_5(In1,In2,In3,In4,FLT)     /*!< Function dispatcher for MLIB_VMac_Dsptchr_4, do not modify!!! */
  #endif
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  /*
  * @violates @ref MLIB_VMac_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
  * @violates @ref MLIB_VMac_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_VMac_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter
  * in definition of macro.
  */
  #define MLIB_VMac_Dsptchr_5(In1,In2,In3,In4,Impl)    MLIB_VMac_Dsptchr_(In1,In2,In3,In4,Impl)     /*!< Function dispatcher for MLIB_VMac_Dsptchr_5, do not modify!!! */

  /*
  * @violates @ref MLIB_VMac_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
  * @violates @ref MLIB_VMac_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_VMac_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter
  * in definition of macro.
  * @violates @ref MLIB_VMac_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
  */
  /** @remarks Implements DMLIB00242 */
  #define MLIB_VMac_Dsptchr_(In1,In2,In3,In4,Impl)     MLIB_VMac_##Impl(In1,In2,In3,In4)            /*!< Function dispatcher for MLIB_VMac_Dsptchr_, do not modify!!! */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/
static inline tFrac32 VMac_F32_C(register tFrac32 f32In1, register tFrac32 f32In2, register tFrac32 f32In3, register tFrac32 f32In4)
/*
* @violates @ref MLIB_VMac_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  return(MLIB_Add_F32(MLIB_Mul_F32(f32In1,f32In2),MLIB_Mul_F32(f32In3,f32In4)));
}
static inline tFrac32 VMac_F32F16F16_C(register tFrac16 f16In1, register tFrac16 f16In2, register tFrac16 f16In3, register tFrac16 f16In4)
/*
* @violates @ref MLIB_VMac_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  return(MLIB_Add_F32(MLIB_Mul_F32F16F16(f16In1,f16In2),MLIB_Mul_F32F16F16(f16In3,f16In4)));
}
static inline tFrac16 VMac_F16_C(register tFrac16 f16In1, register tFrac16 f16In2, register tFrac16 f16In3, register tFrac16 f16In4)
/*
* @violates @ref MLIB_VMac_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  return(MLIB_Add_F16(MLIB_Mul_F16(f16In1,f16In2),MLIB_Mul_F16(f16In3,f16In4)));
}
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
static inline tFloat VMac_FLT_C(register tFloat fltIn1, register tFloat fltIn2, register tFloat fltIn3, register tFloat fltIn4)
/*
* @violates @ref MLIB_VMac_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_VMac_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
  * header file.
  */
  tFloat fltReturn, fltTemp1, fltTemp2;

  fltTemp1 = MLIB_Mul_FLT(fltIn1,fltIn2);
  fltTemp2 = MLIB_Mul_FLT(fltIn3,fltIn4);
  fltReturn = MLIB_Add_FLT(fltTemp1,fltTemp2);
  fltTemp1 = MLIB_Mnac_FLT(fltTemp1,fltIn1,fltIn2);
  fltTemp2 = MLIB_Mnac_FLT(fltTemp2,fltIn3,fltIn4);
  fltTemp1 = MLIB_Add_FLT(fltTemp1,fltTemp2);
  fltReturn = MLIB_Add_FLT(fltReturn,fltTemp1);
  return(fltReturn);
}
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function implements the vector multiply accumulate function.

@param[in]    f32In1     First input value to first multiplication.

@param[in]    f32In2     Second input value to first multiplication.

@param[in]    f32In3     First input value to second multiplication.

@param[in]    f32In4     Second input value to second multiplication.

@return       Vector multiplied input values with addition.

@details      This inline function returns the vector multiply accumulate of input values. The input values as well as
              output value is considered as 32-bit fractional values. The output saturation is not implemented in this
              function, thus in case the vector multiply-add of input values is outside the (-1, 1) interval, the output
              value will overflow without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_VMac_F32
              \image rtf vmacEq1_f32.math "MLIB_VMac_Eq1"

*/
/*!
@note         Overflow is not detected. Due to effectivity reason this function is implemented as inline and thus is
              not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32In2;
tFrac32 f32In3;
tFrac32 f32In4;
tFrac32 f32Out;

void main(void)
{
  // input1 value = 0.25
  f32In1  = FRAC32(0.25);

  // input2 value = 0.15
  f32In2  = FRAC32(0.15);

  // input3 value = 0.35
  f32In3  = FRAC32(0.35);

  // input4 value = 0.45
  f32In4  = FRAC32(0.45);

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac_F32(f32In1, f32In2, f32In3, f32In4);

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac(f32In1, f32In2, f32In3, f32In4, F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac(f32In1, f32In2, f32In3, f32In4);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00241, DMLIB00233, DMLIB00236, DMLIB00239 */
static inline tFrac32 MLIB_VMac_F32(register tFrac32 f32In1,register tFrac32 f32In2,register tFrac32 f32In3,register tFrac32 f32In4)
/*
* @violates @ref MLIB_VMac_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00238 */
  return(VMac_F32_C(f32In1, f32In2, f32In3, f32In4));
}





/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function implements the vector multiply accumulate function.

@param[in]    f16In1     First input value to first multiplication.

@param[in]    f16In2     Second input value to first multiplication.

@param[in]    f16In3     First input value to second multiplication.

@param[in]    f16In4     Second input value to second multiplication.

@return       Vector multiplied input values with addition.

@details      This inline function returns the vector multiply accumulate of input values. The input values are
              considered as 16-bit fractional values and the output value is considered as 32-bit fractional value.
              The output saturation is not implemented in this function, thus in case the vector multiply-add of input
              values is outside the (-1, 1) interval, the output value will overflow without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_VMac_F32F16F16
              \image rtf vmacEq1_f32f16f16.math "MLIB_VMac_Eq1"

*/
/*!
@note         Overflow is not detected. Due to effectivity reason this function is implemented as inline and thus is
              not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16In3;
tFrac16 f16In4;
tFrac32 f32Out;

void main(void)
{
  // input1 value = 0.25
  f16In1  = FRAC16(0.25);

  // input2 value = 0.15
  f16In2  = FRAC16(0.15);

  // input3 value = 0.35
  f16In3  = FRAC16(0.35);

  // input4 value = 0.45
  f16In4  = FRAC16(0.45);

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac_F32F16F16(f16In1, f16In2, f16In3, f16In4);

  // output should be FRAC32(0.195) = 0x18F5C28F
  f32Out = MLIB_VMac(f16In1, f16In2, f16In3, f16In4, F32F16F16);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00241, DMLIB00233, DMLIB00237, DMLIB00239 */
static inline tFrac32 MLIB_VMac_F32F16F16(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3,register tFrac16 f16In4)
/*
* @violates @ref MLIB_VMac_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00238 */
  return(VMac_F32F16F16_C(f16In1, f16In2, f16In3, f16In4));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function implements the vector multiply accumulate function.

@param[in]    f16In1     First input value to first multiplication.

@param[in]    f16In2     Second input value to first multiplication.

@param[in]    f16In3     First input value to second multiplication.

@param[in]    f16In4     Second input value to second multiplication.

@return       Vector multiplied input values with addition.

@details      This inline function returns the vector multiply accumulate of input values. The input values as well as
              output value is considered as 16-bit fractional values. The output saturation is not implemented in this
              function, thus in case the vector multiply-add of input values is outside the (-1, 1) interval, the output
              value will overflow without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_VMac_F16
              \image rtf vmacEq1_f16.math "MLIB_VMac_Eq1"

*/
/*!
@note         Overflow is not detected. Due to effectivity reason this function is implemented as inline and thus is
              not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16In3;
tFrac16 f16In4;
tFrac16 f16Out;

void main(void)
{
  // input1 value = 0.25
  f16In1  = FRAC16(0.25);

  // input2 value = 0.15
  f16In2  = FRAC16(0.15);

  // input3 value = 0.35
  f16In3  = FRAC16(0.35);

  // input4 value = 0.45
  f16In4  = FRAC16(0.45);

  // output should be FRAC16(0.195) = 0x18F5
  f16Out = MLIB_VMac_F16(f16In1, f16In2, f16In3, f16In4);

  // output should be FRAC16(0.195) = 0x18F5
  f16Out = MLIB_VMac(f16In1, f16In2, f16In3, f16In4, F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be FRAC16(0.195) = 0x18F5
  f16Out = MLIB_VMac(f16In1, f16In2, f16In3, f16In4);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00241, DMLIB00233, DMLIB00235, DMLIB00239 */
static inline tFrac16 MLIB_VMac_F16(register tFrac16 f16In1,register tFrac16 f16In2,register tFrac16 f16In3,register tFrac16 f16In4)
/*
* @violates @ref MLIB_VMac_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00238 */
  return(VMac_F16_C(f16In1, f16In2, f16In3, f16In4));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function implements the vector multiply accumulate function.

@param[in]    fltIn1     First input value to first multiplication.

@param[in]    fltIn2     Second input value to first multiplication.

@param[in]    fltIn3     First input value to second multiplication.

@param[in]    fltIn4     Second input value to second multiplication.

@return       Vector multiplied input values with addition.

@details      This inline function returns the vector multiply accumulate of input values. The input values as well as
              output value is considered as single precision floating point values. The output saturation is not
              implemented in this function, thus in case the vector multiply-add of input values is outside the
              (-2\f$^{128}\f$, 2\f$^{128}\f$) interval, the output value will overflow without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_VMac_FLT
              \image rtf vmacEq1_flt.math "MLIB_VMac_Eq1"

*/
/*!
@note         Overflow is not detected. Due to effectivity reason this function is implemented as inline and thus is
              not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1;
tFloat fltIn2;
tFloat fltIn3;
tFloat fltIn4;
tFloat fltOut;

void main(void)
{
  // input1 value = 0.25
  fltIn1  = 0.25;

  // input2 value = 0.15
  fltIn2  = 0.15;

  // input3 value = 0.35
  fltIn3  = 0.35;

  // input4 value = 0.45
  fltIn4  = 0.45;

  // output should be 0.195
  fltOut = MLIB_VMac_FLT(fltIn1, fltIn2, fltIn3, fltIn4);

  // output should be 0.195
  fltOut = MLIB_VMac(fltIn1, fltIn2, fltIn3, fltIn4, FLT);

  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be 0.195
  fltOut = MLIB_VMac(fltIn1, fltIn2, fltIn3, fltIn4);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00241, DMLIB00233, DMLIB00234, DMLIB00239 */
static inline tFloat MLIB_VMac_FLT(register tFloat fltIn1,register tFloat fltIn2,register tFloat fltIn3,register tFloat fltIn4)
/*
* @violates @ref MLIB_VMac_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00238 */
  return(VMac_FLT_C(fltIn1, fltIn2, fltIn3, fltIn4));
}

#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_VMAC_H */
