/*
 * SSD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/***********************************************************************/
/************************Numbers****************************************/
/***********************************************************************/
#define SSD_u8NUM0 0
#define SSD_u8NUM1 1
#define SSD_u8NUM2 2
#define SSD_u8NUM3 3
#define SSD_u8NUM4 4
#define SSD_u8NUM5 5
#define SSD_u8NUM6 6
#define SSD_u8NUM7 7
#define SSD_u8NUM8 8
#define SSD_u8NUM9 9


/***********************************************************************/
/************************Common Displays********************************/
/***********************************************************************/
#define SSD_u8DISP1 0
#define SSD_u8DISP2 1
#define SSD_u8DISP3 2
#define SSD_u8DISP4 3
#define SSD_u8DISP5 4
#define SSD_u8DISP6 5

/*Comment!: Common Anode or Cathode */
#define SSD_u8COMMAND  1
#define SSD_u8COMMCATH 0

/*Comment!: Display ON or OFF */
#define SSD_u8ONSTATE   1
#define SSD_u8OFFSTATE  0


/***********************************************************************/
/************************Public Functions*******************************/
/***********************************************************************/


/*Comment!: Display Init */
extern void SSD_voidInit(void);

/*Comment!: Display Value */
extern u8 SSD_u8Display(u8 Copy_u8DispIdx , u8 Copy_u8DispVal);

/*Comment!: Read Value */
extern u8 SSD_u8GetVal(u8 Copy_u8DispIdx , u8* Copy_u8DispVal);

/*Comment!: Turn On */
extern u8 SSD_u8TurnOn(u8 Copy_u8DispIdx);

/*Comment!: Turn Off */
extern u8 SSD_u8TurnOff(u8 Copy_u8DispIdx);
#endif /* SSD_INTERFACE_H_ */
