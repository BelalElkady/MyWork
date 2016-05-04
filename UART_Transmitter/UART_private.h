/*
 * UART_privvate.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_



#define UDR   *((volatile u8 *)0x2C)
#define UCSRA *((volatile u8 *)0x2B)
#define UCSRB *((volatile u8 *)0x2A)
#define UCSRC *((volatile u8 *)0x40)
#define UBRRL *((volatile u8 *)0x29)
#define UBRRH *((volatile u8 *)0x40)



typedef enum {
	NONE = 0x00, EVEN = 0x20, ODD = 0x30

} UART_PARITY;

typedef enum {
	ONE_BIT = 0x00, TWO_BIT = 0x08
} UART_STOP;

typedef enum {
	FIVE_BITS = 0x00,
	SIX_BITS = 0x02,
	SEVEN_BITS = 0x04,
	EIGHT_BITS = 0x06,
	NINE_BITS = 0x0E,

} UART_CHARACTER_SIZE;


typedef enum {
	UART1200 = 1200UL,
	UART2400 = 2400UL,
	UART4800 = 4800UL,
	UART9600 = 9600UL,
	UART19200 = 19200UL


}UART_BAUD;


#define 	DISABLE 0
#define     ENABLE   1





#endif /* UART_PRIVATE_H_ */
