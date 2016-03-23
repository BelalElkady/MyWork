/*
 * ADC_app.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: Belal
 */
#include "types.h"
#include "util.h"
#include "ADC_interface.h"
#include "DIO_interface.h"


void main (void)
{
	u16 Local_u8AdcResult=0;
	DIO_voidInit();
	ADC_voidConfig();
	ADC_voidEnable();
	while (1)
	{


		ADC_voidReadMulShot(&Local_u8AdcResult);
    	DIO_u8WritePortVal(1,Local_u8AdcResult);
 		DIO_u8WritePortVal(2,Local_u8AdcResult>>8);


	}
	return ;
}


