typedef long long ll;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ll curr=0,maxx=-1e9;
        for(ll t:nums)
        {
            curr=max(curr+t,t);
            maxx=max(curr,maxx);
        }
        return maxx;
    }
};