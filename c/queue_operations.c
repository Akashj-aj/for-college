#include <stdio.h>
#include <stdlib.h>

// Define global variables
int *q; // Pointer for dynamic allocation of queue
int front = -1, rear = -1, q_size;

// Queue Insertion
void insert(int item) 
{
    if (rear == q_size - 1) 
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) 
    { // First element to be inserted
        front = 0;
    }
    q[++rear] = item;
}

// Queue Deletion
void deletion() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Item deleted = %d\n", q[front]);
    front++;
    if (front > rear) 
    { // Reset the queue when it's empty
        front = rear = -1;
    }
}

// Displaying the queue
void display() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Items in queue:\n");
    for (int i = front; i <= rear; i++) 
    {
        printf("%d\t", q[i]);
    }
    printf("\n");
}

// Main function
int main() 
{
    int ch, item;

    // Prompt for queue size
    printf("Enter queue size:\n");
    scanf("%d", &q_size);

    // Allocate memory for queue
    q = (int *)malloc(q_size * sizeof(int));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // For loop to continuously display the menu and perform operations
    for (;;) 
    {
        // Display menu
        printf("Operations on queue are:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        if (ch == 4) 
        {
            printf("Exiting...\n");
            break;
        }

        switch(ch) 
        {
            case 1:
                printf("Enter item to be inserted:\n");
                scanf("%d", &item);
                insert(item);
                break;
            
            case 2:
                deletion();
                break;
            
            case 3:
                display();
                break;
            
            default:
                printf("Invalid choice\n");
        }
    }

    // Free allocated memory
    free(q);

    return 0;
}
