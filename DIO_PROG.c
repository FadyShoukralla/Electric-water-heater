/*
 * DIO_PROG.c
 *
 * Created: 6/29/2024 6:15:45 PM
 *  Author: mrfed
 */ 

#include "BIT_MATH.h"
#include "DIO_INT.h"


void DIO_setPinValue (u8 pinNum, u8 level)
{
	//PORTA
	if (pinNum>=0 && pinNum<=7)
	{
		if (level == DIO_LOW)
		{
			CLEAR_BIT(PORTA,pinNum);
		}
		else if (level == DIO_HIGH)
		{
			SET_BIT(PORTA,pinNum);
		}
	}
	//PORTB
	if (pinNum>=8 && pinNum<=15)
	{
		pinNum=pinNum-8;
		if (level == DIO_LOW)
		{
			CLEAR_BIT(PORTB,pinNum);
		}
		else if (level == DIO_HIGH)
		{
			SET_BIT(PORTB,pinNum);
		}
	}
	//PORTC
	if (pinNum>=16 && pinNum<=23)
	{
		pinNum=pinNum-16;
		if (level == DIO_LOW)
		{
			CLEAR_BIT(PORTC,pinNum);
		}
		else if (level == DIO_HIGH)
		{
			SET_BIT(PORTC,pinNum);
		}
	}
	//PORTD
	if (pinNum>=24 && pinNum<=31)
	{
		pinNum=pinNum-24;
		if (level == DIO_LOW)
		{
			CLEAR_BIT(PORTD,pinNum);
		}
		else if (level == DIO_HIGH)
		{
			SET_BIT(PORTD,pinNum);
		}
	}
}

void DIO_setPinDir (u8 pinNum, u8 dir)
{
	//PORTA
	if (pinNum>=0 && pinNum<=7)
	{
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DDRA,pinNum);
		}
		else if (dir == DIO_OUTPUT)
		{
			SET_BIT(DDRA,pinNum);
		}
	}
	//PORTB
	if (pinNum>=8 && pinNum<=15)
	{
		pinNum=pinNum-8;
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DDRB,pinNum);
		}
		else if (dir == DIO_OUTPUT)
		{
			SET_BIT(DDRB,pinNum);
		}
	}
	//PORTC
	if (pinNum>=16 && pinNum<=23)
	{
		pinNum=pinNum-16;
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DDRC,pinNum);
		}
		else if (dir == DIO_OUTPUT)
		{
			SET_BIT(DDRC,pinNum);
		}
	}
	//PORTD
	if (pinNum>=24 && pinNum<=31)
	{
		pinNum=pinNum-24;
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DDRD,pinNum);
		}
		else if (dir == DIO_OUTPUT)
		{
			SET_BIT(DDRD,pinNum);
		}
	}
}

u8 DIO_readPinValue (u8 pinNum)
{
	//PORTA
	if (pinNum>=0 && pinNum<=7)
	{
		return GET_BIT(PINA,pinNum);
	}
	//PORTB
	else if (pinNum>=8 && pinNum<=15)
	{
		pinNum=pinNum-8;
		return GET_BIT(PINB,pinNum);
	}
	//PORTC
	else if (pinNum>=16 && pinNum<=23)
	{
		pinNum=pinNum-16;
		return GET_BIT(PINC,pinNum);
	}
	//PORTD
	else if (pinNum>=24 && pinNum<=31)
	{
		pinNum=pinNum-24;
		return GET_BIT(PIND,pinNum);
	}
}

void DIO_setPullUp (u8 pinNum)
{
	DIO_setPinValue(pinNum, DIO_HIGH);
}

void DIO_togglePinValue (u8 pinNum)
{
	DIO_setPinValue(pinNum, !DIO_readPinValue(pinNum));
}