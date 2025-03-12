#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void initializeMatrix(int matrix[MAX][MAX], int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[MAX][MAX], int src, int dest)
{
    matrix[src][dest] = 1;
    matrix[dest][src] = 1;
}

void printMatrix(int matrix[MAX][MAX], int vertices)
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void BFS(int matrix[MAX][MAX], int vertices, int startVertex)
{
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++)
        {
            if (matrix[currentVertex][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int vertices, edges, src, dest, startVertex;
    int adjacencyMatrix[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initializeMatrix(adjacencyMatrix, vertices);

    printf("Enter the edges (pair of vertices):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(adjacencyMatrix, src, dest);
    }

    printMatrix(adjacencyMatrix, vertices);

    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(adjacencyMatrix, vertices, startVertex);

    return 0;
}
