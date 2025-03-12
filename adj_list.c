/*
    Name : Rahul Ravikumar Naik
    Topic : Adjajency List
    Class : B
    SRN : PES1PG24CA133
*/
#include <stdio.h>
#include <stdlib.h>

// node which has the vertex that is connected to the main node
typedef struct AdjNode
{
    int dest;
    struct AdjNode *next;
} *NODE;

// Adjacency List which contains vertexes as nodes and
//  each node contains the vertex and address to the head of linked list of nodes connected to the node in adjacency list
typedef struct AdjList
{
    NODE head;
} *LIST;

// graph containing number of vertices and adjacency list containing vertices and their adjacent vertices
typedef struct graph
{
    int numVertices;
    LIST array;
} *Graph;

// adding new adjacent node
NODE newAdjNode(int dest)
{
    NODE newNode = (NODE)malloc(sizeof(struct AdjNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// creating a graph
Graph createGraph(int v)
{
    Graph graph = (Graph)malloc(sizeof(struct graph));
    graph->numVertices = v;
    graph->array = (LIST)malloc(v * sizeof(struct AdjList));
    for (int i = 0; i < v; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

// adding an edge
void addEdge(Graph graph, int src, int dest)
{
    NODE newNode = newAdjNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// printing the graph
void printGraph(Graph graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        NODE curr = graph->array[v].head;
        printf("\nAdjacency List of vertex %d\n head ", v);
        while (curr)
        {
            printf("-> %d", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }
}

// free graph
void freeGraph(Graph graph)
{
    NODE head, temp;
    if (graph)
    {
        if (graph->array)
        {
            for (int v = 0; v < graph->numVertices; v++)
            {
                head = graph->array[v].head;
                temp = NULL;
                while (head != NULL)
                {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
            }
        }
        free(graph->array);
    }
    free(graph);
}

int main()
{
    int v = 3;
    Graph graph = createGraph(v);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    printGraph(graph);
    freeGraph(graph);
    printf("\nGraph is freed\n");
    return 0;
}