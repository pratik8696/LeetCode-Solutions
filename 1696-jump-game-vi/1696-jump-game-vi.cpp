class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int ans=nums[0];
        multiset<int> s;
        s.insert(ans);
        int j=0;
        vector<int> dp(nums.size(),-1e9);
        dp[0]=ans;
        for(int i=1;i<nums.size();i++)
        {
            if(s.size()>k)
            {
                s.erase(s.find(dp[j]));
                j++;
            }
            dp[i]=max({dp[i],*s.rbegin()+nums[i]});
            s.insert(dp[i]);
            ans=max(ans,*s.rbegin());
        }
        return dp.back();
    }
};