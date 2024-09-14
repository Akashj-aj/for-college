// Q. write a program to print ASCII value of a given character
#include <stdio.h>
void main()
{
    char ch;
    printf("enter character: \n");
    scanf("%c", &ch);
    printf("ASCII of %c = %d", ch, ch);
}