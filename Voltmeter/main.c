/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "util.h"
#include "DELAY.h"
#include "DIO_interface.h"
#include "TACTILE_Interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include <stdlib.h>
#include <string.h>

void main(void) {

	u16 Local_u8ADCReading;
	u16 Local_u8LCDresult[5];
	u8 Local_u8SW;
	u8 Local_u8ADCanalog;
	DIO_voidInit();
	TACTILE_voidInit();
	ADC_voidConfig();
	ADC_voidEnable();
	LCD_voidInit();

	while (1) {

		ADC_voidReadSingleShot(&Local_u8ADCReading);
		DIO_u8ReadPinVal(DIO_u8PIN31, &Local_u8SW);
        Local_u8ADCanalog=((Local_u8ADCReading>>6)*(u16)5)/(u16)1024;
		switch (Local_u8SW) {
		case TACTILE_u8Pressed:
			DIO_u8WritePinVal(DIO_u8PIN27, 1);
			itoa(Local_u8ADCanalog+5, Local_u8LCDresult, 10);
			LCD_voidWriteString(Local_u8LCDresult);
			delay_ms(5);
			break;
		case TACTILE_u8Released:
			DIO_u8WritePinVal(DIO_u8PIN27, 0);
			itoa(Local_u8ADCanalog, Local_u8LCDresult, 10);
			LCD_voidWriteString(Local_u8LCDresult);
			delay_ms(5);
			break;

		}

		LCD_voidClearSceen();


	}

	return;
}

