bool check(int value,int i,vector<int> &a,vector<int> &b)
{
    int idx1=lower_bound(begin(a),end(a),value)-begin(a);
    int idx2=lower_bound(begin(b),end(b),value)-begin(b);
    idx1=a.size()-idx1;
    idx2=b.size()-idx2;
    return idx1+idx2>=i;
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> a,b;
        int mini=nums[k];
        for(int i=k+1;i<n;i++)
        {
            mini=min(mini,nums[i]);
            a.push_back(mini);
        }
        mini=nums[k];
        for(int i=k-1;i>=0;i--)
        {
            mini=min(mini,nums[i]);
            b.push_back(mini);
        }
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));
        int rans=nums[k];
        for(int sz=1;sz<=n-1;sz++)
        {
            int i=1,j=2e4+1,ans=1;
            while(i<=j)
            {
                int mid=(i+j)/2;
                if(check(mid,sz,a,b))
                {
                    i=mid+1;
                    ans=mid;
                }
                else
                {
                    j=mid-1;
                }
            }
            rans=max(rans,(sz+1)*ans);
        }
        return rans;
    }
};