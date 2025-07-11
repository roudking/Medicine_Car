#ifndef _RASPBERRY_PI_H
#define _RASPBERRY_PI_H

#include "Raspberry_uart.h"
#include "string.h"

typedef enum
{
     raspberry_wait_echo,
	 raspberry_complite_echo
}Raspberry_STATE;

typedef struct
{
    volatile int leftspeed;
    volatile int rightspeed;
	volatile char led_color;
    volatile float angle;
	volatile Raspberry_STATE state;
}RASPBERRY_TEMP;

typedef struct
{
    volatile int leftspeed;
    volatile int rightspeed;
	volatile char led_color;
    volatile float angle;
	volatile Raspberry_STATE state;
}RASPBERRY;

void Raspberry_init(void);

void Raspberry_leftspeeddataIN(int indata);
void Raspberry_rightspeeddataIN(int indata);
void Raspberry_getleftspeed(RASPBERRY *raspberry);
void Raspberry_getrightspeed(RASPBERRY *raspberry);
void Raspberry_angledataIN(float angle);
void Raspberry_getangle(RASPBERRY *raspberry);
void Raspberr_colorIN(char color);
void Raspberry_getcolor(RASPBERRY *raspberry);
void Raspberry_stateIN(Raspberry_STATE state);
void Raspberry_getstate(RASPBERRY *raspberry);


#endif
