/*
 * SPI_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "util.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "DIO_interface.h"


static u8 SPI_u8Data;

static void (*PtrToIRQ)(void);

extern void SPI_voidInit(void) {
	SPCR |= SPI_MODE | SPI_CPOL | SPI_CPHA | (SPI_CLOCK_RATE & 0x03)
			| SPI_DATA_ORDER;
	SPSR |= (SPI_CLOCK_RATE & 0x04) >> 1;
	SPI_u8Data=0;
	return;
}

extern void SPI_voidEnable(void) {
	SPCR |= (1 << 6);
	return;
}

extern void SPI_voidDisable(void) {
	SPCR &= ~(1 << 6);
	return;
}

void SPI_voidInterruptEnable(void) {
	sei();
	SPCR |= (1 << 7);
	return;
}

extern void SPI_voidInterruptDisable(void) {

	cli();
	SPCR &= ~(1 << 7);

	return;
}
extern void SPI_voidMasterMode(u8 Copy_u8Status) {

	ASSIGN_BIT(SPCR, 4, Copy_u8Status);

	return;
}
extern void SPI_MasterInit(void) {
	/* Set MOSI and SCK output, all others input */
	DIO_u8WritePinDir(DIO_u8PIN12, DIO_u8HIGH);
	DIO_u8WritePinDir(DIO_u8PIN13, DIO_u8HIGH);
	DIO_u8WritePinDir(DIO_u8PIN14, DIO_u8LOW);
	DIO_u8WritePinDir(DIO_u8PIN15, DIO_u8HIGH);

	return;
}

extern void SPI_SlaveInit(void) {
	/* Set MOSI and SCK output, all others input */
	DIO_u8WritePinDir(DIO_u8PIN12, DIO_u8LOW);
	DIO_u8WritePinDir(DIO_u8PIN13, DIO_u8LOW);
	DIO_u8WritePinDir(DIO_u8PIN14, DIO_u8HIGH);
	DIO_u8WritePinDir(DIO_u8PIN15, DIO_u8LOW);

	return;
}

extern void SPI_voidSendData(u8 Copy_u8Data) {

	SPDR = Copy_u8Data;

	while (!(SPSR & (1 << 7)))
		;

	return;
}

extern u8 SPI_voidReceiveData(void) {

	if ((SPSR & (1 << 7)))
	{
		SPI_u8Data=SPDR;
	}


	return SPI_u8Data;
}
extern void SPI_voidInterruptSendData(u8 Copy_u8Data){

	SPDR=Copy_u8Data;

	return ;
}

extern u8 SPI_voidInterruptReceiveData(void) {


	return SPDR;
}

extern void SPI_voidSetISR(void (*PtrToISR)(void)){

	PtrToIRQ=PtrToISR;

	return;
}

ISR(SPI_STC_vect){

   PtrToIRQ();

}


