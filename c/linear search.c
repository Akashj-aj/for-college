#include <stdio.h>
void main()
{
    int a[50], i, n, key, flag = 0;
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
    for(i=0;i<n;i++)
    {
        if(key==a[i])
        {
            printf("%d is found in array at %d position", key, i+1);
            flag = 1;
            break;
        }
    }
    if (flag==0)
        printf("\n %d not found", key);
}