typedef long long ll;

ll dfs(int v,int par,vector<vector<int>> &adj,vector<int> &values)
{
    ll curr=0;
    ll parent=values[v];
    int cc=0;
    for(auto child:adj[v])
    {
        if(par!=child)
        {
            cc++;
            curr+=dfs(child,v,adj,values);
        }
    }
    if(curr>=parent||cc==0)
    {
        return parent;
    }
    return curr;
}

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        ll sum=0;
        for(auto t:values)
        {
            ll c=t;
            sum+=c;
        }
        vector<vector<int>> adj(values.size());
        for(auto t:edges)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        ll curr=dfs(0,0,adj,values);
        return sum-curr;
    }
};