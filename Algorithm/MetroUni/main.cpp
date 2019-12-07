#include <bits/stdc++.h>
using namespace std;

void lis(int a[], int n){
    unordered_map<int, int>mp;
    int dp[n];
    memset(dp,0,sizeof(dp));
    int max=INT_MIN,index=-1,lastIndex,i,j;

    for(i=0;i<n;i++){
        if(mp.find(a[i]-1) != mp.end()){
            lastIndex = mp[a[i]-1]-1;
            dp[i] = 1 + dp[lastIndex];
        }
        else dp[i]=1;
        
        mp[a[i]] = i+1;
        
        if(max<dp[i]){
            max=dp[i];
            index = i;
        }
    }
    for(j=a[index]-max+1;j<=a[index];j++)
        cout<<j<<" ";
}

int main(){
    int a[] = { 3, 10, 3, 11, 4, 5, 6, 7, 8, 12 }; 
    int n= sizeof(a)/sizeof(a[0]);

    lis(a,n);
    return 0;
}