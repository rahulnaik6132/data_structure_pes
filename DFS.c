// B PES1PG24CA119 PRAN BOPANNA KK

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void dfs(int graph[MAX][MAX], bool visited[], int node, int numNodes) {
    visited[node] = true;
    printf("%d ", node);
    
    for (int neighbor = 0; neighbor < numNodes; neighbor++) {
        if (graph[node][neighbor] == 1 && !visited[neighbor]) {
            dfs(graph, visited, neighbor, numNodes);
        }
    }
}

int main() {
    int numNodes = 6;
    int graph[MAX][MAX] = {0};
    bool visited[MAX] = {false};
    
    int edges[][2] = {{0,1}, {0,2}, {1,2}, {1,3}, {2,4}, {3,4}, {3,5}, {4,5}};
    for (int i = 0; i < 8; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }
    
    printf("DFS Traversal: ");
    dfs(graph, visited, 0, numNodes);
    printf("\n");
    
    return 0;
}

