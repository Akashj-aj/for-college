#include<stdio.h>
void main()
{
    char s1[100], s2[100];
    int i;
    printf("enter two strings:\n");
    gets(s1);
    gets(s2);
    while (s1[i] == s2[i] && s1[i]!='\0')
    {
        i++;
    }
    if (s1[i]>s2[i])
    {
        printf("string 1 is greater");
    }
    else if (s1[i]<s2[i]) 
    {
        printf("string 2 is greater");
    }
    else
    {
        printf("both strings are equal");
    }
}