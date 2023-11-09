typedef long long ll;
class Solution {
public:
    const int MOD=1e9+7;
    int countHomogenous(string s) 
    {
        s.push_back('.');
        char prev=s[0];
        ll cc=0,ans=0;
        for(auto t:s)
        {
            if(prev==t)
            {
                cc++;
            }
            else
            {
                ans+=(cc*(cc+1))/2;
                ans%=MOD;                
                prev=t;
                cc=1;
            }
        }
        return ans;
    }
};