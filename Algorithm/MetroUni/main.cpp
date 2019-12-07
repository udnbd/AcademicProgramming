#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void lcs(char *X,char *Y, int m, int n){
    int i,j,l[m+1][n+1];

    for(i=0;i<=m;i++)
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
                l[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                l[i][j] = l[i-1][j-1] +1;
            else l[i][j] =max(l[i-1][j],l[i][j-1]);
        }
    int index = l[m][n];
    char lcs[index+1];
    lcs[index] = '\0';

    i=m,j=n;
    while(i>0 && j>0){
        if(X[i-1] == Y[j-1]){
            lcs[index-1] = X[i-1];
            i--,j--,index--;
        }
        else if(l[i-1][j] >l[i][j-1])
            i--;
        else j--;
    }

    cout<< " LCS of " << X << " and " << Y << " is " <<lcs;
}


int main(){

    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m= strlen(X);
    int n= strlen(Y);

    lcs(X,Y,m,n);
    return 0;
}