class TreeAncestor {
public:
    int sparse[50001][30];
    TreeAncestor(int n, vector<int>& parent) {
        memset(sparse,-1,sizeof(sparse));
        for(int i=0;i<n;i++)
        {
            sparse[i][0]=parent[i];
        }
        for(int i=1;i<30;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(sparse[j][i-1]!=-1)
                {
                    sparse[j][i]=sparse[sparse[j][i-1]][i-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<30;i++)
        {
            int val = k & (1 << i);
            if(val && node!=-1)
                node=sparse[node][i];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */