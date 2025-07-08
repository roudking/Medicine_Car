#ifndef _SERVO_H
#define _SERVO_H


#include "Servo_pwm.h"

typedef struct
{
   float target_angle;
   SERVO_CONFIG servo_config; // Servo configuration 
   uint16_t limit;
}SERVO;

void Servo_create(SERVO *servo, SERVO_CONFIG config);
void Servo_init(SERVO *servo);
void Servo_setangle(SERVO *servo, float angle);

#endif
