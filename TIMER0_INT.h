/*
 * TIMER0_INT.h
 *
 * Created: 6/29/2024 6:48:36 PM
 *  Author: mrfed
 */ 


#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

#include "STD_TYPES.h"

//Timer/Counter Control Register
#define TCCR0	*((volatile u8*)0x53)
#define FOC0		7
#define WGM00		6
#define COM01		5
#define COM00		4
#define WGM01		3
#define CS02		2
#define CS01		1
#define CS00		0

//Timer/Counter Register
#define TCNT0 		*((volatile u8*)0x52)

//Output Compare Register
#define OCR0 		*((volatile u8*)0x5C)

//Timer/Counter Interrupt Mask
#define TIMSK 		*((volatile u8*)0x59)
#define OCIE0		1
#define TOIE0		0

#define TIMER0_DIV0			0
#define TIMER0_DIV8			1
#define TIMER0_DIV64		2
#define TIMER0_DIV256		3
#define TIMER0_DIV1024		4
#define TIMER0_EXT_RIS		5

#define TIMER0_NON_INVERTED	0
#define TIMER0_INVERTED		1
#define TIMER0_PWM_MODE TIMER0_NON_INVERTED

void TIMER0_start(u8 prescaler);
void TIMER0_initCtc();
void TIMER0_setCallbackCtc(void(*func)());
void TIMER0_setOcr(u8 value);

#endif /* TIMER0_INT_H_ */