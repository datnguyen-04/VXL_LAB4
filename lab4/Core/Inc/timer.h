/*
 * timer.h
 *
 *  Created on: Dec 11, 2024
 *      Author: thinkie
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "global.h"

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

extern void setTimer1(int duration);
extern void setTimer2(int duration);
extern void setTimer3(int duration);
void timeRun();

#endif /* INC_TIMER_H_ */
