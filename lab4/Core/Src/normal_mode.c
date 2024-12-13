/*
 * normal_mode.c
 *
 *  Created on: Dec 12, 2024
 *      Author: thinkie
 */

#include "normal_mode.h"

void normalMode() {
	switch (nmode) {
	case init: {
		setTimer1(greenTime * 1000);
		segModeTime = redTime;
		segValueTime = greenTime;
		setRed1();
		setGreen2();
		nmode = mode1;
		break;
	}
	case mode1: {
		if (timer1_flag == 1) {
			setTimer1(yellowTime * 1000);
			setYellow2();
			segValueTime = yellowTime;
			nmode = mode2;
		}
		break;
	}
	case mode2: {
		if (timer1_flag == 1) {
			setTimer1(greenTime * 1000);
			setGreen1();
			setRed2();
			segModeTime = greenTime;
			segValueTime = redTime;
			nmode = mode3;
		}
		break;
	}
	case mode3: {
		if (timer1_flag == 1) {
			setTimer1(yellowTime * 1000);
			setYellow1();
			segModeTime = yellowTime;
			nmode = mode4;
		}
		break;
	}
	case mode4: {
		if (timer1_flag == 1) {
			setTimer1(greenTime * 1000);
			setRed1();
			setGreen2();
			segModeTime = redTime;
			segValueTime = greenTime;
			nmode = mode1;
		}
		break;
	}
	default:
		break;
	}
}
