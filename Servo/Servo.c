#include "Servo.h"

void Servo_create(SERVO *servo, SERVO_CONFIG config)
{
   servo->servo_config = config;
}

void Servo_init(SERVO *servo)
{
  Servo_pwminit(servo->servo_config);
  servo->target_angle = 0.0f; // Initialize angle to 0
}

void Servo_setangle(SERVO *servo,float angle)
{
   servo->target_angle = angle;
   int pwm = (int)Servo_Comparevaluecal(servo->servo_config,angle);
   Servo_setcompare(servo->servo_config,pwm);
}
