#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        fast_cin();
        int n=s.length();
        vector<int> one(n),zero(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                one[i]++;
            }
            if(s[i]=='0')
            {
                zero[i]++;
            }
            if(i>0)
            {
                one[i]+=one[i-1];
                zero[i]+=zero[i-1];
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            int cost=0;
            ans=min(ans,(i-1>=0?one[i-1]:0)+zero.back()-zero[i]);
        }
        return ans;
    }
};