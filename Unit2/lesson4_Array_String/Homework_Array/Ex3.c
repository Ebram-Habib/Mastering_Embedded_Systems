/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{
	int i,j,r,c;
	int a[100][100],t[100][100];

	printf ("Enter rows and column of matrix: ");
	fflush (stdin); fflush (stdout);
	scanf ("%d%d", &r,&c);
	printf ("Enter elements of matrix: \n");

	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf ("Enter elements a%d%d: ", i+1, j+1);
			fflush (stdin); fflush (stdout);
			scanf ("%d", &a[i][j]);

		}
	}
	printf ("Entered Matrix: \n");

	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf ("%d \t", a[i][j]);
		}
		printf("\n");
	}

	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			t[j][i]=a[i][j];
		}
	}
	printf("Transpose of Matrix:\n");

	for (i=0;i<c;i++)
	{
		for (j=0;j<r;j++)
		{
			printf ("%d \t", t[i][j]);
		}
		printf("\n");
	}
}
