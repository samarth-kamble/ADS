#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform Depth-First Search
void DFS(int vertex, int visited[], int adjacencyMatrix[][MAX_VERTICES], int numVertices)
{
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; i++)
    {
        if (adjacencyMatrix[vertex][i] && !visited[i])
        {
            DFS(i, visited, adjacencyMatrix, numVertices);
        }
    }
}

// Function to initialize visited array and call DFS for each unvisited vertex
void DFSTraversal(int adjacencyMatrix[][MAX_VERTICES], int numVertices)
{
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            DFS(i, visited, adjacencyMatrix, numVertices);
        }
    }
}

int main()
{
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Depth-First Search Traversal:\n");
    DFSTraversal(adjacencyMatrix, numVertices);

    return 0;
}
