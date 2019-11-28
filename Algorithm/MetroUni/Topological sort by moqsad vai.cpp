#include "stdio.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 100

vector<int> ans, depends[SZ];
int taken[SZ];


void take(int p)
{
    if(taken[p]==0)
    {
        int i;
        taken[p] = 1;
        for(i=0; i<depends[p].size(); i++)
            take(depends[p][i]);

        ans.push_back(p);
    }
}

int main()
{
    int i, j, k, n, m;

    while(scanf("%d %d",&n,&m)==2)//vertex num....edge num
    {
        for(i=0; i<=n; i++)
        {
            taken[i] = 0;
            depends[i].clear();
        }
        ans.clear();

        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);//2 point of edge
            depends[k].push_back(j);
        }

        for(i=1; i<=n; i++)
            take(i);

        printf("Topologically Sorted List: ");
        for(i=0; i<n; i++)
            printf("%d ", ans[i] );
        printf("\n");
    }

    return 0;
}
/*
4 3
2 1
2 3
4 2*/
