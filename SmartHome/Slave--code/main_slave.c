/*
 * mian.c
 *
 *  Created on: Aug 24, 2021
 *      Author: Mostafa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include <util/delay.h>

#include "../MACL/DIO/DIO_interface.h"
#include "../MACL/SPI/SPI_interface.h"

#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"

int main(void)
{
	u8 rx = 0;
	CLCD_voidInit();
	LED_Type A1={PORTA , PIN1 , LED_ACTIVE_HIGH};
	SPI_voidSlaveInit();

	while(1)
	{
		CLCD_voidSetPosition ( CLCD_Row1 , CLCD_Col1 );
		CLCD_voidWriteString("Mostafa");
		CLCD_voidSetPosition ( CLCD_Row2 , CLCD_Col1 );
		CLCD_voidWriteString("AMIT");

		rx = SPI_u8MasterTransmit(2);
		if(rx == 1)
		{

			LED_voidToggle(A1);

			rx = 0;
		}
		_delay_ms(1000);

	}
}
