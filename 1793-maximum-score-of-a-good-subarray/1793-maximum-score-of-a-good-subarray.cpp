bool check(int value,int i,vector<int> &a,vector<int> &b)
{
    // kitna value mid se bda hai mere pass
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
        // for(auto t:a)
        // {
        //     cout<<t<<" ";
        // }
        // cout<<endl;
        // for(auto t:b)
        // {
        //     cout<<t<<" ";
        // }
        // cout<<endl;        
        for(int sz=1;sz<=n-1;sz++)
        {
            // ab hme dekhna hai 1 length ke lie
            // to hm binary search krenge ki max kya aa 
            // payega 1 length tk mai
            // calculating max mid value possible in this arrangement
            // mtlb hmko dekhna hai ki kitna values aisa hai jo mid se bda hoga
            // hmko max value chahiye
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
            // ab jo answer value mila hmko usko hm multiply krenge
        }
        return rans;
    }
};