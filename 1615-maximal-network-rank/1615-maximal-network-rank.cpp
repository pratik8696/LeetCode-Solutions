class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,set<int>> adj;
        for(auto t:roads)
        {
            auto u=t[0],v=t[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=max(ans,int(adj[i].size()+adj[j].size()-(adj[i].count(j)>0?1:0)));
            }
        }
        return ans;
    }
};