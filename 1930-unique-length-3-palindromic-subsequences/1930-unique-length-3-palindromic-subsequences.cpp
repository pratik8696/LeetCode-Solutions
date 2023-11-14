class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int> f(26),b(26);
        for(auto t:s)
        {
            b[int(t-'a')]++;
        }
        unordered_set<string> ans;
        for(int i=0;i<s.length();i++)
        {
            b[int(s[i]-'a')]--;
            (i-1>=0?f[int(s[i-1]-'a')]++:0);
            for(int j=0;j<26;j++)
            {
                if(b[j]&&f[j])
                {
                    string curr="";
                    curr.push_back(char('a'+j));
                    curr.push_back(s[i]);
                    curr.push_back(char('a'+j));
                    // cout<<curr<<endl;
                    ans.insert(curr);
                }
            }
        }
        // bbb bcb bab aba
        return ans.size();
    }
};