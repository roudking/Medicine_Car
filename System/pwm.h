#ifndef _PWM_H
#define _PWM_H

#include <ti/driverlib/dl_timerg.h>

void pwm_init(GPTIMER_Regs *gptimer);
void pwm_set(GPTIMER_Regs * tim, DL_TIMER_CC_INDEX TIM_CHANNEL, uint32_t pwm);


#endif
