typedef long long ll;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0,prev=-1e18,cc=0;
        nums.push_back(-1);
        for(auto t:nums)
        {
            if(prev!=t)
            {
                if(prev==0)
                {
                    ans+=(cc*(cc+1))/2;
                }
                cc=1;
                prev=t;
            }
            else
            {
                cc++;
            }
        }
        return ans;
    }
};