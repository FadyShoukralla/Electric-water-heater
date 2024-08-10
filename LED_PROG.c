/*
 * LED_PROG.c
 *
 * Created: 7/12/2024 5:13:04 PM
 *  Author: mrfed
 */ 

#include "LED_INT.h"

void LED_init ()
{
	DIO_setPinDir(LED,DIO_OUTPUT);				//LED
}

void LED_ON ()
{
	DIO_setPinValue(LED ,On);			//LED ON
}

void LED_OFF ()
{
	DIO_setPinValue(LED ,Off);			//LED OFF
}