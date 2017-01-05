/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*   All Rights Reserved.
*
******************************************************************************/
/*!
*
* @file       GMCLIB_Park.h
*
* @version    1.0.7.0
*
* @date       Mar-10-2014
*
* @brief      Header file for GMCLIB_Park function
*
******************************************************************************/
#ifndef GMCLIB_PARK_H
#define GMCLIB_PARK_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GMCLIB_Park_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section GMCLIB_Park_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section GMCLIB_Park_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section GMCLIB_Park_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*/
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  /*
  * @violates @ref GMCLIB_Park_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref GMCLIB_Park_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref GMCLIB_Park_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define GMCLIB_Park(...)     macro_dispatcher(GMCLIB_Park, __VA_ARGS__)(__VA_ARGS__)     /*!< This function implements the calculates Park transformation. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref GMCLIB_Park_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref GMCLIB_Park_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref GMCLIB_Park_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DGMCLIB00026 */
    #define GMCLIB_Park_Dsptchr_3(pOut,pInAngle,pIn)     GMCLIB_Park_Dsptchr_4(pOut,pInAngle,pIn,F32)     /*!< Function dispatcher for GMCLIB_Park_Dsptchr_3, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref GMCLIB_Park_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref GMCLIB_Park_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref GMCLIB_Park_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DGMCLIB00026 */
    #define GMCLIB_Park_Dsptchr_3(pOut,pInAngle,pIn)     GMCLIB_Park_Dsptchr_4(pOut,pInAngle,pIn,F16)     /*!< Function dispatcher for GMCLIB_Park_Dsptchr_3, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /*
    * @violates @ref GMCLIB_Park_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref GMCLIB_Park_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref GMCLIB_Park_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DGMCLIB00026 */
    #define GMCLIB_Park_Dsptchr_3(pOut,pInAngle,pIn)     GMCLIB_Park_Dsptchr_4(pOut,pInAngle,pIn,FLT)     /*!< Function dispatcher for GMCLIB_Park_Dsptchr_3, do not modify!!! */
  #endif

  /*
  * @violates @ref GMCLIB_Park_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref GMCLIB_Park_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref GMCLIB_Park_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define GMCLIB_Park_Dsptchr_4(pOut,pInAngle,pIn,Impl)    GMCLIB_Park_Dsptchr_(pOut,pInAngle,pIn,Impl)     /*!< Function dispatcher for GMCLIB_Park_Dsptchr_4, do not modify!!! */

  /*
  * @violates @ref GMCLIB_Park_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref GMCLIB_Park_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref GMCLIB_Park_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  * @violates @ref GMCLIB_Park_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
  */
  /** @remarks Implements DGMCLIB00028 */
  #define GMCLIB_Park_Dsptchr_(pOut,pInAngle,pIn,Impl)     GMCLIB_Park_##Impl(pOut,pInAngle,pIn)            /*!< Function dispatcher for GMCLIB_Park_Dsptchr_, do not modify!!! */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_Park_F32(SWLIBS_2Syst_F32 *pOut,const SWLIBS_2Syst_F32 *const pInAngle,const SWLIBS_2Syst_F32 *const pIn);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_Park_F16(SWLIBS_2Syst_F16 *pOut,const SWLIBS_2Syst_F16 *const pInAngle,const SWLIBS_2Syst_F16 *const pIn);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern void GMCLIB_Park_FLT(SWLIBS_2Syst_FLT *pOut,const SWLIBS_2Syst_FLT *const pInAngle,const SWLIBS_2Syst_FLT *const pIn);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
/****************************************************************************
* Inline functions
****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* GMCLIB_PARK_H */