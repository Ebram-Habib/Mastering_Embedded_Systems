/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ebram
 */

#include "stdio.h"

void main ()

{
	float a,b,temp;
	printf ("Enter value of a: ");
	fflush(stdin); fflush(stdout);
	scanf ("%f", &a);
	fflush(stdin); fflush(stdout);
	printf ("Enter value of b: ");
	fflush(stdin); fflush(stdout);
	scanf ("%f", &b);
	temp=a;
	a=b;
	b=temp;
	printf ("After swapping, value of a = %f \n", a);
	printf ("After swapping, value of b = %f", b);

}
