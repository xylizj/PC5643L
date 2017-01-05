/*******************************************************************************
*
*  FILE
*     Det.c
*
*  DESCRIPTION
*     AUTOSAR Development Error Tracer (DET) implementation 
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

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Det.h"

/*******************************************************************************
* Defines                                                                
*******************************************************************************/

/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Constant definition                         
*******************************************************************************/

/*******************************************************************************
* Local Constant definition                         
*******************************************************************************/

/*******************************************************************************
* Global Variables definition                         
*******************************************************************************/
uint16 Det_ModuleId;
uint8 Det_InstanceId;
uint8 Det_ApiId;
uint8 Det_ErrorId;
/*******************************************************************************
* Local Variables definition                         
*******************************************************************************/

/*******************************************************************************
* Local Functions prototypes                         
*******************************************************************************/

/*******************************************************************************
*  Global Functions Body                                   
*******************************************************************************/

/****************************************************************************
* NAME:             Det_Init
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: void
* RETURN VALUES:    void
* DESCRIPTION:      Service to initialize the Development Error Tracer.   
****************************************************************************/
FUNC(void,TYPEDEF) Det_Init(void)
{
  Det_ModuleId = 0;
  Det_InstanceId = 0;
  Det_ApiId = 0;
  Det_ErrorId = 0;
}

/****************************************************************************
* NAME:             Det_ReportError
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: uint16 ModuleId
*                   uint8 InstanceId
*                   uint8 ApiId
*                   uint8 ErrorId
* RETURN VALUES:    void
* DESCRIPTION:      Service to report development errors.     
****************************************************************************/
FUNC(void,TYPEDEF) Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
  Det_ModuleId = ModuleId;
  Det_InstanceId = InstanceId;
  Det_ApiId = ApiId;
  Det_ErrorId = ErrorId;
/*
  for(;;)
  {
  }
*/
}

/****************************************************************************
* NAME:             Det_GetVersionInfo
* CALLED BY:        Application
* PRECONDITIONS:    
* INPUT PARAMETERS: Std_VersionInfoType *versioninfo
* RETURN VALUES:    void
* DESCRIPTION:      Service to get version information     
****************************************************************************/
FUNC(void,TYPEDEF) Det_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
  versioninfo->vendorID = DET_VENDOR_ID;
  versioninfo->moduleID = DET_MODULE_ID;
  versioninfo->sw_major_version = DET_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version = DET_SW_MINOR_VERSION;
  versioninfo->sw_patch_version = DET_SW_PATCH_VERSION;
}
