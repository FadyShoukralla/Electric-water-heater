/*
 * INTERN_EEPROM_INT.h
 *
 * Created: 8/4/2024 11:30:44 PM
 *  Author: mrfed
 */ 


#ifndef INTERN_EEPROM_INT_H_
#define INTERN_EEPROM_INT_H_

#include "STD_TYPES.h"

#define		EEARL		*((volatile u8*)0x3E)
#define		EEAR0		0
#define		EEAR1		1
#define		EEAR2		2
#define		EEAR3		3
#define		EEAR4		4
#define		EEAR5		5
#define		EEAR6		6
#define		EEAR7		7

#define		EEARH		*((volatile u8*)0x3F)
#define		EEAR8		8
#define		EEAR9		9

#define		EEDR		*((volatile u8*)0x3D)

#define		EECR		*((volatile u8*)0x3C)
#define		EERE		0
#define		EEWE		1
#define		EEMWE		2
#define		EERIE		3

void INTERN_EEPROM_WRITE (u32 location, u8 byte);
u8 INTERN_EEPROM_READ (u32 location);


#endif /* INTERN_EEPROM_INT_H_ */