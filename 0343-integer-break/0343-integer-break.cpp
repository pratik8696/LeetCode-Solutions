typedef long long ll;
ll dp[60][60];
ll sum(ll rem,ll part)
{
    if(rem==0)
    {
        return part>=2;
    }
    auto &x=dp[rem][part];
    if(x!=-1)
    {
        return x;
    }
    ll ans=0;
    for(int i=rem;i>=1;i--)
    {
        ans=max(sum(rem-i,part+1)*i,ans);
    }
    return x = ans;
}

class Solution {
public:
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return sum(n,0);
    }
};