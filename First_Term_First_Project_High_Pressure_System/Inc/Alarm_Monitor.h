/*
 * Alarm_Monitor.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "State.h"

//Declare State Functions of Alarm Monitor
STATE_DEFINE(ALARM_MONITOR_ALARM_OFF);
STATE_DEFINE(ALARM_MONITOR_ALARM_ON);
STATE_DEFINE(ALARM_MONITOR_WAITING);

//State Pointer to function
extern void (*ALARM_MONITOR_state)();

#endif /* ALARM_MONITOR_H_ */
