/*
 * LED_INT.h
 *
 * Created: 7/12/2024 5:12:52 PM
 *  Author: mrfed
 */ 


#ifndef LED_INT_H_
#define LED_INT_H_

#include "DIO_INT.h"

#define		LED			DIO_PINC7

void LED_init ();
void LED_ON ();
void LED_OFF ();

#endif /* LED_INT_H_ */