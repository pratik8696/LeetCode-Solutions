//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int total,n;
int f(int idx,int prev,int sum,vector<vector<vector<int>>> &dp)
{
    if(idx==n)
    {
        return sum==0;
    }
    if(dp[idx][prev][sum]!=-1)
    {
        return dp[idx][prev][sum];
    }
    int ans=0;
    for(int i=max(1,prev);i<=sum;i++)
    {
        ans+=f(idx+1,i,sum-i,dp);
    }
    return dp[idx][prev][sum] = ans;
}

class Solution {
  public:
    int countWaystoDivide(int N, int K) {
        total=N;
        n=K;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(N+1,vector<int>(N+1,-1)));
        return f(0,1,N,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends