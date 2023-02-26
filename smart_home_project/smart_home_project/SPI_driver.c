/*
 * SPI_driver.c
 *
 * Created: 11/30/2022 12:36:23 AM
 *  Author: osama
 */ 
#include <avr/io.h>
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "MACROS.h"


void SPI_master_init(void)
{
	DIO_SETPINDIR('B',4,1);
	DIO_SETPINDIR('B',5,1);
	DIO_SETPINDIR('B',7,1);
	
	SET_BIT(SPCR, MSTR);
	
	SET_BIT(SPCR, SPR0);
	
	SET_BIT(SPCR, SPE);
	
	DIO_WRITE('B', 4, 1);
}


void SPI_slave_init(void)
{
	SET_BIT(SPCR, SPE);
	
	DIO_SETPINDIR('B',6,1);
}

unsigned char SPI_Master_Transmit_char(unsigned char Data)
{
	DIO_WRITE('B', 4, 0);
	
	SPDR =Data;
	
	while (READ_BIT(SPSR,SPIF) == 0);
	
	return SPDR;
}

unsigned char SPI_Slave_Receive_char(unsigned char Data)
{
	SPDR =Data;
	
	while (READ_BIT(SPSR,SPIF) == 0);
	
	return SPDR;
}

void SPI_Master_Transmit_string(unsigned char* ptr)
{
	while (*ptr!=0)
	{
		SPI_Master_Transmit_char(*ptr);
		_delay_ms(300);
		ptr++;
	}
}