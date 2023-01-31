typedef long long ll;
ll dp[1002][1002];
ll sum(int idx,int prev,vector<pair<int,int>> &arr)
{
    ll n=arr.size();
    if(idx == n)
    {
        return 0;
    }
    auto &x=dp[idx][prev];
    if(x != -1)
    {
        return dp[idx][prev];
    }
    ll ans=0;
    if(arr[prev].second<=arr[idx].second)
    {
        ans=max(ans,sum(idx+1,(arr[prev].second<=arr[idx].second?idx:prev),arr)+arr[idx].second);
    }
    ans=max(ans,sum(idx+1,prev,arr));
    return x = ans;
}

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr;
        int n=scores.size();
        arr.push_back({0,0});
        for(int i=0;i<n;i++)
        {
            arr.push_back({ages[i],scores[i]});
        }
        sort(begin(arr),end(arr));
        memset(dp,-1,sizeof(dp));
        return sum(0,0,arr);
    }
};