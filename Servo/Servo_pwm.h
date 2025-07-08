#ifndef _SERVO_PWM
#define _SERVO_PWM

#include "Servo_config.h"

void Servo_pwminit(SERVO_CONFIG servo_config);

void Servo_setcompare(SERVO_CONFIG servo_config, uint16_t pwm);

float  Servo_Comparevaluecal(SERVO_CONFIG servo_config, float angle);


#endif 
