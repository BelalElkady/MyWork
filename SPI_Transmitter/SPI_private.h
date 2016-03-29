/*
 * SPI_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR *((volatile u8 *)0x2D)
#define SPSR *((volatile u8 *)0x2E)
#define SPDR *((volatile u8 *)0x2F)

typedef enum {
	MASTER = 0x10, SLAVE = 0x00
} MODE;

typedef enum {
	LSB = 0x20, MSB = 0x00
} ORDER;

typedef enum {
	FALLING = 0x08, RISING = 0x00
} POLARIY;

typedef enum {
	SETUP = 0x40, SAMPLE = 0x00
} PHASE;

typedef enum {
	FOSC4 = 0x00,
	FOSC16 = 0x01,
	FOSC64 = 0x02,
	FOSC128 = 0x03,
	FOSC2 = 0x04,
	FOSC8 = 0x05,
	FOSC32 = 0x06,


} CLOCK_RATE;


#endif /* SPI_PRIVATE_H_ */
