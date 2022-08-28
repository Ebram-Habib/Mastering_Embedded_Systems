#include "stdio.h"
#include "string.h"

void power_of_number(int a, int b);
int total=1;

int main()

{
	int x,y;
	printf("Enter base number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);
	printf("Enter power number(positive integer): ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &y);
	power_of_number(x,y);
	printf("%d^%d = %d", x, y, total);
	return 0;
}

void power_of_number(int a, int b)
{
	if (b>0)
	{
		total *= a;
		b--;
		power_of_number(a,b);
	}
}
