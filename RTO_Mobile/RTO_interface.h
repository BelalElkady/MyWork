/*
 * RTO_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_

typedef struct {
	void (*Task_voidPtr)(void);
	u8 Task_u8Counter;
	u8 Task_u8Periodicity;
}TCB;

extern void RTO_OSstart(void);
extern void RTO_voidScheduler(void);
extern void TICK_ISR(void);
extern void RTO_voidCreateTask(u8 ptrToFirstDelay, u8 PtrToPeriodicity, void (*ptr)(void));






#endif /* RTO_INTERFACE_H_ */
