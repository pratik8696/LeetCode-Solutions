typedef long long ll;
ll dp[51][102][51];
const int MOD=1e9+7;
ll sum(ll idx,ll maxx,ll rem,ll m,ll n)
{
    if(idx==n)
    {
        return (rem==0);
    }
    auto &x=dp[idx][maxx+1][rem];
    if(x!=-1)
    {
        return x;
    }
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        if(maxx>=i)
        {
            ans+=sum(idx+1,maxx,rem,m,n);
            ans%=MOD;
        }
        else
        {
            if(rem-1>=0)
                ans+=sum(idx+1,i,rem-1,m,n);
            ans%=MOD;
        }
    }
    ans%=MOD;
    return x = ans;
}

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return sum(0,-1,k,m,n);
    }
};