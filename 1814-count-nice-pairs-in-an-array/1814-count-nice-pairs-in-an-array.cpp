class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int ans=0,MOD=1e9+7;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int rev=0;
            int curr=nums[i];
            while(curr)
            {
                rev=rev*10+curr%10;
                curr/=10;
            }
            ans=(ans+m[nums[i]-rev])%MOD;
            m[nums[i]-rev]++;
        }
        return ans;
    }
};