class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        map<int,vector<int>> m;
        vector<vector<int>> ans;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]].push_back(i);
            if(m[arr[i]].size()==arr[i])
            {
                ans.push_back(m[arr[i]]);
                m[arr[i]].clear();
            }
        }
        return ans;
    }
};