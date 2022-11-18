#include "stdio.h"

void prime_numb (int a, int b);
int arr [1000], total_numbers;
int main()

{
	int i,x,y;
	printf("Enter two numbers(intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &x, &y);
	prime_numb(x,y);
	printf("Prime numbers between %d and %d are: ", x,y);
	for (i=0;i<total_numbers;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

 void prime_numb (int a, int b)

{
	 int i,j;
	 for(i=a+1;i<b;i++)
	 {
		 for(j=2;j<i;j++)
		 {
			 if(i%j == 0 && i != j)
			 {
				 break;
			 }

		 }
		 if(j==i)
			 {
			 arr[total_numbers]=i;
			 total_numbers++;
			 }
	 }

}
