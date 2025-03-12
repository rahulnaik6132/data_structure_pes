#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int numVertices;
    int **adjMatrix; // Pointer to Pointer
    // 2D array can be represented using a "pointer to pointer" (int **)
} *Graph;

Graph createGraph(int v)
{
    Graph graph = (Graph)malloc(sizeof(struct graph));
    graph->numVertices = v;
    graph->adjMatrix = malloc(v * sizeof(int *)); // Allocates memory for an array of integer pointers, where each pointer represents a row in the adjacency matrix.
    for (int i = 0; i < v; i++) // i = rows && v = columns
    {
        graph->adjMatrix[i] = malloc(v * sizeof(int));
        for (int j = 0; j < v; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // only when graph is undirected
}

void printGraph(Graph graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix); // Deallocates the memory for the array of row pointers
    free(graph); // Deallocates the memory for the graph structure itself
}

int main()
{
    int numVertices = 4;
    Graph graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    printGraph(graph);
    freeGraph(graph);
    return 0;
}

