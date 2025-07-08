#ifndef GPIO_ENCODER_H
#define GPIO_ENCODER_H

#include <ti/driverlib/dl_gpio.h>

typedef struct
{
//中断线
    IRQn_Type IRQn;

//GPIO端口
    GPIO_Regs *gpio_port;

//编码器引脚
    uint32_t EncoderA_PIN;
    uint32_t EncoderB_PIN;
    uint32_t EncoderC_PIN;
    uint32_t EncoderD_PIN;

//编码器计数器
    int32_t encoder_counter;

//编码器ID
    int encoder_id;

}ENCODER_PORT;

void encoder_init(int encoder_id, ENCODER_PORT encoder_port);
void encoder_start(int encoder_id);
int32_t encoder_getcounter(int encoder_id);

#endif 
