/*
 * Pressure_Sensor_Driver.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */


#include "Pressure_Sensor_Driver.h"

// Defining the States
enum {
	PS_INIT,
	PS_READING,
	PS_WAITIMG
}PS_Status;

static uint32_t PS_pressure_value ;

STATE_DEFINE(PS_INIT)
{
	// Initialize the pressure sensor
	// Call the pressure sensor driver functions
	// State Action
	PS_Status = PS_INIT;

	// Check event and update state
	PS_state = STATE(PS_READING);
}

STATE_DEFINE(PS_READING)
{
	// State Action
	PS_Status = PS_READING;

	// Read form pressure sensor
	PS_pressure_value = GPIO_Get_Pressure_Value();

	// Check event and update state
	PS_state = STATE(PS_WAITIMG);
}

STATE_DEFINE(PS_WAITIMG)
{
	// State Action
	PS_Status = PS_WAITIMG;

	// Wait for data
	GPIO_Delay(1000);

	// Check event and update state
	PS_state = STATE(PS_READING);
}


// Set pressure in Main Algorithm
uint32_t PS_get_pressure_value()
{
	return PS_pressure_value;
}
