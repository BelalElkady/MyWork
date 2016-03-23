/*

 * TACTILE_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#include "types.h"

#include "TACTILE_Interface.h"

#include "TACTILE_Config.h"

#include "DIO_config.h"

#include "DIO_interface.h"

#include "DELAY.h"


extern void TACTILE_voidInit(void) {

}

extern u8 TACTILE_u8GetState(u8 Copy_u8SwitchNumber, u8* Copy_u8PtrToVal) {


	static u8 TACTILE_u8SwitchesState[TACTILE_u8SWITCHESNO]={TACTILE_u8Released};
	static u16 TACTILE_u8PressedCount[TACTILE_u8SWITCHESNO]={0};
	static u16 TACTILE_u8ReleasedCount[TACTILE_u8SWITCHESNO]={0};

	u8 Local_u8ReturnFlag = OK;

	u8 Local_u8ReadSW;



	if (Copy_u8SwitchNumber > TACTILE_u8SWITCHESNO-1) {
		Local_u8ReturnFlag = ERROR;
	} else {
		DIO_u8ReadPinVal(Copy_u8SwitchNumber, &Local_u8ReadSW);
		switch (TACTILE_u8SwitchesState[Copy_u8SwitchNumber]) {

		case TACTILE_u8Released:

			switch (Local_u8ReadSW) {
			case DIO_u8HIGH:
				TACTILE_u8SwitchesState[Copy_u8SwitchNumber] = TACTILE_u8Bounce;
				* Copy_u8PtrToVal = TACTILE_u8Released;
				break;
			case DIO_u8LOW:
				TACTILE_u8SwitchesState[Copy_u8SwitchNumber] = TACTILE_u8Released;
				* Copy_u8PtrToVal = TACTILE_u8Released;
			break;
			default:

				break;

			}

			break;
		case TACTILE_u8Pressed:

			switch (Local_u8ReadSW) {
			case DIO_u8LOW:
				TACTILE_u8SwitchesState[Copy_u8SwitchNumber] = TACTILE_u8Bounce;
				* Copy_u8PtrToVal = TACTILE_u8Pressed;
				break;
			case DIO_u8HIGH:
				TACTILE_u8SwitchesState[Copy_u8SwitchNumber] = TACTILE_u8Pressed;
				* Copy_u8PtrToVal = TACTILE_u8Pressed;
				break;
			default:

				break;

			}

			break;
		case TACTILE_u8Bounce:

					switch (Local_u8ReadSW) {
					case DIO_u8LOW:
						TACTILE_u8ReleasedCount[Copy_u8SwitchNumber]++;
						TACTILE_u8PressedCount[Copy_u8SwitchNumber] = 0;

						if (TACTILE_u8ReleasedCount[Copy_u8SwitchNumber] > TACTILE_u8DEBOUNCE_RANGE) {
							TACTILE_u8SwitchesState[Copy_u8SwitchNumber] = TACTILE_u8Released;
							* Copy_u8PtrToVal=TACTILE_u8Released;
						}


			    	break;
			case DIO_u8HIGH:
				TACTILE_u8PressedCount[Copy_u8SwitchNumber]++;
				TACTILE_u8ReleasedCount[Copy_u8SwitchNumber] = 0;

				if (TACTILE_u8PressedCount[Copy_u8SwitchNumber] > TACTILE_u8DEBOUNCE_RANGE) {

					TACTILE_u8SwitchesState[Copy_u8SwitchNumber] = TACTILE_u8Pressed;
					* Copy_u8PtrToVal=TACTILE_u8Pressed;

				}


				break;
			default:

				break;

			}

			break;

		}
		Local_u8ReturnFlag = OK;
	}

	return Local_u8ReturnFlag;

}

