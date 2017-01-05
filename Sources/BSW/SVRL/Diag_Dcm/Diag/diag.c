/************************************************************************
File Name:      diag.c
Project:		

Last Modified:	by xyl on 2014-11-27

Records:

  xyl, some been modified and some been added to 
    adapt for G64 DRL from ISO15765 TP for MPC5633M platform,
    combined with previous CAN config and Tx Rx functions   

************************************************************************/

#include "diag.h"


//extern uint32_t Gpt_GetCurrentCnt();

//void memcpy(uint8_t *dest, uint8_t *source, uint16_t count);

//volatile RX_tag_type RxMsgBuffA[CAN0_RX_MSG_NUM];
//volatile TX_tag_type TxMsgBuffA[CAN0_TX_MSG_NUM];

vuint8_t diag_rx_buff[DIAG_RX_BUFF_SIZE];
vuint8_t diag_tx_buff[DIAG_TX_BUFF_SIZE];

volatile struct RX_TP_tag rx_state;
volatile struct TX_TP_tag tx_state;

volatile struct DIAG_RX_tag 	gMSG_DIAG_RX;
volatile struct DIAG_TX_tag 	gMSG_DIAG_TX;

vuint8_t Diag_state;
vuint8_t ucRxTSmin;
vuint8_t ucRxBSmax;
vuint8_t ucTxTSmin;
vuint8_t ucTxBSmax;


void Diag_InitTP(void);
void Diag_SendFlowControl(void); 
void Diag_State(void);
void Diag_TPTransmit(void);
void Diag_MsgIndication(void); 
void MsgDIAG_RX_Decode(void);  


/*void ConfigTxMsgA(uint8_t index, uint32_t id, uint8_t dl, uint32_t* data)
{
	if( index >= CAN0_TX_MSG_NUM )
	{
		return;
	}	
	TxMsgBuffA[index].id 		= id;	
	TxMsgBuffA[index].dl 		= dl;	
	TxMsgBuffA[index].data 		= data;	
	TxMsgBuffA[index].state 	= PG_TX_FREE;	
	TxMsgBuffA[index].timer 	= Gpt_GetCurrentCnt();//Modified by xyl 2014.11.28
}

void ConfigRxMsgA(uint8_t index, uint32_t id, uint8_t dl, uint32_t* data)
{
	if( index >= CAN0_RX_MSG_NUM )
	{
		return;
	}	
	RxMsgBuffA[index].id 		= id;	
	RxMsgBuffA[index].dl 		= dl;	
	RxMsgBuffA[index].data 		= data;	
	RxMsgBuffA[index].state 	= PG_RX_FREE;	
	RxMsgBuffA[index].timer 	=  Gpt_GetCurrentCnt();//Modified by xyl 2014.11.28
}*/





void Diag_InitTP(void)
{
	rx_state.timer = Gpt_GetCurrentCnt();//Modified by xyl 2014.11.28
	rx_state.rx_buffer = diag_rx_buff;
	rx_state.data_length = 0;
	rx_state.index = 0;
	rx_state.sn = 0;
	rx_state.st = kRxState_Idle;
	rx_state.target_address = 0xff;
	rx_state.source_address = 0xff;

	tx_state.timer = Gpt_GetCurrentCnt();//Modified by xyl 2014.11.28
	tx_state.tx_buffer = diag_tx_buff;
	tx_state.data_length = 0;
	tx_state.index = 0;
	tx_state.sn = 0;
	tx_state.st = kTxState_Idle;
	tx_state.target_address = 0xff;
	tx_state.source_address = 0xff;
  
  Diag_state = DIAG_STATE_INACTIVE;
  ucRxTSmin = 20;//150ms/50ms
	ucRxBSmax = 0;
}





/*
After receive Diag message, 
*/
void MsgDIAG_RX_Decode(void)  
{
		uint16_t dl;
               
    //RxMsgBuffA[MSG_DIAG_RX_INDEX].timer = Gpt_GetCurrentCnt();//ADDED by xyl 2014.11.28
	  
		Diag_state = DIAG_STATE_ACTIVE;
	
    switch( gMSG_DIAG_RX.data[0] & 0xf0 ) 
    {
    	case kSingleFrame:
    	{	
    		if( rx_state.st != kRxState_Idle )
    		{
    			return ;
    		}
    		dl = gMSG_DIAG_RX.data[0];
    		if( (dl>7) || (dl==0) )
    		{
    			return ;
    		}
    		rx_state.timer = RxMsgBuffA[MSG_DIAG_RX_INDEX].timer;
    		rx_state.data_length = dl;
    		rx_state.index = 0;
    		memcpy((uint8_t *)&diag_rx_buff[0],(uint8_t *)&gMSG_DIAG_RX.data[1], dl);
    		rx_state.st = kRxState_ApplInformed;
    		Diag_MsgIndication();
    		rx_state.st = kRxState_Idle;
				break;
      }
      		
    	case kFirstFrame:
    	{
    		if( rx_state.st != kRxState_Idle )
    		{
    			return ;
    		}
    		if( (0x0f & RxMsgBuffA[MSG_DIAG_RX_INDEX].dl) != 8 )   //for FF, dl must be 8
    		{
    			return ;
    		}
    		
    		dl =  (uint16_t)((gMSG_DIAG_RX.data[0] & 0x0f)<<8) + (uint16_t)gMSG_DIAG_RX.data[1];
    		if(dl<8) 
    		{
    			return ;
    		}
    		memcpy((uint8_t *)&diag_rx_buff[0],(uint8_t *)&gMSG_DIAG_RX.data[2], 6);
    		rx_state.data_length = dl;
    		rx_state.index = 6;
    		rx_state.sn = 1;
    		rx_state.timer = RxMsgBuffA[MSG_DIAG_RX_INDEX].timer;
    		Diag_SendFlowControl();
    		rx_state.st = kRxState_TxFC;
    		break;
      }
    		
    	case kConsecutiveFrame:
    	{
    		if( rx_state.st != kRxState_WaitCF ) 
    		{
    			return ;
    		}
    		if( (gMSG_DIAG_RX.data[0] & 0x0f) != rx_state.sn )
    		{
    			return ;
    		}
    		rx_state.timer = RxMsgBuffA[MSG_DIAG_RX_INDEX].timer;
    		
    		dl = rx_state.data_length - rx_state.index;
    		if( dl < 7 )
    		{
    			memcpy((uint8_t *)&diag_rx_buff[rx_state.index],(uint8_t *)&gMSG_DIAG_RX.data[1],dl);
    		}
    		else
    		{
    			memcpy((uint8_t *)&diag_rx_buff[rx_state.index],(uint8_t *)&gMSG_DIAG_RX.data[1],7);
    		}
    		rx_state.index += 7;
    		if( rx_state.index >= rx_state.data_length ) 
    		{
    			rx_state.st = kRxState_ApplInformed;
    			Diag_MsgIndication();
    		  rx_state.st = kRxState_Idle;
				} 
    		else 
    		{
    			rx_state.st = kRxState_WaitCF;
    			rx_state.sn++;
    			if( rx_state.sn == 16 ) 
    			{
    				rx_state.sn = 0;
    			}
    		}
    		break;
    	}
    		
    	case kFlowControlFrame:
    	{
    		if( tx_state.st == kTxState_WaitFC )
    		{
    			ucTxBSmax = gMSG_DIAG_RX.data[1];
    			ucTxTSmin = gMSG_DIAG_RX.data[2];
    			tx_state.st = kTxState_WaitTxCF;
    			tx_state.timer = RxMsgBuffA[MSG_DIAG_RX_INDEX].timer;
    		}
    		break;
    	}
    		
    	default:
    		break;
    }  
} 
      

void Diag_SendFlowControl(void) 
{
	/*if( tx_state.st != kTxState_Idle )
	{
		return;
	}*/
    gMSG_DIAG_TX.data[0] = kFlowControlFrame;
    gMSG_DIAG_TX.data[1] = ucRxBSmax;
    gMSG_DIAG_TX.data[2] = ucRxTSmin;
    gMSG_DIAG_TX.data[3] = 
    gMSG_DIAG_TX.data[4] = 
    gMSG_DIAG_TX.data[5] = 
    gMSG_DIAG_TX.data[6] = 
    gMSG_DIAG_TX.data[7] = 0XFF;
    TxMsgBuffA[MSG_DIAG_TX_INDEX].state = PG_TX_REQ;
    return ;
}






void Diag_TPTransmit(void)
{
	if( 0 == tx_state.data_length){
	  return;
	}
	
	if( tx_state.data_length < 0x08 )
	{
	    gMSG_DIAG_TX.data[0] = (uint8)tx_state.data_length;
	    gMSG_DIAG_TX.data[1] = diag_tx_buff[0];
	    gMSG_DIAG_TX.data[2] = diag_tx_buff[1];
	    gMSG_DIAG_TX.data[3] = diag_tx_buff[2];
	    gMSG_DIAG_TX.data[4] = diag_tx_buff[3];
	    gMSG_DIAG_TX.data[5] = diag_tx_buff[4];
	    gMSG_DIAG_TX.data[6] = diag_tx_buff[5];
	    gMSG_DIAG_TX.data[7] = diag_tx_buff[6];
	    TxMsgBuffA[MSG_DIAG_TX_INDEX].state = PG_TX_REQ;
	    tx_state.st = kTxState_ReqTx;
	    tx_state.index = tx_state.data_length;
	}
	else
	{
		/* Send First Frame */
	    gMSG_DIAG_TX.data[0] = (uint8_t)(kFirstFrame + (0x0f & (tx_state.data_length>>8)));
	    gMSG_DIAG_TX.data[1] = (uint8_t)(0xff & (tx_state.data_length) );
	    gMSG_DIAG_TX.data[2] = diag_tx_buff[0];
	    gMSG_DIAG_TX.data[3] = diag_tx_buff[1];
	    gMSG_DIAG_TX.data[4] = diag_tx_buff[2];
	    gMSG_DIAG_TX.data[5] = diag_tx_buff[3];
	    gMSG_DIAG_TX.data[6] = diag_tx_buff[4];
	    gMSG_DIAG_TX.data[7] = diag_tx_buff[5];
	    tx_state.index = 6;
	    tx_state.sn = 1;
	    TxMsgBuffA[MSG_DIAG_TX_INDEX].state = PG_TX_REQ;
	    tx_state.st = kTxState_WaitFC;
	}
}

void Diag_State(void)
{
	uint32_t ct;
	uint32_t tmp;
	uint16_t dl;
	
	ct = Gpt_GetCurrentCnt();

	/* Check TX message */
	if( TxMsgBuffA[MSG_DIAG_TX_INDEX].state == PG_TX_REQ ) 
	{
		if( !CAN_0_Transmit(TxMsgBuffA[MSG_DIAG_TX_INDEX].id, \
			(uint8_t *)TxMsgBuffA[MSG_DIAG_TX_INDEX].data, TxMsgBuffA[MSG_DIAG_TX_INDEX].dl) )
		{
			TxMsgBuffA[MSG_DIAG_TX_INDEX].state = PG_TX_FREE;			
			if( rx_state.st == kRxState_TxFC )
			{
				rx_state.st = kRxState_WaitCF;
			}			
			if(tx_state.st == kTxState_ReqTx)
			{
				tx_state.st = kTxState_Idle;
			}
		}
	}

	if(	tx_state.st == kTxState_WaitTxCF )
	{
		tmp = ct - tx_state.timer;
		
		/* Check P2 Timeout */
		if( tmp > DIAG_P2_TIMEOUT_COUNT )
		{
			Diag_InitTP();
		}
		
		if( ( tmp > (ucTxTSmin*TBL_COUNT_1MS) ) && (TxMsgBuffA[MSG_DIAG_TX_INDEX].state == PG_TX_FREE ) )
		{
      dl = tx_state.data_length - tx_state.index;
      //if( dl < 7 )//here a bug!
      if( dl <= 7 )
      {
        gMSG_DIAG_TX.data[0] = kConsecutiveFrame + tx_state.sn;
      	memcpy((uint8_t *)&gMSG_DIAG_TX.data[1],(uint8_t *)&diag_tx_buff[tx_state.index],dl);
      	tx_state.index += dl;
      	tx_state.st = kTxState_Idle;
      }
      else
      {
        gMSG_DIAG_TX.data[0] = kConsecutiveFrame + tx_state.sn;
      	memcpy((uint8_t *)&gMSG_DIAG_TX.data[1],(uint8_t *)&diag_tx_buff[tx_state.index],7);
      	tx_state.index += 7;
        tx_state.sn++;
        if( tx_state.sn == 16 ) tx_state.sn = 0;
      }
            
			TxMsgBuffA[MSG_DIAG_TX_INDEX].state = PG_TX_REQ;
      tx_state.timer = ct;
		}		
  }

	/* Check P3 Timeout */
	if( Diag_state == DIAG_STATE_ACTIVE )
	{
		tmp =  ct - RxMsgBuffA[MSG_DIAG_RX_INDEX].timer;
		if( tmp > DIAG_P3_TIMEOUT_COUNT )
		{
			Diag_InitTP();
		}
	}
	
}








/*void memcpy(uint8_t *dest, uint8_t *source, uint16_t count)
{
   uint8_t* sd = dest;
   uint8_t* ss = source;
   while (count > 0)
   {
      *sd++ = *ss++;
      count--;
   }
}*/


void Diag_MsgIndication(void) 
{
    switch( diag_rx_buff[0] )
    {
    	case SID_REQUEST_CURRENT_POWERTRAIN_DIAGNOSTIC_DATA:
    	{
   			ObdRequestCurrentPowertrainDiagnosticData();
    		break;	
    	}
    	
    	case SID_REQUEST_POWERTRAIN_FREEZE_FRAME_DATA:
    	{
    		DspObdRequsetPowertrainFreezeFrameData();
    		break;	
    	}
    	
    	case SID_REQUEST_EMISSION_RELATED_DIAGNOSTIC_TROUBLE_CODES:
    	{
    		Dcm_ApplReadEmissionConfirmedDTC();
    		break;	
    	}
    	
    	case SID_CLEAR_EMISSION_RELATED_DIAGNOSTIC_INFORMATION:
    	{
    		Dcm_ApplClrEmmisionDigInfo();
    		break;	
    	}
    	
    	case SID_REQUEST_OXYGEN_SENSOR_MONITORING_TEST_RESULTS:
    	{//No need to support in SCR Project
    		break;	
    	}
    	
    	case SID_REQUEST_ONBOARD_MONITORING_TEST_RESULTS:
    	{//No need to support in SCR Project
    		break;	
    	}
    	
    	case SID_REQUEST_EMISSION_RELATED_DIAGNOSTIC_TROUBLE_CODES_DETECTED_DURING_CURRENT_OR_LAST_COMPLETED_DRIVING_CYCLE:
    	{
    		Dcm_ApplReadEmissionDTCDuringCurrentOrLastCycle();
    		break;	
    	}
    	
    	case SID_REQUEST_CONTROL_OF_ONBOARDSYSTEM:
    	{//No need to support in SCR Project
    		break;	
    	}
    	
    	case SID_REQUEST_VEHICLE_INFORMATION:
    	{
    		DspObdRequestvehicleinformation();
    		break;	
    	}
    	
    	default:
    	break;
    }
}

