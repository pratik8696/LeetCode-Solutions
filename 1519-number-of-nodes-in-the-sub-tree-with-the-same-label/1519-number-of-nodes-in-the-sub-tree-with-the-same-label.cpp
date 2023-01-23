int hsh[(int)1e5+1][26];

void dfs(int v,vector<int> &vis,unordered_map<int,vector<int>> &adj,string &s)
{
    vis[v]=1;
    hsh[v][s[v]-'a']++;
    for(auto child:adj[v])
    {
        if(vis[child]==0)
        {
            dfs(child,vis,adj,s);
            for(int i=0;i<26;i++)
            {
                hsh[v][i]+=hsh[child][i];
            }
        }
    }
}

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        unordered_map<int,vector<int>> adj;
        vector<int> vis(n+1);
        for(auto t:edges)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        memset(hsh,0,sizeof(hsh));
        dfs(0,vis,adj,s);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(hsh[i][s[i]-'a']);
        }
        return ans;
    }
};