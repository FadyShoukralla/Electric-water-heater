/*
 * HeaterCooler_INT.h
 *
 * Created: 7/12/2024 5:05:31 PM
 *  Author: mrfed
 */ 


#ifndef HEATERCOOLER_INT_H_
#define HEATERCOOLER_INT_H_

#include "DIO_INT.h"

#define		HEATER		DIO_PINA2
#define		COOLER		DIO_PINB3

void Heater_init();
void Cooler_init();
void Heater_ON ();
void Cooler_ON ();
void Heater_OFF ();
void Cooler_OFF ();

#endif /* HEATERCOOLER_INT_H_ */