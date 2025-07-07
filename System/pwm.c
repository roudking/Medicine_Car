#include "pwm.h"

void pwm_init(GPTIMER_Regs *gptimer)
{
    DL_Timer_startCounter (gptimer);
}

// DL_TIMER_CC_INDEX: D  L_TIMER_CC_0_INDEX
void pwm_set(GPTIMER_Regs * tim, DL_TIMER_CC_INDEX TIM_CHANNEL, uint32_t pwm)
{
    DL_Timer_setCaptureCompareValue(tim, pwm, TIM_CHANNEL);
}

