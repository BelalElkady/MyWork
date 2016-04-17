/*
 * ADC_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

extern void ADC_voidEnable(void);
extern void ADC_voidDisable(void);
extern void ADC_voidConfig(void);
extern void ADC_voidReadSingleShot(u16 *Copy_ptrToVal);
extern void ADC_voidReadMulShot(u16 *Copy_ptrToVal);
extern void ADC_voidReadGrp(u8 *Copy_ptrToVal);




#endif /* ADC_INTERFACE_H_ */
