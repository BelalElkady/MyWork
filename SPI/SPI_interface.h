/*
 * SPI_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*Comment!:SPI Initialization */
extern void SPI_voidInit(void);
/*Comment!:SPI Enable */
extern void SPI_voidEnable(void);
/*Comment!:SPI Disable */
extern void SPI_voidDisable(void);
/*Comment!:SPI Interrupt Enable */
extern void SPI_voidInterruptEnable(void);
/*Comment!:SPI Interrupt Disable */
extern void SPI_voidInterruptDisable(void);
/*Comment!:SPI Master mode pins initialization  */
extern void SPI_MasterInit(void);
/*Comment!:SPI Slave mode pins initialization  */
extern void SPI_SlaveInit(void);
/*Comment!:SPI change Spi mode in run time ( 1= master , 0= Slave */
extern void SPI_voidMasterMode(u8 Copy_u8Status);
/*Comment!:SPI sending data in polling mode */
extern void SPI_voidSendData(u8 Copy_u8Data);
/*Comment!:SPI sending data in Interrupt  mode */
extern void SPI_voidInterruptSendData(u8 Copy_u8Data);
/*Comment!:SPI receiving data in polling mode */
extern u8 SPI_voidReceiveData(void);
/*Comment!:SPI receiving data in interrupt mode */
extern u8 SPI_voidInterruptReceiveData(void);
/*Comment!:SPI call back function to interrupt handling  */
extern void SPI_voidSetISR(void (*PtrToISR)(void));




#endif /* SPI_INTERFACE_H_ */
