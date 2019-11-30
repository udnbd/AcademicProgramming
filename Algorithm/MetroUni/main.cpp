#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int knapsack(int cap, int wght[], int prof[], int n)
{
    int i, j;
    int knap[n + 1][cap + 1];
    for (i = 0; i <= n; i++)
        for (j = 0; j <= cap; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (wght[i - 1] <= j)
            {
                knap[i][j] = max(prof[i - 1] + knap[i - 1][j - wght[i - 1]], knap[i - 1][j]);
            }
            else
                knap[i][j] = knap[i - 1][j];
        }
    return knap[n][cap];
}
int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int capacity = 50;

    int n = sizeof(profit) / sizeof(profit[0]);
    printf("The maximum profit by Knapsack is : %d", knapsack(capacity, weight, profit, n));
    return 0;
}