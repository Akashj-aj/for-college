
/*6.  Design, Develop and implement C program for the following operations on doubly linked list.
      a. Create doubly linked list of N nodes with integer data by adding each node at the front.
     b. Delete the node of a given data if it is found, otherwise display appropriate message.
     c. insert a node to the left of the node whose key value is read as input.
     d. Display the contents of the list.*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
 };
typedef struct node *NODE;

NODE getnode();
NODE ins(int item, NODE first);
NODE insl(int item,int itemleft,NODE first);
NODE del(int item,NODE first);
void disp(NODE first);
void main()
{
     int ch,item,itemleft;
     NODE first=NULL;
     for(;;)
     {
	     printf("\nChoices:");
	     printf("\n\t1-Insert");
	     printf("\n\t2-Insert left");
	     printf("\n\t3-Delete node");
	     printf("\n\t4-Display");
	     printf("\n\t5-Exit");
	     printf("\nEnter your choice: ");
	     scanf("%d",&ch);
	     switch(ch)
	     {
		     case 1: printf("Enter the element to be inserted:");
			     scanf("%d",&item);
			     first=ins(item,first);
			     break;
		     case 2: printf("Enter the element to be inserted:");
			     scanf("%d",&item);
			     printf("Enter the element to the left of which item should be inserted:");
			     scanf("%d",&itemleft);
			     first=insl(item,itemleft,first);
			     break;
		     case 3: printf("Enter the item to be deleted:");
			     scanf("%d",&item);
			     first=del(item,first);
			     break;
		     case 4: disp(first);
			     break;
		     default:exit(0);
	     }
     }

}

NODE getnode()
{
     NODE x;
     x=(NODE) malloc(sizeof(struct node));
     if(x==NULL)
     {
	 printf("Insufficient Memory\n");
	 exit(0);
     }
     return x;
}

NODE ins(int item, NODE first)
{
     NODE temp;
     temp=getnode();
     temp->info=item;
     temp->llink=NULL;
     temp->rlink=NULL;
     if(first==NULL)
	     first=temp;
     else
     {
	     temp->rlink=first;
	     first->llink=temp;
	     first=temp;
     }
     return first;
}

NODE insl(int item, int itemleft,NODE first)
{
     NODE temp,cur;
     if(first==NULL)
     {
	     printf("\nEmpty list\n");
	     return;
     }
     temp=getnode();
     temp->info=item;
     temp->llink=NULL;
     temp->rlink=NULL;
     cur=first;
     if(first->info==itemleft)
     {
	     temp->rlink=first;
	     first->llink=temp;
	     first=temp;
     }
     else
     {
	     while(cur!=NULL)
	     {
		     if(cur->info==itemleft)
			     break;
		     cur=cur->rlink;
	     }
	     if(cur!=NULL)
	     {
		     temp->llink=cur->llink;
		     (cur->llink)->rlink=temp;
		     temp->rlink=cur;
		     cur->llink=temp;
	     }
	     else
		     printf("\nNo element found");

     }
     return first;
}

/*Function to delete the node of the given data*/
NODE del(int item,NODE first)
{
     NODE cur,prev,temp;
     int x;
     cur=first;
     prev=NULL;
     if(first==NULL)
     {
	     printf("\nLinked list is empty\n");
	     return NULL;
     }
     if(cur->info==item)
     {
	     temp=first;
	     first=first->rlink;
	     first->llink=NULL;
	     free(temp);
	     return first;
     }
     else
     {
	     while(cur->rlink!=NULL)
	     {

		     if(cur->info==item)
			break;
		     prev=cur;
		     cur=cur->rlink;
	     }
	     if(cur!=NULL)
	     {
	     temp=cur->rlink;
	     prev->rlink=temp;
	     temp->llink=prev;
	     printf("Item deleted = %d",cur->info);
	     free(cur);
	     }
	     else
		printf("Element not found");
	}
	return first;
}

/*Function to display the contents of the doubly linked list*/
void disp(NODE first)
{
     NODE cur;
     if(first==NULL)
	     printf("List is empty");
     else
     {
	     for(cur=first;cur!=NULL;cur=cur->rlink)
		     printf("%d ",cur->info);
     }
}