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
    k210_temp.num[2] = num[2];
    k210_temp.num[3] = num[3];
    k210_temp.num[4] = num[4];
    k210_temp.num[5] = num[5];
}

void K210_getnumdata(K210 *k210)
{
    k210->num[0] = k210_temp.num[0];
    k210->num[1] = k210_temp.num[1];
    k210->num[2] = k210_temp.num[2];
    k210->num[3] = k210_temp.num[3];
    k210->num[4] = k210_temp.num[4];
    k210->num[5] = k210_temp.num[5];
}