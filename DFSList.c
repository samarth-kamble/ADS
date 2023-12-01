#include <stdio.h>
#include <stdlib.h>

// Node structure for representing an adjacency list node
struct Node
{
    int data;
    struct Node *next;
};

// Graph structure with an array of adjacency lists
struct Graph
{
    int numVertices;
    struct Node **adjacencyList;
};

// Function to create a new node in the adjacency list
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node **)malloc(numVertices * sizeof(struct Node *));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to perform Depth-First Search
void DFSUtil(int vertex, int visited[], struct Graph *graph)
{
    printf("%d ", vertex);
    visited[vertex] = 1;

    struct Node *temp = graph->adjacencyList[vertex];
    while (temp != NULL)
    {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
        {
            DFSUtil(adjVertex, visited, graph);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal of the entire graph
void DFS(struct Graph *graph, int startVertex)
{
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));

    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = 0;
    }

    printf("Depth-First Search Traversal:\n");
    DFSUtil(startVertex, visited, graph);

    free(visited);
}

// Function to free memory allocated for the graph
void freeGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node *temp = graph->adjacencyList[i];
        while (temp != NULL)
        {
            struct Node *prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(graph->adjacencyList);
    free(graph);
}

int main()
{
    struct Graph *graph = createGraph(4);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    DFS(graph, 2);

    // Free allocated memory for the graph
    freeGraph(graph);

    return 0;
}
