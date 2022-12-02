/*
 * Platform_Types.h
 *
 *  Created on: Dec 2, 2022
 *      Author: Ebram Habib
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#define CPU_TYPE 			CPU_TYPE_32
#define CPU_BIT_ORDER 		LSB_FIRST
#define CPU_BYTE_ORDER 		LOW_BYTE_FIRST

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef unsigned char 		boolean;

typedef signed char			sint8_t;
typedef unsigned char		uint8_t;

typedef signed short		sint16_t;
typedef unsigned short		uint16_t;

typedef signed int          sint32_t;
typedef unsigned int        uint32_t;

typedef signed long	long	sint64_t;
typedef unsigned long long	uint64_t;

typedef float				float32_t;
typedef double				float64_t;

typedef volatile sint8_t		vint8_t;
typedef volatile uint8_t		vuint8_t;

typedef volatile sint16_t		vint16_t;
typedef volatile uint16_t		vuint16_t;

typedef volatile sint32_t		vint32_t;
typedef volatile uint32_t		vuint32_t;

typedef volatile sint64_t		vint64_t;
typedef volatile uint64_t		vuint64_t;

#endif /* PLATFORM_TYPES_H_ */
