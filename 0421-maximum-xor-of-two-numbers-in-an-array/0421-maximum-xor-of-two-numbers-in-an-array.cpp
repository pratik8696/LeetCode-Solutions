typedef long long ll;
struct node
{
    node *nxt[2];
    // set<int> one;
    // set<int> zero;
    node()
    {
        for(int i=0;i<2;i++)
        {
            this->nxt[i] = NULL;
        }
    }
};

node *root;

void insert_node(int x)
{
    node *curr = root;
    for(int i=31;i>=0;i--)
    {
        ll temp = (x >> i) & 1;
        if (curr->nxt[temp] == NULL)
        {
            curr->nxt[temp] = new node();
        }
        // if(temp)
        // {
        //     curr->one.insert(x);
        // }
        // else
        // {
        //     curr->zero.insert(x);
        // }
        curr = curr->nxt[temp];
    }
}
 
int helper(int x)
{
    int ans=0;
    node* curr=root;
    for(int i=31;i>=0;i--)
    {
        int temp=(x >> i) & 1;
        if(curr->nxt[1-temp]!=NULL)
        {
            ans+=(1<<i);
            curr=curr->nxt[1-temp];
        }
        else
        {
            curr=curr->nxt[temp];
        }
    }
    return ans;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        root=new node();
        int ans=0;
        insert_node(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            ans=max(ans,helper(nums[i]));
            insert_node(nums[i]);
        }
        return ans;
    }
};