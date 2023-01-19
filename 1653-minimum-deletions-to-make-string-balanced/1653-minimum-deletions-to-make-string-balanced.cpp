class Solution {
public:
    int minimumDeletions(string s) {
        int a=0;
        for(auto t:s)
        {
            a+=(t=='a'?1:0);
        }
        int b=0,ans=1e9;
        for(auto t:s)
        {
            a-=(t=='a'?1:0);
            ans=min(ans,a+b);
            b+=(t=='b'?1:0);
        }
        return ans;
    }
};