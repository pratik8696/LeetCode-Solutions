typedef long long ll;
vector<int> arr;
ll dp[501][501];
ll sum(ll idx,ll cc)
{
    ll n=arr.size();
    if(n==idx)
    {
        return 0;
    }
    auto &x=dp[idx][cc];
    if(x!=-1)
    {
        return x;
    }
    // take it 
    ll ans=-1e18;
    ans=max(ans,sum(idx+1,cc+1)+(arr[idx]*cc));
    ans=max(ans,sum(idx+1,cc));
    return x = ans;
}

class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        arr=a;
        sort(begin(arr),end(arr));
        memset(dp,-1,sizeof(dp));
        return sum(0,1);
    }
};