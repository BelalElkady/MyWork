/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "interrupt.h"
#include "UART_private.h"
#include "UART_interface.h"
#include "DIO_interface.h"
#include "DELAY.h"


void ISR_Handler(void) {


	if (UART_u8InterruptReceive() == '1') {
		DIO_u8WritePinVal(DIO_u8PIN8, 1);
	} else {
		DIO_u8WritePinVal(DIO_u8PIN8, 0);
	}

}
int main(void) {

	DIO_voidInit();
	UART_voidInit();
	UART_voidRxEnable();
	UART_voidReceiveISR(ISR_Handler);

	while (1) ;
	return 0;
}
