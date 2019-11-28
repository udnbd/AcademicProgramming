#include<stdio.h>
void quicksort(int x[10],int first,int last)
{
    int pivot,i,j,temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
                j--;
            if(i<j)
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);
    }
}
int main()
{
    int i,n,m,x[10];
    while(scanf("%d",&n)==1)
    {
        for(i=0; i<n; i++)
            scanf("%d",&x[i]);
        quicksort(x,0,n-1);
        for(i=0; i<n; i++)
            printf("%d ",x[i]);
        printf("\n");
    }
    return 0;
}
