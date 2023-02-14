typedef TreeNode N;

int res;
vector<int> dfs(N* v)
{
    vector<int> left{0,1,INT_MAX,INT_MIN};
    vector<int> right{0,1,INT_MAX,INT_MIN};
    if(v->left!=NULL)
    {
        vector<int> temp=dfs(v->left);
        left[0]+=temp[0];
        left[1]&=temp[1];
        left[2]=min(left[2],temp[2]);
        left[3]=max(left[3],temp[3]);
    }
    if(v->right!=NULL)
    {
        vector<int> temp=dfs(v->right);
        right[0]+=temp[0];
        right[1]&=temp[1];
        right[2]=min(right[2],temp[2]);
        right[3]=max(right[3],temp[3]);
    }
    if(left[1]&right[1])
    {
        if(v->val>left[3]&&v->val<right[2])
        {
            res=max(res,left[0]+right[0]+v->val);
            return {left[0]+right[0]+v->val,1,min({left[2],v->val}),max({right[3],v->val})};
        }
        else
        {
            return {0,0,0,0};
        }
    }
    return {0,0,0,0};
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        res=0;
        dfs(root);
        return res;
    }
};