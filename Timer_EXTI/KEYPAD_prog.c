/*
 * KEYPAD_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "types.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "DIO_config.h"
#include "DIO_interface.h"


static const u8 KEYPAD_u8RowsArr[KEYPAD_ROWS_NUM]={KEYPAD_R1,KEYPAD_R2,KEYPAD_R3,KEYPAD_R4};
static const u8 KEYPAD_u8ColsArr[KEYPAD_COLS_NUM]={KEYPAD_C1,KEYPAD_C2,KEYPAD_C3,KEYPAD_C4};

extern void KEYPAD_voidRead(u8 * Copy_u8PtrToVal) {
	u8 Local_u8RowCounter=0;
	u8 Local_u8ColCounter=0;
	u8 Local_u8RowVal;
	u8 Local_u8Flag=0;

	DIO_u8WritePortDir(DIO_u8PORT0,0xf0);
	for (Local_u8ColCounter=0;Local_u8ColCounter< KEYPAD_COLS_NUM && Local_u8Flag!=1 ; Local_u8ColCounter++ ){

		DIO_u8WritePortVal(DIO_u8PORT0,0xf0&(0x10<<Local_u8ColCounter));

	      for (Local_u8RowCounter=0;Local_u8RowCounter< KEYPAD_ROWS_NUM && Local_u8Flag!=1 ; Local_u8RowCounter++ ){

	    	  	  DIO_u8ReadPortVal(DIO_u8PORT0,&Local_u8RowVal);

	    	  	  if ((Local_u8RowVal&(0x08>>Local_u8RowCounter))!=0){

	    	  		* Copy_u8PtrToVal=Local_u8ColCounter+(4*Local_u8RowCounter)+1;
	    	  		Local_u8Flag=1;

	    	 	  }
	    	  	  else {
	    	  		* Copy_u8PtrToVal=0;
	    	  	  }




			}

	}

	return;
}

