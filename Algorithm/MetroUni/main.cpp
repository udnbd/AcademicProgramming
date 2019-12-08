#include <iostream>
#define I 9999

using namespace std;
/*
int cost[][8] = {{I, I, I, I, I, I, I, I},
                 {I, I, 25, I, I, I, 5, I},
                 {I, 25, I, 12, I, I, I, 10},
                 {I, I, 12, I, 8, I, I, I},
                 {I, I, I, 8, I, 16, I, 14},
                 {I, I, I, I, 16, I, 20, 18},
                 {I, 5, I, I, I, 20, I, I},
                 {I, I, 10, I, 14, 18, I, I}};

 */
//int near[8] = {I, I, I, I, I, I, I, I};

int main()
{

    int i, j, k, u, v, nodes, min = I, expense, edges, near[100], cost[100][100];

    printf("Enter Number of Nodes: ");
    scanf("%d", &nodes);

    int t[2][nodes - 1];

    for (i = 0; i < nodes; i++)
        near[i] = I;

    printf("Enter Number of Edges: ");
    scanf("%d", &edges);

    for (k = 1; k <= edges; k++)
    {
        printf("Enter Edge %d and Expense as N1 N2 Cost : ", k);
        scanf("%d %d %d", &u, &v, &expense);
        for (i = 1; i <= nodes; i++)
        {

            for (j = 1; j <= nodes; j++)
            {
                cost[u][v] = expense;
            }
        }
    }

    for (i = 1; i <= nodes; i++)
    {
        for (j = i; j <= nodes; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;
    for (i = 1; i <= nodes; i++)
    {
        if (near[i] != 0)
        {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    for (i = 1; i < nodes - 1; i++)
    {
        min = I;
        for (j = 1; j <= nodes; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] < min)
            {
                k = j;
                min = cost[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        for (j = 1; j <= nodes; j++)
        {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }
    for (i = 0; i < nodes - 1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }
}