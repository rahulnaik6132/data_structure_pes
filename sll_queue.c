#include <stdio.h>
#include <stdlib.h>

typedef struct mynode
{
    int data;
    struct mynode *link;
} *NODE;

typedef struct myQueue
{
    NODE front, rear;
} *Queue;

NODE create_node(int data)
{
    NODE new_node = (NODE)malloc(sizeof(struct mynode));
    if (new_node == NULL)
    {
        printf("No memory available");
        exit(EXIT_FAILURE);
    }
    else
    {
        new_node->data = data;
        new_node->link = NULL;
    }
    printf("\nNODE with %d is created\n", data);
    return new_node;
}

Queue display(Queue queue)
{
    NODE temp = queue->front;
    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        return queue;
    }
    printf("\nQueue elements:");
    while (temp != NULL)
    {
        printf(" ->%d", temp->data);
        temp = temp->link;
    }
    printf("\n");
    return queue;
}

Queue create_queue()
{
    Queue new_queue = (Queue)malloc(sizeof(struct myQueue));
    if (new_queue == NULL)
    {
        printf("Can't create queue\n");
        exit(EXIT_FAILURE);
    }
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

Queue enqueue(Queue queue, int data)
{
    NODE new_node = create_node(data);
    if (new_node == NULL)
    {
        printf("\nQueue is FULL\n");
        return queue;
    }
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = new_node;
    }
    else
    {
        queue->rear->link = new_node;
        queue->rear = new_node;
    }
    return queue;
}

Queue dequeue(Queue queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        return queue;
    }
    NODE temp = queue->front;
    printf("\n%d is deleted from the queue\n", temp->data);
    queue->front = queue->front->link;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return queue;
}

int main()
{
    Queue queue = create_queue();

    queue = enqueue(queue, 30);
    display(queue);

    queue = enqueue(queue, 20);
    display(queue);

    queue = enqueue(queue, 10);
    display(queue);

    queue = dequeue(queue);
    display(queue);

    // queue = dequeue(queue);
    // display(queue);

    // queue = dequeue(queue);
    // display(queue);

    return 0;
}
