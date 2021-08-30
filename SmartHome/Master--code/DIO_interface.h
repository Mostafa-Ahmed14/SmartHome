/*
 * DIO_interface.h
 *
 *  Created on: May 29, 2021
 *      Author: AMIT
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_

#define OUTPUT  1
#define INPUT   0

#define HIGH    1
#define LOW     0

#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3

#define PIN1   0
#define PIN2   1
#define PIN3   2
#define PIN4   3
#define PIN5   4
#define PIN6   5
#define PIN7   6
#define PIN8   7

void DIO_voidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction);
void DIO_voidSetPortValue     (u8 Copy_u8Port , u8 Copy_u8Value);
u8   DIO_u8GetPortValue       (u8 Copy_u8Port);


void DIO_voidSetPinDirection  (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);
void DIO_voidSetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);
u8   DIO_u8GetPinValue        (u8 Copy_u8Port , u8 Copy_u8Pin );



#endif /* DIO_DIO_INTERFACE_H_ */