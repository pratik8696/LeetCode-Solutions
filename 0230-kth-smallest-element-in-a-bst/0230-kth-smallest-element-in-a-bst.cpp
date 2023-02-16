int dfs(TreeNode* root,int &i,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    int val=dfs(root->left,i,k);
    if(val!=-1)
    {
        return val;
    }
    i++;
    if(k==i)
    {
        return root->val;
    }
    return dfs(root->right,i,k);
}


class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return dfs(root,i,k);
    }
};