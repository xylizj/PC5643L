#ifndef __PWM_H_
#define __PWM_H_

#define FLEXPWM0_SUB012_FREQ 20//KHz
#define FLEXPWM0_SUB012_HALF ((120000/FLEXPWM0_SUB012_FREQ)/2)


#define FLEXPWM0_1US 120
#define FLEXPWM0_DTCNT (FLEXPWM0_1US)

#define PWM0_SUB012_INIT_DUTY 50

#if (PWM0_SUB012_INIT_DUTY != 50)
#error "sub 0 1 2 init duty not correct!"
#endif


#define FLEXPWM0_SUB3_A_FREQ 2//KHz

#if (PWM0_SUB012_INIT_DUTY == 1)
#error "sub 3 clk should be divided!"
#endif

#define PWM0_SUB3_A_PERIOD ((120000)/FLEXPWM0_SUB3_A_FREQ)

#if (PWM0_SUB3_A_PERIOD > 65535)
#error "sub 3 clk should be divided!"
#endif



extern void PWM_PadConfig(void);
extern void ConfigureFlexPWM0(void);
extern void ConfigureFlexPWM0Sub(uint8_t sub_no, uint8_t duty_ratio);
extern void SetFlexPWM0SubXDuty(uint8_t sub_no, uint8_t duty_ratio);
extern void FlexPWM0Sub0ReloadIntEn(void);

extern void FlexPWM0SubOutTrig(uint8_t sub_no);
extern void LaunchFlexPWM0_modules012(void);

extern void FlexPWM0Sub3(uint8_t duty_ratio);
extern void SetFlexPWM0Sub3Duty(uint8_t duty_ratio);
extern void SetFlexPWM0Sub3Val2(int16_t delta);
extern void SetFlexPWM0Sub3_val2(uint16_t val2);

extern void SetFlexPWM0SubXval3(uint8_t sub_no, uint16_t val3);
extern void FlexPWM0Sub012_ReadSts(void);


extern void ConfigureFlexPWM0Sub0(void);
extern void ConfigureFlexPWM0Sub1(void);
extern void ConfigureFlexPWM0Sub2(void);









#endif
