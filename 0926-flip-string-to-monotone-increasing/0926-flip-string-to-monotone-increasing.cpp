#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        fast_cin();
        int n=s.length(),zero=0;
        for(int i=0;i<n;i++)
        {
            zero+=(s[i]=='0'?1:0);
        }
        int ans=1e9,one=0;
        for(int i=0;i<n;i++)
        {
            zero-=(s[i]=='0'?1:0);
            ans=min(ans,one+zero);
            one+=(s[i]=='1'?1:0);
        }
        return ans;
    }
};