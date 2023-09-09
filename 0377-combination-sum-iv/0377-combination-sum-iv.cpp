int dp[201][1001];
int sum(int idx,vector<int> &arr,int k)
{
    if(idx==0)
    {
        return k==0;
    }
    int ans=0;
    if(dp[idx][k]!=-1)
    {
        return dp[idx][k];
    }
    if(arr[idx-1]<=k)
    {
        ans=sum(idx-1,arr,k)+sum(arr.size(),arr,k-arr[idx-1]);
    }
    else{
        ans=sum(idx-1,arr,k);
    }
    return dp[idx][k] = ans;
}

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return sum(nums.size(),nums,target);
    }
};