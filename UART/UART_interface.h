/*
 * UART_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
/*Comment!:UART initialization */
extern void UART_voidInit(void);
/*Comment!:Enable Transmission whether in polling or interrupt  */
extern void UART_voidTxEnable(void);
/*Comment!:Enable reception whether in polling or interrupt  */
extern void UART_voidRxEnable(void);
/*Comment!:Send one character  */
extern void UART_voidSend(u8 Copy_u8Char);
/*Comment!:Receive one character  */
extern u8 UART_u8Receive (void);
/*Comment!:send one character on interrupt  */
extern void UART_voidInteruptSend(u8 Copy_u8Char);
/*Comment!:Receive one character on interrupt  */
extern u8 UART_u8InterruptReceive(void);
/*Comment!:Send a String  */
extern void UART_voidSendString(u8 *Copy_u8PtrToStr);
/*Comment!:Call back function for the interrupt handler */
extern void UART_voidISR(void (*Copy_PtrToISR)(void));





#endif /* UART_INTERFACE_H_ */
