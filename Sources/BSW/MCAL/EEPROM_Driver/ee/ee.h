/************************************************************************
* (c) Copyright Freescale Semiconductor & STMicroelectronics,2010       *
*                        All Rights Reserved                            *
*************************************************************************

*************************************************************************
*                                                                       *
*                EEPROM Emulation driver for C90lc                      *
*                                                                       *
* FILE NAME     : ee_demo.h                                        	*
* DESCRIPTION   : This file consitutes of high level API's which user   *
*                 application needs to call for performing EEPROM       *
*                 emulation.                                            *
* DATE          : Sept 23, 2010                                         *
* AUTHOR        : FPT Team                                              *
* E-mail        : b33626@freescale.com                                  *
*                                                                       *
*************************************************************************/

/******************************* CHANGES ********************************
 0.0.1   08.09.2010           FPT Team               Initial Version
 0.1.0   09.23.2010           FPT Team               Update comments
 0.1.1   05.20.2011           FPT Team               Support fixed-length
                                                     data record.   									 	
************************************************************************/


#ifndef _EE_DEMO_H_
#define _EE_DEMO_H_

#include "ee_types.h"
#include "ee_emulation.h"


/* Flash Control Register */

#define C90LC_REG_BASE                  0xC3F8C000	/* Register base for Data Flash */
#define MAIN_ARRAY_BASE                 0x00800000

/* Unlock macro */
#define C90LC_LML_SLOCK					0x00100000	/* Shadow Lock */
#define C90LC_SLL_SSLOCK				0x00100000	/* Secondary Shadow Lock */

/******************************************************************************
*	                    Flash configuration				      * 
******************************************************************************/

/* Data low space block 0 */
#define LOW_BLOCK0_OFFSET               0x00000000	/* Offset of low block 0 */
#define LOW_BLOCK0_SIZE                 0x4000		/* 16KB size */
#define LOW_BLOCK0_MASK                 0x00000001

/* Data low space block 1 */
#define LOW_BLOCK1_OFFSET               0x00004000	/* Offset of low block 1 */
#define LOW_BLOCK1_SIZE                 0x4000    	/* 16KB size */
#define LOW_BLOCK1_MASK                 0x00000002

/* Data low space block 2 */
#define LOW_BLOCK2_OFFSET               0x00008000	/* Offset of low block 2 */
#define LOW_BLOCK2_SIZE                 0x4000		/* 16KB size */
#define LOW_BLOCK2_MASK                 0x00000004

/* Data low space block 3 */
#define LOW_BLOCK3_OFFSET								0x0000C000	/* Offset of low block 3 */
#define LOW_BLOCK3_SIZE									0x4000  	/* 16KB size */
#define LOW_BLOCK3_MASK									0x00000008

/* data record ID*/
#define DATA_ID_0       0
#define DATA_ID_1       1
#define DATA_ID_2       2
#define DATA_ID_3       3
#define DATA_ID_4       4
#define DATA_ID_5       5

/* demo return code*/
#define DEMO_OK         0
#define DEMO_FAILED     0xFFFF0000

#if (FIX_LENGTH == LENGTH_TYPE)
#define	BUFFER_SIZE_BYTE	DATA_SIZE + 0x10
#else
#define BUFFER_SIZE_BYTE	0x100
#endif


//====================================================//
//								added by xyl												//
//====================================================//
extern UINT8  srcBuffer[BUFFER_SIZE_BYTE];
extern UINT8  readBuffer[BUFFER_SIZE_BYTE];

extern void WriteRecordConfirmCallBack(void);
extern void ee_WriteRecord(UINT8 *dataPtr, UINT16	dataSize);
extern void ee_InitEeprom(void);
extern UINT16 ee_SearceIdTable(UINT8  *readPtr, UINT16 dataSize);
//!<===========================================================================================






#endif /*_EE_DEMO_H_*/
