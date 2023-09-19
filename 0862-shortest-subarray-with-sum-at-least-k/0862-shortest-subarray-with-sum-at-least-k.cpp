typedef long long ll;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<ll> pre(nums.size()+1);
        pre[1]=nums[0];
        for(int i=2;i<=nums.size();i++)
        {
            pre[i]+=pre[i-1]+nums[i-1];
        }
        deque<ll> dq;
        ll ans=1e9;
        for(int i=0;i<pre.size();i++)
        {
            // calculate the answer
            while(dq.size()&&pre[i]-pre[dq.front()]>=k)
            {
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            // remove 
            while(dq.size()&&pre[i]<=pre[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return (ans==1e9?-1:ans);
    }
};