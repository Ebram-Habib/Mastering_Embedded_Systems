/*
 * main.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#include "Platform_Types.h"
#include "Util.h"

#include "GPIO_Driver.h"
#include "Pressure_Sensor_Driver.h"
#include "Alarm_LED_Driver.h"
#include "Alarm_Monitor.h"
#include "Main_Algorithm.h"

void (*PS_state)() = STATE(PS_INIT);
void (*ALARM_LED_state)() = STATE(ALARM_LED_INIT);
void (*ALARM_MONITOR_state)() = STATE(ALARM_MONITOR_ALARM_OFF);
void (*MA_state)() = STATE(MA_HIGH_PRESSURE);

int main(void)
{
	// System Initialization
	GPIO_Init();

	// Run The Program Forever
	while (1)
	{
		PS_state();
		ALARM_LED_state();
		ALARM_MONITOR_state();
		MA_state();
	}

	return 0;
}
