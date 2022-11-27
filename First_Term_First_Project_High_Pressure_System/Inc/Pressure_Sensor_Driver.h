/*
 * Pressure_Sensor_Driver.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

#include "State.h"

//Declare State Functions of Pressure Sensor
STATE_DEFINE(PS_INIT);
STATE_DEFINE(PS_READING);
STATE_DEFINE(PS_WAITIMG);

//State Pointer to function
extern void (*PS_state)();

#endif /* PRESSURE_SENSOR_DRIVER_H_ */
