/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{
	float x,y,product;
	printf ("Enter two numbers: ");
	fflush(stdin); fflush(stdout);
	scanf ("%f %f", &x, &y);
	fflush(stdin); fflush(stdout);
	product = x * y;
	printf ("product: %f", product);

}
