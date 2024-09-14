#include<stdio.h>
#include<string.h>
struct student
{
	int roll;
	char name[50];
	int marks[6];
};
void main()
{
	struct student s[10];
	int i,j,m,n,sum;
	float avg;
	printf("enter number of students\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter details of student: %d\n",i+1);
		printf("enter roll number of student\n");
		scanf("%d",&s[i].roll);
		printf("enter name of student\n");
		scanf("%s",&s[i].name);
		printf("enter the marks of each subject\n");
		for(j=0;j<6;j++)
			{
				scanf("%d",&s[i].marks[j]);
			}
	}
	for(i=0;i<n;i++)
	{
		sum = 0, avg = 0;
		for(j=0;j<6;j++)
			{
				sum = sum+s[i].marks[j];
			}
		avg = (float)sum/6;
		printf("roll number: %d\nname: %s\navg marks: %f \n", s[i].roll,s[i].name, avg);
		if(avg>=80&&avg<=100)
			printf("DISTINCTION\n");
		else if(avg>=60&&avg<=79)
			printf("FIRST CLASS\n");
		else if(avg>=40&&avg<=59)
			printf("SECOND CLASS\n");
		else 
			printf("FAIL\n");
	}
}