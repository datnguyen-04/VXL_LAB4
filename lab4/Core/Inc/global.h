/*
 * global.h
 *
 *  Created on: Dec 12, 2024
 *      Author: thinkie
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "button.h"
#include "traffic_led.h"
#include "normal_mode.h"
#include "traffic_process.h"
#include "led_display.h"

#define TIMER_CYCLE		10

#define MODE_0_7SEG		0
#define MODE_1_7SEG		1
#define VALUE_0_7SEG	2
#define VALUE_1_7SEG	3

#define YELLOW_TIME		2
#define GREEN_TIME		3
#define RED_TIME		5

#define INIT 			0
#define MODE1			1
#define MODE2 			2
#define MODE3	 		3
#define MODE4			4

#define NUM_OF_MODES	4

extern int redTime;
extern int yellowTime;
extern int greenTime;
extern int segModeTime;
extern int segValueTime;

extern int mode;
extern int nmode;

void initValues();

#endif /* INC_GLOBAL_H_ */
