/*
 * GPIO_Driver.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Ebram Habib
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "Platform_Types.h"
#include "Util.h"

#define GPIO_PORTA 0x40010800
#define BASE_RCC   0x40021000

#define APB2ENR   *(vuint32_t *)(BASE_RCC + 0x18)

#define GPIOA_CRL *(vuint32_t *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(vuint32_t *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(vuint32_t *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(vuint32_t *)(GPIO_PORTA + 0x0C)

void GPIO_Init (void);
void GPIO_Delay(uint32_t nCount);
uint32_t GPIO_Get_Pressure_Value(void);
void GPIO_Set_Alarm_LED(uint32_t i);

#endif /* GPIO_DRIVER_H_ */
