class Solution {
public:
    int search(vector<int>& arr, int target) {
        int i=0,j=arr.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(arr[mid]==target)
            {
                return mid;
            }
            else if(arr[0]<=arr[mid])
            {
                if(target>=arr[0]&&target<arr[mid])
                {
                    j=mid-1;
                }
                else
                {
                    i=mid+1;
                }
            }
            else
            {
                if(target<=arr.back()&&target>arr[mid])
                {
                    i=mid+1;
                }
                else
                {
                    j=mid-1;
                }
            }
        }
        return -1;
    }
};