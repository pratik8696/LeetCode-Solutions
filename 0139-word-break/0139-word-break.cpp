int dp[400];

bool sum(int idx,unordered_set<string> &m,string &s)
{
    if(idx==s.length())
    {
        return true;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    string temp="";
    for(int i=idx;i<s.length();i++)
    {
        temp.push_back(s[i]);
        if(m.count(temp))
        {
            if(sum(i+1,m,s))
            {
                return dp[idx] = true;
            }
        }
    }
    return dp[idx] = false;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& x) {
        unordered_set<string> m;
        memset(dp,-1,sizeof(dp));
        for(auto t:x)
        {
            m.insert(t);
        }
        return sum(0,m,s);
    }
};