#include<stdio.h>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
vector<int>edge[100];
int infinity=10000000;
queue<int>Q;
int BFS(int start,int last)
{
    int i,u,m,p,ucost,vcost,v;
    int dis[100];
    for(i=0; i<100; i++)
        dis[i]=infinity;
    Q.push(start);
    dis[start]=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        ucost=dis[u];
        for(i=0; i<edge[u].size(); i++)
        {
            v=edge[u][i];
            vcost=ucost+1;
            if(dis[v]>vcost)
            {
                dis[v]=vcost;
                Q.push(v);
            }

        }
    }
    return dis[last];
}
int main()
{
    int a,b,x,y,k,m,c,i;
    while(scanf("%d",&a)==1)
    {
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        while(1)
        {
            scanf("%d%d",&c,&b);

            k=BFS(c,b);
            printf("%d\n",k);

        }
        for(i=0; i<a; i++)
            edge[i].clear();
    }
    return 0;
}
