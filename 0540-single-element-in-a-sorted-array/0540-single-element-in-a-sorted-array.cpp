bool check(int idx,vector<int> &arr)
{
    int n=arr.size();
    if(idx%2==0)
    {
        //agr age h to
        if(idx+1<n)
        {
            if(arr[idx+1]==arr[idx])
            {
                return true;
            }
        }
    }
    else
    {
        if(idx-1>=0)
        {
            if(arr[idx-1]==arr[idx])
            {
                return true;
            }
        }
    }
    return false;
}
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        while(i<j)
        {
            int mid=(i+j)/2;
            if(check(mid,arr))
            {
                i=mid+1;
            }
            else
            {
                j=mid;
            }
        }
        return arr[i];
    }
};