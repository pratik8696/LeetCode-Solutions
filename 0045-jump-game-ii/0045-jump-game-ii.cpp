int dp[int(1e4+1)];
int sum(int idx,vector<int> &arr)
{
    if(idx==arr.size()-1)
    {
        return 0;
    }
    auto &x=dp[idx];
    if(x!=-1)
    {
        return dp[idx];
    }
    int ans=1e9;
    for(int i=idx+1;i<=min(int(arr.size()-1),arr[idx]+idx);i++)
    {
        ans=min(ans,sum(i,arr)+1);
    }
    return x=ans;
}
class Solution {
public:
    int jump(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return sum(0,arr);
    }
};