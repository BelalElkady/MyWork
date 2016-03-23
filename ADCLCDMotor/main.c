/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#include "types.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "TACTILE_Interface.h"
#include "DIO_interface.h"
#include "STEPPER_interface.h"
#include "DELAY.h"
#include <string.h>
#include <stdlib.h>

void main(void) {
	u8 Local_u8SwReading;
	u8 Local_u8Flag = 0;
	u8 Local_u8StopFlag = 0;
	u8 Local_u8RightFlag = 0;
	u8 Local_u8LeftFlag = 0;
	u16 Local_u8ADCReading;
	u8 Local_u8Direction[6];
	Local_u8Direction[5] = '\0';
	u16 Local_u8ADCResult[5];
	u8 Local_u8SpeedCounter = 0;
	u16 Local_u8ADCprev=Local_u8ADCReading;
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidConfig();
	ADC_voidEnable();

	while (1) {
                           //switch8
		TACTILE_u8GetState(TACTILE_u8Switch9, &Local_u8SwReading);

		switch (Local_u8SwReading) {
		case TACTILE_u8PRESSED:
			if (Local_u8Flag == 0) {
				LCD_voidClearSceen();
				LCD_voidWriteName();
			}


			Local_u8Flag = 1;

			break;
		case TACTILE_u8RELEASED:
			ADC_voidReadSingleShot(&Local_u8ADCReading);


			if (Local_u8Flag == 1) {
				LCD_voidClearSceen();
			}
			if (Local_u8ADCReading >= 0 && Local_u8ADCReading <= 400) {

						Local_u8SpeedCounter++;
						if (Local_u8SpeedCounter >= (u16) ((Local_u8ADCReading/1000))) {
							STEPPER_voidStepLeft();
							Local_u8SpeedCounter = 0;
						}
						itoa(400-Local_u8ADCReading, Local_u8ADCResult, 10);
						strcpy(Local_u8Direction, "LEFT");
						if (Local_u8LeftFlag == 0) {
							LCD_voidClearSceen();
							Local_u8LeftFlag = 1;
						}
						Local_u8RightFlag = 0;
						Local_u8StopFlag = 0;

			} else if (Local_u8ADCReading >= 600 && Local_u8ADCReading <= 1023) {
							Local_u8SpeedCounter++;
							if (Local_u8SpeedCounter
									>= (u16) (2000 / (Local_u8ADCReading))) {
								STEPPER_voidStepRight();
								Local_u8SpeedCounter = 0;
							}
							itoa((Local_u8ADCReading-600), Local_u8ADCResult, 10);
							strcpy(Local_u8Direction, "RIGHT");
							if (Local_u8RightFlag == 0) {
								LCD_voidClearSceen();
								Local_u8RightFlag = 1;
							}
							Local_u8LeftFlag = 0;
							Local_u8StopFlag = 0;
			} else {
							STEPPER_voidStop();
							itoa((u16)0, Local_u8ADCResult, 10);
							strcpy(Local_u8Direction, "STOP");
							if (Local_u8StopFlag == 0) {
								LCD_voidClearSceen();
								Local_u8StopFlag = 1;
							}
							Local_u8RightFlag = 0;
							Local_u8LeftFlag = 0;

			}
			if(Local_u8ADCprev!=Local_u8ADCReading){
				LCD_voidWriteCommand(0x02); //return cursor to Home
				LCD_voidWriteString("Direction:");
				LCD_voidWriteString(Local_u8Direction);
				LCD_voidWriteCommand(0xC0);
				LCD_voidWriteString("Speed:");
				LCD_voidWriteString(Local_u8ADCResult);
				Local_u8ADCprev=Local_u8ADCReading;
			}
			Local_u8Flag = 0;

			break;

		}

	}

	return;
}
