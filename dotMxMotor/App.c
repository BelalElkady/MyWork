/*

 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#include "types.h"
#include  "DELAY.h"
#include "App.h"
#include "DIO_interface.h"
#include "SHIFT_interface.h"
#include "KEYPAD_interface.h"
#include "TACTILE_Interface.h"

/*Comment!: rows then colums */

static const u8 App_u8MotorDirArr[MOTOR_NUMBER_OF_DIRECTIONS][MOTOR_NUMBER_OF_TERMINALS] ={ { DIO_u8LOW, DIO_u8HIGH }, { DIO_u8HIGH, DIO_u8LOW }, { DIO_u8LOW,DIO_u8LOW } };
static const u8 App_u8MotorPinsArr[MOTOR_NUMBER_OF_TERMINALS] = { MOTOR_PIN1,MOTOR_PIN2 };
static const u8 App_u8StepperPinsArr[STEPPER_NUMBER_OF_TERMINLS] = {STEPPER_PIN1, STEPPER_PIN2, STEPPER_PIN3, STEPPER_PIN4 };

void App_voidStepperSpeed(void) {
	static u8 Local_u8KeyVal = 0;
	static u8 Local_u8KeyPrevVal = 3;
	static u8 Local_u8Counter = 0;
	static u8 Local_u8MaxCount = 1;
	static u8 Local_u8Dir = LEFT;
	static u8 Local_u8Flag = 0;

	/*Stepper Part*/
	KEYPAD_voidRead(&Local_u8KeyVal);

	if (Local_u8Flag == 1) {
		Local_u8KeyVal = Local_u8KeyPrevVal;
	}
	switch (Local_u8KeyVal) {
	case 0:
		Local_u8Flag = 1;
		break;
	case 14:
		Local_u8MaxCount = Local_u8KeyVal + 2;
		while (Local_u8Counter == Local_u8MaxCount) {
			App_voidStepperStop();
 			Local_u8Counter = 0;

		}
		App_voidDotMotor();
		Local_u8Counter++;
		Local_u8KeyPrevVal = Local_u8KeyVal;
		Local_u8Flag = 0;

		break;
	case 15:
		     if (Local_u8Dir==LEFT){
		    	 Local_u8Dir=RIGHT;
		     }else if(Local_u8Dir==RIGHT){
		    	 Local_u8Dir=LEFT;
		     }
		     App_voidDotMotor();
			break;
	default:

		Local_u8MaxCount =  (Local_u8KeyVal + 2);
		while (Local_u8Counter == Local_u8MaxCount) {
			if(Local_u8Dir==LEFT){
			App_voidStepperStepLeft();
			   }
			else if(Local_u8Dir==RIGHT){
			   App_voidStepperStepRight();
			}
			Local_u8Counter = 0;
		}
		App_voidDotMotor();
		Local_u8Counter++;

		Local_u8KeyPrevVal = Local_u8KeyVal;
		Local_u8Flag = 0;
		break;

	}

	return;
}

extern void App_voidDisplayLetter(u8 Copy_u8PtrToLetterArr[][COLS]) {

	u8 Local_u8CounterRows;
	u8 Local_u8CounterCols;

	for (Local_u8CounterRows = 0; Local_u8CounterRows < ROWS;
			Local_u8CounterRows++) {
		for (Local_u8CounterCols = 0; Local_u8CounterCols < COLS;
				Local_u8CounterCols++) {

			SHIFT_voidWriteVal(Copy_u8PtrToLetterArr[Local_u8CounterRows][Local_u8CounterCols]);

		}
		SHIFT_voidWriteLatch();
	}

	return;
}

extern u8 App_u8MotorDirection(u8 Copy_u8Dir) {
	u8 Local_u8ReturnFlag = OK;
	u8 Local_u8Counter;
	if (Copy_u8Dir != RIGHT && Copy_u8Dir != LEFT && Copy_u8Dir != STOP) {
		Local_u8ReturnFlag = ERROR;
	} else {
		for (Local_u8Counter = 0; Local_u8Counter < MOTOR_NUMBER_OF_TERMINALS;
				Local_u8Counter++) {
			DIO_u8WritePinVal(App_u8MotorPinsArr[Local_u8Counter],
					App_u8MotorDirArr[Copy_u8Dir][Local_u8Counter]);
		}
		switch (Copy_u8Dir) {
		case RIGHT:

			App_voidDisplayLetter(App_u8LetterR);
			break;
		case LEFT:

			App_voidDisplayLetter(App_u8LetterL);
			break;
		case STOP:

			App_voidDisplayLetter(App_u8Stop);
			break;
		default:

			break;

		}

		Local_u8ReturnFlag = OK;
	}
	return Local_u8ReturnFlag;

}

extern void App_voidInit(void) {

	App_u8MotorDirection(STOP);
	SHIFT_voidInit();

	return;
}

extern void App_voidDotMotor(void) {
	static u8 Local_u8Mode = INIT;
	static u8 Local_u8Flag = 0;
	static u8 Local_u8Switch = TACTILE_u8RELEASED;
	static u16 Local_u8Counter = 0;
	static u8 Local_u8MotorDir = RIGHT;

	TACTILE_u8GetState(TACTILE_u8Switch32, &Local_u8Switch);

	switch (Local_u8Mode) {
	case INIT:

		switch (Local_u8Switch) {
		case TACTILE_u8PRESSED:

			if (Local_u8Counter >= 250) {
				Local_u8Mode = ON_CLICK;
				Local_u8Counter = 0;

			} else {
				Local_u8Counter++;
				App_u8MotorDirection(Local_u8MotorDir);
			}

			break;
		case TACTILE_u8RELEASED:

			if (Local_u8Counter > 0 && Local_u8Counter < 250) {
				Local_u8Mode = CONTINUES;
				Local_u8Counter = 0;
				App_u8MotorDirection(Local_u8MotorDir);

			} else {
				App_u8MotorDirection(STOP);
			}

			break;

		}

		break;

	case CONTINUES:

		switch (Local_u8Switch) {
		case TACTILE_u8PRESSED:

			App_u8MotorDirection(STOP);

			Local_u8Flag = 1;

			break;
		case TACTILE_u8RELEASED:

			if (Local_u8Flag == 1) {
				Local_u8Mode = INIT;
				App_u8MotorDirection(STOP);

				Local_u8Flag = 0;
			} else {
				App_u8MotorDirection(Local_u8MotorDir);
			}

			break;

		}

		break;
	case ON_CLICK:
		switch (Local_u8Switch) {
		case TACTILE_u8PRESSED:

			App_u8MotorDirection(Local_u8MotorDir);

			break;
		case TACTILE_u8RELEASED:

			App_u8MotorDirection(STOP);
			App_u8MotorDirection(Local_u8MotorDir);
			if (Local_u8MotorDir == RIGHT) {
				Local_u8MotorDir = LEFT;
			} else if (Local_u8MotorDir == LEFT) {
				Local_u8MotorDir = RIGHT;
			}

			Local_u8Mode = INIT;
			break;

		}

		break;

	}

}

extern void App_voidStepperStepLeft(void) {
	static u8 Local_u8StepCount = 0;
	static u8 Local_u8StepVal = 0x01;

	DIO_u8WritePinVal(App_u8StepperPinsArr[0], ~(Local_u8StepVal & 0x01));
	DIO_u8WritePinVal(App_u8StepperPinsArr[1], ~((Local_u8StepVal & 0x02) >> 1));
	DIO_u8WritePinVal(App_u8StepperPinsArr[2], ~((Local_u8StepVal & 0x04) >> 2));
	DIO_u8WritePinVal(App_u8StepperPinsArr[3], ~((Local_u8StepVal & 0x08) >> 3));

	Local_u8StepCount++;

	Local_u8StepVal <<= 1;

	if (Local_u8StepCount == 4) {
		Local_u8StepCount = 0;
		Local_u8StepVal = 0x01;
	}

	return;
}

extern void App_voidStepperStepRight(void) {
	static u8 Local_u8StepCount = 0;
	static u8 Local_u8StepVal = 0x08;

	DIO_u8WritePinVal(App_u8StepperPinsArr[0],~( Local_u8StepVal & 0x01));
	DIO_u8WritePinVal(App_u8StepperPinsArr[1], ~((Local_u8StepVal & 0x02) >> 1));
	DIO_u8WritePinVal(App_u8StepperPinsArr[2],~ ((Local_u8StepVal & 0x04) >> 2));
	DIO_u8WritePinVal(App_u8StepperPinsArr[3],~((Local_u8StepVal & 0x08) >> 3));

	Local_u8StepCount++;

	Local_u8StepVal >>= 1;

	if (Local_u8StepCount == 4) {
		Local_u8StepCount = 0;
		Local_u8StepVal = 0x08;
	}

	return;
}

extern void App_voidStepperStop(void) {
	static u8 Local_u8StepCount = 0;
	static u8 Local_u8StepVal = 0x00;

	DIO_u8WritePinVal(App_u8StepperPinsArr[0], Local_u8StepVal);
	DIO_u8WritePinVal(App_u8StepperPinsArr[1], Local_u8StepVal);
	DIO_u8WritePinVal(App_u8StepperPinsArr[2], Local_u8StepVal);
	DIO_u8WritePinVal(App_u8StepperPinsArr[3], Local_u8StepVal);

	Local_u8StepCount++;

	if (Local_u8StepCount == 4) {
		Local_u8StepCount = 0;
		Local_u8StepVal = 0x00;
	}

	return;
}
