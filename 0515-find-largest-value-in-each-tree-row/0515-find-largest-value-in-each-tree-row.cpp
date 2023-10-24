vector<int> m;

void dfs(TreeNode* root,int height)
{
    if(m.size()<height)
    {
        m.push_back(root->val);
    }
    else
    {
        m[height-1]=max(m[height-1],root->val);
    }
    
    if(root->left!=NULL)
    {
        dfs(root->left,height+1);
    }
    
    if(root->right!=NULL)
    {
        dfs(root->right,height+1);
    }
}


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        m.clear();
        dfs(root,1);
        return m;
    }
};