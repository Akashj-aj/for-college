#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *arr,i,n,m;
    printf("enter number of elements: \n");
    scanf("%d",&n);
    arr = (int*)malloc(n*sizeof(int)); // or (int*)calloc(n,sizeof(int));
    if (arr==NULL)
    {
        printf("memory allocation failed\n");
    }
    else
    {
        printf("enter the array elements\n");
        for(i = 0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("enter addtional M elements:\n");
        scanf("%d",&m);
        arr = (int*)realloc(arr,m);
        printf("enter additional array elements:\n");
        for(i=0;i<m+n;i++)
        {
            scanf("%d",&arr[i]);
        }
    }
        printf("the array elements are:\n");
        for (i=0;i<m+n;i++)
        {
            printf("%d",arr[i]);
        }
    free(arr);
}