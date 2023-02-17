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

vector<int> in;

void dfs(TreeNode* v)
{
    if(v->left!=NULL)
        dfs(v->left);
    
    in.push_back(v->val);
    
    if(v->right!=NULL)
        dfs(v->right);
}

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        in.clear();
        int ans=1e9;
        dfs(root);
        for(int i=0;i<in.size()-1;i++)
        {
            ans=min(ans,in[i+1]-in[i]);
        }
        return ans;
    }
};