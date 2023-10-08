class Solution {
public:
    int sum(int idx1,int idx2,int val,vector<int>&a,vector<int>&b,vector<vector<vector<int>>> &dp)
    {
        if(idx1==a.size()||idx2==b.size()) return (val==1?0:-1e7);
        if(dp[idx1][idx2][val]!=-1e7) return dp[idx1][idx2][val];
        return dp[idx1][idx2][val] = max({INT_MIN,sum(idx1+1,idx2,val,a,b,dp),sum(idx1,idx2+1,val,a,b,dp),sum(idx1+1,idx2+1,min(val+1,1),a,b,dp)+(a[idx1]*b[idx2])});
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        vector<vector<vector<int>>> dp(a.size(),vector<vector<int>>(b.size(),vector<int>(2,-1e7)));
        return sum(0,0,0,a,b,dp);
    }
};