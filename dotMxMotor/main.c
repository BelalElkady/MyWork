#include "types.h"
#include "DIO_interface.h"
#include "TACTILE_Interface.h"
#include "SHIFT_interface.h"
#include "KEYPAD_interface.h"
#include "App.h"
#include "DELAY.h"

void main(void) {



	DIO_voidInit();
	App_voidInit();

	while (1) {



	  App_voidStepperSpeed();
	    	//App_voidDotMotor();
		//App_voidDisplayLetter(App_u8Stop);


		}

		return;

	}
