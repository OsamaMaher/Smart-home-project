/*
 * smart_home_project.c
 *
 * Created: 12/13/2022 12:44:07 AM
 * Author : osama
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Timer_Drive.h"
#include "smart_home_master.h"
#include "LCD_test.h"
#include "SPI_driver.h"
#include "Keypad_my.h"
#include "EEPROM_drive.h"
#include "LED.h"
#include "Control_rooms_AC.h"

unsigned short is_pass_set = 0x0030;
unsigned short pass_add_1 = 0x0031;
unsigned short pass_add_2 = 0x0032;
unsigned short pass_add_3 = 0x0033;
unsigned short pass_add_4 = 0x0034;
unsigned short pass_add_guest_1 = 0x0035;
unsigned short pass_add_guest_2 = 0x0036;
unsigned short pass_add_guest_3 = 0x0037;
unsigned short pass_add_guest_4 = 0x0038;
unsigned char enter_flag=0;
unsigned char mode=0;
signed char tries=3;
unsigned char wronge_pass=0;
unsigned char control_choice;
char sec=0;

int main(void)
{
	SPI_master_init();
    LCD_init();
	Keypad_vinit();
	LED_INIT('D', 0);
	LED_INIT('D', 1);
	LCD_send_string("welcome to smart");
	LCD_move_cursor(2,5);
	LCD_send_string("home app");
	_delay_ms(2000);
	LCD_clear_screen();
	
	unsigned char x, i;
	
	if (EEPROM_Read(is_pass_set) == NOT_SET)
	{
		LCD_send_string("SET ADMIN PASS:");
		LCD_move_cursor(2,1);
		for (i=0;i<4;i++)
		{
			do
			{
				x = Keypad_vRead();
			} while (x == NOT_SET);
			LCD_send_char(x);
			_delay_ms(500);
			LCD_move_cursor(2,i+1);
			LCD_send_char('*');
			EEPROM_Write((pass_add_1+i),x);
		}
		
		LCD_clear_screen();
		LCD_send_string("SET GUEST PASS:");
		LCD_move_cursor(2,1);
		for (i=0;i<4;i++)
		{
			do
			{
				x = Keypad_vRead();
			} while (x == NOT_SET);
			LCD_send_char(x);
			_delay_ms(500);
			LCD_move_cursor(2,i+1);
			LCD_send_char('*');
			EEPROM_Write((pass_add_guest_1+i),x);
		}
		EEPROM_Write(is_pass_set, 0);
	}
	else
	{
		do 
		{
			LCD_clear_screen();
			LCD_send_string("SELECT MODE:");
			LCD_move_cursor(2,1);
			LCD_send_string("0:ADMIN 1:GUEST");
			_delay_ms(500);
			do
			{
				mode=Keypad_vRead();
			} while (mode==NOT_SET);
			_delay_ms(250);
			if (mode == '0')
			{
				do 
				{
					wronge_pass=0;
					LCD_clear_screen();
					LCD_send_string("ENTER ADMIN PASS");
					LCD_move_cursor(2,1);
					_delay_ms(50);
					for (i=0;i<4;i++)
					{
						do
						{
							x = Keypad_vRead();
						} while (x == NOT_SET);
						LCD_send_char(x);
						_delay_ms(500);
						LCD_move_cursor(2,i+1);
						LCD_send_char('*');
						if (x != EEPROM_Read(pass_add_1+i))
						{
							wronge_pass=1;
						}
					}
					if (wronge_pass == 0)
					{
						enter_flag = 2;
						break;
					}
					else
					{
						LCD_clear_screen();
						LCD_send_string("wrong password");
						LCD_move_cursor(2,1);
						LCD_send_string("NUM of tries:");
						LCD_send_char(tries+47);
						_delay_ms(1000);
					}
					tries--;
				} while (tries > 0);
				
				
			}
			else if (mode =='1')
			{
				do 
				{
					wronge_pass=0;
					LCD_clear_screen();
					LCD_send_string("ENTER GUEST PASS");
					LCD_move_cursor(2,1);
					_delay_ms(50);
					for (i=0;i<4;i++)
					{
						do
						{
							x = Keypad_vRead();
						} while (x == NOT_SET);
						LCD_send_char(x);
						_delay_ms(500);
						LCD_move_cursor(2,i+1);
						LCD_send_char('*');
						if (x != EEPROM_Read(pass_add_guest_1+i))
						{
							wronge_pass=1;
						}
					}
					if (wronge_pass == 0)
					{
						enter_flag = 2;
						break;
					}
					else
					{
						LCD_clear_screen();
						LCD_send_string("wrong password");
						LCD_move_cursor(2,1);
						LCD_send_string("NUM of tries:");
						LCD_send_char(tries+47);
						_delay_ms(1000);
					}
					tries--;
				} while (tries> 0);
			}
			else
			{
				LCD_send_string("WRONG CHOISE");
				_delay_ms(500);
				
			}
			if (tries == 0)
			{
				LCD_clear_screen();
				LCD_send_string("NO MORE TRIES");
				LCD_move_cursor(2,1);
				LCD_send_string("SMART HOME EXIT");
				_delay_ms(500);
				break;
			}
		} while (enter_flag!=2);
		
	}
	if (tries>0 && enter_flag==2)
	{
		enter_flag = 1;
		Timer2_OVF_init_interrupt();
	}
	
	
	
    while (enter_flag == 1) 
    {
		switch (mode)
		{
			case '0':									   // if admen mode
			{
				LED_ON('D',1);                             // gives choices for admen user
				LCD_clear_screen();
				LCD_send_string("CHOSE:   0:ROOM1");
				LCD_move_cursor(2,1);
				LCD_send_string("1:ROOM2   2:MORE");
				do
				{
					control_choice = Keypad_vRead();
				} while (control_choice==NOT_SET);
				_delay_ms(250);
				if (control_choice=='2')				  // additional choices for admen
				{
					LCD_clear_screen();
					LCD_send_string("3:ROOM3 4:ROOM4");
					LCD_move_cursor(2,1);
					LCD_send_string("5:AC   6:GoBack");
					do
					{
						control_choice = Keypad_vRead();
					} while (control_choice==NOT_SET);
					_delay_ms(250);
				}
				break;
			}
			case '1':                                  // if guest mode
			{
				LED_ON('D',0);
				LCD_clear_screen();					  // choices for guest user
				LCD_send_string("0:ROOM1  1:ROOM2");
				LCD_move_cursor(2,1);
				LCD_send_string("2:ROOM3  3:ROOM4");
				do
				{
					control_choice = Keypad_vRead();
				} while (control_choice==NOT_SET);
				_delay_ms(250);
				break;
			}
		}
		
		switch (control_choice)
		{
			case '0':
			{
				control_room(1);
				break;
			}
			case '1':
			{
				control_room(2);
				break;
			}
			case '2':
			{
				control_room(3);	
				break;
			}
			case '3':
			{
				if (mode=='1')
				{
					control_room(4);
				}
				else
				{
					control_room(3);
				}
				break;
			}
			case '4':
			{
				control_room(4);
				break;
			}
			case '5':
			{
				control_AC();
				break;
			}
		}
		if (sec>=5)
		{
			LCD_clear_screen();
			LCD_send_string("USER TIMEOUT");
			LCD_move_cursor(2,1);
			LCD_send_string("EXIT APP");
			_delay_ms(1000);
			enter_flag=0;
		}
    }
}

ISR(TIMER2_OVF_vect)
{
	sec++;
}