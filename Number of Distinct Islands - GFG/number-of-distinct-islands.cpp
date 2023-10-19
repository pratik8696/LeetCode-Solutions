//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
  
  bool check(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
  {
      if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
      return 0;
      if(vis[i][j]==1 || grid[i][j]==0)
      return 0;
      return 1;
  }
  
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int xx,int yy,vector<pair<int,int>> &curr)
    {
        curr.push_back({xx-i,yy-j});
        vis[i][j]=1;
        for(auto t: dirs)
        {
           int x=i+t.first;
           int y=j+t.second;
           if(check(x,y,grid,vis))
           {
                dfs(x,y,grid,vis,xx,yy,curr);
           }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        set<vector<pair<int,int>>> ans;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1&&vis[i][j]==0)
                {
                    vector<pair<int,int>> curr;
                    dfs(i,j,grid,vis,i,j,curr);
                    ans.insert(curr);
                }
            }
        }
        return ans.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends