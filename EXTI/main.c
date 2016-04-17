/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "EXTI_interface.h"
#include "DELAY.h"
#include "DIO_interface.h"
#include "interrupt.h"

volatile u8 x =0;
void function(void){
  x^=1;
  DIO_u8WritePinVal(0,x);


}


int main (void){
	DIO_voidInit();
	Global_voidInterruptEnable();
	EXTI_voidInit();
	EXTI_voidINT0SetISR(function);


	while(1){
		DIO_u8WritePinVal(24,1);
		delay_ms(10);
		DIO_u8WritePinVal(24,0);
		delay_ms(10);

	}


	return 0 ;
}

