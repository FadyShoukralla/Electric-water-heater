/*
 * INTERN_EEPROM_PROG.c
 *
 * Created: 8/4/2024 11:30:14 PM
 *  Author: mrfed
 */ 
#include "INTERN_EEPROM_INT.h"
#include "GI_INT.h"

void INTERN_EEPROM_WRITE (u32 location, u8 byte)
{
	//wait for previous write
	while (EECR & (1<<EEWE));
	
	//set up address and data registers
	EEARL = location;
	EEARH = (location>>8);
	
	EEDR = byte;
	
	//disable interrupts
	GI_disable();
	
	//write logical one to EEMWE
	EECR |= (1<<EEMWE);
	
	//start EEPROM write
	EECR |= (1<<EEWE);
	
	//enable interrupts
	GI_enable();
}


u8 INTERN_EEPROM_READ (u32 location)
{
	//wait for previous write
	while(EECR & (1<<EEWE));
	
	//set up address register
	EEARL = location;
	EEARH = (location>>8);
	
	//start EEPROM read 
	EECR |= (1<<EERE);
	
	//return EEDR
	return EEDR;
}