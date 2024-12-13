/*
 * traffic_process.c
 *
 *  Created on: Dec 12, 2024
 *      Author: thinkie
 */

#include "traffic_process.h"

int segOrder;
int setTime;

void trafficRun() {
	//traffic system works as 4 modes
	switch (mode) {
	//Init mode, in here we preset all values then change to MODE1
	case INIT: {
		segOrder = 2;
		segRun1();
		setTimer2(500);
		mode = MODE1;
		break;
	}
	case MODE1: {
		//In MODE1, we have 2 traffic systems to control
		normalMode();
		if (timer2_flag == 1) {
			setTimer2(500);
			if (segOrder == 2) {
				segRun2();
				segValueTime--;
				segModeTime--;
				segOrder = 0;
			} else {
				segRun1();
			}
			segOrder++;
		}
		//if we press button 1, system will change to MODE2
		if (isButtonPressed(BUTTON_1) == 1) {
			setTimer2(500);
			setTime = redTime;
			segModeTime = MODE2;
			segValueTime = redTime;
			mode = MODE2;
			offAllLeds();
		}
		break;
	}
	case MODE2: {
		//In MODE2, we use button 2 and 3 to adjust duration of red light
		if (timer2_flag == 1) {
			setTimer2(500);
			blinkingLeds(MODE2);
			if (segOrder == 2) {
				segRun2();
				segOrder = 0;
			} else {
				segRun1();
			}
			segOrder++;
		}
		//if we press button 1, system will change to MODE3
		if (isButtonPressed(BUTTON_1) == 1) {
			setTimer2(500);
			setTime = yellowTime;
			segModeTime = MODE3;
			segValueTime = yellowTime;
			mode = MODE3;
			offAllLeds();
		}
		//if we press button 2, duration of red light will increase 1s
		if (isButtonPressed(BUTTON_2) == 1) {
			if (setTime > 99) {
				setTime = 1;
			}
			setTime++;
			segValueTime = setTime;
		}
		//if we press button 3, system will save the change to red light
		if (isButtonPressed(BUTTON_3) == 1) {
			redTime = setTime;
			segValueTime = redTime;
		}
		break;
		//MODE3 is similar to MODE2
	}
	case MODE3: {
		if (timer2_flag == 1) {
			setTimer2(500);
			blinkingLeds(MODE3);
			if (segOrder == 2) {
				segRun2();
				segOrder = 0;
			} else {
				segRun1();
			}
			segOrder++;
		}
		if (isButtonPressed(BUTTON_1) == 1) {
			setTimer2(500);
			setTime = greenTime;
			segModeTime = MODE4;
			segValueTime = greenTime;
			mode = MODE4;
			offAllLeds();
		}
		if (isButtonPressed(BUTTON_2) == 1) {
			if (setTime > 99) {
				setTime = 1;
			}
			setTime++;
			segValueTime = setTime;
		}
		if (isButtonPressed(BUTTON_3) == 1) {
			yellowTime = setTime;
			segValueTime = yellowTime;
		}
		break;
		//MODE4 is similar to MODE1
	}
	case MODE4: {
		if (timer2_flag == 1) {
			setTimer2(500);
			blinkingLeds(MODE4);
			if (segOrder == 2) {
				segRun2();
				segOrder = 0;
			} else {
				segRun1();
			}
			segOrder++;
		}
		if (isButtonPressed(BUTTON_1) == 1) {
			nmode = init;
			segOrder = 2;
			segRun1();
			setTimer2(500);
			mode = MODE1;
		}
		if (isButtonPressed(BUTTON_2) == 1) {
			if (setTime > 99) {
				setTime = 1;
			}
			setTime++;
			segValueTime = setTime;
		}
		if (isButtonPressed(BUTTON_3) == 1) {
			greenTime = setTime;
			segValueTime = greenTime;
		}
		break;
	}
	default:
		break;
	}
}
