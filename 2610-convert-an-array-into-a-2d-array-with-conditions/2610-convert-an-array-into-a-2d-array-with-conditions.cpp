class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> m;
        for(auto t:nums)
        {
            m[t]++;
        }
        vector<vector<int>> ans(200);
        for(auto t:m)
        {
            int curr=t.second;
            for(int i=0;i<curr;i++)
            {
                ans[i].push_back(t.first);
            }
        }
        while(ans.back().size()==0)
        {
            ans.pop_back();
        }
        return ans;
    }
};