#include <stdio.h>

int main() 
{
    int a[5], i, n, sum = 0, average;
    printf("enter the number of elements of the array: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("enter array element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        sum = sum + a[i];
    }
    printf("sum of the array element: %d ", sum);
}
