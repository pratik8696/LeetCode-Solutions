class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int>  m;
        for(auto t:nums)
        {
            m[t]++;
        }
        for(int i=0;i<nums.size();i++)
        {            
            if(m[nums[i]]==1&&m[nums[i]-1]==0&&m[nums[i]+1]==0)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};