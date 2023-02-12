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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int cc=0;
        while(q.size())
        {
            int curr=q.size();
            vector<int> temp;
            while(curr--)
            {
                TreeNode* node=q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            if(cc%2)
            {
                reverse(begin(temp),end(temp));
            }
            cc++;
            ans.push_back(temp);
        }
        return ans;
    }
};