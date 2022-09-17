/**** EX1_C_Program_to_Store_Information(name,roll,marks)_of_a_student_Using_Structure ****/

#include "stdio.h"
#include "string.h"

struct SStudent
{
	char name [50];
	int roll;
	float marks;
};

struct SStudent gstudent;

int main()
{
	printf("Enter information of students: \n\n");
	printf("Enter name: ");
	gets(gstudent.name);
	fflush (stdin); fflush (stdin);
	printf("Enter roll: ");
	scanf("%d", &gstudent.roll);
	fflush (stdin); fflush (stdin);
	printf("Enter marks: ");
	scanf("%f", &gstudent.marks);
	fflush (stdin); fflush (stdin);
	printf("\nDisplaying Information \n");
	printf("name: %s\n", gstudent.name);
	printf("Roll: %d\n", gstudent.roll);
	printf("Marks: %.2f\n", gstudent.marks);

	return 0;
}
