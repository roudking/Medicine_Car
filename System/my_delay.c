#include "my_delay.h"

//实现微秒级延时
void delay_us(uint32_t us)
{
    while(us--)
        delay_cycles(CPUCLK_FREQ/1000000);
}

//实现毫秒级延时
void delay_ms(uint32_t ms)
{
    while(ms--)
	    delay_cycles(CPUCLK_FREQ/1000);
}
