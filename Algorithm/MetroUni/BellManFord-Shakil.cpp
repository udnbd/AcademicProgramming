#include<stdio.h>
#include<iostream>
using namespace std;
struct E
{
    int a,b,c;
} ;
E ed[100000];
int dis[100000],p;
int m,n;
int  belmen (int n1,int e,int s,int d)
{
    int i,j;
    dis[s]=0;
    for (i=0; i<n1-1; i++)
    {
        for(j=0; j<e; j++)
        {
            if(dis[ed[j].a]+ed[j].c<dis[ed[j].b])
            {
                dis[ed[j].b]=dis[ed[j].a]+ed[j].c;
            }
        }
    }
    for(j=0; j<e; j++)
    {

        if(dis[ed[j].a]+ed[j].c<dis[ed[j].b])
            p=1;
    }
    return dis[d];
}
int main()
{
    int a,b,c,m,n,i,a1,b1,c1,n1,d1,x,s1;
    scanf("%d",&n1);
    while(n1--)
    {
        p=0;
        cin>>n>>m;
        for(i=0; i<n; i++)
            dis[i]=10000000;
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a1,&b1,&c1);
            ed[i].a=a1;
            ed[i].b=b1;
            ed[i].c=c1;
        }
        scanf("%d%d",&s1,&d1);
        x=belmen(n,m,s1,d1);
        if(p==1)
            printf("There Is a negative Cycle\n");
        else
            printf("Shortest path:%d\n",x);
    }
    return 0;
}
/*
input:
2
4 4
0 1 10
1 2 20
2 3 30
3 0 -60
0 2
3 3
0 1 1000
1 2 15
2 1 -42
1 2
output:
Shortest path:30
There Is a negative Cycle

*/


