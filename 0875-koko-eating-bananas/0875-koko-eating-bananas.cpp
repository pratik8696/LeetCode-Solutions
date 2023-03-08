typedef long long ll;
bool check(ll val,vector<int> &arr,ll h)
{
    ll ans=0;
    for(auto t:arr)
    {
        ll temp=t+val-1;
        ans+=temp/val;
    }
    return ans<=h;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        ll i=1,j=1e18,ans=0;
        while(i<=j)
        {
            ll mid=(i+j)/2;
            if(check(mid,arr,h))
            {
                ans=mid;
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
    }
};