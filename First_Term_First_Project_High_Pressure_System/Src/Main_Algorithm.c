/*
 * Main_Algorithm.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */


#include "Main_Algorithm.h"

// Define the states
enum {
	MA_HIGH_PRESSURE
}MA_Status;

static uint32_t MA_pressure_value;
static uint32_t MA_pressure_threshold = 20;

STATE_DEFINE(MA_HIGH_PRESSURE)
{
	// State Action
	MA_Status = MA_HIGH_PRESSURE;

	// Read pressure value from pressure sensor
	MA_pressure_value = PS_get_pressure_value();

	// Check event and update state
	MA_state = STATE(MA_HIGH_PRESSURE);
}

// Main Program =====> Alarm Monitor
uint32_t MA_high_pressure_detected(void)
{
	return (MA_pressure_value >= MA_pressure_threshold);
}
