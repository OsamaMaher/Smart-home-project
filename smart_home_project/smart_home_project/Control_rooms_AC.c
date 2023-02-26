/*
 * Control_rooms_AC.c
 *
 * Created: 12/26/2022 12:16:39 AM
 *  Author: osama
 */ 

#include <avr/io.h>
#include "MACROS.h"
#include "SPI_driver.h"
#include "Keypad_my.h"
#include "LCD_test.h"
#define F_CPU 8000000UL
#include <util/delay.h>




void control_room(unsigned char room_num)
{
	unsigned char check;
	SPI_Master_Transmit_char(room_num+47);
	LCD_clear_screen();
	LCD_send_string("LIGHTS:");
	LCD_move_cursor(2,1);
	LCD_send_string("0:OFF   1:ON");
	do 
	{
		check = Keypad_vRead();
	} while (check == 0xff);
	_delay_ms(250);
	SPI_Master_Transmit_char(check);
}

void control_AC(void)
{
	unsigned char i;
	unsigned char AC_temp;
	LCD_clear_screen();
	LCD_send_string("SET TEMP TO:");
	LCD_move_cursor(2,3);
	LCD_send_char('C');
	LCD_send_char(223);
	LCD_move_cursor(2,1);
	for(i=0;i<2;i++)
	{
		do
		{
			AC_temp = Keypad_vRead();
		} while (AC_temp == 0xff);
		_delay_ms(250);
		LCD_send_char(AC_temp);
		SPI_Master_Transmit_char(AC_temp);
		_delay_ms(250);
	}
	LCD_clear_screen();
	LCD_send_string("Temp is sent");
	_delay_ms(500);
	
	
}