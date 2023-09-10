typedef long long ll;
const int MOD=1e9+7;
ll dp[501][501];
ll sum(ll rem_start,ll rem_end)
{
    if(rem_start+rem_end==0)
    {
        return 1;
    }
    auto &x=dp[rem_start][rem_end];
    if(x!=-1)
    {
        return x;
    }
    x=0;
    if(rem_start>0)
        x+=rem_start*sum(rem_start-1,rem_end+1);
    x%=MOD;
    if(rem_end>0)
        x+=rem_end*sum(rem_start,rem_end-1);
    x%=MOD;
    return x;
}

class Solution {
public:
    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        return sum(n,0);
    }
};