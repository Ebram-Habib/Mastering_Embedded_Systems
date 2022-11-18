/**** EX4_C_Program_to_Store_Information_of_Students_Using_Structure ****/

#include "stdio.h"

struct SStudent
{
	int roll;
	char name [50];
	float marks;
};

struct SStudent gstudent_data [10];

int main()
{
	int i;
	printf("Enter information of students: \n");
	for(i=0;i<10;i++)
	{
		printf("For roll number %d\n", i+1);
		gstudent_data[i].roll = i+1;
		printf("Enter name: ");
		scanf("%s", gstudent_data[i].name);
		printf("Enter marks: ");
		scanf("%f", &gstudent_data[i].marks);
	}

	printf("\nDisplaying information of students: \n\n");

	for(i=0;i<10;i++)
	{
		printf("Information for roll number %d:\n", gstudent_data[i].roll);
		printf("Name: %s\n", gstudent_data[i].name);
		printf("Marks: %.f\n", gstudent_data[i].marks);
	}
	return 0;
}
