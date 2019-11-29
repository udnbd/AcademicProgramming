#include <stdio.h>

int main()
{

    int i, first, last, middle, search, n, array[100];

    printf("Enter Number of Elements:\n");
    scanf("%d", &n);

    printf("Enter Sorted Integers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Enter an integer value to find: \n");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last)
    {
        if (array[middle] < search)
            first = middle + 1;
        else if (array[middle] == search)
        {
            printf("%d is found at location %d", n, middle + 1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last) / 2;
    }
    if (first > last)
        printf("%d is not in the list", search);

    return 0;
}