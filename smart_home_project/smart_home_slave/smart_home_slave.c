/*
 * smart_home_slave.c
 *
 * Created: 12/13/2022 12:49:02 AM
 * Author : osama
 */ 

#include <avr/io.h>
#include "SPI_driver.h"
#include "LED.h"

unsigned char choice_romm;
unsigned char choice;
unsigned char AC_temp = 0;

int main(void)
{
	LED_INIT('D',0);
	LED_INIT('D',1);
	LED_INIT('D',2);
	LED_INIT('D',3);
	LED_INIT('D',4);
	LED_INIT('D',5);
    SPI_slave_init();
    while (1) 
    {
		choice_romm = SPI_Slave_Receive_char('1');
		switch (choice_romm)
		{
			case '0':
			{
				choice = SPI_Slave_Receive_char('1');
				if (choice == '0')
				{
					LED_OFF('D',0);
				}
				else if (choice == '1')
				{
					LED_ON('D',0);
				}
				break;
			}
			case '1':
			{
				choice = SPI_Slave_Receive_char('1');
				if (choice == '0')
				{
					LED_OFF('D',1);
				}
				else if (choice == '1')
				{
					LED_ON('D',1);
				}
				break;
			}
			case '2':
			{
				choice = SPI_Slave_Receive_char('1');
				if (choice == '0')
				{
					LED_OFF('D',2);
				}
				else if (choice == '1')
				{
					LED_ON('D',2);
				}
				break;
			}
			case '3':
			{
				choice = SPI_Slave_Receive_char('1');
				if (choice == '0')
				{
					LED_OFF('D',3);
				}
				else if (choice == '1')
				{
					LED_ON('D',3);
				}
				break;
			}
			case '4':
			{
				unsigned char i;
				for(i=0;i<2;i++)
				{
					choice = SPI_Slave_Receive_char('1');
					AC_temp = AC_temp + (i+10)*choice - (i*10)*choice;
				}
				break;
			}
		}
    }
}

