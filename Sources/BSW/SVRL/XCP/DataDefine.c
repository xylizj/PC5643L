#include "Platform_Types.h"
#include "Ioa.h"



#pragma push

//__declspec(section ".data")
#pragma section RW ".internal_ram"
 

boolean phase_drive_enable;
boolean phase_drive_disable;
boolean phase_drive_fault_reset;

uint8_t pwm0_sub0_a_duty_set_en;
uint8_t pwm0_sub1_a_duty_set_en;
uint8_t pwm0_sub2_a_duty_set_en;
uint8_t pwm0_sub3_a_duty_set_en;

uint8_t pwm0_sub0_a_duty;
uint8_t pwm0_sub1_a_duty;
uint8_t pwm0_sub2_a_duty;
uint8_t pwm0_sub3_a_duty;
int16_t pwm0_sub3_VAL2;








#pragma pop