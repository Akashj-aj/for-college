// Q. write a program to compute simple interest
#include<stdio.h>
void main()
{
	int p,n,r,si;
	printf("enter principle, ROI and time: \n");
	scanf("%d %d %d", &p,&r, &n);
	si = (p*n*r)/100;
	printf("simple interest is: %d", si);
}