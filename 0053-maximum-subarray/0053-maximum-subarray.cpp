typedef long long ll;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]+=(i-1>=0?nums[i-1]:0);
        }
        int ans=nums[0],mini=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(nums[i]-mini,ans);
            mini=min(mini,nums[i]);
        }
        return ans;
    }
};