/*
 * led7_segment.h
 *
 *  Created on: Nov 14, 2024
 *      Author: Duc Original
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_
#include "software_timer.h"

extern int segmentNumber1[10];
extern int segmentNumber2[10];
extern int led_buffer[4];
extern int counter_7seg1;
extern int counter_7seg2;
extern int index_led1;
extern int index_led2;
extern int btn;


void display7SEG1(int num);
void display7SEG2(int num);
void updateClockBuffer();
void update7SEG1 ( int index );
void update7SEG2 ( int index );
void checkBTN();
void set7LED();


#endif /* INC_LED7_SEGMENT_H_ */
