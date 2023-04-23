typedef long long ll;
const int MOD=1e9+7;
ll sum(ll idx,string &s,ll k,vector<ll> &dp)
{
    if(idx==s.length())
    {
        return 1;
    }
    auto &x=dp[idx];
    if(x!=-1)
    {
        return x;
    }
    if(s[idx]=='0')
    {
        return 0;
    }
    ll ans=0,val=0;
    for(ll i=idx;i<min(idx+12,ll(s.length()));i++)
    {
        val=val*10+int(s[i]-'0');
        if(val>=1&&val<=k)
        {
            ans+=sum(i+1,s,k,dp);
            ans%=MOD;
        }
    }
    ans%=MOD;
    return x = ans;
}

class Solution {
public:
    int numberOfArrays(string s, int k) {
        vector<ll> dp(s.length()+1,-1);
        return sum(0,s,k,dp);
    }
};