typedef long long ll;
struct node
{
    node *nxt[2];
    int count[2];
    node()
    {
        for(int i=0;i<2;i++)
        {
            this->nxt[i] = NULL;
        }
        memset(count,0,sizeof(count));
    }
};

node *root;

void insert_node(ll x,ll val)
{
    node *curr = root;
    for(int i=31;i>=0;i--)
    {
        ll temp = (x >> i) & 1;
        if (curr->nxt[temp] == NULL)
        {
            curr->nxt[temp] = new node();
        }
        curr->count[temp]+=val;
        curr = curr->nxt[temp];
    }
}
 
int helper(ll x)
{
    int ans=0;
    node* curr=root;
    for(int i=31;i>=0;i--)
    {   
        int temp=(x >> i) & 1;
        if(curr->nxt[1-temp]!=NULL&&curr->count[1-temp]>0)
        {
            ans+=1<<i;
            curr=curr->nxt[1-temp];
        }
        else
        {
            curr=curr->nxt[temp];
        }
    }
    return ans;
}

void dfs(int v,vector<int> &vis,unordered_map<int,vector<int>> &adj,unordered_map<int,vector<pair<int,int>>> &nodes,vector<int> &ans)
{
    vis[v]=1;
    insert_node(v,1);
    for(auto t : nodes[v])
    {
        int val=t.first;
        int idx=t.second;
        ans[idx]=helper(val);
    }
    for(auto child:adj[v])
    {
        if(vis[child]==0)
        {
            dfs(child,vis,adj,nodes,ans);
        }
    }
    insert_node(v,-1);
}

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        root=new node();
        unordered_map<int,vector<int>> adj;
        unordered_map<int,vector<pair<int,int>>> nodes;
        int rt=0;
        for(int i=0;i<parents.size();i++)
        {
            if(parents[i]==-1)
            {
                rt=i;
                continue;
            }
            adj[i].push_back(parents[i]);
            adj[parents[i]].push_back(i);
        }
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0];
            int value=queries[i][1];
            nodes[u].push_back({value,i});
        }
        vector<int> ans(queries.size());
        vector<int> vis(parents.size()+1,0);
        dfs(rt,vis,adj,nodes,ans);
        return ans;
    }
};