/*
 * fsm_automatic.c
 *
 *  Created on: Nov 14, 2024
 *      Author: Duc Original
 */

#include "fsm_automatic.h"

void fsm_automatic_run()
{
	set7LED(); // Display all 4 7-SEG Leds

	// Set up Traffic 1
	switch(status1){
		case INIT:
			initial1();
			status1 = AUTO_RED; //change INIT to AUTO_RED
			counter_7seg1 = counter_red; //counter_7seg1 displays the Traffic 1's 7-LEDs.
			setTimer1(counter_red);
			break;
		case AUTO_RED:
			setRED1(); //turn on red led.
			if(timer1_flag == 1)
			{
				status1 = AUTO_GRE;
				setTimer1(counter_gre);
			}
			//if Button 1 is pressed, it moves on MODE1:
			if(isButton1Pressed() == 1)
			{
				//if mode1_flag = 1, it will be MODE1,
				//else if mode1_flag  = 2, it will be MODE 2
				mode1_flag++;
			}
			break;
		case AUTO_YEL:
			setYEL1();
			if(timer1_flag == 1)
			{
				status1 = AUTO_RED;
				setTimer1(counter_red);
			}
			if(isButton1Pressed() == 1)
			{
				mode1_flag++;
			}
			break;
		case AUTO_GRE:
			setGRE1();
			if(timer1_flag == 1)
			{

				status1 = AUTO_YEL;
				setTimer1(counter_yel);
			}
			if(isButton1Pressed() == 1)
			{
				mode1_flag++;
			}
			break;
		default:
			break;

	}
//-------------------------------------------------
	// Set up Traffic 2
	switch(status2){
		case INIT:
			initial2();
			status2 = AUTO_GRE;
			counter_7seg2 = counter_gre;
			setTimer2(counter_gre);
			break;
		case AUTO_RED:
			setRED2();
			if(timer2_flag == 1)
			{
				status2 = AUTO_GRE;
				setTimer2(counter_gre);
			}
			break;
		case AUTO_YEL:
			setYEL2();
			if(timer2_flag == 1)
			{
				status2 = AUTO_RED;
				setTimer2(counter_red);
			}
			break;
		case AUTO_GRE:
			setGRE2();
			if(timer2_flag == 1)
			{
				status2 = AUTO_YEL;
				setTimer2(counter_yel);
			}
			break;
		default:
			break;

	}
///////////////////////////////////////////////////////////
	//We don't need set mode1_flag for Traffic 2.
	//With mode1_flag = 1, it will change from the AUTO state to the MODE state.
	//At MODE1, there is nothing changed. It means that it runs normally.
	//At MODE2, it means mode1_flag = 2, the system change MODE1 to MODE2.
	if(mode1_flag ==2)
	{
		status_manual = MODE1;
		status1 = status2 = status_manual;
		setTimer1(0);
		setTimer2(0);
	}
}
