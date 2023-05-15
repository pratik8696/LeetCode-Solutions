typedef long long ll;

ll sum(ll mask,vector<int> &arr,vector<int> &dp)
{
    if(mask==(1<<arr.size())-1)
    {
        return 0;
    }
    auto &x=dp[mask];
    if(x!=-1)
    {
        return x;
    }
    ll ans=0;
    ll cc=0;
    for(int i=0;i<=14;i++)
    {
        if(mask&(1<<i))
        {
            cc++;
        }
    }
    cc/=2;
    cc++;
    for(int i=0;i<arr.size();i++)
    {
        if((mask&(1<<i))==0)
        {
            ll curr_mask=mask|(1<<i);
            for(int j=i+1;j<arr.size();j++)
            {
                if((curr_mask&(1<<j))==0)
                {
                    ans=max(ans,sum(curr_mask|1<<j,arr,dp)+(cc*__gcd(arr[i],arr[j])));
                }
            }
        }
    }
    return x = ans;
}

class Solution {
public:
    int maxScore(vector<int>& arr) {
        vector<int> dp(1<<arr.size(),-1);
        return sum(0,arr,dp);
    }
};