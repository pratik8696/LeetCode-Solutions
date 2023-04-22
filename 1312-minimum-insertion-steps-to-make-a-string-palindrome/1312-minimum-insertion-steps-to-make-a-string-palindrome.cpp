class Solution {
public:
    int longestPalindromeSubseq(string a) {
        string b=a;
        reverse(b.begin(),b.end());
        int dp[501][501];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=a.length();i++)
        {
            for(int j=1;j<=b.length();j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                ans=max(ans,dp[i][j]);
            }   
        }
        return ans;
    }
    
    int minInsertions(string s) {
        return s.length()-longestPalindromeSubseq(s);
    }
};