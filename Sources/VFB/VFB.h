#ifndef _VFB_H_
#define _VFB_H_

#include "Std_Types.h"
#include "Ioa.h"
#include "Adc.h"
#include "AD2S1210.h"
#include "SID_F_MCData.h"
#include "SID_MCData.h"
//#include "Variant_Cfg.h"



//#include "SCR.h"

//#include "SCR_SID.h"


//#include "SCRRemov.h"
//#include "UreaConsum.h"



/***************************************************************************
*                        From SWC                                          
***************************************************************************/

/***************************************************************************
*                       To SWC                                          
***************************************************************************/




extern uint8_t CAN_m_ct_ModReq;
extern uint8_t CAN_m_ct_TrqReq;
extern uint16_t CAN_m_ct_PosTrqGradReq;
extern uint16_t CAN_m_ct_NegTrqGradReq;
extern uint8_t CAN_m_ct_PosTrqLimReq;
extern uint8_t CAN_m_ct_NegTrqLimReq;
extern int16_t CAN_m_ct_ESATrqLimReq;
extern int16_t CAN_m_ct_ESASpdGradReq;
extern uint16_t CAN_m_ct_ESAEndSpdReq;
extern uint16_t CAN_m_ct_ESADurMaxReq;
extern uint16_t CAN_m_ct_DISExcMaxCurReq;







/* AD Input, Unit 5000/4096mV */
extern VAR(uint16,TYPEDEF) ecu_CatTempInVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_CatTempOutVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_CatTempOutVoltRaw1;
extern VAR(uint16,TYPEDEF) ecu_CatTempOutVoltRaw2;
extern VAR(uint16,TYPEDEF) ecu_CatTempOutVoltRaw3;
extern VAR(uint16,TYPEDEF) ecu_UreaTempVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_UreaLvlVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_UreaPipelineVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_ShellTempVoltRaw; 
extern VAR(uint16,TYPEDEF) ecu_PumpTempVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_BattVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_PressureSplyVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_10VVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_5VVoltRaw;
extern VAR(uint16,TYPEDEF) ecu_PressureSigVoltRaw;

extern uint16 ecu_LiquidBVoltRaw;

/* Calculated AD Value */
extern VAR(uint16,TYPEDEF) ecu_BattVoltActRaw;
extern VAR(uint16,TYPEDEF) ecu_5VVoltActRaw;
extern VAR(uint16,TYPEDEF) ecu_10VVoltActRaw;
extern uint16 ecu_PressureSplyVoltActRaw;


/* Vlv FeedBack Signal  */
extern VAR(boolean,TYPEDEF) ecu_RelayFdBk;
extern VAR(boolean,TYPEDEF) ecu_PumpHeaterVlv1FdBk;
extern VAR(boolean,TYPEDEF) ecu_CoolVlv1FdBk;
extern boolean ecu_AirSwtVlvFdBk;
extern VAR(boolean,TYPEDEF) ecu_PumpVlvFdBk;
extern VAR(boolean,TYPEDEF) ecu_TrqOutFdBk;
extern VAR(uint16,TYPEDEF) ecu_Ptc2FdbStRaw;
extern VAR(uint16,TYPEDEF) ecu_Ptc1FdbCurrentRaw;
extern VAR(uint16,TYPEDEF) ecu_Ptc2FdbCurrentRaw;
extern VAR(boolean,TYPEDEF) ecu_PtcStandbyFdBk;


/* Digital Input */
extern VAR(boolean,TYPEDEF) ecu_T15SwtSts;
extern boolean ecu_LiquidSts;



extern uint8 ecu_PumpVlvDefSts; 

extern uint32 ecu_EngRunTime;

extern uint8 obd_UreaConsumpErrStsOld;


/***************************************************************************
*                       CAN Tx Signals                                         
***************************************************************************/
/* ETC1 */

extern uint8 EEC3_StrtCode;
/***************************************************************************
*                       CAN Rx Signals                                         
***************************************************************************/
extern uint8 EEC1_EngDemPrcTrq;
extern uint8 EEC1_ActEngTrq;
extern uint8 EEC1_DrvDemEngTrq;
extern uint8 EEC1_EngStarterMode;
extern uint8 EEC1_SrcAdrOfCtrlDevice;
extern uint16 EEC1_EngSpd;
/* Added in 2011-2-21 */
extern uint8 EEC1_EngTrqMode;

extern uint8 ET1_EngClntTemp;


extern uint16 ATS_Nox;
extern uint16 ATS_O2;
extern uint8 ATS_Status;
extern uint8 ATS_ErrorNOx;
extern uint8 ATS_ErrorO2;
extern uint8 ATS_ErrorHeater;
extern uint8 ATS_StatusHeaterMode;

extern uint16 TCO1_VehSpd;

extern uint8 TD_Second;
extern uint8 TD_Minute;
extern uint8 TD_Hour;
extern uint8 TD_Day;
extern uint8 TD_Month;
extern uint8 TD_Year;

extern uint32 VD_TotalDistance;

extern uint8 EEC2_EngLoad;

extern uint16 LFE_FuelRate;

extern uint8 IC1_BoostPressure;
extern uint8 IC1_BoostTemp;

extern uint8 DM1E_WarnLmpSt;
extern uint8 DM1E_StopLmpSt;
extern uint8 DM1E_ProtLmpSt;
extern uint8 DM1E_MILLmpSt;

extern uint32 DM1E_FaultCode[10];
extern uint8 DM1E_FaultNum;

extern uint16 CAN_m_n_EngSpd;        /* '<Root>/EngSpdRaw' */
extern uint16 CAN_m_r_FuelRate;      /* '<Root>/InjQRaw' */
extern uint8 CAN_m_p_Boost;          /* '<Root>/BostPRaw' */
extern uint8 CAN_m_t_IntakManifold;  /* '<Root>/BostTRaw' */
extern uint8 CAN_m_t_EngCoolant;     /* '<Root>/CoolT' */
extern uint8 CAN_m_r_ActEngTrq;      /* '<Root>/EngTPc' */
extern uint8 CAN_m_r_DrvDemEngTrq;   /* '<Root>/EngTDmdPc' */
extern uint16 SID_m_per_O2;          /* '<Root>/O2' */
extern uint16 SID_m_u_NoxDown;       /* '<Root>/NoxDown' */


/***************************************************************************
*                       Defined in SWC                                        
***************************************************************************/


/***************************************************************************
*                       Calibration Parameter                                        
***************************************************************************/

extern uint16 Ioa_LiquidPresentVolt_C;

/* Unit: 10ms */
extern uint16 Ioa_LiquidAPDelay_C;
extern uint16 Ioa_LiquidANPDelay_C;

extern uint16 Ioa_LiquidBPDelay_C;
extern uint16 Ioa_LiquidBNPDelay_C;



#endif