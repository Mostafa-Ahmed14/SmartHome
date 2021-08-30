/*
 * USART_private.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Mostafa
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_


#define     UBRRL       *((volatile u8*) 0x29)
#define     UBRRH       *((volatile u8*) 0x40)

#define     UDR         *((volatile u8*) 0x2C)
#define     UCSRA       *((volatile u8*) 0x2B)
#define     UCSRB       *((volatile u8*) 0x2A)
#define     UCSRC       *((volatile u8*) 0x40) /* UCSRC_REG OR UBRRH_REG */



#endif /* MCAL_USART_USART_PRIVATE_H_ */
