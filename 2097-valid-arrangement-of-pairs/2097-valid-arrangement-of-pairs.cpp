vector<vector<int>> ans;
void dfs(int v,unordered_map<int,vector<int>> &adj)
{
    while(adj[v].size())
    {
        int back=adj[v].back();
        adj[v].pop_back();
        dfs(back,adj);
        // cout<<v<<" "<<back<<" ,";
        ans.push_back({v,back});
    }
}

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int> in,out;
        unordered_map<int,vector<int>> adj;
        set<int> s;
        for(auto t:pairs)
        {
            int u=t[0];
            int v=t[1];
            s.insert(u);
            s.insert(v);
            out[u]++;
            in[v]++;
            adj[u].push_back(v);
        }
        // find out about the start node
        int cc=0;
        int start=*s.begin();
        for(auto t:s)
        {
            if(out[t]-in[t]==1)
            {
                start=t;
            }
        }
        // cout<<start<<endl;
        ans.clear();
        dfs(start,adj);
        reverse(begin(ans),end(ans));
        return ans;
    }
};