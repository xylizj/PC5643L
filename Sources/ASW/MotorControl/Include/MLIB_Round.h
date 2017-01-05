/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*   All Rights Reserved.
*
******************************************************************************/
/*!
*
* @file       MLIB_Round.h
*
* @version    1.0.14.0
*
* @date       Nov-21-2014
*
* @brief      Header file for MLIB_Round function
*
******************************************************************************/
#ifndef MLIB_ROUND_H
#define MLIB_ROUND_H
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
* @section MLIB_Round_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section MLIB_Round_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section MLIB_Round_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section MLIB_Round_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*
* @section MLIB_Round_h_REF_5
* Violates MISRA 2004 Required Rule 8.5, Object/function definition in header file.
* Allowing the inline functions significantly increase the speed of the library thus the lowest
* layer (MLIB) is implemented as inline. This approach removes the overhead caused by standard
* function calling.
*
* @section MLIB_Round_h_REF_6
* Violates MISRA 2004 Required Rule 12.7, Bitwise operator applied to signed underlying type: &.
* Bitwise operation is well-defined in this context and verified by testing.
*
* @section MLIB_Round_h_REF_7
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness.
* Change of signedness is necessary to achieve desired functionality.
*/

#include "SWLIBS_Defines.h"
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_AddSat.h"
  #include "MLIB_ShL.h"
#else
  /* Following includes serve for Freescale internal testing purposes only.
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_AddSat.h"
  #include "CCOV_MLIB_ShL.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  /*
  * @violates @ref MLIB_Round_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref MLIB_Round_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_Round_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define MLIB_Round(...)     macro_dispatcher(MLIB_Round, __VA_ARGS__)(__VA_ARGS__)     /*!< This function rounds the first input value for number of digits defined by second parameter and saturate automatically. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref MLIB_Round_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_Round_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_Round_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00205 */
    #define MLIB_Round_Dsptchr_2(In1,In2)     MLIB_Round_Dsptchr_3(In1,In2,F32)     /*!< Function dispatcher for MLIB_Round_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref MLIB_Round_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref MLIB_Round_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref MLIB_Round_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DMLIB00205 */
    #define MLIB_Round_Dsptchr_2(In1,In2)     MLIB_Round_Dsptchr_3(In1,In2,F16)     /*!< Function dispatcher for MLIB_Round_Dsptchr_2, do not modify!!! */
  #endif

  /*
  * @violates @ref MLIB_Round_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref MLIB_Round_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_Round_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define MLIB_Round_Dsptchr_3(In1,In2,Impl)    MLIB_Round_Dsptchr_(In1,In2,Impl)   /*!< Function dispatcher for MLIB_Round_Dsptchr_3, do not modify!!! */

  /*
  * @violates @ref MLIB_Round_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref MLIB_Round_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref MLIB_Round_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  * @violates @ref MLIB_Round_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
  */
  /** @remarks Implements DMLIB00207 */
  #define MLIB_Round_Dsptchr_(In1,In2,Impl)     MLIB_Round_##Impl(In1,In2)          /*!< Function dispatcher for MLIB_Round_Dsptchr_, do not modify!!! */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        The function rounds the input and saturates.

@param[in]         f32In1     The value to be rounded.

@param[in]         u16In2     The number of trailing zeros in the rounded result.

@return       Rounded 32-bit fractional value.

@details      The function rounds the first input argument to the nearest value (round half up). The
              number of trailing zeros in the rounded result is equal to the second input argument,
              i.e., the number of significant digits is 32 - u16In2. The result is saturated to the
              fractional range.

@note         The second input argument must not exceed 30 for positive and 31 for negative
              f32In1, respectively, otherwise the result is undefined.
              Due to effectivity reason this function is implemented as inline
              and thus is not ANSI-C compliant.

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32Out;
tU16 u16In2;

void main(void)
{
    // Example no. 1
    // first input = 0.25
    f32In1 = FRAC32(0.25);
    // second input = 29
    u16In2 = 29;

    // output should be 0x20000000 ~ FRAC32(0.25)
    f32Out = MLIB_Round_F32(f32In1,u16In2);

    // output should be 0x20000000 ~ FRAC32(0.25)
    f32Out = MLIB_Round(f32In1,u16In2,F32);

    // ##############################################################
    // Available only if 32-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 0x20000000 ~ FRAC32(0.25)
    f32Out = MLIB_Round(f32In1,u16In2);


    // Example no. 2
    // first input = 0.375
    f32In1 = FRAC32(0.375);
    // second input = 29
    u16In2 = 29;

    // output should be 0x40000000 ~ FRAC32(0.5)
    f32Out = MLIB_Round_F32(f32In1,u16In2);


    // Example no. 3
    // first input = -0.375
    f32In1 = FRAC32(-0.375);
    // second input = 29
    u16In2 = 29;

    // output should be 0xE0000000 ~ FRAC32(-0.25)
    f32Out = MLIB_Round_F32(f32In1,u16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
/** @remarks Implements DMLIB00206, DMLIB00199, DMLIB00204 */
static inline tFrac32 MLIB_Round_F32(register tFrac32 f32In1,register tU16 u16In2)
/*
* @violates @ref MLIB_Round_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
    /** @remarks Implements DMLIB00202, DMLIB00203 */
    /*
    * @violates @ref MLIB_Round_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
    * signed underlying type: &.
    * @violates @ref MLIB_Round_h_REF_7 MISRA 2004 Required Rule 10.3, Cast of complex expression
    * changes signedness.
    */
    return(MLIB_AddSat_F32(f32In1, (tFrac32)((tU32)MLIB_ShL_F32((tFrac32)1u, u16In2) >> 1u)) & MLIB_ShL_F32((tFrac32)0xFFFFFFFFu, u16In2));
}




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/*!
@ingroup    MLIB_GROUP

@brief        The function rounds the input and saturates.

@param[in]         f16In1     The value to be rounded.

@param[in]         u16In2     The number of trailing zeros in the rounded result.

@return       Rounded 16-bit fractional value.

@details      The function rounds the first input argument to the nearest value (round half up). The
              number of trailing zeros in the rounded result is equal to the second input argument,
              i.e., the number of significant digits is 16 - u16In2. The result is saturated to the
              fractional range.

@note         The second input argument must not exceed 14 for positive and 15 for negative
              f16In1, respectively, otherwise the result is undefined.
              Due to effectivity reason this function is implemented as inline
              and thus is not ANSI-C compliant.

@par Re-entrancy
              The function is re-entrant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16Out;
tU16 u16In2;

void main(void)
{
    // Example no. 1
    // first input = 0.25
    f16In1 = FRAC16(0.25);
    // second input = 13
    u16In2 = 13;

    // output should be 0x2000 ~ FRAC16(0.25)
    f16Out = MLIB_Round_F16(f16In1,u16In2);

    // output should be 0x2000 ~ FRAC16(0.25)
    f16Out = MLIB_Round(f16In1,u16In2,F16);

    // ##############################################################
    // Available only if 16-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be 0x2000 ~ FRAC16(0.25)
    f16Out = MLIB_Round(f16In1,u16In2);


    // Example no. 2
    // first input = 0.375
    f16In1 = FRAC16(0.375);
    // second input = 13
    u16In2 = 13;

    // output should be 0x4000 ~ FRAC16(0.5)
    f16Out = MLIB_Round_F16(f16In1,u16In2);


    // Example no. 3
    // first input = -0.375
    f16In1 = FRAC16(-0.375);
    // second input = 13
    u16In2 = 13;

    // output should be 0xE000 ~ FRAC16(-0.25)
    f16Out = MLIB_Round_F16(f16In1,u16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif /* if defined __CWCC__ || defined __MWERKS__ */
/** @remarks Implements DMLIB00206, DMLIB00199, DMLIB00204 */
static inline tFrac16 MLIB_Round_F16(register tFrac16 f16In1,register tU16 u16In2)
/*
* @violates @ref MLIB_Round_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in
* header file.
*/
{
    /** @remarks Implements DMLIB00201, DMLIB00203 */
    /*
    * @violates @ref MLIB_Round_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
    * signed underlying type: &.
    * @violates @ref MLIB_Round_h_REF_7 MISRA 2004 Required Rule 10.3, Cast of complex expression
    * changes signedness.
    */
    return(MLIB_AddSat_F16(f16In1, (tFrac16)((tU16)MLIB_ShL_F16((tFrac16)1u, u16In2) >> 1u)) & MLIB_ShL_F16((tFrac16)0xFFFFu, u16In2));
}

#ifdef __cplusplus
}
#endif

#endif /* MLIB_ROUND_H */
