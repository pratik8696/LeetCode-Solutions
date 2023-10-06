class Solution {
public:
    void dfs(string v,map<string,int> &vis,map<string,vector<pair<string,double>>> &adj,map<string,double> &dist)
    {
        vis[v]=1;
        for(auto t:adj[v])
        {
            auto child=t.first;
            auto wt=t.second;
            if(vis[child]==0)
            {
                dist[child]*=wt*dist[v];
                dfs(child,vis,adj,dist);
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> adj;
        set<string> s;
        for(int i=0;i<equations.size();i++)
        {
            string a=equations[i][0];
            string b=equations[i][1];
            double val=values[i];
            adj[a].push_back({b,val});
            adj[b].push_back({a,1/val});
            s.insert(a);
            s.insert(b);
        }
        vector<string> total(begin(s),end(s));        
        vector<double> ans;
        for(auto t:queries)
        {
            string a=t[0];
            string b=t[1];
            if(!(s.count(a)&&s.count(b)))
            {
                ans.push_back(-1);
                continue;                
            }
            map<string,double> dist;
            map<string,int> vis;
            for(auto t:total)
            {
                dist[t]=1;
            }
            dfs(a,vis,adj,dist);
            if(vis[b]==0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(dist[b]);
            }
        }
        return ans;
    }
};