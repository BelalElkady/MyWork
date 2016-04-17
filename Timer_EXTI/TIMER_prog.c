/*
 * TIMER_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_interface.h"
#include "DIO_interface.h"
#include "interrupt.h"


static void (*PtrToOVISR)(void);
static void (*PtrToCTCISR)(void);
 volatile u8 Timer_u8Counter=0;


extern void TIMER_voidInit(void) {

	TCCR0 |= TIMER0_MODE | TIMER0_PRESCALER;
	TIMSK |= TIMER0_OV_INTRRUPT;

	return;
}

extern u16 TIMER_u8ReadTimer(void) {
	u32  Local_Timer;

#if TIMER0_PRESCALER==FOSC_0
	Local_Timer=(f32)(256*(1/F_CPU))*Timer_u8Counter;
#elif TIMER0_PRESCALER==FOSC_8
	Local_Timer=(f32)(256*(8/F_CPU))*Timer_u8Counter;
#elif TIMER0_PRESCALER==FOSC_64
	Local_Timer=(f32)(256*(64/F_CPU))*Timer_u8Counter;
#elif TIMER0_PRESCALER==FOSC_256
	Local_Timer=(f32)(256*(256/F_CPU))*Timer_u8Counter;
#elif TIMER0_PRESCALER==FOSC_1024
	Local_Timer=((256*1024*Timer_u8Counter)/(F_CPU));
#endif

	return Local_Timer;
}

extern void TIMER_voidSetCounter(u8 Copy_u8Value) {
#if TIMER0_MODE==TIMER0_OVERFLOW

	TCNT0 = Copy_u8Value;

#elif TIMER0_MODE==TIMER0_OVERFLOW
	OCR0=CoCopy_u8Value;
	TCNT0=0;
#endif

	return;
}

extern void TIMER_voidCheckFlag(void) {

#if TIMER0_MODE==TIMER0_OVERFLOW

	while (!(TIFR & (1 << 0)))
		;
	TIFR |= (1 << 0);

#elif TIMER0_MODE==TIMER0_OVERFLOW

	while(!(TIFR &(1<<1)));
	TIFR|=(1<<1);

#endif
}

extern void TIMER_voidEnableOVInterrupt(void){
	TIMSK|=(1<<0);
	return;
}
extern void TIMER_voidEnableCTCInterrupt(void){
	TIMSK|=(1<<1);
	return;
}
extern void TIMER_voidDisableOVInterrupt(void){
	TIMSK&=~(1<<0);
	return ;
}
extern void TIMER_voidDisableCTCInterrupt(void){
	TIMSK&=~(1<<1);
	return ;
}
extern void TIMER_voidClearTimer(void){
	Timer_u8Counter=0;
}
extern void TIMER_voidSetOVISR(void (*Copy_PtrToFun)(void)){

	PtrToOVISR=Copy_PtrToFun;

}
extern void TIMER_voidSetCTCISR(void (*Copy_PtrToFun)(void)){

	PtrToCTCISR=Copy_PtrToFun;
}



ISR(__vector_11){
	Timer_u8Counter++;
	PtrToOVISR();


}


ISR(__vector_10 ){
	Timer_u8Counter++;
	PtrToCTCISR();

}

