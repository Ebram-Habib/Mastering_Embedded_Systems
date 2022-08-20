/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{

	char a,output;

	for (output=1;output<3;output++)
	{
		printf ("Enter a character: ");
		fflush (stdin); fflush (stdout);
		scanf ("%c", &a);
		if ((a >= 65) && (a < 91))
		{
			printf ("%c is an alphabet.\n", a);
		}
		else if ((a >= 97) && (a< 122))
		{
			printf ("%c is an alphabet.\n", a);
		}
		else
			printf ("%c is not an alphabet.\n", a);
	}
}
