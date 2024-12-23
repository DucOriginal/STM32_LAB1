/*
 * traffic_light.c
 *
 *  Created on: Nov 14, 2024
 *      Author: Duc Original
 */

#include "traffic_light.h"
#include "software_timer.h"
#include "main.h"

void initial1()
{
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
	HAL_GPIO_WritePin(LED_YEL1_GPIO_Port, LED_YEL1_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, 0);
}

void initial2()
{
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
	HAL_GPIO_WritePin(LED_YEL2_GPIO_Port, LED_YEL2_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, 0);
}

void setRED1()
{
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
	HAL_GPIO_WritePin(LED_YEL1_GPIO_Port, LED_YEL1_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, 0);
}
void setRED2()
{
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1);
	HAL_GPIO_WritePin(LED_YEL2_GPIO_Port, LED_YEL2_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, 0);
}
void setYEL1()
{
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
	HAL_GPIO_WritePin(LED_YEL1_GPIO_Port, LED_YEL1_Pin, 1);
	HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, 0);
}
void setYEL2()
{
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
	HAL_GPIO_WritePin(LED_YEL2_GPIO_Port, LED_YEL2_Pin, 1);
	HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, 0);
}
void setGRE1()
{
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
	HAL_GPIO_WritePin(LED_YEL1_GPIO_Port, LED_YEL1_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, 1);
}
void setGRE2()
{
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
	HAL_GPIO_WritePin(LED_YEL2_GPIO_Port, LED_YEL2_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, 1);
}

void blinkRED()
{
	HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
	HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
//	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
//	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1);
	HAL_GPIO_WritePin(LED_YEL1_GPIO_Port, LED_YEL1_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, 0);
	HAL_GPIO_WritePin(LED_YEL2_GPIO_Port, LED_YEL2_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, 0);
}

void blinkYEL()
{
	HAL_GPIO_TogglePin(LED_YEL1_GPIO_Port, LED_YEL1_Pin);
	HAL_GPIO_TogglePin(LED_YEL2_GPIO_Port, LED_YEL2_Pin);
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, 0);
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
	HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, 0);
}

void blinkGRE()
{
	HAL_GPIO_TogglePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin);
	HAL_GPIO_TogglePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin);
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
	HAL_GPIO_WritePin(LED_YEL1_GPIO_Port, LED_YEL1_Pin, 0);
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
	HAL_GPIO_WritePin(LED_YEL2_GPIO_Port, LED_YEL2_Pin, 0);
}




