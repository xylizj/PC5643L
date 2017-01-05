/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*   All Rights Reserved.
*
******************************************************************************/
/*!
*
* @file       MLIB_ConvertPU.h
*
* @version    1.0.29.0
*
* @date       Dec-5-2015
*
* @brief      Header file for MLIB_ConvertPU function
*
******************************************************************************/
#ifndef MLIB_CONVERTPU_H
#define MLIB_CONVERTPU_H
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
* @section MLIB_ConvertPU_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section MLIB_ConvertPU_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section MLIB_ConvertPU_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section MLIB_ConvertPU_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*
* @section MLIB_ConvertPU_h_REF_5
* Violates MISRA 2004 Required Rule 8.5, Object/function definition in header file.
* Allowing the inline functions significantly increase the speed of the library thus the lowest
* layer (MLIB) is implemented as inline. This approach removes the overhead caused by standard
* function calling.
*
* @section MLIB_ConvertPU_h_REF_6
* Violates MISRA 2004 Required Rule 12.7, Bitwise operator applied to signed underlying type.
* The fractional arithmetic requires the bit-wise operations on signed values.
*
* @section MLIB_ConvertPU_h_REF_7
* Violates MISRA 2004 Required Rule 10.4, Cast of complex expression from floating point to integer
* type.
* The casting of the expression required for data type conversion.
*/

#include "SWLIBS_Defines.h"
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_ShL.h"
  #include "MLIB_Mul.h"
  #include "MLIB_ShR.h"
  #include "MLIB_Div.h"
#else
  /* Following includes serve for Freescale internal testing purposes only.
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_ShL.h"
  #include "CCOV_MLIB_Mul.h"
  #include "CCOV_MLIB_ShR.h"
  #include "CCOV_MLIB_Div.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  /*
  * @violates @ref MLIB_ConvertPU_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref MLIB_ConvertPU_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
  * defined.
  * @violates @ref MLIB_ConvertPU_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define MLIB_ConvertPU(...)     macro_dispatcher(MLIB_ConvertPU, __VA_ARGS__)(__VA_ARGS__)     /*!< This function converts the input value to different representation with scale. */

  /*
  * @violates @ref MLIB_ConvertPU_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref MLIB_ConvertPU_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
  * defined.
  * @violates @ref MLIB_ConvertPU_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define MLIB_ConvertPU_Dsptchr_2(In,Impl)    MLIB_ConvertPU_Dsptchr_(In,Impl)     /*!< Function dispatcher for MLIB_ConvertPU_Dsptchr_2, do not modify!!! */

  /*
  * @violates @ref MLIB_ConvertPU_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref MLIB_ConvertPU_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro
  * defined.
  * @violates @ref MLIB_ConvertPU_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in
  * macro.
  */
  /** @remarks Implements DMLIB00252*/
  #define MLIB_ConvertPU_Dsptchr_(In,Impl)     MLIB_ConvertPU_##Impl(In)            /*!< Function dispatcher for MLIB_ConvertPU_Dsptchr_, do not modify!!! */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/
static inline tFrac32 ConvertPU_F32F16_C(register tFrac16 f16In)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_ConvertPU_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type.
  */
  return((tFrac32)((tFrac32)f16In << ((tU16)16)));
}
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
static inline tFrac32 ConvertPU_F32FLT_C(register tFloat fltIn)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_ConvertPU_h_REF_7 MISRA 2004 Required Rule 10.4, Cast of complex expression
  * from floating point to integer type.
  */
  return((fltIn>=(tFloat)1) ? (tFrac32)INT32_MAX : ((fltIn<(tFloat)-1) ? (tFrac32)INT32_MIN : ((tFrac32)(fltIn * (((tFloat)INT32_MAX)+(tFloat)1)))));
}
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
static inline tFrac16 ConvertPU_F16F32_C(register tFrac32 f32In)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_ConvertPU_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type.
  */
  return((tFrac16)(f32In >> ((tU16)16)));
}
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
static inline tFrac16 ConvertPU_F16FLT_C(register tFloat fltIn)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_ConvertPU_h_REF_7 MISRA 2004 Required Rule 10.4, Cast of complex expression
  * from floating point to integer type.
  */
  return((fltIn>=(tFloat)1) ? (tFrac16)INT16_MAX : ((fltIn<(tFloat)-1) ? (tFrac16)INT16_MIN : ((tFrac16)(fltIn * (((tFloat)INT16_MAX)+(tFloat)1)))));
}
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
static inline tFloat ConvertPU_FLTF16_C(register tFrac16 f16In)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  return(MLIB_Div_FLT((tFloat)f16In,((tFloat)(INT16_MAX))+(tFloat)1));
}
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
static inline tFloat ConvertPU_FLTF32_C(register tFrac32 f32In)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  return(MLIB_Div_FLT((tFloat)f32In,((tFloat)(INT32_MAX))+(tFloat)1));
}
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function converts the input value to different representation without scale.

@param[in]    f16In     Input value in 16-bit fractional format to be converted.

@return       Converted input value in 32-bit fractional format.

@details      This inline function returns converted input value. The input value is considered as 16-bit fractional
              data type and output value is considered as 32-bit fractional data type thus both values represent the
              values in unity model. The output saturation is not implemented in this function, thus in case the input
              value is outside the (-1, 1) interval, the output value will overflow without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_ConvertPU_F32F16
              \image rtf convertpuEq1_f32f16.math "MLIB_ConvertPU_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In;
tFrac32 f32Out;

void main(void)
{
    // input value = 0.25 = 0x2000
    f16In  = FRAC16(0.25);

    // output should be FRAC32(0.25) = 0x20000000
    f32Out = MLIB_ConvertPU_F32F16(f16In);

    // output should be FRAC32(0.25) = 0x20000000
    f32Out = MLIB_ConvertPU(f16In, F32F16);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
/** @remarks Implements DMLIB00251, DMLIB00247, DMLIB00249, DMLIB00246 */
static inline tFrac32 MLIB_ConvertPU_F32F16(register tFrac16 f16In)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00249 */
  return(ConvertPU_F32F16_C(f16In));
}




#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function converts the input value to different representation without scale.

@param[in]    fltIn     Input value in single precision floating point format to be converted.

@return       Converted input value in 32-bit fractional format.

@details      This inline function returns converted input value. The input value is considered as single precision
              floating  point data type and output value is considered as 32-bit fractional data type. The output value
              represents the values in unity model. The output saturation is implemented in this function, thus in case
              the input value is outside the (-1, 1) interval, the output value is limited to the boundary value.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_ConvertPU_F32FLT
              \image rtf convertpuEq1_f32flt.math "MLIB_ConvertPU_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn;
tFrac32 f32Out;

void main(void)
{
    // input value = 0.25
    fltIn  = 0.25;

    // output should be FRAC32(0.25) = 0x20000000
    f32Out = MLIB_ConvertPU_F32FLT(fltIn);

    // output should be FRAC32(0.25) = 0x20000000
    f32Out = MLIB_ConvertPU(fltIn, F32FLT);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
/** @remarks Implements DMLIB00251, DMLIB00244, DMLIB00247, DMLIB00249, DMLIB00245 */
static inline tFrac32 MLIB_ConvertPU_F32FLT(register tFloat fltIn)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00248 */
  return(ConvertPU_F32FLT_C(fltIn));
}




#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function converts the input value to different representation without scale.

@param[in]    f32In     Input value in 32-bit fractional format to be converted.

@return       Converted input value in 16-bit fractional format.

@details      This inline function returns converted input value. The input value is considered as 32-bit fractional
              data type and output value is considered as 16-bit fractional data type thus both values represent the
              values in unity model. The output saturation is not implemented in this function, thus in case the input
              value is outside the (-1, 1) interval, the output value will overflow without any detection.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_ConvertPU_F16F32
              \image rtf convertpuEq1_f16f32.math "MLIB_ConvertPU_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In;
tFrac16 f16Out;

void main(void)
{
    // input value = 0.25 = 0x2000 0000
    f32In  = FRAC32(0.25);

    // output should be FRAC16(0.25) = 0x2000
    f16Out = MLIB_ConvertPU_F16F32(f32In);

    // output should be FRAC16(0.25) = 0x2000
    f16Out = MLIB_ConvertPU(f32In, F16F32);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
/** @remarks Implements DMLIB00251, DMLIB00246, DMLIB00249, DMLIB00247 */
static inline tFrac16 MLIB_ConvertPU_F16F32(register tFrac32 f32In)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00249 */
  return(ConvertPU_F16F32_C(f32In));
}




#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function converts the input value to different representation without scale.

@param[in]    fltIn     Input value in single precision floating point format to be converted.

@return       Converted input value in 16-bit fractional format.

@details      This inline function returns converted input value. The input value is considered as single precision
              floating  point data type and output value is considered as 16-bit fractional data type. The output value
              represents the values in unity model. The output saturation is implemented in this function, thus in case
              the input value is outside the (-1, 1) interval, the output value is limited to the boundary value.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_ConvertPU_F16FLT
              \image rtf convertpuEq1_f16flt.math "MLIB_ConvertPU_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFloat fltIn;
tFrac16 f16Out;

void main(void)
{
    // input value = 0.25
    fltIn  = 0.25;

    // output should be FRAC16(0.25) = 0x2000
    f16Out = MLIB_ConvertPU_F16FLT(fltIn);

    // output should be FRAC16(0.25) = 0x2000
    f16Out = MLIB_ConvertPU(fltIn, F16FLT);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
/** @remarks Implements DMLIB00251, DMLIB00244, DMLIB00246, DMLIB00249, DMLIB00245 */
static inline tFrac16 MLIB_ConvertPU_F16FLT(register tFloat fltIn)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00248 */
  return(ConvertPU_F16FLT_C(fltIn));
}




#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function converts the input value to different representation without scale.

@param[in]    f16In     Input value in 16-bit fractional format to be converted.

@return       Converted input value in single precision floating point format.

@details      This inline function returns converted input value. The input value is considered as 16-bit fractional
              data type and output value is considered as single precision floating point data type. The input value
              represents the values in unity model. The output saturation is not implemented in this function.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_ConvertPU_FLTF16
              \image rtf convertpuEq1_fltf16.math "MLIB_ConvertPU_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tF16 f16In;
tFloat fltOut;

void main(void)
{
    // input value = 0.25 = 0x2000
    f16In  = FRAC16(0.25);

    // output should be 0.25
    fltOut = MLIB_ConvertPU_FLTF16(f16In);

    // output should be 0.25
    fltOut = MLIB_ConvertPU(f16In, FLTF16);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
/** @remarks Implements DMLIB00251, DMLIB00244, DMLIB00245, DMLIB00249, DMLIB00246 */
static inline tFloat MLIB_ConvertPU_FLTF16(register tFrac16 f16In)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00248 */
  return(ConvertPU_FLTF16_C(f16In));
}




#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function converts the input value to different representation without scale.

@param[in]    f32In     Input value in 32-bit fractional format to be converted.

@return       Converted input value in single precision floating point format.

@details      This inline function returns converted input value. The input value is considered as 32-bit fractional
              data type and output value is considered as single precision floating point data type. The input value
              represents the values in unity model. The output saturation is not implemented in this function.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_ConvertPU_FLTF32
              \image rtf convertpuEq1_fltf32.math "MLIB_ConvertPU_Eq1"

*/
/*!
@note         Due to effectivity reason this function is implemented as inline, and thus is not ANSI-C compliant.
*/
/*!

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tF32 f32In;
tFloat fltOut;

void main(void)
{
    // input value = 0.25 = 0x2000 0000
    f32In  = FRAC32(0.25);

    // output should be 0.25
    fltOut = MLIB_ConvertPU_FLTF32(f32In);

    // output should be 0.25
    fltOut = MLIB_ConvertPU(f32In, FLTF32);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
/** @remarks Implements DMLIB00251, DMLIB00244, DMLIB00245, DMLIB00249, DMLIB00247 */
static inline tFloat MLIB_ConvertPU_FLTF32(register tFrac32 f32In)
/*
* @violates @ref MLIB_ConvertPU_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00248 */
  return(ConvertPU_FLTF32_C(f32In));
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_CONVERTPU_H */
