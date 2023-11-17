class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=0;
        for(int i=0;i<nums.size()/2;i++)
        {
            ans=max(ans,nums[i]+nums[nums.size()-1-i]);
        }
        return ans;
    }
};