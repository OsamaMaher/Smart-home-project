/*
 * EEPROM_drive.h
 *
 * Created: 11/24/2022 12:10:21 AM
 *  Author: osama
 */ 


#ifndef EEPROM_DRIVE_H_
#define EEPROM_DRIVE_H_

void EEPROM_Write(unsigned short address, unsigned char data);
char EEPROM_Read(unsigned short address);



#endif /* EEPROM_DRIVE_H_ */