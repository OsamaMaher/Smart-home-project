/*
 * MACROS.h
 *
 * Created: 11/14/2022 11:02:35 PM
 *  Author: osama
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=~(1<<bit)
#define TOG_BIT(reg,bit) reg^=(1<<bit)
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)
//#define ROR(reg,num) reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
//#define ROR(reg,num) reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num))



#endif /* MACROS_H_ */