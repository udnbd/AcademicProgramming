#include<stdio.h>
int main()
{
    int shakil[100];
    int a,i,k,j,b,c,d,beg,mid,end;
    scanf("%d",&a);
    for(i=1; i<=a; i++)
        scanf("%d",&shakil[i]);
    scanf("%d",&b);
    beg=1;
    end=a;

    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(b>shakil[mid])
            beg=mid+1;
        else if(b<shakil[mid])
            end=mid-1;
        else if(b==shakil[mid])
        {
            k=mid;
            break;

        }
    }
    if(k==mid)
        printf("%d",k);
    return 0;
}
