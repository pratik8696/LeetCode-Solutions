int ans=0;
void dfs(TreeNode* v,int val,int type)
{
    int l=0,r=0;
    if(type==0)
    {
        r=val;
    }
    else
    {
        l=val;
    }
    if(v->left!=NULL)
    {
        dfs(v->left,l+1,0);
        ans=max(ans,l+1);
    }
    if(v->right!=NULL)
    {
        dfs(v->right,r+1,1);
        ans=max(ans,r+1);
    }
}


class Solution {
public:
    int longestZigZag(TreeNode* root) {
        ans=0;
        dfs(root,0,0);
        return ans;
    }
};