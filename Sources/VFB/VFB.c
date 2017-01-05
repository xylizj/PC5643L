#include "VFB.h"

/***************************************************************************
*                        From SWC                                          
***************************************************************************/
/* Control Signal from  SWC */

/* Sensor Power Control */
VAR(boolean,TYPEDEF) ecu_PressureSplyCtl;

/* Control */

/* Pipeline heater*/
VAR(uint8,TYPEDEF) ecu_RelayCtl;

VAR(boolean,TYPEDEF) ecu_AirSwtVlvCtl;
VAR(boolean,TYPEDEF) ecu_CoolVlvCtl;
boolean ecu_PumpHeaterCtl;


uint8 ecu_TrqOutCtl;


VAR(uint16,TYPEDEF) ecu_PumpVlvCtlPeriod;


/***************************************************************************
*                       To SWC                                          
***************************************************************************/




uint8_t CAN_m_ct_ModReq;
uint8_t CAN_m_ct_TrqReq;
uint16_t CAN_m_ct_PosTrqGradReq;
uint16_t CAN_m_ct_NegTrqGradReq;
uint8_t CAN_m_ct_PosTrqLimReq;
uint8_t CAN_m_ct_NegTrqLimReq;
int16_t CAN_m_ct_ESATrqLimReq;
int16_t CAN_m_ct_ESASpdGradReq;
uint16_t CAN_m_ct_ESAEndSpdReq;
uint16_t CAN_m_ct_ESADurMaxReq;
uint16_t CAN_m_ct_DISExcMaxCurReq;












/* AD Input, Unit 5000/1023mV */
VAR(uint16,TYPEDEF) ecu_CatTempInVoltRaw;
VAR(uint16,TYPEDEF) ecu_CatTempOutVoltRaw;
VAR(uint16,TYPEDEF) ecu_CatTempOutVoltRaw1;
VAR(uint16,TYPEDEF) ecu_CatTempOutVoltRaw2;
VAR(uint16,TYPEDEF) ecu_CatTempOutVoltRaw3;
VAR(uint16,TYPEDEF) ecu_UreaTempVoltRaw;
VAR(uint16,TYPEDEF) ecu_UreaLvlVoltRaw;
VAR(uint16,TYPEDEF) ecu_UreaPipelineVoltRaw;
VAR(uint16,TYPEDEF) ecu_ShellTempVoltRaw; 
VAR(uint16,TYPEDEF) ecu_PumpTempVoltRaw;
VAR(uint16,TYPEDEF) ecu_BattVoltRaw;
VAR(uint16,TYPEDEF) ecu_PressureSplyVoltRaw;
VAR(uint16,TYPEDEF) ecu_5VVoltRaw;
VAR(uint16,TYPEDEF) ecu_10VVoltRaw;
VAR(uint16,TYPEDEF) ecu_PressureSigVoltRaw;
VAR(uint16,TYPEDEF) ecu_Ptc2FdbStRaw;
VAR(uint16,TYPEDEF) ecu_Ptc1FdbCurrentRaw;
VAR(uint16,TYPEDEF) ecu_Ptc2FdbCurrentRaw;

uint16 ecu_LiquidBVoltRaw;

/* Calculated AD Value */
VAR(uint16,TYPEDEF) ecu_BattVoltActRaw;
VAR(uint16,TYPEDEF) ecu_5VVoltActRaw;
VAR(uint16,TYPEDEF) ecu_10VVoltActRaw;
uint16 ecu_PressureSplyVoltActRaw;

/* Vlv FeedBack Signal  */
VAR(boolean,TYPEDEF) ecu_RelayFdBk;
VAR(boolean,TYPEDEF) ecu_PumpHeaterVlv1FdBk;
VAR(boolean,TYPEDEF) ecu_PumpHeaterVlv2FdBk;
VAR(boolean,TYPEDEF) ecu_CoolVlv1FdBk;
boolean ecu_AirSwtVlvFdBk;
VAR(boolean,TYPEDEF) ecu_PumpVlvFdBk;
VAR(boolean,TYPEDEF) ecu_TrqOutFdBk;

VAR(boolean,TYPEDEF) ecu_PtcStandbyFdBk;

/* Digital Signal by IOA */
VAR(boolean,TYPEDEF) ecu_T15SwtSts;
boolean ecu_LiquidSts;


uint8 ecu_PumpVlvDefSts;

uint32 ecu_EngRunTime;

uint8 obd_UreaConsumpErrStsOld;

/***************************************************************************
*                       CAN Tx Signals                                         
***************************************************************************/
/* EEC3 */

uint8 EEC3_StrtCode;

/***************************************************************************
*                       CAN Rx Signals                                         
***************************************************************************/
uint8 EEC1_EngDemPrcTrq;
uint8 EEC1_ActEngTrq;
uint8 EEC1_DrvDemEngTrq;
uint8 EEC1_EngStarterMode;
uint8 EEC1_SrcAdrOfCtrlDevice;
uint16 EEC1_EngSpd;
/* Added in 2011-2-21 */
uint8 EEC1_EngTrqMode;

uint8 ET1_EngClntTemp;

uint16 ATS_Nox;
uint16 ATS_O2;
uint8 ATS_Status;
uint8 ATS_ErrorNOx;
uint8 ATS_ErrorO2;
uint8 ATS_ErrorHeater;
uint8 ATS_StatusHeaterMode;

uint16 TCO1_VehSpd;

uint8 TD_Second;
uint8 TD_Minute;
uint8 TD_Hour;
uint8 TD_Day;
uint8 TD_Month;
uint8 TD_Year;

uint32 VD_TotalDistance;

uint8 EEC2_EngLoad;



uint16 LFE_FuelRate;

uint8 IC1_BoostPressure;
uint8 IC1_BoostTemp;

uint8 DM1E_WarnLmpSt;
uint8 DM1E_StopLmpSt;
uint8 DM1E_ProtLmpSt;
uint8 DM1E_MILLmpSt;

uint32 DM1E_FaultCode[10];
uint8 DM1E_FaultNum;

uint16 CAN_m_n_EngSpd;        /* '<Root>/EngSpdRaw' */
uint16 CAN_m_r_FuelRate;      /* '<Root>/InjQRaw' */
uint8 CAN_m_p_Boost;          /* '<Root>/BostPRaw' */
uint8 CAN_m_t_IntakManifold;  /* '<Root>/BostTRaw' */
uint8 CAN_m_t_EngCoolant;     /* '<Root>/CoolT' */
uint8 CAN_m_r_ActEngTrq;      /* '<Root>/EngTPc' */
uint8 CAN_m_r_DrvDemEngTrq;   /* '<Root>/EngTDmdPc' */
uint16 SID_m_per_O2;          /* '<Root>/O2' */
uint16 SID_m_u_NoxDown;       /* '<Root>/NoxDown' */


/***************************************************************************
*                       Calibration Parameter                                        
***************************************************************************/

uint16 Ioa_LiquidPresentVolt_C = 900;

/* Unit: 10ms */
uint16 Ioa_LiquidAPDelay_C = 3000;
uint16 Ioa_LiquidANPDelay_C = 100;

uint16 Ioa_LiquidBPDelay_C = 3000;
uint16 Ioa_LiquidBNPDelay_C = 100;



