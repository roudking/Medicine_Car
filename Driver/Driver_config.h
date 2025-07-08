#ifndef _DRIVER_CONFIG
#define _DRIVER_CONFIG

#include "gpio_encoder.h"
#include "ti_msp_dl_config.h"
#include "pwm.h"

typedef struct {

	//电机编码器端口设置
    ENCODER_PORT encoder_port;

	//电机PWM端口设置
	GPTIMER_Regs *pwm_port;
	DL_TIMER_CC_INDEX Channel[2];
  	int DriverPWMTimer_autoreload;

	//电机编码器极性设置  （软件）
	int Encoder_polarity;

	//电机PWM极性设置（软件）
	int Pwm_polarity;

} DRIVER_CONFIG;


extern DRIVER_CONFIG leftdriver;
extern DRIVER_CONFIG rightdriver;



#endif
