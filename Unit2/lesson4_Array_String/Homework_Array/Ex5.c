/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{
	int i,n,x,l,f=0;
	int a[100];

	printf ("Enter number of elements: ");
	fflush (stdin); fflush (stdout);
	scanf ("%d", &n);
	for (i=0;i<n;i++)
	{
		fflush (stdin); fflush (stdout);
		scanf ("%d", &a[i]);
	}
	printf ("Entered the elements to be searched: \n");
	fflush (stdin); fflush (stdout);
	scanf ("%d", &x);
	for (i=0;i<n;i++)
	{
		if (a[i]==x)
		{
			l=i+1;
			f=1;
			break;
		}
	}
	if (f==0)
	{
		printf ("Number not found ");
	}
	else
	printf ("Number found at the location: %d",l);
}
