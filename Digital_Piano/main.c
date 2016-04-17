/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "KEYPAD_interface.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "interrupt.h"
#include "DELAY.h"
volatile u8 Value=0;
u8 Local_u8KeyValue;
u8 Tones[16]={1 , 10 , 20 , 30 , 40 , 50 ,  60 , 70 , 80 , 90 , 100 , 120 , 140 , 150 , 160 , 180 };
void Timer_ISR(void){

			Value=!Value;
			TIMER_voidSetCounter(Tones[Local_u8KeyValue]);



}

int main(void) {

	DIO_voidInit();
	TIMER_voidInit();
	TIMER_voidSetOVISR(Timer_ISR);
	Global_voidInterruptEnable();


	while (1) {



    App();


	}

	return 0;
}







void App(void) {



	KEYPAD_voidRead(&Local_u8KeyValue);

	if (Local_u8KeyValue!=0){

		DIO_u8WritePinVal(16,Value);
		DIO_u8WritePinVal(31,Value);



	}
	else {

		DIO_u8WritePinVal(16,0);
		DIO_u8WritePinVal(31,0);
	}



	return;
}
