/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{
	int i,n,x,l;
	int a[100];

	printf ("Enter number of elements: ");
	fflush (stdin); fflush (stdout);
	scanf ("%d", &n);
	for (i=0;i<n;i++)
	{
		fflush (stdin); fflush (stdout);
		scanf ("%d", &a[i]);
	}
	printf ("Entered the element to be inserted: \n");
	fflush (stdin); fflush (stdout);
	scanf ("%d", &x);
	printf ("Entered the location: \n");
	fflush (stdin); fflush (stdout);
	scanf ("%d", &l);
	for (i=n;i>=0;i--)
	{
		if (i==(l-1))
		{
			a[i]=x;
			break;
		}
		a[i]=a[i-1];
	}

	for (i=0;i<n+1;i++)
	{
		printf("%d",a[i]);
	}
}
