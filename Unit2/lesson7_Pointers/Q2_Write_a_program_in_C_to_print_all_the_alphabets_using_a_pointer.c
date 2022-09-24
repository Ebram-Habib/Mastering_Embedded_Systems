/**** Q2_Write_a_program_in_C_to_print_all_the_alphabets_using_a_pointer. ****/

#include "stdio.h"

int main()
{
	int i;
	char letter = 'A';
	char* p = &letter;

	printf("The Alphabets are: \n");

	for(i=0;i<26;i++)
	{
		printf("%c\t", *p+i);
	}

	return 0;
}
