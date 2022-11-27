/*
 * State.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#ifndef STATE_H_
#define STATE_H_

#include "GPIO_Driver.h"

// State function generation
#define STATE_DEFINE(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

//States Connections
// Pressure Sensor =====> Main Algorithm
uint32_t PS_get_pressure_value(void);

// Alarm LED =====> Alarm Monitor
void ALARM_LED_start_alarm(void);

// Alarm LED =====> Alarm Monitor
void ALARM_LED_stop_alarm(void);

// Main Algorithm =====> Alarm Monitor
uint32_t MA_high_pressure_detected(void);

#endif /* STATE_H_ */
