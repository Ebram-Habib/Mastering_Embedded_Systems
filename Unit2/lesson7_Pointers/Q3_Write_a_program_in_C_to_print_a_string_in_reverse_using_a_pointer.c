/**** Q3_Write_a_program_in_C_to_print_a_string_in_reverse_using_a_pointer. ****/

#include "stdio.h"
#include "string.h"

int main()
{
	int i, last_letter;
	char string [100];
	char* p;

	printf("Print a string : ");
	fflush(stdin); fflush(stdout);
	scanf("%s", string);
	last_letter = (strlen(string)-1);
	p = &string[last_letter];

	printf("Reverse of the string is : ");

	for(i=last_letter;i>=0;i--)
	{
		printf("%c", *p);
		p--;
	}

	return 0;
}
