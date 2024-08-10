/*
 * GI_PROG.c
 *
 * Created: 6/29/2024 6:22:19 PM
 *  Author: mrfed
 */ 

#include "BIT_MATH.h"
#include "GI_INT.h"

void GI_enable()
{
	SET_BIT(SREG, I);
}

void GI_disable()
{
	CLEAR_BIT(SREG, I);
}