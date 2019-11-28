#include<stdio.h>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int >ver[50],cost[50];
int dist[105];
struct data
{
    int address,dis;
    data(int a,int b)
    {
        address=a;
        dis=b;
    }
    bool operator<(const data &x)const
    {
        return dis>x.dis;
    }
};
int dijkstra(int start,int end)
{
    dist[start]=0;
    int i,u,v,t;
    priority_queue<data >Q;
    Q.push(data(start,dist[start]));
    while(!Q.empty())
    {
        data temp=Q.top();
        Q.pop();
        u=temp.address;
        if(u==end)
            return (dist[end]);

        for(i=0; i<ver[u].size(); i++)
        {
            v=ver[u][i];
            t=dist[u]+cost[u][i];
            if(dist[v]>t)
            {
                dist[v]=t;
                Q.push(data(v,dist[v]));

            }
        }
    }
    //return -1;
}
int main()
{
    int i,k,n,m,p,a,b,x,y,z,j,v,ans,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&j,&v,&b);
        for(i=0; i<b; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            ver[x].push_back(y);
            ver[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }

        for(i=0; i<101; i++)
            dist[i]=100000000;

        ans=dijkstra(j,v);
        if(ans==-1)
            printf("impossible\n");
        else
            printf("%d\n",ans);
        for(i=0; i<a; i++)
        {
            ver[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}



