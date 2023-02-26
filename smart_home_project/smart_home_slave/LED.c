/*
 * LED.c
 *
 * Created: 11/16/2022 1:42:44 AM
 *  Author: osama
 */ 
#include "DIO.h"

void LED_PORT_INIT(unsigned char port)
{
	DIO_SET_PORT_DIR(port, 1);
}

void LED_INIT(unsigned char port, unsigned char pin)
{
	DIO_SETPINDIR(port, pin, 1);
}

void LED_ON(unsigned char port, unsigned char pin)
{
	DIO_WRITE(port, pin, 1);
}

void LED_OFF(unsigned char port, unsigned char pin)
{
	DIO_WRITE(port, pin, 0);
}

void LED_TOGGLE(unsigned char port, unsigned char pin)
{
	DIO_TOGGLE(port, pin);
}