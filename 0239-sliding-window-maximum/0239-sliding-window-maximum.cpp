class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        for(int i=0;i<k;i++)
        {
            while(dq.size()&&nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<n;i++)
        {
            // pop kro
            while(dq.size()&&i-dq.front()>=k)
            {
                dq.pop_front();
            }
            // insert kro
            while(dq.size()&&nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};