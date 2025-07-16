#include "K210.h"

//树莓派缓存区
static K210 k210_temp;

void K210_numstatusIN(int status)
{
    k210_temp.status.numstatus = status;
}

void K210_getnumstatus(K210 *k210)
{
    k210->status.numstatus = k210_temp.status.numstatus;
}

void K210_numdataIN(int *num)
{
    k210_temp.num[0] = num[0];
    k210_temp.num[1] = num[1];
}

void K210_getnumdata(K210 *k210)
{
    k210->num[0] = k210_temp.num[0];
    k210->num[1] = k210_temp.num[1];
    k210_temp.num[0] = 0; // 清空缓存
    k210_temp.num[1] = 0; // 清空缓存
}