// QUEUE USING STATIC ARRAYS
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct
{
    int arrays[MAX];
    int front, rear;
} *Queue;

// Function to initialize the queue
void initialize(Queue q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue q)
{
    return q->rear == -1;
}

// Check if the queue is full
int isFull(Queue q)
{
    return q->rear == MAX - 1;
}

// Add an element to the queue
void enqueue(Queue q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot insert %d\n", data);
    }
    else
    {
        if (q->front == -1)
        { // First element to be inserted
            q->front = 0;
        }
        q->rear++;
        q->arrays[q->rear] = data;
    }
}

// Remove and return the front element from the queue
int dequeue(Queue q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
    else
    {
        int del = q->arrays[q->front];
        q->front++;
        if (q->front > q->rear)
        { // Queue has become empty
            initialize(q);
        }
        return del;
    }
}

int peek(Queue q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. No front element\n");
        return -1;
    }
    else
    {
        return q->arrays[q->front];
    }
}

void display(Queue q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->arrays[i]);
    }
}

int main()
{
    Queue q;
    initialize(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    int item = dequeue(q);
    printf("\nDequeued item: %d\n", item);
    display(q);
}