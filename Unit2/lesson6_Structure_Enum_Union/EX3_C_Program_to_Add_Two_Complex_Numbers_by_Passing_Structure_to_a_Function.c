/**** EX3_C_Program_to_Add_Two_Complex_Numbers_by_Passing_Structure_to_a_Function ****/

#include "stdio.h"

struct SComplex_Number
{
	double real;
	double imaginary;
};

struct SComplex_Number g1st_num, g2nd_num, Sum;

struct SComplex_Number Add_Comp_nums(struct SComplex_Number num1, struct SComplex_Number num2)
{
	struct SComplex_Number res;
	res.real = num1.real + num2.real;
	res.imaginary = num1.imaginary + num2.imaginary;
	return res;
}

int main()
{
	printf("For 1st complex number \n");
	printf("Enter real and imaginary respectively: ");
	scanf("%lf %lf", &g1st_num.real, &g1st_num.imaginary);
	printf("For 2nd complex number \n");
	printf("Enter real and imaginary respectively: ");
	scanf("%lf %lf", &g2nd_num.real, &g2nd_num.imaginary);
	Sum = Add_Comp_nums(g1st_num, g2nd_num);
	printf("Sum = %.1lf+%.1fi", Sum.real, Sum.imaginary);
	return 0;
}
