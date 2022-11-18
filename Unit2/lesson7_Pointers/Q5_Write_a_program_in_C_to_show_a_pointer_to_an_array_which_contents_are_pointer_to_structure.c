/**** Q5_Write_a_program_in_C_to_show_a_pointer_to_an_array_which_contents_are_pointer_to_structure. ****/

#include "stdio.h"

struct Employees
{
	char name [20];
	int ID;
};

int main()
{
	struct Employees emp1 = {"Ebram",7}, emp2 = {"Alex",1002};
	struct Employees (*arr_of_emp [2])= {&emp1,&emp2};
	struct Employees (*(*p)[2]) = &arr_of_emp;
	printf("Employee Name : %s\nEmployee ID : %d", (**(*p+1)).name, (*(*p+1))->ID);
	return 0;
}
