#include<stdio.h>
void main()
{
    char str[100];
    int i, length = 0;
    printf("enter a string: \n");
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        length++;
    }
    printf("length of string = %d", length);
}