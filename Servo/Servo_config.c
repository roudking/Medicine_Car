#include "Servo_config.h"

#define Servo_TIM_CounterCycleTime    1000000.0/Servo_INST_CLK_FREQ    //us
#define Servo_kind servo_180
#define bias 0.0f

SERVO_CONFIG servo_config = {
    .pwm_port = Servo_INST,
    .CHANNEL = GPIO_Servo_C0_IDX,
    .CounterCycleTime = Servo_TIM_CounterCycleTime,
    .kind = Servo_kind,
    .delta_bias = bias
};