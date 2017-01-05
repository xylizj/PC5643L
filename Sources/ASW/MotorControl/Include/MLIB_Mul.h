/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*
******************************************************************************/
/*!
*
* @file       MLIB_Mul.h
*
* @version    1.0.46.0
*
* @date       Dec-4-2015
*
* @brief      Header file for MLIB_Mul function
*
******************************************************************************/
#ifndef MLIB_MUL_H
#define MLIB_MUL_H
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
* @section MLIB_Mul_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section MLIB_Mul_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section MLIB_Mul_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section MLIB_Mul_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*
* @section MLIB_Mul_h_REF_5
* Violates MISRA 2004 Required Rule 8.5, Object/function definition in header file.
* Allowing the inline functions significantly increase the speed of the library thus the lowest
* layer (MLIB) is implemented as inline. This approach removes the overhead caused by standard
* function calling.
*
* @section MLIB_Mul_h_REF_6
* Violates MISRA 2004 Required Rule 12.7, Bitwise operator applied to signed underlying type.
* The fractional arithmetic requires the bit-wise operations on signed values.
*
* @section MLIB_Mul_h_REF_7
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness.
* The Khnut alhorithm requires the casting to different signedness of the resulting output.
*/
#include "SWLIBS_Defines.h"
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_ShR.h"
#else
  /* Following includes serve for Freescale internal testing purposes only.
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_ShR.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  /*
  * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
  * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter
  * in definition of macro.
  */
  #define MLIB_Mul(...)     macro_dispatcher(MLIB_Mul, __VA_ARGS__)(__VA_ARGS__)     /*!< This function multiply two input parameters. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00091 */
    #define MLIB_Mul_Dsptchr_2(In1,In2)     MLIB_Mul_Dsptchr_3(In1,In2,F32)     /*!< Function dispatcher for MLIB_Mul_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00091 */
    #define MLIB_Mul_Dsptchr_2(In1,In2)     MLIB_Mul_Dsptchr_3(In1,In2,F16)     /*!< Function dispatcher for MLIB_Mul_Dsptchr_2, do not modify!!! */
  #endif
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /*
    * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00091 */
    #define MLIB_Mul_Dsptchr_2(In1,In2)     MLIB_Mul_Dsptchr_3(In1,In2,FLT)     /*!< Function dispatcher for MLIB_Mul_Dsptchr_2, do not modify!!! */
  #endif
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  /*
  * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
  * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter
  * in definition of macro.
  */
  #define MLIB_Mul_Dsptchr_3(In1,In2,Impl)    MLIB_Mul_Dsptchr_(In1,In2,Impl)     /*!< Function dispatcher for MLIB_Mul_Dsptchr_3, do not modify!!! */

  /*
  * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
  * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter
  * in definition of macro.
  * @violates @ref MLIB_Mul_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
  */
  /** @remarks Implements DMLIB00093 */
  #define MLIB_Mul_Dsptchr_(In1,In2,Impl)     MLIB_Mul_##Impl(In1,In2)            /*!< Function dispatcher for MLIB_Mul_Dsptchr_, do not modify!!! */
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* static inline functions
****************************************************************************/
static inline tFrac32 Mul_F32_C(register tFrac32 f32In1, register tFrac32 f32In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Mul_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (>>).
  */
  return((tFrac32) ((F32TOINT64(f32In1)*F32TOINT64(f32In2))>>31));
}

static inline tFrac32 Mul_F32F16F16_C(register tFrac16 f16In1, register tFrac16 f16In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Mul_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (<<).
  */
  return(INT32TOF32((F16TOINT32(f16In1)*F16TOINT32(f16In2))<<1));
}



static inline tFrac16 Mul_F16_C(register tFrac16 f16In1, register tFrac16 f16In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Mul_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (>>).
  */
  return(INT32TOF16((F16TOINT32(f16In1)*F16TOINT32(f16In2))>>15));
}



/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function multiplies two input parameters.

@param[in]    f32In1     Operand is a 32-bit number normalized between [-1,1).

@param[in]    f32In2     Operand is a 32-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      Fractional multiplication of two fractional 32-bit values. The input values as well as output value is
              considered as 32-bit fractional values. The output saturation is not implemented in this function, thus
              in case the multiplication of input values is outside the (-1, 1) interval, the output value will overflow
              without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_F32
              \image rtf mulEq1_f32.math "MLIB_Mul_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32In2;
tFrac32 f32Out;

void main(void)
{
  // first input = 0.5
  f32In1  = FRAC32(0.5);

  // second input = 0.25
  f32In2  = FRAC32(0.25);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul_F32(f32In1,f32In2);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul(f32In1,f32In2,F32);


  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul(f32In1,f32In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00092, DMLIB00084, DMLIB00087, DMLIB00090 */
static inline tFrac32 MLIB_Mul_F32(register tFrac32 f32In1,register tFrac32 f32In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /** @remarks Implements DMLIB00089 */
  return(Mul_F32_C(f32In1, f32In2));
}





/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function multiplies two input parameters.

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      Fractional multiplication of two fractional 16-bit values. The input values are considered as 16-bit
              fractional values and the output value is considered as 32-bit fractional value. The output saturation is
              not implemented in this function, thus in case the multiplication of input values is outside the (-1, 1)
              interval, the output value will overflow without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_F32F16F16
              \image rtf mulEq1_f32f16f16.math "MLIB_Mul_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac32 f32Out;

void main(void)
{
  // first input = 0.5
  f16In1  = FRAC16(0.5);

  // second input = 0.25
  f16In2  = FRAC16(0.25);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul_F32F16F16(f16In1, f16In2);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul(f16In1, f16In2, F32F16F16);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00092, DMLIB00084, DMLIB00088, DMLIB00090 */
static inline tFrac32 MLIB_Mul_F32F16F16(register tFrac16 f16In1,register tFrac16 f16In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /** @remarks Implements DMLIB00089 */
  return(Mul_F32F16F16_C(f16In1, f16In2));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function multiplies two input parameters.

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      Fractional multiplication of two fractional 16-bit values. The input values as well as output value is
              considered as 16-bit fractional values. The output saturation is not implemented in this function, thus
              in case the multiplication of input values is outside the (-1, 1) interval, the output value will overflow
              without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_F16
              \image rtf mulEq1_f16.math "MLIB_Mul_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16Out;

void main(void)
{
  // first input = 0.5
  f16In1  = FRAC16(0.5);

  // second input = 0.25
  f16In2  = FRAC16(0.25);

  // output should be 0x1000 = FRAC16(0.125)
  f16Out = MLIB_Mul_F16(f16In1,f16In2);

  // output should be 0x1000 = FRAC16(0.125)
  f16Out = MLIB_Mul(f16In1,f16In2,F16);


  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x1000 = FRAC16(0.125)
  f16Out = MLIB_Mul(f16In1,f16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00092, DMLIB00084, DMLIB00086, DMLIB00090 */
static inline tFrac16 MLIB_Mul_F16(register tFrac16 f16In1,register tFrac16 f16In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /** @remarks Implements DMLIB00089 */
  return(Mul_F16_C(f16In1, f16In2));
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function multiplies two input parameters.

@param[in]    fltIn1     Operand is a single precision floating point number.

@param[in]    fltIn2     Operand is a single precision floating point number.

@return       Floating point multiplication of the input arguments.

@details      Single precision floating point multiplication of two input values. The input values as well as output
              value is considered as single precision floating point data type. The output saturation is not implemented
              in this function, thus in case the multiplication of input values is outside the
              (-2\f$^{128}\f$, 2\f$^{128}\f$) interval, the output value will overflow without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_FLT
              \image rtf mulEq1_flt.math "MLIB_Mul_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn1;
tFloat fltIn2;
tFloat fltOut;

void main(void)
{
  // first input = 50.5
  fltIn1  = 50.5;

  // second input = 25.25
  fltIn2  = 25.25;

  // output should be 1275.125
  fltOut = MLIB_Mul_FLT(fltIn1,fltIn2);

  // output should be 1275.125
  fltOut = MLIB_Mul(fltIn1,fltIn2,FLT);


  // ##############################################################
  // Available only if single precision floating point
  // implementation selected as default
  // ##############################################################

  // output should be 1275.125
  fltOut = MLIB_Mul(fltIn1,fltIn2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00092, DMLIB00084, DMLIB00085, DMLIB00090 */
static inline tFloat MLIB_Mul_FLT(register tFloat fltIn1,register tFloat fltIn2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /** @remarks Implements DMLIB00089 */
  return(fltIn1 * fltIn2);
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_MUL_H */
