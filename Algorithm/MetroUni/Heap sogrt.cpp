#include<bits/stdc++.h>
using namespace std;
int arr1[100],arr2[100],a,s,d,f,g;
void maxheap()
{

    for(int i=1; i<=a; i++)
    {
        s=arr1[i];
        arr2[i]=s;
        f=i/2;
        g=i;
        while(f>=1)
        {
            if(arr2[g]>arr2[f])
            {
                swap(arr2[f],arr2[g]);
                g=f;
                f=f/2;
            }
            else
                break;

        }

    }
}
void del(int k)
{
    int t=1;
    arr2[1]=arr2[k] ;

    while(1)
    {
        if(k%2==0)
            if(2*t+1>k-1)
                return;
            else if(2*t>k-1)
                return;

        if(arr2[2*t]>=arr2[(2*t)+1])
        {
            if(arr2[t]<arr2[2*t])
            {
                swap(arr2[t],arr2[2*t]);
                t=2*t;
            }
            else if(arr2[t]<arr2[2*t+1])
            {
                swap(arr2[t],arr2[2*t+1]);
                t=2*t+1;
            }
            else
                return;

        }
        else
        {
            if(arr2[t]<arr2[2*t+1])
            {
                swap(arr2[t],arr2[2*t+1]);
                t=2*t;
            }
            else if(arr2[t]<arr2[2*t])
            {
                swap(arr2[t],arr2[2*t]);
                t=2*t+1;
            }
            else
                return;

        }

    }
}
void heapsort()
{
    maxheap();
    int k=a,f=0;

    while(k--)
    {
        arr1[f++]=arr2[1];
        del(k+1);
    }

}
int main()
{
    while(scanf("%d",&a)==1)
    {
        for(int i=1; i<=a; i++)
            scanf("%d",&arr1[i]);
        heapsort();
        for(int i=0; i<a; i++)
            printf("%d ",arr1[i]);
    }
    return 0;
}
