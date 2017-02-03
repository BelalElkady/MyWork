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
	TIMSK |= TIMER0_OV_INTRRUPT |  TIMER0_CTC_INTRRUPT;

	return;
}

extern f32  TIMER_u8SysTick(f32 Local_f32SetTick) {
	u16  Local_Timer;
	u16 NoOfOverFlow=0;

#if TIMER0_PRESCALER==FOSC_0
	//Local_Timer=((Local_f32SetTick)*(F_CPU))/(1UL*1000UL);
//		if (Local_Timer > 255 ){
//			NoOfOverFlow=((Local_f32SetTick)*(F_CPU))/(1UL*256UL*1000UL);
//		}
//		else {
			NoOfOverFlow=0;
		    TIMER_voidSetCounter(31);

	//	}

#elif TIMER0_PRESCALER==FOSC_8
	Local_Timer=((Local_u16SetTick)*(F_CPU))/(8UL*256UL)
#elif TIMER0_PRESCALER==FOSC_64
	Local_Timer=((Local_u16SetTick)*(F_CPU))/(64UL*256UL)
#elif TIMER0_PRESCALER==FOSC_256
	Local_Timer=((Local_u16SetTick)*(F_CPU))/(256UL*256UL);
#elif TIMER0_PRESCALER==FOSC_1024

	Local_Timer=((Local_f32SetTick)*(F_CPU))/(1024UL*1000UL);
	if (Local_Timer > 255 ){
		NoOfOverFlow=((Local_f32SetTick)*(F_CPU))/(1024UL*256UL*1000UL);


	}
	else {
		NoOfOverFlow=1;
	    TIMER_voidSetCounter(255-Local_Timer);

	}



#endif

	return NoOfOverFlow;
}

extern void TIMER_voidSetCounter(u8 Copy_u8Value) {
#if TIMER0_MODE==TIMER0_OVERFLOW

	TCNT0 = Copy_u8Value;

#elif TIMER0_MODE==TIMER0_CTC
	OCR0=Copy_u8Value;
	TCNT0=0;
#endif

	return;
}

extern void TIMER_voidCheckFlag(void) {

#if TIMER0_MODE==TIMER0_OVERFLOW

	while (!(TIFR & (1 << 0)))
		;
	TIFR |= (1 << 0);

#elif TIMER0_MODE==TIMER0_CTC

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

