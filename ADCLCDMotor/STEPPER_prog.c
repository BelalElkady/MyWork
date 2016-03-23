/*
 * STEPPER_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#include "types.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DELAY.h"
#include "STEPPER_interface.h"
#include "STEPPER_config.h"

static const u8 STEPPER_u8PinsArr[STEPPER_NUMBER_OF_TERMINLS] = {STEPPER_PIN1, STEPPER_PIN2, STEPPER_PIN3, STEPPER_PIN4 };



extern void STEPPER_voidStepRight(void) {
	static u8 Local_u8StepCount = 0;
	static u8 Local_u8StepVal = 0x08;

	DIO_u8WritePinVal(STEPPER_u8PinsArr[0], ( Local_u8StepVal & 0x01));
	DIO_u8WritePinVal(STEPPER_u8PinsArr[1], ((Local_u8StepVal & 0x02) >> 1));
	DIO_u8WritePinVal(STEPPER_u8PinsArr[2],  ((Local_u8StepVal & 0x04) >> 2));
	DIO_u8WritePinVal(STEPPER_u8PinsArr[3], ((Local_u8StepVal & 0x08) >> 3));


	Local_u8StepCount++;

	Local_u8StepVal >>= (u8)1;

	if (Local_u8StepCount == 4) {
		Local_u8StepCount = 0;
		Local_u8StepVal = 0x08;
	}

	return;
}


extern void STEPPER_voidStop(void) {
	static u8 Local_u8StepCount = 0;
	static u8 Local_u8StepVal = 0x00;

	DIO_u8WritePinVal(STEPPER_u8PinsArr[0], Local_u8StepVal);
	DIO_u8WritePinVal(STEPPER_u8PinsArr[1], Local_u8StepVal);
	DIO_u8WritePinVal(STEPPER_u8PinsArr[2], Local_u8StepVal);
	DIO_u8WritePinVal(STEPPER_u8PinsArr[3], Local_u8StepVal);

	Local_u8StepCount++;

	if (Local_u8StepCount == 4) {
		Local_u8StepCount = 0;
		Local_u8StepVal = 0x00;
	}

	return;
}

extern void STEPPER_voidStepLeft(void) {
	static u8 Local_u8StepCount = 0;
	static u8 Local_u8StepVal = 0x01;

	DIO_u8WritePinVal(STEPPER_u8PinsArr[0], (Local_u8StepVal & 0x01));
	DIO_u8WritePinVal(STEPPER_u8PinsArr[1], ((Local_u8StepVal & 0x02) >> 1));
	DIO_u8WritePinVal(STEPPER_u8PinsArr[2], ((Local_u8StepVal & 0x04) >> 2));
	DIO_u8WritePinVal(STEPPER_u8PinsArr[3], ((Local_u8StepVal & 0x08) >> 3));

	Local_u8StepCount++;

	Local_u8StepVal <<=(u8) 1;

	if (Local_u8StepCount == 4) {
		Local_u8StepCount = 0;
		Local_u8StepVal = 0x01;
	}

	return;
}
