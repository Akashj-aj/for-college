// write a program to add first 10 numbers.

#include<stdio.h>
void main()
{
	int sum = 0, i = 1;
	while (i<=10)
	{
		sum = sum + i;
		i = i + 1;
	}
	printf("sum = %d", sum);
}