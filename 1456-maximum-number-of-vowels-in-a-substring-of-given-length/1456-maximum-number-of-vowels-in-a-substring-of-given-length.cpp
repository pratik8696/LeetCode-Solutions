class Solution {
public:
    int check(vector<int> &m)
    {
        int cc=0;
        cc+=m['a'-'a'];
        cc+=m['e'-'a'];
        cc+=m['i'-'a'];
        cc+=m['o'-'a'];
        cc+=m['u'-'a'];
        return cc;
    }
    
    int maxVowels(string s, int k) {
        vector<int> m(26);
        int n=s.length();
        for(int i=0;i<k;i++)
        {
            m[int(s[i]-'a')]++;
        }
        int ans=check(m);
        int i=0;
        for(int j=k;j<n;j++)
        {
            m[int(s[i++]-'a')]--;
            m[int(s[j]-'a')]++;
            ans=max(ans,check(m));
        }
        return ans;
    }
};