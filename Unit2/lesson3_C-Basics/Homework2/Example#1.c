/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{

	int a, output;

	for (output=1; output<3 ; output++)
	{
		printf ("enter an integer you want to check: ");
		fflush (stdin); fflush (stdout);
		scanf ("%d", &a);
		if ((a % 2) == 1)
		{
			printf ("%d is odd\n", a);
		}
		else if ((a % 2) == 0)
		{
			printf ("%d is even\n", a);
		}
	}

}
