/**** Q1_Write_a_program_in_C_to_demonstrate_how_to_handle_the_pointers_in_the_program ****/

#include "stdio.h"

int main()
{
	int m = 29;

	printf("Address of m : 0x%x \n", &m);
	printf("Value of m : %d \n", m);

	int* ab = &m;
	printf("\nNow ab is assigned with the address of m. \n");
	printf("Address of pointer ab : 0x%x \n", ab);
	printf("Content of pointer ab : %d \n", *ab);

	m = 34;
	printf("\nThe value of m assigned to 34 now. \n");
	printf("Address of pointer ab : 0x%x \n", ab);
	printf("Content of pointer ab : %d \n", *ab);

	*ab = 7;
	printf("\nThe pointer variable ab is assigned with the value 7 now. \n");
	printf("Address of m : 0x%x \n", &m);
	printf("Value of m : %d \n", m);

	return 0;
}
