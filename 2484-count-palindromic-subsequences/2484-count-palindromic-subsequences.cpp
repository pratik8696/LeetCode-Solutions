typedef long long ll;

class Solution {
public:
    const int MOD=1e9+7;
    ll dp[int(1e4)][12][12][3];
    ll sum(ll idx,ll one,ll two,ll third,string &s)
    {
        if(third==3)
        {
            return 1;
        }
        if(idx==s.length())
        {
            return 0;
        }
        auto &x=dp[idx][one+1][two+1][third];
        if(x!=-1)
        {
            return x;
        }
        ll ans=0;
        // not take
        ans+=sum(idx+1,one,two,third,s);
        ans%=MOD;
        if(one==-1)
        {
            // fix one
            ans+=sum(idx+1,s[idx]-'0',two,third,s);
            ans%=MOD;
        }
        else if(two==-1)
        {
            // fix two
            ans+=sum(idx+1,one,s[idx]-'0',third,s);
            ans%=MOD;
        }
        else if(third==0)
        {
            ans+=sum(idx+1,one,two,1,s);
            ans%=MOD;
        }
        else if(third==1)
        {
            if(int(s[idx]-'0')==two)
            {
                ans+=sum(idx+1,one,two,third+1,s);
                ans%=MOD;
            }
        }
        else if(third==2)
        {
            if(int(s[idx]-'0')==one)
            {
                ans+=sum(idx+1,one,two,third+1,s);
                ans%=MOD;
            }
        }
        ans%=MOD;
        return x = ans;
    }
    
    int countPalindromes(string s) {
        // yani ki 5 ke lie
        // 3 size ka pehle sara khojo 
        // 10^2 size h 
        // 0 0 3 
        memset(dp,-1,sizeof(dp));
        return sum(0,-1,-1,0,s);
    }
};