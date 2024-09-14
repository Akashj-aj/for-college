#include<stdio.h>
void main()
{
	int num, digit, rev=0, temp;
	printf("enter number\n");
	scanf("%d",&num);
	temp = num;
	while(num!=0)
	{
		digit = num%10;
		num = num/10;
		rev = rev*10+digit;
	}
	if(rev==temp)
		printf("the number is a palindrome");
	else
		printf("the number is not a palindrome");
}