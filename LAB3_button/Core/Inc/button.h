/*
 * button.h
 *
 *  Created on: Nov 13, 2024
 *      Author: Duc Original
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

void getKeyInput();


#endif /* INC_BUTTON_H_ */
