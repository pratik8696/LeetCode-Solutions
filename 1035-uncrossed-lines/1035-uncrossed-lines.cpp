typedef long long ll;
ll dp[501][501];

ll sum(ll idx1,ll idx2,vector<int> &a,vector<int> &b)
{
    if(idx1>=a.size()||idx2>=b.size())
    {
        return 0;
    }
    ll ans=0;
    auto &x=dp[idx1][idx2];
    if(x!=-1)
    {
        return x;
    }
    // try it
    if(a[idx1]==b[idx2])
    {
        ans=max(ans,sum(idx1+1,idx2+1,a,b)+1);
    }
    // leave it
    ans=max(ans,sum(idx1+1,idx2,a,b));
    ans=max(ans,sum(idx1,idx2+1,a,b));
    return x = ans;
}

class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        map<int,vector<int>> hsh1,hsh2;
        memset(dp,-1,sizeof(dp));
        int n=min(a.size(),b.size());
        return sum(0,0,a,b);
    }
};