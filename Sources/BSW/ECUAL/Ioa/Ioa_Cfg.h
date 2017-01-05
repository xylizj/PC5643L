/*******************************************************************************
*
*  FILE
*     Ioa_Cfg.h
*
*  DESCRIPTION
*     The Configuration Header file for IO abstraction
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
*    0.01
*
*******************************************************************************/

#ifndef _IOA_CFG_H_
#define _IOA_CFG_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
* Defines                                                                
*******************************************************************************/



































/* Mapping Sensor to HW (AD) */

#define TLE5205   0
#define TLE5206   1


#define IOA_DRIVE_CHIP       TLE5206

/*
#define IOA_AD_PRESSURE_SIG_CH              0U
#define IOA_AD_5V_CH                        1U
#define IOA_AD_PRESSURE_SPLY_CH             2U
#define IOA_AD_LIQUID_SIG_A_CH              3U
#define IOA_AD_LIQUID_SIG_B_CH              4U
#define IOA_AD_10V_CH                       6U
#define IOA_AD_MULTI_CH                     7U
*/
#define IOA_AD_MULTI_CH                     7U
#define IOA_AD_CAT_TEMP_IN_CH               6U
#define IOA_AD_SHELL_TEMP_CH                5U
#define IOA_AD_PRESSURE_SIG_CH              4U
#define IOA_AD_PUMP_TEMP_CH                 3U
#define IOA_AD_UREA_TANK_TEMP_CH            2U
#define IOA_AD_CAT_TEMP_OUT_CH              1U
#define IOA_AD_UREA_TANK_LVL_CH             0U

#define IOA_AD_5V_GAIN                      11U
#define IOA_AD_10V_GAIN                     11U
#define IOA_AD_BATT_GAIN                    11U

/*
#define IOA_SENS_SPLY_NOM_GAIN              205U
#define IOA_SENS_SPLY_DENOM_GAIN            178U
*/

#define IOA_SENS_SPLY_NOM_GAIN              11U
#define IOA_SENS_SPLY_DENOM_GAIN            1U

#define IOA_AD_MULTI_UREA_PIPELINE_CH       0U
#define IOA_AD_MULTI_24V_CH                 1U
#define IOA_AD_MULTI_PRESSURE_SPLY_CH             2U
#define IOA_AD_MULTI_10V_CH                       3U
#define IOA_AD_MULTI_5V_CH                        4U

/* Mapping Sensor to HW (Switch) */

/* Mapping AD MUX CONTROL to HW  */
#define IOA_DO_AD_MUX_CH_A_CH               5U
#define IOA_DO_AD_MUX_CH_A_PORT             DIO_PORTV_DO
#define IOA_DO_AD_MUX_CH_A_DIR              DIO_PORTV_DIR

#define IOA_DO_AD_MUX_CH_B_CH               6U
#define IOA_DO_AD_MUX_CH_B_PORT             DIO_PORTV_DO
#define IOA_DO_AD_MUX_CH_B_DIR              DIO_PORTV_DIR

#define IOA_DO_AD_MUX_CH_C_CH               7U
#define IOA_DO_AD_MUX_CH_C_PORT             DIO_PORTV_DO
#define IOA_DO_AD_MUX_CH_C_DIR              DIO_PORTV_DIR

/* Sensor Supply Control  */

#define IOA_DO_PRESSURE_SPLY_CTL_CH         4
#define IOA_DO_PRESSURE_SPLY_CTL_PORT       DIO_PORTV_DO
#define IOA_DO_PRESSURE_SPLY_CTL_DIR        DIO_PORTV_DIR

/* Power Supply Control  */

#define IOA_DO_PWR_CTL_CH                   2
#define IOA_DO_PWR_CTL_PORT                 DIO_PORTV_DO
#define IOA_DO_PWR_CTL_DIR                  DIO_PORTV_DIR
/* Control  */
#define IOA_DO_TQ_OUT_CTL_CH                3
#define IOA_DO_TQ_OUT_CTL_PORT              DIO_PORTR_DO
#define IOA_DO_TQ_OUT_CTL_DIR               DIO_PORTR_DIR

/*  MOS 9226 */
// Ctl_Dig_Valve1
#define IOA_DO_PUMP_HEATER_VLV1_CTL_CH             3
#define IOA_DO_PUMP_HEATER_VLV1_CTL_PORT           DIO_PORTB_DO
#define IOA_DO_PUMP_HEATER_VLV1_CTL_DIR            DIO_PORTB_DIR

/*   BTS723 */
// Ctl_Dig_Valve3
#define IOA_DO_AIR_SWT_VLV_CTL_CH                 7
#define IOA_DO_AIR_SWT_VLV_CTL_PORT               DIO_PORTU_DO
#define IOA_DO_AIR_SWT_VLV_CTL_DIR                DIO_PORTU_DIR

// Ctl_Dig_Valve4
#define IOA_DO_COOL_VLV_CTL_DIR                 DIO_PORTU_DIR
#define IOA_DO_COOL_VLV_CTL_CH                  4
#define IOA_DO_COOL_VLV_CTL_PORT                DIO_PORTU_DO

// Ctl_Dig_Valve7
#define IOA_DO_PUMP_VLV_CTL_CH                 3
#define IOA_DO_PUMP_VLV_CTL_PORT               DIO_PORTP_DO
#define IOA_DO_PUMP_VLV_CTL_DIR                DIO_PORTP_DIR

#define IOA_DO_RELAY_CTL_CH                 0
#define IOA_DO_RELAY_CTL_PORT               DIO_PORTU_DO
#define IOA_DO_RELAY_CTL_DIR                DIO_PORTU_DIR


/* Mapping Feed Back to HW  */
//Fed_Dig_Valve1
#define IOA_DI_PUMP_HEATER_VLV1_FDBK_CH               3U
#define IOA_DI_PUMP_HEATER_VLV1_FDBK_PORT             DIO_PORTV_DI
#define IOA_DI_PUMP_HEATER_VLV1_FDBK_DIR              DIO_PORTV_DIR

//Fed_Dig_Valve3
#define IOA_DI_AIR_SWT_VLV_FDBK_CH               6U
#define IOA_DI_AIR_SWT_VLV_FDBK_PORT             DIO_PORTU_DI
#define IOA_DI_AIR_SWT_VLV_FDBK_DIR              DIO_PORTU_DIR

//Fed_Dig_Valve4
#define IOA_DI_COOL_VLV_FDBK_CH               5U
#define IOA_DI_COOL_VLV_FDBK_PORT             DIO_PORTU_DI
#define IOA_DI_COOL_VLV_FDBK_DIR              DIO_PORTU_DIR

//Fed_Dig_Valve7
#define IOA_DI_PUMP_VLV_FDBK_CH               2U
#define IOA_DI_PUMP_VLV_FDBK_PORT             DIO_PORTB_DI
#define IOA_DI_PUMP_VLV_FDBK_DIR              DIO_PORTB_DIR



#define IOA_DI_RELAY_FDBK_CH                1U
#define IOA_DI_RELAY_FDBK_PORT              DIO_PORTU_DI
#define IOA_DI_RELAY_FDBK_DIR               DIO_PORTU_DIR

#define IOA_DI_T15_SWT_CH                   6U
#define IOA_DI_T15_SWT_PORT                 DIO_PORTA_DI
#define IOA_DI_T15_SWT_DIR                  DIO_PORTA_DIR

#define IOA_DI_TQ_OUT_FDBK_CH               7U
#define IOA_DI_TQ_OUT_FDBK_PORT             DIO_PORTA_DI
#define IOA_DI_TQ_OUT_FDBK_DIR              DIO_PORTA_DIR


#define IOA_DI_LIQUID_SWT_CH                   0U
#define IOA_DI_LIQUID_SWT_PORT                 DIO_PORTS_DI
#define IOA_DI_LIQUID_SWT_DIR                  DIO_PORTS_DIR
#define IOA_DI_LIQUID_SWT_PORT_PULL_ENA        DIO_PERS



/* Unit: us */
#define IOA_TIME_BASE                         (8)  
#define IOA_PERIOD_TIME_BASE                  (16)  

#define IOA_DO_PUMP_CTL_HIGH                  (10000)
#define IOA_DO_PUMP_CTL_MIN_PERIOD            (20000)

#define IOA_DO_PUMP_CTL_HIGH_CNT              (IOA_DO_PUMP_CTL_HIGH/IOA_TIME_BASE)
#define IOA_DO_PUMP_CTL_HIGH_PERIOD_CNT       (IOA_DO_PUMP_CTL_HIGH/IOA_PERIOD_TIME_BASE)
#define IOA_DO_PUMP_CTL_MIN_PERIOD_CNT        (IOA_DO_PUMP_CTL_MIN_PERIOD/IOA_PERIOD_TIME_BASE)

#define IOA_DEFECT_ACTIVE_CNT                 10U

/* Unit: ms */
#define IOA_DEFECT_DELAY_TO_TEST              500U

#define IOA_AIR_SWT_DELAY                     100U

/* Unit: ms */


/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/

/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/



#endif /* #ifndef _IOA_CFG_H_ */