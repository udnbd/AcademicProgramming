#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,n,m,a,sh[100][100],cap;
    int w[1000],p[1000];
    while(scanf("%d",&n)==1)
    {
        for(i=1; i<=n; i++)
            scanf("%d%d",&w[i],&p[i]);
        scanf("%d",&cap);
        for(i=0; i<=n; i++)
            sh[i][0]=0;
        for(j=0; j<=cap; j++)
            sh[0][j]=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=cap; j++)
            {
                if(w[i]>j)
                    sh[i][j]=sh[i-1][j];
                else if(w[i]<=j)
                {
                    sh[i][j]=max(sh[i-1][j],(sh[i-1][j-w[i]]+p[i]));
                }

            }
        }
        printf("%d\n",sh[n][cap]);

    }
    return 0;

}



