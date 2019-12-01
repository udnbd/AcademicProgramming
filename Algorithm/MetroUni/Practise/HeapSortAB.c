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
    int i, j, temp, val;

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
    //int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int H[100];
    int i, j, n;

    printf("Enter Number of Elements to create and sort Heap:\n");
    scanf("%d", &n);

    printf("Enter the Integer Numbers preceding 0 Please !\n");
    for (j = 0; j < n; j++)
        scanf("%d", &H[j]);

    for (i = 2; i < n; i++)
        Insert(H, i);

    for (i = n - 1; i > 1; i--)
        Delete(H, i);

    for (i = 1; i < n; i++)
        printf("%d ", H[i]);

    return 0;
}
