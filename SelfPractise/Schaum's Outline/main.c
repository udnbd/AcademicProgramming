#include <stdio.h>

int main()
{
    int i, j, k, l;
    int n = 5;
    char val = '0';

    for (i = 0; i < n; i++)
    {
        printf("\n");
        printf("Level %d ->", i + 1);
        printf("\n");
        for (j = 0; j < n; j++)
        {
            //printf("Level J");
            printf("\n");
            for (k = 0; k < n; k++)
            {
                //printf("Level K");
                printf(":");
                for (l = 0; l < n; l++)
                {
                    printf("%d ", l);
                }
            }
        }
    }
    return 0;
}


