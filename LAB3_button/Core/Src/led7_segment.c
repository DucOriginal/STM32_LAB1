/*
 * led7_segment.c
 *
 *  Created on: Nov 14, 2024
 *      Author: Duc Original
 */
#include "led7_segment.h"
#include "main.h"
#include "button.h"

int counter_7seg1 = 0;
int counter_7seg2 = 0;
int btn = 0;
int index_led1 = 0;
int index_led2 = 0;
int segmentNumber1[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int segmentNumber2[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int led_buffer[4] = {1 , 2 , 3 , 4};

void display7SEG1(int num){
    int number = segmentNumber1[num];
	//Check a nth bit by shifting n times to the right, then bitwise AND it:
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, ((number>>0)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, ((number>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, ((number>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, ((number>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, ((number>>4)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, ((number>>5)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, ((number>>6)&0x01));
}

void display7SEG2(int num){
    int number = segmentNumber2[num];
	//Check a nth bit by shifting n times to the right, then bitwise AND it:
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, ((number>>0)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, ((number>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, ((number>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, ((number>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, ((number>>4)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, ((number>>5)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, ((number>>6)&0x01));
}

void updateClockBuffer(){
    //update values for the array led_buffer according to the values of hour and minute.
    led_buffer[0] = counter_7seg1/10;
    led_buffer[1] = counter_7seg1%10;
    led_buffer[2] = counter_7seg2/10;
    led_buffer[3] = counter_7seg2%10;
}


void update7SEG1 ( int index ){
	switch ( index ) {
	  case 0:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		  display7SEG1(led_buffer[0]);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		  display7SEG1(led_buffer[1]);
		  break;
	}
}

void update7SEG2 ( int index ){
	switch ( index ) {
	  case 0:
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		  display7SEG2(led_buffer[2]);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		  display7SEG2(led_buffer[3]);
		  break;
	}
}

void set7LED()
{
	if(segment1_flag == 1)
	{
		updateClockBuffer();
		if(index_led1 >= 2)
			index_led1 = 0;
		update7SEG1(index_led1++);
		setTimer7segment1(20);
	}

	if(segment2_flag == 1)
	{
		updateClockBuffer();
		if(index_led2 >= 2)
			index_led2 = 0;
		update7SEG2(index_led2++);
		setTimer7segment2(20);
	}
}
