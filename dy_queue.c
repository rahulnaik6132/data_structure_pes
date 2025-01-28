/*
Example 2 : Dynamic Array Linear Queue
Authour : Rahul R Naik
PRN : PES1202404471
Date : 22 NOV 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct MyQueueADT
{
    int *array;
    int front, rear;
    int capacity;
} *Queue;

Queue CreateQueue(int capacity)
{
    Queue new_queue = (Queue)malloc(sizeof(struct MyQueueADT));
    if (new_queue == NULL)
    {
        printf("\n\t\t Insufficient Memory !!! Exiting !!!! ");
        exit(EXIT_FAILURE);
    }
    new_queue->array = (int *)malloc(sizeof(int) * capacity);
    if (new_queue->array == NULL)
    {
        printf("\n\t\t Insufficient Memory !!! Exiting !!!! ");
        exit(EXIT_FAILURE);
    }
    new_queue->front = 0;
    new_queue->rear = -1;
    new_queue->capacity = capacity;
    printf("\n\t\t Queue is created\n");
    return new_queue;
}

void display(Queue MyQueue)
{
    if (MyQueue->rear == -1)
    {
        printf("\n\t\t Queue is Empty\n");
    }
    else
    {
        printf("\n\t FRONT-> ");
        for (int i = MyQueue->front; i <= MyQueue->rear; i++)
        {
            printf("|%d|-> ", MyQueue->array[i]);
        }
        printf("REAR\n");
    }
}

int Do_Resize(Queue MyQueue, int data)
{
    int NewSize = MyQueue->capacity + data;
    int *NewArray = (int *)realloc(MyQueue->array, sizeof(int) * NewSize);
    if (NewArray == NULL)
    {
        printf("\n\t\t Insufficient Memory !!! Exiting !!!! ");
        return 0;
    }
    MyQueue->capacity = NewSize;
    MyQueue->array = NewArray;
    return 1;
}

int isFULL(Queue MyQueue)
{
    return (MyQueue->rear == MyQueue->capacity - 1) ? Do_Resize(MyQueue, 1) : 1;
}

int isEmpty(Queue MyQueue)
{
    return (MyQueue->front > MyQueue->rear) ? Do_Resize(MyQueue, -1) : 1;
}

void enqueue(Queue MyQueue)
{
    int element;
    printf("\n\t\t Enter the element to be enqueued: ");
    scanf("%d", &element);

    if (isFULL(MyQueue))
    {
        MyQueue->array[++MyQueue->rear] = element;
        printf("\n\t\t Enqueue Element: | %d |", element);
    }
    display(MyQueue);
}

void dequeue(Queue MyQueue)
{
    if (MyQueue->front > MyQueue->rear)
    {
        printf("\n\t\t Queue Underflow !!! ");
    }
    else
    {
        printf("\n\t\t Dequeue Element: | %d |", MyQueue->array[MyQueue->front++]);
    }
    display(MyQueue);
}

int peek(Queue MyQueue)
{
    if (MyQueue->front > MyQueue->rear)
    {
        printf("\n\t\t Queue is Empty\n");
        return INT_MIN;
    }
    return MyQueue->array[MyQueue->front];
}

void DestroyQueue(Queue MyQueue)
{
    free(MyQueue->array);
    free(MyQueue);
    printf("\n\t\t Queue Destroyed.\n");
}

int main()
{
    Queue MyQueue = CreateQueue(1);
    enqueue(MyQueue);
    enqueue(MyQueue);
    enqueue(MyQueue);
    enqueue(MyQueue);
    dequeue(MyQueue);
    printf("\n\t\t Peek Element is: | %d |", peek(MyQueue));
    display(MyQueue);

    DestroyQueue(MyQueue);
    return 0;
}
