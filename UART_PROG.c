/*
 * UART_PROG.c
 *
 * Created: 6/29/2024 6:52:11 PM
 *  Author: mrfed
 */ 

#include "UART_INT.h"


void UART_init()
{
	//enable T&R
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	u8 temp = 0b10000000;
	//disable parity
	CLEAR_BIT(temp,UPM0);
	CLEAR_BIT(temp,UPM1);
	
	//stop bit
	CLEAR_BIT(temp,USBS);
	
	//char size
	SET_BIT(temp,UCSZ0);
	SET_BIT(temp,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);
	
	UCSRC_UBRRH = temp;
	
	//Baud rate
	UBRRL = 103;
	UCSRC_UBRRH = 0;
}

void UART_sendData(u8 data)
{
	//check register is free
	while(GET_BIT(UCSRA,UDRE) == 0);
	
	//send data
	UDR = data;
}

void UART_sendStr(u8* str)
{
	u8 i=0;
	while (str[i] != '\0')
	{
		UART_sendData(str[i]);
		i++;
	}
}

u8 UART_receiveData()
{
	//check register is free
	u32 Timeout = 100000;
	while(GET_BIT(UCSRA,RXC) == 0)
	{
		Timeout -- ;
		if (Timeout == 0)
		{
			return UART_NOT_RECEIVE;
		}
	}
	//receive data
	return UDR;
}

void UART_sendNum(u8 value)
{
	// Convert the numeric value to ASCII characters
	char buffer[3]; 
	snprintf(buffer, sizeof(buffer), "%u", value);

	// Send each character in the buffer
	for (int i = 0; buffer[i] != '\0'; ++i)
	{
		UART_sendData(buffer[i]);
	}
}