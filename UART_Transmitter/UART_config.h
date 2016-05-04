/*
 * UART_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*Comment!:frequency oscillator for the MCU */
#define F_CPU                    4000000UL
/*Comment!:Parity (EVEN, ODD and NONE)*/
#define UART_PARITY	             NONE
/*Comment!:Baudrate (UART1200, UART2400,UART4800,UART9600 and UART19200)*/
#define UART_BAUDRATE            UART9600
/*Comment!:Stop bits  (ONE_BIT and TWO_BIT)*/
#define UART_STOPBITS             ONE_BIT
/*Comment!:Data bits  (FIVE_BITS, SIX_BITS ,SEVEN_BITS,EIGHT_BITS and NINE_BITS)*/
#define UART_DATABITS            EIGHT_BITS
/*Comment!:Enable/Disable reception interrupt (ENABLE and  DISBALE)*/
#define UART_Receiver_Interrupt    ENABLE
/*Comment!:Enable/Disable data register empty interrupt (ENABLE and  DISBALE)*/
#define UART_Transmitter_Interrupt DISBALE

#endif /* UART_CONFIG_H_ */
