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


		LCD_voidWriteString("Belal");
		delay_ms(10);
		LCD_voidClearSceen();
		LCD_voidWriteName();





	}

	return;
}
