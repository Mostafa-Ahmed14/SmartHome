/*
 * CLCD_program.c
 *
 *  Created on: Jun 11, 2021
 *      Author: AMIT
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.H"

#include <util/delay.h>
#include "../../MACL/DIO/DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"

void CLCD_voidInit(void){

	DIO_voidSetPortDirection ( CLCD_DATA_PORT , 255 );
	DIO_voidSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS_PIN , OUTPUT );
	DIO_voidSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW_PIN , OUTPUT );
	DIO_voidSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN_PIN , OUTPUT );

	_delay_ms(50);

	/* Function set Commend */
	CLCD_voidWriteCommend( 0b00111100 );

	_delay_ms(1);

	/* Display ON/OFF commend */

	CLCD_voidWriteCommend( 0b00001100 );

	_delay_ms(1);

	/* Display Clear commend */
	CLCD_voidWriteCommend( 0b00000001 );

	_delay_ms(2);

	/* End Of Initialization */
}

void CLCD_voidSetPosition  ( u8  Row , u8 Col ) {
	if (Row == CLCD_Row1){
		CLCD_voidWriteCommend( 0X80 + Col );
	}
	else if (Row == CLCD_Row2){
		CLCD_voidWriteCommend( 0x80 + 64 + Col);
	}
}


void CLCD_voidWriteString  ( u8 * Copy_u8ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[ LOC_u8Iterator ] != '\0' ){

		CLCD_voidWriteData( Copy_u8ptrString[ LOC_u8Iterator ] );
		LOC_u8Iterator++;

	}

}


void CLCD_voidWriteExtraChar( u8 * ptr , u8 Len , u8 Row , u8 Col ){
	s8 i = 0;
	CLCD_voidWriteCommend(0x40);
	for( i=0 ; i < Len ; i++ ){
		CLCD_voidWriteData( ptr[i] );
	}
	CLCD_voidSetPosition( Row , Col );
	for( i = (Len/8)-1 ; i >= 0 ; i-- ){
		CLCD_voidWriteData(i);
	}
}


void CLCD_voidSendNumber   ( u64 Copy_u64Num   ){
	u64 Reversed = 1;
	if (Copy_u64Num == 0){CLCD_voidWriteData('0');}
	else{
		while(Copy_u64Num != 0){
			Reversed = (Reversed * 10) + (Copy_u64Num % 10) ;
			Copy_u64Num /= 10;
		}
		while(Reversed !=1){
			CLCD_voidWriteData((Reversed % 10)+48);
			Reversed /= 10;
		}
	}
}
void CLCD_voidWriteData    ( u8 Copy_u8Data    ){

	DIO_voidSetPinValue( CLCD_CONTROL_PORT , CLCD_RS_PIN , HIGH );
	DIO_voidSetPinValue( CLCD_CONTROL_PORT , CLCD_RW_PIN , LOW  );
	DIO_voidSetPortValue ( CLCD_DATA_PORT  , Copy_u8Data );

	DIO_voidSetPinValue( CLCD_CONTROL_PORT , CLCD_EN_PIN , HIGH );
	_delay_ms(1);
	DIO_voidSetPinValue( CLCD_CONTROL_PORT , CLCD_EN_PIN , LOW  );
	_delay_ms(1);

}
void CLCD_voidWriteCommend ( u8 Copy_u8Commend ){

	DIO_voidSetPinValue( CLCD_CONTROL_PORT , CLCD_RS_PIN , LOW  );
	DIO_voidSetPinValue( CLCD_CONTROL_PORT , CLCD_RW_PIN , LOW  );
	DIO_voidSetPortValue ( CLCD_DATA_PORT  , Copy_u8Commend );

	DIO_voidSetPinValue( CLCD_CONTROL_PORT , CLCD_EN_PIN , HIGH );
	_delay_ms(1);
	DIO_voidSetPinValue( CLCD_CONTROL_PORT , CLCD_EN_PIN , LOW  );
	_delay_ms(1);

}
