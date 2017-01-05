#ifndef __MSG_TYPE_H_
#define __MSG_TYPE_H_



typedef void  (* FuncType ) (void);


typedef struct _TX_tag
{
  vuint32_t id;         //4  
  uint32_t  *data;      //8   
  vuint8_t  dl;   		//9
  vuint8_t  enable;     //10    
  vuint8_t  state;      //11    
  vuint8_t 	tt;			//12
  vuint32_t rate;    	//16
  vuint32_t timer;      //20 
  FuncType encode_func; //24
  FuncType tx_err_func; //28 
} TX_tag_type;	


typedef struct _RX_tag
{
  vuint32_t id;         //4  
  uint32_t  *data;      //8   
  vuint8_t  dl;   		//9
  vuint8_t  enable;     //10    
  vuint8_t  state;      //11    
  vuint8_t 	tt;			//12
  vuint32_t rate;    	//16
  vuint32_t timer;      //20 
  FuncType decode_func; //24
  FuncType rx_timeout_func; //28
} RX_tag_type;				//size = 28 bytes

/*RX message structure definition*/
typedef struct _Msg_Rx_tag
{
	vuint8_t data[8];
}Msg_Rx_tag_type;


/*TX message structure definition*/
typedef struct _Msg_Tx_tag
{
	vuint8_t data[8];
}Msg_Tx_tag_type;


typedef struct
{
  uint32 length;
  uint32 id;
  uint8  data[8];
} CanXcp_MsgType;


































#endif/*__MSG_TYPE_H_*/