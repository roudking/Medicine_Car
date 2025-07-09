#include "Driver_config.h"


DRIVER_CONFIG leftdriver = {

	.encoder_port = {
            //中断线	
            	.IRQn = GPIO_MULTIPLE_GPIOA_INT_IRQN,
            // GPIO端口
            	.gpio_port = Encoder_Left_PORT,
            	.EncoderA_PIN = Encoder_Left_Left_A_PIN,
            	.EncoderB_PIN = Encoder_Left_Left_B_PIN,
            	.EncoderC_PIN = Encoder_Left_Left_C_PIN,
            	.EncoderD_PIN = Encoder_Left_Left_D_PIN,
            // 编码器计数器
            	.encoder_counter = 0,
            // 编码器ID
            	.encoder_id = 0
        },

	.pwm_port = Driver_Left_INST,
	.DriverPWMTimer_autoreload = 7200,
	.Channel[0] = GPIO_Driver_Left_C0_IDX,
	.Channel[1] = GPIO_Driver_Left_C1_IDX,
	
	.Encoder_polarity = 0,

	.Pwm_polarity = 0

};

DRIVER_CONFIG rightdriver = {
            	.encoder_port = {
              //中断线
            	.IRQn = GPIO_MULTIPLE_GPIOA_INT_IRQN,
              // GPIO端口	
            	.gpio_port = Encoder_Right_PORT,
            	.EncoderA_PIN = Encoder_Right_Right_A_PIN,
            	.EncoderB_PIN = Encoder_Right_Right_B_PIN,
            	.EncoderC_PIN = Encoder_Right_Right_C_PIN,
            	.EncoderD_PIN = Encoder_Right_Right_D_PIN,
              // 编码器计数器	
                .encoder_counter = 0,
              // 编码器ID
            	.encoder_id = 1
          },
        
	.pwm_port = Driver_Right_INST,
	.DriverPWMTimer_autoreload = 7200,
	.Channel[0] = GPIO_Driver_Right_C0_IDX,
	.Channel[1] = GPIO_Driver_Right_C1_IDX,

	.Encoder_polarity = 1,

	.Pwm_polarity = 1
};