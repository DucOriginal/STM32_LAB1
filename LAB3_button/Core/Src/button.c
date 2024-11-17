/*
 * button.c
 *
 *  Created on: Nov 13, 2024
 *      Author: Duc Original
 */
#include "button.h"
#include "software_timer.h"

#define NO_OF_BUTTONS 3
int keyReg01,keyReg02,keyReg03 = NORMAL_STATE;
int keyReg11,keyReg12,keyReg13 = NORMAL_STATE;
int keyReg21,keyReg22,keyReg23 = NORMAL_STATE;
int keyReg31,keyReg32,keyReg33 = NORMAL_STATE;

int TimerForKeyPress1 = 200;
int TimerForKeyPress2 = 200;
int TimerForKeyPress3 = 200;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;


int isButton1Pressed()
{
	if(button1_flag == 1)
	{
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed()
{
	if(button2_flag == 1)
	{
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed()
{
	if(button3_flag == 1)
	{
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess1(){
	button1_flag = 1;
}

void subKeyProcess2(){
	button2_flag = 1;
}

void subKeyProcess3(){
	button3_flag = 1;
}

void getKeyInput()
{
	//////////////////For Button 1////////////////////
	keyReg01 = keyReg11;
	keyReg11 = keyReg21;
	keyReg21 = HAL_GPIO_ReadPin(Button1_GPIO_Port,Button1_Pin);

	if((keyReg01 == keyReg11) && (keyReg11 == keyReg21))
	{
		if(keyReg31 != keyReg21)
		{
			keyReg31 = keyReg21;
			if(keyReg21 == PRESSED_STATE)
			{
				subKeyProcess1();
				TimerForKeyPress1 = 200;
			}
		}
		else{
			TimerForKeyPress1--;

			if(TimerForKeyPress1 == 0)
			{
				//if(keyReg21 == PRESSED_STATE)
					keyReg31 = NORMAL_STATE;
			}
		}
	}
	//////////////////For Button 2////////////////////
	keyReg02 = keyReg12;
	keyReg12 = keyReg22;
	keyReg22 = HAL_GPIO_ReadPin(Button2_GPIO_Port,Button2_Pin);

	if((keyReg02 == keyReg12) && (keyReg12 == keyReg22))
	{
		if(keyReg32 != keyReg22)
		{
			keyReg32 = keyReg22;
			if(keyReg22 == PRESSED_STATE)
			{
				subKeyProcess2();
				TimerForKeyPress2 = 200;
			}
		}
		else{
			TimerForKeyPress2--;
			if(TimerForKeyPress2 == 0)
			{
				keyReg32 = NORMAL_STATE;
			}
		}
	}
	//////////////////For Button 3////////////////////
	keyReg03 = keyReg13;
	keyReg13 = keyReg23;
	keyReg23 = HAL_GPIO_ReadPin(Button3_GPIO_Port,Button3_Pin);

	if((keyReg03 == keyReg13) && (keyReg13 == keyReg23))
	{
		if(keyReg33 != keyReg23)
		{
			keyReg33 = keyReg23;
			if(keyReg23 == PRESSED_STATE)
			{
				subKeyProcess3();
				TimerForKeyPress3 = 200;
			}
		}
		else{
			TimerForKeyPress3--;
			if(TimerForKeyPress3 == 0)
			{
				keyReg33 = NORMAL_STATE;
			}
		}
	}

}

