#include <cstdio>

#define I 99999

using namespace std;

int cost[][8] = {{I, I, I, I, I, I, I, I},
                 {I, I, 25, I, I, I, 5, I},
                 {I, 25, I, 12, I, I, I, 10},
                 {I, I, 12, I, 8, I, I, I},
                 {I, I, I, 8, I, 16, I, 14},
                 {I, I, I, I, 16, I, 20, 18},
                 {I, 5, I, I, I, 20, I, I},
                 {I, I, 10, I, 14, 18, I, I}};

int near[8] = {I, I, I, I, I, I, I, I};
int t[2][6];

int main()
{

    int i, j, k, u, v, n = 7, min = 7;
    for (i = 1; i <= n; i++)
        for (j = i; j <= n)

            return 0;
}