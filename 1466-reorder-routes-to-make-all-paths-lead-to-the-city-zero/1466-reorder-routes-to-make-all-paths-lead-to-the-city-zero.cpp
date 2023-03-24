void bfs(unordered_map<int,vector<int>> &adj,vector<int> &dist,int src)
{
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(q.size())
    {
        int curr=q.front();
        q.pop();
        for(auto child:adj[curr])
        {
            if(dist[child]>dist[curr]+1)
            {
                dist[child]=dist[curr]+1;
                q.push(child);
            }
        }
    }
}
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> adj;
        for(auto t:connections)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        vector<int> dist(n,1e9);
        bfs(adj,dist,0);
        int ans=0;
        for(auto t:connections)
        {
            if(dist[t[0]]<dist[t[1]])
            {
                ans++;
            }
        }
        return ans;
    }
};