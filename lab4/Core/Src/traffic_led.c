/*
 * traffic_led.c
 *
 *  Created RESET: Dec 12, 2024
 *      Author: thinkie
 */

#include "traffic_led.h"

void blinkingLeds(int mode) {
    switch (mode) {
        case MODE2:
            // Blink red LEDs
            HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
            HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
            break;

        case MODE3:
            // Blink yellow LEDs
            HAL_GPIO_TogglePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin);
            HAL_GPIO_TogglePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin);
            break;

        case MODE4:
            // Blink green LEDs
            HAL_GPIO_TogglePin(GREEN_1_GPIO_Port, GREEN_1_Pin);
            HAL_GPIO_TogglePin(GREEN_2_GPIO_Port, GREEN_2_Pin);
            break;

        default:
            break;
    }
}

void offAllLeds() {
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);

	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
}

void setRed1() {
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
}
void setYellow1() {
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, RESET);
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
}
void setGreen1() {
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, RESET);
}

void setRed2() {
	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
}
void setYellow2() {
	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, RESET);
	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
}
void setGreen2() {
	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, RESET);
}
