#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,h,n,m,a,b,v,w[100],p[100],t;
    struct shakil
    {
        int price;
        int weight;
    } sh[100],tem;
    while(scanf("%d",&n)==1)
    {
        int total=0,cap;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&w[i],&p[i]);
            sh[i].price=p[i]/w[i];
            sh[i].weight=w[i];
        }
        scanf("%d",&cap);
        for(i=1; i<n; i++)
        {
            for(j=0; j<n-i; j++)
            {
                if(sh[j].price>sh[j+1].price)
                {
                    tem=sh[j];
                    sh[j]=sh[j+1];
                    sh[j+1]=tem;

                }
            }
        }
        for(i=n-1; i>=0; i--)
        {

            t= min(cap,sh[i].weight);
            total+=t*(sh[i].price);
            cap-=t;
            if(cap==0)
                break;

        }
        printf("Maximum price=%d\n",total);
    }
    return 0;
}
