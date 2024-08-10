/*
 * SYS_CONFG_PROG.c
 *
 * Created: 7/12/2024 5:29:42 PM
 *  Author: mrfed
 */ 

#include "SYS_CONFG_INT.h"
#define F_CPU 16000000UL
#include <util/delay.h>



void sys_init ()
{
	//Initializations:
	ADC_init();
	SS_init();
	Button_init();
	LED_init();
	Cooler_init();
	Heater_init();
	UART_init();
	
	//Initially state is off
	state = OFF;
	
	//check if EEPROM storage empty or not
	if (INTERN_EEPROM_READ(50) != 255)		//EEPROM storage is not empty
	{
		Td = INTERN_EEPROM_READ(50);
	}
	else
	{
		Td = INIT_Td;					//EEPROM storage is empty
	}
	
	
	for (u8 i=0; i<NUM_OF_MEASURES; i++)
	{
		Tc = ADC_read(ADC_CH0);
		readings[i] = Tc;
	}
	
	Temp_flag = 0;
	Display_count = 0;
	Temp_counter = 0;
	
	INTERN_EEPROM_WRITE(50, Td);
}

void OFF_Mode ()
{
	SS_off();
	LED_OFF();
	Heater_OFF();
	Cooler_OFF();
}

void ON_Mode ()
{
	if (Temp_flag == 1)
	{
		Tc = ADC_read(ADC_CH0);
		
		readings[Display_count] = Tc;
		Display_count++;
		if (Display_count == NUM_OF_MEASURES)
		{
			Display_count = 0;
			Tavg = GetAvg(readings);
		}
	
		Temp_flag = 0;
	}
		
	if ( (Td < (Tavg+RANGE)) && (Td > (Tavg-RANGE)) )			//Desired Temp reached
	{
		Heater_OFF();										//Heater and Cooler are off
		Cooler_OFF();
		LED_OFF();
	}
	else if (Td < (Tavg+RANGE))								//Desired Temp is less than Average Temp + 5
	{
		Heater_OFF();
		Cooler_ON();										//Cooler is on
		LED_ON();
	}
	else if (Td > (Tavg-RANGE))								//Desired Temp is greater than Average Tamp + 5
	{
		Cooler_OFF();
		Heater_ON();										//Heater is on
		if (Blink_Counter == 1)								//Make Led blink while heater is on
		{
			LED_ON();
		}
		else
		{
			LED_OFF();
		}
	}
	
	SS_writenum((u16)Tavg);
	UART_sendNum(Tavg);
	
	if ((UP_Button() == PRESSED) || (DOWN_Button() == PRESSED) || (UART_receiveData() == 'a') || (UART_receiveData() == 'b'))
	{
		SS_off();
		Counter = 0;
		state = SETTING;
	}
}

f32 GetAvg (u16* readings)
{
	f32 sum = 0.0;
	for (u8 i=0; i<NUM_OF_MEASURES; i++)
	{
		sum = sum + (ADC_convertAnalog(readings[i])*100);
	}
	return ((u16)sum / NUM_OF_MEASURES);
}

void Setting_Mode ()
{
	Heater_OFF();
	Cooler_OFF();
	LED_OFF();
	
	if (Blink_Counter == 1)
	{
		SS_writenum(Td);
	}
	else
	{
		SS_off();
	}
	
	if ( ( (UP_Button() == PRESSED) || (UART_receiveData() == 'a') ) && (Td < MAX) )
	{
		Td = Td + 5;
		Counter = 0;
	}
	else if ( ( (DOWN_Button() == PRESSED) || (UART_receiveData() == 'b') ) && (Td > MIN) )
	{
		Td = Td - 5;
		Counter = 0;
	}
	
	SS_writenum(Td);
	UART_sendNum(Td);
	INTERN_EEPROM_WRITE(50,Td);
}