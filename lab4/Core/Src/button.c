/*
 * button.c
 *
 *  Created on: Dec 12, 2024
 *      Author: thinkie
 */

#include "button.h"

static int buttonBuffer[NUM_OF_BUTTONS] = { RELEASE_STATE };
static int debounceButtonBuffer1[NUM_OF_BUTTONS] = { RELEASE_STATE };
static int debounceButtonBuffer2[NUM_OF_BUTTONS] = { RELEASE_STATE };
static int longPressButtonBuffer[NUM_OF_BUTTONS] = { RELEASE_STATE };

int button_flag[NUM_OF_BUTTONS];
int TimeOutForKeyPress[NUM_OF_BUTTONS];

void clearAllButtons() {
	for (int i = 0; i < NUM_OF_BUTTONS; i++) {
		debounceButtonBuffer1[i] = RELEASE_STATE;
		debounceButtonBuffer2[i] = RELEASE_STATE;
		buttonBuffer[i] = RELEASE_STATE;
	}
	HAL_GPIO_WritePin(BUTTON_1_GPIO_Port, BUTTON_1_Pin, RELEASE_STATE);
	HAL_GPIO_WritePin(BUTTON_2_GPIO_Port, BUTTON_2_Pin, RELEASE_STATE);
	HAL_GPIO_WritePin(BUTTON_3_GPIO_Port, BUTTON_3_Pin, RELEASE_STATE);
}

int isButtonPressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index) {
	button_flag[index] = 1;
}

void getKeyInput() {
	for (int i = 0; i < NUM_OF_BUTTONS; i++) {
		debounceButtonBuffer1[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = buttonBuffer[i];

		//Read signal from user
		if (i == 0) {
			buttonBuffer[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port,
			BUTTON_1_Pin);
		} else if (i == 1) {
			buttonBuffer[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port,
			BUTTON_2_Pin);
		} else if (i == 2) {
			buttonBuffer[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port,
			BUTTON_3_Pin);
		}
		//debouncing step
		if ((debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
				&& (debounceButtonBuffer2[i] == buttonBuffer[i])) {
			if (buttonBuffer[i] != longPressButtonBuffer[i]) {
				longPressButtonBuffer[i] = buttonBuffer[i];
				//when pressed, do subKeyProcess()
				if (buttonBuffer[i] == PRESSED_STATE) {
					TimeOutForKeyPress[i] = TIME_OUT_FOR_KEY_PRESS;
					subKeyProcess(i);
				}
			}

			else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0) {
					longPressButtonBuffer[i] = RELEASE_STATE;
				}
			}
		}
	}
}
