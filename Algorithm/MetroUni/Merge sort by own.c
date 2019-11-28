#include<stdio.h>
int A[100];
void merge(int low,int mid,int high)
{
    int h=low,i=low,j=mid+1,k,B[100];
    while(h<=mid&&j<=high)
    {
        if(A[h]<A[j])
        {
            B[i]=A[h];
            h++;
        }
        else
        {
            B[i]=A[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            B[i]=A[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            B[i]=A[k];
            i++;
        }
    }
    for(k=low; k<=high; k++)
    {
        A[k]=B[k];
    }
}
void mergesort(int low ,int high)
{
    int mid;
    if(low<high)
    {
        mid=(int)((low+high)/2);
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}
int main()
{
    int i,j,k,low,high,n;
    while(scanf("%d",&n)==1)
    {
        low=0;
        high=n-1;
        for(i=0; i<n; i++)
            scanf("%d",&A[i]);
        mergesort(low,high);
        for(i=0; i<n; i++)
            printf("%d ",A[i]);
        printf("\n");

    }
    return 0;
}
