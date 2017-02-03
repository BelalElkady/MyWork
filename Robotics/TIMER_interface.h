/*
 * TIMER_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

extern void TIMER_voidInit(void);
extern f32  TIMER_u8SysTick(f32 Local_f32SetTick);
extern void TIMER_voidSetCounter(u8 Copy_u8Value);
extern void TIMER_voidCheckFlag(void);
extern void TIMER_voidEnableOVInterrupt(void);
extern void TIMER_voidEnableCTCInterrupt(void);
extern void TIMER_voidDisableOVInterrupt(void);
extern void TIMER_voidDisableCTCInterrupt(void);
extern void TIMER_voidSetOVISR(void (*Copy_PtrToFun)(void));
extern void TIMER_voidSetCTCISR(void (*Copy_PtrToFun)(void));
extern void TIMER_voidClearTimer(void);
#endif /* TIMER_INTERFACE_H_ */
