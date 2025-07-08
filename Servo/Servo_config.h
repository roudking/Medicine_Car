#ifndef SERVO_CONFIG_H
#define SERVO_CONFIG_H

#include "pwm.h"
#include "ti_msp_dl_config.h"

typedef enum
{
  servo_270,
	servo_180
}Servo_Category;

typedef struct
{
   GPTIMER_Regs *pwm_port;
   DL_TIMER_CC_INDEX  CHANNEL;
  float CounterCycleTime; //us

  Servo_Category kind;
  
  float delta_bias; //us, the bias of the servo angle
}SERVO_CONFIG;

extern SERVO_CONFIG servo_config;

 

#endif // SERVO_CONFIG_H