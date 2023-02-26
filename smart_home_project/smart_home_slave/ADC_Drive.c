/*
 * ADC_Drive.c
 *
 * Created: 11/26/2022 1:16:15 AM
 *  Author: osama
 */ 
#include <avr/io.h>
#include "MACROS.h"

void ADC_init(void)
{
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADCSRA, ADEN);
	
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
}

unsigned short ADC_Read(void)
{
	unsigned short read_val;
	SET_BIT(ADCSRA, ADSC);
	while (READ_BIT(ADCSRA, ADIF)==0);
	SET_BIT(ADCSRA, ADIF);
	read_val= (ADCL);
	read_val |= (ADCH<<8);
	return read_val;
}