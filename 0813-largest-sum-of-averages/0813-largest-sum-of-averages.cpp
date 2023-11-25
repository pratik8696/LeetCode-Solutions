class Solution {
public:
    vector<vector<double>> dp;
    double sum(int idx,int k,vector<int> &nums)
    {
        if(idx==nums.size())
        {
            if(k==0)
            {
                return 0;
            }
            return -1e9;
        }
        if(k==0)
        {
            return -1e9;
        }
        if(dp[idx][k] != -1)
        {
            return dp[idx][k];
        }
        double num=0,ans=-1e9;
        if(k>0)
        {
            for(int i=idx,j=1;i<nums.size();i++,j++)
            {
                double denom=j;
                num+=nums[i];
                ans=max(ans,sum(i+1,k-1,nums)+num/denom);
            }
        }
        return dp[idx][k] = ans;
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        dp=vector<vector<double>>(101,vector<double>(101,-1));
        return sum(0,k,nums);
    }
};