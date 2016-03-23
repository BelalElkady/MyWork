/*
 * LCD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


extern void LCD_voidInit(void);

extern void LCD_voidWriteCommand(u8);

extern void LCD_voidWriteData(u8);
extern void LCD_voidWriteNonAscii(void);
extern void LCD_voidWriteString(u8* Copy_u8PtrToString);
extern void LCD_voidWriteName(void);
extern void LCD_voidClearSceen(void);



#endif /* LCD_INTERFACE_H_ */
