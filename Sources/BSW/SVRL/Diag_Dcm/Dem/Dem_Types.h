/*******************************************************************************
*
*  FILE
*     Dem_Types.h
*
*  DESCRIPTION
*     The Data Type Header file for Dem Module  
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

#ifndef _DEM_TYPES_H_
#define _DEM_TYPES_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
* Defines                                                                
*******************************************************************************/
typedef uint32 Dem_ChksumType;
typedef uint8  Dem_ErrStatusLengthType;
typedef uint8  Dem_EventIdType;


#define DEM_ERRMEM_PASSIVE       0
#define DEM_ERRMEM_ACTIVE        1
#define DEM_ERRMEM_CONFIRMED     2
#define DEM_ERRMEM_HEALING       3
#define DEM_ERRMEM_POST_HEAL     4
#define DEM_ERRMEM_DELETING      5
#define DEM_ERR_STATUS_MAX    (DEM_ERRMEM_DELETING)
  
#define DEM_SEVERITY_NO_SEVERITY          0x00
#define DEM_SEVERITY_MAINTENANCE_ONLY     0x20
#define DEM_SEVERITY_CHECK_AT_NEXT_HALT   0x40
#define DEM_SEVERITY_IMMEDIATELY          0x80

#define DEM_DTC_EMMISSION_TYPE              0x01
#define DEM_DTC_COMMUNICATION_TYPE          0x02
#define DEM_DTC_POWERTRAIN_TYPE             0x04

typedef uint8 Dem_ErrMemStatusType;

typedef uint8 Dem_DTCKindType;

typedef uint8 Dem_DTCSeverityType;




typedef struct
{
  bittype testFailed:1;
  bittype testFailedThisOpCycle:1;
  bittype pendingDTC:1;
  bittype confirmedDTC:1;
  bittype testNotCompletedSinceLastClr:1;
  bittype testFailedSinceLastClr:1;
  bittype testNotCompletedThisOpCycle:1;
  bittype warningIndicatorRequest:1;      
}Dem_EventStatusExtendedType;

typedef struct {
  uint16 SPN;
  uint8 FMI;
  uint32 DtcCode;
  uint8 ErrorClass:3;
  uint8 dtcKind:5;
  uint16 LampStatus;
  uint16 ConfirmCounter;
  uint16 HealingCounter;
  uint8 CounterType:2;
  uint8 ErrorType:3;
  uint8 TorqueLimitType:3;  
}Dem_FaultCodeType;

typedef struct
{
  uint32 SPN_FMI;
  uint16 Dtc;
}Dem_EngFaultConfigType;


// 4
typedef struct { 
  Dem_EventIdType EventId;
  uint8 ErrClass;
  Dem_ErrMemStatusType ErrState;
  uint8 ErrOccurCounter; 
  uint32 StsUpdCnt;   
  uint32 TrqLmtEngRunCnt; 
  uint8 WarmUpCycleCounter;
  uint8 EngTrqMode;  
  uint8 BoostPressure; 
  uint16 EngSpd; 
  uint8 EngLoad;
  uint8 EngTemp;
  uint16 Velocity;
  uint32 Odometer;  
  uint16 BattVolt; 
  uint8 Year;
  uint8 Month;
  uint8 Day;
  uint8 Hour;
  uint8 Minute;
  uint8 Second;     
  uint32 EngRunTimeSinceMILOn;
  uint16 Nox;         //add by mt 20150828
  uint16 UreaLvl;     //add by mt 20150828 
  uint8  CycCntSinceErrOccur;                                                             
}Dem_FaultMemType;

typedef enum
{
  ALL_DTC      = 0,
  ACTIVE_DTC   = 1,
  INACTIVE_DTC = 2    
}Dem_DtcType;

typedef struct
{
  bittype active:1;
  bittype mem:1;
  bittype resv:6;
}Dem_FaultStatusBitType;

typedef union
{
  uint8 byte;
  Dem_FaultStatusBitType Bits;
}Dem_FaultStatusType;




/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/

/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/

#endif /* #ifndef _DEM_TYPES_H_ */
