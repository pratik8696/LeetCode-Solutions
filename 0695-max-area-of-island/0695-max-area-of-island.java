class DSU{
    private int[] parent;
    private int[] size;
    DSU(int n)
    {
        parent=new int[n];
        size=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    public int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    public int sz(int x)
    {
        return size[find(x)];
    }
    public void union(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            if(size[a]<size[b])
            {
                int t=a;
                a=b;
                b=t;
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }
}

class Solution {
    private int n,m;
    public int[] dx={1,0,-1,0};
    public int[] dy={0,1,0,-1};
    
    public boolean isvalid(int x,int y)
    {
        if(x<0||y<0||x>=n||y>=m)
        {
            return false;
        }
        return true;
    }

    public int maxAreaOfIsland(int[][] grid) {
        n=grid.length;
        m=grid[0].length;
        int res=n*m;
        DSU dsu=new DSU(n*m);
        int[][] arr=new int[n][m];
        int cc=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j]=cc++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<4;k++)
                {
                    int x1=i+dx[k];
                    int y1=j+dy[k];
                    if(isvalid(x1,y1)&&grid[i][j]==1&&grid[x1][y1]==1)
                    {
                        dsu.union(arr[i][j],arr[x1][y1]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                ans=Math.max(ans,dsu.sz(arr[i][j]));
            }
        }
        return ans;
    }
}