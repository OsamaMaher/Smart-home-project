/*
 * SPI_driver.h
 *
 * Created: 11/30/2022 12:51:22 AM
 *  Author: osama
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

void SPI_master_init(void);
void SPI_slave_init(void);
unsigned char SPI_Master_Transmit_char(unsigned char Data);
unsigned char SPI_Slave_Receive_char(unsigned char Data);
unsigned char SPI_Master_Transmit_string(unsigned char* ptr);



#endif /* SPI_DRIVER_H_ */