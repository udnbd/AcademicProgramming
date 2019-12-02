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
            else if (weight[i] <= j)
                knap[i][j] = max(profit[i] + knap[i - 1][j - weight[i]], knap[i - 1][j]);
            else
                knap[i][j] = knap[i - 1][j];
        }
    }
    return knap[n][capacity];
}

int main()
{

    int n, i, j, profit[100], weight[100], capacity;

    while (1)
    {
        printf("\nEnter Number of Products: ");
        scanf("%d", &n);

        printf("Enter Weight & Profits accordingly Now: \n");
        for (i = 1; i <= n; i++)
        {
            printf("Weight for Product Number %d : ", i);
            scanf("%d", &weight[i]);
            printf("Profit for Product Number %d : ", i);
            scanf("%d", &profit[i]);
        }

        weight[0] = 0;
        profit[0] = 0;

        printf("Enter the capacity of Knapsack : ");
        scanf("%d", &capacity);

        printf("The maximum profit by knapsack is : %d \n", knapsack(capacity, weight, profit, n));
    }
    return 0;
}