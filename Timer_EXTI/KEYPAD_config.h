/*
 * KEYPAD_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


typedef struct{
	u16 KEYPAD_sw1:1;
	u16 KEYPAD_sw2:1;
	u16 KEYPAD_sw3:1;
	u16 KEYPAD_sw4:1;
	u16 KEYPAD_sw5:1;
	u16 KEYPAD_sw6:1;
	u16 KEYPAD_sw7:1;
	u16 KEYPAD_sw8:1;
	u16 KEYPAD_sw9:1;
	u16 KEYPAD_sw10:1;
	u16 KEYPAD_sw11:1;
	u16 KEYPAD_sw12:1;
	u16 KEYPAD_sw13:1;
	u16 KEYPAD_sw14:1;
	u16 KEYPAD_sw15:1;
	u16 KEYPAD_sw16:1;
}KEYPAD;


////////////////////////KEYPAD macros//////////////////////////////

#define KEYPAD_ROWS_NUM  4
#define KEYPAD_COLS_NUM  4



///////////////////////KEYPAD rows///////////////////////////////

#define KEYPAD_R1 DIO_u8PIN0
#define KEYPAD_R2 DIO_u8PIN1
#define KEYPAD_R3 DIO_u8PIN2
#define KEYPAD_R4 DIO_u8PIN3


///////////////////////KEYPAD cols///////////////////////////////
#define KEYPAD_C1 DIO_u8PIN4
#define KEYPAD_C2 DIO_u8PIN5
#define KEYPAD_C3 DIO_u8PIN6
#define KEYPAD_C4 DIO_u8PIN7


#endif /* KEYPAD_CONFIG_H_ */
