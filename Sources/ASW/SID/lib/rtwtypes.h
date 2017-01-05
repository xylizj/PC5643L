/*******************************************************************************
 *  Real-Time Workshop code generated for Simulink model < SID_F >
 *
 *  File: rtwtypes.h
 *  File Creation Date: 11-May-2016
 *  Code generated on : Wed May 11 09:47:50 2016
 *  Abstraction:
 *  Notes:
 *
 *  Model Information:
 *  Model Name: SID_F
 *  Model Version: 1.513
 *  Model Description:
 *  Creation date:	Mon Apr 21 14:27:52 2014
 *  Last Saved Modification:   Wed May 11 09:46:38 2016
 *
 *  (c)Copyright 2014-2016£¬Wuhan Eureka Control Co., Ltd.
 *******************************************************************************/
/******************************************************************************
 *  Include files
 ******************************************************************************/

/*****************************************************************************
 *  Defines
 *****************************************************************************/
#ifndef __RTWTYPES_H__
#define __RTWTYPES_H__

/* Logical type definitions */
#if (!defined(__cplusplus))
#  ifndef false
#   define false                       (0U)
#  endif

#  ifndef true
#   define true                        (1U)
#  endif
#endif

#define __TMWTYPES__

/*=======================================================================*
 * Target hardware information
 *   Device type: Freescale->32-bit PowerPC
 *   Number of bits:     char:   8    short:   16    int:  32
 *                       long:  32
 *                       native word size:  32
 *   Byte ordering: BigEndian
 *   Signed integer division rounds to: Zero
 *   Shift right on a signed integer as arithmetic shift: on
 *=======================================================================*/

/*=======================================================================*
 * Fixed width word size data types:                                     *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;

/*===========================================================================*
 * Generic type definitions: boolean_T, int_T, uint_T, ulong_T, char_T,      *
 *                           and byte_T.                                     *
 *===========================================================================*/
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

/*=======================================================================*
 * Min and Max:                                                          *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255U))
#define MIN_uint8_T                    ((uint8_T)(0U))
#define MAX_int16_T                    ((int16_T)(32767))
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535U))
#define MIN_uint16_T                   ((uint16_T)(0U))
#define MAX_int32_T                    ((int32_T)(2147483647))
#define MIN_int32_T                    ((int32_T)(-2147483647-1))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))
#define MIN_uint32_T                   ((uint32_T)(0U))

/* Block D-Work pointer type */
typedef void * pointer_T;

/* Define Simulink Coder replacement data types. */
#include "Rte_Type.h"                  /* User defined replacement datatype for int8_T uint8_T int16_T uint16_T int32_T uint32_T boolean_T int_T uint_T char_T  */

/* Simulink specific types */
#ifndef __ZERO_CROSSING_TYPES__
#define __ZERO_CROSSING_TYPES__

/* Trigger directions: falling, either, and rising */
typedef enum
{
    FALLING_ZERO_CROSSING = -1,
    ANY_ZERO_CROSSING = 0,
    RISING_ZERO_CROSSING = 1
}
ZCDirection;

/* Previous state of a trigger signal */
typedef uint8_T ZCSigState;

/* Initial value of a trigger zero crossing signal */
#define UNINITIALIZED_ZCSIG            0x03U
#define NEG_ZCSIG                      0x02U
#define POS_ZCSIG                      0x01U
#define ZERO_ZCSIG                     0x00U

/* Current state of a trigger signal */
typedef enum
{
    FALLING_ZCEVENT = -1,
    NO_ZCEVENT = 0,
    RISING_ZCEVENT = 1
}
ZCEventType;

#endif                                 /* __ZERO_CROSSING_TYPES__ */
#endif                                 /* __RTWTYPES_H__ */

/*****************************************************************************
 *  Data Types
 *****************************************************************************/

/*****************************************************************************
 *  Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Declarations
 *****************************************************************************/

/*****************************************************************************
 *  Global Function Declaration
 *****************************************************************************/

/*======================== TOOL VERSION INFORMATION ==========================*
 * MATLAB 8.3 (R2014a)27-Dec-2013                                             *
 * Simulink 8.3 (R2014a)27-Dec-2013                                           *
 * Simulink Coder 8.6 (R2014a)27-Dec-2013                                     *
 * Embedded Coder 6.6 (R2014a)27-Dec-2013                                     *
 * Stateflow 8.3 (R2014a)27-Dec-2013                                          *
 * Fixed-Point Designer 4.2 (R2014a)27-Dec-2013                               *
 *============================================================================*/

/*======================= LICENSE IN USE INFORMATION =========================*
 * fixed_point_toolbox                                                        *
 * matlab_coder                                                               *
 * real-time_workshop                                                         *
 * rtw_embedded_coder                                                         *
 * simulink                                                                   *
 * stateflow                                                                  *
 *============================================================================*/
