/*
 * ADC_INT.h
 *
 * Created: 6/29/2024 6:12:45 PM
 *  Author: mrfed
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
/*ADC Registers*/
#define ADMUX 				*((volatile u8*)0x27)
#define REFS1	7	//reference
#define REFS0	6	//reference

#define MUX4	4	//channel select
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

#define ADCSRA 				*((volatile u8*)0x26)
#define ADEN	7	//enable
#define ADSC	6 	//start conversion
#define ADPS2   2	//Prescaler
#define ADPS1   1	//Prescaler
#define ADPS0   0	//Prescaler


#define ADCH 				*((volatile u8*)0x25)//low bits only
#define ADCL 				*((volatile u8*)0x24)//high bits only
#define ADCLH				*((volatile u16*)0x24)//all bits..(u16)

///////////////////////////////////////////////////////////////

#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4		4
#define ADC_CH5		5
#define ADC_CH6		6
#define ADC_CH7		7




/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

void ADC_init();

u16 ADC_read(u8 chNum);//return digital

f32 ADC_convertAnalog(u16 digitalValue);//return analog

#endif /* ADC_INT_H_ */