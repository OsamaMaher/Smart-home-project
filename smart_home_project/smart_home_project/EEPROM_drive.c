/*
 * EEPROM_drive.c
 *
 * Created: 11/24/2022 12:10:04 AM
 *  Author: osama
 */ 
#include <avr/io.h>
#include "MACROS.h"


void EEPROM_Write(unsigned short address, unsigned char data)
{
	EEARL = (unsigned char) address;
	EEARH = (unsigned char) (address>>8);
	
	EEDR = data;
	
	SET_BIT(EECR, EEMWE);
	
	SET_BIT(EECR, EEWE);
	
	while (READ_BIT(EECR, EEWE)==1);
}


char EEPROM_Read(unsigned short address)
{
	EEARL = (unsigned char) address;
	EEARH = (unsigned char) (address>>8);
	
	SET_BIT(EECR, EERE);
	
	return EEDR;
}