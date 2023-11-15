class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int ans=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>=ans+1)
            {
                ans++;
            }
        }
        return ans;
    }
};