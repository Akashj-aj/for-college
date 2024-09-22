#include<stdio.h>
int fact(int);
void main()
{
    int n, res;
    printf("enter integer: \n");
    scanf("%d", &n);
    res = fact(n);
    printf("factorial of the number is: %d\n", res);
}
int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return (n*fact(n-1));
    }
}