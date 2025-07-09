#include "hwt101_uart.h"

void Uart2Send(unsigned char *p_data, unsigned int uiSize)
{	
   usart_transmit(HWT101_UART,p_data,uiSize);
}

void HWT101_UARTStart(void)
{
   usart_rx_it_start(HWT_UART_INST_INT_IRQN);
}

void HWT_UART_INST_IRQHandler(void)
{
    unsigned char ucTemp = usart_receivebyte(HWT101_UART);
	WitSerialDataIn(ucTemp);
}
