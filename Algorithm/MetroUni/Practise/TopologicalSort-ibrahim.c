#include <stdio.h>
 
int main(){
	int i,j,k,a,b,cost,indeg[10],flag[10],count=0,nodes,edges,G[100][100];
 
    printf("Enter Number of Nodes: ");
    scanf("%d", &nodes);

    printf("Enter Number of Edges: ");
    scanf("%d", &edges);

    for (k = 1; k <= edges; k++)
    {
        printf("Enter Edge %d and Cost as N1 N2 Cost : ", k);
        scanf("%d %d %d", &a, &b, &cost);
        for (i = 1; i <= nodes; i++)
        {

            for (j = 1; j <= nodes; j++)
            {
                G[a][b] = cost;
            }
        }
    } 
 
	for(i=0;i<nodes;i++){
        indeg[i]=0;
        flag[i]=0;
    }
 
    for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
            indeg[i]=indeg[i]+G[j][i];
 
    printf("\nThe topological order is:");
 
    while(count<nodes){
        for(k=0;k<nodes;k++){
            if((indeg[k]==0) && (flag[k]==0)){
                printf("%d ",(k+1));
                flag [k]=1;
            }
 
            for(i=0;i<nodes;i++){
                if(G[i][k]==1)
                    indeg[k]--;
            }
        }
 
        count++;
    }
 
    return 0;
}