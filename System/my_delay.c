#include "my_delay.h"

//实现微秒级延时
void delay_us(uint32_t i)
{
   delay_cycles((i/1000000)*CPUCLK_FREQ);
}

//实现毫秒级延时
void delay_ms(uint32_t nms)
{
    for (uint32_t i = 0; i < nms; i++) {
        delay_us(1000);  // ��ʱ 1 ms
    }
}
