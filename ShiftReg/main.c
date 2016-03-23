/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "DELAY.h"
#include "DIO_interface.h"
#include "SHIFT_interface.h"



void main(void) {

	DIO_voidInit();

	while (1) {

		SHIFT_u8WriteVal(0b01000000);
		SHIFT_u8WriteVal(0b00000000);
		SHIFT_u8WriteLatch();

		SHIFT_u8WriteVal(0b00100000);
		SHIFT_u8WriteVal(0b11100110);
		SHIFT_u8WriteLatch();


		SHIFT_u8WriteVal(0b00010000);
		SHIFT_u8WriteVal(0b11010110);
		SHIFT_u8WriteLatch();

		SHIFT_u8WriteVal(0b00001000);
		SHIFT_u8WriteVal(0b10110110);
		SHIFT_u8WriteLatch();

		SHIFT_u8WriteVal(0b00000100);
		SHIFT_u8WriteVal(0b01110000);
		SHIFT_u8WriteLatch();




	}

	return;
}

