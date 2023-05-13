typedef long long ll;
const int MOD=1e9+7;
ll l,r,a,b;

ll dp[100010];
ll sum(ll val)
{
    if(val>r)
    {
        return 0;
    }
    if(dp[val]!=-1)
    {
        return dp[val];
    }
    
    ll ans=0;
    
    if(val>=l&&val<=r)
    {
        ans++;
    }
    
    ans+=sum(val+a)%MOD;
    ans+=sum(val+b)%MOD;
    ans%=MOD;
    return dp[val] = ans;
}

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        l=low,r=high,a=zero,b=one;
        memset(dp,-1,sizeof(dp));
        return sum(0);
    }
};