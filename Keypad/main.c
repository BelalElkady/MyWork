/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "DELAY.h"




void main(void) {

	DIO_voidInit();
	u8 Local_u8Val=0;


	while (1) {

		KEYPAD_voidRead(&Local_u8Val);

		DIO_u8WritePortVal(DIO_u8PORT1,~Local_u8Val);


	}
	return;
}






