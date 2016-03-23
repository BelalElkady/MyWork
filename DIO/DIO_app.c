/*
 * DIO_app.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DELAY.h"
#define NAMESIZE 5
#define LEDS DIO_u8PORT2

int main(void) {

	u8 Local_u8Counter, Local_u8Status, Local_u8Shift = 0x01,
			Local_u8ShiftLeft = 0x00, Local_u8CounterRight;
	u8 Local_u8NameArr[NAMESIZE] = "BELAL";

	DIO_voidInit();


	while (1) {
		DIO_u8WritePinVal(0, 1);
		delay100ms();

				DIO_u8WritePinVal(0, 0);
				delay100ms();

		/*for (Local_u8Counter = 0; Local_u8Counter < 7; Local_u8Counter++) {
			DIO_u8WritePortVal(LEDS, 0x01 << Local_u8Counter);
			delay_ms(100);

		}
		for (Local_u8Counter = 0; Local_u8Counter < 7; Local_u8Counter++) {
			DIO_u8WritePortVal(LEDS, 0x80 >> Local_u8Counter);
			delay_ms(100);
		}
		for (Local_u8Counter = 0; Local_u8Counter < 3; Local_u8Counter++) {
			DIO_u8WritePortVal(LEDS, 0xFF);
			delay_ms(100);
			DIO_u8WritePortVal(LEDS, 0x00);
			delay_ms(100);
		}
		for (Local_u8Counter = 0; Local_u8Counter < 3; Local_u8Counter++) {
			DIO_u8WritePortVal(LEDS, 0xAA);
			delay_ms(100);
			DIO_u8WritePortVal(LEDS, 0x55);
			delay_ms(100);
		}
		for (Local_u8Counter = 0; Local_u8Counter < 3; Local_u8Counter++) {
			DIO_u8WritePortVal(LEDS, 0x33);
			delay_ms(100);
			DIO_u8WritePortVal(LEDS, 0xCC);
			delay_ms(100);
		}
		for (Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++) {
			Local_u8Shift |= 1 << Local_u8Counter;
			DIO_u8WritePortVal(LEDS, Local_u8Shift);
			delay_ms(100);

		}
		for (Local_u8Counter = 7; Local_u8Counter > 0; Local_u8Counter--) {
			Local_u8Shift &= ~(1 << Local_u8Counter);
			DIO_u8WritePortVal(LEDS, Local_u8Shift);
			delay_ms(100);
		}
		for (Local_u8Counter = 0, Local_u8CounterRight = 7; Local_u8Counter < 4;
				Local_u8Counter++, Local_u8CounterRight--) {

			Local_u8ShiftLeft |= 1 << Local_u8Counter
					| 1 << Local_u8CounterRight;
			DIO_u8WritePortVal(LEDS, Local_u8ShiftLeft);

			delay_ms(100);
		}
		for (Local_u8Counter = 3, Local_u8CounterRight = 4;
				Local_u8CounterRight <= 7;
				Local_u8Counter--, Local_u8CounterRight++) {

			Local_u8ShiftLeft &= ~(1 << Local_u8Counter)
					& ~(1 << Local_u8CounterRight);
			DIO_u8WritePortVal(LEDS, Local_u8ShiftLeft);

			delay_ms(100);
		}
		for (Local_u8Counter = 0, Local_u8CounterRight = 7; Local_u8Counter < 4;
				Local_u8Counter++, Local_u8CounterRight--) {
			Local_u8ShiftLeft = 1 << Local_u8Counter
					| 1 << Local_u8CounterRight;
			DIO_u8WritePortVal(LEDS, Local_u8ShiftLeft);
			delay_ms(100);
		}

		for (Local_u8Counter = 0; Local_u8Counter < NAMESIZE;
				Local_u8Counter++) {
			DIO_u8WritePortVal(LEDS, Local_u8NameArr[Local_u8Counter]);
			delay_ms(100);

		}
*/

	}
	return 0;
}

void delay100ms(void){ 	// try different numbers on your
volatile unsigned int i;	// compiler and examine
	for(i=0; i<42150; i++);	// result.
}

