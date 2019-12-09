#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
bool mark[100000];
vector<int>tahmid[1000];

void DFS(int t)
{
    if(mark[t]==0)
    {
        int i,to;
        mark[t] = 1;
        printf("%d ",t);
        for(i=0;i<tahmid[t].size(); i++)
        {
            to = tahmid[t][i];
            DFS(to);
        }
    }
    return ;
}

int main()
{
    int i,j,k,m,n,ver,edg,str;
    while(scanf("%d%d",&ver, &edg)==2)
    {
        memset(mark,0,sizeof(mark));
        for(i=0; i<edg; i++)
        {
            scanf("%d%d",&m,&n);
            tahmid[m].push_back(n);
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

