typedef long long ll;
struct node
{
    node *nxt[2];
    ll one=0;
    ll zero=0;
    node()
    {
        for(int i=0;i<2;i++)
        {
            this->nxt[i] = NULL;
        }
    }
};

node *root;

void insert_node(ll x)
{
    node *curr = root;
    for(int i=20;i>=0;i--)
    {
        ll temp = (x >> i) & 1;
        if (curr->nxt[temp] == NULL)
        {
            curr->nxt[temp] = new node();
        }
        if(temp)
        {
            curr->one=max(curr->one,x);
        }
        else
        {
            curr->zero=max(curr->zero,x);
        }
        curr = curr->nxt[temp];
    }
}
 
int helper(ll x)
{
    int ans=0;
    node* curr=root;
    for(int i=20;i>=0;i--)
    {
        int temp=(x >> i) & 1;
        ll o=curr->one;
        ll z=curr->zero;
        if(curr->nxt[1-temp]!=NULL)
        {
            if(1-temp==0)
            {
                if(2*z>=x)
                {
                    ans+=(1<<i);
                    curr=curr->nxt[1-temp];
                }
                else
                {
                    if(curr->nxt[temp]!=NULL)
                    {
                        curr=curr->nxt[temp];
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if(2*o>=x)
                {
                    ans+=(1<<i);
                    curr=curr->nxt[1-temp];
                }
                else
                {
                    if(curr->nxt[temp]!=NULL)
                    {
                        curr=curr->nxt[temp];
                    }
                    else
                    {
                        break;
                    }
                }                
            }
        }
        else
        {
            if(curr->nxt[temp]!=NULL)
            {
                curr=curr->nxt[temp];
            }
            else
            {
                break;
            }
        }
    }
    return ans;
}

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        root=new node();
        sort(begin(nums),end(nums));
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