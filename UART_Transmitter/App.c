/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "UART_private.h"
#include "UART_interface.h"
#include "DIO_interface.h"
#include "DELAY.h"

void main(void) {
	u8 Local_u8ReadPin;
	DIO_voidInit();
	UART_voidInit();
	UART_voidTxEnable();

	while (1) {
		DIO_u8ReadPinVal(DIO_u8PIN0, &Local_u8ReadPin);
		delay_ms(10);
		if (Local_u8ReadPin == 1) {
			UART_voidSend('1');
		} else {
			UART_voidSend('0');
		}
	}
	return;
}
