#ifndef __ISR_H_
#define __ISR_H_


//(1900*3300/4096)/(0.2*27.5)=278.3A
#define CUR_PHASE_RAW_DELTA_THROLD 1900



extern void eTimer_0_TC5IR_Isr(void);


extern  uint8_t  DANGER_FLAG;
extern  int32_t angle_c;







#endif
