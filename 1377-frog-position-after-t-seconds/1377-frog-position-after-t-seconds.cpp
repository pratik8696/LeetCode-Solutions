double res=0;
void dfs(int v,vector<int> &vis,unordered_map<int,vector<int>> &adj,int parent,int time,int target,double prob)
{
    if(time==0)
    {
        if(v==target)
        {
            res=prob;
        }
        return;
    }
    vector<int> cc;
    for(auto child:adj[v])
    {
        if(parent!=child)
        {
            cc.push_back(child);
        }
    }

    for(auto child:cc)
    {
        double denom=cc.size();
        dfs(child,vis,adj,v,time-1,target,prob/denom);
    }
    
    if(cc.size()==0)
    {
        dfs(v,vis,adj,parent,time-1,target,prob);
    }
}

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        res=0;
        unordered_map<int,vector<int>> adj;
        for(auto t:edges)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        vector<int> vis;
        double start=1;
        dfs(1,vis,adj,1,t,target,start);
        return res;
    }
};