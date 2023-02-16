class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            if(i<=maxx)
            {
                int reach=min(n-1,i+nums[i]);
                maxx=max(maxx,reach);
                if(maxx==n-1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};