typedef long long ll;

bool check(ll val,vector<int> &arr)
{
    int n=arr.size();
    ll carry=0;
    for(int i=n-1;i>=1;i--)
    {
        ll curr=arr[i]+carry;
        if(curr>val)
        {
            carry=curr-val;
        }
        else
        {
            carry=0;
        }
    }
    ll last=arr[0]+carry;
    if(last<=val)
    {
        return true;
    }
    return false;
}

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        ll i=0,j=*max_element(nums.begin(),nums.end()),ans=0;
        while(i<=j)
        {
            ll mid=(i+j)/2;
            if(check(mid,nums))
            {
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};