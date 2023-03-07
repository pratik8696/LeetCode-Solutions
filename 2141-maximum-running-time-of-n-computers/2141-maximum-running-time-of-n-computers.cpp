typedef long long ll;
bool check(ll val,vector<ll> &r,int n)
{
    vector<int> arr(r.begin(),r.end());
    ll m=arr.size();
    ll j=0,sum=0,cc=0,ans=0;
    for(int i=0;i<m;i++)
    {
        if(sum+arr[i]>val)
        {
            arr[i]=arr[i]-(val-sum);
            cc++;
            if(cc>1)
            {
                i--;
            }
            ans++;
            cc=0;
            sum=0;
        }
        else if(sum+arr[i]==val)
        {
            cc=0;
            ans++;
            sum=0;
        }
        else
        {
            cc++;
            sum+=arr[i];
        }
    }
    return ans>=n;
}

class Solution {
public:
    long long maxRunTime(int n, vector<int>& r) {
        vector<ll> arr;
        for(auto t:r)
        {
            arr.push_back(t);
        }
        sort(rbegin(arr),rend(arr));
        ll i=0,j=1e18,ans=0;
        while(i<=j)
        {
            ll mid=(i+j)/2;
            if(check(mid,arr,n))
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