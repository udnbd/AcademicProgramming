//protita node theke protitar shortest distance
#include<stdio.h>
using namespace std;
int main()
{
    int arr[100][100];
    int i,j,k,g,m,a,b,x,y;
    while(scanf("%d%d",&a,&b)==2)
    {
        for(i=0; i<a; i++)
        {
            for(j=0; j<a; j++)
            {
                if(i==j)
                    arr[i][j]=0;
                else
                    arr[i][j]=10000;
            }
        }
        for(i=0; i<b; i++)
        {
            scanf("%d%d",&x,&y);

            arr[x][y]=arr[y][x]=1;
        }

        for(k=0; k<a; k++)
        {
            for(i=0; i<a; i++)
            {
                for(j=0; j<a; j++)
                {
                    x=arr[i][k]+arr[k][j];
                    if(x<arr[i][j])
                        arr[i][j]=x;

                }
            }
        }
        for(i=0; i<a; i++)
        {
            for(j=0; j<a; j++)
            {

                printf("%d ",arr[i][j]);//prottekta theke protthetar distance print

            }
            printf("\n");

        }
    }
    return 0;
}
/*
3      //number of node
2      //number of edge
0 1
0 2
output:
0 1 1
1 0 2
1 2 0
*/
