#include "serial.h"

// int fputc(int ch, FILE *f) {
// HAL_UART_Transmit(&Debugger_UART, (uint8_t *)&ch, 1, 0xFFFF);
// return ch;
// }

void usart_printf(UART_Regs *uart,char *fmt, ...){
   uint16_t i, j;
   va_list ap;
   char TX_BUF[200];
   va_start(ap, fmt);
   vsprintf((char *)TX_BUF, fmt, ap);
   va_end(ap);
   i = strlen((const char *)TX_BUF); // 此次发送数据的长度
   for (j = 0; j < i; j++)                  // 循环发送数据
   {
      DL_UART_transmitDataBlocking(uart, TX_BUF[j]);
   }
}

void usart_rx_it_start(IRQn_Type IRQn)
{
    NVIC_ClearPendingIRQ(IRQn);
    NVIC_EnableIRQ(IRQn);
}

void usart_rx_it_stop(IRQn_Type IRQn)
{
     NVIC_DisableIRQ(IRQn);
}

void usart_transmit(UART_Regs *uart,unsigned char *p_data, unsigned int uiSize)
{	
    while(*p_data != '\0')  DL_UART_transmitDataBlocking(uart, *p_data++);
}

char usart_receivebyte(UART_Regs *uart)
{
     return DL_UART_Main_receiveData(uart);
}
