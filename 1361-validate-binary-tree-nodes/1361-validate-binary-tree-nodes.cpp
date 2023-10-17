class Solution 
{
public:
    int val=0;
    bool dfs(int v,vector<int> &vis,unordered_map<int,vector<int>> &adj)
    {
        val++;
        vis[v]=1;
        for(auto child:adj[v])
        {
            if(vis[child]==0)
            {
                if(dfs(child,vis,adj)==true)
                    return true;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> in;
        
        for(int i=0;i<leftChild.size();i++)
        {
            int u=leftChild[i];
            int v=rightChild[i];
            if(u!=-1)
                {adj[i].push_back(u);in[u]++;}
            if(v!=-1)
                {adj[i].push_back(v);in[v]++;}
        }
        
        int cc=0;
        vector<int> vis(n+1,0);
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                ans.push_back(i);
            }
        }
        
        if(ans.size()!=1)
            return false;

        if(dfs(ans.back(),vis,adj)==true)
            return false;
        
        if(val!=n)
            return false;
        
        return true;
    }
};