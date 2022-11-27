/*
 * Alarm_Monitor.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#include "Alarm_Monitor.h"

// Defining the states
enum {
    ALARM_MONITOR_ALARM_OFF,
    ALARM_MONITOR_ALARM_ON,
    ALARM_MONITOR_WAITING
}ALARM_MONITOR_Status;

STATE_DEFINE(ALARM_MONITOR_ALARM_OFF)
{
	// State Action
	ALARM_MONITOR_Status = ALARM_MONITOR_ALARM_OFF;

	// Stop alarm LED
	ALARM_LED_stop_alarm();

	// Check event and update state
	if(MA_high_pressure_detected() == TRUE)
	{
		ALARM_MONITOR_state = STATE(ALARM_MONITOR_ALARM_ON);
	}
}

STATE_DEFINE(ALARM_MONITOR_ALARM_ON)
{
	// State Action
	ALARM_MONITOR_Status = ALARM_MONITOR_ALARM_ON;

	// Start alarm LED
	ALARM_LED_start_alarm();

	// Check event and update state
	ALARM_MONITOR_state = STATE(ALARM_MONITOR_WAITING);
}

STATE_DEFINE(ALARM_MONITOR_WAITING)
{
	// State Action
	ALARM_MONITOR_Status = ALARM_MONITOR_WAITING;

	GPIO_Delay(1000);

	// Check event and update state
	ALARM_MONITOR_state = STATE(ALARM_MONITOR_ALARM_OFF);
}
