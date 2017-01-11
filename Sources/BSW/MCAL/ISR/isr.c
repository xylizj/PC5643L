#include "MPC5643L.h"
#include "isr.h"
#include "Gpt.h"//"stm.h"
#include "foc.h"
#include "AD2S1210.h"
#include "Adc.h"
#include "SchM.h"
#include "FlexPWM.h"


#define PHASE_CUR_RAW_DELTA_MAX 10
#define POS_RAW_DELTA_MAX 10

volatile uint16_t PhaseCurRawULast;
volatile uint16_t PhaseCurRawVLast;
volatile uint16_t PhaseCurRawWLast;

volatile uint16_t PhaseCurRawLast[3];
volatile uint16_t PhaseCurRawCurrent[3];

uint32_t   PosLast;

uint32_t angle_a;



#ifdef MOTOR0
uint32_t angle_pos_zero = 24320;//20336;//19627;//motor 0
#define SID_m_ct_CurPhaseU_Ref 2071	
#define SID_m_ct_CurPhaseV_Ref 2047
#define SID_m_ct_CurPhaseW_Ref 2060
#endif

#ifdef MOTOR1
uint32_t angle_pos_zero = 11306;//motor 1,new
#define SID_m_ct_CurPhaseU_Ref 2020
#define SID_m_ct_CurPhaseV_Ref 2045
#define SID_m_ct_CurPhaseW_Ref 2074
#endif

uint32_t angle_b;
int32_t angle_c;


static uint8_t phase_not_first_time = 1;
static uint8_t pos_not_first_time = 1;


uint8_t  DANGER_FLAG = 0;
SInt32 SID_m_i_CurPhase_sum;

static inline
void AcquirePhaseCur(void)
{
	SID_m_ct_CurPhaseURaw = (uint16_t)(RawVoltagesTable_FIFO3[0] & ADC_RESULT_MASK);
	//SID_m_ct_CurPhaseVRaw = (uint16_t)(RawVoltagesTable_FIFO3[1] & ADC_RESULT_MASK);
	SID_m_ct_CurPhaseWRaw = (uint16_t)(RawVoltagesTable_FIFO3[1] & ADC_RESULT_MASK);
	
		
	//*********************//
	//disable Phase Drv in case of current exceed limit 
	if(SID_m_ct_CurPhaseURaw>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseU_Ref)
	   || SID_m_ct_CurPhaseU_Ref>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseURaw))
	{
		SIU.GPDO[22].R=0;//三相驱动失能
		DANGER_FLAG = 1;	
	}
	/*if(SID_m_ct_CurPhaseVRaw>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseV_Ref)
	   || SID_m_ct_CurPhaseV_Ref>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseVRaw))
	{
		SIU.GPDO[22].R=0;//三相驱动失能	
		DANGER_FLAG = 1;
	}*/
	if(SID_m_ct_CurPhaseWRaw>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseW_Ref)
	   || SID_m_ct_CurPhaseW_Ref>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseWRaw))
	{
		SIU.GPDO[22].R=0;//三相驱动失能	
		DANGER_FLAG = 1;
	}
	//*********************//
	/*		
	{//Phase current normalization BEGIN!!
	    SID_m_i_CurPhaseU = (SInt32)(((SInt16)(SID_m_ct_CurPhaseURaw-SID_m_ct_CurPhaseU_Ref))<<20);//*1048576
	    //SID_m_i_CurPhaseV = (SInt32)(((SInt16)(SID_m_ct_CurPhaseVRaw-SID_m_ct_CurPhaseV_Ref))<<20);
      	SID_m_i_CurPhaseW = (SInt32)(((SInt16)(SID_m_ct_CurPhaseWRaw-SID_m_ct_CurPhaseW_Ref))<<20);
	}//Phase current normalization END!!
	SID_m_i_CurPhase_sum = SID_m_i_CurPhaseU+SID_m_i_CurPhaseV+SID_m_i_CurPhaseW;*/	
}


static inline
void UpdatePWM_MDRV(void)
{//Update PWM VALx BEGIN!!
    stc_hMDRV_pwmAbc.s16sub0   &= 0xFFFE;
	stc_hMDRV_pwmAbc.s16sub1   &= 0xFFFE;
	stc_hMDRV_pwmAbc.s16sub2   &= 0xFFFE;

	FLEXPWM_0.MCTRL.B.CLOK |= 1;
	FLEXPWM_0.SUB[0].VAL[2].R = (int16_t)-(stc_hMDRV_pwmAbc.s16sub0);
	FLEXPWM_0.SUB[0].VAL[3].R = (int16_t)(stc_hMDRV_pwmAbc.s16sub0);					
	FLEXPWM_0.SUB[1].VAL[2].R = (int16_t)-(stc_hMDRV_pwmAbc.s16sub1);
	FLEXPWM_0.SUB[1].VAL[3].R = (int16_t)(stc_hMDRV_pwmAbc.s16sub1);					
	FLEXPWM_0.SUB[2].VAL[2].R = (int16_t)-(stc_hMDRV_pwmAbc.s16sub2);
	FLEXPWM_0.SUB[2].VAL[3].R = (int16_t)(stc_hMDRV_pwmAbc.s16sub2);
	FLEXPWM_0.MCTRL.B.LDOK |= 0b1;
}//Update PWM VALx END!!


void eTimer_1_TC5IR_Isr(void) 
{
	ETIMER_1.CHANNEL[5].STS.B.TCF=1; 

	//GetMotorVel();
	//delay_us(2);
	//ReadMotorVel();	
	
	SID_m_ct_CurPhaseURaw = (uint16_t)(RawVoltagesTable_FIFO3[0] & ADC_RESULT_MASK);
	SID_m_ct_CurPhaseWRaw = (uint16_t)(RawVoltagesTable_FIFO3[1] & ADC_RESULT_MASK);
	//AcquirePhaseCur();
	
	//Enc_SpdMeas();//20161128 xyl add
	
	//focFastLoop();	
	//UpdatePWM_MDRV();
}
