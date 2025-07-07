#include "tim_it.h"

//使能中断
void tim_it_start(GPTIMER_Regs *gptimer,IRQn_Type IRQn)
{
    NVIC_EnableIRQ(IRQn);

    DL_TimerG_startCounter(gptimer);
}


