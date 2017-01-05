/******************************************************************************
*
*   (c) Copyright 2015 Freescale Semiconductor, Inc.
*   All Rights Reserved.
*
******************************************************************************/
/*!
*
* @file     SWLIBS_Version.h
*
* @version  1.0.8.0
*
* @date     Mar-10-2014
*
* @brief    MCLIB version header file.
*
******************************************************************************/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section SWLIBS_Version_h_REF_1
* Violates MISRA 2004 Advisory Rule 6.3, Use of modifier or type 'unsigned char'
* outside of a typedef.
* The modifier is used within a typedef struct.
*/

#ifndef SWLIBS_VERSION_H_
#define SWLIBS_VERSION_H_

#include "SWLIBS_Config.h"

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
#define SWLIBS_MCID_SIZE ((unsigned char)4U)
#define SWLIBS_MCVERSION_SIZE ((unsigned char)3U)
#define SWLIBS_MCIMPLEMENTATION_SIZE ((unsigned char)9U)

#define SWLIBS_ID {(unsigned char)0x90U,(unsigned char)0x71U,(unsigned char)0x77U,(unsigned char)0x68U} /*!< Library identification string. */

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/***************************************************************************/
/*!
@struct SWLIBS_VERSION_T "\SWLIBS_Version.h"

@brief  Motor Control Library Set identification structure
*//*************************************************************************/
typedef struct
{
/*
* @violates @ref SWLIBS_Version_h_REF_1 MISRA 2004 Advisory Rule 6.3, Use of
* modifier or type 'unsigned char' outside of a typedef.
*/
  unsigned char mcId[SWLIBS_MCID_SIZE];                 /*!< MCLIB identification code */
/*
* @violates @ref SWLIBS_Version_h_REF_1 MISRA 2004 Advisory Rule 6.3, Use of
* modifier or type 'unsigned char' outside of a typedef.
*/
  unsigned char mcVersion[SWLIBS_MCVERSION_SIZE];       /*!< MCLIB version code */
/*
* @violates @ref SWLIBS_Version_h_REF_1 MISRA 2004 Advisory Rule 6.3, Use of
* modifier or type 'unsigned char' outside of a typedef.
*/
  unsigned char mcImpl[SWLIBS_MCIMPLEMENTATION_SIZE];   /*!< MCLIB supported implementation code */
}SWLIBS_VERSION_T;

const SWLIBS_VERSION_T* SWLIBS_GetVersion(void);

#endif /* SWLIBS_VERSION_H_ */
