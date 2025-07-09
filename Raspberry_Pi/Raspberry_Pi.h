#ifndef _RASPBERRY_PI_H
#define _RASPBERRY_PI_H

#include "Raspberry_uart.h"

typedef enum
{
     raspberry_wait_echo,
	 raspberry_complite_echo
}Raspberry_STATE;

typedef struct
{
    volatile int speed;
	volatile double angle;
	volatile Raspberry_STATE state;
}RASPBERRY_TEMP;

typedef struct
{
    volatile int speed;
	volatile double angle;
	volatile Raspberry_STATE state;
}RASPBERRY;

void Raspberry_init(void);

void Raspberry_speeddataIN(int indata);
void Raspberry_getspeed(RASPBERRY *raspberry);
void Raspberry_angledataIN(double angle);
void Raspberry_getangle(RASPBERRY *raspberry);
void Raspberry_stateIN(Raspberry_STATE state);
void Raspberry_getstate(RASPBERRY *raspberry);



#endif
