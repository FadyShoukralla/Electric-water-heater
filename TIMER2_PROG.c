/*
 * TIMER2_PROG.c
 *
 * Created: 6/29/2024 9:40:10 PM
 *  Author: mrfed
 */ 

#include "BIT_MATH.h"
#include "TIMER2_INT.h"


void TIMER2_start(u8 prescaler)
{
	if (prescaler == TIMER2_DIV0)
	{
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
	}
	else if (prescaler == TIMER2_DIV8)
	{
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
	}
	else if (prescaler == TIMER2_DIV32)
	{
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
	}
	else if (prescaler == TIMER2_DIV64)
	{
		CLEAR_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
	}
	else if (prescaler == TIMER2_DIV128)
	{
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
	}
	else if (prescaler == (TIMER2_DIV256))
	{
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
	}
	else if (prescaler == TIMER2_DIV1024)
	{
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
	}
	else if (prescaler == TIMER2_EXT_RIS)
	{
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
	}
}

void TIMER2_initCtc()
{
	//select ctc mode
	CLEAR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	//enable
	SET_BIT(TIMSK,OCIE2);
}

void (*TIMER2_CtcFunc)();

void TIMER2_setCallbackCtc(void(*func)())
{
	TIMER2_CtcFunc =func;
}

//num(in vector table)-1
void __vector_4() __attribute__((signal));
void __vector_4()
{
	TIMER2_CtcFunc();
}

void TIMER2_setOcr(u8 value)
{
	OCR2 = value;
}