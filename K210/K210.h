#ifndef _K210_H
#define _K210_H

#include "string.h"

typedef struct
{
   int numstatus;
}K210_STATUS;

typedef struct
{
    volatile int num[2];
	volatile K210_STATUS status;
}K210;

void K210_getnumstatus(K210 *k210);
void K210_numstatusIN(int status);
void K210_numdataIN(int *num);
void K210_getnumdata(K210 *k210);


#endif
