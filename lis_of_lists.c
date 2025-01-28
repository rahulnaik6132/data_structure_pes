#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int element;
    struct Node *next;
} *Node;

// Define the header node structure
typedef struct HeaderNode
{
    int priority;
    Node head;
    struct HeaderNode *next;
} *HeaderNode;

Node Create_Node(int element)
{
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->element = element;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new header node
HeaderNode NewHeaderNode(int priority)
{
    HeaderNode newHeader = (HeaderNode)malloc(sizeof(struct HeaderNode));
    newHeader->priority = priority;
    newHeader->head = NULL;
    newHeader->next = NULL;
    return newHeader;
}

void Add(HeaderNode *priorityQueue, int element, int priority)
{
    if (*priorityQueue == NULL || (*priorityQueue)->priority > priority)
    {
        HeaderNode newHeader = NewHeaderNode(priority);
        newHeader->next = *priorityQueue;
        newHeader->head = Create_Node(element);
        *priorityQueue = newHeader;
    }
    else
    {
        // Search for the correct position or existing priority
        HeaderNode temp = *priorityQueue;
        while (temp->next != NULL && temp->next->priority < priority)
        {
            temp = temp->next;
        }

        if (temp->priority == priority)
        {
            // Priority already exists, add to the existing
            Node newNode = Create_Node(element);
            newNode->next = temp->head;
            temp->head = newNode;
        }
        else
        {
            // Create a new priority header
            HeaderNode newHeader = NewHeaderNode(priority);
            newHeader->next = temp->next;
            temp->next = newHeader;
            newHeader->head = Create_Node(element);
        }
    }
}

// Function to remove and return the element with the highest priority (lowest number)
int Pop(HeaderNode *priorityQueue)
{
    if (*priorityQueue == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    Node tempNode = (*priorityQueue)->head;
    int poppedElement = tempNode->element;
    (*priorityQueue)->head = tempNode->next;

    // If no more elements in this priority, remove the header
    if ((*priorityQueue)->head == NULL)
    {
        HeaderNode tempHeader = *priorityQueue;
        *priorityQueue = (*priorityQueue)->next;
        free(tempHeader);
    }

    free(tempNode);
    return poppedElement;
}

// Function to destroy the queue and free memory
void DestroyQueue(HeaderNode *priorityQueue)
{
    while (*priorityQueue != NULL)
    {
        HeaderNode header = *priorityQueue;
        *priorityQueue = (*priorityQueue)->next;

        // Free all nodes in the current header
        Node tempNode = header->head;
        while (tempNode != NULL)
        {
            Node nextNode = tempNode->next;
            free(tempNode);
            tempNode = nextNode;
        }

        free(header);
    }
}

// Function to check if the queue is empty
int IsEmpty(HeaderNode *priorityQueue)
{
    return (*priorityQueue) == NULL;
}

// Function to display the priority queue
void Display(HeaderNode priorityQueue)
{
    if (priorityQueue == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    while (priorityQueue != NULL)
    {
        printf("Priority %d: ", priorityQueue->priority);
        Node temp = priorityQueue->head;
        while (temp != NULL)
        {
            printf("%d ", temp->element);
            temp = temp->next;
        }
        printf("\n");
        priorityQueue = priorityQueue->next;
    }
}

int main()
{
    HeaderNode pq = NULL;

    // Adding elements with different priorities
    Add(&pq, 40, 2);
    Add(&pq, 30, 1);
    Add(&pq, 20, 2);
    Add(&pq, 50, 3);

    // Displaying the queue before popping
    Display(pq);

    // Popping elements and displaying after each pop
    while (!IsEmpty(&pq))
    {
        printf("Pop: %d\n", Pop(&pq));
        Display(pq);
    }

    DestroyQueue(&pq);
    return 0;
}
