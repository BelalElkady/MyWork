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
#include "DIO_private.h"
#include "interrupt.h"

volatile f32 Freq = 0;
volatile f32 DutyCycle = 0;
static u32 Local_u8Distance=0;

void Task1(void) {
	u8 Local_pinVal;
	static u16 Local_Pve = 0;
	static u16 Local_Nve = 0;
	static u8 Local_EndFlag=0;
	static u8 Local_NveFlag=0;
	static u8 Local_PveFlag=0;
	DIO_u8ReadPinVal(1, &Local_pinVal);

	switch (Local_pinVal) {
		case 1:
			if (Local_PveFlag==1 && Local_NveFlag==1) {
				Local_EndFlag=1;
			}
			Local_Pve++;
			Local_PveFlag=1;
			break;
		case 0:
			Local_Nve++;
			Local_NveFlag=1;
			break;
		default:
			break;
	}

	if (Local_EndFlag==1){
		DutyCycle=(Local_Pve*100)/(Local_Nve+Local_Pve);
		Freq=1/((Local_Nve+Local_Pve)*.012/*sys-tic measured by a percent of error*/);
		DIO_u8WritePortVal(3,Freq);
		Local_Pve=0;
		Local_Nve=0;
		Local_PveFlag=0;
		Local_NveFlag=0;
		Local_EndFlag=0;

	}
//	static u8 x = 0;
//	x=!x;
//	DIO_u8WritePinVal(16, x);



	return;
}

void Task2(void) {
	u8 Local_u8Value=0;

	static u8 Local_u8Counter=0;
	static u8 Flag=0;
	DIO_u8ReadPinVal(16,&Local_u8Value);
	switch (Local_u8Value){
	case 1:
		if (Flag==0){
			Local_u8Counter++;
		}
		Flag=1;
		break;

	case 0 :
		Flag=0;
		break;

	default:
		break;

	}

	if (Local_u8Counter==10){
		Local_u8Distance+=1;
		Local_u8Counter=0;
	}

	return;
}

void Task3(void) {

	if (Local_u8Distance>100){
		DIO_u8WritePinVal(17,0);
		DIO_u8WritePinVal(18,0);
	}
	else {
		DIO_u8WritePinVal(17,1);
		DIO_u8WritePinVal(18,1);
	}

	return;
}
void Task4(void) {




	return;
}

int main(void) {

	DIO_voidInit();
	RTO_voidCreateTask(0, 1, Task2);
	RTO_voidCreateTask(0, 4, Task3);
	//RTO_voidCreateTask(0,4,Task3);
	RTO_OSstart();

	while (1) {

	}

	return 0;

}

