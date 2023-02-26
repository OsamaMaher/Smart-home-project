/*
 * Keypad.c
 *
 * Created: 11/22/2022 11:35:11 PM
 *  Author: osama
 */ 
#include "Keypad_my.h"
#include "DIO.h"

void Keypad_vinit(void)
{
	DIO_SETPINDIR(USER_PORT, 0, 1);
	DIO_SETPINDIR(USER_PORT, 1, 1);
	DIO_SETPINDIR(USER_PORT, 2, 1);
	DIO_SETPINDIR(USER_PORT, 3, 1);
	DIO_SETPINDIR(USER_PORT, 4, 0);
	DIO_SETPINDIR(USER_PORT, 5, 0);
	DIO_SETPINDIR(USER_PORT, 6, 0);
	DIO_SETPINDIR(USER_PORT, 7, 0);
	DIO_PULLUP(USER_PORT, 4, 1);
	DIO_PULLUP(USER_PORT, 5, 1);
	DIO_PULLUP(USER_PORT, 6, 1);
	DIO_PULLUP(USER_PORT, 7, 1);
}

unsigned char Keypad_vRead(void)
{
	unsigned char arr[4][4]= {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}};
	unsigned char row,column,x,return_val=0xff;
	
	for (row=0 ; row<4 ; row++)
	{
		DIO_WRITE(USER_PORT, 0, 1);
		DIO_WRITE(USER_PORT, 1, 1);
		DIO_WRITE(USER_PORT, 2, 1);
		DIO_WRITE(USER_PORT, 3, 1);
		DIO_WRITE(USER_PORT, row, 0);
		for (column=0 ; column<4 ; column++)
		{
			x=DIO_READ(USER_PORT, (column+4));
			if (x==0)
			{
				return_val=arr[row][column];
				break;
			}
		}
		if (x==0)
		{
			break;
		}
	}
	return return_val;
}