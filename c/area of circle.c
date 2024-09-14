// Q. write a program to compute area of circle
#include <stdio.h>
void main()
{
    float radius, area;
    printf("enter radius: \n");
    scanf("%f", &radius);
    area = 3.14 * radius * radius;
    printf("area of circle: %f", area);
}