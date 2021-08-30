/*
 * CLCD_interface.h
 *
 *  Created on: Jun 11, 2021
 *      Author: AMIT
 */

#ifndef HAL_CLCD_CLCD_INTERFACE_H_
#define HAL_CLCD_CLCD_INTERFACE_H_

#define CLCD_Row1         1
#define CLCD_Row2         2

#define CLCD_Col1         0
#define CLCD_Col2         1
#define CLCD_Col3         2
#define CLCD_Col4         3
#define CLCD_Col5         4
#define CLCD_Col6         5
#define CLCD_Col7         6
#define CLCD_Col8         7
#define CLCD_Col9         8
#define CLCD_Col10        9
#define CLCD_Col11        10
#define CLCD_Col12        11
#define CLCD_Col13        12
#define CLCD_Col14        13
#define CLCD_Col15        14
#define CLCD_Col16        15

void CLCD_voidInit(void);
void CLCD_voidWriteData       ( u8  Copy_u8Data    );
void CLCD_voidWriteCommend    ( u8  Copy_u8Commend );
void CLCD_voidWriteString     ( u8 * Copy_u8ptrString );
void CLCD_voidSendNumber      ( u64 Copy_u64Num    );
void CLCD_voidSetPosition     ( u8  Row , u8 Col   );
void CLCD_voidWriteExtraChar  ( u8 * ptr , u8 Len , u8 Row , u8 Col );
#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
