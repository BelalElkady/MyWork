/*
 * SHIFT_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#include "types.h"

#include "DIO_config.h"

#include "DIO_interface.h"

#include "SHIFT_config.h"

#include "SHIFT_interface.h"

#include "DELAY.h"

extern void SHIFT_u8WriteVal(u8 Copy_u8ShiftVal){

	int Local_u8Counter;
	for (Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++){

      DIO_u8WritePinVal(SHIFT_DS,(Copy_u8ShiftVal>>Local_u8Counter)&0x01);
      DIO_u8WritePinVal(SHIFT_SH_CP,DIO_u8HIGH);
      DIO_u8WritePinVal(SHIFT_SH_CP,DIO_u8LOW);

	}




      return ;

}

extern void SHIFT_u8WriteLatch(void){



	DIO_u8WritePinVal(DIO_u8PIN18, DIO_u8HIGH);
	DIO_u8WritePinVal(DIO_u8PIN18, DIO_u8LOW);


	return;
}
