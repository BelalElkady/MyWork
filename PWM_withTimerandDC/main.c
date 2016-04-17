/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"
#include "interrupt.h"

volatile u8 Value=1;


u16 ADC_read;
volatile u8 ADC_Counter=0;
void Timer_ISR(void){
	ADC_Counter++;
	if (ADC_Counter > ((ADC_read>>8))){
			//Value=!Value;
			DIO_u8WritePinVal(8,1);

	}
	else {
		    DIO_u8WritePinVal(8,0);
	}

	if (ADC_Counter>255) ADC_Counter=0;


}

int main(void) {

	DIO_voidInit();
	TIMER_voidInit();
	ADC_voidConfig();
	ADC_voidEnable();
	TIMER_voidSetOVISR(Timer_ISR);
	Global_voidInterruptEnable();

	while (1) {

		ADC_voidReadSingleShot(&ADC_read);



	}

	return 0;
}






