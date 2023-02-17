vector<int> in;
void dfs(TreeNode* v)
{
    if(v->left!=NULL)
        dfs(v->left);
    
    in.push_back(v->val);
    
    if(v->right!=NULL)
        dfs(v->right);
}

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

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        return minDiffInBST(root);
    }
};