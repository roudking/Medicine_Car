#ifndef _MY_DELAY_H
#define _MY_DELAY_H

#include "ti_msp_dl_config.h"

#define DELAY_TIMER htim6

void delay_us(uint32_t i);
void delay_ms(uint32_t i);

#endif
