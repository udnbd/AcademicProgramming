#include<stdio.h>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
vector<int>stor[1000],stor2[1000];
bool mark[1000],mark2[10000];
stack<int>shakil;

void dfs(int n)
{
    int i,temp;

    if(mark[n]==0)
    {
        mark[n]=1;

        for(i=0; i<stor[n].size(); i++)
        {
            temp=stor[n][i];
            dfs(temp);
        }
        shakil.push(n);
        //printf("%d ",n);

    }
}
void dfs2(int n1)
{
    int i,tem,ans;
    if(mark2[n1]==0)
    {
        mark2[n1]=1;
        for(i=0; i<stor2[n1].size(); i++)
        {
            tem=stor2[n1][i];
            dfs2(tem);
        }

    }
    return ;
}
int main()
{
    int i,m,n,p,k,a,b,ans;
    while(scanf("%d%d",&n,&m)==2)
    {
        ans=0;
        memset(mark,0,sizeof(mark));
        memset(mark2,0,sizeof(mark2));

        while(!shakil.empty())shakil.pop();
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            stor[a].push_back(b);
            stor2[b].push_back(a);
        }
        for(i=0; i<n; i++)
        {
            if(mark[i]==0)
                dfs(i);
        }
        while(!shakil.empty())
        {
            int t;
            t=shakil.top();
            if(mark2[shakil.top()]==0)
            {
                ans++;
                dfs2(shakil.top());

            }
            shakil.pop();
            //break;
        }
        printf("%d\n",ans);

    }
    return 0;
}
/*
3 4
0 1
1 0
0 2
2 0
*/
