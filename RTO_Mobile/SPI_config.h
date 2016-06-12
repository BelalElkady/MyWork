/*
 * SPI_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*Comment!:SPI Mode (MASTER , SLAVE)*/
#define SPI_MODE			SLAVE
/*Comment!:SPI Clock polarity  (RISING , FALLING)*/
#define SPI_CPOL			RISING
/*Comment!:SPI Clock phase (SAMPLE , SETUP)*/
#define SPI_CPHA			SAMPLE
/*Comment!:SPI Clock Rate (FOSC4 ,FOSC16,FOSC64 ,FOSC128 , FOSC2 ,FOSC8 , FOSC32 )*/
#define SPI_CLOCK_RATE		FOSC4
/*Comment!:SPI Data order (MSB , LSBs)*/
#define SPI_DATA_ORDER		MSB



#endif /* SPI_CONFIG_H_ */
