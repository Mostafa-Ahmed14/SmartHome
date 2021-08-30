/*
 * USART_interface.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Mostafa
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

#define      RXEN          4
#define      TXEN          3
#define      URSEL         7
#define      UCSZ0         1
#define      UCSZ1         2
#define      RXC           7
#define      UDRE          5

#define MYUBRR FOSC/16/BAUD-1


extern void UART_Init(void);
extern void UART_Send_data(u8 data);
extern u8 UART_Recieve_data(void);
void UART_Transmit_string (u8 * str);

#endif /* MCAL_USART_USART_INTERFACE_H_ */
