/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{
	int i,j;
	float a[2][2],b[2][2],c[2][2];

	printf ("Enter the elements of 1st matrix \n");
	for (i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
			printf ("Enter a%d%d: ",i+1,j+1);
			fflush (stdin); fflush (stdout);
			scanf ("%f", &a[i][j]);
		}
	}
	printf ("Enter the elements of 2nd matrix \n");
	for (i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
			printf ("Enter b%d%d: ",i+1,j+1);
			fflush (stdin); fflush (stdout);
			scanf ("%f", &b[i][j]);
		}
	}

	for (i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	printf ("Sum of matrix:\n");

	for (i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
			printf ("%.1f\t", c[i][j]);
		}
		printf ("\n");
	}
}
