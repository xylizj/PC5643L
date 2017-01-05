/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*   All Rights Reserved.
*
******************************************************************************/
/*!
*
* @file     SWLIBS_Typedefs.h
*
* @version  1.0.12.0
*
* @date     Jul-10-2015
*
* @brief    Basic types definition file.
*
*******************************************************************************
*
******************************************************************************/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section SWLIBS_Typedefs_h_REF_1
* Violates MISRA 2004 Required Rule 20.2, Re-use of C90 identifier.
* NULL symbol is redefined only in case, that null pointer is not defined by compiler.
*
* @section SWLIBS_Typedefs_h_REF_2
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*/

#ifndef SWLIBS_TYPEDEFS_H
#define SWLIBS_TYPEDEFS_H

#include "SWLIBS_Config.h"
#include "SWLIBS_MacroDisp.h"

/******************************************************************************
* Implementation configuration checking            (scope: module-global)
******************************************************************************/
 #if((SWLIBS_DEFAULT_IMPLEMENTATION != SWLIBS_DEFAULT_IMPLEMENTATION_F32)&& \
      (SWLIBS_DEFAULT_IMPLEMENTATION != SWLIBS_DEFAULT_IMPLEMENTATION_F16)&& \
      (SWLIBS_DEFAULT_IMPLEMENTATION != SWLIBS_DEFAULT_IMPLEMENTATION_FLT))
    #error "Define default implementation in SWLIBS_Config.h file."
  #endif

  #if((SWLIBS_SUPPORT_F32 == SWLIBS_STD_OFF)&&(SWLIBS_SUPPORT_F16 == SWLIBS_STD_OFF)&&(SWLIBS_SUPPORT_FLT == SWLIBS_STD_OFF))
    #error "Define at least one supported implementation in SWLIBS_Config.h file."
  #endif

  #if((SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)&&(SWLIBS_SUPPORT_F32 == SWLIBS_STD_OFF))
    #error "Set the SWLIBS_SUPPORT_F32 to SWLIBS_STD_ON in SWLIBS_Config.h file to support FRAC32 default implementation."
  #endif

  #if((SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)&&(SWLIBS_SUPPORT_F16 == SWLIBS_STD_OFF))
    #error "Set the SWLIBS_SUPPORT_F16 to SWLIBS_STD_ON in SWLIBS_Config.h file to support FRAC16 default implementation."
  #endif

  #if((SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)&&(SWLIBS_SUPPORT_FLT == SWLIBS_STD_OFF))
    #error "Set the SWLIBS_SUPPORT_FLT to SWLIBS_STD_ON in SWLIBS_Config.h file to support FLOAT default implementation."
  #endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
#ifndef NULL
  #ifdef __cplusplus
    #define NULL ((void*)0)
  #else
    /*
    * @violates @ref SWLIBS_Typedefs_h_REF_1 MISRA 2004 Required Rule 20.2, Re-use of C90
    * identifier.
    */
    #define NULL 0
  #endif
#endif /* NULL */


/******************************************************************************
* Defines and macros            (scope: module-global)
******************************************************************************/


/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
typedef unsigned char       tBool;          /*!< basic boolean type */

#ifndef FALSE
#define FALSE ((tBool)0)                    /*!< Boolean type FALSE constant */
#endif

#ifndef TRUE
#define TRUE ((tBool)1)                     /*!< Boolean type TRUE constant */
#endif

typedef unsigned char       tU8;            /*!< unsigned 8-bit integer type */
typedef signed char         tS8;            /*!< signed 8-bit integer type */
typedef unsigned short      tU16;           /*!< unsigned 16-bit integer type */
typedef signed short        tS16;           /*!< signed 16-bit integer type */
typedef unsigned long       tU32;           /*!< unsigned 32-bit integer type */
typedef signed long         tS32;           /*!< signed 32-bit integer type */
typedef signed long long    tS64;           /*!< signed 64-bit integer type */
typedef tS16                tFrac16;        /*!< 16-bit signed fractional Q1.15 type */
typedef tS32                tFrac32;        /*!< 32-bit Q1.31 type */
typedef float               tFloat;         /*!< single precision float type */
typedef double              tDouble;        /*!< double precision float type */


/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref SWLIBS_Typedefs_h_REF_2 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define SWLIBS_2Syst    SWLIBS_2Syst_F32                        /*!< Definition of SWLIBS_2Syst as alias for SWLIBS_2Syst_F32 array in case the 32-bit fractional implementation is selected. */
    /*
    * @violates @ref SWLIBS_Typedefs_h_REF_2 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define SWLIBS_3Syst    SWLIBS_3Syst_F32                        /*!< Definition of SWLIBS_3Syst as alias for SWLIBS_3Syst_F32 array in case the 32-bit fractional implementation is selected. */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref SWLIBS_Typedefs_h_REF_2 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define SWLIBS_2Syst    SWLIBS_2Syst_F16                        /*!< Definition of SWLIBS_2Syst as alias for SWLIBS_2Syst_F16 array in case the 16-bit fractional implementation is selected. */
    /*
    * @violates @ref SWLIBS_Typedefs_h_REF_2 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define SWLIBS_3Syst    SWLIBS_3Syst_F16                        /*!< Definition of SWLIBS_3Syst as alias for SWLIBS_3Syst_F16 array in case the 16-bit fractional implementation is selected. */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /*
    * @violates @ref SWLIBS_Typedefs_h_REF_2 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define SWLIBS_2Syst    SWLIBS_2Syst_FLT                        /*!< Definition of SWLIBS_2Syst as alias for SWLIBS_2Syst_FLT array in case the single precision floating point implementation is selected. */
    /*
    * @violates @ref SWLIBS_Typedefs_h_REF_2 MISRA 2004 Required Rule 19.4, Disallowed definition
    * for macro.
    */
    #define SWLIBS_3Syst    SWLIBS_3Syst_FLT                        /*!< Definition of SWLIBS_3Syst as alias for SWLIBS_3Syst_FLT array in case the single precision floating point implementation is selected. */
  #endif


#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
/************************************************************************//*!
@struct SWLIBS_3Syst_F32 "\SWLIBS_Typedefs.h"

@brief  Array of three standard 32-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac32 f32Arg1;   /*!< First argument */
    tFrac32 f32Arg2;   /*!< Second argument */
    tFrac32 f32Arg3;   /*!< Third argument */
  } SWLIBS_3Syst_F32;

/************************************************************************//*!
@struct SWLIBS_2Syst_F32 "\SWLIBS_Typedefs.h"

@brief  Array of two standard 32-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac32 f32Arg1;   /*!< First argument */
    tFrac32 f32Arg2;   /*!< Second argument */
  } SWLIBS_2Syst_F32;
#endif


#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
/************************************************************************//*!
@struct SWLIBS_3Syst_F16 "\SWLIBS_Typedefs.h"

@brief  Array of three standard 16-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac16 f16Arg1;   /*!< First argument */
    tFrac16 f16Arg2;   /*!< Second argument */
    tFrac16 f16Arg3;   /*!< Third argument */
  } SWLIBS_3Syst_F16;

/************************************************************************//*!
@struct SWLIBS_2Syst_F16 "\SWLIBS_Typedefs.h"

@brief  Array of two standard 16-bit fractional arguments.
*//*************************************************************************/
  typedef struct
  {
    tFrac16 f16Arg1;   /*!< First argument */
    tFrac16 f16Arg2;   /*!< Second argument */
  } SWLIBS_2Syst_F16;
#endif


#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/************************************************************************//*!
@struct SWLIBS_3Syst_FLT "\SWLIBS_Typedefs.h"

@brief  Array of three standard single precision floating point arguments.
*//*************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  typedef struct
  {
    tFloat fltArg1;   /*!< First argument */
    tFloat fltArg2;   /*!< Second argument */
    tFloat fltArg3;   /*!< Third argument */
  } SWLIBS_3Syst_FLT;
#endif

/************************************************************************//*!
@struct SWLIBS_2Syst_FLT "\SWLIBS_Typedefs.h"

@brief  Array of two standard single precision floating point arguments.
*//*************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  typedef struct
  {
    tFloat fltArg1;   /*!< First argument */
    tFloat fltArg2;   /*!< Second argument */
  } SWLIBS_2Syst_FLT;
#endif
#endif

#endif /* SWLIBS_TYPEDEFS_H */
