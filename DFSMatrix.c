#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Adjacency matrix
int adj[5][5];

// Function to add an edge to the graph
void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

// Function to perform DFS on the graph
void dfs(int start, bool visited[], int v)
{
    // Print the current node
    printf("%d ", start);

    // Set current node as visited
    visited[start] = true;

    // For every node of the graph
    for (int i = 0; i < v; i++)
    {
        // If some node is adjacent to the current node
        // and it has not already been visited
        if (adj[start][i] == 1 && (!visited[i]))
        {
            dfs(i, visited, v);
        }
    }
}

int main()
{
    // Number of vertices
    int v = 5;

    // Number of edges
    int e = 4;

    // Adjacency matrix
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            adj[i][j] = 0;
        }
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(0, 4);

    // Visited array to track visited vertices
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    // Perform DFS
    printf("Depth-First Search Traversal:\n");
    dfs(0, visited, v);

    return 0;
}
