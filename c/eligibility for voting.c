// Q. write a program to check eleigibility for voting and print appropriate message in each case
#include <stdio.h>
void main()
{
	int age;
	printf("enter age: \n");
	scanf("%d", &age);
	if (age>=18)
		printf("eligible for voting");
	else
		printf("ineligible");
}