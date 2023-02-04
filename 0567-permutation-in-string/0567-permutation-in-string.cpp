#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool check(vector<int> &a,vector<int> &b)
{
    for(int i=0;i<26;i++)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool checkInclusion(string s, string r) {
        fast_cin();
        int n=s.length(),m=r.length();
        if(n>m)
        {
            return false;
        }
        vector<int> hsh1(26);
        vector<int> hsh2(26);
        for(auto t:s)
        {
            hsh1[t-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            hsh2[r[i]-'a']++;
        }
        if(check(hsh1,hsh2))
        {
            return true;
        }
        int i=0;
        for(int j=n;j<m;j++)
        {
            hsh2[r[j]-'a']++;
            hsh2[r[i++]-'a']--;
            if(check(hsh1,hsh2))
            {
                return true;
            }
        }
        return false;
    }
};