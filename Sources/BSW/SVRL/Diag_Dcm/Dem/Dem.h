/*******************************************************************************
*
*  FILE
*     Dem.h
*
*  DESCRIPTION
*     The Header file for Dem Module
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
*    1.1.0
*
*******************************************************************************/

#ifndef _DEM_H_
#define _DEM_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"
#include "Dem_Types.h"
#include "Dem_Cfg.h"

/*******************************************************************************
* Defines                                                                
*******************************************************************************/

/* Vendor ID. */
#define DEM_VENDOR_ID           6666

/* Module ID  */
#define DEM_MODULE_ID           54

/* Version number of the module */
#define DEM_SW_MAJOR_VERSION    1
#define DEM_SW_MINOR_VERSION    0
#define DEM_SW_PATCH_VERSION    0

#define DEM_INSTANCE_ID                       1

#define DEM_API_SETERROR_ID                   1
#define DEM_API_ERRMEMUPDATE_ID               2


#define DEM_E_INVALID_INDEX                   1
#define DEM_E_INVALID_ERRSTATUS               2


#define DEM_ERR_MEM_UPDATE_OK         ((uint8)0)
#define DEM_ERR_MEM_FULL              ((uint8)1)
#define DEM_ERR_MEM_INDEX_NA          ((uint8)2)

//#define DEM_ERRMEM_PASSIVE               ((uint8)0)
//#define DEM_ERRMEM_ACTIVE                ((uint8)1)

//#define DEM_ERR_STATUS_MAX            (DEM_ERRMEM_ACTIVE)

#define DEM_NOT_FOUND                 ((uint8)0xFF)

#define DEM_NO_ERR                    ((uint8)0xFF)

#define DEM_NO_PARAM                  ((uint8)0xFF)

#define DEM_MAX_ERR_CLASS             ((uint8)0xFF)

#define DEM_EVENT_ID_NA               ((Dem_EventIdType)0xFFFF)

#define DEM_NO_TRQ_LMT                ((uint32)0xFFFFFFFF)
/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/
extern boolean dem_TrqLmtOut;
extern VAR(boolean,DEM_VAR) Dem_stClear;
extern Dem_FaultMemType dem_ErrMemoEntry[DEM_MEM_ENTRY_NUM];
extern VAR(uint8,DEM_VAR) dem_MemEntryNextEmpty;
extern void Dem_UpdateOperCycle(void);

/*******************************************************************************
* Global Constant declaration                         
*******************************************************************************/
#ifndef OBD_TEST
extern CONST(boolean,DEM_CONST) Dem_stClear_C;
#else
extern boolean Dem_stClear_C;
#endif


/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/
extern void DEM_CODE  Dem_Init(void);
extern void DEM_CODE  Dem_MainFunction(void);
extern void DEM_CODE  Dem_FaultMemClearAll(void);
extern FUNC(Std_ReturnType,DEM_CODE)  Dem_SetError(Dem_EventIdType EventId, uint8 EventStatus);
extern FUNC(uint8,DEM_CODE) Dem_DM1Assembly(uint8* dataPtr,uint8 maxLength);
extern FUNC(uint8,DEM_CODE) Dem_GetError(Dem_EventIdType EventId);
extern FUNC(void,DEM_CODE) Dem_ApplDrvCycleRisingEdge(void);
extern FUNC(Std_ReturnType,DEM_CODE) Dem_ApplWarmUpCycleRisingEdge(void);

extern uint8 DEM_CODE Dem_DM4Assembly(uint8* dataPtr,uint8 maxErrNum);
extern uint8 DEM_CODE Dem_GetEmRelatedDtcNumAMil(void);
extern uint8 DEM_CODE Dem_ReqEmRelatedDTC(uint8* buffer);
extern void DEM_CODE Dem_TestClrFault(uint8 type, boolean complete);
extern uint8 DEM_CODE Dem_ReprotDtcByStatusMask(uint8* buffer);
extern uint8 DEM_CODE Dem_ReprotDtcSnapshotbyDTCNum(uint8* buffer);
extern void Dem_UpdEngFaultCnt(void);
extern void DEM_CODE Dem_ChkEngFault(void);



//!<	====================================================================
//!<	================	add by xyl 2015-08-04	=================
extern Std_ReturnType Dem_ApplGetPID01(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID04(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID05(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID0B(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID0C(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID0D(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID0F(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID1C(uint8 *txBuffer);

extern Std_ReturnType Dem_ApplGetPID04FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID05FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID0BFreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID0CFreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPID0DFreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPIDE1FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPIDE2FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPIDE3FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPIDE4FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPIDE5FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPIDE6FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPIDE7FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPIDE8FreezeData(uint8 *txBuffer);
extern Std_ReturnType Dem_ApplGetPIDE9FreezeData(uint8 *txBuffer);


extern Std_ReturnType Dem_GetFreezeFramePids(uint8 Pid,uint32 *Data);
extern Std_ReturnType Dem_GetDTCOfOBDFreezeFrame(uint8 FrameNumber, uint32* DTC );
extern Std_ReturnType Dem_GetOBDFreezeFrameData(uint8 PID, uint8* DestBuffer, uint8* BufSize);
extern Std_ReturnType Dem_ApplInfoType02(uint8 *txBuffer);

#endif /* #ifndef _DEM_H_ */
