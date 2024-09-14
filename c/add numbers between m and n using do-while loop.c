#include <stdio.h>
void main()
{
	int m, n, i, sum = 0;
	printf("enter the lower and upper limit\n");
	scanf("%d %d", &m, &n);
	i = m;
	do
	{
		sum = sum+i;
	i = i+1;
	}while (i<=n);
	printf("sum = %d", sum);
}