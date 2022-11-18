/**** Q4_Write_a_program_in_C_to_print_the_elements_of_an_array_in_reverse_order. ****/

#include "stdio.h"

int main()
{
	int i, num_of_elements, arr [15];
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num_of_elements);
	int* p = &arr[num_of_elements-1];
	printf("Input %d number of elements in the array: \n", num_of_elements);

	for(i=0;i<num_of_elements;i++)
	{
		printf("element-%d: ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d", &arr[i]);
	}

	printf("\nThe elements of array in reverse order are : \n");

	for(i=num_of_elements;i>0;i--)
	{
		printf("element - %d : %d\n", i, *p);
		p--;
	}
	return 0;
}
