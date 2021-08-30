/*
 * UART.c
 *
 * Created: 2/23/2019 8:16:02 PM
 *  Author: Mohamed Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

void UART_Init(void)
{
	UBRRL=(u8)(MYUBRR);
	UBRRH=(u8)(MYUBRR>>8);
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);

}

void UART_Send_data(u8 data)
{
	 while (!( UCSRA & (1<<UDRE)));
	 UDR = data;
}

u8 UART_Recieve_data(void)
{
	while(!(UCSRA) & (1<<RXC));
	return UDR;
}

void UART_Transmit_string (u8 * str)
{
	u8 i =0 ;
	 while(str[i]!=0)
	    {UART_Send_data(str[i]) ; i++;}
}
