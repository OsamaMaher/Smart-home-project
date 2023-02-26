/*
 * DIO.h
 *
 * Created: 11/16/2022 1:56:46 AM
 *  Author: osama
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_WRITE(unsigned char port, unsigned char pin, unsigned char value);
unsigned char DIO_READ(unsigned char port, unsigned char pin);
void DIO_SETPINDIR(unsigned char port, unsigned char pin, unsigned char value);
void DIO_SET_PORT_DIR(unsigned char port, unsigned char value);
void DIO_PULLUP(unsigned char port, unsigned char pin, unsigned char value);
void DIO_TOGGLE(unsigned char port, unsigned char pin);
void DIO_PORT_WRITE(unsigned char port, unsigned char value);
void DIO_WRITE_LOWNIBBLE(unsigned char port, unsigned char value);
void DIO_WRITE_HIGHNIBBLE(unsigned char port, unsigned char value);


#endif /* DIO_H_ */