/*
 * Util.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#ifndef UTIL_H_
#define UTIL_H_

#define	GET_BIT(reg,n)				(((reg)>>(n))&1)
#define SET_BIT(reg,n)				(reg|=(1<<n))
#define CLR_BIT(reg,n)				(reg&=~(1<<n))
#define TOGGLE_BIT(reg,n)			(reg^=(1<<n))

#endif /* UTIL_H_ */
