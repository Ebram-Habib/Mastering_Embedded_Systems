#include "stdio.h"

int fact (int a);
int temp=1;
int main()

{
	int x,y;
	printf("Enter a positive integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);
	y= fact(x);
	printf("Factorial of %d = %d", x, y);
	return 0;
}

int fact (int a)
{
	if(a>0)
	{
		temp *= a;
		a--;
		fact(a);
	}
	return temp;
}
