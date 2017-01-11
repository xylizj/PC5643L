/************************************************************************/
/* File Name:      eQADC.c
/* Description:    
/* Comments:       
/*
/* Version     Date           Author           Remark
/* -------  ----------   --------------   ------------------------------      
/*
/************************************************************************/
#include "Adc.h"
#include "isr.h"
   	
extern volatile uint32_t RawVoltagesTable_FIFO3[CTU_FIFO3_THRESHOLD];
extern volatile uint32_t RawVoltagesTable_FIFO2[CTU_FIFO2_THRESHOLD];
extern volatile uint32_t RawVoltagesTable_FIFO2_Array[BITER_CNT][CTU_FIFO2_THRESHOLD];
extern volatile uint32_t RawVoltagesTable_FIFO1[CTU_FIFO1_THRESHOLD];
extern volatile uint32_t RawVoltagesTable_FIFO1_Array[BITER_CNT][CTU_FIFO1_THRESHOLD];
extern volatile uint32_t RawVoltagesTable_FIFO0_Array[BITER_CNT][CTU_FIFO0_THRESHOLD];
extern volatile uint32_t  ADC_CDATARaw[ADC_FLT_TIME][ADC_CH_NUM];
//uint32_t Adc0_result[ADC0_NUMBER_OF_CHANNELS];
//extern uint32_t Adc1_result[ADC1_NUMBER_OF_CHANNELS];



uint16_t SID_m_ct_CurPhaseURaw;
//uint16_t SID_m_ct_CurPhaseVRaw;
uint16_t SID_m_ct_CurPhaseWRaw;

uint16_t SID_m_ct_TempPURaw;
uint16_t SID_m_ct_TempPVRaw;
uint16_t SID_m_ct_TempPWRaw;

uint16_t SID_m_ct_V12Raw;
uint16_t SID_m_ct_T15Raw;
uint16_t SID_m_ct_V5Raw;

uint16_t SID_m_ct_AccRaw;
uint16_t SID_m_ct_VBAT2Raw;
uint16_t SID_m_ct_SHalfRaw;

uint16_t  SID_m_ct_SBreakRaw;
uint16_t  SID_m_ct_SForwardRaw;
uint16_t  SID_m_ct_SReverseRaw;

uint16_t  SID_m_ct_ModeTempRaw;
uint16_t  SID_m_ct_MotorTempRaw;
uint16_t  SID_m_ct_SAccRaw;
uint16_t SID_m_ct_VREFRaw;
uint16_t SID_m_ct_VBATRaw;
uint16_t SID_m_ct_REFRaw;


uint8_t   DISABLE_FLAG = 0;	



_STATIC_ void Adc_TrigSrcInit(void);
_STATIC_ void Adc_ControllerInit(void);
_STATIC_ void Adc_PadConfig(void);

static 
void Adc_Var2Ptr(void);
/*********************************************************************/
/*  function name:  Adc_Init() 
/*  description:    initialize the adc module
/*  parameters:     none
/*  return values:  none
/*  remark:
/*********************************************************************/
void Adc_Init(void)
{	
	Adc_PadConfig();
	Adc_ControllerInit();
	//Adc_Trigger();
	//Adc_TrigSrcInit();
	Adc_Var2Ptr();  		
}


void Adc0_CtuTrigger(void)
{
	ADC_0.MCR.B.CTUEN  = 1;	
}


void Adc1_NormalStart(void)
{
	ADC_1.MCR.B.NSTART = 1;    // Trigger normal conversions for ADC1	
}

/*********************************************************************/
/*  function name:  Adc_Trigger() 
/*  description:    trigger the ad channel
/*  parameters:     none
/*  return values:  none
/*  remark:
/*********************************************************************/
void Adc_Trigger(void)
{
	Adc0_CtuTrigger();
	Adc1_NormalStart();
}


void Adc_F_GetValue(void)
{
	SID_m_ct_CurPhaseURaw = (uint16_t)(RawVoltagesTable_FIFO3[0] & ADC_RESULT_MASK);
	//SID_m_ct_CurPhaseVRaw = (uint16_t)(RawVoltagesTable_FIFO3[1] & ADC_RESULT_MASK);				
	SID_m_ct_CurPhaseWRaw = (uint16_t)(RawVoltagesTable_FIFO3[2] & ADC_RESULT_MASK);	
}
/*********************************************************************/
/*  function name:  Adc_GetValue_10ms() 
/*  description:    
/*  parameters:     none
/*  return values:  none
/*  remark:
/*********************************************************************/
void Adc_GetValue_1ms(void)
{/*
	uint8_t i;
	uint32_t Temp_CDATARaw_Sum;
	
  Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO2_Array[i][0] & ADC_RESULT_MASK;
	}
	SID_m_ct_CurExcRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);*/
}




void SafetyControl(void)
{/*
	if ( (SID_m_ct_V48Raw>3546)||//60V
	     (SID_m_ct_TempPURaw<NTC_125DEG)||//125deg
	     (SID_m_ct_TempPVRaw<NTC_125DEG)||//125deg
	     (SID_m_ct_TempPWRaw<NTC_125DEG)||//125deg
	     (SID_m_ct_TempStatorRaw>PTC_150DEG)  )
	{
		SIU.GPDO[22].R=0;//三相驱动失能

		if 	(DISABLE_FLAG <= 250)
		{
		    DISABLE_FLAG ++;
		}
	}
    else if (DANGER_FLAG == 0)//current exceed limit
    {
    	if ( (SID_m_ct_V48Raw < 3250)&&//55V
        	 (SID_m_ct_TempPURaw>NTC_90DEG)&&//90deg
         	 (SID_m_ct_TempPVRaw>NTC_90DEG)&&//90deg
         	 (SID_m_ct_TempPWRaw>NTC_90DEG)&&//90deg
         	 (SID_m_ct_TempStatorRaw<PTC_100DEG) )
		{
			SIU.GPDO[22].R=1;//三相驱动使能	
		}
     	
    }
*/
}

uint16_t  *SID_m_ct_FIFO1RawVoltagesTable[ADC_FIFO1_TOTAL_CH];
uint16_t  *SID_m_ct_FIFO0RawVoltagesTable[ADC_FIFO0_TOTAL_CH];

static 
void Adc_Var2Ptr(void)
{
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_Half] = &SID_m_ct_SHalfRaw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_T15] = &SID_m_ct_T15Raw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_Forward] = &SID_m_ct_SForwardRaw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_VBAT2] = &SID_m_ct_VBAT2Raw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_Mode_Temp] = &SID_m_ct_ModeTempRaw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_VBAT] = &SID_m_ct_VBATRaw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_Motor_Temp] = &SID_m_ct_MotorTempRaw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_REF] = &SID_m_ct_REFRaw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_S_Break] = &SID_m_ct_SBreakRaw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_S_accelerator] = &SID_m_ct_SAccRaw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_S_Reverse] = &SID_m_ct_SReverseRaw;
	SID_m_ct_FIFO1RawVoltagesTable[ADC_CH_VREF] = &SID_m_ct_VREFRaw;
	
	SID_m_ct_FIFO0RawVoltagesTable[ADC_CH_I_A_accelerator-ADC_FIFO1_TOTAL_CH] = &SID_m_ct_AccRaw;
	SID_m_ct_FIFO0RawVoltagesTable[ADC_CH_12V-ADC_FIFO1_TOTAL_CH] = &SID_m_ct_V12Raw;
	SID_m_ct_FIFO0RawVoltagesTable[ADC_CH_5V-ADC_FIFO1_TOTAL_CH] = &SID_m_ct_V5Raw;	
}

void Adc_GetValue_10ms(void)
{
	uint8_t i;
	uint8_t j;		
	uint32_t Temp_CDATARaw_Sum;
	
  	for (j=0; j<ADC_FIFO1_TOTAL_CH; j++)
  	{
	  	Temp_CDATARaw_Sum = 0;
		for (i=0; i<ADC_FLT_TIME; i++)
		{
		   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][j] & ADC_RESULT_MASK;
		}
		*SID_m_ct_FIFO1RawVoltagesTable[j] = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);		  		
  	}
  	
  	for (j=0; j<ADC_FIFO0_TOTAL_CH; j++)
  	{
	  	Temp_CDATARaw_Sum = 0;
		for (i=0; i<ADC_FLT_TIME; i++)
		{
		   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO0_Array[i][j] & ADC_RESULT_MASK;
		}
		*SID_m_ct_FIFO0RawVoltagesTable[j] = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);		  		
  	}  	  	
}

/*void Adc_GetValue_10ms(void)
{  
	uint8_t i;
	uint32_t Temp_CDATARaw_Sum;
	
  	Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_T15] & ADC_RESULT_MASK;
	}
	SID_m_ct_T15Raw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);

  	Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_I_A_accelerator] & ADC_RESULT_MASK;
	}
	SID_m_ct_AccRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);

    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_VBAT2] & ADC_RESULT_MASK;
	}
	SID_m_ct_VBAT2Raw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);
		
	
   	Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO0_Array[i][ADC_CH_12V-ADC_FIFO1_TOTAL_CH] & ADC_RESULT_MASK;
	}
	SID_m_ct_V12Raw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);	
	
   	Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_Half] & ADC_RESULT_MASK;
	}
	SID_m_ct_SHalfRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);
	
   	Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO0_Array[i][ADC_CH_5V-ADC_FIFO1_TOTAL_CH] & ADC_RESULT_MASK;
	}
	SID_m_ct_V5Raw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);
			
    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_S_Break] & ADC_RESULT_MASK;
	}
	SID_m_ct_SBreakRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);

    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_Forward] & ADC_RESULT_MASK;
	}
	SID_m_ct_SForwardRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);
	
    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_S_Reverse] & ADC_RESULT_MASK;
	}
	SID_m_ct_SReverseRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);
	
    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_Mode_Temp] & ADC_RESULT_MASK;
	}
	SID_m_ct_ModeTempRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);	

    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_Motor_Temp] & ADC_RESULT_MASK;
	}
	SID_m_ct_MotorTempRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);

    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_S_accelerator] & ADC_RESULT_MASK;
	}
	SID_m_ct_SAccRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);
	
    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_VREF] & ADC_RESULT_MASK;
	}
	SID_m_ct_VREFRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);
	
    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_VBAT] & ADC_RESULT_MASK;
	}
	SID_m_ct_VBATRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);
	
    Temp_CDATARaw_Sum = 0;
	for (i = 0;i< ADC_FLT_TIME;i ++)
	{
	   Temp_CDATARaw_Sum +=	RawVoltagesTable_FIFO1_Array[i][ADC_CH_REF] & ADC_RESULT_MASK;
	}
	SID_m_ct_REFRaw = (uint16_t)(Temp_CDATARaw_Sum/ADC_FLT_TIME);			
}*/





/*********************************************************************/
/*  function name:  Adc_TrigSrcInit() 
/*  description:  
/*  parameters:     none
/*  return values:  none
/*  remark:
/*********************************************************************/
_STATIC_ void Adc_TrigSrcInit(void)
{


}





_STATIC_ void Adc_ControllerInit(void)
{
  //ADC Module 0
  //saple 24 clk:400ns@60MHz;evbit 4 clk:800ns@60MHz
  ADC0.CTR0.R   = 0x00009019;  //INPLATCH=1 - OFFSHIFT=01 - INPCMP=00 - INPSMP=25
  //saple 60 clk:1000ns@60MHz;evbit 4 clk:800ns@60MHz
  //ADC0.CTR0.R   = 0x00009040;  //INPLATCH=1 - OFFSHIFT=01 - INPCMP=00 - INPSMP=61
  //saple 240 clk:4us@60MHz;evbit 4 clk:800ns@60MHz
  ADC0.CTR1.R   = 0x000090F1;  //INPLATCH=1 - OFFSHIFT=01 - INPCMP=00 - INPSMP=241  
  ADC0.MCR.R 	= 0x80020000;  //OVRWEN - 1SHOT - SYSCLK/2-CTUEN-ADCRUN


  //ADC Module 1
  //saple 24 clk:400ns@60MHz;evbit 4 clk:800ns@60MHz
  ADC1.CTR0.R   = 0x00009019;  //INPLATCH=1 - OFFSHIFT=01 - INPCMP=00 - INPSMP=25
  //saple 60 clk:1000ns@60MHz;evbit 4 clk:800ns@60MHz
  //ADC1.CTR0.R   = 0x00009040;  //INPLATCH=1 - OFFSHIFT=01 - INPCMP=00 - INPSMP=61
  //saple 243 clk:4.05us@60MHz;evbit 4 clk:800ns@60MHz
  ADC1.CTR1.R   = 0x000090F4;  //INPLATCH=1 - OFFSHIFT=01 - INPCMP=00 - INPSMP=244  
  ADC1.MCR.R    = 0x80020000;  //OVRWEN - 1SHOT - SYSCLK/2-CTUEN-ADCRUN

  //ADC_0.IMR.B.MSKEOC = 1;/* Mask ADC1 interrupts */       
  //ADC_1.IMR.B.MSKEOC = 1;/* Mask ADC1 interrupts */       

  ADC_0.IMR.B.MSKEOCTU = 1;/* Mask ADC1 interrupts */       
  ADC_1.IMR.B.MSKEOCTU = 1;/* Mask ADC1 interrupts */       
}


_STATIC_ void Adc_PadConfig(void)
{	
	/* MPC5643L: Config pad B[10] pin as ADC1 AN[12] input */
  SIU.PCR[26].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[26].B.PA = 2;//01: Alternative Mode 0,ADC_0; 10: Alternative Mode 1,ADC_1

	/* MPC5643L: Config pad B[9] pin as ADC0 AN[11] input */
  SIU.PCR[25].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[25].B.PA = 1;//01: Alternative Mode 0,ADC_0; 10: Alternative Mode 1,ADC_1

  /* MPC5643L: Config pad B[13] pin as ADC1 AN[0] input */
  SIU.PCR[29].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[29].B.PA = 2;
  
  	/* MPC5643L: Config pad B[14] pin as ADC1 AN[1] input */
  SIU.PCR[30].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[30].B.PA = 3;

  	/* MPC5643L: Config pad B[15] pin as ADC1 AN[2] input */
  SIU.PCR[31].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[31].B.PA = 2;

  	/* MPC5643L: Config pad C[0] pin as ADC1 AN[3] input */
  SIU.PCR[32].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[32].B.PA = 1;

 	/* MPC5643L: Config pad C[1] pin as ADC0 AN[2] input */
  SIU.PCR[33].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[33].B.PA = 1;

 	/* MPC5643L: Config pad C[2] pin as ADC0 AN[3] input */
  SIU.PCR[34].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[34].B.PA = 1;
 
 	/* MPC5643L: Config pad E[0] pin as ADC1 AN[5] input */
  SIU.PCR[64].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[64].B.PA = 1;

 	/* MPC5643L: Config pad E[4] pin as ADC0 AN[7] input */
  SIU.PCR[68].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[68].B.PA = 1;

 	/* MPC5643L: Config pad E[5] pin as ADC0 AN[8] input */
  SIU.PCR[69].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[69].B.PA = 1;

 	/* MPC5643L: Config pad E[6] pin as ADC0 AN[4] input */
  SIU.PCR[70].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[70].B.PA = 1;

 	/* MPC5643L: Config pad E[7] pin as ADC0 AN[6] input */
  SIU.PCR[71].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[71].B.PA = 1;

 	/* MPC5643L: Config pad E[9] pin as ADC1 AN[7] input */
  SIU.PCR[73].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[73].B.PA = 1;

	/* MPC5643L: Config pad E[10] pin as ADC1 AN[8] input */
  SIU.PCR[74].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[74].B.PA = 1;

 	/* MPC5643L: Config pad E[11] pin as ADC1 AN[4] input */
  SIU.PCR[75].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[75].B.PA = 1;

 	/* MPC5643L: Config pad E[12] pin as ADC1 AN[6] input */
  SIU.PCR[76].B.APC = 1;//1: Analog input path switch can be enabled by the ADC.0x2XXX
  SIU.PCR[76].B.PA = 1;
}




/***************************************************************/
/*                           End of File
/***************************************************************/

