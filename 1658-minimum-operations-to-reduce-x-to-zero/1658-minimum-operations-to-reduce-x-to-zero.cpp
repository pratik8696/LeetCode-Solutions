class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 5 se jyada size hona chahiye na
        // 6 se barabar ya kam size ka max array
        int total=0;
        for(auto t:nums) total+=t;
        int k=total-x;
        if(total<x)
        {
            return -1;
        }
        int i=0,sum=0,ans=-1;
        for(int j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            while(sum>k)
            {
                sum-=nums[i++];
            }
            if(sum==k)
                ans=max(ans,j-i+1);
        }
        if(ans==-1)
        {
            return -1;
        }
        return nums.size()-ans;
    }
};