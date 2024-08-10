/*
 * TIMER0_PROG.c
 *
 * Created: 6/29/2024 6:48:22 PM
 *  Author: mrfed
 */ 

#include "BIT_MATH.h"
#include "TIMER0_INT.h"


void TIMER0_start(u8 prescaler)
{
	if (prescaler == TIMER0_DIV0)
	{
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
	}
	else if (prescaler == TIMER0_DIV8)
	{
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
	}
	else if (prescaler == TIMER0_DIV64)
	{
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
	}
	else if (prescaler == TIMER0_DIV256)
	{
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}
	else if (prescaler == TIMER0_DIV1024)
	{
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}
	else if (prescaler == TIMER0_EXT_RIS)
	{
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}
}



void TIMER0_initCtc()
{
	//select ctc mode
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	//enable
	SET_BIT(TIMSK,OCIE0);
}

void (*TIMER0_CtcFunc)();

void TIMER0_setCallbackCtc(void(*func)())
{
	TIMER0_CtcFunc =func;
}

//num(in vector table)-1
void __vector_10() __attribute__((signal));
void __vector_10()
{
	TIMER0_CtcFunc();
}

void TIMER0_setOcr(u8 value)
{
	OCR0 = value;
}