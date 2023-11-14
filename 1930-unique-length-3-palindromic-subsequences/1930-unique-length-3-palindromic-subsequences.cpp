class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int> f(26),b(26);
        for(auto t:s)
        {
            b[int(t-'a')]++;
        }
        int dp[26][26][26];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.length();i++)
        {
            b[int(s[i]-'a')]--;
            (i-1>=0?f[int(s[i-1]-'a')]++:0);
            for(int j=0;j<26;j++)
            {
                if(b[j]&&f[j])
                {
                    string curr="";
                    dp[j][int(s[i]-'a')][j]=1;
                }
            }
        }
        // bbb bcb bab aba
        int res=0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<26;k++)
                {
                    res+=dp[i][j][k];
                }
            }
        }
        return res;
    }
};