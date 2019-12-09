#include<stdio.h>
#include<queue>
#include<vector>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int mark[100000];
4
int n,m,a,b,c,ans;
struct data
{
    int u,v,w;
    bool operator < ( const data& p) const
    {
        return w<p.w;
    }

};
data A,S,D;
int find1(int t)
{
    if(mark[t]==t)return t;
    else
        find1(mark[t]);
}
vector<data>V;
int krus(int n)
{
    sort(V.begin(),V.end());
    int sum=0,countt=0;
    int i;
    for(i=1; i<=n; i++)
    {
        mark[i]=i;
    }

    for(int i=0; i<m; i++)
    {
        int u=V[i].u;
        int v=V[i].v;
        int w=V[i].w;
        u=find1(u);
        v=find1(v);
        if(u!=v)
        {
            sum+=w;
            countt++;
            mark[u]=v;
            if(countt==n-1)break;

        }
    }
    return sum;


}
int main()
{

    while(scanf("%d %d",&n,&m)==2)
    {
        V.clear();
        //scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            A.u=a;
            A.v=b;
            A.w=c;
            V.push_back(A);

        }
        ans=krus(n);
        printf("%d\n",ans);

    }
    return 0;
}


