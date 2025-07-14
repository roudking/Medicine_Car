#ifndef _K230_H
#define _K230_H

#include "K230_uart.h"
#include "string.h"

typedef struct
{
    int tstatus; //到达T路口
    int nstatus; //到达空白路口
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

//获取T路口状态
void K230_tstatusIN(int Tstatus);
void K230_gettstatus(K230 *k230);

//获取N路口状态
void K230_nstatusIN(int Nstatus);
void K230_getnstatus(K230 *k230);

#endif
