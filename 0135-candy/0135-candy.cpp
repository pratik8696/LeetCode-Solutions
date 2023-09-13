class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> arr(n,1);
        if(ratings.size()==1)
        {
            return 1;
        }
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                arr[i]=arr[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                arr[i]=max(arr[i+1]+1,arr[i]);
            }
        }        
        int ans=0;
        for(auto t:arr)
        {
            // cout<<t<<" ";
            ans+=t;
        }
        // cout<<endl;
        return ans;
    }
};