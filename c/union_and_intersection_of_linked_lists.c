
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if (x==NULL)
    {
	printf("Out of memory\n");
	exit(0);
    }
    return x;
}

/*Insert rear */
NODE insert_rear(int item, NODE first)
{
    NODE temp, cur;
    temp=getnode();
    
    temp->info=item;
    temp->link=NULL;
    
    if(first==NULL) //list is empty
    {
	return temp;
    }
    
    cur=first;
    while(cur->link!=NULL)
    {
	cur=cur->link;
    }
    
    cur->link=temp;
    return first;
}


/*Display contents*/
void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
	printf("List is empty\n");
	return;
    }
    cur=first;
    while(cur!=NULL)
    {
	printf("%d\t",cur->info);
	cur=cur->link;
    }
    printf("\n");
}

/*Search an element*/
int search(int key, NODE first)
{
    NODE cur;
    if(first==NULL)
    {
	printf("List is empty\n");
	return 0;                  //Search is unsuccessful
    }
    cur=first;
    while(cur!=NULL)
    {
	if(key==cur->info)
	   return 1;
	cur=cur->link;
    }
    return 0;
}

/*Function to remove duplicate elements from the list*/

NODE remove_duplicate(NODE first)
{
   NODE a,b;
   int flag;
   if(first==NULL)        //Empty list
      return  NULL;

   a=first;
   b=NULL;               //Existing list
   while(a!=NULL)         //Traverse the entire list
   {
      flag=search(a->info,b); /*Search for item in new list b*/
      /*if not found insert into new list*/
      if(flag==0)
	 b=insert_rear(a->info,b);
      a=a->link;		//access next item in the list
   }
   return b;
}


/*Function to find union of two lists*/

NODE union_of_list(NODE first, NODE second)
{
   NODE a,third;
   int flag;
   a=first;        //access first list using variable a

   /* Add all elements of first list to the end of resultant list*/
   third=NULL;     //Initial resultant list
   while(a!=NULL)
   {
      third=insert_rear(a->info,third);
      a=a->link;
   }

   //Search for each item of second list in third list.
   //If not found add into third list

   a=second;
   while(a!=NULL)
   {
      flag=search(a->info,third);
      if(flag==0)
	 third=insert_rear(a->info,third);
      a=a->link;
   }
   return third;
}

/* Function to find intersection of two lists*/

NODE intersection_of_list(NODE first,NODE second)
{
   NODE a, b, third;
   int flag;
   a=first;
   b=second;
   third=NULL;
   while(a!=NULL)
   {
      flag=search(a->info,b);
      if(flag==1)            //if found then insert into third list
	third=insert_rear(a->info,third);
      a=a->link;
   }
   return third;
}


void main()
{
   int item,choice,i,n;
   NODE first,second,third;
   clrscr();
   for(;;)
   {
      printf("\n1:Create first list\n2:Create second list\n");
      printf("3:Remove duplicates of list 1\n4:Remove duplicates of list 2\n");
      printf("5:Union of two lists\n6:Intersection of two lists\n7:Exit\n");
      printf("Enter the choice:");
      scanf("%d",&choice);
      switch(choice)
      {
	 case 1:printf("Enter the number of nodes in first list:");
		scanf("%d",&n);
		first=NULL;
		for(i=1;i<=n;i++)
		{
		   printf("\nEnter the item:");
		   scanf("%d",&item);
		   first=insert_rear(item,first);
		}
		printf("\nContents of first list\n");
		display(first);
		break;
	 case 2:printf("Enter the number of nodes in second list:");
		scanf("%d",&n);
		second=NULL;
		for(i=1;i<=n;i++)
		{
		   printf("\nEnter the item:");
		   scanf("%d",&item);
		   second=insert_rear(item,second);
		}
		printf("\nContents of second list\n");
		display(second);
		break;
	 case 3:printf("The first list before removing duplicates:\n");
		display(first);
		first=remove_duplicate(first);
		printf("The first list after removing duplicates:\n");
		display(first);
		break;
	 case 4:printf("The second list before removing duplicates:\n");
		display(second);
		second=remove_duplicate(second);
		printf("The second list after removing duplicates:\n");
		display(second);
		break;
	 case 5:printf("The first list\n");
		display(first);
		printf("The second list\n");
		display(second);
		third=union_of_list(first,second);
		printf("The union of two lists\n");
		display(third);
		break;
	 case 6:printf("The first list\n");
		display(first);
		printf("The second list\n");
		display(second);
		third=intersection_of_list(first,second);
		printf("The intersection of two lists\n");
		display(third);
		break;
	 default:exit(0);
      }
   }
   getch();
}
