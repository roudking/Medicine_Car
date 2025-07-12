#ifndef _RASPBERRY_PI_H
#define _RASPBERRY_PI_H

#include "Raspberry_uart.h"
#include "string.h"


typedef struct{
    int key_status;
    int reset_status;
}RASPBERRY_STATUS;

typedef struct
{
    volatile float leftspeed;
    volatile float rightspeed;
	volatile char led_color;
    volatile float angle;
	volatile RASPBERRY_STATUS status;
}RASPBERRY;

void Raspberry_init(void);

void Raspberry_leftspeeddataIN(float leftspeed);
void Raspberry_rightspeeddataIN(float rightspeed);
void Raspberry_getleftspeed(RASPBERRY *raspberry);
void Raspberry_getrightspeed(RASPBERRY *raspberry);

void Raspberry_angledataIN(float angle);
void Raspberry_getangle(RASPBERRY *raspberry);

void Raspberr_colorIN(char color);
void Raspberry_getcolor(RASPBERRY *raspberry);

void Raspberry_keystatusIN(int status);
void Raspberry_getkeystatus(RASPBERRY *raspberry);

void Raspberry_resetstatusIN(int status);
void Raspberry_getresetstatus(RASPBERRY *raspberry);


#endif
