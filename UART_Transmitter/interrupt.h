/*
 * interrupt.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_


#define ISR(vector,...) \
	void vector (void) __attribute__((signal,used,externally_visible)) __VA_ARGS__;\
	void vector (void)

extern void Global_voidInterruptEnable(void);
extern void Global_voidInterruptDisable(void);

#endif /* INTERRUPT_H_ */
