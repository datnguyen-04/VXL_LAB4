/*
 * traffic_led.h
 *
 *  Created on: Dec 12, 2024
 *      Author: thinkie
 */

#ifndef INC_TRAFFIC_LED_H_
#define INC_TRAFFIC_LED_H_

#include "global.h"

void offAllLeds();
void blinkingLeds(int mode);

void setRed1();
void setYellow1();
void setGreen1();

void setRed2();
void setYellow2();
void setGreen2();

#endif /* INC_TRAFFIC_LED_H_ */
