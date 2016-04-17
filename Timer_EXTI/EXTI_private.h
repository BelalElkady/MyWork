/*
 * EXTI_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR   *((volatile u8 *) 0x55)
#define MCUCSR	*((volatile u8 *) 0x54)
#define GICR	*((volatile u8 *) 0x5B)
#define GIFR	*((volatile u8 *) 0x5A)

#define INT0_ENBALE			0x40
#define INT0_DISABLE		0x00

#define INT1_ENBALE			0x80
#define INT1_DISABLE		0x00


#define INT2_ENBALE			0x20
#define INT2_DISABLE		0x00


#define INT0_LOW_LEVEL		0x00
#define INT0_ON_CHANGE		0x01
#define INT0_FALLING_EDGE	0x02
#define INT0_RISING_EDGE	0x03



#define INT1_LOW_LEVEL		0x00
#define INT1_ON_CHANGE		0x04
#define INT1_FALLING_EDGE	0x08
#define INT1_RISING_EDGE	0x0C


#define INT2_FALLING_EDGE	0x00
#define INT2_RISING_EDGE	0x40



#endif /* EXTI_PRIVATE_H_ */
