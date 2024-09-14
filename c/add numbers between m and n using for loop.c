#include <stdio.h>
void main()
{
	int m, n, i, sum;
	printf("enter the lower and upper limit:\n");
	scanf("%d %d", &m, &n);
	for (sum = 0, i = m; i<=n; i = i+1)
	{
		sum = sum + i;

	}
	printf("sum = %d", sum);
}