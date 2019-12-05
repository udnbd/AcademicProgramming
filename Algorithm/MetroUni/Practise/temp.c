#include <stdio.h>

int main()
{

    int G[100][100], nodes, edges, i, j, k, a, b, cost;

    printf("Enter Number of Nodes: ");
    scanf("%d", &nodes);

    printf("Enter Number of Edges: ");
    scanf("%d", &edges);

    for (k = 1; k <= edges; k++)
    {
        printf("Enter Edge %d and Cost as N1 N2 Cost : ", k);
        scanf("%d %d %d", &a, &b, &cost);
        for (i = 1; i <= nodes; i++)
        {

            for (j = 1; j <= nodes; j++)
            {
                G[a][b] /*= G[b][a]*/ = cost;
            }
        }
    }

    printf("The Cost Adjacency Matrix is : \n");
    for (i = 0; i <= nodes; i++)
    {
        for (j = 0; j <= nodes; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    return 0;
}