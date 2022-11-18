#include "stdio.h"
#include "string.h"

void str_rev (int x);
char sentence[100];
int length;
int main()

{
	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	gets (sentence);
	length= strlen(sentence);
	str_rev(length);
	return 0;
}

void str_rev (int x)
{
	if (x>=0)
	{
	printf("%c", sentence[x]);
	x--;
	str_rev(x);
	}

}
