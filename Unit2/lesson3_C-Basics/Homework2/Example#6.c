/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{

	int a,i,sum=0;

	printf ("Enter an integer: ");
	fflush (stdin); fflush (stdout);
	scanf ("%d", &a);

	for (i=1;i<=a;i++)
	{
		sum += i;
	}

	printf ("Sum = %d", sum);
}
