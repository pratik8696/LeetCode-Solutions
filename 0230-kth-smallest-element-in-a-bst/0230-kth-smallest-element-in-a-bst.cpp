int dfs(TreeNode* root,int &i,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    
    if(root->left!=NULL)
    {
        int curr=dfs(root->left,i,k);
        if(curr!=-1)
        {
            return curr;
        }
    }
    i++;
    if(i==k)
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