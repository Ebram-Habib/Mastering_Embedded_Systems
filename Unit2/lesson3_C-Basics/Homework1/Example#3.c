/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{
	int x,y,sum;
	printf ("Enter two integers: ");
	fflush(stdin); fflush(stdout);
	scanf ("%d %d", &x, &y);
	fflush(stdin); fflush(stdout);
	sum = x + y;
	printf ("Sum: %d", sum);

}
