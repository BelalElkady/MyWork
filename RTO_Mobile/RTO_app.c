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
#include "SPI_interface.h"
#include "interrupt.h"

#define NUM_OF_SIGNALS	5

#define  STOP		0
#define  FRONT		1
#define  BACKWORD	2
#define  RIGHT		3
#define  LEFT		4

static u8 Data;

struct{
	u8 Motor:1;
	u8 Right_Dir:1;
	u8 Left_Dir:1;
}Encoder;

const static struct Encoder Motors_Signal[NUM_OF_SIGNALS]={{0,0,0},{1,0,0},{1,1,1},{1,1,0},{1,0,1}};


void Task1(void) {
	Data = SPI_voidReceiveData();
}
void Task2(void) {

}
int main(void) {

	DIO_voidInit();
	SPI_voidInit();
	SPI_voidEnable();
	SPI_SlaveInit();
	RTO_voidCreateTask(0, 1, Task1);
	RTO_voidCreateTask(0, 1, Task2);
	//RTO_voidCreateTask(0,4,Task3);
	RTO_OSstart();

	while (1) {

	}

	return 0;

}

