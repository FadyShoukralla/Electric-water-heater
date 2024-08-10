/*
 * SS_INT.h
 *
 * Created: 6/29/2024 6:02:52 PM
 *  Author: mrfed
 */ 


#ifndef SS_INT_H_
#define SS_INT_H_

#include "STD_TYPES.h"
#include "DIO_INT.h"

#define SS_ENABLE1 DIO_PINB1
#define SS_ENABLE2 DIO_PINB2

#define SS_S0 DIO_PINA4
#define SS_S1 DIO_PINA5
#define SS_S2 DIO_PINA6
#define SS_S3 DIO_PINA7

void SS_init();
void SS_writenum(u8 num);
void SS_off();

#endif /* SS_INT_H_ */