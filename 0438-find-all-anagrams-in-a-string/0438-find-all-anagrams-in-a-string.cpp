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

    vector<int> checkInclusion(string s, string r) {
        int n=s.length(),m=r.length();
        if(n>m)
        {
            return {};
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
        vector<int> ans;
        if(check(hsh1,hsh2))
        {
            ans.push_back(0);
        }
        int i=0;
        for(int j=n;j<m;j++)
        {
            hsh2[r[j]-'a']++;
            hsh2[r[i++]-'a']--;
            if(check(hsh1,hsh2))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        return checkInclusion(p,s);
    }
};