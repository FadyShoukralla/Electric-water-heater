/*
 * HeaterCooler.c
 *
 * Created: 6/29/2024 6:00:28 PM
 * Author : mrfed
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO_INT.h"
#include "STD_TYPES.h"
#include "SYS_CONFG_INT.h"


void ONOFF_Change ()
{
	if (state == OFF)
	{
		Td = INTERN_EEPROM_READ(50);
		state = ON;
	}
	else if ((state == ON) ||(state == SETTING))
	{
		state = OFF;
	}
}

void Sensor_reads()
{
	Temp_counter++;
	if (Temp_counter == 25)		//(0.1 s/ 250*Ttick)		OCR=249		Ttick= N/FCPU = 1/16M
	{
		Temp_flag = 1;
		Temp_counter = 0;
	}
}

void Blink ()
{
	if ((state == SETTING) || (state == ON))
	{
		Counter++;
		if (Counter % 250 == 0)		//(1 s/ 250*Ttick)		OCR=249		Ttick= N/FCPU = 256/16M
		{
			Blink_Counter = Blink_Counter ^ 1;
		}
		if (Counter > 1250)			//to complete 5 seconds
		{
			Counter = 0;
			state = ON;
		}
	}
}

int main(void)
{
	GI_enable();
	
	sys_init();
	
	//Timer0 initialization
	TIMER0_initCtc();				//using CTC mode to get accurate time.
	TIMER0_setCallbackCtc(Blink);
	TIMER0_setOcr(249);
	TIMER0_start(TIMER0_DIV256);
	
	//Timer2 initialization
	TIMER2_initCtc();
	TIMER2_setCallbackCtc(Sensor_reads);
	TIMER2_setOcr(249);
	TIMER2_start(TIMER2_DIV256);
	
	//External interrupt initialization
	EXT_int0Init(EXT_RISING);
	EXT_setCallbackInt0(ONOFF_Change);
	
    while (1)
    {
		if (state == ON)
		{
			ON_Mode();
		}
		else if (state == OFF)
		{
			OFF_Mode();
		}
		else if (state == SETTING)
		{
			Setting_Mode();
		}
    }
}

