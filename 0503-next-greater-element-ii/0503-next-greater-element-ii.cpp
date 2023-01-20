class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> st;
        vector<int> ans(n,-1);
        for(int i=0;i<2*nums.size();i++)
        {
            while(st.size()&&nums[st.back()]<nums[i%n])
            {
                ans[st.back()]=i%n;
                st.pop_back();
            }
            st.push_back(i%n);
        }
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            res[i]=(ans[i]!=-1?nums[ans[i]]:-1);
        }
        return res;
    }
};