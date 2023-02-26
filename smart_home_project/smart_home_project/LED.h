/*
 * LED.h
 *
 * Created: 11/16/2022 1:42:59 AM
 *  Author: osama
 */ 


#ifndef LED_H_
#define LED_H_

void LED_PORT_INIT(unsigned char port);
void LED_INIT(unsigned char port, unsigned char pin);
void LED_ON(unsigned char port, unsigned char pin);
void LED_OFF(unsigned char port, unsigned char pin);
void LED_TOGGLE(unsigned char port, unsigned char pin);


#endif /* LED_H_ */