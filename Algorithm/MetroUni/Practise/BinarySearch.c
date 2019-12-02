#include <stdio.h>

int main()
{

    int n, first, last, middle, search, i, bs[100];

    while (1)
    {
        printf("\n\nEnter number of Elements: ");
        scanf("%d", &n);

        printf("Enter the numbers as sorted for Binary search: ");
        for (i = 0; i < n; i++)
            scanf("%d", &bs[i]);

        printf("Enter a Number to search:");
        scanf("%d", &search);

        first = 0, last = n - 1, middle = (first + last) / 2;

        while (first <= last)
        {
            if (bs[middle] < search)
                first = middle + 1;
            else if (bs[middle] == search)
            {
                printf("%d is found in the binary array!", search);
                break;
            }
            else
                last = middle - 1;

            middle = (first + last) / 2;
        }

        if (last < first)
            printf("%d not found in the binary array\n\n", search);
    }

    return 0;
}