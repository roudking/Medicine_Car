#include "K230.h"

// K230缓存区
static K230 k230_temp;


void K230_posdataIN(float pos)
{
   k230_temp.pos = pos;
}

void K230_getposdata(K230 *k230)
{
    k230->pos = k230_temp.pos;
}

void K230_tstatusIN(int Tstatus)
{
    k230_temp.status.tstatus = Tstatus;
}

void K230_gettstatus(K230 *k230)
{
    k230->status.tstatus = k230_temp.status.tstatus;
}

void K230_nstatusIN(int Nstatus)
{
    k230_temp.status.nstatus = Nstatus;
}

void K230_getnstatus(K230 *k230)
{
    k230->status.nstatus = k230_temp.status.nstatus;
}