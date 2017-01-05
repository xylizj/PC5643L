/*******************************************************************************
*
*  FILE
*     Dem_Cfg.h
*
*  DESCRIPTION
*     The Configuration Header file for Dem Module
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

#ifndef _DEM_CFG_H_
#define _DEM_CFG_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"
#include "Dem_Types.h"




#ifndef debug
  #define SECONDS(X)   (X)
  #define MINUTES(X)   (X*60UL)
  #define HOURS(X)     (X*3600UL)
  #define OBD_CYCLE(X)     (X*780UL)
#else
  #define SECONDS(X)      (X)
  #define MINUTES(X)          (X*1UL)
  #define HOURS(X)          (X*1UL)
  #define OBD_CYCLE(X)     (X*10UL)
#endif



#define TRQ_LMT_NONE      0
#define TRQ_LMT_IMM       1
#define TRQ_LMT_50H       2

#define MIL_LAMP_ON             0x40C0
#define WRN_LAMP_ON             0x040C
#define MIL_LAMP_BLINK          0x4000
#define MIL_LAMP_OFF            0x0
#define WRN_MIL_LAMP_ON         0x44CC
#define WRN_LAMP_ON_MIL_BLINK   0x440C

#define ERASABLE            0U
#define NON_ERASABLE        1U
#define IMMEDIATE_ERASE     2U

#define COUNTER_ENG_RUN     0U
#define COUNTER_TIME        1U
/*******************************************************************************
* Defines                                                                
*******************************************************************************/
#define DEM_DEV_ERROR_DETECT        STD_OFF



#define DEM_ENG_FAULT_NUM          96U

#define DEM_MEM_ENTRY_NUM           16U

#define DEM_HIS_MEM_ENTRY_NUM       20U

#define DEM_CLR_DELAY               100U

/* When set on, the fault memory placed in Ram and cannot be stored 
 simply used for debugger */
#define DEM_FAULT_MEM_DEBUG         STD_OFF

#define DEM_DM4_FREEZE_FRAME_LENGTH    29U

/* Event Id */

/* 1 - 32 OBD FAULT*/
#define NOX_OVER5                     0U
#define NOX_OVER7                     (NOX_OVER5 + 1)    //1
#define UREA_C2M                      (NOX_OVER7 + 1)    //2
#define NOX_OVER7_UREA_C2L            (UREA_C2M + 1) //3
#define UREA_TANK_HEATER_VLV_OC       (NOX_OVER7_UREA_C2L + 1)  //4
#define UREA_TANK_HEATER_VLV_STG      (UREA_TANK_HEATER_VLV_OC + 1)  //5
#define AIR_SUPPLY_VALVE_DEFECT       (UREA_TANK_HEATER_VLV_STG + 1) //6
#define NOX_SENSOR_HEATER_SC_DEFECT      (AIR_SUPPLY_VALVE_DEFECT + 1)       //7
#define NOX_SENSOR_HEATER_OC_DEFECT      (NOX_SENSOR_HEATER_SC_DEFECT + 1)       //8
#define NOX_SENSOR_SC_DEFECT          (NOX_SENSOR_HEATER_OC_DEFECT + 1) //9
#define NOX_SENSOR_OC_DEFECT          (NOX_SENSOR_SC_DEFECT + 1) //10
#define NOX_SENSOR_NO_OUTPUT          (NOX_SENSOR_OC_DEFECT + 1) //9
#define NOX_SENSOR_ABNORMAL           (NOX_SENSOR_NO_OUTPUT + 1)    //10
#define UREA_LVL_SENSOR_STP_OC        (NOX_SENSOR_ABNORMAL + 1)    //11
#define UREA_LVL_SENSOR_STG           (UREA_LVL_SENSOR_STP_OC + 1)//12
#define NOZZLE_JAM                    (UREA_LVL_SENSOR_STG + 1)  //13
#define AIR_SUPPLY_ABNORMAL           (NOZZLE_JAM + 1) //14
#define UREA_LEVEL_2LOW               (AIR_SUPPLY_ABNORMAL + 1)  //15
#define UREA_TANK_EMPTY               (UREA_LEVEL_2LOW + 1)        //16
#define REACTION_AGENT_QUAL_LOW       (UREA_TANK_EMPTY + 1)  //17
#define REACTION_AGENT_INTERRUPT      (REACTION_AGENT_QUAL_LOW + 1) //18
#define SCR_ABSENT                    (REACTION_AGENT_INTERRUPT + 1)   //19
#define PUMP_DEFECT                   (SCR_ABSENT + 1)                 //20
#define EGP_INLET_SENSOR_STP_OC       (PUMP_DEFECT + 1)               //21
#define EGP_INLET_SENSOR_STG          (EGP_INLET_SENSOR_STP_OC + 1)     //22
#define EGP_OUTLET_SENSOR_STP_OC      (EGP_INLET_SENSOR_STG + 1)  //23
#define EGP_OUTLET_SENSOR_STG         (EGP_OUTLET_SENSOR_STP_OC + 1)    //24
#define UREA_TEMP_SENSOR_STP_OC       (EGP_OUTLET_SENSOR_STG + 1)  //25
#define UREA_TEMP_SENSOR_STG          (UREA_TEMP_SENSOR_STP_OC + 1)   //26
#define UREA_TEMP_SENSOR_OOR          (UREA_TEMP_SENSOR_STG + 1)    //27
#define ENV_TEMP_SENSOR_STP_OC        (UREA_TEMP_SENSOR_OOR + 1)    //28
#define ENV_TEMP_SENSOR_STG           (ENV_TEMP_SENSOR_STP_OC + 1)  //29
#define PIPE_HEATER_STP_OC            (ENV_TEMP_SENSOR_STG + 1)     //30
#define PIPE_HEATER_STG               (PIPE_HEATER_STP_OC + 1)  //33



#define EEC1_TIME_OUT                  (34)
#define ET1_TIME_OUT                   (EEC1_TIME_OUT + 1)      //33
#define FIECO_TIME_OUT                 (ET1_TIME_OUT + 1)       //34
#define INCON_TIME_OUT                 (FIECO_TIME_OUT + 1)     //35
#define TCO1_TIME_OUT                  (INCON_TIME_OUT + 1)     //36
#define TD_TIME_OUT                    (TCO1_TIME_OUT + 1)      //37
#define VD_TIME_OUT                    (TD_TIME_OUT + 1)        //38
#define EEC2_TIME_OUT                  (VD_TIME_OUT + 1)        //39
#define DM1EECU_TIME_OUT               (EEC2_TIME_OUT + 1)       //40

#define EEPROM_DEF                     (DM1EECU_TIME_OUT + 1)    //41

#define DEM_EVENT_INNER_NUM             (EEPROM_DEF + 1)


#define EVENT_NUM_ENG_FAULT_START       (DEM_EVENT_INNER_NUM)

#define EVENT_NUM_MAX                 (EVENT_NUM_ENG_FAULT_START+DEM_ENG_FAULT_NUM-1)

#define DEM_EVENT_TOT_NUM              (EVENT_NUM_MAX + 1)

#define DEM_ENG_FAULT_DELETE_CNT        100U
#define DEM_ENG_FAULT_HEALING_CNT       20U
#define DEM_ENG_FAULT_CONFIRM_CNT       0U
#define DEM_ENG_FAULT_ERR_CLASS         2U



/*
 * Size limitations of storage area
 */
#define DEM_MAX_SIZE_FF_DATA					 10	// Max number of bytes in one freeze frame
#define DEM_MAX_SIZE_EXT_DATA					 10	// Max number of bytes in one extended data record
#define DEM_MAX_NUMBER_EVENT					100	// Max number of events to keep status on

#define DEM_MAX_NUMBER_EVENT_PRE_INIT			 20	// Max number of events status to keep before init
#define DEM_MAX_NUMBER_FF_DATA_PRE_INIT			 20	// Max number of freeze frames to store before init
#define DEM_MAX_NUMBER_EXT_DATA_PRE_INIT		 20	// Max number of extended data to store before init

#define DEM_MAX_NUMBER_EVENT_PRI_MEM			(DEM_MAX_NUMBER_EVENT_ENTRY_PRI)	// Max number of events status to store in primary memory
#define DEM_MAX_NUMBER_FF_DATA_PRI_MEM			5									// Max number of freeze frames to store in primary memory
#define DEM_MAX_NUMBER_EXT_DATA_PRI_MEM			5									// Max number of extended data to store in primary memory

#define DEM_MAX_NUMBER_AGING_PRI_MEM 1
#define DEM_MAX_NR_OF_CLASSES_IN_FREEZEFRAME_DATA 1
#define DEM_MAX_NR_OF_RECORDS_IN_FREEZEFRAME_DATA 1
#define DEM_DID_IDENTIFIER_SIZE_OF_BYTES 1
#define DEM_FREEZEFRAME_DEFAULT_VALUE 1
#define DEM_MAX_TIMESTAMP_FOR_REARRANGEMENT 1

/*OBD RequestCurrentPowertrainDiagnosticData*/
#define PIDZERO								0
#define PIDE0								0xE0
#define DATAZERO							0
#define INFOTYPE_ZERO						0
#define PID_LEN								1
#define RECORD_NUM 							0
#define HALF_BYTE 							4
#define OFFSET_ONE_BYTE						8
#define OFFSET_TWO_BYTES 					16
#define OFFSET_THREE_BYTES					24
#define SUPPRTED_PIDS_DATA_LEN				4
#define LEAST_BIT_MASK  					((uint8)0x01u)
#define OBD_DATA_LSB_MASK 					((uint32)0x000000FFu)
#define OBD_REQ_MESSAGE_LEN_ONE_MIN 		2
#define OBD_REQ_MESSAGE_LEN_MAX  			7
#define AVAIL_TO_SUPPORTED_PID_OFFSET_MIN  	0x01
#define AVAIL_TO_SUPPORTED_PID_OFFSET_MAX  	0x20
#define AVAIL_TO_SUPPORTED_INFOTYPE_OFFSET_MIN  	0x01
#define AVAIL_TO_SUPPORTED_INFOTYPE_OFFSET_MAX  	0x20
#define MAX_REQUEST_PID_NUM 				6
#define LENGTH_OF_DTC  						2

/*OBD RequestCurrentPowertrainDiagnosticData*/
#define FF_NUM_LEN							1
#define OBD_DTC_LEN							2
#define OBD_SERVICE_TWO 					((uint8)0x02u)
#define MAX_PID_FFNUM_NUM					3
#define OBD_REQ_MESSAGE_LEN_TWO_MIN			3

#if defined(DEM_MAX_NR_OF_RECORDS_IN_FREEZEFRAME_DATA)
#define DCM_MAX_PID_NUM_IN_FF				DEM_MAX_NR_OF_RECORDS_IN_FREEZEFRAME_DATA
#else
#define DCM_MAX_PID_NUM_IN_FF				0
#endif

/*OBD Requestvehicleinformation service09*/
#define OBD_TX_MAXLEN						0xFF
#define MAX_REQUEST_VEHINFO_NUM				6
#define OBD_SERVICE_FOUR 					0x04
#define OBD_VIN_LENGTH						17
#define OBD_CALID_LENGTH						16
/*******************************************************************************
* Macros                                                                
*******************************************************************************/
#define DEM_ENG_RUN() ((EEC1_EngSpd > 1600)&&(EEC1_EngSpd<0xFE00))

#if (DEM_ENG_FAULT_NUM % 16)
#define DEM_ENG_FAULT_WORD  ((DEM_ENG_FAULT_NUM/16) + 1)
#else
#define DEM_ENG_FAULT_WORD  ((DEM_ENG_FAULT_NUM/16))
#endif
/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/

/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/
extern const Dem_FaultCodeType Dem_ErrJ1939FaultCode[DEM_EVENT_INNER_NUM];
extern const Dem_EngFaultConfigType Dem_EngFaultCode[DEM_ENG_FAULT_NUM];

#endif /* #ifndef _DEM_CFG_H_ */





