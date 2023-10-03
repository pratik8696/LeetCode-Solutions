class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> arr(101);
        int ans=0;
        for(auto t:nums)
        {
            ans+=arr[t];
            arr[t]++;
        }
        return ans;
    }
};