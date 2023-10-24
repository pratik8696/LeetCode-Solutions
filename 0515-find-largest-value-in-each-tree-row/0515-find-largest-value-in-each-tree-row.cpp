map<int,int> m;

void dfs(TreeNode* root,int height)
{
    if(m.count(height)==0)
    {
        m[height]=root->val;
    }
    else
    {
        m[height]=max(m[height],root->val);
    }
    if(root->left!=NULL)
    {
        dfs(root->left,height+1);
    }
    if(root->right!=NULL)
    {
        dfs(root->right,height+1);
    }
}


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        m.clear();
        dfs(root,0);
        vector<int> ans;
        for(auto t:m)
        {
            ans.push_back(t.second);
        }
        return ans;
    }
};