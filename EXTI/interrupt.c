/*
 * interrupt.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#include "interrupt.h"
extern void Global_voidInterruptEnable(void){

	__asm__("SEI");
	return;
}

extern void Global_voidInterruptDisable(void){

	__asm__("CLI");
	return;
}
