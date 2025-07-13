#ifndef _K230_UART_H 
#define _K230_UART_H

#include "serial.h"
#include "cJSON.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "K230.h"
#include "ti_msp_dl_config.h"

#define K230_UART  K230_UART_INST
#define K230_printf(fmt, ...)  usart_printf(K230_UART, fmt, ##__VA_ARGS__)

void K230_uartinit(void);


#endif
