// Q. write a program to check whether the given number is odd or even
#include<stdio.h>
void main()
{
	int a;
	printf("enter the number: \n");
	scanf("%d", &a);
	if ((a%2)==0)
		printf("%d is even", a);

	else
		printf("%d is odd", a);
}