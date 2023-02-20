int sum(int idx,int rem,vector<vector<int>> &arr,int dp[1001][2001])
{
    if(idx==arr.size()){return 0;}
    auto &x=dp[idx][rem];
    if(x!=-1) {return x;}
    int curr=0,ans=0;
    for(int i=0;i<min((int)arr[idx].size(),rem);i++)
    {
        curr+=arr[idx][i];
        ans=max(ans,sum(idx+1,rem-(i+1),arr,dp)+curr);
    }
    ans=max(ans,sum(idx+1,rem,arr,dp));
    return x = ans;
}

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int dp[1001][2001];
        memset(dp,-1,sizeof(dp));
        return sum(0,k,piles,dp);
    }
};