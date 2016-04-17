/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "EXTI_interface.h"
#include "KEYPAD_interface.h"
#include "DELAY.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "TACTILE_Interface.h"
#include "interrupt.h"

volatile u8 x = 0;
u8 Led1_Flag = 0;
u8 Led2_Flag = 0;
u8 Led3_Flag = 0;

volatile u8 Led1_Status = 0;
volatile u8 Led2_Status = 0;
volatile u8 Led3_Status = 0;
volatile u8 Led1_Counter = 0;
volatile u8 Led2_Counter = 0;
volatile u8 Led3_Counter = 0;
volatile u8 Local_u8flagLed1 = 0;
volatile u8 Local_u8flagLed2 = 0;
volatile u8 Local_u8flagLed3 = 0;
volatile u8 Local_u8flagEXT=0;

void App(void);
void ToggleLed(void) {

			if (Led1_Flag == 1) {
				Led1_Status ^= 1;

			}
			if (Led2_Flag == 1) {
				Led2_Status ^= 1;
			}
			if (Led3_Flag == 1) {
				Led3_Status ^= 1;
			}

}
void Timer_ISR(void) {
	Led1_Counter++;
	Led2_Counter++;
	Led3_Counter++;
	return;
}

int main(void) {

	DIO_voidInit();
	EXTI_voidInit();
	TIMER_voidInit();
	TIMER_voidSetOVISR(Timer_ISR);
	Global_voidInterruptEnable();
	EXTI_voidINT0SetISR(ToggleLed);

	while (1) {

		App();

	}

	return 0;
}

void LED1_blinking(void) {
	static u8 LED_STATUS = 0;
	LED_STATUS = !LED_STATUS;
	DIO_u8WritePinVal(16, LED_STATUS);


}
void LED2_blinking(void) {
	static u8 LED_STATUS = 0;
	LED_STATUS = !LED_STATUS;
	DIO_u8WritePinVal(17, LED_STATUS);


}
void LED3_blinking(void) {
	static u8 LED_STATUS = 0;
	LED_STATUS = !LED_STATUS;
	DIO_u8WritePinVal(18, LED_STATUS);


}

void LED1_OFF(void) {

	DIO_u8WritePinVal(16, 0);
}
void LED2_OFF(void) {
	DIO_u8WritePinVal(17, 0);
}
void LED3_OFF(void) {
	DIO_u8WritePinVal(18, 0);
}

void App(void) {
	u8 Local_u8KeyValue;
	u8 Local_u8SwValue;

	KEYPAD_voidRead(&Local_u8KeyValue);
	TACTILE_u8GetState(24,&Local_u8SwValue);
	if (Local_u8SwValue==TACTILE_u8Pressed){
		DIO_u8WritePinVal(25,1);
	}
	else{
		DIO_u8WritePinVal(25,0);
	}
	if (Local_u8KeyValue==0){
		Local_u8flagLed1=0;
		Local_u8flagLed2=0;
		Local_u8flagLed3=0;
	}

	switch (Local_u8KeyValue) {
	case 5:
		if (Local_u8flagLed1==0){
		Led1_Flag ^= 1;
		Led2_Flag = 0;
		Led3_Flag = 0;
		LED1_blinking();
		Local_u8flagLed1=1;
		}


		break;
	case 6:
		if (Local_u8flagLed2==0){
		Led2_Flag ^= 1;
		Led1_Flag = 0;
		Led3_Flag = 0;
		LED2_blinking();
		Local_u8flagLed2=1;
				}

		break;
	case 7:
		if (Local_u8flagLed3==0){
		Led3_Flag ^= 1;
		Led2_Flag = 0;
		Led1_Flag = 0;
		LED3_blinking();
		Local_u8flagLed3=1;
				}
		break;

	default:

		break;

	}

	if (Led1_Status == 1) {
		if (Led1_Counter > 10) {
			LED1_blinking();
			Led1_Counter = 0;

		}
	} else {
		LED1_OFF();
	}
	if (Led2_Status == 1) {
		if (Led2_Counter > 10) {
			LED2_blinking();
			Led2_Counter = 0;
		}
	} else {
		LED2_OFF();
	}
	if (Led3_Status == 1) {
		if (Led3_Counter > 10) {
			LED3_blinking();
			Led3_Counter = 0;
		}
	} else {
		LED3_OFF();
	}

	return;
}
