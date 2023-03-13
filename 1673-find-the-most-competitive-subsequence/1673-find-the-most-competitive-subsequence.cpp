vector<int> r(vector<int> &s, int k) {
    deque<int> st;
    int len=s.size()-k;
    for(auto t:s)
    {
        while(st.size()&&st.back()>t&&k)
        {
            k--;
            st.pop_back();
        }
        st.push_back(t);
    }
    while(k&&st.size())
    {
        st.pop_back();
        k--;
    }
    vector<int> ans;
    for(int i=0;i<min(len,(int)st.size());i++)
    {
        ans.push_back(st[i]);
    }
    if(ans.size()==0)
    {
        return {};
    }
    return ans;
}

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        return r(nums,nums.size()-k);
    }
};