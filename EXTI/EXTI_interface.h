/*
 * EXTI_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



extern void EXTI_voidInit(void);
extern void EXTI_voidINT0Enable(void);
extern void EXTI_voidINT1Enable(void);
extern void EXTI_voidINT2Enable(void);
extern void EXTI_voidINT0Disable(void);
extern void EXTI_voidINT1Disable(void);
extern void EXTI_voidINT2Disable(void);
extern void EXTI_voidINT0SetISR(void (*Copy_ptrToISR)(void));
extern void EXTI_voidINT1SetISR(void (*Copy_ptrToISR)(void));
extern void EXTI_voidINT2SetISR(void (*Copy_ptrToISR)(void));


#endif /* EXTI_INTERFACE_H_ */
