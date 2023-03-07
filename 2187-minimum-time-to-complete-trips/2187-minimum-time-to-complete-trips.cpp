typedef long long ll;

bool check(ll val,vector<int> &time,ll k)
{
    ll ans=0;
    for(auto t:time)
    {
        ans+=val/t;
        if(ans>=k)
        {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    long long minimumTime(vector<int>& time, int k) {
        ll i=1,j=1e18,ans=0;
        while(i<=j)
        {
            ll mid=(i+j)/2;
            if(check(mid,time,k))
            {
                j=mid-1;
                ans=mid;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
    }
};