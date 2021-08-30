/*
 * mian.c
 *
 *  Created on: Aug 24, 2021
 *      Author: Mostafa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include <util/delay.h>


#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/SPI_MASTER/SPI_MASTER_interface.h"
#include "../MCAL/USART/USART_interface.h"

#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/BLUETOOTH/BLUETOOTH_interface.h"

int main(void)
{
	u8 rx = 0;
	//u8 tx = 0;
	u8 LOC_u8REC  ;
	LED_Type A1={PORTA , PIN1 , LED_ACTIVE_HIGH};
	CLCD_voidInit();
	BLUETOOTH_voidInit('A');
	SPI_voidMasterInit();
	SPI_voidMasterStart();
	_delay_ms(1000);
	while(1)
	{
		/*UART PROTOCOL SEND A TO BLUETOOTH*/

		LOC_u8REC = UART_Recieve_data();
		CLCD_voidSetPosition( CLCD_Row1 , CLCD_Col1 );
		CLCD_voidWriteString("UART SEND A");
		CLCD_voidSetPosition( CLCD_Row2 , CLCD_Col1 );
		CLCD_voidWriteData(LOC_u8REC);


		/*SPI TOGGLE LED*/
		CLCD_voidSetPosition( CLCD_Row1 , CLCD_Col1 );
		rx = SPI_u8MasterTransmit(1);
		if(rx == 2)
		{
			LED_voidToggle(A1);
			UART_Recieve_data();

			rx = 0;
		}
		_delay_ms(1000);

	}
}
