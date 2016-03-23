
#include "types.h"
#include "DIO_interface.h"
#include "TACTILE_Interface.h"



void main (void){



	u8 Local_u8SwVal , count=0;

	DIO_voidInit();


	while(1){

    TACTILE_u8GetState(TACTILE_u8Switch3,&Local_u8SwVal);
   if (Local_u8SwVal==1){

	   DIO_u8WritePinVal(16,1);
   }
   else {
	   DIO_u8WritePinVal(16,0);
   }



	}




}
