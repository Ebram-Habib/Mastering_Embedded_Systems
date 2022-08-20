/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{

	float a,output;

	for (output=1;output<3;output++)
	{
		printf ("Enter a number: ");
		fflush (stdin); fflush (stdout);
		scanf ("%f", &a);
		if (a>0)
		{
			printf ("%f is positive.\n", a);
		}
		else if (a<0)
		{
			printf ("%f is negative.\n", a);
		}
		else
			printf ("You entered Zero.\n", a);
	}
}
