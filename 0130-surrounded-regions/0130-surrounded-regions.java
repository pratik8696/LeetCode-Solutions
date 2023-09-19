class Solution {
    int n,m;
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    
    boolean isvalid(int x,int y)
    {
        if(x<0||y<0||x>=n||y>=m)
        {
            return false;
        }
        return true;
    }
    
    void dfs(int x,int y,char[][] arr,int[][] vis)
    {
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(isvalid(x1,y1)&&vis[x1][y1]==0&&arr[x1][y1]=='O')
            {
                dfs(x1,y1,arr,vis);
            }
        }
    }
    
    public void solve(char[][] arr) 
    {
        n=arr.length;
        m=arr[0].length;
        // horizontal
        int[][] vis = new int[n][m];
        for(int i=0;i<m;i++)
        {
            if(vis[0][i]==0&&arr[0][i]=='O')
            {
                dfs(0,i,arr,vis);
            }
            if(vis[n-1][i]==0&&arr[n-1][i]=='O')
            {
                dfs(n-1,i,arr,vis);
            }
        }
        // vertical
        for(int i=0;i<n;i++)
        {
            if(vis[i][0]==0&&arr[i][0]=='O')
            {
                dfs(i,0,arr,vis);
            }
            if(vis[i][m-1]==0&&arr[i][m-1]=='O')
            {
                dfs(i,m-1,arr,vis);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // System.out.print(vis[i][j]+" ");
                if(vis[i][j]==1)
                {
                    continue;
                }
                else
                {
                    arr[i][j]='X';
                }
            }
            // System.out.println(" ");
        }
    }
}