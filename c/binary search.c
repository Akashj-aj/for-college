#include <stdio.h>
#include <stdlib.h>
void main()
{
    int a[50], i, n, low, high, mid, key;
    printf("enter size of array: ");
    scanf("%d", &n);
    printf("enter the number to be found: ");
    scanf("%d", &key);
    for(i=0;i<n;i++)
    {
        printf("enter the number: ");
        scanf("%d",&a[i]);
    }
    printf("the array elements are: \n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    low = 0;
    high = n-1;
    while(low<high)
    {
        mid = (low+high)/2;
        if(key==a[mid])
        {
            printf("element is found at %d position",i+1);
            exit(0);
        }
        else if(key<a[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }
    printf("%d not found",key);
}
