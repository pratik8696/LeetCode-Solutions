typedef long long ll;
void build(vector<int>&arr, vector<int>&tree, ll s, ll e, ll tn)
{
    if (s == e)
    {
        tree[tn] = arr[s];
        return;
    }
    ll mid = (s + e) / 2;
    build(arr, tree, s, mid, 2 * tn);
    build(arr, tree, mid + 1, e, (2 * tn) + 1);
    tree[tn] = max(tree[2 * tn] , tree[(2 * tn) + 1]);
}

ll query(vector<int>&arr, vector<int>&tree, ll s, ll e, ll tn, ll l, ll r)
{
    ll mid = (s + e) / 2;
    // out
    if (s > r || l > e)
    {
        return 0;
    }
    // in
    if (s >= l && r >= e)
    {
        return tree[tn];
    }

    ll ans1 = query(arr, tree, s, mid, 2 * tn, l, r);
    ll ans2 = query(arr, tree, mid + 1, e, (2 * tn) + 1, l, r);
    return max(ans1 , ans2);
}

void update(vector<int>&arr, vector<int>&tree, ll s, ll e, ll tn, ll idx, ll val)
{
    if (s == e)
    {
        arr[idx] = val;
        tree[tn] = val;
        return;
    }
    ll mid = (s + e) / 2;
    if (idx > mid)
    {
        update(arr, tree, mid + 1, e, (2 * tn) + 1, idx, val);
    }
    else
    {
        update(arr, tree, s, mid, 2 * tn, idx, val);
    }
    tree[tn] = max(tree[2 * tn] , tree[(2 * tn) + 1]);
}


class Solution {
public:
    bool canReach(string s, int mi, int mx) {
        int n=s.length();
        vector<int> arr(n,0);
        vector<int> tree(4*n,0);
        arr[0]=1;
        build(arr,tree,0,n-1,1);
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                int left=i-mx;
                int right=i-mi;
                if(right>=0)
                {
                    int q=query(arr,tree,0,n-1,1,max(0,i-mx),max(0,i-mi));
                    if(q)
                    {
                        update(arr,tree,0,n-1,1,i,1);
                    }
                }
            }
        }
        return arr.back();
    }
};