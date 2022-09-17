/**** EX5_C_Program_to_find_area_of_a_circle_by_passing_arguments_to_macros ****/

#include "stdio.h"

#define pi 3.1415
#define area(r) (pi*(r)*(r))

int main()
{
	int radius;
	float area;
	printf("Enter the radius: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &radius);
	area = area(radius);
	printf("Area = %.2f", area);
	return 0;
}
