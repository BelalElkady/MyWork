/*
 * TIMER_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#define OCR0    *((volatile u8 *)0x5C)
#define	TIMSK	*((volatile u8 *)0x59)
#define	TIFR	*((volatile u8 *)0x58)
#define	TCCR0	*((volatile u8 *)0x53)
#define	TCNT0	*((volatile u8 *)0x52)


#define TIMER0_OVERFLOW	    0x00
#define TIMER0_CTC			0x08

#if  (TIMER0_MODE==TIMER0_OVERFLOW)
#define ENABLE_INTERRUPT	0x01
#elif (TIMER0_MODE==TIMER0_CTC)
#define ENABLE_INTERRUPT	0x02
#endif
#define DISABLE_INTERRUPT	0x00

#define FOSC_0          0x01
#define FOSC_8          0x02
#define FOSC_64         0x03
#define FOSC_256        0x04
#define FOSC_1024       0x05
#define COUNTER_FALLING 0x05
#define COUNTER_RISING  0x07
#endif /* TIMER_PRIVATE_H_ */
