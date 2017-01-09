#include "CAN_Msg.h"
#include "VFB.h"

/***********************************************
*        Msg struct                  *
************************************************/
volatile Msg_Rx_tag_type Rx_Msg_PTC1;
volatile Msg_Rx_tag_type Rx_Msg_PTC2;
volatile Msg_Rx_tag_type Rx_Msg_PipeHeat;
volatile Msg_Rx_tag_type Rx_Msg_SCRTankHeat;
volatile Msg_Rx_tag_type Rx_Msg_iDQ;
volatile Msg_Rx_tag_type Rx_Msg_SetPWM0;
volatile Msg_Rx_tag_type Rx_Msg_XCP;
extern CanXcp_MsgType canxcp_ReceiveBuffer;

volatile Msg_Tx_tag_type Tx_Msg_PhaseCur;
volatile Msg_Tx_tag_type Tx_Msg_TempBridgeExc;
volatile Msg_Tx_tag_type Tx_Msg_Voltage;
volatile Msg_Tx_tag_type Tx_Msg_StatorShellRef;
volatile Msg_Tx_tag_type Tx_Msg_ADS1210;
volatile Msg_Rx_tag_type Tx_Msg_Debug;
/***************************************************************/

volatile RX_tag_type RxMsgBuffA[CAN0_RX_MSG_NUM];
volatile TX_tag_type TxMsgBuffA[CAN0_TX_MSG_NUM];

volatile boolean CAN_m_st_RxMsgEnable0[CAN0_RX_MSG_NUM];
volatile boolean CAN_m_st_TxMsgEnable0[CAN0_TX_MSG_NUM];

/******************************************************/ 
const boolean CAN_C_st_RX_MsgEnable_PhaseCur		= FALSE; //01     	
const boolean CAN_C_st_RX_MsgEnable_PTC2		= FALSE; //02         	
const boolean CAN_C_st_RX_MsgEnable_PipeHeat	= FALSE; //03  		   	
const boolean CAN_C_st_RX_MsgEnable_SCRTankHeat	= FALSE; //04  		   	
const boolean CAN_C_st_RX_MsgEnable_iDQ	= FALSE; //05    	
const boolean CAN_C_st_RX_MsgEnable_SetPWMRatio	= FALSE; //06    	
const boolean CAN_C_st_RX_MsgEnable_XCP	= TRUE; //07    	

      		
/******************************************************/  
const boolean CAN_C_st_TX_MsgEnable_PhaseCur		= TRUE; //01     	
const boolean TCAN_C_st_TX_MsgEnable_TempBridgeExc		= FALSE; //02     	
const boolean CAN_C_st_TX_MsgEnable_Voltage	= FALSE; //03  		   	
const boolean CAN_C_st_TX_MsgEnable_StatorShellRef	= FALSE; //04
const boolean CAN_C_st_TX_MsgEnable_ADS1210	= FALSE; //05    	
const boolean CAN_C_st_TX_MsgEnable_Debug	= FALSE; //06   	
/******************************************************/ 

/********************************************************************
	          Decode                 
********************************************************************/
void Rx_Msg_PTC1_Decode(void)
{}

void Rx_Msg_PTC2_Decode(void)
{}

void Rx_Msg_PipeHeat_Decode(void)
{}


void Rx_Msg_SCRTankHeat_Decode(void)
{}





extern uint8_t cur_req_d_ov_en;
extern int32_t cur_req_d_ov;


extern uint8_t cur_req_q_ov_en;
extern int32_t cur_req_q_ov;

void Rx_Msg_iDQ_Decode(void)
{
	cur_req_q_ov_en = Rx_Msg_iDQ.data[6];
	
	if(cur_req_q_ov_en==1)
	{
		cur_req_q_ov = Rx_Msg_iDQ.data[7] * 1000;
		if(cur_req_q_ov > 50000)		
		{
			cur_req_q_ov = 50000;	
		}
	}
	else if(cur_req_q_ov_en==2)
	{
		cur_req_q_ov = - Rx_Msg_iDQ.data[7] * 1000;
		if(cur_req_q_ov < -50000)		
		{
			cur_req_q_ov = -50000;	
		}		
	}
	else
	{
		cur_req_q_ov = 0;
	}
}




void Rx_Msg_SetPWM0_Decode(void)
{/*
	pwm0_sub0_a_duty_set_en = Rx_Msg_SetPWM0.data[0];
	pwm0_sub1_a_duty_set_en = Rx_Msg_SetPWM0.data[1];
	pwm0_sub2_a_duty_set_en = Rx_Msg_SetPWM0.data[2];
	pwm0_sub3_a_duty_set_en = Rx_Msg_SetPWM0.data[3];
	pwm0_sub0_a_duty 				= Rx_Msg_SetPWM0.data[4];
	pwm0_sub1_a_duty 				= Rx_Msg_SetPWM0.data[5];
	pwm0_sub2_a_duty 				= Rx_Msg_SetPWM0.data[6];
	pwm0_sub3_a_duty 				= Rx_Msg_SetPWM0.data[7];
	
	if(pwm0_sub0_a_duty_set_en>0)
	{
		pwm0_sub0_a_duty_set_en = 0;
		SetFlexPWM0SubXDuty(0, pwm0_sub0_a_duty);		
	}
	if(pwm0_sub1_a_duty_set_en>0)
	{
		pwm0_sub1_a_duty_set_en = 0;
		SetFlexPWM0SubXDuty(1, pwm0_sub1_a_duty);	
	}
	if(pwm0_sub2_a_duty_set_en>0)
	{
		pwm0_sub2_a_duty_set_en = 0;
		SetFlexPWM0SubXDuty(2, pwm0_sub2_a_duty);	
	}
	if(pwm0_sub3_a_duty_set_en>0)
	{
		pwm0_sub3_a_duty_set_en = 0;
		SetFlexPWM0Sub3Duty(pwm0_sub3_a_duty);	
	}
*/}


void Rx_Msg_XCP_Decode(void)
{
   	canxcp_ReceiveBuffer.length = RxMsgBuffA[RX_XCP_INDEX].dl;
    *(uint32_t*)&canxcp_ReceiveBuffer.data[0] = *(uint32_t*)&Rx_Msg_XCP.data[0];
    *(uint32_t*)&canxcp_ReceiveBuffer.data[4] = *(uint32_t*)&Rx_Msg_XCP.data[4];
    CanXcp_RxIndication(0x0A);
}




extern volatile uint32_t RawVoltagesTable_FIFO3[CTU_FIFO3_THRESHOLD];
/********************************************************************
	           Encode                 
********************************************************************/

void Tx_Msg_PhaseExcCur_Encode(void)
{
	*(uint16_t*)&Tx_Msg_PhaseCur.data[0] = SID_m_ct_CurPhaseURaw;//SID_m_i_CurPhaseURaw;
	//*(uint16_t*)&Tx_Msg_PhaseCur.data[2] = SID_m_ct_CurPhaseVRaw;//SID_m_i_CurPhaseVRaw;
	*(uint16_t*)&Tx_Msg_PhaseCur.data[4] = SID_m_ct_CurPhaseWRaw;//SID_m_i_CurPhaseWRaw;
	//*(uint16_t*)&Tx_Msg_PhaseCur.data[6] = SID_m_ct_CurExcRaw;//SID_m_i_CurExc;
	//*(uint32_t*)&Tx_Msg_PhaseCur.data[0] = RawVoltagesTable_FIFO3[0];
	//*(uint32_t*)&Tx_Msg_PhaseCur.data[4] = RawVoltagesTable_FIFO3[1];
	//*(uint32_t*)&Tx_Msg_PhaseCur.data[0] = RawVoltagesTable_FIFO0_Array[0][4];
	//*(uint32_t*)&Tx_Msg_PhaseCur.data[4] = RawVoltagesTable_FIFO0_Array[0][5];
}

void Tx_Msg_TempBridgeExc_Encode(void)
{}


extern sint32 iD_ActualReq;
extern sint32 SID_m_i_d;

void Tx_Msg_Voltage_Encode(void)
{}


void Tx_Msg_StatorShellRef_Encode(void)
{}

void Tx_Msg_ADS1210_Encode(void)
{
	*(uint16_t*)&Tx_Msg_ADS1210.data[0] = (uint16_t)SID_m_n_MotSpdRaw;
	*(uint32_t*)&Tx_Msg_ADS1210.data[2] = SID_m_phi_RotPos;
	Tx_Msg_ADS1210.data[6] = SID_m_swt_RslvDOSRaw;
	Tx_Msg_ADS1210.data[7] = SID_m_swt_RslvLOTRaw;
}




extern sint32 iQ_ActualReq;
extern sint32 SID_m_i_q;

void Tx_Msg_Debug_Encode(void)
{	
	*(uint32_t*)&Tx_Msg_Debug.data[0] = iQ_ActualReq;
	*(uint32_t*)&Tx_Msg_Debug.data[4] = SID_m_i_q;
}



void ConfigTxMsgA(	uint8_t 	index, 
					uint32_t 	id, 
					uint8_t 	dl, 
					uint32_t 	rate, 
					uint32_t* 	data,
					uint8_t 	tt,  
					FuncType    encode_func,
					FuncType    tx_err_func
					)
{
	if( index >= CAN0_TX_MSG_NUM )
	{
		return;
	}
	
	TxMsgBuffA[index].id 		= id;	
	TxMsgBuffA[index].dl 		= dl;	
	TxMsgBuffA[index].rate 		= rate*TBL_COUNT_1MS;	
	TxMsgBuffA[index].data 		= data;	
	TxMsgBuffA[index].enable 	= CAN_m_st_TxMsgEnable0[index];	
	TxMsgBuffA[index].state 	= PG_TX_FREE;	
	TxMsgBuffA[index].tt 		= tt;	
	TxMsgBuffA[index].timer 	= Gpt_GetCurrentCnt();	
	TxMsgBuffA[index].encode_func 	= encode_func;
	TxMsgBuffA[index].tx_err_func 	= tx_err_func;
}

void ConfigRxMsgA(	uint8_t 	index, 
					uint32_t  	id, 
					uint8_t 	dl, 
					uint32_t 	rate, 
					uint32_t* 	data,
					uint8_t 	tt,  
					FuncType    decode_func,
					FuncType    rx_timeout_func
					)
{
	if( index >= CAN0_RX_MSG_NUM )
	{
		return;
	}
	
	RxMsgBuffA[index].id 		= id;
	RxMsgBuffA[index].dl 		= dl;	
	RxMsgBuffA[index].rate 		= rate*TBL_COUNT_1MS;	
	RxMsgBuffA[index].data 		= data;	
	RxMsgBuffA[index].enable 	= CAN_m_st_RxMsgEnable0[index];	
	RxMsgBuffA[index].state 	= PG_RX_FREE;	
	RxMsgBuffA[index].tt 		= tt;	
	RxMsgBuffA[index].timer 	= Gpt_GetCurrentCnt();	
	RxMsgBuffA[index].decode_func 	= decode_func;
	RxMsgBuffA[index].rx_timeout_func 	= rx_timeout_func;
}


void CAN_InitMsg(void)
{
//==========================RX================================================================
	//RX ENABLE
	CAN_m_st_RxMsgEnable0[RX_PTC1_INDEX] 			= CAN_C_st_RX_MsgEnable_PhaseCur;					//01 	
	CAN_m_st_RxMsgEnable0[RX_PTC2_INDEX] 			= CAN_C_st_RX_MsgEnable_PTC2;					//01 	
	CAN_m_st_RxMsgEnable0[RX_PIPE_HEAT_INDEX] 			= CAN_C_st_RX_MsgEnable_PipeHeat;					//01 	
	CAN_m_st_RxMsgEnable0[RX_SCR_TANKHEAT_INDEX] 			= CAN_C_st_RX_MsgEnable_SCRTankHeat;					//01 	
	CAN_m_st_RxMsgEnable0[RX_DQ_INDEX] 			= CAN_C_st_RX_MsgEnable_iDQ;					//01 	
	CAN_m_st_RxMsgEnable0[RX_PWM0_RATIO_INDEX] 			= CAN_C_st_RX_MsgEnable_SetPWMRatio;					//01 	
	CAN_m_st_RxMsgEnable0[RX_XCP_INDEX] 			= CAN_C_st_RX_MsgEnable_XCP;					//01 	
	#ifdef USE_DIAG
	CAN_m_st_RxMsgEnable0[MSG_DIAG_RX_INDEX] = TRUE;
	#endif
	
	//RX MSG	
	ConfigRxMsgA(RX_PTC1_INDEX, RX_PTC1_ID, 8,10,	(uint32_t*)&Rx_Msg_PTC1,TT_ASYNC,Rx_Msg_PTC1_Decode,NULL);
	ConfigRxMsgA(RX_PTC2_INDEX, RX_PTC2_ID, 8,10,	(uint32_t*)&Rx_Msg_PTC2,TT_ASYNC,Rx_Msg_PTC2_Decode,NULL);
	ConfigRxMsgA(RX_PIPE_HEAT_INDEX, RX_PIPE_HEAT_ID, 8,10,	(uint32_t*)&Rx_Msg_PipeHeat,TT_ASYNC,Rx_Msg_PipeHeat_Decode,NULL);
	ConfigRxMsgA(RX_SCR_TANKHEAT_INDEX, RX_SCR_TANKHEAT_ID, 8,10,(uint32_t*)&Rx_Msg_SCRTankHeat,TT_ASYNC,Rx_Msg_SCRTankHeat_Decode,NULL);
	ConfigRxMsgA(RX_DQ_INDEX, RX_I_DQ_ID, 8,10,	(uint32_t*)&Rx_Msg_iDQ,TT_ASYNC,Rx_Msg_iDQ_Decode,NULL);
	ConfigRxMsgA(RX_PWM0_RATIO_INDEX, RX_PWM0_RATIO_ID, 8,10,	(uint32_t*)&Rx_Msg_SetPWM0,TT_ASYNC,Rx_Msg_SetPWM0_Decode,NULL);
	ConfigRxMsgA(RX_XCP_INDEX, RX_XCP_ID, 8,10,	(uint32_t*)&Rx_Msg_XCP,TT_ASYNC,Rx_Msg_XCP_Decode,NULL);
	#ifdef USE_DIAG
    ConfigRxMsgA(MSG_DIAG_RX_INDEX, MSG_DIAG_RX_PHY_ID, 8, 10,(uint32_t*)&gMSG_DIAG_RX,TT_ASYNC,MsgDIAG_RX_Decode,NULL);	
	#endif
//==========================TX================================================================
	//TX ENABLE
	CAN_m_st_TxMsgEnable0[TX_PHASE_CURRENT_INDEX] 	= CAN_C_st_TX_MsgEnable_PhaseCur;		
	CAN_m_st_TxMsgEnable0[TX_TEMP_BRIDGE_EXC_INDEX] 	= TCAN_C_st_TX_MsgEnable_TempBridgeExc;		
	CAN_m_st_TxMsgEnable0[TX_VOLTAGE_INDEX] 	= CAN_C_st_TX_MsgEnable_Voltage;		
	CAN_m_st_TxMsgEnable0[TX_STATOR_SHELL_REF_INDEX] 	= CAN_C_st_TX_MsgEnable_StatorShellRef;		
	CAN_m_st_TxMsgEnable0[TX_ADS1210_INDEX] 	= CAN_C_st_TX_MsgEnable_ADS1210;		
	CAN_m_st_TxMsgEnable0[TX_DEBUG_INDEX] 	= CAN_C_st_TX_MsgEnable_Debug;		
	CAN_m_st_TxMsgEnable0[TX_XCP_INDEX] 	= FALSE;		
	#ifdef USE_DIAG
	CAN_m_st_TxMsgEnable0[MSG_DIAG_TX_INDEX] = TRUE;
	#endif

	ConfigTxMsgA(TX_PHASE_CURRENT_INDEX,TX_PHASE_CURRENT_ID,    8,100,(uint32_t*)&Tx_Msg_PhaseCur,TT_CYCLIC,Tx_Msg_PhaseExcCur_Encode,NULL);
	ConfigTxMsgA(TX_TEMP_BRIDGE_EXC_INDEX,TX_TEMP_BRIDGE_EXC_ID,    8,10,(uint32_t*)&Tx_Msg_TempBridgeExc,TT_CYCLIC,Tx_Msg_TempBridgeExc_Encode,NULL);
	ConfigTxMsgA(TX_VOLTAGE_INDEX,TX_VOLTAGE_ID,    8,10,(uint32_t*)&Tx_Msg_Voltage,TT_CYCLIC,Tx_Msg_Voltage_Encode,NULL);
	ConfigTxMsgA(TX_STATOR_SHELL_REF_INDEX,TX_STATOR_SHELL_REF_ID,    8,10,(uint32_t*)&Tx_Msg_StatorShellRef,TT_CYCLIC,Tx_Msg_StatorShellRef_Encode,NULL);
	ConfigTxMsgA(TX_ADS1210_INDEX,TX_ADS1210_ID,    8,10,(uint32_t*)&Tx_Msg_ADS1210,TT_CYCLIC,Tx_Msg_ADS1210_Encode,NULL);
	ConfigTxMsgA(TX_DEBUG_INDEX,TX_DEBUG_ID,    8,1,(uint32_t*)&Tx_Msg_Debug,TT_CYCLIC,Tx_Msg_Debug_Encode,NULL);
	ConfigTxMsgA(TX_XCP_INDEX,TX_XCP_ID,    8,10,(uint32_t*)NULL,TT_CYCLIC,NULL,NULL);
	#ifdef USE_DIAG
	ConfigTxMsgA(MSG_DIAG_TX_INDEX, MSG_DIAG_TX_ID, 8, 10,(uint32_t*)&gMSG_DIAG_TX,TT_ASYNC,NULL,NULL);
	#endif
}









