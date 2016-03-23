/*
 * DELAY.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef DELAY_H_
#define DELAY_H_
#include "DELAY_config.h"

#define delay_ms(Copy_u8DelayVal)         do{u32 Local_u32Duration;\
											for(Local_u32Duration=(Copy_u8DelayVal*F_CPU)/3000UL;Local_u32Duration > 0;Local_u32Duration --)\
											{__asm__("NOP");}}while(0)


#endif /* DELAY_H_ */
