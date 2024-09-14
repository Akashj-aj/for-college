#include<stdio.h>
void main()
{
    int arr[10][10];
    int i, j, m, n, count = 0;
    printf("enter the order of the matrix: \n");
    scanf("%d%d",&m,&n);
    printf("enter the elements of the matrix: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j] == 0)
            {
                count++;
            }
        }
    }
    if (count > ((m*n)/2))
    {
        printf("sparse matrix");
    }
    else
    {
        printf("not sparse matrix");
    }
    
}