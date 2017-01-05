#ifndef __CAN_MSG_H_
#define __CAN_MSG_H_


#include "Platform_Types.h"
#include "typedefs.h"
#include "Msg_Type.h"
#include "null.h"
#include "Adc.h"
#include "FlexPWM.h"
#include "Dem.h"
#include "Ioa.h"
#include "Diag.h"


#define TBL_COUNT_1MS	10000

#define TT_ASYNC 	0     
#define TT_CYCLIC 	1    
#define TT_BAM 		2       
#define TT_CMDT 	3      
#define TT_FORWARD 	4      


#define PG_TX_FREE  0      
#define PG_TX_REQ   1      
#define PG_TX_XMT   2      
#define PG_TX_TX    3     

#define PG_RX_FREE  0      
#define PG_RX_FULL  1    

#define RX_PTC1_ID								0x101
#define RX_PTC2_ID								0x111
#define RX_PIPE_HEAT_ID						0x121
#define RX_SCR_TANKHEAT_ID				0x131
#define RX_I_DQ_ID						0x141
#define RX_PWM0_RATIO_ID					0x151
#define RX_XCP_ID									0x1FE



#define TX_PHASE_CURRENT_ID				0x1F1
#define TX_TEMP_BRIDGE_EXC_ID			0x1F2 
#define TX_VOLTAGE_ID							0x1F3
#define TX_STATOR_SHELL_REF_ID		0x1F4
#define TX_ADS1210_ID							0x1F5
#define TX_DEBUG_ID					0x1F6
#define TX_XCP_ID									0x1FF




#ifndef USE_DIAG
#define MSG_DIAG_RX_INDEX 0
typedef enum _msg_rx_index_tag
{
	RX_PTC1_INDEX,	
	RX_PTC2_INDEX,
	RX_PIPE_HEAT_INDEX,
	RX_SCR_TANKHEAT_INDEX,
	RX_DQ_INDEX,
	RX_PWM0_RATIO_INDEX,
	RX_XCP_INDEX,
	
	CAN0_RX_MSG_NUM,
}MSG_RX_INDEX_TYPE;


#define MSG_DIAG_TX_INDEX 0
typedef enum _msg_tx_index_tag
{
	TX_PHASE_CURRENT_INDEX,
	TX_TEMP_BRIDGE_EXC_INDEX,
	TX_VOLTAGE_INDEX,
	TX_STATOR_SHELL_REF_INDEX,
	TX_ADS1210_INDEX,
	TX_DEBUG_INDEX,
	
	CAN0_TX_MSG_NUM,
}MSG_TX_INDEX_TYPE;

#else

typedef enum _msg_rx_index_tag
{
	RX_PTC1_INDEX,	
	RX_PTC2_INDEX,
	RX_PIPE_HEAT_INDEX,
	RX_SCR_TANKHEAT_INDEX,
	RX_DQ_INDEX,
	RX_PWM0_RATIO_INDEX,
	RX_XCP_INDEX,
	MSG_DIAG_RX_INDEX,
	
	CAN0_RX_MSG_NUM
}MSG_RX_INDEX_TYPE;


typedef enum _msg_tx_index_tag
{
	TX_PHASE_CURRENT_INDEX,
	TX_TEMP_BRIDGE_EXC_INDEX,
	TX_VOLTAGE_INDEX,
	TX_STATOR_SHELL_REF_INDEX,
	TX_ADS1210_INDEX,
	TX_DEBUG_INDEX,
	TX_XCP_INDEX,
	
	MSG_DIAG_TX_INDEX,
	CAN0_TX_MSG_NUM
}MSG_TX_INDEX_TYPE;
#endif








extern volatile boolean CAN_m_st_RxMsgEnable0[CAN0_RX_MSG_NUM];
extern volatile boolean CAN_m_st_TxMsgEnable0[CAN0_TX_MSG_NUM];

extern volatile RX_tag_type RxMsgBuffA[CAN0_RX_MSG_NUM];
extern volatile TX_tag_type TxMsgBuffA[CAN0_TX_MSG_NUM];
//extern volatile Msg_Rx_tag_type gMSG_DIAG_RX;

extern void CAN_InitMsg(void);
































#endif/*__CAN_MSG_H_*/