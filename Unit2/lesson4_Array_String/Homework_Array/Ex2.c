/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{
	int i,n;
	float a[100],avg=0;

	printf ("Enter the numbers of data: ");
	fflush (stdin); fflush (stdout);
	scanf ("%d", &n);
	for (i=0;i<n;i++)
	{
			printf ("Enter number: ");
			fflush (stdin); fflush (stdout);
			scanf ("%f", &a[i]);
			avg += a[i];
		}
	printf ("Average = %.2f", avg/n);
	}

