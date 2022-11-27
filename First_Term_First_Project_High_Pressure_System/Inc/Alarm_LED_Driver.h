/*
 * Alarm_LED_Driver.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#ifndef ALARM_LED_DRIVER_H_
#define ALARM_LED_DRIVER_H_

#include "State.h"

//Declare State Functions of Alarm LED
STATE_DEFINE(ALARM_LED_INIT);
STATE_DEFINE(ALARM_LED_WAITING);
STATE_DEFINE(ALARM_LED_ON);
STATE_DEFINE(ALARM_LED_OFF);

//State Pointer to function
extern void (*ALARM_LED_state)();

#endif /* ALARM_LED_DRIVER_H_ */
