typedef long long ll;
const int MOD=1e9+7;
class Solution {
public:
    int numberOfWays(string s) {
        while(s.size()&&s.back()=='P')
        {
            s.pop_back();
        }
        reverse(begin(s),end(s));
        while(s.size()&&s.back()=='P')
        {
            s.pop_back();
        }
        reverse(begin(s),end(s));
        ll x=0;
        for(auto t:s)
        {
            x+=(t=='S');
        }
        if(x%2||x==0)
        {
            return 0;
        }
        ll cc=1,ans=1,curr=0;
        for(auto t:s)
        {
            if(t=='S')
            {
                if(curr<2)
                {
                    curr++;
                }
                else
                {
                    ans*=cc;
                    ans%=MOD;
                    cc=1;
                    curr=1;
                }
            }
            else
            {
                if(curr==2)
                {
                    cc++;
                }
            }
        }
        return ans;
    }
};