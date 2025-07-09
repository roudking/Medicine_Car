#ifndef _MY_HWT101
#define _MY_HWT101

#include "string.h"
#include "stdio.h"
#include "wit_c_sdk.h"
#include "hwt101_uart.h"
#include "my_delay.h"

#define yaw_id 2


typedef struct
{
  	float fAcc[3];
   	float fGyro[3];
	  float fAngle[3];
	
}HWT101_DATA;

void Myhwt101_init(void);
void Myhwt101_getdata(HWT101_DATA *hwt_data);
void Myhwt101_resetz(void);


#endif
