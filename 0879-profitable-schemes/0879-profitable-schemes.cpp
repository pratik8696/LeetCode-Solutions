typedef long long ll;
const int MOD=1e9+7;
ll dp[101][101][101];
ll sum(ll idx,ll curr_profit,ll members,vector<int> &a,vector<int> &b)
{
    if(idx==a.size())
    {
        return (curr_profit==0);
    }
    ll ans=0;
    auto &x=dp[idx][curr_profit][members];
    if(x!=-1)
    {
        return x;
    }
    if(members>=a[idx])
    {
        ans+=sum(idx+1,max(curr_profit-b[idx],0ll),members-a[idx],a,b);
        ans%=MOD;
    }
    ans+=sum(idx+1,curr_profit,members,a,b);
    ans%=MOD;
    return x = ans;
}

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& a, vector<int>& b) {
        memset(dp,-1,sizeof(dp));
        return sum(0,minProfit,n,a,b);
    }
};