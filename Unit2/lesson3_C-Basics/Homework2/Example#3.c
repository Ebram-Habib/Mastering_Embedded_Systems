/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{

	float a,b,c;

	printf ("Enter three numbers: ");
	fflush (stdin); fflush (stdout);
	scanf ("%f %f %f", &a, &b, &c);
	if (a>b)
	{
		if (a>c)
			printf ("Largest number = %f", a);
		else if (c>a)
			printf ("Largest number = %f", c);
	}
	else if (b>a)
	{
		if (b>c)
			printf ("Largest number = %f", b);
		else if (c>b)
			printf ("Largest number = %f", c);
	}
}
