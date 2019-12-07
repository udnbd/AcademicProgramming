#include <stdio.h>
#include <limits.h>

int minDistance(int distance[],bool sptSet[], int n){
    int i, min_index,min = INT_MAX;

    for(i=0;i<n;i++){
        if(sptSet[i] == false && distance[i]<=min)
            min = distance[i];
            min_index = i; 
    }

    return min_index;
}
int printSolution(int distance[], int k, int n){
    int i;
    printf("Vertex -> Distance from Source\n");
    
    for(i=0;i<n;i++)
        printf("%d -> %d\n",i,distance[i]);
}
void dijkstra(int G[9][9], int start,int n){
    int i,j,k,u,distance[9];
    bool sptSet[9];

    for(i=0;i<n;i++){
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }

    distance[start] = 0;

    for(j=0;j<n-1;j++){
        u = minDistance(distance,sptSet,n);
        sptSet[u] = true;

        for(k=0;k<n;k++){
        if(!sptSet[k] && G[u][k] && distance[u]!=INT_MAX && distance[u]+G[u][k] < distance[k])
                distance[k] = distance[u] + G[u][k];
        }
    }
    printSolution(distance,k,n);


}

int main(){
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int n = 9;
    //printf("Enter number of nodes : ");
    //scanf("%d",&n);
    int start = 0;
    dijkstra(graph,start,n);
    
    return 0;
}