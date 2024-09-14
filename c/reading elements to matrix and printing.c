#include<stdio.h>
void main()
{
	int c, i, j, r, a[10][10];
	printf("enter the number of rows and coloumns: \n");
	scanf("%d %d", &r, &c);
	printf("enter the elements of the matrix: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d", &a[i][j]);
	}
	printf("the given matrix is : \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}	
}