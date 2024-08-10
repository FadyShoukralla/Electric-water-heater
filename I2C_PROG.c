/*
 * I2C_PROG.c
 *
 * Created: 6/29/2024 6:58:05 PM
 *  Author: mrfed
 */ 

#include "I2C_INT.h"

void I2C_init(enum I2C_mode mode)
{
	if (mode == MASTER)
	{
		
	}
	else if (mode == SLAVE)
	{
		TWAR = I2C_SLAVE_ADDRESS<<1;
	}
	
	//enable
	SET_BIT(TWCR,TWEN);
	TWBR = 72;
}

void I2C_sendByte(u8 byte, u8 address)
{
	//start
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(GET_BIT(TWCR,TWINT) == 0);
	
	//send address
	u8 x = address<<1;
	CLEAR_BIT(x,0); //write
	TWDR = x; //address_W
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(GET_BIT(TWCR,TWINT) == 0);
	
	//send data
	TWDR = byte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(GET_BIT(TWCR,TWINT) == 0);
	
	//stop
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void I2C_receiveByte(u8* byte, u8 address)
{
	//start
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(GET_BIT(TWCR,TWINT) == 0);
	
	//send address
	u8 x = address<<1;
	SET_BIT(x,0); //read
	TWDR = x; //address_R
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(GET_BIT(TWCR,TWINT) == 0);
	
	//read data
	//below three lines could be used for slave
	TWCR = (1<<TWINT) | (1<<TWEN);  // | (1<<TWEA) to receive by ACK
	while(GET_BIT(TWCR,TWINT) == 0);
	*byte = TWDR;
	
	//stop
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void I2C_slaveReceiveByte(u8* byte)
{
	//read data
	TWCR = (1<<TWINT) | (1<<TWEN);  // | (1<<TWEA) to receive by ACK
	while(GET_BIT(TWCR,TWINT) == 0);
	*byte = TWDR;
}