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
		printf ("enter an alphabet: ");
		fflush (stdin); fflush (stdout);
		scanf ("%c", &a);

		switch (a)

		{

		case 'A':
			printf ("%c is a vowel", a);
			break;
		case 'I':
			printf ("%c is a vowel", a);
			break;
		case 'O':
			printf ("%c is a vowel", a);
			break;
		case 'E':
			printf ("%c is a vowel", a);
			break;
		case 'U':
			printf ("%c is a vowel", a);
			break;
		case 'a':
			printf ("%c is a vowel", a);
			break;
		case 'i':
			printf ("%c is a vowel", a);
			break;
		case 'o':
			printf ("%c is a vowel", a);
			break;
		case 'e':
			printf ("%c is a vowel", a);
			break;
		case 'u':
			printf ("%c is a vowel", a);
			break;
		default:
			printf ("%c is a consonant", a);
		}

		printf ("\n");

	}
}
