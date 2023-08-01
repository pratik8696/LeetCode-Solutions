typedef long long ll;
ll dp[1001][1001];

ll sum(ll idx1,ll idx2,string &a,string &b)
{
    if(idx1==a.length()&&idx2==b.length())
    {
        return 0;
    }
    auto &x=dp[idx1][idx2];
    if(x!=-1)
    {
        return x;
    }
    if(idx1==a.length()||idx2==b.length())
    {
        ll res=0;
        while(idx1!=a.length())
        {
            res+=a[idx1++];
        }
        while(idx2!=b.length())
        {
            res+=b[idx2++];
        }
        return res;
    }
    ll ans=1e17;
    // agr equal then dono age
    if(a[idx1]==b[idx2])
    {
        ans=min(ans,sum(idx1+1,idx2+1,a,b));
    }
    // ek ko age bdha do
    ans=min(ans,sum(idx1+1,idx2,a,b)+a[idx1]);    
    ans=min(ans,sum(idx1,idx2+1,a,b)+b[idx2]);    
    return x = ans;
}

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return sum(0,0,s1,s2);
    }
};