class Solution {
public:
    int check(unordered_map<char,int> &m)
    {
        int cc=0;
        cc+=m['a'];
        cc+=m['e'];
        cc+=m['i'];
        cc+=m['o'];
        cc+=m['u'];
        return cc;
    }
    
    int maxVowels(string s, int k) {
        unordered_map<char,int> m;
        int n=s.length();
        for(int i=0;i<k;i++)
        {
            m[s[i]]++;
        }
        int ans=check(m);
        int i=0;
        for(int j=k;j<n;j++)
        {
            m[s[i++]]--;
            m[s[j]]++;
            ans=max(ans,check(m));
        }
        return ans;
    }
};