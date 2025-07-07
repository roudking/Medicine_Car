#include "my_delay.h"

void delay_us(uint32_t i)
{
   
}

void delay_ms(uint32_t nms)
{
    for (uint32_t i = 0; i < nms; i++) {
        delay_us(1000);  // ��ʱ 1 ms
    }
}
