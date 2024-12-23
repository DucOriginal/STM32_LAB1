/*
 * fsm_setting.c
 *
 *  Created on: Nov 15, 2024
 *      Author: Duc Original
 */

#include "fsm_setting.h"

void fsm_setting_run()
{
	set7LED();
	switch(status_manual)
	{
		case SETTING2:
			btn = SETTING2;
			if(isButton2Pressed() == 1)
			{
				btn = SETTING2;
				idle_counter = 0;
				counter_7seg2 = 2;
				status_manual = SETTING2;
				TurnOnRed();
				isButton1Pressed();
				isButton3Pressed();
				counter_7seg1++;
				if(counter_7seg1 >= 99)
				{
					counter_7seg1 = 1;
				}
			}
			if(timerLedRed_flag == 1)
			{
				blinkRED();
				idle_counter++;
				TurnOnRed();
			}
			if(idle_counter >= 20)
			{
				status1 = INIT;
				status2 = INIT;
				idle_counter = 0;
			}
			if(isButton1Pressed() == 1)
			{
				status_manual = MODE3;
				idle_counter = 0;
				TurnOnYel();
			}
			if(isButton3Pressed() == 1)
			{
				counter_red = counter_7seg1;
			}
		case SETTING3:
			btn = SETTING3;
			if(isButton2Pressed() == 1)
			{
				btn = SETTING3;
				idle_counter = 0;
				counter_7seg2 = 3;
				status_manual = SETTING3;
				isButton1Pressed();
				isButton3Pressed();
				TurnOnYel();
				counter_7seg1++;
				if(counter_7seg1 >= 99)
				{
					counter_7seg1 = 1;
				}
			}
			if(timerLedYel_flag == 1)
			{
				blinkYEL();
				idle_counter++;
				TurnOnYel();
			}
			if(idle_counter >= 20)
			{
				status1 = INIT;
				status2 = INIT;
				idle_counter = 0;
			}
			if(isButton1Pressed() == 1)
			{
				status_manual = MODE4;
				idle_counter = 0;
				TurnOnGre();
			}
			if(isButton3Pressed() == 1)
			{
				counter_yel = counter_7seg1;
			}
		case SETTING4:
			btn = SETTING4;
			if(isButton2Pressed() == 1)
			{
				idle_counter = 0;
				counter_7seg2 = 4;
				status_manual = SETTING4;
				isButton1Pressed();
				isButton3Pressed();
				TurnOnGre();
				counter_7seg1++;
				if(counter_7seg1 >= 99)
				{
					counter_7seg1 = 1;
				}
			}
			if(timerLedGre_flag == 1)
			{
				blinkGRE();
				idle_counter++;
				TurnOnGre();
			}
			if(idle_counter >= 20)
			{
				status1 = INIT;
				status2 = INIT;
				idle_counter = 0;
			}
			if(isButton1Pressed() == 1)
			{
				status1 = INIT;
				status2 = INIT;
				idle_counter = 0;
				mode1_flag = 1;
			}
			if(isButton3Pressed() == 1)
			{
				counter_gre = counter_7seg1;
			}

	}

}
