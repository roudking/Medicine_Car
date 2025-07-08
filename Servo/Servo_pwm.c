#include "Servo_pwm.h"

void Servo_pwminit(SERVO_CONFIG servo_config)
{
  pwm_init(servo_config.pwm_port);
}

float  Servo_Comparevaluecal(SERVO_CONFIG servo_config, float angle)
{
	 float range;
    if(servo_config.kind == servo_270)
		{
		  range = 270.0;
		}
		else if(servo_config.kind == servo_180)
		{
		  range = 180.0;
		}
	
	float k = 2000.0/range;
	float high_leveltime = k * (angle - servo_config.delta_bias) + 500.0;
	float comparevalue = high_leveltime/servo_config.CounterCycleTime;
	return comparevalue;
}


void Servo_setcompare(SERVO_CONFIG servo_config, uint16_t pwm)
{
  pwm_set(servo_config.pwm_port, servo_config.CHANNEL, pwm);
}


