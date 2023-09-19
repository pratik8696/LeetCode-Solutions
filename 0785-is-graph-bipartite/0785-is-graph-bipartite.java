class Solution {
    public boolean dfs(int v,int[] vis,ArrayList<ArrayList<Integer>> adj,int color,int[] col,int parent)
    {
        vis[v]=1;
        col[v]=color;
        boolean ans=true;
        // System.out.println("Node is "+v);
        for(Integer child:adj.get(v))
        {
            if(vis[child]==0)
            {
                ans &= dfs(child,vis,adj,1-color,col,v);
            }
            else 
            {
                if(col[child]==col[v])
                {
                    // System.out.println(child+" , "+v);
                    return false;
                }
            }
        }
        return ans;
    }
    
    public boolean isBipartite(int[][] graph) {
        int n=graph.length;
        ArrayList<ArrayList<Integer>> adj=new ArrayList<>();
        for(int i=0;i<n;i++)
        {
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].length;j++)
            {
                adj.get(i).add(graph[i][j]);
            }
        }
        int[] vis=new int[n+1];
        int[] col=new int[n+1];
        boolean ans=true;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
                ans&=dfs(i,vis,adj,0,col,-1);
        }
        return ans;
    }
}