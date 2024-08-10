/*
 * HeaterCooler_PROG.c
 *
 * Created: 7/12/2024 5:05:02 PM
 *  Author: mrfed
 */ 

#include "HeaterCooler_INT.h"

void Heater_init()
{
	DIO_setPinDir(HEATER,DIO_OUTPUT);			//Heater Button
}

void Cooler_init()
{
	DIO_setPinDir(COOLER,DIO_OUTPUT);			//Cooler Button
}

void Heater_ON ()
{
	DIO_setPinValue(HEATER,On);				//Heater ON
}

void Cooler_ON ()
{
	DIO_setPinValue(COOLER,On);				//Cooler ON
}
void Heater_OFF ()
{
	DIO_setPinValue(HEATER,Off);				//Heater ON
}

void Cooler_OFF ()
{
	DIO_setPinValue(COOLER,Off);				//Cooler ON
}