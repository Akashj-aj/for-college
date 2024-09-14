#include<stdio.h>
#include<stdlib.h>
void main()
{
    int r,c,i,j;
    printf("enter rows and coloumns: \n");
    scanf("%d%d",&r,&c);
    int *arr[r];
    for(i=0;i<r;i++)
    {
        arr[i] = (int*)calloc(c, sizeof (int));
    }
    printf("enter array elements: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("2D array:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    free(arr);
}