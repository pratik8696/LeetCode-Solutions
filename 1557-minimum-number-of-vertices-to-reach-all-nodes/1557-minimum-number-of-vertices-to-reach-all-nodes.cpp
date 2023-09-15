class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> in;
        for(auto t:edges)
        {
            in[t[1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};