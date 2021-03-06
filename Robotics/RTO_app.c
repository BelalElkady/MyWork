/*
 * RTO_app.c
 *
 *  Created on: ??�/??�/????
 *      Author: Belal
 */
#include "types.h"
#include "RTO_interface.h"
#include "TIMER_interface.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "interrupt.h"

volatile u16 Counter = 0;
volatile u8 Motor_Counter = 0;

const u8 Arr[100]={ 0x1F,0x3F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F
		           ,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F
				   ,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
				   ,0xFB,0xFB,0xFB,0xFB,0xEB,0xEB,0xEB,0xEB,0xEB,0xEB
				   ,0xEB,0xEB,0xEB,0xEB,0xEB,0xEB,0xEB,0xEB,0xEB,0xEB
				   ,0xE1,0xE1,0xE1,0xE1,0xE1,0xE1,0xE1,0xE1,0xE1,0xE1
				   ,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
				   ,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
				   ,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
				   ,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
};
void Task1(void){


	if (Counter<=57){

		*PORTC=0xff;
	}
	else if (Counter > 57 && (Counter<=157)){

		*PORTC=Arr[Motor_Counter];
	    Motor_Counter++;


	}
	else if (Counter > 157 && (Counter<=1271)) {
		*PORTC=0x00;
	}
	else {
		Counter = 0 ;
		Motor_Counter=0;
	}

	Counter++;


    TIMER_voidSetCounter(138);

return ;
}

void Task2(void){

}

void Task3(void){


		return ;

	return ;
}
void Task4(void){



	return ;
}




int main (void){

	DIO_voidInit();
	Global_voidInterruptEnable();
	TIMER_voidInit();
	TIMER_voidSetOVISR(Task1);
	 TIMER_voidSetCounter(138);




	while (1){





	}

return 0;


}

