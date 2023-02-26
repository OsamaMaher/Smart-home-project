/*
 * _7segments.c
 *
 * Created: 11/18/2022 12:23:17 AM
 *  Author: osama
 */ 
#include "DIO.h"
#include "MACROS.h"

void segments_dir_init(unsigned char port)
{
	DIO_SET_PORT_DIR(port, 1);
}

void segments_write(unsigned char port, unsigned char value)
{
	unsigned char C[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	DIO_PORT_WRITE(port, C[value]);
}

void segments_write_BCD(unsigned char port, unsigned char value)
{
	DIO_WRITE(port,0,READ_BIT(value, 0));
	DIO_WRITE(port,1,READ_BIT(value, 1));
	DIO_WRITE(port,2,READ_BIT(value, 2));
	DIO_WRITE(port,3,READ_BIT(value, 3));
}