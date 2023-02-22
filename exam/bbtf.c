#include <stdio.h>
#include <stdlib.h>
int graph[10][10];
int visited[10];
int n;
void addEdge(int v1, int v2)
{
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}

void dfs(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j <= n; j++)
    {
        if (graph[i][j] == 1 && visited[j] == 0)
            dfs(j);
    }
}

void main()
{
    int v, v1, v2, op;
    printf("1.Create Edge\n2.DFS\n3.Exit\n");
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    do
    {

        printf("Enter choice:");
        printf("\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter vertexes :");
            scanf("%d%d", &v1, &v2);
            addEdge(v1, v2);
            break;
        case 2:
            printf("Enter the vertex from which dfs should be applied : ");
            scanf("%d", &v);
            dfs(v);
            printf("\n");
            break;
        case 3:
            exit(1);
        case 4:
            printf("Invalid option\n");
        }
    } while (op != 3);
}