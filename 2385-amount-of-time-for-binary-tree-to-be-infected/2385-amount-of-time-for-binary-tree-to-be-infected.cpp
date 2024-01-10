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

map<TreeNode*,TreeNode*> m;
map<TreeNode*,int> dist;
TreeNode* x;
int y;
void dfs(TreeNode* v)
{
    dist[v]=1e9;
    if(v->val==y)
    {
        x=v;
    }
    if(v->left!=NULL)
    {
        dfs(v->left);
        m[v->left]=v;
    }
    if(v->right!=NULL)
    {
        dfs(v->right);
        m[v->right]=v;
    }
}

int ans=0;

void bfs()
{
    queue<TreeNode*> q;
    dist[x]=0;
    q.push(x);
    while(q.size())
    {
        TreeNode* curr=q.front();
        ans=max(ans,dist[curr]);
        q.pop();
        TreeNode* par = m[curr];
        if(curr->left != NULL)
        {
            if(dist[curr->left]>dist[curr]+1)
            {
                q.push(curr->left);
                dist[curr->left]=dist[curr]+1;
            }
        }
        if(curr->right != NULL)
        {
            if(dist[curr->right]>dist[curr]+1)
            {
                q.push(curr->right);
                dist[curr->right]=dist[curr]+1;
            }
        }
        if(par != NULL)
        {
            if(dist[par]>dist[curr]+1)
            {
                q.push(par);
                dist[par]=dist[curr]+1;
            }
        }
    }
}

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        y=start;
        m.clear();
        ans=0;
        dfs(root);
        bfs();
        return ans;
        
    }
};