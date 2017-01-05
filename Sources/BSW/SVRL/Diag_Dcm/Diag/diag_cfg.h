#ifndef __CFG_H_
#define __CFG_H_



#define USE_DIAG 


//#define  MSG_DIAG_RX_INDEX		0

/************************ CAN_A/PCAN TX DIAG MSG INDEX ************************
	DIAG_TX		0x18DAFA01		8	TT_ASYNC	0
*************************************************************************/
//#define  MSG_DIAG_TX_INDEX		0



#define TT_ASYNC 	  0     
#define TT_CYCLIC 	1    
#define TT_BAM 		  2       
#define TT_CMDT 	  3      
#define TT_FORWARD 	4      


#define PG_TX_FREE     0      
#define PG_TX_REQ      1      
#define PG_TX_XMT      2      
#define PG_TX_TX       3     

#define PG_RX_FREE     0      
#define PG_RX_FULL     1      

















#endif /* _J1939CFG_H_ */





