#include <stdio.h>

void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];

    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int Delete(int A[], int n)
{

    int val, temp, i, j;
    val = A[1];
    A[1] = A[n];
    A[n] = val;

    i = 1;
    j = 2 * i;

    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            i = j;
            j = 2 * j;
        }
        else
            break;
    }

    return val;
}

int main()
{
    int H[100];
    int i, j, n;

    while (1)
    {

        printf("\nEnter Number of integers to Sort by HeapSort : ");
        scanf("%d", &n);

        printf("Enter %d Integers for a Complete Binary tree:\n", n);

        for (i = 1; i <= n; i++)
            scanf("%d", &H[i]);

        for (i = 2; i <= n; i++)
            Insert(H, i);

        for (i = n; i > 1; i--)
            Delete(H, i);

        printf("The Sorted Numbers are from small to big :\n");
        for (i = 1; i <= n; i++)
            printf("%d ", H[i]);

        printf("\n");
    }

    return 0;
}