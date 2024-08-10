/*
 * SS_PROG.c
 *
 * Created: 6/29/2024 6:03:04 PM
 *  Author: mrfed
 */ 

#include "BIT_MATH.h"
#include "DIO_INT.h"
#include "SS_INT.h"

# define F_CPU 16000000UL
#include <util/delay.h>

void SS_init()
{
	DIO_setPinDir(SS_S0, DIO_OUTPUT);
	DIO_setPinDir(SS_S1, DIO_OUTPUT);
	DIO_setPinDir(SS_S2, DIO_OUTPUT);
	DIO_setPinDir(SS_S3, DIO_OUTPUT);
	
	DIO_setPinDir(SS_ENABLE1, DIO_OUTPUT);
	DIO_setPinDir(SS_ENABLE2, DIO_OUTPUT);
}

void SS_writenum(u8 num)
{
	//disable 2
	DIO_setPinValue(SS_ENABLE2,DIO_LOW);
	
	//write num1
	u8 num1= num%10;
	DIO_setPinValue(SS_S0,GET_BIT(num1,0));
	DIO_setPinValue(SS_S1,GET_BIT(num1,1));
	DIO_setPinValue(SS_S2,GET_BIT(num1,2));
	DIO_setPinValue(SS_S3,GET_BIT(num1,3));
	
	//enable 1
	DIO_setPinValue(SS_ENABLE1,DIO_HIGH);
	_delay_ms(1);
	
	//disable 1
	DIO_setPinValue(SS_ENABLE1,DIO_LOW);
	
	//write num2
	u8 num2= num/10;
	DIO_setPinValue(SS_S0,GET_BIT(num2,0));
	DIO_setPinValue(SS_S1,GET_BIT(num2,1));
	DIO_setPinValue(SS_S2,GET_BIT(num2,2));
	DIO_setPinValue(SS_S3,GET_BIT(num2,3));
	
	//enable 2
	DIO_setPinValue(SS_ENABLE2,DIO_HIGH);
	_delay_ms(1);
}

void SS_off()
{
	DIO_setPinValue(SS_ENABLE1, Off);
	DIO_setPinValue(SS_ENABLE2, Off);
}