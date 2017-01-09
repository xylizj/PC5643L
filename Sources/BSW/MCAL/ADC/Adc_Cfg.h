/************************************************************************
File name: Adc_Cfg.h

Copyright Eureka Control 2009, 2010

Modify records:
2014-06-09

*************************************************************************/


#ifndef _Adc_Cfg_
#define _Adc_Cfg_

#include "Platform_Types.h"

  
/******************************************/
/**            AD Configration           **/
/******************************************/
/* Init. paramater */


/* ADC scaling,0 for 0mv, 5000 for 5000mv;   gain:0x13e3, offset:0x3fd6 */
#define ADC0GAIN    5095      /* 15bits, physical range:0-2, the first bit is integer number: 0 or 1,*/
#define ADC0OFFSET  -84     /* 14bits, physical range:-2.5v ~ 2.5v*/

#define ADC_RESULT_MASK (0x00000FFF)//lower 12bit



//below are in FIFO1
#define   ADC_CH_Half            0      //ADC0_2
#define   ADC_CH_T15	         1      //ADC1_2
#define   ADC_CH_Forward         2 		//ADC0_3
#define   ADC_CH_VBAT2	         3 		//ADC1_3
#define   ADC_CH_Mode_Temp       4 		//ADC0_4
#define   ADC_CH_VBAT		     5 		//ADC1_4
#define   ADC_CH_Motor_Temp      6 		//ADC0_6
#define   ADC_CH_REF	         7 		//ADC1_6
#define   ADC_CH_S_Break         8 		//ADC0_7
#define   ADC_CH_S_accelerator   9 		//ADC1_7
#define   ADC_CH_S_Reverse       10 	//ADC0_8
#define   ADC_CH_VREF	         11 	//ADC1_8

#define   ADC_FIFO1_TOTAL_CH		 12

//below are in FIFO0
#define   ADC_CH_I_A_accelerator 13 	//ADC1_0
#define   ADC_CH_12V		     15 	//ADC1_1
#define   ADC_CH_5V          	 16     //ADC1_5

#define   ADC_FIFO0_TOTAL_CH		 3

/******************************************/
#define   ADC_CH_NUM             15     //DO NOT CHANGE
#define   ADC_FLT_TIME           10     
#define   CTUFIFO3_CH_NUM        3
#define   CTUFIFO2_CH_NUM        1
#define   CTUFIFO2_FLT_TIME      10






#define CTU_FIFO3_THRESHOLD 2
#define CTU_FIFO3_DATA_BYTES	(4*CTU_FIFO3_THRESHOLD)

#define CTU_FIFO2_THRESHOLD (CTUFIFO2_CH_NUM)
#define CTU_FIFO2_DATA_BYTES	(4*CTU_FIFO2_THRESHOLD)

#define CTU_FIFO1_THRESHOLD 12
#define CTU_FIFO1_DATA_BYTES	(4*CTU_FIFO1_THRESHOLD)

#define CTU_FIFO0_THRESHOLD 3
#define CTU_FIFO0_DATA_BYTES	(4*CTU_FIFO0_THRESHOLD)

#define BITER_CNT ADC_FLT_TIME




#define ADC0_NUMBER_OF_CHANNELS		6
#define ADC0_NUMBER_OF_DATA_BYTES	(4*ADC0_NUMBER_OF_CHANNELS)

#define ADC1_NUMBER_OF_CHANNELS		9
#define ADC1_NUMBER_OF_DATA_BYTES	(4*ADC1_NUMBER_OF_CHANNELS)







#define NTC_90DEG 884
#define NTC_125DEG 336


#define PTC_100DEG 2048
#define PTC_150DEG 2341












#endif