int dp[int(1e5+1)];
bool sum(int idx,vector<int> &arr)
{
    if(idx==arr.size())
    {
        return true;
    }
    auto &x=dp[idx];
    if(x!=-1)
    {
        return x;
    }
    bool ans=false;
    // double dekh
    int rem=arr.size()-idx;
    if(rem==2)
    {
        if(arr[idx]==arr[idx+1])
        {
            ans|=sum(idx+2,arr);
        }
    }
    else if(rem>2)
    {
        if(arr[idx]==arr[idx+1])
        {
            ans|=sum(idx+2,arr);
        }
        if(arr[idx]==arr[idx+1]&&arr[idx+1]==arr[idx+2])
        {
            ans|=sum(idx+3,arr);
        }
        if(arr[idx+1]-arr[idx]==1&&arr[idx+2]-arr[idx+1]==1)
        {
            ans|=sum(idx+3,arr);
        }
    }
    return x = ans;
}

class Solution {
public:
    bool validPartition(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return sum(0,arr);
    }
};