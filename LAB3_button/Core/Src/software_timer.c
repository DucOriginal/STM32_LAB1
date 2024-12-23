/*
 * software_timer.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Duc Original
 */


#include "software_timer.h"
#include "led7_segment.h"

int timer1_counter = 0;
int timer1_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;
int timer3_counter = 0;
int timer3_flag = 0;
int timerLedRed_flag = 0;
int timerLedYel_flag = 0;
int timerLedGre_flag = 0;
int timerLedRed_counter = 0;
int timerLedYel_counter = 0;
int timerLedGre_counter = 0;

int segment1_flag = 0;
int segment2_flag = 0;
int segment1_counter = 0;
int segment2_counter = 0;

int counter_red = 5;
int counter_yel = 2;
int counter_gre = 3;


void setTimer1(int duration)
{
	timer1_counter = duration * 100;
	timer1_flag = 0;
}

void setTimer2(int duration)
{
	timer2_counter = duration * 100;
	timer2_flag = 0;
}

void setTimer3(int duration)
{
	timer3_counter = duration;
	timer3_flag = 0;
}

void setTimer7segment1(int duration)
{
	segment1_counter = duration;
	segment1_flag = 0;
}
void setTimer7segment2(int duration)
{
	segment2_counter = duration;
	segment2_flag = 0;
}


void setTimerLedRed(int duration)
{
	timerLedRed_counter = duration;
	timerLedRed_flag = 0;
}

void setTimerLedYel(int duration)
{
	timerLedYel_counter = duration;
	timerLedYel_flag = 0;
}

void setTimerLedGre(int duration)
{
	timerLedGre_counter = duration;
	timerLedGre_flag = 0;
}

void TurnOnRed()
{
	setTimerLedRed(50);
	setTimerLedYel(0);
	setTimerLedGre(0);
}

void TurnOnYel()
{
	setTimerLedRed(0);
	setTimerLedYel(50);
	setTimerLedGre(0);
}

void TurnOnGre()
{
	setTimerLedRed(0);
	setTimerLedYel(0);
	setTimerLedGre(50);
}

void timerRun()
{
	if(timer1_counter > 0)
	{
		counter_7seg1 = timer1_counter / 100;
		timer1_counter --;

		if(timer1_counter <= 0)
			timer1_flag = 1;
	}

	if(timer2_counter > 0)
	{
		counter_7seg2 = timer2_counter / 100;
		timer2_counter --;
		if(timer2_counter <= 0)
			timer2_flag = 1;
	}

	if(timer3_counter > 0)
	{
		timer3_counter --;
		if(timer3_counter <= 0)
			timer3_flag = 1;
	}

	if(timerLedRed_counter > 0)
	{
		timerLedRed_counter --;
		if(timerLedRed_counter <= 0)
			timerLedRed_flag = 1;
	}

	if(timerLedYel_counter > 0)
	{
		timerLedYel_counter --;
		if(timerLedYel_counter <= 0)
			timerLedYel_flag = 1;
	}

	if(timerLedGre_counter > 0)
	{
		timerLedGre_counter --;
		if(timerLedGre_counter <= 0)
			timerLedGre_flag = 1;
	}

	if(segment1_counter > 0)
	{
		segment1_counter --;
		if(segment1_counter <= 0)
			segment1_flag = 1;
	}

	if(segment2_counter > 0)
	{
		segment2_counter --;
		if(segment2_counter <= 0)
			segment2_flag = 1;
	}


}

