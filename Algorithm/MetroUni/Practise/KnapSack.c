#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int knapsack(int capacity, int weight[], int profit[], int n)
{
    int i, j;
    int knap[n + 1][capacity + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (weight[i - 1] <= j)
                knap[i][j] = max(profit[i - 1] + knap[i - 1][j - weight[i - 1]], knap[i - 1][j]);
            else
                knap[i][j] = knap[i - 1][j];
        }
    }
    return knap[n][capacity];
}
int main()
{
    int profit[] = {20, 25, 40};
    int weight[] = {25, 20, 30};
    int capacity = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("The maximum profit by knapsack is : %d", knapsack(capacity, weight, profit, n));
    return 0;
}