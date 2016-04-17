/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "interrupt.h"

volatile u8 Value=1;



void Timer_ISR(void){

	Value=!Value;
	DIO_u8WritePinVal(16,Value);
//	if (Value==1){
	TIMER_voidSetCounter(255);
//	}
//	else{
//	TIMER_voidSetCounter(247);
//	}



}

int main(void) {

	DIO_voidInit();
	//TIMER_voidInit();
	//TIMER_voidSetOVISR(Timer_ISR);
	//Global_voidInterruptEnable();
	//TIMER_voidSetCounter(255);
	while (1) {



#include "DIO_private.h"

		*PORTB= 0;
		*PORTB = 1;

		//DIO_u8WritePinVal(16,1);
		//DIO_u8WritePinVal(16,0);



	}

	return 0;
}






