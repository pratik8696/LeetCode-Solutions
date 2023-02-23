typedef long long ll;
bool check(ll val,vector<ll> &arr,ll k,ll r,vector<int> &stations)
{
    ll n=stations.size();
    vector<ll> update(n+10);
    for(int i=0;i<n;i++)
    {
        update[i]+=(i-1>=0?update[i-1]:0);
        ll value=arr[i]+update[i];
        // cout<<value<<" "<<update[i]<<" "<<i<<endl;
        if(value<val)
        {
            ll rem = val-value;
            // cout<<value<<" "<<rem<<endl;
            if(rem>k)
            {
                // cout<<"sex"<<endl;
                // cout<<i<<endl;
                return false;
            }
            k -= rem;
            ll first=i;
            ll second=min(i+2*r,n-1);
            update[first]+=rem;
            update[second+1]-=rem;
        }
    }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<update[i]<<" ";
    // }
    // cout<<endl;
    return true;
}

class Solution {
public:
    long long maxPower(vector<int>& stations, int rr, int kk) {
        ll n=stations.size(),r=rr,k=kk;
        vector<ll> arr(n+1);
        for(ll i=0;i<n;i++)
        {
            ll left=max(i-r,0ll);
            ll right=min(n,i+r+1);
            arr[left]+=stations[i];
            arr[right]-=stations[i];
        }
        for(int i=1;i<n;i++)
        {
            arr[i]+=arr[i-1];
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        ll i=0,j=1e14,ans=0;
        while(i<=j)
        {
            ll mid=(i+j)/2;
            // (ll val,vector<int> &arr,ll k,ll r,vector<int> &stations)
            if(check(mid,arr,k,r,stations))
            {
                i=mid+1;
                ans=mid;
            }
            else
            {
                j=mid-1;
            }
        }
        // cout<<check(5,arr,k,r,stations)<<endl;
        return ans;
    }
};