//Traversing Every Nodes
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
bool mark[100000];
vector<int>shakil[1000];
void DFS(int t)
{
    if(mark[t]==0)
    {
        int i,to;
        mark[t]=1;
        printf("%d ",t);
        for(i=0; i<shakil[t].size(); i++)
        {
            to=shakil[t][i];

            DFS(to);
        }
        // printf("%d ",t);
    }
    return ;

}
int main()
{
    int i,k,j,m,n,ver,edg,str;
    while(scanf("%d%d",&ver,&edg)==2)
    {
        memset(mark,0,sizeof(mark));
        for(i=0; i<edg; i++)
        {
            scanf("%d%d",&m,&n);
            shakil[m].push_back(n);
        }
        scanf("%d",&str);
        printf("\n\n");
        if(mark[str]==0)
        {
            DFS(str);
        }
        printf("\n");

    }
    return 0;
}
/*
input:
7 7 //(node and edge jotota ase)
1 2
1 3
2 6
3 4
6 5
6 7
4 5
1   // 1 theke start
output:

1 2 6 5 7 3 4    //1 theke je je node a jaoa jabe(1 soho print)



*/
