/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*
******************************************************************************/
/*!
*
* @file       MLIB_SubSat.h
*
* @version    1.0.42.0
*
* @date       Dec-4-2015
*
* @brief      Header file for MLIB_SubSat function
*
******************************************************************************/
#ifndef MLIB_SUBSAT_H
#define MLIB_SUBSAT_H
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
* @section MLIB_SubSat_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section MLIB_SubSat_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section MLIB_SubSat_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section MLIB_SubSat_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*
* @section MLIB_SubSat_h_REF_5
* Violates MISRA 2004 Required Rule 8.5, Object/function definition in header file.
* Allowing the inline functions significantly increase the speed of the library thus the lowest
* layer (MLIB) is implemented as inline. This approach removes the overhead caused by standard
* function calling.
*
* @section MLIB_SubSat_h_REF_6
* Violates MISRA 2004 Required Rule 12.7, Bitwise operator applied to signed underlying type.
* The fractional arithmetic requires the bit-wise operations on signed values.
*/
#include "SWLIBS_Defines.h"
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_Sub.h"
#else
  /* Following include serves for Freescale internal testing purposes only.
  *  This header is not part of the release. */
  #include "CCOV_MLIB_Sub.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  /*
  * @violates @ref MLIB_SubSat_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref MLIB_SubSat_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_SubSat_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define MLIB_SubSat(...)     macro_dispatcher(MLIB_SubSat, __VA_ARGS__)(__VA_ARGS__)     /*!< This function subtracts the second parameter from the first one and saturate if necessary. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref MLIB_SubSat_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_SubSat_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_SubSat_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00078 */
    #define MLIB_SubSat_Dsptchr_2(In1,In2)     MLIB_SubSat_Dsptchr_3(In1,In2,F32)     /*!< Function dispatcher for MLIB_SubSat_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref MLIB_SubSat_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_SubSat_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_SubSat_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00078 */
    #define MLIB_SubSat_Dsptchr_2(In1,In2)     MLIB_SubSat_Dsptchr_3(In1,In2,F16)     /*!< Function dispatcher for MLIB_SubSat_Dsptchr_2, do not modify!!! */
  #endif

  /*
  * @violates @ref MLIB_SubSat_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref MLIB_SubSat_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_SubSat_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define MLIB_SubSat_Dsptchr_3(In1,In2,Impl)    MLIB_SubSat_Dsptchr_(In1,In2,Impl)     /*!< Function dispatcher for MLIB_SubSat_Dsptchr_3, do not modify!!! */

  /*
  * @violates @ref MLIB_SubSat_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref MLIB_SubSat_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_SubSat_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  * @violates @ref MLIB_SubSat_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
  */
  /** @remarks Implements DMLIB00080 */
  #define MLIB_SubSat_Dsptchr_(In1,In2,Impl)     MLIB_SubSat_##Impl(In1,In2)            /*!< Function dispatcher for MLIB_SubSat_Dsptchr_, do not modify!!! */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/
/* MLIB_SubSat_F32 implementation variant - C */
static inline tFrac32 SubSat_F32_C(register tFrac32 f32In1,register tFrac32 f32In2)
/*
* @violates @ref MLIB_SubSat_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_SubSat_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
  * header file.
  */
  register tS32 s32Temp;
  /*
  * @violates @ref MLIB_SubSat_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
  * header file.
  */
  register tS32 s32satmin, s32satmax;

  s32Temp = F32TOINT32(MLIB_Sub_F32(f32In1, f32In2));

  /*
  * @violates @ref MLIB_SubSat_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (&).
  */
  s32satmax = (~F32TOINT32(f32In1) & F32TOINT32(f32In2)) & s32Temp;
  /*
  * @violates @ref MLIB_SubSat_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (~).
  */
  s32satmin = F32TOINT32(f32In1) & (~F32TOINT32(f32In2)) & (~s32Temp);

  s32Temp = (s32satmin < 0) ? INT32_MIN : s32Temp;
  s32Temp = (s32satmax < 0) ? INT32_MAX : s32Temp;
  return(INT32TOF32(s32Temp));
}

/* MLIB_SubSat_F16 implementation variant - C */
static inline tFrac16 SubSat_F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
/*
* @violates @ref MLIB_SubSat_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_SubSat_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
  * header file.
  */
  register tS32 s32temp;

  s32temp = F32TOINT32(MLIB_Sub_F32((tFrac32)f16In1, (tFrac32)f16In2));

  s32temp = (s32temp > (tS32) INT16_MAX) ? (tS32) INT16_MAX : s32temp;
  s32temp = (s32temp < (tS32) INT16_MIN) ? (tS32) INT16_MIN : s32temp;
  return(INT32TOF16(s32temp));
}





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function subtracts the second parameter from the first one and
              saturate if necessary.

@param[in]    f32In1     Operand is a 32-bit number normalized between [-1,1).

@param[in]    f32In2     Operand is a 32-bit number normalized between [-1,1).

@return       The subtraction of the second argument from the first argument.

@details      Subtraction with overflow control of two fractional 32-bit numbers. The second argument is subtracted
              from the first one. The input values as well as output value are considered as 32-bit fractional data
              type. The output saturation is implemented in this function, thus in case the subtraction of input
              parameters is outside the (-1, 1) interval, the output value is limited to the boundary value.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_SubSat_F32
              \image rtf subsatEq1_f32.math "MLIB_SubSat_Eq1"

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

  // output should be 0x20000000
  f32Out = MLIB_SubSat_F32(f32In1,f32In2);

  // output should be 0x20000000
  f32Out = MLIB_SubSat(f32In1,f32In2,F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x20000000
  f32Out = MLIB_SubSat(f32In1,f32In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00079, DMLIB00073, DMLIB00075, DMLIB00077, DMLIB00082 */
static inline tFrac32 MLIB_SubSat_F32(register tFrac32 f32In1, register tFrac32 f32In2)
/*
* @violates @ref MLIB_SubSat_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00076 */
  return(SubSat_F32_C(f32In1,f32In2));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        This function subtracts the second parameter from the first one
              and saturate if necessary.

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       The subtraction of the second argument from the first argument.

@details      Subtraction with overflow control of two fractional 16-bit numbers. The second argument is subtracted from
              the first one. The input values as well as output value are considered as 16-bit fractional data
              type. The output saturation is implemented in this function, thus in case the subtraction of input
              parameters is outside the (-1, 1) interval, the output value is limited to the boundary value.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_SubSat_F16
              \image rtf subsatEq1_f16.math "MLIB_SubSat_Eq1"

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

  // output should be 0x2000
  f16Out = MLIB_SubSat_F16(f16In1,f16In2);

  // output should be 0x2000
  f16Out = MLIB_SubSat(f16In1,f16In2,F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x2000
  f16Out = MLIB_SubSat(f16In1,f16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/** @remarks Implements DMLIB00079, DMLIB00073, DMLIB00074, DMLIB00077, DMLIB00083 */
static inline tFrac16 MLIB_SubSat_F16(register tFrac16 f16In1,register tFrac16 f16In2)
/*
* @violates @ref MLIB_SubSat_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
  /** @remarks Implements DMLIB00076 */
  return(SubSat_F16_C(f16In1,f16In2));
}

#ifdef __cplusplus
}
#endif

#endif /* MLIB_SUBSAT_H */
