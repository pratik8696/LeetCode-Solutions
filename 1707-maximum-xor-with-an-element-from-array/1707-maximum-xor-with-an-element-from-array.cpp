typedef long long ll;
struct node
{
    node *nxt[2];
    ll one=1e18;
    ll zero=1e18;
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
    for(int i=31;i>=0;i--)
    {
        ll temp = (x >> i) & 1;
        if (curr->nxt[temp] == NULL)
        {
            curr->nxt[temp] = new node();
        }
        if(temp==1)
        {
            curr->one=min(curr->one,x);
        }
        else
        {
            curr->zero=min(curr->zero,x);
        }
        // cout<<i<<" "<<curr->one<<" "<<curr->zero<<" "<<temp<<endl;
        curr = curr->nxt[temp];
    }
}
 
int helper(ll x,ll m)
{
    int ans=0;
    node* curr=root;
    for(int i=31;i>=0;i--)
    {
        
        int temp=(x >> i) & 1;
        ll o=curr->one;
        ll z=curr->zero;
        // cout<<ans<<" "<<i<<" "<<o<<" "<<z<<endl;
        if(curr->nxt[1-temp]!=NULL)
        {
            if(temp)
            {
                if(z<=m)
                {
                    ans+=(1<<i);
                    // cout<<"MOVED TO ZERO"<<endl;
                    // move to zero
                    curr=curr->nxt[1-temp];
                }
                else
                {
                    // move to one
                    if(o<=m)
                    {
                        // cout<<"ZERO MILA MGR BDA HAI TO ONE MAI JA RHE"<<endl;
                        curr=curr->nxt[temp];
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
            else
            {
                // move to one
                if(o<=m)
                {
                    ans+=(1<<i);
                    // cout<<"MOVED TO ONE"<<endl;
                    // move in one
                    curr=curr->nxt[1-temp];
                }
                else
                {
                    //move to zero
                    if(z<=m)
                    {
                        // cout<<"ONE MILA MGR BDA HAI TO ZERO MAI JA RHE"<<endl;
                        curr=curr->nxt[temp];
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
        }
        else
        {
            // cout<<"MERA OPP HI NAI HAI"<<endl;
            // move to temp only 
            if(temp)
            {
                if(o<=m)
                {
                    curr=curr->nxt[temp];
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if(z<=m)
                {
                    curr=curr->nxt[temp];
                }
                else
                {
                    return -1;
                }
            }
        }
    }
    return ans;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root=new node();
        int mini=*min_element(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++)
        {
            insert_node(nums[i]);
        }
        vector<int> ans;
        for(auto t:queries)
        {
            int u=t[0];
            int v=t[1];
            ans.push_back(helper(u,v));
        }
        return ans;
    }
};