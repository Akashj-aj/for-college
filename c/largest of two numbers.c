// Q. write a program to find largest of two numbers using conditional operators
#include<stdio.h>
void main()
{
	int a,b;
	printf("enter two numbers: \n");
	scanf("%d %d", &a, &b);
	if (a>b)
		printf("a = %d is greater",a);
	else
		printf("b = %d is greater",b);
}