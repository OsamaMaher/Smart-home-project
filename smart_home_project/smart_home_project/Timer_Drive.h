/*
 * Timer_Drive.h
 *
 * Created: 11/27/2022 12:50:49 AM
 *  Author: osama
 */ 


#ifndef TIMER_DRIVE_H_
#define TIMER_DRIVE_H_

void Timer0_COM_init_interrupt(void);
void Timer2_OVF_init_interrupt(void);
void Timer_wave_nonPWM(void);
void timer_wave_fastPWM(void);
void timer_wave_phasecorrectPWM(void);



#endif /* TIMER_DRIVE_H_ */