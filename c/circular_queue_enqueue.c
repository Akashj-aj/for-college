void insert()
{
    int num;
    if(rear == front-1 || (front == 0 && rear == MAX - 1))
    {
        printf("overflow\n");
    }
    else
    {
        printf("enter the data: \n");
        scanf("%d", &num);
        if (rear == -1)
        {
            rear++; front++;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        Queue[rear] = num;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("underflow\n");
    }
    else
    {
        printf("element deleted is %d \n", Queue[front]);
        if (front == rear)
        {
            rear = -1, front = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("queue is empty");
    }
    else
    {
        if (rear >= front)
        {
            for(int i = front; i<=rear; i++)
            {
                printf("%d", Queue[i]);
            }
        }
        else
        {
            for (int j = 0; j<=rear; j++)
            {
                printf("%d", Queue[j]);
            }
            for(int i=front; i<MAX; i++)
            {
                printf("%d", Queue[i]);
            }
        }
    }
}