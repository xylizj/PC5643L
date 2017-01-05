#include "CAN_Stack.h"
#include "CAN_Msg.h"



uint32_t CAN_m_st_RxTimeOutA;
uint32_t CAN_m_st_RxTimeOutC;
uint32_t CAN_m_st_TxTimeOutA;
uint32_t CAN_m_st_TxTimeOutC;

void CANTxRx_State(void)
{
	uint8_t i;

	for( i=0; i<CAN0_TX_MSG_NUM; i++ )
	{
		if( (TxMsgBuffA[i].state == PG_TX_REQ) && (TxMsgBuffA[i].dl <= 8) )
		{
			if( !CAN_0_Transmit(TxMsgBuffA[i].id, (uint8_t *)TxMsgBuffA[i].data, TxMsgBuffA[i].dl) )
			{
				TxMsgBuffA[i].state = PG_TX_FREE;
				CAN_m_st_TxTimeOutA &= ~((uint32_t)0x01<<i);
			}
		}
	}				
}


void CANTxRx_Timer(void)
{
	uint32_t cnt;
	uint32_t tmp;
	uint8_t i;
	
	cnt = Gpt_GetCurrentCnt();
	for( i=0; i<CAN0_TX_MSG_NUM; i++ )
	{
		if(TxMsgBuffA[i].enable == TRUE)
		{
			if( (TxMsgBuffA[i].tt == TT_CYCLIC)&&(TxMsgBuffA[i].state == PG_TX_FREE) )
			{
				tmp = cnt - TxMsgBuffA[i].timer;
				if( tmp >= TxMsgBuffA[i].rate )
				{
					if(TxMsgBuffA[i].encode_func != NULL)
					{
						TxMsgBuffA[i].encode_func();
					}
					TxMsgBuffA[i].state = PG_TX_REQ;
					TxMsgBuffA[i].timer = cnt;
					break;
				}
			}		
		}
	}	
	
	/* check Rx time out */
	for( i=0; i<CAN0_RX_MSG_NUM; i++ )
	{
		if(RxMsgBuffA[i].enable == TRUE)
		{
			if(RxMsgBuffA[i].tt == TT_CYCLIC)
			{
				tmp = cnt - RxMsgBuffA[i].timer;
				if( tmp > (4*RxMsgBuffA[i].rate) )
				{
					CAN_m_st_RxTimeOutA |= (uint32_t)((uint32_t)0x00000001<<i);
					if(RxMsgBuffA[i].rx_timeout_func != NULL)
					{
						RxMsgBuffA[i].rx_timeout_func();
					}
				}
			}
		}
	}		
	
	/* check Tx time out, which means Tx error or bus busy */
	for( i=0; i<CAN0_TX_MSG_NUM; i++ )
	{
		if(TxMsgBuffA[i].state == PG_TX_REQ)
		{
			tmp = cnt - TxMsgBuffA[i].timer;
			if( tmp > TxMsgBuffA[i].rate )
			{
				CAN_m_st_TxTimeOutA |= ((uint32_t)0x00000001<<i);
				if(TxMsgBuffA[i].tx_err_func != NULL)
				{
					TxMsgBuffA[i].tx_err_func();
				}
			}
		}
	}
}