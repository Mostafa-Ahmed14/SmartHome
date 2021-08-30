/*
 * SPI_interface.h
 *
 *  Created on: Aug 24, 2021
 *      Author: Mostafa
 */

#ifndef MACL_SPI_INTERFACE_H_
#define MACL_SPI_INTERFACE_H_

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);

void SPI_voidMasterStart(void);
void SPI_voidMasterStop(void);

u8 SPI_u8MasterTransmit(u8 Data);

#endif /* MACL_SPI_INTERFACE_H_ */
