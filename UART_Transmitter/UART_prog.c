/*
 * UART_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "interrupt.h"

static void (*PtrToSendingISR)(void);
static void (*PtrToReciveingISR)(void);


extern void UART_voidInit(void) {

	u16 Local_u16UBRR = 0;
	UCSRC |= UART_PARITY | UART_STOPBITS | (UART_DATABITS & 0x06) | 0x80;

	UCSRB |= (UART_DATABITS & 0x08) >> 1;

	Local_u16UBRR = (F_CPU / (16UL * UART_BAUDRATE));

	UBRRL = (u8) Local_u16UBRR;

	UBRRH = Local_u16UBRR >> 8;

	return;
}

extern void UART_voidTxEnable(void) {

	UCSRB |= (1 << 3);

#if (UART_Transmitter_Interrupt == ENABLE)
	UCSRB |= (1 << 5);
	__asm__("sei");	//enable global interrupt
#elif (UART_Transmitter_Interrupt == DISBALE)
	UCSRB &=~ (1 << 5);
#endif

	return;
}

extern void UART_voidRxEnable(void) {

	UCSRB |= (1 << 4);

#if (UART_Receiver_Interrupt == ENABLE)
	UCSRB |= (1 << 7);
	__asm__("sei");    //enable global interrupt
#elif (UART_Receiver_Interrupt == DISBALE)
	UCSRB &=~ (1 << 7);
#endif

	return;
}



extern void UART_voidSend(u8 Copy_u8Char) {

	while (!(UCSRA & (1 << 5)))
		;

	UDR = Copy_u8Char;

	return;
}

extern u8 UART_u8Receive(void) {

	while (!(UCSRA & (1 << 7)))
		;

	return UDR;
}

extern void UART_voidInteruptSend(u8 Copy_u8Char) {


	UDR = Copy_u8Char;

	return;
}


extern u8 UART_u8InterruptReceive(void) {

	return UDR;
}


extern void UART_voidSendString(u8 *Copy_u8PtrToStr) {
	u8 Local_u8Counter;
	for (Local_u8Counter = 0; Copy_u8PtrToStr != '\0'; Local_u8Counter++) {

		UART_voidSend(Copy_u8PtrToStr[Local_u8Counter]);

	}

	return;
}

extern void UART_voidSendISR(void (*Copy_PtrToISR)(void)){


	PtrToSendingISR=Copy_PtrToISR;

    return  ;
}
extern void UART_voidReceiveISR(void (*Copy_PtrToISR)(void)){


	PtrToReciveingISR=Copy_PtrToISR;

    return  ;
}

ISR (__vector_13){
	PtrToReciveingISR();
}

ISR (__vector_14){

	PtrToSendingISR();

}

