class Solution {
public:
    double champagneTower(int poured, int x, int y) 
    {
        vector<vector<double>> dp(110,vector<double>(110,0));
        dp[1][1]=poured;
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=i;j++)
            {
                double spread=max(double(dp[i][j]-1),double(0));
                double rem=min(dp[i][j],double(1));
                dp[i][j]=rem;
                dp[i+1][j]+=spread/2;
                dp[i+1][j+1]+=spread/2;
            }
        }
        return dp[x+1][y+1];
    }
};