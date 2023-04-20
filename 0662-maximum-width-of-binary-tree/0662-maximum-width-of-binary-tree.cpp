typedef long long ll;

class Solution{ 
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll ans=0;
        while(q.size())
        {
            ll k=q.size();
            ll mini=0,maxi=0;
            ll to=q.front().second;
            for(int i=0;i<k;i++)
            {
                TreeNode* curr=q.front().first;
                ll val=q.front().second-to;
                q.pop();
                if(i==0)
                {
                    mini=val;
                }
                if(i==k-1)
                {
                    maxi=val;
                }
                if(curr->left!=NULL)
                {
                    q.push({curr->left,(2*val)+1});
                }
                if(curr->right!=NULL)
                {
                    q.push({curr->right,(2*val)+2});
                }
            }
            ans=max(ans,maxi-mini+1);
        }
        return ans;
    }
};