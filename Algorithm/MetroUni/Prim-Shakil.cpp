#include<stdio.h>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
bool mark[100000];
vector<int >ver[100000],cost[100000];

struct data
{
    int u,v,w;
    data(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
    bool operator < ( const data& p) const
    {
        return w>p.w;
    }

};
priority_queue<data>Q;
int prim(int str ,int n)
{
    int sum=0,countt=0;
    int i;
    memset(mark,0,sizeof(mark));
    for(i=0; i<ver[str].size(); i++)
    {
        Q.push(data(str,ver[str][i],cost[str][i]));
    }
    while(!Q.empty())

    {
        data tp=Q.top();
        Q.pop();
        int u1=tp.u;
        int v1=tp.v;
        if(mark[v1]==1)
            continue;
        mark[v1]=1;
        sum=sum+tp.w;
        countt++;
        if(countt==n-1)
            return sum;
        for(i=0; i<ver[v1].size(); i++)
            Q.push(data(v1,ver[v1][i], cost[v1][i]));

    }
}
int main()
{
    int x,y,z,k,n,m,i,a,b,c,ans;
    while(scanf("%d %d",&n,&m)==2)
    {
        //scanf("%d %d",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            ver[a].push_back(b);
            ver[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);

        }
        ans=prim(1,n);
        printf("%d\n",ans);

        for(i=0; i<10000; i++)
        {
            ver[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
/*
4 3
1 2 2
2 4 2
2 3 3
*/

