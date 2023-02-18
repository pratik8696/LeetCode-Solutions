class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        {
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int l=q.size();
            while(l--)
            {
                TreeNode* curr=q.front();
                q.pop();
                TreeNode* temp=curr->right;
                curr->right=curr->left;
                curr->left=temp;
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};