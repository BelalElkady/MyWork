/*
 * DIO_private.h
 *
 *  Created on: ??�/??�/????
 *      Author: Belal
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define    PORTA        (*(volatile u8 *)0x3B)
#define    PORTB        ((volatile u8 *)0x38)
#define    PORTC        ((volatile u8 *)0x35)
#define    PORTD        ((volatile u8 *)0x32)

#define    PINA        ((volatile u8 *)0x39)
#define    PINB        ((volatile u8 *)0x36)
#define    PINC        ((volatile u8 *)0x33)
#define    PIND        ((volatile u8 *)0x30)

#define    DDRA        ((volatile u8 *)0x3A)
#define    DDRB        ((volatile u8 *)0x37)
#define    DDRC        ((volatile u8 *)0x34)
#define    DDRD        ((volatile u8 *)0x31)

#define DIO_u8PORTSIZE 8
#define DIO_u8PORTNUMBERS 4
#define DIO_u8PINNUMBERS 32


#define CONC(A7,A6,A5,A4,A3,A2,A1,A0)            conc_helper(A7,A6,A5,A4,A3,A2,A1,A0)
#define conc_helper(x7,x6,x5,x4,x3,x2,x1,x0)     0b##x7##x6##x5##x4##x3##x2##x1##x0

#define DIO_u8PORTA_DIR CONC(DIO_u8PIN_INITDIR7,DIO_u8PIN_INITDIR6,DIO_u8PIN_INITDIR5,DIO_u8PIN_INITDIR4,DIO_u8PIN_INITDIR3,DIO_u8PIN_INITDIR2,DIO_u8PIN_INITDIR1,DIO_u8PIN_INITDIR0)
#define DIO_u8PORTB_DIR CONC(DIO_u8PIN_INITDIR15,DIO_u8PIN_INITDIR14,DIO_u8PIN_INITDIR13,DIO_u8PIN_INITDIR12,DIO_u8PIN_INITDIR11,DIO_u8PIN_INITDIR10,DIO_u8PIN_INITDIR9,DIO_u8PIN_INITDIR8)
#define DIO_u8PORTC_DIR CONC(DIO_u8PIN_INITDIR23,DIO_u8PIN_INITDIR22,DIO_u8PIN_INITDIR21,DIO_u8PIN_INITDIR20,DIO_u8PIN_INITDIR19,DIO_u8PIN_INITDIR18,DIO_u8PIN_INITDIR17,DIO_u8PIN_INITDIR16)
#define DIO_u8PORTD_DIR CONC(DIO_u8PIN_INITDIR31,DIO_u8PIN_INITDIR30,DIO_u8PIN_INITDIR29,DIO_u8PIN_INITDIR28,DIO_u8PIN_INITDIR27,DIO_u8PIN_INITDIR26,DIO_u8PIN_INITDIR25,DIO_u8PIN_INITDIR24)

#define DIO_u8PORTA_VAL CONC(DIO_u8PIN_INITVAL7,DIO_u8PIN_INITVAL6,DIO_u8PIN_INITVAL5,DIO_u8PIN_INITVAL4,DIO_u8PIN_INITVAL3,DIO_u8PIN_INITVAL2,DIO_u8PIN_INITVAL1,DIO_u8PIN_INITVAL0)
#define DIO_u8PORTB_VAL CONC(DIO_u8PIN_INITVAL15,DIO_u8PIN_INITVAL14,DIO_u8PIN_INITVAL13,DIO_u8PIN_INITVAL12,DIO_u8PIN_INITVAL11,DIO_u8PIN_INITVAL10,DIO_u8PIN_INITVAL9,DIO_u8PIN_INITVAL8)
#define DIO_u8PORTC_VAL CONC(DIO_u8PIN_INITVAL23,DIO_u8PIN_INITVAL22,DIO_u8PIN_INITVAL21,DIO_u8PIN_INITVAL20,DIO_u8PIN_INITVAL19,DIO_u8PIN_INITVAL18,DIO_u8PIN_INITVAL17,DIO_u8PIN_INITVAL16)
#define DIO_u8PORTD_VAL CONC(DIO_u8PIN_INITVAL31,DIO_u8PIN_INITVAL30,DIO_u8PIN_INITVAL29,DIO_u8PIN_INITVAL28,DIO_u8PIN_INITVAL27,DIO_u8PIN_INITVAL26,DIO_u8PIN_INITVAL25,DIO_u8PIN_INITVAL24)

#endif /* DIO_PRIVATE_H_ */
