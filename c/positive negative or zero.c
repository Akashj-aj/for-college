// write a program to read an integer value and check if the number is positive, negative or zero(0). Use appropriate constraints in c.

#include<stdio.h>
void main()
{
	int n;
	printf("enter the number\n");
	scanf("%d",&n);
	if (n>0)
		printf("the number is positive\n");
	else if (n<0)
		printf("the number is negative\n");
	else
		printf("the number is 0\n");
}