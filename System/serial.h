#ifndef _SERIAL_H
#define _SERIAL_H

#include <ti/driverlib/dl_uart_main.h>
#include "string.h"
#include "stdarg.h"
#include "stdio.h"
#include "stdint.h"


// 在某个公共头文件里（或 Debugger_printf 前面）加上：
#define Debugger_UART Debugger_UART_INST
#define Debugger_printf(fmt, ...)  usart_printf(Debugger_UART, fmt, ##__VA_ARGS__)

void usart_printf(UART_Regs *uart,char *fmt, ...);
void usart_rx_it_start(IRQn_Type IRQn);
void usart_rx_it_stop(IRQn_Type IRQn);
void usart_transmit(UART_Regs *uart,unsigned char *p_data, unsigned int uiSize);
char usart_receivebyte(UART_Regs *uart);

#endif
