/*
 * Alarm_LED_Driver.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#include "Alarm_LED_Driver.h"

// Defining the States
enum {
	ALARM_LED_INIT,
	ALARM_LED_WAITING,
	ALARM_LED_ON,
	ALARM_LED_OFF,
}ALARM_LED_Status;

STATE_DEFINE(ALARM_LED_INIT)
{
	// Initialize the alarm LED driver
	// Call the alarm LED driver functions
	// State Action
	ALARM_LED_Status = ALARM_LED_INIT;

	// Check event and update state
	ALARM_LED_state = STATE(ALARM_LED_WAITING);
}

STATE_DEFINE(ALARM_LED_WAITING)
{
	// State Action
	ALARM_LED_Status = ALARM_LED_WAITING;
}

STATE_DEFINE(ALARM_LED_ON)
{
	// State Action
	ALARM_LED_Status = ALARM_LED_ON;

	// Start Alarm Actuator
	GPIO_Set_Alarm_LED(TRUE);

	// Check event and update state
	ALARM_LED_state = STATE(ALARM_LED_WAITING);
}

STATE_DEFINE(ALARM_LED_OFF)
{
	// State Action
	ALARM_LED_Status = ALARM_LED_OFF;

	// Start Alarm Actuator
	GPIO_Set_Alarm_LED(FALSE);

	// Check event and update state
	ALARM_LED_state = STATE(ALARM_LED_WAITING);
}

void ALARM_LED_start_alarm(void)
{
	// Update State
	ALARM_LED_state = STATE(ALARM_LED_ON);
}

void ALARM_LED_stop_alarm(void)
{
	// Update State
	ALARM_LED_state = STATE(ALARM_LED_OFF);
}
