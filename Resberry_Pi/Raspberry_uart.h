#ifndef _RASPBERRY_UART_H 
#define _RASPBERRY_UART_H

#include "serial.h"
#include "cJSON.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "Raspberry_Pi.h"
#include "ti_msp_dl_config.h"

#define Raspberry_UART  Debugger_UART_INST
#define Raspberry_printf(fmt, ...)  usart_printf(Raspberry_UART, fmt, ##__VA_ARGS__)

void Raspberry_uartinit(void);


#endif
