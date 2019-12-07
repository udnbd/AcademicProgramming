#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue is Full\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct Node *t;

    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}

void BFS(int G[][100], int start, int n)
{
    int i = start, j;
    int visited[100] = {0};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][100], int start, int n)
{
    static int visited[100] = {0};
    int j;

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;

        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int main()
{
    int i, j, n, startnode, G[100][100];
    while (1)
    {
        printf("Enter Number of Nodes: ");
        scanf("%d", &n);

        printf("Enter the Adjacency Matrix: \n");
        for (i = 1; i <= n; i++)
        {
            printf("Node %d : ", i);
            for (j = 1; j <= n; j++)
                scanf("%d", &G[i][j]);
        }
        printf("Enter the Starting Node: ");
        scanf("%d", &startnode);

        printf("Breadth First Search Traversal is : \n");
        BFS(G, startnode, n + 1);

        printf("\n");

        printf("Depth First Search Traversal is : \n");
        DFS(G, startnode, n + 1);

        printf("\n");
    }
    return 0;
}