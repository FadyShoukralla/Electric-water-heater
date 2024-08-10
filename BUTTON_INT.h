/*
 * BUTTON_INT.h
 *
 * Created: 7/12/2024 4:49:14 PM
 *  Author: mrfed
 */ 


#ifndef BUTTON_INT_H_
#define BUTTON_INT_H_

#include "DIO_INT.h"
#include "STD_TYPES.h"

#define		PRESSED		1
#define		UNPRESSED	0
#define		ONOFFBUTTON	DIO_PIND2
#define		UPBUTTON	DIO_PIND6
#define		DOWNBUTTON	DIO_PINB0

void Button_init();
u8 UP_Button ();
u8 DOWN_Button ();

#endif /* BUTTON_INT_H_ */