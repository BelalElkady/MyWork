/*
 * RTO_app.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "RTO_interface.h"
#include "TIMER_interface.h"
#include "DIO_interface.h"
#include "interrupt.h"

void Task1(void){
	static u8 LED_Status=0;
	LED_Status=!LED_Status;
	DIO_u8WritePinVal(16,LED_Status);
	return ;
}

void Task2(void){
	static u8 LED_Status=0;
		LED_Status=!LED_Status;
		DIO_u8WritePinVal(17,LED_Status);
		return ;
}

void Task3(void){

	static u8 LED_Status=0;
		LED_Status=!LED_Status;
		DIO_u8WritePinVal(18,LED_Status);
		return ;

	return ;
}
void Task4(void){

	static u8 LED_Status=0;
		LED_Status=!LED_Status;
		DIO_u8WritePinVal(18,LED_Status);
		return ;

	return ;
}




int main (void){

	DIO_voidInit();
	RTO_voidCreateTask(0,2,Task1);
	RTO_voidCreateTask(0,3,Task2);
	RTO_voidCreateTask(0,4,Task3);

	RTO_OSstart();




	while (1){





	}

return 0;


}

