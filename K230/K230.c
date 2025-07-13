#include "K230.h"

//树莓派缓存区
static K230 k230_temp;

void K230_init(void)
{
   K230_uartinit();
}


void K230_posdataIN(float pos)
{
   k230_temp.pos = pos;
}

void K230_getposdata(K230 *k230)
{
    k230->pos = k230_temp.pos;
}