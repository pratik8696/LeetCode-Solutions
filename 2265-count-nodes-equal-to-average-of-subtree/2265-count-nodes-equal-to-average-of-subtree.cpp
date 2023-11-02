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
class Solution {
public:
    map<TreeNode*,int> m;
    int count=0;
    pair<int,int> dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int> l={0,0};
        pair<int,int> r={0,0};
        l=dfs(root->left);
        r=dfs(root->right);
        if(root->val==(l.first+r.first+root->val)/(l.second+r.second+1))
        {
            count++;
        }
        return {l.first+r.first+root->val,l.second+r.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        count=0;
        m.clear();
        dfs(root);
        return count;
    }
};