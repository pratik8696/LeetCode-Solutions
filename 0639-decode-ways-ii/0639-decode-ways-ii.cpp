typedef long long ll;
const int MOD=1e9+7;
ll dp[int(1e5+1)];
ll sum(ll idx,string &s)
{
    ll n=s.length();
    if(idx==n)
    {
        return 1;
    }
    auto &x=dp[idx];
    if(x!=-1)
    {
        return x;
    }
    ll ans=0;
    if(s[idx]>='1'&&s[idx]<='9')
    {
        ans+=sum(idx+1,s);
    }
    if(s[idx]=='*')
    {
        ans+=sum(idx+1,s)*9;
    }
    if(idx<n-1)
    {
        if(s[idx]=='*')
        {
            if(s[idx+1]=='*')
            {
                // 1 * 1 2 3 4 5 6 7 8 9
                // 2 * 0 1 2 3 4 5 6
                ans+=sum(idx+2,s)*15;
            }
            else if(s[idx+1]>='0'&&s[idx+1]<='6')
            {
                ans+=sum(idx+2,s)*2;
            }
            else if(s[idx+1]>='7')
            {
                ans+=sum(idx+2,s);
            }
        }
        if(s[idx]=='1')
        {
            if(s[idx+1]>='0'&&s[idx+1]<='9')
            {
                ans+=sum(idx+2,s);
            }
            if(s[idx+1]=='*')
            {
                ans+=sum(idx+2,s)*9;
            }
        }
        if(s[idx]=='2')
        {
            if(s[idx+1]>='0'&&s[idx+1]<='6')
            {
                ans+=sum(idx+2,s);
            }
            if(s[idx+1]=='*')
            {
                ans+=sum(idx+2,s)*6;
            }
        }
    }
    ans%=MOD;
    return x = ans;
}

class Solution {
public:
    int numDecodings(string &s) {
        memset(dp,-1,sizeof(dp));
        return sum(0,s);
    }
};