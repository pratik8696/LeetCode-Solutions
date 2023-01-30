class Solution {
public:
    int tribonacci(int n) {
        vector<unsigned int> dp(n+10);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        for(int i=4;i<n+10;i++)
        {
            dp[i]+=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};