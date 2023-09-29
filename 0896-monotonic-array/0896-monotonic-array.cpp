class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int cc=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<=nums[i+1])
            {
                
            }
            else
            {
                cc++;
                break;
            }
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>=nums[i+1])
            {
                
            }
            else
            {
                cc++;
                break;
            }
        }        
        return (cc<=1);
    }
};