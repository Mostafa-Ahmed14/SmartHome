/*
 * SPI_program.c
 *
 *  Created on: Aug 24, 2021
 *      Author: Mostafa
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"
#include "../SPI/SPI_config.h"
#include "../SPI/SPI_interface.h"
#include "../SPI/SPI_private.h"


void SPI_voidMasterInit(void)

{

	DIO_voidSetPinDirection( PORTB , PIN6 , OUTPUT );    //MOSI
	DIO_voidSetPinDirection( PORTB , PIN7 , INPUT );	 //MISO
	DIO_voidSetPinDirection( PORTB , PIN5 , OUTPUT );	 //SS
	DIO_voidSetPinDirection( PORTB , PIN8 , OUTPUT );	 //SCK

	SPCR_REG = 0x53;
	DIO_voidSetPinValue( PORTB , PIN5 , HIGH );

}

void SPI_voidSlaveInit(void)
{

	DIO_voidSetPinDirection( PORTB , PIN6 , INPUT );    //MOSI
	DIO_voidSetPinDirection( PORTB , PIN7 , OUTPUT );	 //MISO
	DIO_voidSetPinDirection( PORTB , PIN5 , INPUT );	 //SS
	DIO_voidSetPinDirection( PORTB , PIN8 , INPUT );	 //SCK

	SPCR_REG = 0x40;

}
void SPI_voidMasterStart(void)
{
	DIO_voidSetPinValue( PORTB , PIN5 , LOW );
}
void SPI_voidMasterStop(void)
{
	DIO_voidSetPinValue( PORTB , PIN5 , HIGH );
}

u8 SPI_u8MasterTransmit(u8 Data)
{
	u8 REC_Data = 0;
	SPDR_REG = Data;
	while(GET_BIT( SPSR_REG , 7)==0);
	REC_Data = SPDR_REG;
	return REC_Data;
}

