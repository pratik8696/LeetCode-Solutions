class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int> st;
        int s3=-1e9;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<s3)
            {
                return true;
            }            
            while(st.size() && st.back()<nums[i])
            {
                s3=st.back();
                st.pop_back();
            }
            st.push_back(nums[i]);
        }
        return false;
    }
};