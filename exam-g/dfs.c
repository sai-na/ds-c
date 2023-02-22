#include <stdio.h>
#include <stdbool.h>
#define V 12
int visited[V] = {0}; // to keep track of visited nodes
void depthFirstTraversal(int graph[][V], int numV, int u)
{
    visited[u] = 1;                 // mark current node as visited
    printf("%d ", u);               // and print its value
    for (int i = 0; i <= numV; i++) // for every node in the graph
    {
        if (graph[u][i] == 1 && visited[i] == 0) // if it is adjacent and not visited
            depthFirstTraversal(graph, numV, i); // then go to that node
    }
}
void addEdge(int[][V], int, int);
void printAdjacencyMatrix(int[][V], int);
int main()
{
    int graph[V][V] = {0};
    int numVertices, numEdges, l;
    printf("Enter the number of vertices in the graph ");
    scanf("%d", &numVertices);
    for (int i = 1; i <= numVertices; i++)
    {
        printf("\nEnter the number of edges from %d : ", i);
        scanf("%d", &numEdges);
        for (int j = 0; j < numEdges; j++)
        {
            printf("\nEnter the connection %d : ", j + 1);
            scanf("%d", &l);
            addEdge(graph, i, l);
        }
    }
    int startNode;
    printf("\nEnter the start vertex\n");
    scanf("%d", &startNode);
    printf("\nAdjacency matrix\n");
    printAdjacencyMatrix(graph, numVertices);

    printf("\nDepth first traversal from node %d\n", startNode);

    depthFirstTraversal(graph, numVertices, startNode);
    return 0;
}
void addEdge(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void printAdjacencyMatrix(int graph[][V], int numV)
{
    int i, j;
    printf(" ");
    for (int k = 1; k <= numV; k++)
        printf("%3d ", k);
    printf("\n");
    for (int k = 0; k <= numV; k++)
        printf("____");
    printf("\n");
    for (i = 1; i <= numV; i++)
    {
        printf("%2d|", i);
        for (j = 1; j <= numV; j++)
        {
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

// OUTPUT
// Enter the number of vertices in the graph 5
// Enter the number of edges from 1 : 3
// Enter the connection 1 : 2
// Enter the connection 2 : 3
// Enter the connection 3 : 4
// Enter the number of edges from 2 : 2
// Enter the connection 1 : 1
// Enter the connection 2 : 5
// Enter the number of edges from 3 : 2
// Enter the connection 1 : 1
// Enter the connection 2 : 5
// Enter the number of edges from 4 : 2
// Enter the connection 1 : 1
// Enter the connection 2 : 5
// Enter the number of edges from 5 : 3
// Enter the connection 1 : 2
// Enter the connection 2 : 3
// Enter the connection 3 : 4
// Enter the start vertex
// 1
// Adjacency matrix
//  1 2 3 4 5
// ________________________
//  1| 0 1 1 1 0
//  2| 1 0 0 0 1
//  3| 1 0 0 0 1
//  4| 1 0 0 0 1
//  5| 0 1 1 1 0
// Depth first traversal from node 1
// 1 2 5 3 4