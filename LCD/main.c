/*
 * mai.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#include "types.h"
#include "DELAY.h"
#include "LCD_interface.h"
#include "DIO_interface.h"

void main(void) {

	DIO_voidInit();
	LCD_voidInit();


	while (1) {

		__asm__("LDI 17,0");
		__asm__("OUT 0x1B,17");


		LCD_voidWriteString("Belal");

		__asm__("LDI 17,0xff");
		__asm__("OUT 0x1B,17");


		LCD_voidWriteString("Belal");  //600u
//		delay_ms(10);
//		LCD_voidClearSceen();
//		LCD_voidWriteName();





	}

	return;
}
