/*
 * BUTTON_PROG.c
 *
 * Created: 7/12/2024 4:49:35 PM
 *  Author: mrfed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "BUTTON_INT.h"


void Button_init()
{
	DIO_setPinDir(ONOFFBUTTON,DIO_INPUT);		//ONOFF Button
	DIO_setPinDir(UPBUTTON,DIO_INPUT);			//UP Button
	DIO_setPinDir(DOWNBUTTON,DIO_INPUT);		//DOWN Button
}

u8 UP_Button ()
{
	if ((DIO_readPinValue(UPBUTTON)) == On)
	{
		while ((DIO_readPinValue(UPBUTTON)) == On);
		return PRESSED;
	}
	else 
	{
		return UNPRESSED;
	}
}

u8 DOWN_Button ()
{
	if ((DIO_readPinValue(DOWNBUTTON)) == On)
	{
		while (DIO_readPinValue(DOWNBUTTON) == On);
		return PRESSED;
	}
	else 
	{
		return UNPRESSED;
	}
}