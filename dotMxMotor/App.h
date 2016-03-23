/*
 * App.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef APP_H_
#define APP_H_

#define ROWS 5
#define COLS 2

#define STOP  2
#define RIGHT 1
#define LEFT  0

#define INIT      0
#define CONTINUES 1
#define ON_CLICK  2

#define SEND_ROW 0


#define STEPPER_PIN1 DIO_u8PIN20
#define STEPPER_PIN2 DIO_u8PIN21
#define STEPPER_PIN3 DIO_u8PIN22
#define STEPPER_PIN4 DIO_u8PIN23


#define STEPPER_NUMBER_OF_TERMINLS 4


#define MOTOR_PIN1 DIO_u8PIN16
#define MOTOR_PIN2 DIO_u8PIN17




#define MOTOR_NUMBER_OF_TERMINALS 2
#define MOTOR_NUMBER_OF_DIRECTIONS 3


#if (SEND_ROW==1)

	static const u8 App_u8LetterR[ROWS][COLS] = { { 0b01000000, 0b00000000 }, { 0b00100000,
			0b11100110 }, { 0b00010000, 0b11010110 }, { 0b00001000, 0b10110110 }, {
			0b00000100, 0b01110000 } };

	static const u8 App_u8LetterL[ROWS][COLS] = { { 0b01000000, 0b00000000 }, { 0b00100000,
			0b01111111 }, { 0b00010000, 0b01111111 }, { 0b00001000, 0b01111111}, {
			0b00000100, 0b01111111 } };



	static const u8 App_u8Stop[ROWS][COLS] = { {0b00000000 , 0b00000000 }, { 0b00000000 , 0b00000000}, {  0b00000000 , 0b00000000}, {  0b00000000 , 0b00000000}, {
						0b00000000,0b00000000} };
#else



static const u8 App_u8LetterR[ROWS][COLS] = { { 0b00001110, 0b00000100 }, {
		0b01101101, 0b00001000 }, { 0b01101011, 0b00010000 },{ 0b01100111, 0b00100000 }, { 0b00000000,
		0b01000000 }
					 };

static const u8 App_u8LetterL[ROWS][COLS] = { {0b00000000 , 0b01000000 }, { 0b11111110 , 0b00100000}, {  0b11111110 , 0b00010000}, {  0b011111110 , 0b00001000}, {
					0b11111110,0b00000100 } };


static const u8 App_u8Stop[ROWS][COLS] = { {0b00000000 , 0b00000000 }, { 0b00000000 , 0b00000000}, {  0b00000000 , 0b00000000}, {  0b00000000 , 0b00000000}, {
		0b00000000,0b00000000} };


#endif




extern void App_voidDisplayLetter(u8 Copy_u8PtrToLetterArr[][COLS]);
extern u8 App_u8MotorDirection (u8 Copy_u8Dir);
extern void App_voidStepperSpeed(void);
extern void App_voidDotMotor(void);
extern void App_voidStepperStepLeft(void);
extern void App_voidStepperStop(void);
extern void App_voidStepperStepRight(void);
extern void App_voidInit(void);




#endif /* APP_H_ */
