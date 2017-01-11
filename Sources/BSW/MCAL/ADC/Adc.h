
#ifndef _ADC_H_
#define _ADC_H_

#include "Adc_Cfg.h"
#include "Siu.h"
#include "Rte_Type.h"



extern volatile uint32_t RawVoltagesTable_FIFO3[CTU_FIFO3_THRESHOLD];
extern volatile uint32_t RawVoltagesTable_FIFO2_Array[BITER_CNT][CTU_FIFO2_THRESHOLD];
extern volatile uint32_t RawVoltagesTable_FIFO1_Array[BITER_CNT][CTU_FIFO1_THRESHOLD];
extern volatile uint32_t RawVoltagesTable_FIFO0_Array[BITER_CNT][CTU_FIFO0_THRESHOLD];


extern uint16_t SID_m_ct_CurPhaseURaw;
extern uint16_t SID_m_ct_CurPhaseWRaw;
extern uint16_t SID_m_ct_TempPURaw;
extern uint16_t SID_m_ct_TempPVRaw;
extern uint16_t SID_m_ct_TempPWRaw; 
extern uint16_t SID_m_ct_V12Raw;
extern uint16_t SID_m_ct_T15Raw;
extern uint16_t SID_m_ct_V5Raw;
extern uint16_t SID_m_ct_AccRaw;
extern uint16_t SID_m_ct_VBAT2Raw;
extern uint16_t SID_m_ct_SHalfRaw;
extern uint16_t  SID_m_ct_SBreakRaw;
extern uint16_t  SID_m_ct_SForwardRaw;
extern uint16_t  SID_m_ct_SReverseRaw;
extern uint16_t  SID_m_ct_ModeTempRaw;
extern uint16_t  SID_m_ct_MotorTempRaw;
extern uint16_t  SID_m_ct_SAccRaw;
extern uint16_t SID_m_ct_VREFRaw;
extern uint16_t SID_m_ct_VBATRaw;
extern uint16_t SID_m_ct_REFRaw;
 

extern void Adc_Init(void);
extern void Adc0_CtuTrigger(void);
extern void Adc1_NormalStart(void);
extern void Adc_Trigger(void);

extern void Adc_F_GetValue(void);
extern void Adc_GetValue_1ms(void);
extern void Adc_GetValue_10ms(void);
extern void SafetyControl(void);






































#endif

/***************************************************************/
/*                           End of File
/***************************************************************/

