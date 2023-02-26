/*
 * _7segments.h
 *
 * Created: 11/18/2022 12:23:44 AM
 *  Author: osama
 */ 


#ifndef SEGMENTS_H_
#define SEGMENTS_H_

void segments_dir_init(unsigned char port);
void segments_write(unsigned char port, unsigned char value);
void segments_write_BCD(unsigned char port, unsigned char value);

#endif /* 7SEGMENTS_H_ */