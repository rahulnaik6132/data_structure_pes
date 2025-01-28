#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct myQueue
{
    int arr[MAX];
    int front, rear;
} *Queue;

void initialisation(Queue q)
{
    q->front = -1;
    q->rear = -1;
}

Queue create_queue()
{
    Queue new_element = (Queue)malloc(sizeof(struct myQueue));
    if (new_element == NULL)
    {
        printf("\nNo Memory");
    }
    initialisation(new_element);
    return new_element;
}

int IsEmpty(Queue q)
{
    return q->front == -1;
}

int IsFull(Queue q)
{
    return (q->rear + 1) % MAX == q->front; // Full when rear is one step behind front
}

int Enqueue(Queue q, int data)
{
    if (IsFull(q))
    {
        return -1; // Queue is full
    }
    else if (IsEmpty(q))
    {
        q->front = q->rear = 0; // First element
    }
    else
    {
        q->rear = (q->rear + 1) % MAX; // Circular increment
    }
    q->arr[q->rear] = data;
    return 0; // Success
}

int Dequeue(Queue q)
{
    if (IsEmpty(q))
    {
        return -1; // Queue is empty
    }
    int x = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1; // Queue becomes empty
    }
    else
    {
        q->front = (q->front + 1) % MAX; // Circular increment
    }
    return x;
}

int peek(Queue q)
{
    if (IsEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    printf("Peek element is %d\n", q->arr[q->front]);
    return q->arr[q->front];
}

void display(Queue q)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("\nQueue Elements are: ");
    int i = q->front;
    while (i != q->rear)
    {
        printf(" %d->", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf(" %d", q->arr[q->rear]);
    printf(" LAST\n\n");
}

int main()
{
    Queue q = create_queue();
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    display(q);
    printf("\nDequeued ");
    int delete = Dequeue(q);
    printf("%d\n", delete);
    display(q);
    peek(q);
    display(q);
    return 0;
}
