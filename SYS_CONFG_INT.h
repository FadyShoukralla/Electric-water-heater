/*
 * SYS_CONFG_INT.h
 *
 * Created: 7/12/2024 5:29:16 PM
 *  Author: mrfed
 */ 


#ifndef SYS_CONFG_INT_H_
#define SYS_CONFG_INT_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_INT.h"
#include "DIO_INT.h"
#include "EXT_INT.h"
#include "GI_INT.h"
#include "UART_INT.h"
#include "TIMER0_INT.h"
#include "TIMER2_INT.h"
#include "INTERN_EEPROM_INT.h"
#include "SS_INT.h"
#include "UART_INT.h"
#include "BUTTON_INT.h"
#include "HeaterCooler_INT.h"
#include "LED_INT.h"

#define		OFF				0
#define		ON				1
#define		SETTING			2

#define		RANGE			5
#define		MAX				75
#define		MIN				35
#define		INIT_Td			60
#define		NUM_OF_MEASURES 10



u16 readings[NUM_OF_MEASURES];
u8 Td;
u16 Tc;

u8 state;
u8 Blink_Counter;
u8 Temp_counter;
u8 Temp_flag;
u8 Display_count;

u32 Counter;
f32 Tavg;
f32 GetAvg (u16* readings);

void sys_init ();
void OFF_Mode ();
void ON_Mode ();
void Setting_Mode ();

#endif /* SYS_CONFG_INT_H_ */