/*
 * button.h
 *
 *  Created on: Dec 12, 2024
 *      Author: thinkie
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define BUTTON_1				0
#define BUTTON_2				1
#define	BUTTON_3				2
#define RELEASE_STATE 				SET
#define PRESSED_STATE 				RESET
#define NUM_OF_BUTTONS				3
#define TIME_OUT_FOR_KEY_PRESS		200

extern int button_flag[NUM_OF_BUTTONS];

void getKeyInput();
void subKeyProcess(int index);
int isButtonPressed(int index);

#endif /* INC_BUTTON_H_ */
