/*
 * ADC_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADMUX  ((volatile u8 *)0x27)
#define ADCSRA ((volatile u8 *)0x26)
#define ADCH   ((volatile u8 *)0x25)
#define ADCL   ((volatile u8 *)0x24)
#define ADC 	((volatile u16 *)0x24)
#define SFIOR   ((volatile u8 *)0x50)


/*Comment!:ADMUX ADC Multiplexer Selection Register pins */
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define REFERENCE_SELECTION_OPTIONS    3
#define REFERENCE_SELECTION_BITS       2

#define ADC_PRESCAL2	0
#define ADC_PRESCAL2_1	1
#define ADC_PRESCAL4	2
#define ADC_PRESCAL8	3
#define ADC_PRESCAL16	4
#define ADC_PRESCAL32	5
#define ADC_PRESCAL64	6
#define ADC_PRESCAL128	7
#define ADC_PRESCALER_OPTIONS  8
#define ADC_PRESCALER_BITS     3




/*Comment!:ADCSRA ADC Control and Status Register A pins */
#define ADEN  7
#define ADSC  6
#define ADATE 5
#define ADIF  4
#define ADIE  3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

/*Comment!:SFIOR Special FunctionIO Register */
#define ADTS2 7
#define ADTS1 6
#define ADTS0 5


/*Comment!:Number of channels */
#define ADC_u8CHANNELSNUMBER 8


/*Comment!: ADC voltage references */
#define AREF      0
#define AVCC      1
#define INRERNAL  2


/*Comment!: ADC result adjusting  */
#define RIGHT_ADJSUTED 0
#define LEFT_ADJSUTED  1


/*Comment!: ADC Channel */
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
#define CHANNEL_SELECTION_BITS         5

/*Comment!: ADC Channel Mode */
#define SINGLE_ENDED_INPUT 0
#define DIFFERENTIAL_INPUT 1



#define ENABLE  1
#define DISABLE 0

#endif /* ADC_PRIVATE_H_ */
