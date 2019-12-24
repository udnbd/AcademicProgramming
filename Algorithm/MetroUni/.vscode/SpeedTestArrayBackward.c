#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define kElements 125000

struct arrayItem
{
    int p;
    int q;
    //    char foreName[64];
    //    char surname[64];
};

int sumArray(struct arrayItem p[], int num)
{
    int sum = 0, i;

    for (i = num - 1; i >= 0; --i)
    {
        sum = sum + p[i].p;
    }
    return sum;
}

const char *progress = "-\\|/";

int main(int argc, char **argv)
{
    clock_t clk;
    struct arrayItem *a;
    int i;
    int sum;

    int tot = 0;

    printf("Initializing array [-]");
    a = calloc(1, sizeof(struct arrayItem) * kElements);

    /* Generate random numbers <100 */
    for (i = 0; i < kElements; i++)
    {
        if (i % 100 == 0)
        {
            printf("%c%c%c]", 8, 8, progress[(i / 100) % 4]);
            fflush(stdout);
        }
        a[i].p = rand() % 100;
    }
    printf("\n\nTiming...\n");
    /* Generate random numbers <100 */
    for (i = 0; i < kElements; i++)
    {
        a[i].p = rand() % 100;
    }

    for (i = 0; i < 100; i++)
    {

        clk = clock();
        sum = sumArray(a, kElements);

        clk = clock() - clk;
        tot += clk;
        printf("Array %ld ticks,sum %d\n", clk, sum);
    }

    printf("Average time: %f ticks\n", ((double)tot) / 100.0);
    getchar();
}
