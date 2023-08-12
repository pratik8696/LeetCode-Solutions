typedef long long ll;

int sum(int x,int y,vector<vector<int>> &h,vector<vector<int>> &v,vector<vector<int>> &dp,vector<unordered_map<ll,vector<ll>>> &row,vector<unordered_map<ll,vector<ll>>> &col,vector<vector<int>> &arr)
{
    auto &xx=dp[x][y];
    if(xx!=-1)
    {
        return xx;
    }
    xx=0;
    // horizontally
    int idx1=h[x][y];
    int ans=0;
    if(idx1!=-1)
    {
        // iterate all the values which equal arr[x][idx1] in the same column
        for(auto t:row[x][arr[x][idx1]])
        {
            ans=max(ans,1+sum(x,t,h,v,dp,row,col,arr));
        }
    }
    // vertically
    int idx2=v[x][y];
    if(idx2!=-1)
    {
        // iterate all the values which equal arr[idx2][y] in the same row
        for(auto t:col[y][arr[idx2][y]])
        {
            ans=max(ans,1+sum(t,y,h,v,dp,row,col,arr));
        }
    }
    return xx=ans;
}

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> horizontal(n,vector<int>(m,-1));
        vector<vector<int>> vertical(n,vector<int>(m,-1));
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<unordered_map<ll,vector<ll>>> col(m),row(n);
        for(int i=0;i<n;i++)
        {
            vector<pair<int,int>> res;
            for(int j=0;j<m;j++)
            {
                res.push_back({arr[i][j],j});
                row[i][arr[i][j]].push_back(j);
            }
            sort(begin(res),end(res));
            vector<int> a;
            // cout<<"HORIZONTAL"<<endl;
            for(auto t:res)
            {
                // cout<<t.first<<" -- "<<t.second<<endl;
                a.push_back(t.first);
            }
            // cout<<"HORIZONTAL"<<endl;
            for(int j=0;j<m;j++)
            {
                int val=res[j].first;
                int idx=upper_bound(begin(a),end(a),val)-begin(a);
                if(idx!=a.size())
                {
                    // cout<<res[j].second<<" --> "<<res[idx].second<<endl;
                    horizontal[i][res[j].second]=res[idx].second;
                    
                }
                else
                {
                    // cout<<res[j].second<<" --> -1"<<endl;
                }
            }
            // cout<<endl;
            // cout<<endl;
        }
            // cout<<endl;
            // cout<<endl;
            // cout<<endl;
            // cout<<endl;
        for(int j=0;j<m;j++)
        {
            vector<pair<int,int>> res;
            for(int i=0;i<n;i++)    
            {
                res.push_back({arr[i][j],i});
                col[j][arr[i][j]].push_back(i);
            }
            sort(begin(res),end(res));
            vector<int> a;
            // cout<<"VERTICAL"<<endl;
            for(auto t:res)
            {
                // cout<<t.first<<" -- "<<t.second<<endl;
                a.push_back(t.first);
            }
            // cout<<"VERTICAL"<<endl;
            for(int i=0;i<n;i++)  
            {
                int val=res[i].first;
                int idx=upper_bound(begin(a),end(a),val)-begin(a);
                if(idx!=a.size())
                {
                    // cout<<res[i].second<<" --> "<<res[idx].second<<endl;
                    vertical[res[i].second][j]=res[idx].second;
                }
                else
                {
                    // cout<<res[i].second<<" --> -1"<<endl;
                }
            }
            // cout<<endl;
            // cout<<endl;
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)        
        //     {
        //         cout<<horizontal[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }        
        // cout<<endl;
        // cout<<endl;        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)        
        //     {
        //         cout<<vertical[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<endl;
        int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<": "<<endl;
        //     for(auto t:row[i])
        //     {
        //         cout<<t.first<<" --> ";
        //         for(auto x:t.second)
        //         {
        //             cout<<x<<" ";
        //         }
        //         cout<<endl;
        //     }
        // }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // cout<<1+sum(i,j,horizontal,vertical)<<" ";
                ans=max(ans,1+sum(i,j,horizontal,vertical,dp,row,col,arr));
            }
            // cout<<endl;
        }
        // cout<<endl;
        // cout<<endl;
        // cout<<endl;
        return ans;
    }
};