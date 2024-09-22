#include<stdio.h>
#include<math.h>
void tower(int n, char S, char T, char D)
{
    if(n == 0)
    {
        return;
    }
    else
    {
        tower(n-1, S, D, T);
        printf("move disk %d from %c to %c \n", n, S, D);
        tower(n-1, T, S, D);
    }
}
void main()
{
    int n;
    printf("enter the number of disks: \n");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C');
    printf("number of moves = %d", (int)(pow(2,n)-1));
}