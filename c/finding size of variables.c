// Q. write a program to find siz of variables
#include<stdio.h>
void main()
{
	int intType;
	float floatType;
	char charType;
	double doubleType;
	printf("size of integer = %zu \n", sizeof(intType));
	printf("size of float = %zu \n", sizeof(floatType));
	printf("size of character = %zu \n", sizeof(charType));
	printf("size of double = %zu \n", sizeof(doubleType));
}