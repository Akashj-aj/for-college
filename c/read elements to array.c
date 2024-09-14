#include<stdio.h>
void main()
{
	int a[5],i;
	for(i = 0; i <= 4; i++)
	{
		printf("enter elements: %d",i++);
		scanf("%d"&a[i]);
	}
}