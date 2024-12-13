/*
 * global.c
 *
 *  Created on: Dec 12, 2024
 *      Author: thinkie
 */

#include "global.h"

int mode = INIT;
int nmode = init;

int yellowTime;
int greenTime;
int redTime;

int segModeTime;
int segValueTime;

void initValues() {
	yellowTime = YELLOW_TIME;
	greenTime = GREEN_TIME;
	redTime = RED_TIME;
	segModeTime = redTime;
	segValueTime = greenTime;
	mode = INIT;
	nmode = init;
}
