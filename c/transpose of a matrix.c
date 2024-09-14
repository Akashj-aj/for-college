#include<stdio.h>
void main()
{
	int c,i,j,r,a[10][10],t[10][10];
	printf("enter number of rows and coloums:\n");
	scanf("%d %d",&r,&c);
	printf("enter elements of matrix:\n" );
	for(i =0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	}
	printf("the given matrix is: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("the transpose of given matrix \n");
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d\t",a[j][i]);
		}
		printf("\n");
	}
}