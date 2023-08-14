class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto t:nums)
        {
            pq.push(-t);
            while(pq.size()>k)
            {
                pq.pop();
            }
        }
        return -pq.top();
    }
};