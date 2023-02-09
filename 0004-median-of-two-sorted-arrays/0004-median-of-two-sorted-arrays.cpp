typedef long long ll;

bool check(int val,vector<int> &a,vector<int> &b,int res)
{
    int idx1=upper_bound(begin(a),end(a),val)-begin(a);
    int idx2=upper_bound(begin(b),end(b),val)-begin(b);
    return idx1+idx2>=res;
}

ll value(ll sizer,vector<int> &a,vector<int> &b)
{
    ll i=-1e7,j=1e7,ans=0;
    while(i<=j)
    {
        ll mid=i+(j-i)/2;
        if(check(mid,a,b,sizer))
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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        // fast_cin();
        ll sizer=(a.size()+b.size());
        if(sizer%2)
        {
            return value((sizer+1)/2,a,b);
        }
        else
        {
            double val1=value(sizer/2,a,b);
            double val2=value((sizer/2)+1,a,b);
            return (val1+val2)/2;
        }        
    }
};