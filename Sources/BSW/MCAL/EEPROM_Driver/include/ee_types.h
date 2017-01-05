/************************************************************************
* (c) Copyright Freescale Semiconductor & STMicroelectronics,Inc 2010   *
*                        All Rights Reserved                            *
*************************************************************************

*************************************************************************
*                                                                       *
*                EEPROM Emulation driver for C90lc                      *
*                                                                       *
* FILE NAME     : ee_types.h                                            *
* DESCRIPTION   : This file type defines the data types for EED         *
*                 functions.                                            *
* DATE          : Sep 23, 2010                                          *
* AUTHOR        : FPT Team                                              *
* E-mail        : b33626@freescale.com                                  *
*                                                                       *
*************************************************************************/

/******************************* CHANGES *********************************
 0.0.1   08.04.2010          FPT Team      Initial Version
 0.1.0   09.23.2010          FPT Team      Update comments
*************************************************************************/

#ifndef _EE_TYPES_H_
#define _EE_TYPES_H_

/*******************************************************************
| typedefs and structures (scope: module-local)
|------------------------------------------------------------------*/
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

typedef unsigned char BOOL;

typedef signed char INT8;
typedef unsigned char UINT8;
typedef volatile signed char VINT8;
typedef volatile unsigned char VUINT8;

typedef signed short INT16;
typedef unsigned short UINT16;
typedef volatile signed short VINT16;
typedef volatile unsigned short VUINT16;

typedef signed long INT32;
typedef unsigned long UINT32;
typedef volatile signed long VINT32;
typedef volatile unsigned long VUINT32;

typedef signed long long INT64;
typedef unsigned long long UINT64;
typedef volatile signed long long VINT64;
typedef volatile unsigned long long VUINT64;

#endif  /*_EE_TYPES_H_*/
