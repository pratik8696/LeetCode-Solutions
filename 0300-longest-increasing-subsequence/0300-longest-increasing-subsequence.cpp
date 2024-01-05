class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        for(auto t:nums)
        {
            auto it=s.lower_bound(t);
            if(it!=s.end())
            {
                s.erase(it);
            }
            s.insert(t);
        }
        return s.size();
    }
};