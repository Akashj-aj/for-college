#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 5

int s[STACK_SIZE], top;

void push(int item) {
    if (top == STACK_SIZE - 1) 
    {
        printf("Stack overflow\n");
        return;
    }
    s[++top] = item;
}

int pop() {
    if (top == -1) 
    {
        printf("Stack underflow\n");
        return -1; 
    }
    return s[top--];
}

void display() {
    if (top == -1) 
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Contents of the stack:\n");
    for (int i = 0; i <= top; i++) 
    {
        printf("%d\n", s[i]);
    }
}

int is_palindrome(char str[]) 
{
    int length = strlen(str);
    char stack[length];
    int stack_top = -1;

    for (int i = 0; i < length; i++) 
    {
        stack[++stack_top] = str[i];
    }

    for (int i = 0; i < length; i++) 
    {
        if (str[i] != stack[stack_top--]) 
        {
            return 0;
        }
    }
    return 1;
}

int main() 
{
    int item, item_deleted;
    char str[20];
    int choice, flag;

    top = -1; 
    while (1) 
    {
        printf("Please enter your choice: \n1. Push \n2. Pop \n3. Display \n4. Palindrome check\n");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
            {
                int num_items;
                printf("Enter the number of items to be pushed (up to %d): \n", STACK_SIZE - top - 1);
                scanf("%d", &num_items);

                if (num_items > STACK_SIZE - top - 1) 
                {
                    printf("Cannot push %d items. Stack will overflow. Only %d items can be pushed.\n", num_items, STACK_SIZE - top - 1);
                    num_items = STACK_SIZE - top - 1;
                }

                for (int i = 0; i < num_items; i++) 
                {
                    printf("Enter item %d: \n", i + 1);
                    scanf("%d", &item);
                    push(item);
                }
                break;
            }

            case 2:
                item_deleted = pop();
                if (item_deleted == -1) 
                {
                    printf("Stack is empty\n");
                } 
                else 
                {
                    printf("Item deleted: %d\n", item_deleted);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Enter the string: \n");
                scanf("%s", str);
                flag = is_palindrome(str);
                if (flag == 0) 
                {
                    printf("The string is not a palindrome\n");
                } 
                else 
                {
                    printf("The string is a palindrome\n");
                }
                break;

            default:
                exit(0);
        }
    }
}
