class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> st;
        vector<int> ans(n,-1);
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++)
        {
            while(st.size()&&nums2[st.back()]<nums2[i])
            {
                // operation kro
                ans[st.back()]=i;
                st.pop_back();
            }
            st.push_back(i);
            m[nums2[i]]=i;
        }
        vector<int> res(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            res[i]=(ans[m[nums1[i]]]!=-1?nums2[ans[m[nums1[i]]]]:-1);
        }
        return res;
    }
};