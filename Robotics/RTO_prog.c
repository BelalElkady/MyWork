/*
 * RTO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "RTO_config.h"
#include "RTO_interface.h"
#include "TIMER_interface.h"
#include "DIO_interface.h"
#include "interrupt.h"

volatile  u8 OV_Count = 0;
static u8 NoOFCurrenTasks=0;
TCB TCB_Arr[NumberOfTasks];
extern void RTO_OSstart(void) {


	TIMER_voidInit();
	TIMER_voidSetOVISR(TICK_ISR);
	Global_voidInterruptEnable();
	RTO_voidScheduler();

	return;
}

extern void RTO_voidScheduler(void) {

	u8 Local_u8Counter = 0;

	for (Local_u8Counter = 0; Local_u8Counter < NoOFCurrenTasks;
			Local_u8Counter++) {
		if (TCB_Arr[Local_u8Counter].Task_u8Counter == 1) {
			TCB_Arr[Local_u8Counter].Task_voidPtr();
		}

	}

	return;

}

void TICK_ISR(void) {

	OV_Count++;
	if (OV_Count > TIMER_u8SysTick(SysTick)) {
		u8 Local_u8Counter = 0;

		for (Local_u8Counter = 0; Local_u8Counter < NoOFCurrenTasks;
				Local_u8Counter++) {
			TCB_Arr[Local_u8Counter].Task_u8Counter--;
			if (TCB_Arr[Local_u8Counter].Task_u8Counter == 0) {
				TCB_Arr[Local_u8Counter].Task_u8Counter =
						TCB_Arr[Local_u8Counter].Task_u8Periodicity;
			}

		}
		OV_Count = 0;
		RTO_voidScheduler();
	}

}

extern void RTO_voidCreateTask(u8 ptrToFirstDelay, u8 PtrToPeriodicity, void (*ptr)(void)) {

if (NoOFCurrenTasks<NumberOfTasks){
	TCB_Arr[NoOFCurrenTasks].Task_u8Counter = ptrToFirstDelay + 1;
	TCB_Arr[NoOFCurrenTasks].Task_u8Periodicity = PtrToPeriodicity;
	TCB_Arr[NoOFCurrenTasks].Task_voidPtr = ptr;
	NoOFCurrenTasks++;
}

}

