// CPP program to find length of the 
// longest increasing subsequence 
// whose adjacent element differ by 1 
#include <bits/stdc++.h> 
using namespace std; 
  
// function that returns the length of the 
// longest increasing subsequence 
// whose adjacent element differ by 1 
void longestSubsequence(int a[], int n) 
{ 
    // stores the index of elements 
    unordered_map<int, int> mp; 
  
    // stores the length of the longest 
    // subsequence that ends with a[i] 
    int dp[n]; 
    memset(dp, 0, sizeof(dp)); 
  
    int maximum = INT_MIN; 
  
    // iterate for all element 
    int index = -1; 
    for (int i = 0; i < n; i++) { 
  
        // if a[i]-1 is present before i-th index 
        if (mp.find(a[i] - 1) != mp.end()) { 
  
            // last index of a[i]-1 
            int lastIndex = mp[a[i] - 1] - 1; 
  
            // relation 
            dp[i] = 1 + dp[lastIndex]; 
        } 
        else
            dp[i] = 1; 
  
        // stores the index as 1-index as we need to 
        // check for occurrence, hence 0-th index 
        // will not be possible to check 
        mp[a[i]] = i + 1; 
  
        // stores the longest length 
        if (maximum < dp[i]) { 
            maximum = dp[i]; 
            index = i; 
        } 
    } 
  
    // We know last element of sequence is 
    // a[index]. We also know that length 
    // of subsequence is "maximum". So We 
    // print these many consecutive elements 
    // starting from "a[index] - maximum + 1" 
    // to a[index]. 
    for (int curr = a[index] - maximum + 1; 
         curr <= a[index]; curr++) 
        cout << curr << " "; 
} 
  
// Driver Code 
int main() 
{ 
    int a[] = { 3, 10, 3, 11, 4, 5, 6, 7, 8, 12 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    longestSubsequence(a, n); 
    return 0; 
} 