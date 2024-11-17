/*
 * global.h
 *
 *  Created on: Nov 14, 2024
 *      Author: Duc Original
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "led7_segment.h"
#include "traffic_light.h"

extern int status1;
extern int status2;
extern int status_manual;
extern int status_counting;
extern int mode1_flag;
extern int mode2_flag;
extern int idle_counter;
extern int first_press;

#define INIT	1
#define AUTO_RED 2
#define AUTO_YEL 3
#define AUTO_GRE 4

#define MODE1 11
#define MODE2 5
#define MODE3 6
#define MODE4 7

#define SETTING2 8
#define SETTING3 9
#define SETTING4 12

#endif /* INC_GLOBAL_H_ */
