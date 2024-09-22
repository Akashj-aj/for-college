#include<stdio.h>
int fib(int);
void main()
{
    int n, i=0, c;
    printf("enter N value: \n");
    scanf("%d", &n);
    for(c=1; c<=n; c++)
    {
        printf("%d\t", fib(i));
        i++;
    }
}
int fib(int n)
{
    if (n==0 || n==1)
    {
        return n;
    }
    else
    {
        return (fib(n-1) + fib(n-2));
    }
}