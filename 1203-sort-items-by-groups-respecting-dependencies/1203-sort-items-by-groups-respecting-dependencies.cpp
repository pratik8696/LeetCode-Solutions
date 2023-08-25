vector<int> bfs(int n,unordered_map<int,int> &in,unordered_map<int,vector<int>> &adj)
{
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
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
            in[child]--;
            if(in[child]==0)
            {
                q.push(child);
            }
        }
    }
    return ans;
}


class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& b) 
    {
        // -1 ko bhi group no de m+1 se
        // koun kis group mai hai ye bhi dekh
        int rem=m+1;
        map<int,int> belong;
        for(int i=0;i<group.size();i++)
        {
            if(group[i]==-1)
            {
                group[i]=rem++;
            }
            // cout<<group[i]<<" ";
            belong[i]=group[i];
        }
        // cout<<endl;
        // create the adj list
        unordered_map<int,vector<int>> adj,gadj;
        unordered_map<int,int> in,in_group;
        for(int i=0;i<n;i++)
        {
            // cout<<i<<":";
            for(auto x:b[i])
            {
                if(group[x] != group[i])
                {
                    gadj[group[x]].push_back(group[i]);
                    in_group[group[i]]++;
                }
                else
                {
                    adj[x].push_back(i);
                    in[i]++;
                }
                // cout<<x<<",";
            }
            // cout<<endl;
        }
        vector<int> order=bfs(n,in,adj);
        vector<int> order_group=bfs(rem,in_group,gadj);
        unordered_map<int,vector<int>> curr;
        for(auto t:order)
        {
            curr[group[t]].push_back(t);
        }
        vector<int> ans;
        for(auto t:order_group)
        {
            // cout<<t<<" ";
            vector<int> res=curr[t];
            for(auto t:res)
            {
                ans.push_back(t);
            }
        }
        // cout<<endl;
        // for(auto t:order)
        // {
        //     cout<<t<<" ";
        // }
        // cout<<endl;
        if(ans.size()!=n)
        {
            return {};
        }
        return ans;
    }
};
