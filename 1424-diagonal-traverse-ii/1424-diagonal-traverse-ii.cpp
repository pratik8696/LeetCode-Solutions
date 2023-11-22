class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> adj;
        int maxx=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=nums[i].size()-1;j>=0;j--)
            {
                adj[i+j].push_back(nums[i][j]);
                maxx=max(maxx,j);
            }
        }
        // 6 0 0 0 
        // 8 0 0 0 
        // 6 1 6 16
        
        // 6 8 6 1 6 16
//         for(auto t:adj)
//         {
//             cout<<t.first<<" ";
//         }
//         cout<<endl;
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            auto &v=adj[i];
            for(auto t:v)
            {
                ans.push_back(t);
            }
        }
        
        for(int j=1;j<=maxx;j++)
        {
            auto &v=adj[nums.size()-1+j];
            for(auto t:v)
            {
                ans.push_back(t);
            }
        }
        return ans;
    }
};