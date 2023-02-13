/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

typedef long long ll;
bool dfs(TreeNode* root,ll s,ll e)
{
    if(root==NULL)
    {
        return true;
    }
    bool left=true,right=true;
    if(root->val>s&&root->val<e)
    {
        left=dfs(root->left,s,root->val);
        right=dfs(root->right,root->val,e);        
        return left&right;
    }
    else
    {
        return false;
    }
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MIN*10ll,INT_MAX*10ll);
    }
};