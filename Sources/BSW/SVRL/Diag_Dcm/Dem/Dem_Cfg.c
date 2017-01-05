/*******************************************************************************
*
*  FILE
*     Dem_Cfg.c
*
*  DESCRIPTION
*     Configuration Source Code File for Dem Module  
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

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"
#include "VFB.h"
#include "Dem_Cfg.h"

/*******************************************************************************
* Defines                                                                
*******************************************************************************/

/*******************************************************************************
* Macros                                                                
*******************************************************************************/

#pragma CODE_SEG DEFAULT

/*******************************************************************************
* Global Constant definition                         
*******************************************************************************/
#ifndef OBD_TEST
CONST(boolean,DEM_CONST) Dem_stClear_C = 0;
#else
boolean Dem_stClear_C;
#endif 

CONST(Dem_FaultCodeType,DEM_CONST) Dem_ErrJ1939FaultCode[DEM_EVENT_INNER_NUM] = 
/*  SPN,  FMI, DtcCode,
                  ErrorClass, 
                        DtcKind,
                        Lamp Status, 
                                    Confirm Counter, 
                                          Healing Counter ,
                                                      Counter Type 
                                                                 ErrorType 
                                                                           TorqueLimitType */
{
  /* Nox Over 5g/kwh */
  {
    4090, 16, 0x200000, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,SECONDS(0),SECONDS(0), COUNTER_ENG_RUN, NON_ERASABLE,  TRQ_LMT_NONE
  },
  /* Nox Over 7g/kwh */
  {
    4090, 0,  0x200000, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,SECONDS(0),SECONDS(0), COUNTER_ENG_RUN, NON_ERASABLE,  TRQ_LMT_IMM,  
  },
  /* urea consump too much */
  {
//    3826,15,  0x106A00, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,SECONDS(0),  OBD_CYCLE(3),  COUNTER_ENG_RUN, ERASABLE,      TRQ_LMT_NONE, 
// 2015-07-07, LZY, changed 
    3826,15,  0x106A00, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,SECONDS(0),  SECONDS(0),  COUNTER_ENG_RUN, ERASABLE,      TRQ_LMT_NONE, 
  },
  /* Nox Over 7g/kwh, urea consumption too little */
  {
    3826, 0,  0x200100, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON, SECONDS(0), SECONDS(0), COUNTER_ENG_RUN, NON_ERASABLE,  TRQ_LMT_IMM,   
  },
  /* UREA_TANK_HEATER_VLV_OC  */  
  {
    3363, 5,  0x10B200, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,  ERASABLE,        TRQ_LMT_NONE,  
  },  
  /* UREA_TANK_HEATER_VLV_STG  */  
  {
    //3363, 4,  0x10B100, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,  ERASABLE,        TRQ_LMT_NONE,  
    //2015-07-04, lzy, change to 6 by mail
    3363, 6,  0x10B100, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,  ERASABLE,        TRQ_LMT_NONE,  
  },
  /* air supply valve defect  */  
  {
    4336, 7,  0x103900, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(0),  SECONDS(0), COUNTER_ENG_RUN,  ERASABLE,        TRQ_LMT_NONE,  
  },      
  /* NOX_SENSOR_HEATER_SC_DEFECT */  
  {
    3232, 3,  0x220200, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,   NON_ERASABLE,        TRQ_LMT_50H,  
  },
  /* NOX_SENSOR_HEATER_OC_DEFECT */  
  {
    3232, 5,  0x220300, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,   NON_ERASABLE,        TRQ_LMT_50H,  
  },  
  /* NOX_SENSOR_SC_DEFECT  */  
  {
    3234, 3,  0x220500, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,  NON_ERASABLE,        TRQ_LMT_50H,  
  }, 
  /* NOX_SENSOR_OC_DEFECT  */  
  {
    3234, 5,  0x220600, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,  NON_ERASABLE,        TRQ_LMT_50H,  
  },      
  /* NOX_SENSOR_NO_OUTPUT */  
  {
    //3226, 12, 0xC11300, 9, (DEM_DTC_EMMISSION_TYPE|DEM_DTC_COMMUNICATION_TYPE), MIL_LAMP_ON,  SECONDS(10),  SECONDS(10), COUNTER_TIME,   NON_ERASABLE,        TRQ_LMT_50H,  
    3226, 9, 0xC11300, 9, (DEM_DTC_EMMISSION_TYPE|DEM_DTC_COMMUNICATION_TYPE), MIL_LAMP_ON,  SECONDS(10),  SECONDS(10), COUNTER_TIME,   NON_ERASABLE,        TRQ_LMT_50H,  
  },
  /* NOX_SENSOR_ABNORMAL  */  
  {
    3226, 2,  0x220100, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  OBD_CYCLE(1),  SECONDS(390), COUNTER_ENG_RUN,  NON_ERASABLE,        TRQ_LMT_50H,  
  }, 
  /* UREA_LVL_SENSOR_STP_OC, 3532 was replaced with 1761 */  
  {
    1761, 3,  0x203D00, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,   NON_ERASABLE,        TRQ_LMT_50H,  
  },
  /* UREA_LVL_SENSOR_STG  */  
  {
    1761, 4,  0x203C00, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,  NON_ERASABLE,        TRQ_LMT_50H,  
  },     
  /* NOZZLE_JAM  */  
  {
    3362, 7,  0x104900,5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,SECONDS(0),  SECONDS(0), COUNTER_ENG_RUN,  ERASABLE,  TRQ_LMT_NONE,  
  },
  /* AIR_SUPPLY_ABNORMAL  */ 
  {
    4335, 2,  0x104800, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,SECONDS(0),  SECONDS(0), COUNTER_ENG_RUN,  ERASABLE,     TRQ_LMT_NONE,    
  },
  /* urea level too low  */ 
  {
    1761,18,  0x203F00, 5, DEM_DTC_EMMISSION_TYPE, WRN_LAMP_ON_MIL_BLINK,SECONDS(6),  SECONDS(6), COUNTER_TIME,  ERASABLE,  TRQ_LMT_NONE,    
  },   
  /* urea tank empty  */   
  {
   	1761,1,   0x203F00, 6, DEM_DTC_EMMISSION_TYPE, WRN_MIL_LAMP_ON, SECONDS(6),  SECONDS(6), COUNTER_TIME,  NON_ERASABLE,  TRQ_LMT_IMM,  
  },
  /* reaction agent quality too bad  */
  {
    3364, 0,  0x200100, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,SECONDS(0), SECONDS(0), COUNTER_ENG_RUN, NON_ERASABLE,  TRQ_LMT_IMM,
  },
  /* reaction agent interrupt*/
  {
    4095, 0,  0x200100, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,OBD_CYCLE(1),  SECONDS(390),  COUNTER_ENG_RUN, NON_ERASABLE,  TRQ_LMT_IMM,  
  }, 
   /* SCR_ABSENT */  
  {
    4794, 31, 0x105000, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(0),  SECONDS(0), COUNTER_TIME,   ERASABLE,        TRQ_LMT_NONE,  
  }, 
  /* pump defect */
  {
    3361, 14, 0x104900, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,SECONDS(10),  SECONDS(390), COUNTER_ENG_RUN,  ERASABLE,  TRQ_LMT_NONE,  
  },
  /* EGP_INLET_SENSOR_STP_OC  */  
  {
    4360, 3,  0x042800, 6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,  NON_ERASABLE,        TRQ_LMT_50H,  
  },  
  /* EGP_INLET_SENSOR_STG */  
  {
    4360, 4, 0x042700,  6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,   NON_ERASABLE,        TRQ_LMT_50H,  
  },
  /* EGP_OUTLET_SENSOR_STP_OC  */  
  {
    4363, 3, 0x042D00,  6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,  NON_ERASABLE,        TRQ_LMT_50H,  
  },                       
  /* EGP_OUTLET_SENSOR_STG */  
  {
    4363, 4, 0x042C00,  6, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,   NON_ERASABLE,        TRQ_LMT_50H,  
  },
  /* UREA_TEMP_SENSOR_STP_OC */  
  {
    3031, 3, 0x205D00,  5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(2),  SECONDS(2), COUNTER_TIME,   ERASABLE,        TRQ_LMT_NONE,  
  },
  /* UREA_TEMP_SENSOR_STG  */  
  {
    3031, 4, 0x205C00,  5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(2),  SECONDS(2), COUNTER_TIME,  ERASABLE,        TRQ_LMT_NONE,  
  },  
  /* UREA_TEMP_SENSOR_OOR */  
  {
    3031, 16, 0x205B00, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(30),  SECONDS(30), COUNTER_TIME,   ERASABLE,        TRQ_LMT_NONE,  
  },
  /* ENV_TEMP_SENSOR_STP_OC  */  
  {
    171, 3,   0x007300, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(0),  SECONDS(0),  COUNTER_TIME, ERASABLE,        TRQ_LMT_NONE,  
  }, 
  /* ENV_TEMP_SENSOR_STG */  
  {
    171, 4,   0x007200, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(0),  SECONDS(0), COUNTER_TIME,   ERASABLE,        TRQ_LMT_NONE,  
  },
  /* PIPE_HEATER_STP_OC  */  
  {
    4340, 5,  0x107100, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,  ERASABLE,        TRQ_LMT_NONE,  
  },  
  /* PIPE_HEATER_STG */  
  {
    4340, 4,  0x107000, 5, DEM_DTC_EMMISSION_TYPE, MIL_LAMP_ON,  SECONDS(5),  SECONDS(5), COUNTER_TIME,   ERASABLE,        TRQ_LMT_NONE,  
  },                     
  /* EEC1_TIME_OUT */  
  {
    188, 1,   0xC00100, 1, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(0),  SECONDS(0), COUNTER_TIME,  IMMEDIATE_ERASE,        TRQ_LMT_NONE,  
  },
  /* ET1_TIME_OUT  */  
  {
    188, 2,   0xC00200,1, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(0),  SECONDS(0), COUNTER_TIME, IMMEDIATE_ERASE,        TRQ_LMT_NONE,  
  },  
  /* FIECO_TIME_OUT  */  
  {
    188, 3,   0xC00300,1, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(0),  SECONDS(0), COUNTER_TIME, IMMEDIATE_ERASE,        TRQ_LMT_NONE,  
  }, 
  /* INCON_TIME_OUT */  
  {
    188, 4,   0xC00400,1, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(0),  SECONDS(0), COUNTER_TIME,  IMMEDIATE_ERASE,        TRQ_LMT_NONE,  
  },
  /* TCO1_TIME_OUT  */  
  {
    188, 5,   0xC00500,1, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(0),  SECONDS(0), COUNTER_TIME, IMMEDIATE_ERASE,        TRQ_LMT_NONE,  
  },  
  /* TD_TIME_OUT  */  
  {
    188, 6,   0xC00600,1, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(0),  SECONDS(0), COUNTER_TIME, IMMEDIATE_ERASE,        TRQ_LMT_NONE,  
  },  
  /* VDHR_TIME_OUT  */  
  {
    188, 7,   0xC00700,1, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(0),  SECONDS(0), COUNTER_TIME, IMMEDIATE_ERASE,        TRQ_LMT_NONE,  
  },  
  /* EEC2_TIME_OUT  */  
  {
    188, 8,   0xC00800,1, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(0),  SECONDS(0), COUNTER_TIME, IMMEDIATE_ERASE,        TRQ_LMT_NONE,  
  },  
  /* DM1EECU_TIME_OUT */  
  {
    188, 9,   0xC00900,1, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(0),  SECONDS(0),  COUNTER_TIME, IMMEDIATE_ERASE,        TRQ_LMT_NONE,  
  },  
  /* EEPROM_DEF */  
  {
    199, 7,   0xC01000,3, DEM_DTC_COMMUNICATION_TYPE, MIL_LAMP_OFF,  SECONDS(10),  SECONDS(10),  COUNTER_TIME, ERASABLE,        TRQ_LMT_NONE,  
  }  
};

const Dem_EngFaultConfigType Dem_EngFaultCode[DEM_ENG_FAULT_NUM]= 
{
/* 0 dfp_InjVlvNumMinInj_mp */
{
  0x22F0EC00,  100
},
/* 1 dfp_SSpMon1_mp  */
{
  0x37040300,  100
},
/* 2 dfp_SSpMon1_mp */
{
  0x37040400,  100
},
/* 3 dfp_SSpMon2_mp */
{
  0x38040300,  100
},
/* 4 dfp_SSpMon2_mp */
{
  0x38040400,   100
},
/* 5 dfp_MnRly1_SCB */
{
  0x4A0A0300,100
},
/* 6 dfp_MnRly1_SCG */
{
  0x4A0A0400, 100
},
/* 7 dfp_SSpMon3_mp */
{ 
  0x51FDE300,  100
},
/* 8 dfp_SSpMon3_mp */
{
  0x51FDE400,   100
},
/* 9 Bank1A */
{
  0x56FCE300,  100
},
/* 10 Bank1A */
{
  0x56FCE400,  100
},
/* 11 Bank1A */
{
  0x56FCEB00,  100
},
/* 12dfp_VSSCD2_mp */
{
  0x58060c00,  100
},
/* 13 Bank2A */
{
  0x58FCE300,  100
},
/* 14 Bank2A */
{
  0x58FCE400,   100
},
/* 15 Bank2A */
{
  0x58FCEB00,  100
},
/* 16 dfp_InjVlvChipA_mp */
{
  0x5AFCE200,  100
},
/* 17 dfp_InjVlvChipA_mp */
{
  0x5AFCE300,  100
},
/* 18 dfp_InjVlvChipA_mp */
{
  0x5AFCE400,  100
},
/* 19 dfp_InjVlvChipA_mp */
{
  0x5AFCEC00,  100
},
/* 20 dfp_InjVlvChipB_mp */
{
  0x5BFCE200,  100
},
/* 21 dfp_InjVlvChipB_mp */
{
  0x5BFCE300,  100
},
/* 22 dfp_InjVlvChipB_mp */
{
  0x5BFCE400,  100
},
/* 23 dfp_InjVlvChipB_mp */
{
  0x5BFCEC00,  100
},
/* 24 dfp_RailMeUn3_mp */
{
  0x5DFDE200,  100
},
/* 25 dfp_RailMeUn3_mp */
{
  0x5DFDE300,   100
},
/*  dfp_RailMeUn3_mp */
{
  0x5DFDE400,   100
},
/* dfp_RailMeUn3_mp */
{
  0x5DFDE700,   100
},
/* dfp_RailMeUn3_mp */
{
  0x5DFDEE00,   100
},
/* dfp_RailMeUn3_mp */
{
  0x5DFDF000,   100
},
/* dfp_RailMeUn3_mp */
{
  0x5DFDF100,   100
},
/* dfp_RailMeUn3_mp */
{
0x5DFDF200,   100
},
/* dfp_MeUnCDNoLoad_mp */
{
  0x5FFDE200,    100
},
/* dfp_MeUnCDNoLoad_mp */
{
  0x5FFDE300,    100
},
/* dfp_MeUnCDNoLoad_mp */
{
  0x5FFDE400,    100
},
/* dfp_MeUnCDNoLoad_mp */
{
  0x5FFDE500,    100
},
/* dfp_MeUnCDNoLoad_mp */
{
  0x5FFDF000,     100
},
/* dfp_MeUnCDNoLoad_mp */
{
  0x5FFDF200,     100
},
/* 102 dfp_HWEMonCom_mp */
{
  0x61FDEB00,     100
},
/* dfp_BPSCD_mp */
{
  0x66000200,     100
},
/* dfp_BPSCD_mp */
{
  0x66000300,      100
},
  /* dfp_BPSCD_mp */
{
  0x66000400,     100
},
/* dfp_IATSCD_mp */
{ 
  0x69000300,      100
},
/* dfp_IATSCD_mp */
{
  0x69000400,      100
},
/* dfp_IATSCD_mp */
{
  0x69000C00,      100
},
/* dfp_CTSCDOverTemp_mp */
{
  0x6E000200,      100
},
/* dfp_CTSCD_mp */
{
  0x6E000300,      100
},
/* dfp_CTSCD_mp */
{
  0x6E000400,      100
},
/* dfp_CTSCD_mp */
{
  0x6E000500,     100
},
/* dfp_CTSCD_mp */
{
  0x6E000F00,     100
},
/* 103 dfp_HWEMonEEPROM */
{
0x76020200,     100
},
/* 103 dfp_HWEMonEEPROM */
{
0x76020400,     100
},
/* 103 dfp_HWEMonEEPROM */
{
0x76020C00,     100
},
/* dfp_EngMCaS1_mp */
{
0x7C020B00,     100
},
/* dfp_EngMCaS1_mp */
{
0x7C020C00,     100
},
/* dfp_NetMngCANAOff_mp */
{
0x7F020C00,     100
},
/* Cyl1A */
{
0x8B020300,     100
},
/* Cyl1A */
{
0x8B020800,     100
},
/* Cyl1A */
{
0x8B020B00,     100
},
/* Cyl1A */
{
0x8B020C00,     100
},
/* Cyl2A */
{
0x8C020300,     100
},
/* Cyl2A */
{
0x8C020800,     100
},
/* Cyl2A */
{
0x8C020B00,     100
},
/* Cyl2A */
{
0x8C020C00,    100
},
/* Cyl3A */
{
0x8D020300,     100
},
/* Cyl3A */
{
0x8D020800,     100
},
/* Cyl3A */
{
0x8D020B00,      100
},
/* Cyl3A */
{
0x8D020C00,      100
},
/* Cyl4A */
{
0x8E020300,      100
},
/* Cyl4A */
{
0x8E020800,      100
},
/* Cyl4A */
{
0x8E020B00,      100
},
/* Cyl4A */
{
0x8E020C00,     100
},
/* Cyl5A */
{
0x8F020300,     100
},
/* Cyl5A */
{
0x8F020800,      100
},
/* Cyl5A */
{
0x8F020B00,     100
},
/* Cyl5A */
{
0x8F020C00,    100
},
/* Cyl6A */
{
0x90020300,     100
},
/* 77 Cyl6A */
{
0x90020800,    100
},
/* 78 Cyl6A */
{
0x90020B00,    100
},
/* 79 Cyl6A */
{
0x90020C00,    100
},
/* 80 dfp_Montr_mp */
{
0x9CFCE200,   100
},
/* 81 dfp_RailCD */
{
0x9D000300,  100
},
/* 82 dfp_RailCD */
{
0x9D000400,   100
},
/* 83 dfp_EngMOfsCaSCrS */
{
0xBE000700,   100
},
/* 84 dfp_EngMCrS1_mp */
{
0xBE000B00,   100
},
/* 85 dfp_EngMCrS1_mp */
{
0xBE000C00,   100
},
/* 86 dfp_MRlyCD_mp */
{
0xCD050300,  100
},
/* 87 dfp_MRlyCD_mp */
{
0xCD050400,100
},
/* 88 dfp_PRVMon */
{
0xCEFCE000,100
},
/* 89 dfp_PRVMon */
{
0xCEFCE700,100
},
/* 90 dfp_PRVMon */
{
0xCEFCEB00, 100
},
/* 91dfp_PRVMon */
{
0xCEFCEC00,100
},
/* 92dfp_PRVMon */
{
0xCEFCEE00, 100
},
/* 93 dfp_PRVMon */
{
0xCEFCF000, 100
},
/* 94 dfp_NetMngCANBOff_mp */
{
0xCF040C00, 100
},
/* 95 dfp_NetMngCANCOff_mp */
{
0xD3040C00, 100
},
};
/*******************************************************************************
* Local Constant definition                         
*******************************************************************************/


/*******************************************************************************
* Global Variables definition                         
*******************************************************************************/

/*******************************************************************************
* Local Variables definition                         
*******************************************************************************/

/*******************************************************************************
* Local Functions prototypes                         
*******************************************************************************/


/*******************************************************************************
*  Global Functions Body                                   
*******************************************************************************/



/*******************************************************************************
*  Local Functions Body                                   
*******************************************************************************/





