typedef long long ll;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ll curr=0,maxx=-1e9;
        for(auto t:nums)
        {
            curr=max(curr+t,ll(t));
            maxx=max(maxx,curr);
        }
        return maxx;
    }
};