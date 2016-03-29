/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "UART_interface.h"


int main (void){

	DIO_voidInit();
	SPI_voidInit();
	SPI_voidEnable();
	SPI_MasterInit();
	UART_voidInit();
	UART_voidRxEnable();

	while(1){




     SPI_voidSendData(UART_u8Receive());


	}

	return 0 ;
}


