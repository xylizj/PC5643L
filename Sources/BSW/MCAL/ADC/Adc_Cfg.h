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
#define   ADC_CH_V5              0      //ADC0_0
#define   ADC_CH_TempExc         1      //ADC1_0
#define   ADC_CH_ADC0_1          2 		//ADC0_1
#define   ADC_CH_ADC1_1          3 		//ADC1_1
#define   ADC_CH_V12             4 		//ADC0_2
#define   ADC_CH_TempStator      5 		//ADC1_2
#define   ADC_CH_TempPW          6 		//ADC0_3
#define   ADC_CH_ADC1_3          7 		//ADC1_3
#define   ADC_CH_ADC0_4          8 		//ADC0_4
#define   ADC_CH_ADC1_4          9 		//ADC1_4
#define   ADC_CH_TempPU          10 	//ADC0_5
#define   ADC_CH_ADC1_5          11 	//ADC1_5
#define   ADC_CH_ADC0_6          12 	//ADC0_6
#define   ADC_CH_ADC1_6          13		//ADC1_6

#define   ADC_FIFO1_TOTAL_CH		 14

//below are in FIFO0
#define   ADC_CH_V10             14 	//ADC0_7
#define   ADC_CH_TempShell       15 	//ADC1_7
#define   ADC_CH_TempPV          16     //ADC0_8
#define   ADC_CH_V48             17     //ADC1_8
#define   ADC_CH_CurRef          18 	//ADC0_11(ADCx_11)
#define   ADC_CH_ADCx_12         19		//ADC1_12(ADCx_12)
#define   ADC_CH_ADCx_13         20		//ADC0_13(ADCx_13)
#define   ADC_CH_ADCx_14         21		//ADC1_14(ADCx_14)
#define   ADC_CH_VReg0           22		//ADC0_10(1.2V)
#define   ADC_CH_TsensP          23		//ADC1_15(INSAMP=244)
#define   ADC_CH_TsensC          24		//ADC0_15(INSAMP=241)
#define   ADC_CH_VReg1           25		//ADC1_10(1.2V)

/******************************************/
#define   ADC_CH_NUM             26     //DO NOT CHANGE
#define   ADC_FLT_TIME           10     
#define   CTUFIFO3_CH_NUM        3
#define   CTUFIFO2_CH_NUM        1
#define   CTUFIFO2_FLT_TIME      10






#define CTU_FIFO3_THRESHOLD 3
#define CTU_FIFO3_DATA_BYTES	(4*CTU_FIFO3_THRESHOLD)

#define CTU_FIFO2_THRESHOLD (CTUFIFO2_CH_NUM)
#define CTU_FIFO2_DATA_BYTES	(4*CTU_FIFO2_THRESHOLD)

#define CTU_FIFO1_THRESHOLD 14
#define CTU_FIFO1_DATA_BYTES	(4*CTU_FIFO1_THRESHOLD)

#define CTU_FIFO0_THRESHOLD 12
#define CTU_FIFO0_DATA_BYTES	(4*CTU_FIFO0_THRESHOLD)

#define BITER_CNT ADC_FLT_TIME




#define ADC0_NUMBER_OF_CHANNELS		8
#define ADC0_NUMBER_OF_DATA_BYTES	(4*ADC0_NUMBER_OF_CHANNELS)

#define ADC1_NUMBER_OF_CHANNELS		12
#define ADC1_NUMBER_OF_DATA_BYTES	(4*ADC1_NUMBER_OF_CHANNELS)







#define NTC_90DEG 884
#define NTC_125DEG 336


#define PTC_100DEG 2048
#define PTC_150DEG 2341












#endif