#ifndef _K210_UART_H 
#define _K210_UART_H

#include "serial.h"
#include "cJSON.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "K210.h"
#include "ti_msp_dl_config.h"

#define K210_UART  Debugger_UART_INST
#define K210_printf(fmt, ...)  usart_printf(K210_UART, fmt, ##__VA_ARGS__)

void K210_uartinit(void);


#endif
