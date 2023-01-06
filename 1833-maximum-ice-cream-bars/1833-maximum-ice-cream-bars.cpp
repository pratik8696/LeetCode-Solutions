typedef long long ll;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(begin(costs),end(costs));
        vector<ll> pre(n);
        pre[0]=costs[0];
        for(int i=1;i<n;i++)
        {
            pre[i] += pre[i-1] + costs[i];
        }
        pre.push_back(1e18);
        ll idx=upper_bound(begin(pre),end(pre),coins)-begin(pre);
        return idx;
    }
};