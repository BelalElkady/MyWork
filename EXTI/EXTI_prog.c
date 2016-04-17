/*
 * EXTI_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "util.h"
#include "types.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "interrupt.h"


static void (*ptrToINT0ISR)(void);
static void (*ptrToINT1ISR)(void);
static void (*ptrToINT2ISR)(void);

extern void EXTI_voidInit(void){

	GICR|=EXTI_INT0_ENABLE|EXTI_INT1_ENABLE|EXTI_INT2_ENABLE;
	MCUCR|=EXTI_INT0_TRIG|EXTI_INT1_TRIG;
	MCUCSR|=EXTI_INT2_TRIG;

	return ;
}
extern void EXTI_voidINT0Enable(void){
	SET_BIT(GICR,6);

	return ;
}
extern void EXTI_voidINT1Enable(void){
	SET_BIT(GICR,7);
	return ;
}
extern void EXTI_voidINT2Enable(void){
	SET_BIT(GICR,5);
	return ;
}
extern void EXTI_voidINT0Disable(void){
	CLR_BIT(GICR,6);
	return ;
}
extern void EXTI_voidINT1Disable(void){
	CLR_BIT(GICR,7);
	return ;
}
extern void EXTI_voidINT2Disable(void){
	CLR_BIT(GICR,5);
	return ;
}
extern void EXTI_voidINT0SetISR(void (*Copy_ptrToISR)(void)){
	ptrToINT0ISR=Copy_ptrToISR;
	return;
}
extern void EXTI_voidINT1SetISR(void (*Copy_ptrToISR)(void)){
	ptrToINT1ISR=Copy_ptrToISR;
	return;
}
extern void EXTI_voidINT2SetISR(void (*Copy_ptrToISR)(void)){
	ptrToINT2ISR=Copy_ptrToISR;
}
ISR(__vector_1){
	ptrToINT0ISR();

}
ISR(__vector_2){
	ptrToINT1ISR();

}
ISR(__vector_3){
	ptrToINT2ISR();

}

