typedef long long ll;
class Solution {
public:
    void build(ll arr[], ll tree[], ll s, ll e, ll tn)
    {
        if (s == e)
        {
            tree[tn] = arr[s];
            return;
        }
        ll mid = (s + e) / 2;
        build(arr, tree, s, mid, 2 * tn);
        build(arr, tree, mid + 1, e, (2 * tn) + 1);
        tree[tn] = max(tree[2 * tn], tree[(2 * tn) + 1]);
    }

    ll query(ll arr[], ll tree[], ll s, ll e, ll tn, ll l, ll r)
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
        return max(ans1, ans2);
    }

    void update(ll arr[], ll tree[], ll s, ll e, ll tn, ll idx, ll val)
    {
        if (s == e)
        {
            arr[idx] = max(val,arr[idx]);
            tree[tn] = max(val,tree[tn]);
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
        tree[tn] = max(tree[2 * tn], tree[(2 * tn) + 1]);
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        const int szz=1e5+10;
        ll arr[szz];
        ll tree[4*szz];
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        build(arr,tree,0,szz-1,1);
        vector<vector<int>> a(int(1e5+1));
        for(auto t:envelopes)
        {
            a[t[0]].push_back(t[1]);
        }
        int ans=0;
        for(int i=1;i<=1e5;i++)
        {
            unordered_map<int,int> current;
            for(auto t:a[i])
            {
                int curr_res_fort=query(arr,tree,0,szz-1,1,0,t-1)+1;
                ans=max(ans,curr_res_fort);
                current[t]=max(current[t],curr_res_fort);
            }
            for(auto t:current)
            {
                update(arr,tree,0,szz-1,1,t.first,t.second);
            }
        }
        return ans;
    }
};