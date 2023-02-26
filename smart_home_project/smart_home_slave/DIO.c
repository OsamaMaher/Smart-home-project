/*
 * DIO.c
 *
 * Created: 11/16/2022 1:46:04 AM
 *  Author: osama
 */ 
#include "MACROS.h"
#include <avr/io.h>

void DIO_SETPINDIR(unsigned char port, unsigned char pin, unsigned char value)
{
	switch (port)
	{
		case 'A':
		case 'a':
		{
			if (value == 1)
			{
				SET_BIT(DDRA,pin);
			}
			else
			{
				CLR_BIT(DDRA,pin);
			}
			break;
		}
		case 'B':
		case 'b':
		{
			if (value == 1)
			{
				SET_BIT(DDRB,pin);
			}
			else
			{
				CLR_BIT(DDRB,pin);
			}
			break;
		}
		case 'C':
		case 'c':
		{
			if (value == 1)
			{
				SET_BIT(DDRC,pin);
			}
			else
			{
				CLR_BIT(DDRC,pin);
			}
			break;
		}
		case 'D':
		case 'd':
		{
			if (value == 1)
			{
				SET_BIT(DDRD,pin);
			}
			else
			{
				CLR_BIT(DDRD,pin);
			}
			break;
		}
	}
}

void DIO_WRITE(unsigned char port, unsigned char pin, unsigned char value)
{
	switch (port)
	{
		case 'A':
		case 'a':
		{
			if (value == 1)
			{
				SET_BIT(PORTA,pin);
			}
			else
			{
				CLR_BIT(PORTA,pin);
			}
			break;
		}
		case 'B':
		case 'b':
		{
			if (value == 1)
			{
				SET_BIT(PORTB,pin);
			}
			else
			{
				CLR_BIT(PORTB,pin);
			}
			break;
		}
		case 'C':
		case 'c':
		{
			if (value == 1)
			{
				SET_BIT(PORTC,pin);
			}
			else
			{
				CLR_BIT(PORTC,pin);
			}
			break;
		}
		case 'D':
		case 'd':
		{
			if (value == 1)
			{
				SET_BIT(PORTD,pin);
			}
			else
			{
				CLR_BIT(PORTD,pin);
			}
			break;
		}
	}
}

unsigned char DIO_READ(unsigned char port, unsigned char pin)
{
	char ret_val=0;
	switch (port)
	{
		case 'A':
		case 'a':
		{
			ret_val = READ_BIT(PINA, pin);
			break;
		}
		case 'B':
		case 'b':
		{
			ret_val = READ_BIT(PINB, pin);
			break;
		}
		case 'C':
		case 'c':
		{
			ret_val = READ_BIT(PINC, pin);
			break;
		}
		case 'D':
		case 'd':
		{
			ret_val = READ_BIT(PIND, pin);
			break;
		}
	}
	return ret_val;
}

void DIO_SET_PORT_DIR(unsigned char port, unsigned char value)
{
	switch (port)
	{
		case 'A':
		case 'a':
		{
			if (value == 1)
			{
				DDRA = 0xff;
			}
			else
			{
				DDRA = 0x00;
			}
			break;
		}
		case 'B':
		case 'b':
		{
			if (value == 1)
			{
				DDRB = 0xff;
			}
			else
			{
				DDRB = 0x00;
			}
			break;
		}
		case 'C':
		case 'c':
		{
			if (value == 1)
			{
				DDRC = 0xff;
			}
			else
			{
				DDRC = 0x00;
			}
			break;
		}
		case 'D':
		case 'd':
		{
			if (value == 1)
			{
				DDRD = 0xff;
			}
			else
			{
				DDRD = 0x00;
			}
			break;
		}
	}
}

void DIO_PULLUP(unsigned char port, unsigned char pin, unsigned char value)
{
	switch(port)
	{
		case 'A':
		if(value==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		case 'B':
		if(value==1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLR_BIT(PORTB,pin);
		}
		break;
		case 'C':
		if(value==1)
		{
			SET_BIT(PORTC,pin);
			
		}
		else
		{
			CLR_BIT(PORTC,pin);
		}
		break;
		case 'D':
		if(value==1)
		{
			SET_BIT(PORTD,pin);
			
		}
		else
		{
			CLR_BIT(PORTD,pin);
		}
		break;
		
	}
}

void DIO_TOGGLE(unsigned char port, unsigned char pin)
{
	switch (port)
	{
		case 'A':
		case 'a':
		{
			TOG_BIT(PORTA, pin);
			break;
		}
		case 'B':
		case 'b':
		{
			TOG_BIT(PORTB, pin);
			break;
		}
		case 'C':
		case 'c':
		{
			TOG_BIT(PORTC, pin);
			break;
		}
		case 'D':
		case 'd':
		{
			TOG_BIT(PORTD, pin);
			break;
		}
	}
}

void DIO_PORT_WRITE(unsigned char port, unsigned char value)
{
	switch (port)
	{
		case 'A':
		case 'a':
		{
			PORTA = value;
			break;
		}
		case 'B':
		case 'b':
		{
			PORTB = value;
			break;
		}
		case 'C':
		case 'c':
		{
			PORTC = value;
			break;
		}
		case 'D':
		case 'd':
		{
			PORTD = value;
			break;
		}
	}
}

void DIO_WRITE_LOWNIBBLE(unsigned char port, unsigned char value)
{
	DIO_WRITE(port, 0, READ_BIT(value, 0));
	DIO_WRITE(port, 1, READ_BIT(value, 1));
	DIO_WRITE(port, 2, READ_BIT(value, 2));
	DIO_WRITE(port, 3, READ_BIT(value, 3));
}

void DIO_WRITE_HIGHNIBBLE(unsigned char port, unsigned char value)
{
	DIO_WRITE(port, 4, READ_BIT(value, 0));
	DIO_WRITE(port, 5, READ_BIT(value, 1));
	DIO_WRITE(port, 6, READ_BIT(value, 2));
	DIO_WRITE(port, 7, READ_BIT(value, 3));
}