#ifndef _K230_H
#define _K230_H

#include "K230_uart.h"
#include "string.h"

typedef struct
{
   
}K230_STATUS;


typedef struct
{
    volatile float pos;
	volatile K230_STATUS status;
}K230;

void K230_init(void);


//获取位置信息
void K230_posdataIN(float pos);
void K230_getposdata(K230 *k230);


#endif
