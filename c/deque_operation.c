#include <stdio.h>

#define MAX 10

struct Deque {
    int arr[MAX];
    int front, rear;
};

void initialize(struct Deque* dq) {
    dq->front = dq->rear = -1;
}

int isFull(struct Deque* dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(struct Deque* dq) {
    return dq->front == -1;
}

void insertFront(struct Deque* dq, int data) {
    if (isFull(dq)) {
        return;
    }
    if (dq->front == -1) {  // If deque is empty
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {  // If front is at the first position, wrap around to the end
        dq->front = MAX - 1;
    } else {  // Otherwise, decrement front
        dq->front = dq->front - 1;
    }
    dq->arr[dq->front] = data;
}

void insertRear(struct Deque* dq, int data) {
    if (isFull(dq)) {
        return;
    }
    if (dq->rear == -1) {  // If deque is empty
        dq->rear = 0;
        dq->front = 0;
    } else if (dq->rear == MAX - 1) {  // If rear is at the last position, wrap around to the start
        dq->rear = 0;
    } else {  // Otherwise, increment rear
        dq->rear = dq->rear + 1;
    }
    dq->arr[dq->rear] = data;
}

void deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        return;
    }
    if (dq->front == dq->rear) {  // If there's only one element
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX - 1) {  // If front is at the last position, wrap around to the start
        dq->front = 0;
    } else {  // Otherwise, increment front
        dq->front = dq->front + 1;
    }
}

void deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        return;
    }
    if (dq->front == dq->rear) {  // If there's only one element
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {  // If rear is at the first position, wrap around to the end
        dq->rear = MAX - 1;
    } else {  // Otherwise, decrement rear
        dq->rear = dq->rear - 1;
    }
}

void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        return;
    }
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->arr[i]);
        if (i == MAX - 1) {
            i = 0;  // Wrap around
        } else {
            i++;
        }
    }
    printf("%d\n", dq->arr[dq->rear]);  // Print the last element
}

int main() {
    struct Deque dq;
    initialize(&dq);

    insertRear(&dq, 5);
    insertRear(&dq, 10);
    insertFront(&dq, 20);
    display(&dq);

    deleteFront(&dq);
    display(&dq);

    deleteRear(&dq);
    display(&dq);

    insertFront(&dq, 30);
    insertRear(&dq, 40);
    display(&dq);

    return 0;
}
