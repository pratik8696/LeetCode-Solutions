class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size(),maxx=-1e9;
        deque<int> dq;
        vector<int> dp(n);
        for(int i=0;i<n;i++)
        {
            while(dq.size()&&i-k>dq.front())
            {
                dq.pop_front();
            }
            int value=0;
            if(dq.size()) value=dp[dq.front()];
            dp[i]=max(value+nums[i],nums[i]);
            maxx=max(dp[i],maxx);
            while(dq.size()&&dp[dq.back()]<=dp[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return maxx;
    }
};