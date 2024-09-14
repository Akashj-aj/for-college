/* Q. write a program to accept grades acquired by the students in final assesment.
O - oustanding
A - excellent
B - good
C - fair
D - fail
write a program using if-else-if to print the grade of the student
*/

#include <stdio.h>
void main()
{
	char grad;
	printf("enter grade: [O, A, B, C, D]\n");
	scanf("%c", &grad);
	if(grad == 'O')
		printf("outstanding");
	else if(grad == 'A')
		printf("excellent");
	else if(grad == 'A')
		printf("good");
	else if(grad == 'B')
		printf("fair");
	else if(grad == 'C')
		printf("fail");
	else
		printf("invalid grade");
}