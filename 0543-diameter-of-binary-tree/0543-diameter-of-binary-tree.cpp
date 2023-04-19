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
    int f(TreeNode* root,int &res){
        if(root==NULL){
            return 0;
        }
        int l=f(root->left,res);
        int r=f(root->right,res);
        
        int temp=max(l,r)+1;
        int ans=max(temp,1+r+l);
         res=max(res,ans);
        
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=INT_MIN;
        f(root,ans);
        return ans-1;
    }
};



// diameter of tree ka code v glt hora h dekho to ek baar
