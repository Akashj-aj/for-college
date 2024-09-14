#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *arr, i, n;
    printf("enter the number of elements: \n");
    scanf("%d",&n);
    arr = (int*)calloc(n, sizeof (int));
    if (arr == NULL)
    {
        printf("memory allocation failed");
    }
    else
    {
        printf("enter array elements: \n");
        for (i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
    }
    printf("the array elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    free(arr);
}