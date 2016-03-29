/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Belal
 */
#include "types.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "UART_interface.h"

void SPI_IRQHandelr(void){

	UART_voidSend(SPI_voidInterruptReceiveData());
}


int main (void){

	DIO_voidInit();
	SPI_voidInit();
	SPI_voidEnable();
	SPI_voidInterruptEnable();
	SPI_voidSetISR(SPI_IRQHandelr);
	SPI_SlaveInit();
	UART_voidInit();
	UART_voidTxEnable();

	while(1);


	return 0 ;
}


