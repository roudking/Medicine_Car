#ifndef _TIM_IT_H
#define _TIM_IT_H

#include <ti/driverlib/dl_timerg.h>

void tim_it_start(GPTIMER_Regs *gptimer,IRQn_Type IRQn);


#endif
