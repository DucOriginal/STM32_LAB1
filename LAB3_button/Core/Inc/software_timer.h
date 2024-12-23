/*
 * software_timer.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Duc Original
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timerLedRed_flag;
extern int timerLedYel_flag;
extern int timerLedGre_flag;

extern int segment1_flag;
extern int segment2_flag;

extern int counter_red;
extern int counter_yel;
extern int counter_gre;
int number1_counter;
int number1_flag;
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimerLedRed(int duration);
void setTimerLedYel(int duration);
void setTimerLedGre(int duration);

void TurnOnRed();
void TurnOnYel();
void TurnOnGre();

void setTimer7segment1(int duration);
void setTimer7segment2(int duration);
void setTimerNumber1(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
