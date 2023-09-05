int dp[1001];
int sum(int idx,int d,vector<int> &arr)
{
    int ans=0;
    auto &x=dp[idx];
    if(x!=-1)
    {
        return x;
    }
    // x age
    for(int i=idx+1;i<=min(idx+d,int(arr.size()-1));i++)
    {
        if(arr[idx]<=arr[i])
        {
            break;
        }
        ans=max(sum(i,d,arr)+1,ans);
    }
    // x piche
    for(int i=idx-1;i>=max(0,idx-d);i--)
    {
        if(arr[idx]<=arr[i])
        {
            break;
        }
        ans=max(sum(i,d,arr)+1,ans);
    }
    return x=ans;
}
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<arr.size();i++)
        {
            int curr=sum(i,d,arr)+1;
            ans=max(ans,curr);
        }
        return ans;
    }
};