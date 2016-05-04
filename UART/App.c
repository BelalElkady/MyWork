/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "UART_private.h"
#include "UART_interface.h"
#include "interrupt.h"
void ISR_Handler(void){



}


void main(void) {
	UART_voidInit();
	UART_voidReceiveISR(ISR_Handler);

	while (1) {

	}
 return ;
}
