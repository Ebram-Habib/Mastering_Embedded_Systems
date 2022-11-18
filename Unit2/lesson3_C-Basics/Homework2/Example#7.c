/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{

	int a,i,fact=1,output;

	for (output=1;output<3;output++)
	{
		printf ("Enter an integer: ");
		fflush (stdin); fflush (stdout);
		scanf ("%d", &a);

		if (a<0)
			printf ("Error!!! factorial of negative number doesn't exit\n");
		else if (a==0)
			printf ("Factorial = 1\n");
		else
		{
			for (i=1;i<=a;i++)
			{
				fact *= i;
			}

			printf ("Factorial = %d", fact);
		}
	}
}
