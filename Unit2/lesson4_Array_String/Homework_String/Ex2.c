/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"
void main ()

{
	int i,strlen=0;
	char text[100];

	printf ("Enter a string: ");
	fflush (stdin); fflush (stdout);
	for (i=0;i<100;i++)
	{
		scanf ("%c",&text[i]);
		if (text[i]==10)
		{
			strlen=i;
			break;
		}
	}
	printf ("Length of string: %d", strlen);
}
