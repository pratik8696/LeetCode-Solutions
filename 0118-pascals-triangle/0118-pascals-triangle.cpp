class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int dp[50][50];
        memset(dp,0,sizeof(dp));
        int k=1;
        vector<vector<int>> ans;
        while(k<=numRows)
        {
            vector<int> t;
            for(int i=1;i<=k;i++)
            {
                if(i==1||i==k)       
                {
                    dp[k][i]=1;
                }
                else
                {
                    dp[k][i]=dp[k-1][i-1]+dp[k-1][i];
                }
                t.push_back(dp[k][i]);
            }
            ans.push_back(t);
            k++;
        }
        return ans;
    }
};