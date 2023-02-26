/*
 * USART_drive.c
 *
 * Created: 11/29/2022 10:30:32 PM
 *  Author: osama
 */ 
#include <avr/io.h>
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "MACROS.h"


void USART_init(unsigned long baud)
{
	unsigned short UBRR;
	UBRR = (F_CPU/(16*baud))-1;
	UBRRH =(unsigned char)(UBRR>>8);
	UBRRL =(unsigned char)UBRR;
	
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);
	
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void UART_send_data(char data)
{
	while (READ_BIT(UCSRA, UDRE) == 0);
	UDR = data;
}

char UART_receive_data(void)
{
	while (READ_BIT(UCSRA, RXC) == 0);
	return UDR;
}

void UART_send_string(char* ptr)
{
	while (*ptr!=0)
	{
		UART_send_data(*ptr);
		ptr++;
		_delay_ms(100);
	}
}