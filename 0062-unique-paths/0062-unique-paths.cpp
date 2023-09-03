typedef long long ll;
ll x,y;
ll dp[110][110];
ll sum(ll i,ll j)
{
    if(i==x&&j==y)
    {
        return 1;
    }
    ll ans=0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(j<y)
    {
        ans+=sum(i,j+1);
    }
    if(i<x)
    {
        ans+=sum(i+1,j);
    }
    return dp[i][j]=ans;
}


class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        x=m,y=n; 
        return sum(1,1);
    }
};