/*
 * Main_Algorithm.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_

#include "State.h"

//Declare State Functions of Main Algorithm
STATE_DEFINE(MA_HIGH_PRESSURE);

//State Pointer to function
extern void (*MA_state)();

#endif /* MAIN_ALGORITHM_H_ */
