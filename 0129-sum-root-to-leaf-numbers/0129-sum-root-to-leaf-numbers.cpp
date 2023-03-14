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

ll dfs(TreeNode* root,ll &val)
{
    val*=10;
    val+=root->val;
    ll ans=0;
    if(root->left!=NULL)
    {
        ans+=dfs(root->left,val);
    }
    if(root->right!=NULL)
    {
        ans+=dfs(root->right,val);
    }
    if(root->right==NULL&&root->left==NULL)
    {
        ans+=val;
    }
    val/=10;
    return ans;
}


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        ll v=0;
        return dfs(root,v);
        return 0;
    }
};