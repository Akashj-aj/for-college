// write a program to add the numbers b/w m and n using while loop.

#include<stdio.h>
void main()
{
	int m,n, sum = 0, i;
	printf("enter the lower an dupper limit:\n");
	scanf("%d %d", &m, &n);
	i = m;
	while (i<=n)
	{
		sum = sum+i;
		i = i+1;
	}
	printf("sum = %d", sum);
}