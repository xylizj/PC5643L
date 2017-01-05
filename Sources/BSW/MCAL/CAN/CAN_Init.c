/***********************************************************************
 File Name:      CAN_Init.c
 Description:    initilize the can driver
 Last Modified: 
 2011-08-31, lzy, clear IFRL flag in CAN_A_Receive() 
 2012-02-25, lzy, adapt for HCU 
 2012-03-08, lzy, fix initial error
 2012-09-02, lzy, fixed XCP map order error, XCP need msg send orderly

/************************************************************************/

#include "CAN_Init.h"

uint8_t CAN1_m_st_BusError = 0;
uint8_t CAN0_m_st_BusError = 0;

uint8_t CAN0_m_ct_MsgReceived = 0;


boolean CAN0_m_st_TxError = 0;
boolean CAN0_m_st_RxError = 0;

 
boolean CAN1_m_st_Initialized = 0;
boolean CAN0_m_st_Initialized = 0;


#ifdef USE_CAN_0

void CAN_TransceiverInit(void);
void CAN_PAD_Config(void);
uint8_t CAN_0_Init(void);


/*********************************************************************/
/*  function name:  CAN_init() 
/*  description:    initialize the can module
/*  parameters:     none
/*  return values:  none
/*  remark:
/*********************************************************************/
void CAN_Init(void)
{
	CAN_PAD_Config();	
	CAN_TransceiverInit();
	CAN_0_Init();
}


void CAN_TransceiverInit(void)
{
	//vehicle CAN power
  /* MPC5643L: Config pad G[3] pin as GPIO output */
  SIU.PCR[99].B.PA = 0;//GPIO
  SIU.PCR[99].B.OBE = 1;//enables the output buffer of the pad in case the pad is in GPIO mode.
	SIU.GPDO[99].R=1;
}


void CAN_PAD_Config(void)
{  	
	SIU.PSMI[33].B.PADSEL = 1;//CAN0 PAD select
	SIU_PAD_CONFIG(CAN0_TX, CAN0_TX_CONFIG);
	SIU_PAD_CONFIG(CAN0_RX, CAN0_RX_CONFIG);
}


uint8_t CAN_0_Init(void)
{
    uint16_t  i;

    CAN_0.MCR.B.MDIS    = 1;
    CAN_0.CR.R  = CAN0CTRL500;
             
    CAN_0.MCR.B.MDIS    = 0;
    
    /* Enable to enter Freeze mode  */
    CAN_0.MCR.B.FRZ   =  1;
    CAN_0.MCR.B.HALT    = 1;
    
    /* initilize can buffer */
    for(i=0; i<MAX_MESSAGE_BUFF; i++)
    {
        /* Keep RX MB as INACTIVE */
        CAN_0.BUF[i].CS.B.CODE = 0;
        CAN_0.BUF[i].ID.R = 0;
        CAN_0.BUF[i].DATA.W[0] = 0;
        CAN_0.BUF[i].DATA.W[1] = 0;
    }
    
    /* Acceptance Mask */
    CAN_0.RXGMASK.R  = 0x1FFFFFFF;//must be 0x1FFFFFFF
    /* Disable all Message Buffer Interrupt */
    CAN_0.IMRH.R  = 0x00000000;
    CAN_0.IMRL.R  = 0x00000000;
    CAN_0.MCR.B.MAXMB  = MAX_MESSAGE_BUFF-1;
	    
    CAN_0.BUF[TX_BUFF0].CS.B.CODE = 0x8;  
    CAN_0.BUF[TX_BUFF1].CS.B.CODE = 0x8;  
    CAN_0.BUF[TX_BUFF2].CS.B.CODE = 0x8;  
    CAN_0.BUF[TX_BUFF3].CS.B.CODE = 0x8;  

    for(i=0; i<CAN0_RX_MSG_NUM; i++)
    {
    	if( CAN_m_st_RxMsgEnable0[i] )
    	{
  			#if (CAN0_ID_TYPE == STDFMT)
				CAN_0.BUF[i].CS.B.IDE = 0; 
				CAN_0.BUF[i].ID.B.STD_ID = RxMsgBuffA[i].id ;
				#else
				CAN_0.BUF[i].CS.B.IDE = 1; 
				CAN_0.BUF[i].ID.R = RxMsgBuffA[i].id;
				#endif
		
				CAN_0.BUF[i].CS.B.CODE = 4;
    	}
    }

    /* Disable Self reception */
    CAN_0.MCR.B.SRX_DIS = 1;
    
    CAN_0.MCR.B.AEN = 1;   
    CAN_0.MCR.B.SUPV   =  0;
    /********************************/
    /* Exit freeze mode             */
    /********************************/
    
    /* Disable Freeze mode request */
    CAN_0.MCR.B.HALT  =  0;
    /* Disable to enter Freeze mode  */
    CAN_0.MCR.B.FRZ   =  0;
   
    /* waiting CAN ready, 11 consecutive recessive bits */
    for(i=1; i < 1000; i++){}
    
    if(CAN_0.MCR.B.NOT_RDY == 1)
    {
       return 1;
    }    

    return 0;
}


void CAN_0_Monitor(void)
{
	if( CAN_0.ESR.R & CAN_ESR_TWRNINT )
	{
		CAN0_m_st_TxError = 1;
		CAN_0.ESR.R |= CAN_ESR_TWRNINT;
	}
	else
	{
		CAN0_m_st_TxError = 0;
	}
		
	if( CAN_0.ESR.R & CAN_ESR_RWRNINT )
	{
		CAN0_m_st_RxError = 1;
		CAN_0.ESR.R |= CAN_ESR_RWRNINT;
	}
	else
	{
		CAN0_m_st_RxError = 0;
	}
		
	
	if( CAN_0.ESR.R & CAN_ESR_BOFFINT )
	{		
		CAN_0.ESR.R |= CAN_ESR_BOFFINT;//write 1 to clear
		CAN0_m_st_BusError = 1;
	}
	else
	{
		CAN0_m_st_BusError = 0;
	}
}



/*********************************************************************/
/*  function name:  CAN_A_Transmit() 
/*  description:    transmit the can message
/*  parameters:     id     - can id
/*                  data   - the pointer pointed to the data that will be transmit
/*                  length - the length of data
/*  return values:  none
/*  remark:
/*********************************************************************/
#define CAN_TRANSMIT_DELAY 5000
uint8_t CAN_0_Transmit(vuint32_t id, uint8_t* data, uint8_t length)
{
 	uint16_t index;
 	vuint8_t txbuf;

  if(CAN_0.BUF[TX_BUFF0].CS.B.CODE == 0x8)
 	{
	 	txbuf = TX_BUFF0;
 	}
 	else if(CAN_0.BUF[TX_BUFF1].CS.B.CODE == 0x8)
 	{
 	 	txbuf = TX_BUFF1;
 	}
 	else if(CAN_0.BUF[TX_BUFF2].CS.B.CODE == 0x8)
 	{
 	 	txbuf = TX_BUFF2;
 	}
 	else if(CAN_0.BUF[TX_BUFF3].CS.B.CODE == 0x8)
 	{
 	 	txbuf = TX_BUFF3;
 	}
 	else
 	{
 		return TX_BUSY;
 	}  

 	if(CAN_0.IFRL.R & (uint32)(1<<txbuf))
	{
		CAN_0.IFRL.R |= (uint32)(1<<txbuf);
	}
	  	

	CAN_0.BUF[txbuf].CS.B.RTR = 0x0;
	#if (CAN0_ID_TYPE == STDFMT)
	  CAN_0.BUF[txbuf].CS.B.IDE= 0x0;
	  CAN_0.BUF[txbuf].ID.B.STD_ID = id;
	#else
	  CAN_0.BUF[txbuf].CS.B.IDE= 1;
	  CAN_0.BUF[txbuf].ID.R = id;
	#endif
	
	CAN_0.BUF[txbuf].DATA.W[0] = *( (uint32_t *)data );
	CAN_0.BUF[txbuf].DATA.W[1] = *( (uint32_t *)(data+4) );
		    
	CAN_0.BUF[txbuf].CS.B.LENGTH = length;
	CAN_0.BUF[txbuf].CS.B.SRR = 1;

	CAN_0.BUF[txbuf].CS.B.CODE = 0xC;
    
    return TX_OK;
 }
 
 

 /* 2016-05-05, lzy, added for XCP */
uint8_t CAN_A_XCP_Transmit(uint32_t id, uint8_t* data, uint8_t length)//added by xyl 2015.5.29
{
	return CAN_0_Transmit(id, data, length);
}

 /* 2016-05-05, lzy, added for XCP */
 uint8_t CAN_C_XCP_Transmit(uint32_t id, uint8_t* data, uint8_t length)
{

 }

/*********************************************************************/
/*  function name:  CAN_A_Receive() 
/*  description:    read the value from the mail box 
/*  parameters:     none
/*  return values:  none
/*  remark:         disposal the timeout temporarily
/*********************************************************************/
void CAN_0_Receive(void)
{
  	uint32_t n;
  	uint32_t i; 
  	
  	n = ( CAN0_RX_MSG_NUM < 32 ? CAN0_RX_MSG_NUM : 32 );
  	
  	for( i=0; i<n; i++ )
  	{
	   	if( ( CAN_0.IFRL.R & ((uint32_t)(0x00000001U<<i) ) ) != 0U )
	   	{	   										
	   		RxMsgBuffA[i].dl = (uint8_t)CAN_0.BUF[i].CS.B.LENGTH;
	    	RxMsgBuffA[i].data[0] = CAN_0.BUF[i].DATA.W[0];
	    	RxMsgBuffA[i].data[1] = CAN_0.BUF[i].DATA.W[1];
	    	RxMsgBuffA[i].timer = Gpt_GetCurrentCnt();

    		//(void)CAN_0.BUF[i].CS.B.TIMESTAMP; 
 	        /* Added to make it empty, it's only for used on MPC 55xx */
	        //CAN_0.BUF[i].CS.B.CODE = 0x04;
	        n = CAN_0.TIMER.R;   /* unlock buffer*/
    		
	        /* Clear the flag */
	        CAN_0.IFRL.R  |= (uint32_t)( 0x00000001U<<i); //clear the flag
	        
	        if( RxMsgBuffA[i].decode_func != NULL )
	        {

	        	RxMsgBuffA[i].decode_func();
	        }
	        
	        #ifdef USE_CAN_A        
	        if( RxMsgBuffA[i].tt == TT_FORWARD )
	        {
	        	TxMsgBuffC[i].state = PG_TX_REQ;
	        }	        
	        #endif
	            			
    		return; /* erery time receive only one msg */
	   	}
  	}
   
   return;		
}
#endif















































		

/*====== end ========*/