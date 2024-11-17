/*
 * fsm_manual.c
 *
 *  Created on: Nov 15, 2024
 *      Author: Duc Original
 */


#include "fsm_manual.h"

void fsm_manual_run()
{
	set7LED();
	switch(status_manual)
	{
		case MODE1:
			//Check status to see whether it is on MODE1 or MODE2.
			//mode1_flag  = 1 -> MODE1 else MODE2
			mode1_flag = 1;
			first_press = 0; //check whether button 2 is pressed first or not.
			counter_7seg1 = 1; // display value
			TurnOnRed(); //Set timer for blinking all red LEDs. [0.5s]
			status_manual = MODE2; // move to MODE 2
			break;
		case MODE2:
			counter_7seg2 = 2; //display mode
			if(timerLedRed_flag == 1)
			{
				blinkRED();
				idle_counter++;
				TurnOnRed();
			}
			//if the system doesn't receive any signal, it will move to MODE1 (in essence, the AUTO mode) after 10s.
			if(idle_counter >= 20)
			{
				idle_counter = 0; // check the idle status.
				mode1_flag = 1;
				status1 = INIT;
				status2 = INIT;
			}
			if(isButton1Pressed() == 1)
			{
				//change to the next mode.
				first_press = 0;
				idle_counter = 0;
				counter_7seg1 = 1;
				TurnOnYel();
				status_manual = MODE3;
			}
			if(isButton2Pressed() == 1)
			{
				//if button 2 is pressed at the first time, the value is 2.
				//Because of changing mode, the value is 1 in default.
				if(first_press == 0)
				{
					counter_7seg1 = 2;
					first_press = 1;
				}
				else // count up the value by 1.
					counter_7seg1++;

				// if the value is up to 100, it changes to 1.
				if(counter_7seg1 >= 100)
				{
					counter_7seg1 = 1;
				}
				counter_7seg2 = 2; // display mode.
				idle_counter = 0;
				TurnOnRed();
				status_manual = MODE2;

			}
			if(isButton3Pressed() == 1)
			{
				//if button 3 is pressed , set the timer for red led.
				counter_red = counter_7seg1;
				status_manual = MODE2;
			}
			break;
		case MODE3:
			counter_7seg2 = 3;
			if(timerLedYel_flag == 1)
			{
				blinkYEL();
				idle_counter++;
				TurnOnYel();
			}
			if(idle_counter >= 20)
			{
				idle_counter = 0;
				mode1_flag =1;
				status1 = INIT;
				status2 = INIT;
			}
			if(isButton1Pressed() == 1)
			{
				idle_counter = 0;
				first_press = 0;
				counter_7seg1 = 1;
				TurnOnGre();
				status_manual = MODE4;
			}
			if(isButton2Pressed() == 1)
			{
				if(first_press == 0)
				{
					counter_7seg1 = 2;
					first_press = 1;
				}
				else
					counter_7seg1++;

				if(counter_7seg1 >= 100)
				{
					counter_7seg1 = 1;
				}
				counter_7seg2 = 3;
				idle_counter = 0;
				TurnOnYel();
				status_manual = MODE3;
			}
			if(isButton3Pressed() == 1)
			{
				counter_yel = counter_7seg1;
				status_manual = MODE3;
			}
			break;
		case MODE4:
			counter_7seg2 = 4;
			if(timerLedGre_flag == 1)
			{
				blinkGRE();
				idle_counter++;
				TurnOnGre();
			}
			if(idle_counter >= 20)
			{
				//Here, it goes back to MODE 1 after 10s.
				idle_counter = 0;
				mode1_flag = 1;
				status1 = INIT;
				status2 = INIT;
			}
			if(isButton1Pressed() == 1)
			{
				//change all to MODE 1(in essence, go back to AUTO status)
				idle_counter = 0;
				mode1_flag = 1;
				first_press = 0;
				status_manual = 0;
				status1 = INIT;
				status2 = INIT;
			}
			if(isButton2Pressed() == 1)
			{
				if(first_press == 0)
				{
					counter_7seg1 = 2;
					first_press = 1;
				}
				else
					counter_7seg1++;

				if(counter_7seg1 >= 100)
				{
					counter_7seg1 = 1;
				}
				idle_counter = 0;
				TurnOnGre();
				status_manual = MODE4;
			}
			if(isButton3Pressed() == 1)
			{
				counter_gre = counter_7seg1;
				status_manual = MODE4;
			}
			break;
		default:
			break;
	}






}
