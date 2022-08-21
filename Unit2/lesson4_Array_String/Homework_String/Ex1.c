/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"
void main ()

{
	int i,counter=0,strlen=0;
	char text[100],character;

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
	printf ("Entered a character to find frequency: \n");
	fflush (stdin); fflush (stdout);
	scanf ("%c", &character);
	for (i=0;i<strlen;i++)
	{
		if (text[i] == character)
		{
			counter++;
		}
	}
	printf ("Frequency of %c = %d", character, counter);
}
