class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        vector<int> dp(n),idx(n);
        for(int i=0;i<n;i++)
        {
            int maxx=0;
            int index=i;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(maxx<dp[j])   
                    {
                        maxx=dp[j];
                        index=j;
                    }
                }
            }
            dp[i]=maxx+1;
            idx[i]=index;
        }
        int maxx=*max_element(begin(dp),end(dp));
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==maxx)
            {
                int prev=i;
                while(prev!=idx[prev])
                {
                    ans.push_back(nums[prev]);
                    prev=idx[prev];
                }
                ans.push_back(nums[prev]);
                break;
            }
        }
        return ans;
    }
};