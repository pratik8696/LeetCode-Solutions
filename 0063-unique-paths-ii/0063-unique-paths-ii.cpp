typedef long long ll;
ll x,y;
ll dp[110][110];
ll sum(ll i,ll j,vector<vector<int>>& arr)
{
    if(arr[i-1][j-1])
    {
        return 0;
    }
    if(i==x&&j==y)
    {
        return 1;
    }
    ll ans=0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(j<y&&arr[i-1][j]==0)
    {
        ans+=sum(i,j+1,arr);
    }
    if(i<x&&arr[i][j-1]==0)
    {
        ans+=sum(i+1,j,arr);
    }
    return dp[i][j]=ans;
}


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        memset(dp,-1,sizeof(dp));
        x=arr.size(),y=arr[0].size(); 
        return sum(1,1,arr);        
    }
};