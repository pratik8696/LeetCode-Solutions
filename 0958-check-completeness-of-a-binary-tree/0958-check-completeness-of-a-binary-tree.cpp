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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        while(q.size())
        {
            int x=q.size();
            while(x--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr==NULL)
                {
                    flag=1;
                }
                else
                {
                    if(flag)
                    {
                        return false;
                    }
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return true;
    }
};