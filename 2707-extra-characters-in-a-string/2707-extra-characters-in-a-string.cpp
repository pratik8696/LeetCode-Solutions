int dp[55];

int sum(int idx,string &s,map<string,int> &m)
{
    if(idx==s.length())
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int ans=1e9;
    ans=min(ans,sum(idx+1,s,m)+1);
    string curr="";
    for(int i=idx;i<s.length();i++)
    {
        curr.push_back(s[i]);
        if(m[curr]>0)
        {
            ans=min(ans,sum(i+1,s,m));
        }
    }
    return dp[idx] = ans;
}

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        map<string,int> m;
        for(auto t:dictionary) m[t]++;
        memset(dp,-1,sizeof(dp));
        return sum(0,s,m);
    }
};