// write a program to read a character from the user, check whether the enteered character is a vowel or consonant, print appropriate messages

#include<stdio.h>
void main()
{
	char vowel;
	printf("enter the character:\n");
	scanf("%c",&vowel);
	if ((vowel=='a')||(vowel=='A'))
		printf("character is a vowel");
	else if ((vowel=='e')||(vowel=='E'))
		printf("character is a vowel");
	else if ((vowel=='i')||(vowel=='I'))
		printf("character is a vowel");
	else if ((vowel=='o')||(vowel=='O'))
		printf("character is a vowel");
	else if ((vowel=='u')||(vowel=='U'))
		printf("character is a vowel");
	else
		printf("character is a consonant");
}