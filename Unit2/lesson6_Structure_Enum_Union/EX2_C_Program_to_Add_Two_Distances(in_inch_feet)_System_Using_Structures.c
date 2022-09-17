/**** EX2_C_Program_to_Add_Two_Distances(in_inch_feet)_System_Using_Structures) ****/

#include "stdio.h"

struct SDistance
{
	int feet;
	float inch;
};

struct SDistance gfirst_distance, gsecond_distance, Sum;

int main()
{
	printf("Enter information for 1st distance \n");
	printf("Enter feet: ");
	scanf("%d", &gfirst_distance.feet);
	printf("Enter inch: ");
	scanf("%f", &gfirst_distance.inch);
	printf("Enter information for 2nd distance \n");
	printf("Enter feet: ");
	scanf("%d", &gsecond_distance.feet);
	printf("Enter inch: ");
	scanf("%f", &gsecond_distance.inch);
	Sum.feet = gfirst_distance.feet + gsecond_distance.feet;
	Sum.inch = gfirst_distance.inch + gsecond_distance.inch;
	if(Sum.inch>=12)
	{
		Sum.feet++;
		Sum.inch-=12;
	}
	printf("Sum of distances= %d'-%.1f\"", Sum.feet, Sum.inch);
	return 0;
}
