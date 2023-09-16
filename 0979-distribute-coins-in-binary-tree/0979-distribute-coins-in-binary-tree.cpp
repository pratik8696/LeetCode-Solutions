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
int ans=0;
int dfs(TreeNode* root)
{
    int curr=root->val;
    // go left
    int value_left=0,value_right=0;
    if(root->left!=NULL)
    {
        value_left=dfs(root->left);
    }
    // go right
    if(root->right!=NULL)
    {
        value_right=dfs(root->right);
    }
    ans+=abs(value_left)+abs(value_right);
    return root->val+value_left+value_right-1;
}

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};