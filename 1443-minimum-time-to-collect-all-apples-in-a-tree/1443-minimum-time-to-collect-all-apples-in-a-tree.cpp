int dfs(int v,vector<int> &vis,unordered_map<int,vector<int>> &adj,vector<bool> &a)
{
    vis[v]=1;
    vector<int> curr;
    for(auto child:adj[v])
    {
        if(vis[child]==0)
        {
            int temp=dfs(child,vis,adj,a);
            if(temp)
            {
                curr.push_back(temp);
            }
        }
    }
    int val=0;
    for(auto t:curr)
    {
        val+=t;
    }
    if(val)
    {
        val++;
    }
    else if(val==0&&a[v])
    {
        val++;
    }
    return val;
}

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& a) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> in;
        for(auto t:edges)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        vector<int> vis(n+1);
        return max((dfs(0,vis,adj,a)-1)*2,0);
    }
};