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
int dfs(TreeNode* v)
{
    int left=0,right=0;
    if(v->left!=NULL)
    {
        left=dfs(v->left);
    }
    if(v->right!=NULL)
    {
        right=dfs(v->right);
    }
    return max(left,right)+1;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        return dfs(root);
    }
};