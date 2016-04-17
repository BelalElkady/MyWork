/*
 * main.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: Belal
 */
#include "types.h"
#include "ADC_interface.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "interrupt.h"

volatile u8 Value=0;
u16 Local_ADCreading;
volatile u8 counter =0;

void Timer_ISR(void){

	counter++;


}
void Timer_setTime(u8 time){

	if (counter > time){
		Value=!Value;
		DIO_u8WritePinVal(16,Value);
		counter=0;
	}

}
int main(void) {

	DIO_voidInit();
	TIMER_voidInit();
	ADC_voidConfig();
	ADC_voidEnable();
	TIMER_voidSetOVISR(Timer_ISR);
	Global_voidInterruptEnable();
	while (1) {

		ADC_voidReadSingleShot( &Local_ADCreading);

		Timer_setTime((Local_ADCreading&0xff00)>>8);









	}

	return 0;
}






