/*
 * TIMER2_INT.h
 *
 * Created: 6/29/2024 9:39:45 PM
 *  Author: mrfed
 */ 


#ifndef TIMER2_INT_H_
#define TIMER2_INT_H_

#include "STD_TYPES.h"

//Timer/Counter Control Register
#define TCCR2	*((volatile u8*)0x45)
#define FOC2		7
#define WGM20		6
#define COM21		5
#define COM20		4
#define WGM21		3
#define CS22		2
#define CS21		1
#define CS20		0

//Timer/Counter Register
#define TCNT2 		*((volatile u8*)0x44)

//Output Compare Register
#define OCR2 		*((volatile u8*)0x5C)

//Timer/Counter Interrupt Mask
#define TIMSK 		*((volatile u8*)0x59)
#define TOIE0		0
#define OCIE0		1
#define TOIE1		2
#define OCIE1B		3
#define OCIE1A		4
#define TICIE1		5
#define TOIE2		6
#define OCIE2		7


#define TIMER2_DIV0			0
#define TIMER2_DIV8			1
#define TIMER2_DIV32		2
#define TIMER2_DIV64		3
#define TIMER2_DIV128		4
#define TIMER2_DIV256		5
#define TIMER2_DIV1024		6
#define TIMER2_EXT_RIS		7

#define TIMER2_NON_INVERTED	0
#define TIMER2_INVERTED		1
#define TIMER2_PWM_MODE TIMER2_NON_INVERTED

void TIMER2_start(u8 prescaler);
void TIMER2_initCtc();
void TIMER2_setCallbackCtc(void(*func)());
void TIMER2_setOcr(u8 value);

#endif /* TIMER2_INT_H_ */