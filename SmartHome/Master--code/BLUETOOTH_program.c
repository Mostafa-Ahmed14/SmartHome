/*
 * BLUETOOTH_program.c
 *
 *  Created on: Aug 29, 2021
 *      Author: Mostafa
 */


#include  "../../LIB/STD_TYPES.h"
#include  "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/USART/USART_interface.h"

#include "BLUETOOTH_interface.h"

void BLUETOOTH_voidInit (u8 Copy_u8Data)
{
	UART_Init();
	UART_Send_data(Copy_u8Data);

}

extern void BLUETOOTH_voidsend (u8 text)
{

		UART_Transmit_string(text);
}
