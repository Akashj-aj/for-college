
/*Program to implement Job processing using priority queue*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int front=-1,rear=-1;
typedef struct process
{
 int pid;
 int pr;
}job;
job pjob[MAX];
void insert()
{
 int pid,pr;
 if(rear==MAX-1)
 {
  printf("Overflow\n");
 }
 else
 {
  for(int i=0;i<MAX;i++)
  {
  printf("Enter Process Number and its priority:\n");
  scanf("%d %d",&pid,&pr);
  if(rear==-1)
  {
   rear++;
   front++;
  }
 else
 {
  rear++;
 }
 pjob[rear].pid=pid;
 pjob[rear].pr=pr;
 }
}
}
void del()
{
 int i,pos=0,max=0;
 if(front==-1)
 {
  printf("Underflow\n");
 }
 else
 {
  if(front==rear)
  {
   front=-1;
   rear=-1;
  }
  else
  {
   for(i=front;i<=rear;i++)
   {
    if(pjob[i].pr>max)
    {
     max=pjob[i].pr;
     pos=i;
    }
   }
 for(i=pos;i<=rear;i++)
 {
  pjob[i].pid=pjob[i+1].pid;
  pjob[i].pr=pjob[i+1].pr;
 }
 rear--;
  }
 }
}

void display()
{
 if(front==-1)
 {
  printf("Queue is empty\n");
 }
 else
 {
  printf("Pid\t PR\n");
  for(int i=front;i<=rear;i++)
  {
   printf("%d\t %d\n",pjob[i].pid,pjob[i].pr);
  }
 }
}
void main()
{
 int ch;
 for(;;)
 {
   printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
   printf("Enter your choice\n");
   scanf("%d",&ch);
  switch(ch)
  {
   case 1:insert();
         break;
   case 2:del();
          display();
         break;
   case 3:display();
          break;
   case 4:exit(0);
          break;
   default:printf("\nInvalid choice\n");
           break;
  }
 }
}