#include<stdio.h>
void main()
{
	int fac, i, n;
	printf("enter the number:\n");
	scanf("%d",&n);
	for(fac=1,i=1; i<=n; i++)
		fac = fac*i;
	printf("the factorial of %d is %d", n, fac);
}