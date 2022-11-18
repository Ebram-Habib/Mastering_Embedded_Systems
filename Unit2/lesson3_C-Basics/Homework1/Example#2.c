/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{
	int x;
	printf ("Enter an integer:");
	fflush(stdin); fflush(stdout);
	scanf ("%d", &x);
	fflush(stdin); fflush(stdout);
	printf ("You entered: %d", x);

}
