typedef long long ll;

bool check(ll mid,vector<int> &weights,int days)
{
    ll cc=1,sum=0,n=weights.size();
    for(int i=0;i<n;i++)
    {
        if(weights[i]>mid)
        {
            return false;
        }
        if(sum+weights[i]<=mid)
        {
            sum+=weights[i];
        }
        else
        {
            sum=weights[i];
            cc++;
        }
    }
    return cc<=days;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        ll i=1,j=1e9,ans=1e9;
        while(i<=j)
        {
            ll mid=(i+j)/2;
            if(check(mid,weights,days))
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