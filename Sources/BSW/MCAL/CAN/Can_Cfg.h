#ifndef _CFG_CAN_H_
#define _CFG_CAN_H_

#define USE_CAN_0
//#define USE_CAN_1

/***************************CAN Config **********************************/
/* can control register marco*/
#define CAN_PRESDIV(div)    (((uint32_t)div-1)<<24)   
#define CAN_RJW1        	0x00000000ul                 /* two bits */
#define CAN_RJW2        	0x00400000ul
#define CAN_RJW3        	0x00800000ul
#define CAN_RJW4        	0x00c00000ul
#define CAN_PSEG1(psg1)     (((uint32_t)psg1-1)<<19)  /* three bits */
#define CAN_PSEG2(psg2)     (((uint32_t)psg2-1)<<16)  /* three bits */        
#define CAN_PROPSEG(pseg)   (uint32_t)pseg-1

#define STDFMT              0
#define EXTFMT              1

#define MAX_MESSAGE_BUFF  	32   

#define CAN0_CLKSRC       	0    			/* 0: osc     1: sys clk */
#define CAN0_PRESDIV        CAN_PRESDIV(1)  /* bit timing, CAN baud = f(canclk)/((PREDIV)*(1+PSEG1+PROPSG+PSEG2)) */
#define CAN0_RJW            CAN_RJW2   		
#define CAN0_PSEG1          CAN_PSEG1(3)
#define CAN0_PSEG2          CAN_PSEG2(5)	/* when seg2 = 5, prop+seg1 = 6-13 */ 
#define CAN0_PROPSEG        CAN_PROPSEG(7)

#define CAN1_CLKSRC       	0    			/* 0: osc     1: sys clk */
#define CAN1_PRESDIV        CAN_PRESDIV(2)  /* bit timing, CAN baud = f(canclk)/((PREDIV)*(1+PSEG1+PROPSG+PSEG2)) */
#define CAN1_RJW            CAN_RJW2   		
#define CAN1_PSEG1          CAN_PSEG1(3)
#define CAN1_PSEG2          CAN_PSEG2(5)	/* when seg2 = 5, prop+seg1 = 6-13 */ 
#define CAN1_PROPSEG        CAN_PROPSEG(7)

/* bit timing, CAN baud = f(canclk)/((PREDIV)*(1+PSEG1+PROPSG+PSEG2)) 
   for 8MHz osc, 8000000/(1*(1+3+7+5))=500k
   for 40MHz osc, 8000000/(5*(1+3+7+5))=500k
   if define PREDIV(2), then it is 250k
*/
/*40M*/            
#define CAN0CTRL500  		CAN0_CLKSRC|CAN_PRESDIV(5)|CAN0_RJW|CAN0_PSEG1|CAN0_PSEG2|CAN0_PROPSEG   

/*8M*/
/*
#define CAN0CTRL100  		CAN0_CLKSRC|CAN_PRESDIV(5)|CAN0_RJW|CAN0_PSEG1|CAN0_PSEG2|CAN0_PROPSEG       

#define CAN0CTRL250  		CAN0_CLKSRC|CAN1_PRESDIV|CAN0_RJW|CAN0_PSEG1|CAN0_PSEG2|CAN0_PROPSEG       

#define CAN0CTRL500  		CAN0_CLKSRC|CAN0_PRESDIV|CAN0_RJW|CAN0_PSEG1|CAN0_PSEG2|CAN0_PROPSEG   

#define CAN1CTRL100  		CAN1_CLKSRC|CAN_PRESDIV(5)|CAN1_RJW|CAN1_PSEG1|CAN1_PSEG2|CAN1_PROPSEG   

#define CAN1CTRL250  		CAN1_CLKSRC|CAN1_PRESDIV|CAN1_RJW|CAN1_PSEG1|CAN1_PSEG2|CAN1_PROPSEG       

#define CAN1CTRL500  		CAN1_CLKSRC|CAN0_PRESDIV|CAN1_RJW|CAN1_PSEG1|CAN1_PSEG2|CAN1_PROPSEG       
*/
//#define CAN0_ID_TYPE EXTFMT //modified by xyl
#define CAN0_ID_TYPE STDFMT     /* CAN ID type */

/* transmit buffer, use buffer30 and buffer31 as transmit buffer, the other used to Rx */
#define TX_BUFF0          31 
#define TX_BUFF1          30
#define TX_BUFF2          29
#define TX_BUFF3          28
#define TX_BUFF4          27
#define TX_BUFF5          26
/*
31
30
29
28
27
26*/

#define TX_BUSY           1
#define TX_OK             0


/*********** CAN Config ****************/

#endif

