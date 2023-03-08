typedef long long ll;
bool check(ll val,vector<int> &arr,int m)
{
    ll prev=arr[0],cc=1,n=arr.size();
    for(int i=1;i<n;i++)
    {
        if(arr[i]-prev>=val)
        {
            prev=arr[i];
            cc++;
        }
    }
    return cc>=m;
}

class Solution {
public:
    int maxDistance(vector<int>& arr, int m) {
        sort(begin(arr),end(arr));
        ll i=1,j=1e18,ans=0;
        while(i<=j)
        {
            ll mid=(i+j)/2;
            if(check(mid,arr,m))
            {
                i=mid+1;
                ans=mid;
            }
            else
            {
                j=mid-1;
            }
        }
        return ans;
    }
};