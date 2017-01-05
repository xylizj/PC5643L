/*******************************************************************************
*
*  FILE
*     Det.h
*
*  DESCRIPTION
*      AUTOSAR Development Error Tracer (DET) header file.
*      
*       
*  COPYRIGHT
*     
*     All rights reserved.
*
*  AUTHOR
*    
*
*  VERSION
*    1.00
*
*******************************************************************************/

#ifndef _DET_H_
#define _DET_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
* Defines                                                                
*******************************************************************************/

/* Vendor ID. */
#define DET_VENDOR_ID           6666

/* Module ID of Development Error Tracer. */
#define DET_MODULE_ID           15

/* Version number of the module. */
#define DET_SW_MAJOR_VERSION    1
#define DET_SW_MINOR_VERSION    0
#define DET_SW_PATCH_VERSION    0

/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/

/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/
extern FUNC(void,TYPEDEF) Det_Init(void);
extern FUNC(void,TYPEDEF) Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
extern FUNC(void,TYPEDEF) Det_GetVersionInfo(Std_VersionInfoType* versioninfo);

#endif /* #ifndef _DET_H_ */
