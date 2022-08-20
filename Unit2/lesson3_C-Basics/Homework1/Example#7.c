/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{

	int a,b;

	printf ("enter a: ");
	fflush (stdin); fflush (stdout);
	scanf ("%d", &a);
	printf ("enter b: ");
	fflush (stdin); fflush (stdout);
	scanf ("%d", &b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf ("a= %d \nb= %d", a, b);

}
