class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> adj;
        for(auto t:adjacentPairs)
        {
            auto u=t[0];
            auto v=t[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,int> vis;
        queue<int> q;
        for(auto t:adj)
        {
            if(t.second.size()==1&&q.size()==0)
            {
                vis[t.first]=1;
                q.push(t.first);
            }
        }
        vector<int> ans;
        while(q.size())
        {
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(auto child:adj[curr])
            {
                if(vis[child]==0)
                {
                    q.push(child);
                    vis[child]=1;
                }
            }
        }
        return ans;
    }
};