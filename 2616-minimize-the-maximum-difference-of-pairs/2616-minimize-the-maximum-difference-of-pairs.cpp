bool check(int val,vector<int> &arr,int p)
{
    int c=0;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i+1]-arr[i]<=val)
        {
            c++;
            i++;
        }
    }
    return c>=p;
}

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int i=0,j=1e9,ans=0;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(check(mid,nums,p))
            {
                j=mid-1;
                ans=mid;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
    }
};